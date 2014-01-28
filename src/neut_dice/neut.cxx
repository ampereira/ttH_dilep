#include "neut.h"



using std::vector;
using namespace std;

extern std::vector<Event::EventData> events;
extern int dilep_iterations;
extern std::vector<DilepInput> inputs;

namespace Dilep {
	namespace DICE {

		unsigned _tid = 0, size;
	
		void dilep (void) {

			size = inputs.size();
			
			double in_mpx[2 * size], in_mpy[2 * size], 
				   t_mass[2 * size], w_mass[2 * size];

			double a[5 * size], b[5 * size], c[5 * size], d[5 * size];
			double aFlags[5 * size], bFlags[5 * size], cFlags[5 * size], dFlags[5 * size];

			double *nc;
			int *count;

			double _misspx = inputs[0].getMissPx(), _misspy = inputs[0].getMissPy();

			// time measurement
			#ifdef MEASURE_DILEP
			long long int time = startTimer();
			#endif

			// Data marshalling process
			for (unsigned i = 0; i < size; ++i) {

				in_mpx[i * 2]		= inputs[i].getInMpx(0);
				in_mpx[(i * 2) + 1] = inputs[i].getInMpx(1);
				in_mpy[i * 2]		= inputs[i].getInMpy(0);
				in_mpy[(i * 2) + 1] = inputs[i].getInMpy(1);
				t_mass[i * 2]		= inputs[i].getTmass(0);
				t_mass[(i * 2) + 1] = inputs[i].getTmass(1);
				w_mass[i * 2]		= inputs[i].getWmass(0);
				w_mass[(i * 2) + 1] = inputs[i].getWmass(1);
				
				// z_lep
				a[i * 5]	   = inputs[i].getZlep().Px();
				a[(i * 5) + 1] = inputs[i].getZlep().Py();
				a[(i * 5) + 2] = inputs[i].getZlep().Pz();
				a[(i * 5) + 3] = inputs[i].getZlep().E();
				a[(i * 5) + 4] = inputs[i].getZlep().M();

				// z_lepWFlags
				aFlags[i * 5]	    = inputs[i].getZlepW().Px();
				aFlags[(i * 5) + 1] = inputs[i].getZlepW().Py();
				aFlags[(i * 5) + 2] = inputs[i].getZlepW().Pz();
				aFlags[(i * 5) + 3] = inputs[i].getZlepW().isb;
				aFlags[(i * 5) + 4] = inputs[i].getZlepW().M();

				// c_lep
				b[i * 5]	   = inputs[i].getClep().Px();
				b[(i * 5) + 1] = inputs[i].getClep().Py();
				b[(i * 5) + 2] = inputs[i].getClep().Pz();
				b[(i * 5) + 3] = inputs[i].getClep().E();
				b[(i * 5) + 4] = inputs[i].getClep().M();

				// c_lepWFlags
				bFlags[i * 5]	    = inputs[i].getClepW().Px();
				bFlags[(i * 5) + 1] = inputs[i].getClepW().Py();
				bFlags[(i * 5) + 2] = inputs[i].getClepW().Pz();
				bFlags[(i * 5) + 3] = inputs[i].getClepW().isb;
				bFlags[(i * 5) + 4] = inputs[i].getClepW().M();

				// z_bj
				c[i * 5]	   = inputs[i].getZbj().Px();
				c[(i * 5) + 1] = inputs[i].getZbj().Py();
				c[(i * 5) + 2] = inputs[i].getZbj().Pz();
				c[(i * 5) + 3] = inputs[i].getZbj().E();
				c[(i * 5) + 4] = inputs[i].getZbj().M();

				// z_bjWFlags
				cFlags[i * 5]	    = inputs[i].getZbjW().Px();
				cFlags[(i * 5) + 1] = inputs[i].getZbjW().Py();
				cFlags[(i * 5) + 2] = inputs[i].getZbjW().Pz();
				cFlags[(i * 5) + 3] = inputs[i].getZbjW().isb;
				cFlags[(i * 5) + 4] = inputs[i].getZbjW().M();

				// c_bj
				d[i * 5]	   = inputs[i].getCbj().Px();
				d[(i * 5) + 1] = inputs[i].getCbj().Py();
				d[(i * 5) + 2] = inputs[i].getCbj().Pz();
				d[(i * 5) + 3] = inputs[i].getCbj().E();
				d[(i * 5) + 4] = inputs[i].getCbj().M();

				// c_bjWFlags
				dFlags[i * 5]	    = inputs[i].getCbjW().Px();
				dFlags[(i * 5) + 1] = inputs[i].getCbjW().Py();
				dFlags[(i * 5) + 2] = inputs[i].getCbjW().Pz();
				dFlags[(i * 5) + 3] = inputs[i].getCbjW().isb;
				dFlags[(i * 5) + 4] = inputs[i].getCbjW().M();

			}

			long long unsigned dilep_executions = size * dilep_iterations;


			cout << "Max size:  " << dilep_executions << endl;
			cout << "Max size2: " << dilep_iterations << endl;
			cout << "Max size3: " << size << endl;


			// Create and execute the dilep class required by DICE
			DilepClass dp (in_mpx, in_mpy, aFlags, bFlags, cFlags, dFlags, a, b, c, d, _misspx,
						   _misspy, t_mass, w_mass, 0, 0, dilep_executions);

			dp.execute();

			nc = dp.nc;
			count = dp.a;


			// reconstruction of the normal output of dilep
			// o num de combs*vars e o num de threads

			// Watch out! Indexing witchcraft below!
			int total;
			for (Event::event_counter = 0, total = 0; Event::event_counter < events.size(); ++Event::event_counter) {
				for (unsigned comb = 0; comb < events[Event::event_counter].num_Combs * dilep_iterations; ++comb, ++total) {
					vector<myvector> result;
					// Reset the partial hasSolution per combination per variation
					int hasSolution = 0;

					unsigned index = comb % dilep_iterations;

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

					// More indexing magic to properly set the results...
					inputs[total / dilep_iterations].setHasSol(hasSolution, index);
					inputs[total / dilep_iterations].setResult(&result, index);
				}
			}

			// time measurement
			#ifdef MEASURE_DILEP
			stopTimer(time);
			#endif
			
		}
	}
}
