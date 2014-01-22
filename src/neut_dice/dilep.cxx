#include "dilep.h"

DilepClass::DilepClass () {

}

DilepClass::DilepClass (double_t _in_mpx[], double_t _in_mpy[], double_t z_lepWFlags[], double_t c_lepWFlags[],
			double_t z_bjWFlags[], double_t c_bjWFlags[], double_t z_lep[], double_t c_lep[], double_t z_bj[], double_t c_bj[],
			double_t MissPx, double_t MissPy, double_t _t_mass[], double_t _w_mass[], unsigned up, unsigned lo, unsigned len) {

	_in_mpx		 = _in_mpx;
	_in_mpy		 = _in_mpy;
	_z_lepWFlags = z_lepWFlags;
	_c_lepWFlags = c_lepWFlags;
	_z_bjWFlags  = z_bjWFlags;
	_c_bjWFlags  = c_bjWFlags;
	_z_lep 		 = z_lep;
	_c_lep 		 = c_lep;
	_z_bj 		 = z_bj;
	_c_bj 		 = c_bj;
	_MissPx 	 = MissPx;
	_MissPy 	 = MissPy;
	_t_mass 	 = _t_mass;
	_w_mass 	 = _w_mass;
	upper_bound  = up;
	lower_bound  = lo;
	length		 = len;

	// Memory alocation for results
	nc	  = new double_t [16 * length];
	a 	  = new int [length];
	// Memory alocation for partial results
	_z_bl = new double_t [5 * length];
	_c_bl = new double_t [5 * length];
}

DilepClass::~DilepClass () {
	
}

/*
// Dicing function. DEV is the amount of dices and wl I have no idea...
virtual ptrwork* dice (double *wl, unsigned &DEV) {
	ptrwork *L = ne ptrwork[DEV];
	unsigned start = lower_bound;

	// Iterates through the amount of divisions to make
	for (unsigned k = 0; k < DEV - 1; ++k) {
		// Calculates the size of the partition
		unsigned size = (upper_bound - lower_bound) * wl[k];

		// Creates the new work for the current k
		if (size != 0) {
			L[k] = new DilepClass (_in_mpx, _in_mpy, _z_lepWFlags, _c_lepWFlags, _z_bjWFlags, _c_bjWFlags
								   _z_lep, _c_lep, _z_bj, _c_bj, _MissPx, _MissPy, _t_mass, _w_mass
								   start, start + size, length);

			start += size;
		} else {
			L[k] = NULL;
		}
	}
	// Last diced piece. Handled differently to avoid sizes higher than the limit
	L[DEV - 1] = new DilepClass (_in_mpx, _in_mpy, _z_lepWFlags, _c_lepWFlags, _z_bjWFlags, _c_bjWFlags
								   _z_lep, _c_lep, _z_bj, _c_bj, _MissPx, _MissPy, _t_mass, _w_mass
								   start, upper_bound, length);

	return L;
}
*/

void DilepClass::calcMass (double_t array[]) {
	double_t mm = array[3]*array[3] - (array[0]*array[0] + array[1]*array[1] + array[2]*array[2]);

	if (mm < 0.0)
		array[4] = -sqrt(-mm);
	else
		array[4] = sqrt(mm);
}

double_t DilepClass::calcMass (double_t x, double_t y, double_t z, double_t e) {
	double_t mm, mass;

	mm = e*e - (x*x + y*y + z*z);

	if (mm < 0.0)
		mass = -sqrt(-mm);
	else
		mass = sqrt(mm);

	return mass;
}

void DilepClass::applyVariance (unsigned tid) {

	//unsigned tid = threadIdx.x + blockIdx.x * blockDim.x;;

	// Using pointers for better code readbility - does it affect the performance in the kernel?
/*
	double_t *_in_mpx	  = &STRIDE2(_in_mpx, 0);
	double_t *_in_mpy 	  = &STRIDE2(_in_mpy, 0);
	double_t *z_lepWFlags = &STRIDE5(_z_lepWFlags, 0);
	double_t *c_lepWFlags = &STRIDE5(_c_lepWFlags, 0);
	double_t *z_bjWFlags  = &STRIDE5(_z_bjWFlags, 0);
	double_t *c_bjWFlags  = &STRIDE5(_c_bjWFlags, 0);
*/

//	cout << tid << " - " << 5 * tid << " - " << length << " - " << 5 * length << endl;

/*
	double_t *z_lep = &STRIDE5(_z_lep, 0);
	double_t *c_lep = &STRIDE5(_c_lep, 0);
	double_t *z_bj  = &STRIDE5(_z_bj, 0);
	double_t *c_bj  = &STRIDE5(_c_bj, 0);
	double_t *z_bl  = &STRIDE5(_z_bl, 0);
	double_t *c_bl  = &STRIDE5(_c_bl, 0);


	z_bl[0] = z_bj[0] + z_lep[0];
	z_bl[1] = z_bj[1] + z_lep[1];
	z_bl[2] = z_bj[2] + z_lep[2];
	z_bl[3] = z_bj[3] + z_lep[3];

	c_bl[0] = c_bj[0] + c_lep[0];
	c_bl[1] = c_bj[1] + c_lep[1];
	c_bl[2] = c_bj[2] + c_lep[2];
	c_bl[3] = c_bj[3] + c_lep[3];

	// Re-calculate the masses
	calcMass(z_bl);
	calcMass(c_bl);
	*/

	STRIDE5(_z_bl, 0) = STRIDE5(_z_bj, 0) + STRIDE5(_z_lep, 0);
	STRIDE5(_z_bl, 1) = STRIDE5(_z_bj, 1) + STRIDE5(_z_lep, 1);
	STRIDE5(_z_bl, 2) = STRIDE5(_z_bj, 2) + STRIDE5(_z_lep, 2);
	STRIDE5(_z_bl, 3) = STRIDE5(_z_bj, 3) + STRIDE5(_z_lep, 3);

	STRIDE5(_c_bl, 0) = STRIDE5(_c_bj, 0) + STRIDE5(_c_lep, 0);
	STRIDE5(_c_bl, 1) = STRIDE5(_c_bj, 1) + STRIDE5(_c_lep, 1);
	STRIDE5(_c_bl, 2) = STRIDE5(_c_bj, 2) + STRIDE5(_c_lep, 2);
	STRIDE5(_c_bl, 3) = STRIDE5(_c_bj, 3) + STRIDE5(_c_lep, 3);

	// Re-calculate the masses
	STRIDE5(_z_bl, 4) = calcMass(STRIDE5(_z_bl, 0),  STRIDE5(_z_bl, 1), STRIDE5(_z_bl, 2), STRIDE5(_z_bl, 3));
	STRIDE5(_c_bl, 4) = calcMass(STRIDE5(_c_bl, 0),  STRIDE5(_c_bl, 1), STRIDE5(_c_bl, 2), STRIDE5(_c_bl, 3));
}

void DilepClass::execute (void) {

	cout << sizeof(_z_bl) / sizeof(double_t) << " - " << 5 * length << endl;

	for (unsigned tid = 0; tid < length; ++tid)
		applyVariance(tid);

	for (unsigned tid = 0; tid < length; ++tid)
		calc_dilep(_t_mass, _w_mass, _in_mpx, _in_mpy, 
					_z_lep, _c_lep, _z_bl, _c_bl, nc, a, tid);
}

void DilepClass::calc_dilep( unsigned tid)
		{

	//unsigned tid = threadIdx.x + blockIdx.x * blockDim.x;
	double_t WMass_a, WMass_b, tMass_a, tMass_b, lep_a[5], lep_b[5], bl_a[5], bl_b[5];
//	double_t in_mpz[2] = {0.0, 0.0};


	WMass_a = STRIDE2(_w_mass, 0);
	tMass_a = STRIDE2(_t_mass, 0);
	WMass_b = STRIDE2(_w_mass, 1);
	tMass_b = STRIDE2(_t_mass, 1);

	for (unsigned i = 0; i < 5; ++i) {
		lep_a[i] = STRIDE5(_z_lep, i);
		lep_b[i] = STRIDE5(_c_lep, i);

		bl_a[i] = STRIDE5(_z_bl, i);
		bl_b[i] = STRIDE5(_c_bl, i);
	}

	/*
	 * G_1    0
	 * G_3    1
	 * G_5	  2
	 * G_6	  3
	 * G_7	  4
	 * G_8	  5
	 * G_9	  6
	 * G_10	  7
	 * G_11	  8
	 * G_12	  9
	 */


	double_t G[10]; 

	G[0] = (WMass_a - lep_a[4]) * (WMass_a + lep_a[4]);
	G[1] = (WMass_b - lep_b[4]) * (WMass_b + lep_b[4]);

	G[2] = ( bl_a[0]/bl_a[3] - lep_a[0]/lep_a[3] );
	G[3] = ( bl_a[1]/bl_a[3] - lep_a[1]/lep_a[3] );
	G[4] = ( bl_a[2]/bl_a[3] - lep_a[2]/lep_a[3] );
	G[5] = ( G[0]/lep_a[3] - ((tMass_a - bl_a[4]) * (tMass_a + bl_a[4]))/bl_a[3] )/2.;

	G[6] =	( bl_b[0]/bl_b[3] - lep_b[0]/lep_b[3] );
	G[7] =	( bl_b[1]/bl_b[3] - lep_b[1]/lep_b[3] );
	G[8] =	( bl_b[2]/bl_b[3] - lep_b[2]/lep_b[3] );
	G[9] =	( G[1]/lep_b[3] - ((tMass_b - bl_b[4]) * (tMass_b + bl_b[4]))/bl_b[3] )/2.;

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
	
	double_t in_a[5],out_a[6];
	in_a[0] = G[5]/G[4];
	in_a[1] = -1.0*G[2]/G[4];
	in_a[2] = -1.0*G[3]/G[4];
	in_a[3] = lep_a[3];
	in_a[4] = G[0];
	toz(in_a, lep_a, out_a);

	double_t in_c[5],out_c[6];
	in_c[0] = G[9]/G[8];
	in_c[1] = -1*G[6]/G[8];
	in_c[2] = -1*G[7]/G[8];
	in_c[3] = lep_b[3];
	in_c[4] = G[1];
	toz(in_c, lep_b, out_c);
	/////////////////////////////////////////////////////
	//////change x2 y2 equation to x1 and y1 by using
	////// 		x1+x2 = S = _in_mpx[0]
	////// 		y1+y2 = T = mpy
	/////////////////////////////////////////////////////
	double_t out_e[6];
	out_e[0] = out_c[0];
	out_e[1] = out_c[1];
	out_e[2] = -1*( out_c[0]*_in_mpx[0] + out_c[2] + out_c[4]*_in_mpy[0]);
	out_e[3] = -1*( out_c[1]*_in_mpy[0] + out_c[3] + out_c[4]*_in_mpx[0]);
	out_e[4] = out_c[4]; 
	out_e[5] =( out_c[0]*_in_mpx[0]*_in_mpx[0] + out_c[1]*_in_mpy[0]*_in_mpy[0] + 2*out_c[2]*_in_mpx[0] + 2*out_c[3]*_in_mpy[0] + out_c[5] + 2*out_c[4]*_in_mpx[0]*_in_mpy[0]);

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
	
	double_t fx[5];
	double_t k[5];

	// bad organization of the code; diminished register spilling
	if ( out_a[0]!=0  ){
		fx[0] = 2.*(out_e[0]*out_a[2] - out_a[0]*out_e[2]);
		fx[1] = 2.*(out_e[0]*out_a[4] - out_a[0]*out_e[4]);
		fx[2] = out_a[0]*out_e[1] - out_e[0]*out_a[1];
		fx[3] = 2.*(out_e[3]*out_a[0] - out_e[0]*out_a[3]);
		fx[4] = out_a[0]*out_e[5] - out_a[5]*out_e[0];

		k[0] = ( out_a[4]*out_a[4] - out_a[0]*out_a[1] )/out_a[0]/out_a[0];
		k[1] = ( 2.*out_a[2]*out_a[4] - 2.*out_a[0]*out_a[3] )/out_a[0]/out_a[0];
		k[2] = ( out_a[2]*out_a[2]-out_a[0]*out_a[5] )/out_a[0]/out_a[0];
		k[3] = -out_a[2]/out_a[0];
		k[4] = -out_a[4]/out_a[0];
	} else {
		if (out_a[0]==0 && out_e[0]!=0 ) {
			fx[0] = 2.*(out_e[0]*(out_a[2] + out_e[2]/out_e[0]) - out_e[2]);
			fx[1] = 2.*(out_e[0]*(out_a[4] + out_e[4]/out_e[0]) - out_e[4]);
			fx[2] = out_e[1] - out_e[0]*(out_a[1] + out_e[1]/out_e[0]);
			fx[3] = 2.*(out_e[3] - out_e[0]*(out_a[3] + out_e[3]/out_e[0]));
			fx[4] = out_e[5] - (out_a[5] + out_e[5]/out_e[0])*out_e[0];

			k[0] = ( (out_a[4] + out_e[4]/out_e[0])*(out_a[4] + out_e[4]/out_e[0]) - (out_a[1] + out_e[1]/out_e[0]) );
			k[1] = ( 2.*(out_a[2] + out_e[2]/out_e[0])*(out_a[4] + out_e[4]/out_e[0]) - 2.*(out_a[3] + out_e[3]/out_e[0]) );
			k[2] = ( (out_a[2] + out_e[2]/out_e[0])*(out_a[2] + out_e[2]/out_e[0])-(out_a[5] + out_e[5]/out_e[0]) );
			k[3] = -(out_a[2] + out_e[2]/out_e[0]);
			k[4] = -(out_a[4] + out_e[4]/out_e[0]);
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

	double_t g[6];
	double_t m[17];	// m_80 and m_81 are in positions 15 and 16 respectively

	g[0] = 4.*out_e[0]*out_e[0]*k[4]*k[4] + 4.*out_e[4]*out_e[4] + 8.*out_e[0]*out_e[4]*k[4];
	m[0] = g[0]*k[0];
	g[1] = 8.*out_e[0]*out_e[0]*k[3]*k[4] + 8.*out_e[0]*out_e[2]*k[4] + 8.*out_e[0]*out_e[4]*k[3] + 8.*out_e[2]*out_e[4];
	g[2] = 4.*out_e[0]*out_e[0]*k[3]*k[3] + 4.*out_e[2]*out_e[2] + 8.*out_e[0]*out_e[2]*k[3];
	g[3] = out_e[0]*k[0] + out_e[0]*k[4]*k[4];
	g[4] = out_e[0]*k[1] + 2.*out_e[0]*k[3]*k[4] + 2.*out_e[2]*k[4];
	g[5] = out_e[0]*k[2] + out_e[0]*k[3]*k[3] + 2.*out_e[2]*k[3] + out_e[5];

	m[1] = g[0]*k[1] + g[1]*k[0];
	m[2] = g[0]*k[2] + g[1]*k[1] + g[2]*k[0];
	m[3] = g[1]*k[2] + g[2]*k[1];
	m[4] = g[2]*k[2];

	m[5]  = out_e[1]*out_e[1] + 4.*out_e[4]*out_e[4]*k[4]*k[4] + 4.*out_e[1]*out_e[4]*k[4];
	m[6]  = 4.*out_e[1]*out_e[3] + 8.*out_e[4]*out_e[4]*k[3]*k[4] + 4.*out_e[1]*out_e[4]*k[3] + 8.*out_e[3]*out_e[4]*k[4];
	m[7]  = 4.*out_e[3]*out_e[3] + 4.*out_e[4]*out_e[4]*k[3]*k[3] + 8.*out_e[3]*out_e[4]*k[3];
	// old m_80
	m[15] = pow(g[3],2);
	// old m_81
	m[16] = 2*g[3]*g[4];
	m[8]  = pow(g[4],2) + 2.*g[3]*g[5];
	m[9] = 2.*g[4]*g[5];
	m[10] = g[5]*g[5];

	m[11] = 	2.*out_e[0]*out_e[1]*k[0] + 2.*out_e[0]*out_e[1]*k[4]*k[4] + 4.*out_e[0]*out_e[4]*k[0]*k[4] + 4.*out_e[0]*out_e[4]*pow(k[4],3);
	m[12] = 	2.*out_e[0]*out_e[1]*k[1] + 4.*out_e[0]*out_e[1]*k[3]*k[4] + 4.*out_e[1]*out_e[2]*k[4] + 
		4.*out_e[0]*(out_e[3]*k[0] + out_e[3]*k[4]*k[4] + out_e[4]*k[0]*k[3] + out_e[4]*k[1]*k[4]) + 
		12.*out_e[0]*out_e[4]*k[3]*k[4]*k[4] + 8.*out_e[2]*out_e[4]*k[4]*k[4];
	m[13] = 	2.*out_e[0]*out_e[1]*k[2] + 2.*out_e[0]*out_e[1]*k[3]*k[3] + 4.*out_e[2]*out_e[1]*k[3] + 2.*out_e[1]*out_e[5] + 4.*out_e[0]*out_e[3]*k[1] + 
		8.*out_e[0]*out_e[3]*k[3]*k[4] + 8.*out_e[3]*out_e[2]*k[4] + 4.*out_e[0]*out_e[4]*k[1]*k[3] + 4.*out_e[0]*out_e[4]*k[2]*k[4] + 
		12.*out_e[0]*out_e[4]*k[3]*k[3]*k[4] + 16.*out_e[2]*out_e[4]*k[3]*k[4] + 4.*out_e[4]*out_e[5]*k[4];
	m[14] = 	4.*out_e[0]*out_e[3]*(k[2] + k[3]*k[3]) + 8.*out_e[3]*out_e[2]*k[3] + 4.*out_e[3]*out_e[5] + 4.*out_e[0]*out_e[4]*(k[2]*k[3] + pow(k[3],3)) + 
		8.*out_e[2]*out_e[4]*k[3]*k[3] + 4.*out_e[4]*out_e[5]*k[3];

	double_t  re[5];
	re[0] = m[0] - m[5] - m[11] - m[15];
	re[1] = m[1] - m[6] - m[12] - m[16];
	re[2] = m[2] - m[7] - m[8] - m[13];
	re[3] = m[3] - m[9] - m[14];
	re[4] = m[4] - m[10];  



	double_t output[8];
	my_qu(re, output);

	int ncand(0);

	/*
	 * m_w11 - m_wt[0]
	 * m_w12 - m_wt[1]
	 * m_t11 - m_wt[2]
	 * m_t12 - m_wt[3]
	 */
	double_t rec_x[2], rec_y[2], rec_z[2], rec_e[2], m_wt[4];
	bool m_good_eq[6];

	for (int j=0; j<8; j+=2){
		double_t delta = k[0]*output[j]*output[j] + k[1]*output[j] + k[2];
		if ( output[j+1]==0 && delta >=0) {
			if ( (fx[0] + fx[1]*output[j])!=0 ) {
				rec_x[0] = (fx[2]*pow(output[j],2) + fx[3]*output[j] + fx[4])/(fx[0] + fx[1]*output[j]);
			} else {
				rec_x[0] = sqrt(delta)+k[3]+k[4]*output[j];
			}  

			rec_y[0] = output[j];
			rec_z[0] = G[5]/G[4] - G[2]*rec_x[0]/G[4] - G[3]*rec_y[0]/G[4];
			rec_e[0] = sqrt(rec_x[0]*rec_x[0] + rec_y[0]*rec_y[0] + rec_z[0]*rec_z[0]);
			rec_x[1] = _in_mpx[0] - rec_x[0];
			rec_y[1] = _in_mpy[0] - rec_y[0];
			rec_z[1] = G[9]/G[8] - G[6]*rec_x[1]/G[8] - G[7]*rec_y[1]/G[8];
			rec_e[1] = sqrt(rec_x[1]*rec_x[1] + rec_y[1]*rec_y[1] + rec_z[1]*rec_z[1]);
			
			// self-consistence check and control of the solutions
			m_wt[0] = calcMass(rec_x[0]+lep_a[0], rec_y[0]+lep_a[1], rec_z[0]+lep_a[2], rec_e[0]+lep_a[3]);
			m_wt[1] = calcMass(rec_x[1]+lep_b[0], rec_y[1]+lep_b[1], rec_z[1]+lep_b[2], rec_e[1]+lep_b[3]);
			m_wt[2] = calcMass(rec_x[0]+ bl_a[0], rec_y[0]+ bl_a[1], rec_z[0]+ bl_a[2], rec_e[0]+ bl_a[3]);
			m_wt[3] = calcMass(rec_x[1]+ bl_b[0], rec_y[1]+ bl_b[1], rec_z[1]+ bl_b[2], rec_e[1]+ bl_b[3]);

			// m_delta_mass is 1000.0
			m_good_eq[0] = ( fabs(_in_mpx[0] -(rec_x[0]+rec_x[1])) <= 0.01 ) * true + 
							  ( fabs(_in_mpx[0] -(rec_x[0]+rec_x[1])) > 0.01 ) * false;
			m_good_eq[1] = ( fabs(_in_mpy[0] -(rec_y[0]+rec_y[1])) <= 0.01 ) * true +
							  ( fabs(_in_mpy[0] -(rec_y[0]+rec_y[1])) > 0.01 ) * false;
			m_good_eq[2] = ( fabs(m_wt[0] - _w_mass[0]) <= 1000.0 ) * true + 
							  ( fabs(m_wt[0] - _w_mass[0]) > 1000.0 ) * false;
			m_good_eq[3] = ( fabs(m_wt[1] - _w_mass[1]) <= 1000.0 ) * true +
							  ( fabs(m_wt[1] - _w_mass[1]) > 1000.0 ) * false;
			m_good_eq[4] = ( fabs(m_wt[2] - _t_mass[0]) <= 1000.0 ) * true +
							  ( fabs(m_wt[2] - _t_mass[0]) > 1000.0 ) * false;
			m_good_eq[5] = ( fabs(m_wt[3] - _t_mass[1]) <= 1000.0 ) * true +
							  ( fabs(m_wt[3] - _t_mass[1]) <= 1000.0 ) * false;

			bool cond = m_good_eq[0] && m_good_eq[1] && m_good_eq[2] && m_good_eq[3] && m_good_eq[4] && m_good_eq[5];
			
			// Synchronize this
			nc[tid * 16 + 2*j] = cond * rec_x[0];
			nc[tid * 16 + 2*j + 1] = cond * rec_y[0];
			nc[tid * 16 + 2*j + 2] = cond * rec_z[0];
			nc[tid * 16 + 2*j + 3] = cond * rec_z[1];
			ncand += cond * 1;
		}
	}

	// indicates the number of solutions that this thread found
	a[tid] = ncand;
}

void DilepClass::toz(double_t k[], double_t l[], double_t g[]){
	//// checked !!
	///////////////////////////////////////////////////////////////////////////
	///// bring z=A+Bx+Cy to 2*D*sqrt(x**2+y**2+z**2)-2(ax+by+dz) = E
	///// simplify it to g1*x^2 + g2*y^2 + 2*g3*x + 2*g4*y + 2*g5*xy + g6 = 0
	///////////////////////////////////////////////////////////////////////////

	g[0] = 4*pow(k[3],2)*( 1 + pow(k[1],2)) - 4*pow(l[0],2) -4*pow(l[2],2)*pow(k[1],2) - 8*l[0]*l[2]*k[1];

	if ( g[0]!=0 ) { 
		g[1] = ( 4*pow(k[3],2)*( 1 + pow(k[2],2)) - 4*pow(l[1],2) -4*pow(l[2],2)*pow(k[2],2) - 8*l[1]*l[2]*k[2] )/g[0];
		g[2] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[1] - 4*l[0]*l[2]*k[0] - 2*k[4]*l[0] - 2*k[4]*l[2]*k[1] )/g[0];
		g[3] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[2] - 4*l[1]*l[2]*k[0] - 2*k[4]*l[1] - 2*k[4]*l[2]*k[2] )/g[0];
		g[4] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[1]*k[2] - 4*l[0]*l[1]   - 4*l[0]*l[2]*k[2] - 4*l[1]*l[2]*k[1] )/g[0];
		g[5] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[0] - k[4]*k[4] - 4*k[4]*l[2]*k[0] )/g[0];
		g[0] = 1.0; 
	} else {
		g[1] = (  4*pow(k[3],2)*( 1 + pow(k[2],2)) - 4*pow(l[1],2) -4*pow(l[2],2)*pow(k[2],2) - 8*l[1]*l[2]*k[2] ) ;
		g[2] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[1] - 4*l[0]*l[2]*k[0] - 2*k[4]*l[0] - 2*k[4]*l[2]*k[1] );
		g[3] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[2] - 4*l[1]*l[2]*k[0] - 2*k[4]*l[1] - 2*k[4]*l[2]*k[2] );
		g[4] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[1]*k[2] - 4*l[0]*l[1]   - 4*l[0]*l[2]*k[2] - 4*l[1]*l[2]*k[1] );
		g[5] = ( (4*pow(k[3],2)-4*l[2]*l[2])*k[0]*k[0] - k[4]*k[4] - 4*k[4]*l[2]*k[0] );
		g[0] = 0.;  
	}	 
	return;
}


///////////////////////////////////////////
void DilepClass::my_qu( double_t my_in[], double_t my_val[])
{

	///////////////////////////////////////////
	/////  find the solution /////////////////
	/////  ax^4+bx^3+cx^2+dx+e=0
	//////////////////////////////////////////

	double_t real[3]={0,0,0};
	double_t img[3]={0,0,0};
	double_t x_r[4] = {0,0,0,0};
	double_t x_i[4] = {0,0,0,0};


	/////////////////////////////////////////////
	///// in case of a==0, simplify to cubic
	///// bx^3+cx^2+dx+my_in[4]=0
	/////////////////////////////////////////////

	if ( my_in[0] ==0 && my_in[1]!=0 ){
		double_t input[4]={my_in[1],my_in[2],my_in[3],my_in[4]};
		cubic(input,real,img);
		x_r[0] = real[0];	x_i[0] = img[0];
		x_r[1] = real[1];	x_i[1] = img[1];
		x_r[2] = real[2];	x_i[2] = img[2];
		my_val[0] = x_r[0];
		my_val[1] = x_i[0];
		my_val[2] = x_r[1];
		my_val[3] = x_i[1];
		my_val[4] = x_r[2];
		my_val[5] = x_i[2];
		my_val[6] = x_r[3];
		my_val[7] = x_i[3];
		
		return;
	}


	/////////////////////////////////////////////
	///// in case of a==0 && b==0, 
	///// simplify to quadratic
	///// cx*2 + my_in[3]*x + my_in[4] =0
	/////////////////////////////////////////////

	if ( my_in[0] ==0 && my_in[1]==0 && my_in[2]!=0){
		double_t alpha = pow(my_in[3],2)-4*my_in[2]*my_in[4];
		if (alpha>=0) {
			x_r[0] = (-1*my_in[3] + sqrt(alpha))/2/my_in[2];	x_i[0] = 0;
			x_r[1] = (-1*my_in[3] - sqrt(alpha))/2/my_in[2];	x_i[1] = 0;
		} else {
			x_r[0] = (-1*my_in[3] )/2/my_in[2];	x_i[0] = sqrt(-alpha)/2/my_in[2];
			x_r[1] = (-1*my_in[3] )/2/my_in[2];	x_i[1] = -1*sqrt(-alpha)/2/my_in[2];  	
		}
		my_val[0] = x_r[0];
		my_val[1] = x_i[0];
		my_val[2] = x_r[1];
		my_val[3] = x_i[1];
		my_val[4] = x_r[2];
		my_val[5] = x_i[2];
		my_val[6] = x_r[3];
		my_val[7] = x_i[3];
		
		return;
	}


	/////////////////////////////////////////////
	///// in case of a==0 && b==0 && my_in[2]==0, 
	///// simplify to linear equation dx + my_in[4] =0
	/////////////////////////////////////////////

	if (my_in[0] ==0 && my_in[1]==0 && my_in[2]==0 && my_in[3]!=0){
		x_r[0] = -my_in[4]/my_in[3];	x_i[0] = 0;
		my_val[0] = x_r[0];
		my_val[1] = x_i[0];
		my_val[2] = x_r[1];
		my_val[3] = x_i[1];
		my_val[4] = x_r[2];
		my_val[5] = x_i[2];
		my_val[6] = x_r[3];
		my_val[7] = x_i[3];
		
		return;	
	}


	//////////////////////////////////////////////
	////  (1)the common expression
	///////////////////////////////////////////////
	double_t bb=my_in[1]/my_in[0]; double_t cc=my_in[2]/my_in[0];
	double_t dd=my_in[3]/my_in[0]; double_t ee=my_in[4]/my_in[0];

	//////////////////////////////////////////////
	////  (2) the equation changes to 
	////	x^4 + bb*x^3 + cc*x^2 + dd*x + ee=0
	////
	////  (3) substitude x=y-aa/4, then we get
	////    y^4 + f*y^2 + g*y + h =0; where
	///////////////////////////////////////////

	double_t _f = cc - 3*pow(bb,2)/8;
	double_t _g = dd + (pow(bb,3)/8) - (bb*cc/2);
	double_t _h = ee - (3*pow(bb,4)/256) + (pow(bb,2)*cc/16) - (bb*dd/4);

	////////////////////////////////////////////////////////////////////////////
	///  (4) the normal situation is f, g and h are non-zero; then		////
	//// 	the related cubic equation is					////
	//// 	z^3 + (f/2) z^2 + ( (f^2-4h)/16 )*z -g^2/64 =0;			////
	////	 it has three "squared" roots, for example, p,q and l, 		////
	//// 	then p^2, q^2 and l^2 are the root of equation above		////
	//// 	set r=-g/8(pq), then the four roots of the original quartic are	////
	//// 		x = p + q + r -bb/4;					////
	//// 		x = p - q - r -bb/4;					////
	//// 		x = -p + q - r -bb/4;					////
	//// 		x = -p - q + r -bb/4;					////
	////////////////////////////////////////////////////////////////////////////

	double_t c_1 = 1.;
	double_t c_2 = _f/2;
	double_t c_3 = (pow(_f,2)-4*_h)/16.;
	double_t c_4 = -1*pow(_g,2)/64.;

	double_t input[4]={c_1,c_2,c_3,c_4};
	cubic(input,real,img);

	////////////////////////////////////////////////
	////// (5) sqrt root of the cubic equation solutions
	////////////////////////////////////////////////

	double_t out_r[3]={0,0,0};
	double_t out_i[3]={0,0,0};
	bool _img[3]={false,false,false};
	int img_index =0;
	double_t my[2];

	for (int ii=0; ii<3; ii++){
		Csqrt(real[ii],img[ii],my);
		out_r[ii] = my[0];
		out_i[ii] = my[1];
		if ( my[1]!=0 ) {
			_img[ii]=true;
			img_index++;
		}
	}    


	///////////////////////////////////////////////
	////(x + yi)(u + vi) = (xu - yv) + (xv + yu)i
	//// calculating r = -g/(8pq)
	////////////////////////////////////////////////
	double_t r_r;	double_t r_i;
	double_t p_r;	double_t p_i;
	double_t q_r;	double_t q_i;

	if (_img[0]==_img[1] && out_r[0]*out_r[1]>0 ){
		r_r	= out_r[0]*out_r[1] - out_i[0]*out_i[1];
		r_i	= out_r[0]*out_i[1] + out_r[1]*out_i[0];
		p_r	= out_r[0]; p_i = out_i[0];
		q_r	= out_r[1]; q_i = out_i[1];
	} else {	
		for (int kk=0; kk<2; kk++) {
			for (int k=kk+1; k<3; k++) {
				if (_img[kk]==_img[k]){ 
					r_r	= out_r[kk]*out_r[k] - out_i[kk]*out_i[k];
					r_i	= out_r[kk]*out_i[k] + out_r[k]*out_i[kk];
					p_r	= out_r[kk]; p_i = out_i[kk];
					q_r	= out_r[k]; q_i = out_i[k];
				}
			}
		}
	}


	if( r_r !=0 )	{ 
		r_r 	= -1.*_g/8/r_r;
	} else {
		r_r 	= 0;
	}
	if( r_i !=0 )	{ 
		r_r 	= -1.*_g/8/r_i;
	} else {
		r_i 	= 0;
	}	

	x_r[0] = p_r + q_r + r_r -my_in[1]/my_in[0]/4;
	x_i[0] = p_i + q_i + r_i;
	x_r[1] = p_r - q_r - r_r -my_in[1]/my_in[0]/4;
	x_i[1] = p_i - q_i - r_i;
	x_r[2] = -1*p_r + q_r - r_r -my_in[1]/my_in[0]/4;
	x_i[2] = -1*p_i + q_i - r_i;
	x_r[3] = -1*p_r - q_r + r_r -my_in[1]/my_in[0]/4;
	x_i[3] = -1*p_i - q_i + r_i;

	my_val[0] = x_r[0];
	my_val[1] = x_i[0];
	my_val[2] = x_r[1];
	my_val[3] = x_i[1];
	my_val[4] = x_r[2];
	my_val[5] = x_i[2];
	my_val[6] = x_r[3];
	my_val[7] = x_i[3];
}
////////////////////end of main
///////////////////////////////////////////////////////////////
////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void DilepClass::Csqrt(double_t _ar, double_t _ai, double_t _my[])
{
	///// complex sqrt
	double_t x[4];
	if  (  (_ar == 0.0) && (_ai == 0.0) ) {
		_my[0]=0.0;
		_my[1]=0.0;
		return;
	} else {	
		x[0] =fabs(_ar);
		x[1]=fabs(_ai);
		if (x[0] >= x[1]) {
			x[2]=x[1]/x[0];
			x[3]=sqrt(x[0])*sqrt(0.5*(1.0+sqrt(1.0+x[2]*x[2])));
		} else {
			x[2]=x[0]/x[1];
			x[3]=sqrt(x[1])*sqrt(0.5*(x[2]+sqrt(1.0+x[2]*x[2])));
		}
		if (_ar>= 0.0) {
			_my[0]=x[3];
			_my[1]=_ai/(2.0*x[3]);
		} else {
			_my[1]=(_ai >= 0) ? x[3] : -x[3];
			_my[0]=_ai/(2.0*_my[1]);
		}
		return;
	}
}

//////////////////////////////////////////////////////////////////
/// cubic /// a[0]x^3+a[1]x^2+a[2]x+a[3]=0
//////////////////////////////////////////////////////////////////
void DilepClass::cubic(double_t a[], double_t rr[], double_t ri[]) {
	int i;
	double_t g, h, sh, theta;
	double_t xy[3], y[2], z[4], aa[2];

	//// initialize the results
	for (i = 0; i < 3; i ++)
	{
		rr[i] = 0.0;
		ri[i] = 0.0;
	}

	aa[0] = a[1]/3.0;
	aa[1] = a[2]/3.0;

	g = (a[0] * a[0]) * a[3] - 3.0 * a[0] * aa[0] * aa[1] + 2.0 * pow(aa[0], 3);
	h = a[0] * aa[1] - aa[0] * aa[0];
	y[0] = g * g + 4.0 * pow(h, 3);

	if (y[0] < 0.0){
		sh = sqrt(-h);
		theta = acos(g / (2.0 * h * sh)) / 3.0;
		xy[0] = 2.0 * sh * cos(theta);
		xy[1] = 2.0 * sh * cos(theta + (2.0 * TPI / 3.0));
		xy[2] = 2.0 * sh * cos(theta + (4.0 * TPI / 3.0));
		rr[0] = (xy[0] - aa[0]) / a[0];
		rr[1] = (xy[1] - aa[0]) / a[0];
		rr[2] = (xy[2] - aa[0]) / a[0];
		return;
	} else {
		y[1] = sqrt(y[0]);
		z[0] = (g + y[1]) / 2.0;
		z[1] = (g - y[1]) / 2.0;
		if (z[0] < 0.0){
			z[2] = pow(-z[0], 1.0/3.0);
			z[2] = -z[2];
		} else  z[2] = pow(z[0], 1.0/3.0);
		if (z[1] < 0.0){
			z[3] = pow(-z[1], 1.0/3.0);
			z[3] = - z[3];
		}
		else  z[3] = pow(z[1], 1.0/3.0);

		rr[0] = -(aa[0] + z[2] + z[3]) / a[0];
		rr[1] = (-2.0 * aa[0] + z[2] + z[3]) / (2.0 * a[0]);
		ri[1] = sqrt(3.0) * (z[3] - z[2]) / (2.0 * a[0]);
		rr[2] = rr[1];
		ri[2] = -ri[1];

		return;

	}
}
