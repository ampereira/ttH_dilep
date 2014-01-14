#ifndef LIP_DILEP
#define LIP_DILEP

//#include <config/common.h>
//#include <gamalib/gamalib.h>

#include <cmath>

#define TPI 3.14159265358979312
#define TO1D(nc,tid,sol,did) nc[tid*16+sol*4+did]
#define STRIDE2(a,i) a[tid * 2 + i]
#define STRIDE5(a,i) a[tid * 5 + i]

typedef double double_t;

class DilepClass/* : public work*/ {

public:
	// Input variables used for the reconstruction
	double_t *_in_mpx, *_in_mpy, *_z_lepWFlags, *_c_lepWFlags, *_z_bjWFlags, *_c_bjWFlags;
	double_t *_z_lep, *_c_lep, *_z_bj, *_c_bj, *_t_mass, *_w_mass;
	double_t _MissPx, _MissPy;

	// Output and control parameters
	double_t *nc;
	int *a;
	unsigned upper_bound, lower_bound, length;

	/*__HYBRID__*/ 
	DilepClass (void);
	DilepClass (double_t in_mpx[], double_t in_mpy[], double_t z_lepWFlags[], double_t c_lepWFlags[],
				double_t z_bjWFlags[], double_t c_bjWFlags[], double_t z_lep[], double_t c_lep[], double_t z_bj[], double_t c_bj[],
				double_t MissPx, double_t MissPy, double_t t_mass[], double_t w_mass[], unsigned up, unsigned lo, unsigned len);
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
	void calc_dilep(double_t t_mass[], double_t w_mass[], 
					double_t in_mpx[], double_t in_mpy[], double_t _lep_a[], 
					double_t _lep_b[], double_t _bl_a[], double_t _bl_b[], 
					double_t nc[], int a[], unsigned tid);

	// Applies the variance to the inputs according to a given resolution
	// Still on test version, i.e., tid must be passed as an argument
	void applyVariance (double_t _in_mpx[], double_t _in_mpy[], double_t _z_lepWFlags[], double_t _c_lepWFlags[],
					double_t _z_bjWFlags[], double_t _c_bjWFlags[], double_t _z_lep[], double_t _c_lep[], double_t _z_bj[], double_t _c_bj[],
					double_t _z_bl[], double_t _c_bl[], double_t _MissPx, double_t _MissPy, unsigned tid);
};

#endif
