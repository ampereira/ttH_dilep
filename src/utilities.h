#ifndef UTILITIES
#define UTILITIES

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <cmath>
#include <queue>
#include <TRandom.h>

#ifdef MIC
	#include <offload.h>
#endif

#ifdef OMP
	#include <omp.h>
	#include "ttDKF_Best_Sol.h"
#endif

#define APP_TIME_RESOLUTION 1000000.0	// time measuring resolution (us)
#define DEFAULT_DILEP 1					// default number of dilep iterations
#define DEFAULT_THREADS 1				// default number of threads
#define SEED 123456.0					// default seed for the PRNG


namespace Dilep {

	// timer functions
	long long int startTimer (void);
	long long int stopTimer (long long int);
	void printTimer (void);
}

namespace ttH {

	void defineDilepIterations (void);
	void defineNumThreads (void);
	long long int startTimer (void);
	long long int stopTimer (long long int);

	#ifdef MIC
	namespace Phi {
		void setupPhi(void);
	}
	#endif

	namespace KinFit {
		long long int startTimer (void);
		long long int stopTimer (long long int);
		void printTimer (void);

		#ifdef OMP
		ttDKF_Best_Sol reduce (ttDKF_Best_Sol[]);
		#endif
	}
}

#endif