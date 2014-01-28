#ifndef NEUT
#define NEUT

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <TROOT.h>
#include <TLorentzVector.h>
#include <iomanip>
#include <math.h>
#include <sys/time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "../myvector.h"
#include "../dilep_input.h"
#include "../../../LipMiniAnalysis/src/LipMiniAnalysis.h"

#include "dilep.h"

#define CUDA_THREAD_STRIDE2(a,i) a[(tid / size) * 2 + i]
#define CUDA_THREAD_STRIDE5(a,i) a[(tid / size) * 5 + i]
#define RESOLUTION 0.02
#define TO1D(nc,tid,sol,did) nc[tid*16+sol*4+did]
//#define cuRand(x) (((double) curand(x))/((double) UINT_MAX))

//#define CUDA_CALL(x) if((x) != cudaSuccess) { \
//	printf("Error at %s:%d - %d\n",__FILE__,__LINE__,x); \
//	exit (EXIT_FAILURE);}
#define CUDA_CALL(x) x



namespace Dilep {
	namespace DICE {

		void dilep (void);

	}
}

#endif
