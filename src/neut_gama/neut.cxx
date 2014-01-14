#include "neut.h"

using std::vector;
using namespace std;

extern std::vector<Event::EventData> events;

namespace Dilep {
	namespace GAMA {

		unsigned _tid = 0, size;
	
		void dilep (vector<DilepInput> &di) {

			size = di.size();
			
			double in_mpx[2 * size], in_mpy[2 * size], in_mpz[2 * size], 
				   t_mass[2 * size], w_mass[2 * size];
			
			double *dev_t_mass, *dev_w_mass, *dev_in_mpx, *dev_in_mpy;
			double a[5 * size], b[5 * size], c[5 * size], d[5 * size], e[5 * size], f[5 * size];	// e and f are the z/c_bl
			double aFlags[5 * size], bFlags[5 * size], cFlags[5 * size], dFlags[5 * size];
		
			double *dev_lep_a, *dev_lep_b, *dev_bj_a, *dev_bj_b;
			double *dev_lep_aFlags, *dev_lep_bFlags, *dev_bj_aFlags, *dev_bj_bFlags;
			double nc[16*size];
			double *dev_nc, *dev_MissPx, *dev_MissPy;
			int count[size], *dev_count;
			int hasSolution = 0;

			double _misspx = di[0].getMissPx(), _misspy = di[0].getMissPy();

			// time measurement
			#ifdef MEASURE_DILEP
			long long int time = startTimer();
			#endif

			for (unsigned i = 0; i < size; ++i) {

				in_mpx[i * 2]		= di[i].getInMpx(0);
				in_mpx[(i * 2) + 1] = di[i].getInMpx(1);
				in_mpy[i * 2]		= di[i].getInMpy(0);
				in_mpy[(i * 2) + 1] = di[i].getInMpy(1);
				t_mass[i * 2]		= di[i].getTmass(0);
				t_mass[(i * 2) + 1] = di[i].getTmass(1);
				w_mass[i * 2]		= di[i].getWmass(0);
				w_mass[(i * 2) + 1] = di[i].getWmass(1);
				
				// z_lep
				a[i * 5]	   = di[i].getZlep().Px();
				a[(i * 5) + 1] = di[i].getZlep().Py();
				a[(i * 5) + 2] = di[i].getZlep().Pz();
				a[(i * 5) + 3] = di[i].getZlep().E();
				a[(i * 5) + 4] = di[i].getZlep().M();

				// z_lepWFlags
				aFlags[i * 5]	    = di[i].getZlepW().Px();
				aFlags[(i * 5) + 1] = di[i].getZlepW().Py();
				aFlags[(i * 5) + 2] = di[i].getZlepW().Pz();
				aFlags[(i * 5) + 3] = di[i].getZlepW().isb;
				aFlags[(i * 5) + 4] = di[i].getZlepW().M();

				// c_lep
				b[i * 5]	   = di[i].getClep().Px();
				b[(i * 5) + 1] = di[i].getClep().Py();
				b[(i * 5) + 2] = di[i].getClep().Pz();
				b[(i * 5) + 3] = di[i].getClep().E();
				b[(i * 5) + 4] = di[i].getClep().M();

				// c_lepWFlags
				bFlags[i * 5]	    = di[i].getClepW().Px();
				bFlags[(i * 5) + 1] = di[i].getClepW().Py();
				bFlags[(i * 5) + 2] = di[i].getClepW().Pz();
				bFlags[(i * 5) + 3] = di[i].getClepW().isb;
				bFlags[(i * 5) + 4] = di[i].getClepW().M();

				// z_bj
				c[i * 5]	   = di[i].getZbj().Px();
				c[(i * 5) + 1] = di[i].getZbj().Py();
				c[(i * 5) + 2] = di[i].getZbj().Pz();
				c[(i * 5) + 3] = di[i].getZbj().E();
				c[(i * 5) + 4] = di[i].getZbj().M();

				// z_bjWFlags
				cFlags[i * 5]	    = di[i].getZbjW().Px();
				cFlags[(i * 5) + 1] = di[i].getZbjW().Py();
				cFlags[(i * 5) + 2] = di[i].getZbjW().Pz();
				cFlags[(i * 5) + 3] = di[i].getZbjW().isb;
				cFlags[(i * 5) + 4] = di[i].getZbjW().M();

				// c_bj
				d[i * 5]	   = di[i].getCbj().Px();
				d[(i * 5) + 1] = di[i].getCbj().Py();
				d[(i * 5) + 2] = di[i].getCbj().Pz();
				d[(i * 5) + 3] = di[i].getCbj().E();
				d[(i * 5) + 4] = di[i].getCbj().M();

				// c_bjWFlags
				dFlags[i * 5]	    = di[i].getCbjW().Px();
				dFlags[(i * 5) + 1] = di[i].getCbjW().Py();
				dFlags[(i * 5) + 2] = di[i].getCbjW().Pz();
				dFlags[(i * 5) + 3] = di[i].getCbjW().isb;
				dFlags[(i * 5) + 4] = di[i].getCbjW().M();

			}

			//cout << "Tau1: " << di[200].getCbj().Px() << endl;
			// GPU memory allocation of the inputs and outputs of the dilep kernel
			//cudaMalloc(&dev_t_mass, size*2*sizeof(double));
			//cudaMalloc(&dev_w_mass, size*2*sizeof(double));
			//cudaMalloc(&dev_in_mpx, size*2*sizeof(double));
			//cudaMalloc(&dev_in_mpy, size*2*sizeof(double));

			//cudaMalloc(&dev_lep_a, sizeof(a));
			//cudaMalloc(&dev_lep_b, sizeof(b));
			//cudaMalloc(&dev_bj_a, sizeof(c));
			//cudaMalloc(&dev_bj_b, sizeof(d));

			//cudaMalloc(&dev_lep_aFlags, sizeof(aFlags));
			//cudaMalloc(&dev_lep_bFlags, sizeof(bFlags));
			//cudaMalloc(&dev_bj_aFlags, sizeof(cFlags));
			//cudaMalloc(&dev_bj_bFlags, sizeof(dFlags));

			//cudaMalloc(&dev_MissPx, sizeof(double));
			//cudaMalloc(&dev_MissPy, sizeof(double));

			// allocation of the results
			//cudaMalloc(&dev_nc, size*16*sizeof(double));
			//cudaMalloc(&dev_count, size*sizeof(int));

			// transfer the inputs to GPU memory
			//cudaMemcpy(dev_t_mass, t_mass, sizeof(t_mass), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_w_mass, w_mass, sizeof(w_mass), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_in_mpx, in_mpx, sizeof(in_mpx), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_in_mpy, in_mpy, sizeof(in_mpy), cudaMemcpyHostToDevice);

			//cudaMemcpy(dev_lep_a, a, sizeof(a), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_lep_b, b, sizeof(b), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_bj_a, c, sizeof(c), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_bj_b, d, sizeof(d), cudaMemcpyHostToDevice);

			//cudaMemcpy(dev_lep_aFlags, aFlags, sizeof(aFlags), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_lep_bFlags, bFlags, sizeof(bFlags), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_bj_aFlags, cFlags, sizeof(cFlags), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_bj_bFlags, dFlags, sizeof(dFlags), cudaMemcpyHostToDevice);

			//cudaMemcpy(dev_MissPx, _misspx, sizeof(double), cudaMemcpyHostToDevice);
			//cudaMemcpy(dev_MissPy, _misspy, sizeof(double), cudaMemcpyHostToDevice);
			
			//dilep_kernel(in_mpx, in_mpy, aFlags, bFlags, cFlags, dFlags,
			//		a, b, c, d, _misspx, _misspy, t_mass, w_mass, nc, count);


			DilepClass dp (in_mpx, in_mpy, aFlags, bFlags, cFlags, dFlags, a, b, c, d, _misspx,
						   _misspy, t_mass, w_mass, 0, 0, size);

			dp.execute();

			nc = dp.nc;
			a = dp.a;

			//dilep_kernel <<< 1, size >>> (dev_in_mpx, dev_in_mpy, dev_lep_aFlags, dev_lep_bFlags, dev_bj_aFlags, dev_bj_bFlags,
			//		dev_lep_a, dev_lep_b, dev_bj_a, dev_bj_b, dev_MissPx, dev_MissPy, dev_t_mass, dev_w_mass, dev_nc, dev_count);
			
			
			// memory transfer of the results from the GPU
			//cudaMemcpy(nc, dev_nc, 16*size*sizeof(double), cudaMemcpyDeviceToHost);
			//cudaMemcpy(count, dev_count, size*sizeof(int), cudaMemcpyDeviceToHost);

			// reconstruction of the normal output of dilep
			// o num de combs*vars e o num de threads

			int total;
			for (Event::event_counter = 0, total = 0; Event::event_counter < events.size(); ++Event::event_counter) {
				for (unsigned comb = 0; comb < events[Event::event_counter].num_Combs; ++comb, ++total) {
					vector<myvector> result;

					for (int sol = 0 ; sol < count[total] && sol<4 ; sol++) {
						myvector *mv = new myvector( 
							TO1D(nc,total,sol,0),
							TO1D(nc,total,sol,1),
							TO1D(nc,total,sol,2),
							TO1D(nc,total,sol,3) );
						
						result.push_back(*mv);
					}
					if(result.size())
						++hasSolution;
					//cout << "Tau: " << hasSolution << " - " << result.size() << endl;

					di[total].setHasSol(hasSolution);
					di[total].setResult(&result);
				}
			}
			//cout << "Sizes: " << di.size() << " - " << total << " - " << size << endl<<endl;

			// time measurement
			#ifdef MEASURE_DILEP
			stopTimer(time);
			#endif
			
		}

		//__global__
		

		//__host__
		void calc_dilep(double t_mass[], double w_mass[], 
				double in_mpx[], double in_mpy[], double _lep_a[], 
				double _lep_b[], double _bl_a[], double _bl_b[], 
				double nc[], int a[], unsigned _tid)
		{

			unsigned tid = _tid;
			double G_1, G_3;
			double WMass_a, WMass_b, tMass_a, tMass_b, lep_a[5], lep_b[5], bl_a[5], bl_b[5];
			double in_mpz[2] = {0.0, 0.0};


			WMass_a = STRIDE2(w_mass, 0);
			tMass_a = STRIDE2(t_mass, 0);
			WMass_b = STRIDE2(w_mass, 1);
			tMass_b = STRIDE2(t_mass, 1);

			for (unsigned i = 0; i < 5; ++i) {
				lep_a[i] = STRIDE5(_lep_a, i);
				lep_b[i] = STRIDE5(_lep_b, i);

				bl_a[i] = STRIDE5(_bl_a, i);
				bl_b[i] = STRIDE5(_bl_b, i);
			}

			G_1 = (WMass_a - lep_a[4]) * (WMass_a + lep_a[4]);
			G_3 = (WMass_b - lep_b[4]) * (WMass_b + lep_b[4]);

			double G_5,G_6,G_7,G_8,G_9,G_10,G_11,G_12;
			G_5 = ( bl_a[0]/bl_a[3] - lep_a[0]/lep_a[3] );
			G_6 = ( bl_a[1]/bl_a[3] - lep_a[1]/lep_a[3] );
			G_7 = ( bl_a[2]/bl_a[3] - lep_a[2]/lep_a[3] );
			G_8 = ( G_1/lep_a[3] - ((tMass_a - bl_a[4]) * (tMass_a + bl_a[4]))/bl_a[3] )/2.;

			G_9 =	( bl_b[0]/bl_b[3] - lep_b[0]/lep_b[3] );
			G_10 =	( bl_b[1]/bl_b[3] - lep_b[1]/lep_b[3] );
			G_11 =	( bl_b[2]/bl_b[3] - lep_b[2]/lep_b[3] );
			G_12 =	( G_3/lep_b[3] - ((tMass_b - bl_b[4]) * (tMass_b + bl_b[4]))/bl_b[3] )/2.;

			///////////////////////////////////////////////////////////////////
			//// 	G_5 *x1 + G_6*y1 + G_7*z1 = G8;  		(6)
			////  	G_9 *x2 + G_10*y2 + G_11*z2 = G12; 		(7)
			////  	2*El_1*sqrt() - 2*(ax1+by1+cz1) = G_1;  	(8)
			////  	2*El_2*sqrt() - 2*(Ax2+By2+Cz2) = G_3;		(9)
			////  	x1+x2 = S;					(10)
			////  	y1+y2 = T;					(11)
			////  	bring z1 and z2 (from 6/7) to 7 and 8
			///////////////////////////////////////////////////////////////////

			//// 1st top decay product /////
			
			double in_a[5],out_a[6];
			in_a[0] = G_8/G_7;
			in_a[1] = -1.0*G_5/G_7;
			in_a[2] = -1.0*G_6/G_7;
			in_a[3] = lep_a[3];
			in_a[4] = G_1;
			toz(in_a, lep_a, out_a);

			double in_c[5],out_c[6];
			in_c[0] = G_12/G_11;
			in_c[1] = -1*G_9/G_11;
			in_c[2] = -1*G_10/G_11;
			in_c[3] = lep_b[3];
			in_c[4] = G_3;
			toz(in_c, lep_b, out_c);
			/////////////////////////////////////////////////////
			//////change x2 y2 equation to x1 and y1 by using
			////// 		x1+x2 = S = in_mpx[0]
			////// 		y1+y2 = T = mpy
			/////////////////////////////////////////////////////
			double out_e[6];
			out_e[0] = out_c[0];
			out_e[1] = out_c[1];
			out_e[2] = -1*( out_c[0]*in_mpx[0] + out_c[2] + out_c[4]*in_mpy[0]);
			out_e[3] = -1*( out_c[1]*in_mpy[0] + out_c[3] + out_c[4]*in_mpx[0]);
			out_e[4] = out_c[4]; 
			out_e[5] =( out_c[0]*in_mpx[0]*in_mpx[0] + out_c[1]*in_mpy[0]*in_mpy[0] + 2*out_c[2]*in_mpx[0] + 2*out_c[3]*in_mpy[0] + out_c[5] + 2*out_c[4]*in_mpx[0]*in_mpy[0]);

			///////////////////////////////////////////////////
			///  solve 
			/// {ax2+by2+2dx+2ey+2fxy+g=0		(12)
			/// {Ax2+By2+2Dx+2Ey+2Fxy+G=0		(13)
			/// out_a[6]: 0   1    2    3    4     5
			/// out_a[6]: a   b    d    e    f     g
			/// out_e[6]: A   B    D    E    F     G
			/// if a!=0, everything is OK.
			///
			/// if a==0, then we can get x2 = f(x,y) from (13)
			/// (12) --> [x2 - f(x,y)] + by2 + ... = 0
			///////////////////////////////////////////////////
			
			double fx_1, fx_2, fx_3, fx_4, fx_5;
			double k_1, k_2, k_3, k_4, k_5;

			// bad organization of the code; diminished register spilling
			if ( out_a[0]!=0  ){
				fx_1 = 2.*(out_e[0]*out_a[2] - out_a[0]*out_e[2]);
				fx_2 = 2.*(out_e[0]*out_a[4] - out_a[0]*out_e[4]);
				fx_3 = out_a[0]*out_e[1] - out_e[0]*out_a[1];
				fx_4 = 2.*(out_e[3]*out_a[0] - out_e[0]*out_a[3]);
				fx_5 = out_a[0]*out_e[5] - out_a[5]*out_e[0];

				k_1 = ( out_a[4]*out_a[4] - out_a[0]*out_a[1] )/out_a[0]/out_a[0];
				k_2 = ( 2.*out_a[2]*out_a[4] - 2.*out_a[0]*out_a[3] )/out_a[0]/out_a[0];
				k_3 = ( out_a[2]*out_a[2]-out_a[0]*out_a[5] )/out_a[0]/out_a[0];
				k_4 = -out_a[2]/out_a[0];
				k_5 = -out_a[4]/out_a[0];
			} else {
				if (out_a[0]==0 && out_e[0]!=0 ) {
					fx_1 = 2.*(out_e[0]*(out_a[2] + out_e[2]/out_e[0]) - out_e[2]);
					fx_2 = 2.*(out_e[0]*(out_a[4] + out_e[4]/out_e[0]) - out_e[4]);
					fx_3 = out_e[1] - out_e[0]*(out_a[1] + out_e[1]/out_e[0]);
					fx_4 = 2.*(out_e[3] - out_e[0]*(out_a[3] + out_e[3]/out_e[0]));
					fx_5 = out_e[5] - (out_a[5] + out_e[5]/out_e[0])*out_e[0];

					k_1 = ( (out_a[4] + out_e[4]/out_e[0])*(out_a[4] + out_e[4]/out_e[0]) - (out_a[1] + out_e[1]/out_e[0]) );
					k_2 = ( 2.*(out_a[2] + out_e[2]/out_e[0])*(out_a[4] + out_e[4]/out_e[0]) - 2.*(out_a[3] + out_e[3]/out_e[0]) );
					k_3 = ( (out_a[2] + out_e[2]/out_e[0])*(out_a[2] + out_e[2]/out_e[0])-(out_a[5] + out_e[5]/out_e[0]) );
					k_4 = -(out_a[2] + out_e[2]/out_e[0]);
					k_5 = -(out_a[4] + out_e[4]/out_e[0]);
				}
			}

			if ( out_a[0]==0 && out_e[0]==0){
				return;
			}


			/////
			///// the part above is 
			///// x = (fx3*y**2 + fx4*y + fx5)/(fx1 + fx2*y)
			///// used to get x value once y is known
			/////
			//// if fx1 + fx2*y == 0, then x is 
			//// x = +/-sqrt(k1*y**2 + k2*y + k3) + (k4 + k5*y)
			////


			double g_1 = 4.*out_e[0]*out_e[0]*k_5*k_5 + 4.*out_e[4]*out_e[4] + 8.*out_e[0]*out_e[4]*k_5;
			double m_1 = g_1*k_1;
			double g_2 = 8.*out_e[0]*out_e[0]*k_4*k_5 + 8.*out_e[0]*out_e[2]*k_5 + 8.*out_e[0]*out_e[4]*k_4 + 8.*out_e[2]*out_e[4];
			double g_3 = 4.*out_e[0]*out_e[0]*k_4*k_4 + 4.*out_e[2]*out_e[2] + 8.*out_e[0]*out_e[2]*k_4;
			double g_4 = out_e[0]*k_1 + out_e[0]*k_5*k_5;
			double g_5 = out_e[0]*k_2 + 2.*out_e[0]*k_4*k_5 + 2.*out_e[2]*k_5;
			double g_6 = out_e[0]*k_3 + out_e[0]*k_4*k_4 + 2.*out_e[2]*k_4 + out_e[5];

			double m_2 = g_1*k_2 + g_2*k_1;
			double m_3 = g_1*k_3 + g_2*k_2 + g_3*k_1;
			double m_4 = g_2*k_3 + g_3*k_2;
			double m_5 = g_3*k_3;

			double m_6  = out_e[1]*out_e[1] + 4.*out_e[4]*out_e[4]*k_5*k_5 + 4.*out_e[1]*out_e[4]*k_5;
			double m_7  = 4.*out_e[1]*out_e[3] + 8.*out_e[4]*out_e[4]*k_4*k_5 + 4.*out_e[1]*out_e[4]*k_4 + 8.*out_e[3]*out_e[4]*k_5;
			double m_8  = 4.*out_e[3]*out_e[3] + 4.*out_e[4]*out_e[4]*k_4*k_4 + 8.*out_e[3]*out_e[4]*k_4;
			double m_80 = pow(g_4,2);
			double m_81 = 2*g_4*g_5;
			double m_9  = pow(g_5,2) + 2.*g_4*g_6;
			double m_10 = 2.*g_5*g_6;
			double m_11 = g_6*g_6;

			double m_12 = 	2.*out_e[0]*out_e[1]*k_1 + 2.*out_e[0]*out_e[1]*k_5*k_5 + 4.*out_e[0]*out_e[4]*k_1*k_5 + 4.*out_e[0]*out_e[4]*pow(k_5,3);
			double m_13 = 	2.*out_e[0]*out_e[1]*k_2 + 4.*out_e[0]*out_e[1]*k_4*k_5 + 4.*out_e[1]*out_e[2]*k_5 + 
				4.*out_e[0]*(out_e[3]*k_1 + out_e[3]*k_5*k_5 + out_e[4]*k_1*k_4 + out_e[4]*k_2*k_5) + 
				12.*out_e[0]*out_e[4]*k_4*k_5*k_5 + 8.*out_e[2]*out_e[4]*k_5*k_5;
			double m_14 = 	2.*out_e[0]*out_e[1]*k_3 + 2.*out_e[0]*out_e[1]*k_4*k_4 + 4.*out_e[2]*out_e[1]*k_4 + 2.*out_e[1]*out_e[5] + 4.*out_e[0]*out_e[3]*k_2 + 
				8.*out_e[0]*out_e[3]*k_4*k_5 + 8.*out_e[3]*out_e[2]*k_5 + 4.*out_e[0]*out_e[4]*k_2*k_4 + 4.*out_e[0]*out_e[4]*k_3*k_5 + 
				12.*out_e[0]*out_e[4]*k_4*k_4*k_5 + 16.*out_e[2]*out_e[4]*k_4*k_5 + 4.*out_e[4]*out_e[5]*k_5;
			double m_15 = 	4.*out_e[0]*out_e[3]*(k_3 + k_4*k_4) + 8.*out_e[3]*out_e[2]*k_4 + 4.*out_e[3]*out_e[5] + 4.*out_e[0]*out_e[4]*(k_3*k_4 + pow(k_4,3)) + 
				8.*out_e[2]*out_e[4]*k_4*k_4 + 4.*out_e[4]*out_e[5]*k_4;

			double  re[5];
			re[0] = m_1 - m_6 - m_12 - m_80;
			re[1] = m_2 - m_7 - m_13 - m_81;
			re[2] = m_3 - m_8 - m_9 - m_14;
			re[3] = m_4 - m_10 - m_15;
			re[4] = m_5 - m_11;  



			double output[8];
			my_qu(re, output);

			int ncand(0);

			double rec_x1, rec_y1, rec_z1, rec_e1, rec_x2, rec_y2, rec_z2, rec_e2;

			for (int j=0; j<8; j+=2){
				double delta = k_1*output[j]*output[j] + k_2*output[j] + k_3;
				if ( output[j+1]==0 && delta >=0) {
					if ( (fx_1 + fx_2*output[j])!=0 ) {
						rec_x1 = (fx_3*pow(output[j],2) + fx_4*output[j] + fx_5)/(fx_1 + fx_2*output[j]);
					} else {
						rec_x1 = sqrt(delta)+k_4+k_5*output[j];
					}  

					rec_y1 = output[j];
					rec_z1 = G_8/G_7 - G_5*rec_x1/G_7 - G_6*rec_y1/G_7;
					rec_e1 = sqrt(rec_x1*rec_x1 + rec_y1*rec_y1 + rec_z1*rec_z1);
					rec_x2 = in_mpx[0] - rec_x1;
					rec_y2 = in_mpy[0] - rec_y1;
					rec_z2 = G_12/G_11 - G_9*rec_x2/G_11 - G_10*rec_y2/G_11;
					rec_e2 = sqrt(rec_x2*rec_x2 + rec_y2*rec_y2 + rec_z2*rec_z2);
					
					// self-consistence check and control of the solutions

					double m_w11 = calcMass(rec_x1+lep_a[0], rec_y1+lep_a[1], rec_z1+lep_a[2], rec_e1+lep_a[3]);
					double m_w12 = calcMass(rec_x2+lep_b[0], rec_y2+lep_b[1], rec_z2+lep_b[2], rec_e2+lep_b[3]);
					double m_t11 = calcMass(rec_x1+ bl_a[0], rec_y1+ bl_a[1], rec_z1+ bl_a[2], rec_e1+ bl_a[3]);
					double m_t12 = calcMass(rec_x2+ bl_b[0], rec_y2+ bl_b[1], rec_z2+ bl_b[2], rec_e2+ bl_b[3]);

					// m_delta_mass is 1000.0
					bool m_good_eq1 = ( fabs(in_mpx[0] -(rec_x1+rec_x2)) <= 0.01 ) * true + 
									  ( fabs(in_mpx[0] -(rec_x1+rec_x2)) > 0.01 ) * false;
					bool m_good_eq2 = ( fabs(in_mpy[0] -(rec_y1+rec_y2)) <= 0.01 ) * true +
									  ( fabs(in_mpy[0] -(rec_y1+rec_y2)) > 0.01 ) * false;
					bool m_good_eq3 = ( fabs(m_w11 - w_mass[0]) <= 1000.0 ) * true + 
									  ( fabs(m_w11 - w_mass[0]) > 1000.0 ) * false;
					bool m_good_eq4 = ( fabs(m_w12 - w_mass[1]) <= 1000.0 ) * true +
									  ( fabs(m_w12 - w_mass[1]) > 1000.0 ) * false;
					bool m_good_eq5 = ( fabs(m_t11 - t_mass[0]) <= 1000.0 ) * true +
									  ( fabs(m_t11 - t_mass[0]) > 1000.0 ) * false;
					bool m_good_eq6 = ( fabs(m_t12 - t_mass[1]) <= 1000.0 ) * true +
									  ( fabs(m_t12 - t_mass[1]) <= 1000.0 ) * false;

					bool cond = m_good_eq1 && m_good_eq2 && m_good_eq3 && m_good_eq4 && m_good_eq5 && m_good_eq6;
					
					// aqui podem nao chegar as threads todas
					//__syncthreads();
					nc[tid * 16 + 2*j] = cond * rec_x1;
					nc[tid * 16 + 2*j + 1] = cond * rec_y1;
					nc[tid * 16 + 2*j + 2] = cond * rec_z1;
					nc[tid * 16 + 2*j + 3] = cond * rec_z2;
					ncand += cond * 1;
				}
			}

			// indicates the number of solutions that this thread found
			a[tid] = ncand;
		}
	}
}

