#ifndef DILEP_INPUT
#define DILEP_INPUT

#include <TLorentzVector.h>
#include <TRandom.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <TRandom3.h>
#include <omp.h>
#include "myvector.h"
#include "../../LipMiniAnalysis/src/TLorentzVectorWFlags.h"

#define SEED 123456.0

extern TRandom3 *t_rnd;

#ifdef D_DICE
	extern int dilep_iterations;
#endif

using namespace std;


class DilepInput {
	unsigned event_id;

	TLorentzVector z_lep, c_lep;
	TLorentzVector z_bj, c_bj;
	TLorentzVector z_bl, c_bl;

	TLorentzVectorWFlags z_bjWFlags, c_bjWFlags;
	TLorentzVectorWFlags z_lepWFlags, c_lepWFlags;
	TLorentzVectorWFlags jet1_HiggsWFlags, jet2_HiggsWFlags;

	double in_mpx[2];
	double in_mpy[2];
	double in_mpz[2];

	double t_mass[2];
	double w_mass[2];

	double MissPx, MissPy;


	#ifdef D_DICE
		vector<int> hasSolution;
		vector< vector<myvector> > result;
	#else
		int hasSolution;
		vector<myvector> result;
	#endif

public:
	DilepInput () {
	}

	DilepInput (TLorentzVector _z_lep, TLorentzVector _c_lep, TLorentzVector _z_bj, TLorentzVector _c_bj, 
				TLorentzVectorWFlags _z_bjWFlags, TLorentzVectorWFlags _c_bjWFlags, TLorentzVectorWFlags _z_lepWFlags,
				TLorentzVectorWFlags _c_lepWFlags, TLorentzVectorWFlags _jet1_HiggsWFlags, TLorentzVectorWFlags _jet2_HiggsWFlags, 
				double _in_mpx[], double _in_mpy[], double _in_mpz[], double _MissPx,
				double _MissPy, double _t_mass[], double _w_mass[], unsigned _event_id);

	DilepInput (TLorentzVector _z_lep, TLorentzVector _c_lep, TLorentzVector _z_bj, TLorentzVector _c_bj, 
				TLorentzVectorWFlags _z_bjWFlags, TLorentzVectorWFlags _c_bjWFlags, TLorentzVectorWFlags _z_lepWFlags,
				TLorentzVectorWFlags _c_lepWFlags, TLorentzVectorWFlags _jet1_HiggsWFlags, TLorentzVectorWFlags _jet2_HiggsWFlags, 
				double _in_mpx[], double _in_mpy[], double _in_mpz[], double _MissPx,
				double _MissPy, double _t_mass[], double _w_mass[], TRandom3 &_t_rnd);
	DilepInput (const DilepInput &other);

	void print (char* filename);
	void applyVariance (float res);
	void applyVariance (float res, int seed);



	// Getters and setters

	inline TLorentzVector getZlep (void) const { return z_lep; }
	inline TLorentzVector getClep (void) const { return c_lep; }
	inline TLorentzVector getZbj (void) const {	return z_bj; }
	inline TLorentzVector getCbj (void) const {	return c_bj; }
	inline TLorentzVector getZbl (void) const {	return z_bl; }
	inline TLorentzVector getCbl (void) const {	return c_bl; }
	inline TLorentzVectorWFlags getZlepW (void) const {	return z_lepWFlags; }
	inline TLorentzVectorWFlags getClepW (void) const {	return c_lepWFlags; }
	inline TLorentzVectorWFlags getZbjW (void) const { return z_bjWFlags; }
	inline TLorentzVectorWFlags getCbjW (void) const { return c_bjWFlags; }
	inline int getZlepWisb (void) const { return z_lepWFlags.isb; }
	inline int getClepWisb (void) const { return c_lepWFlags.isb; }
	inline int getZbjWisb (void) const { return z_bjWFlags.isb; }
	inline int getCbjWisb (void) const { return c_bjWFlags.isb; }
	inline TLorentzVectorWFlags getJet1HiggsW (void) const { return jet1_HiggsWFlags; }
	inline TLorentzVectorWFlags getJet2HiggsW (void) const { return jet2_HiggsWFlags; }
	inline double getMissPx (void) const { return MissPx; }
	inline double getMissPy (void) const { return MissPy; }
	inline double getInMpx (int x) const { return in_mpx[x]; }
	inline double getInMpy (int x) const { return in_mpy[x]; }
	inline double getInMpz (int x) const { return in_mpz[x]; }
	inline double getTmass (int x) const { return t_mass[x]; }
	inline double getWmass (int x) const { return w_mass[x]; }
	inline unsigned getEventID (void) const { return event_id; }

	#ifdef D_DICE
		inline int getHasSol (unsigned index) const { return hasSolution[index]; }
		inline vector<myvector> getResult (unsigned index) const { return result[index]; }

		inline void setHasSol (int x, unsigned index) { hasSolution.push_back(x); }
		inline void setResult (vector<myvector> *x, unsigned index) { result.push_back(*x); }
	#else
		//inline int getHasSol (unsigned variation) const { return hasSolution[variation]; }
		//inline vector<myvector> getResult (unsigned variation) const { return result[variation]; }

		//inline void setHasSol (unsigned variation, int x) {	hasSolution[variation] = x; }
		//inline void setResult (unsigned variation, vector<myvector> *x) { result[variation] = *x; }


		inline int getHasSol (void) const { return hasSolution; }
		inline vector<myvector> getResult (void) const { return result; }

		inline void setHasSol (int x) {	hasSolution = x; }
		inline void setResult (vector<myvector> *x) { result = *x; }
	#endif

	inline void setEventID (unsigned id) { event_id = id; }

	inline void setZblCbl (void) {
		// ---------------------------------------
		// Define TLorentzVectors for (b,l) system
		// ---------------------------------------
		z_bl = z_bj + z_lep;
		c_bl = c_bj + c_lep;
	}
};

void resetSeed(unsigned seed);
void applyVariance (vector<DilepInput> &vdi, float res, int amount);
vector<DilepInput> applyVariance (vector<DilepInput> &vdi, float res, int amount, int seed);
//std::vector<DilepInput> buildDilepIntputVector (std::vector<Event::EventData> event_vector, double _mt, double _mW, int _ttDKF_JetCombChoice, int _ttDKF_njets, int _ttDKF_njet_UserValue);

#endif
