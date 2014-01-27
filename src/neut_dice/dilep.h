#ifndef LIP_DILEP
#define LIP_DILEP

// Include DICE related headers
//#include <config/common.h>
//#include <gamalib/gamalib.h>

#define DILEP_ITERATIONS 1

#include <iostream>
using namespace std;

#include <cmath>

#define TPI 3.14159265358979312
#define STRIDE2(array,i) array[tid * 2 + i]
#define STRIDE5(array,i) array[tid * 5 + i]

// BUG - O TAMANHO DESTA MERDA
/*
 * Tabela de tamanhos
 * iteracoes - tamanho aproximado obtido experimentalmente
 */
#define BL_SIZE1    300000		// for 1 dilep iterations
#define BL_SIZE2    950000		// for 2 dilep iterations
#define BL_SIZE4    4000000		// for 4 dilep iterations
// --== Ate aqui ta testado == --
#define BL_SIZE16   1000000		// for 16 dilep iterations
#define BL_SIZE32   1000000		// for 32 dilep iterations
#define BL_SIZE64   1000000		// for 64 dilep iterations
#define BL_SIZE128  1000000		// for 128 dilep iterations
#define BL_SIZE256  1000000		// for 256 dilep iterations
#define BL_SIZE512  1000000		// for 512 dilep iterations
#define BL_SIZE1024 1000000		// for 1024 dilep iterations

typedef double double_t;

class DilepClass/* : public work*/ {

public:
	// Input variables used for the reconstruction
	double_t *_in_mpx, *_in_mpy, *_z_lepWFlags, *_c_lepWFlags, *_z_bjWFlags, *_c_bjWFlags;
	double_t *_z_lep, *_c_lep, *_z_bj, *_c_bj, *_t_mass, *_w_mass;
	double_t _MissPx, _MissPy;

	// Partial results
	//double_t *_z_bl, *_c_bl;


	double_t _z_bl[BL_SIZE1];
	double_t _c_bl[BL_SIZE1];


	// Output and control parameters
	double_t *nc;
	int *a;
	unsigned upper_bound, lower_bound;
	long long unsigned _length;

	/*__HYBRID__*/ 
	DilepClass (void);
	DilepClass (double_t in_mpx[], double_t in_mpy[], double_t z_lepWFlags[], double_t c_lepWFlags[],
				double_t z_bjWFlags[], double_t c_bjWFlags[], double_t z_lep[], double_t c_lep[], double_t z_bj[], double_t c_bj[],
				double_t MissPx, double_t MissPy, double_t t_mass[], double_t w_mass[], unsigned up, unsigned lo, long long unsigned len);
	~DilepClass ();

	// Performs the variance and the dileptonic stuff
	void execute (void);

	//virtual ptrwork* dice (double *wl, unsigned &DEV);

	// Helper functions
	void Csqrt(double_t _ar, double_t _ai, double_t _my[]);
	void cubic(double_t a[], double_t rr[], double_t ri[]);
	void toz(double_t k[], double_t l[], double_t g[]);
	void my_qu( double_t my_in[], double_t my_val[]);
	void calcMass (double_t array[]);
	double_t calcMass (double_t x, double_t y, double_t z, double_t e);

	// Calculates dileptonic kinematics
	void calc_dilep(long long unsigned tid);

	// Applies the variance to the inputs according to a given resolution
	// Still on test version, i.e., tid must be passed as an argument
	void applyVariance (long long unsigned tid);
};

#endif
