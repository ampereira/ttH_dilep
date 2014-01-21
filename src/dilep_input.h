#ifndef DILEP_INPUT
#define DILEP_INPUT

#include <TLorentzVector.h>
#include <TRandom.h>
#include <fstream>
#include <vector>
#include <string.h>
#include "myvector.h"
#include "../../LipMiniAnalysis/src/LipMiniAnalysis.h"

#define SEED 123456.0

extern TRandom3 *t_rnd;

#ifdef D_DICE
	extern int dilep_iterations;
#endif

using namespace std;


class DilepInput {

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
		//int hasSolution[dilep_iterations];
		int hasSolution;
		//vector< vector<myvector> > result;
		vector<myvector> result;
	#else
		int hasSolution;
		vector<myvector> result;
	#endif

public:
	DilepInput () {
	}
	unsigned event_id;

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

inline TLorentzVector DilepInput::getZlep (void) const { return z_lep; }
inline TLorentzVector DilepInput::getClep (void) const { return c_lep; }
inline TLorentzVector DilepInput::getZbj (void) const {	return z_bj; }
inline TLorentzVector DilepInput::getCbj (void) const {	return c_bj; }
inline TLorentzVector DilepInput::getZbl (void) const {	return z_bl; }
inline TLorentzVector DilepInput::getCbl (void) const {	return c_bl; }
inline TLorentzVectorWFlags DilepInput::getZlepW (void) const {	return z_lepWFlags; }
inline TLorentzVectorWFlags DilepInput::getClepW (void) const {	return c_lepWFlags; }
inline TLorentzVectorWFlags DilepInput::getZbjW (void) const { return z_bjWFlags; }
inline TLorentzVectorWFlags DilepInput::getCbjW (void) const { return c_bjWFlags; }
inline int DilepInput::getZlepWisb (void) const { return z_lepWFlags.isb; }
inline int DilepInput::getClepWisb (void) const { return c_lepWFlags.isb; }
inline int DilepInput::getZbjWisb (void) const { return z_bjWFlags.isb; }
inline int DilepInput::getCbjWisb (void) const { return c_bjWFlags.isb; }
inline TLorentzVectorWFlags DilepInput::getJet1HiggsW (void) const { return jet1_HiggsWFlags; }
inline TLorentzVectorWFlags DilepInput::getJet2HiggsW (void) const { return jet2_HiggsWFlags; }
inline double DilepInput::getMissPx (void) const { return MissPx; }
inline double DilepInput::getMissPy (void) const { return MissPy; }
inline double DilepInput::getInMpx (int x) const { return in_mpx[x]; }
inline double DilepInput::getInMpy (int x) const { return in_mpy[x]; }
inline double DilepInput::getInMpz (int x) const { return in_mpz[x]; }
inline double DilepInput::getTmass (int x) const { return t_mass[x]; }
inline double DilepInput::getWmass (int x) const { return w_mass[x]; }

#ifdef D_DICE
	inline int DilepInput::getHasSol (unsigned index) const {
		//return hasSolution[index];
		return hasSolution;
	}

	inline vector<myvector> DilepInput::getResult (unsigned index) const {
		//return result[index];
		return result;
	}

	inline void DilepInput::setHasSol (int x, unsigned index) {
		//hasSolution[index] = x;
		hasSolution = x;
	}

	inline void DilepInput::setResult (vector<myvector> *x, unsigned index) {
		//result[index].assign(x->begin(), x->end());
		result = *x;
	}
#else
	inline int DilepInput::getHasSol (void) const {
		return hasSolution;
	}

	inline vector<myvector> DilepInput::getResult (void) const {
		return result;
	}
	inline void DilepInput::setHasSol (int x) {
		hasSolution = x;
	}

	inline void DilepInput::setResult (vector<myvector> *x) {
		result = *x;
	}
#endif

inline void DilepInput::setZblCbl (void) {
	// ---------------------------------------
	// Define TLorentzVectors for (b,l) system
	// ---------------------------------------
	z_bl = z_bj + z_lep;
	c_bl = c_bj + c_lep;
}
};

void applyVariance (vector<DilepInput> &vdi, float res, int amount);
vector<DilepInput> applyVariance (vector<DilepInput> &vdi, float res, int amount, int seed);
//std::vector<DilepInput> buildDilepIntputVector (std::vector<Event::EventData> event_vector, double _mt, double _mW, int _ttDKF_JetCombChoice, int _ttDKF_njets, int _ttDKF_njet_UserValue);

#endif
