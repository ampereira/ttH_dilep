#include "neut.h"

using std::vector;
using namespace std;

extern std::vector<Event::EventData> events;

namespace Dilep {
	namespace DICE {

		unsigned _tid = 0, size;
	
		void dilep (vector<DilepInput> &di) {

			size = di.size();
			
			double in_mpx[2 * size], in_mpy[2 * size], 
				   t_mass[2 * size], w_mass[2 * size];

			double a[5 * size], b[5 * size], c[5 * size], d[5 * size];
			double aFlags[5 * size], bFlags[5 * size], cFlags[5 * size], dFlags[5 * size];

			double *nc;
			int *count;
			int hasSolution = 0;

			double _misspx = di[0].getMissPx(), _misspy = di[0].getMissPy();

			// time measurement
			#ifdef MEASURE_DILEP
			long long int time = startTimer();
			#endif

			// Data marshalling process
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

			DilepClass dp (in_mpx, in_mpy, aFlags, bFlags, cFlags, dFlags, a, b, c, d, _misspx,
						   _misspy, t_mass, w_mass, 0, 0, size);

			dp.execute();

			nc = dp.nc;
			count = dp.a;

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
	}
}
