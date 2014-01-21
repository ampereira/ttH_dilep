#include "dilep_input.h"

DilepInput::DilepInput (TLorentzVector _z_lep, TLorentzVector _c_lep, TLorentzVector _z_bj, TLorentzVector _c_bj,
						TLorentzVectorWFlags _z_bjWFlags, TLorentzVectorWFlags _c_bjWFlags, TLorentzVectorWFlags _z_lepWFlags,
						TLorentzVectorWFlags _c_lepWFlags, TLorentzVectorWFlags _jet1_HiggsWFlags, TLorentzVectorWFlags _jet2_HiggsWFlags,
						double _in_mpx[], double _in_mpy[], double _in_mpz[], double _MissPx,
						double _MissPy, double _t_mass[], double _w_mass[], TRandom3 &_t_rand) {

	z_lep = _z_lep;
	c_lep = _c_lep;
	z_bj = _z_bj;
	c_bj = _c_bj;

	z_bjWFlags = _z_bjWFlags;
	c_bjWFlags = _c_bjWFlags;
	z_lepWFlags = _z_lepWFlags;
	c_lepWFlags = _c_lepWFlags;
	jet1_HiggsWFlags = _jet1_HiggsWFlags;
	jet2_HiggsWFlags = _jet2_HiggsWFlags;

	in_mpx[0] = _in_mpx[0];
	in_mpx[1] = _in_mpx[1];
	in_mpy[0] = _in_mpy[0];
	in_mpy[1] = _in_mpy[1];
	in_mpz[0] = _in_mpz[0];
	in_mpz[1] = _in_mpz[1];

	MissPx = _MissPx;
	MissPy = _MissPy;

	t_mass[0] = _t_mass[0];
	t_mass[1] = _t_mass[1];
	w_mass[0] = _w_mass[0];
	w_mass[1] = _w_mass[1];

	#ifndef D_DICE
		hasSolution = 0;
	#endif
}

// Constructor
DilepInput::DilepInput (TLorentzVector _z_lep, TLorentzVector _c_lep, TLorentzVector _z_bj, TLorentzVector _c_bj,
						TLorentzVectorWFlags _z_bjWFlags, TLorentzVectorWFlags _c_bjWFlags, TLorentzVectorWFlags _z_lepWFlags,
						TLorentzVectorWFlags _c_lepWFlags, TLorentzVectorWFlags _jet1_HiggsWFlags, TLorentzVectorWFlags _jet2_HiggsWFlags,
						double _in_mpx[], double _in_mpy[], double _in_mpz[], double _MissPx,
						double _MissPy, double _t_mass[], double _w_mass[], unsigned _event_id) {

	z_lep = _z_lep;
	c_lep = _c_lep;
	z_bj = _z_bj;
	c_bj = _c_bj;

	z_bjWFlags = _z_bjWFlags;
	c_bjWFlags = _c_bjWFlags;
	z_lepWFlags = _z_lepWFlags;
	c_lepWFlags = _c_lepWFlags;
	jet1_HiggsWFlags = _jet1_HiggsWFlags;
	jet2_HiggsWFlags = _jet2_HiggsWFlags;

	in_mpx[0] = _in_mpx[0];
	in_mpx[1] = _in_mpx[1];
	in_mpy[0] = _in_mpy[0];
	in_mpy[1] = _in_mpy[1];
	in_mpz[0] = _in_mpz[0];
	in_mpz[1] = _in_mpz[1];

	MissPx = _MissPx;
	MissPy = _MissPy;

	t_mass[0] = _t_mass[0];
	t_mass[1] = _t_mass[1];
	w_mass[0] = _w_mass[0];
	w_mass[1] = _w_mass[1];

	event_id = _event_id;

	#ifdef D_DICE
		//hasSolution = new int [dilep_iterations];
		//result 		= new vector<myvector> [dilep_iterations];
	#else
		hasSolution = 0;
	#endif

}

// Constructor
DilepInput::DilepInput (const DilepInput &other) {

	in_mpx[0] = other.getInMpx(0);
	in_mpx[1] = other.getInMpx(1);
	in_mpy[0] = other.getInMpy(0);
	in_mpy[1] = other.getInMpy(1);
	in_mpz[0] = other.getInMpz(0);
	in_mpz[1] = other.getInMpz(1);

	t_mass[0] = other.getTmass(0);
	t_mass[1] = other.getTmass(1);
	w_mass[0] = other.getWmass(0);
	w_mass[1] = other.getWmass(1);

	MissPx = other.getMissPx();
	MissPy = other.getMissPy();

	z_lep = other.getZlep();
	c_lep = other.getClep();
	z_bj = other.getZbj();
	c_bj = other.getCbj();

	z_bjWFlags = other.getZbjW();
	c_bjWFlags = other.getCbjW();
	z_lepWFlags = other.getZlepW();
	c_lepWFlags = other.getClepW();

	jet1_HiggsWFlags = other.getJet1HiggsW();
	jet2_HiggsWFlags = other.getJet2HiggsW();

	z_bl = other.getZbl();
	c_bl = other.getCbl();

	#ifndef D_DICE
		hasSolution = other.getHasSol();
		result = other.getResult();
	#endif
}

// Constructor
/*DilepInput::DilepInput (void) {
	//t_rnd.SetSeed(SEED);
	hasSolution = 0;
}*/
// Print the private variables of the class for debug purposes
void DilepInput::print (char* filename) {
	ofstream file (filename, fstream::app);

	file << "in_mpx " << in_mpx[0] << " " << in_mpx[1] << endl;
	file << "in_mpy " << in_mpy[0] << " " << in_mpy[1] << endl;
	file << "in_mpz " << in_mpz[0] << " " << in_mpz[1] << endl;

	file << "MissPx " << MissPx << endl;
	file << "MissPy " << MissPy << endl;

	file << "t_mass " << t_mass[0] << " " << t_mass[1] << endl;
	file << "w_mass " << w_mass[0] << " " << w_mass[1] << endl;

	file << "z_lep " << z_lep.Px() << " " << z_lep.Py() << " " << z_lep.Pz() << " " << z_lep.E() << endl;
	file << "c_lep " << c_lep.Px() << " " << c_lep.Py() << " " << c_lep.Pz() << " " << c_lep.E() << endl;
	file << "z_bj " << z_bj.Px() << " " << z_bj.Py() << " " << z_bj.Pz() << " " << z_bj.E() << endl;
	file << "c_bj " << c_bj.Px() << " " << c_bj.Py() << " " << c_bj.Pz() << " " << c_bj.E() << endl;

	file << "z_bjWFlags " << z_bjWFlags.Px() << " " << z_bjWFlags.Py() << " " << z_bjWFlags.Pz() << " " << z_bjWFlags.E() << endl;
	file << "c_bjWFlags " << c_bjWFlags.Px() << " " << c_bjWFlags.Py() << " " << c_bjWFlags.Pz() << " " << c_bjWFlags.E() << endl;
	file << "z_lepWFlags " << z_lepWFlags.Px() << " " << z_lepWFlags.Py() << " " << z_lepWFlags.Pz() << " " << z_lepWFlags.E() << endl;
	file << "c_lepWFlags " << c_lepWFlags.Px() << " " << c_lepWFlags.Py() << " " << c_lepWFlags.Pz() << " " << c_lepWFlags.E() << endl;

	file << "jet1_HiggsWFlags " << jet1_HiggsWFlags.Px() << " " << jet1_HiggsWFlags.Py() << " " << jet1_HiggsWFlags.Pz() << " " << jet1_HiggsWFlags.E() << endl;
	file << "jet2_HiggsWFlags " << jet2_HiggsWFlags.Px() << " " << jet2_HiggsWFlags.Py() << " " << jet2_HiggsWFlags.Pz() << " " << jet2_HiggsWFlags.E() << endl;

	file.close();
}

// Apply variance to the inputs of the dilep function a given number of times
// resulting a vector of varied inputs
// Uses given seed
vector<DilepInput> applyVariance (vector<DilepInput> &vdi, float res, int amount, int seed) {
	vector<DilepInput> inputs;

	for (int i = 0; i < vdi.size(); ++i) {
		DilepInput di = vdi[i];

		for (int j = 0; j < amount; ++j) {
			DilepInput aux (di);
			aux.applyVariance (res, seed + i * j);

			inputs.push_back (aux);
		}
	}

	return inputs;
}

// Apply variance to the inputs of the dilep function a given number of times
// resulting a vector of varied inputs
// Uses default seed
void applyVariance (vector<DilepInput> &vdi, float res, int amount) {
	unsigned size = vdi.size();

	for (unsigned i = 0; i < size; ++i) {
		for (int j = 0; j < amount; ++j) {
			DilepInput aux (vdi[i]);
			aux.applyVariance (res);

			vdi.push_back (aux);
		}
		vdi[i].applyVariance(res);
	}
}

// Apply variance to the inputs of the dilep function, given a resolution and a seed,
// following a Gaussian distribution
// Use given seed
void DilepInput::applyVariance (float res, int seed) {
	#ifndef CUDA
	// Resolution values
	double Sx_e = res, Sy_e = res, Sz_e = res, St_e = res, Se_e = res;  // electrons
	double Sx_m = res, Sy_m = res, Sz_m = res, St_m = res, Se_m = res;  // muons
	double Sx_j = res, Sy_j = res, Sz_j = res, St_j = res, Se_j = res;  // jets

	// new four-vectors	
	double n_Px, n_Py, n_Pz, n_Pt, n_E;	
	double delPx, delPy;
	
	#ifdef OMP
	unsigned thread_id = omp_get_thread_num();
	#else
	unsigned thread_id = 0;
	#endif
	// Initialize the random number generator
	t_rnd[thread_id].SetSeed (seed);

	// Vary!

	// _______________________________
	// _______z_lep___________________
	// _______________________________
	if (  abs(  z_lepWFlags.isb  )  ==  11  ){ //___electrons____
		n_Px = z_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_e ) );
		n_Py = z_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_e ) );
		n_Pz = z_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_e ) );
		//n_Pt = z_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_e ) );
		//n_E  = z_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_e ) );
	} else if (  abs(z_lepWFlags.isb) == 13 ){ //_____muons______
		n_Px = z_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_m ) );
		n_Py = z_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_m ) );
		n_Pz = z_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_m ) );
		//n_Pt = z_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_m ) );
		//n_E  = z_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_m ) );
	}
	// Recalculate z_lep
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + z_lepWFlags.M()*z_lepWFlags.M() );
	z_lep.SetPx( n_Px );	// Change Px 				
	z_lep.SetPy( n_Py ); 	// Change Py 	
	z_lep.SetPz( n_Pz ); 	// Change Pz 
	z_lep.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = z_lepWFlags.Px() - n_Px; 
	delPy = z_lepWFlags.Py() - n_Py;			
	in_mpx[0] = MissPx + delPx; in_mpx[1] = MissPx + delPx; // initialize miss(Px,Py) neutrino 1
	in_mpy[0] = MissPy + delPy; in_mpy[1] = MissPy + delPy; // initialize miss(Px,Py) neutrino 2
	in_mpz[0] = 0.            ; in_mpz[1] = 0.;		// initialize neutrinos Pz to zero

	// _______________________________
	// _______c_lep___________________
	// _______________________________
	if (  abs(  c_lepWFlags.isb  )  ==  11  ){ //___electrons____
		n_Px = c_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_e ) );
		n_Py = c_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_e ) );
		n_Pz = c_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_e ) );
		//n_Pt = c_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_e ) );
		//n_E  = c_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_e ) );
	} else if (  abs(c_lepWFlags.isb) == 13 ){ //_____muons______
		n_Px = c_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_m ) );
		n_Py = c_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_m ) );
		n_Pz = c_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_m ) );
		//n_Pt = c_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_m ) );
		//n_E  = c_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_m ) );
	}
	// Recalculate c_lep
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + c_lepWFlags.M()*c_lepWFlags.M() );
	c_lep.SetPx( n_Px );	// Change Px 				
	c_lep.SetPy( n_Py ); 	// Change Py 	
	c_lep.SetPz( n_Pz ); 	// Change Pz 
	c_lep.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = c_lepWFlags.Px() - n_Px; 
	delPy = c_lepWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero

	// _______________________________
	// _______z_bj____________________
	// _______________________________
	n_Px = z_bjWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_j ) );
	n_Py = z_bjWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_j ) );
	n_Pz = z_bjWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_j ) );
//	n_Pt = z_bjWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_j ) );
//	n_E  = z_bjWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_j ) );
	// Recalculate z_bj
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + z_bjWFlags.M()*z_bjWFlags.M() );
	z_bj.SetPx( n_Px );	// Change Px 				
	z_bj.SetPy( n_Py ); 	// Change Py 	
	z_bj.SetPz( n_Pz ); 	// Change Pz 
	z_bj.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = z_bjWFlags.Px() - n_Px; 
	delPy = z_bjWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero


	// _______________________________
	// _______c_bj____________________
	// _______________________________
	n_Px = c_bjWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_j ) );
	n_Py = c_bjWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_j ) );
	n_Pz = c_bjWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_j ) );
//	n_Pt = c_bjWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_j ) );
//	n_E  = c_bjWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_j ) );
	// Recalculate c_bj
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + c_bjWFlags.M()*c_bjWFlags.M() );
	c_bj.SetPx( n_Px );	// Change Px 				
	c_bj.SetPy( n_Py ); 	// Change Py 	
	c_bj.SetPz( n_Pz ); 	// Change Pz 
	c_bj.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = c_bjWFlags.Px() - n_Px; 
	delPy = c_bjWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero

	// ---------------------------------------
	// Define TLorentzVectors for (b,l) system
	// ---------------------------------------
	z_bl = z_bj + z_lep;
	c_bl = c_bj + c_lep;

#endif
}

// Apply variance to the inputs of the dilep function, given a resolution and a seed,
// following a Gaussian distribution
// Use default seed
void DilepInput::applyVariance (float res) {
	#ifndef CUDA
	// Resolution values
	double Sx_e = res, Sy_e = res, Sz_e = res, St_e = res, Se_e = res;  // electrons
	double Sx_m = res, Sy_m = res, Sz_m = res, St_m = res, Se_m = res;  // muons
	double Sx_j = res, Sy_j = res, Sz_j = res, St_j = res, Se_j = res;  // jets

	// new four-vectors	
	double n_Px, n_Py, n_Pz, n_Pt, n_E;	
	double delPx, delPy;

	#ifdef OMP
	unsigned thread_id = omp_get_thread_num();
	#else
	unsigned thread_id = 0;
	#endif
	// Vary!

	// _______________________________
	// _______z_lep___________________
	// _______________________________
	if (  abs(  z_lepWFlags.isb  )  ==  11  ){ //___electrons____
		n_Px = z_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_e ) );
		n_Py = z_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_e ) );
		n_Pz = z_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_e ) );
		//n_Pt = z_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_e ) );
		//n_E  = z_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_e ) );
	} else if (  abs(z_lepWFlags.isb) == 13 ){ //_____muons______
		n_Px = z_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_m ) );
		n_Py = z_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_m ) );
		n_Pz = z_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_m ) );
		//n_Pt = z_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_m ) );
		//n_E  = z_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_m ) );
	}
	// Recalculate z_lep
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + z_lepWFlags.M()*z_lepWFlags.M() );
	z_lep.SetPx( n_Px );	// Change Px 				
	z_lep.SetPy( n_Py ); 	// Change Py 	
	z_lep.SetPz( n_Pz ); 	// Change Pz 
	z_lep.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = z_lepWFlags.Px() - n_Px; 
	delPy = z_lepWFlags.Py() - n_Py;			
	in_mpx[0] = MissPx + delPx; in_mpx[1] = MissPx + delPx; // initialize miss(Px,Py) neutrino 1
	in_mpy[0] = MissPy + delPy; in_mpy[1] = MissPy + delPy; // initialize miss(Px,Py) neutrino 2
	in_mpz[0] = 0.            ; in_mpz[1] = 0.;		// initialize neutrinos Pz to zero

	// _______________________________
	// _______c_lep___________________
	// _______________________________
	if (  abs(  c_lepWFlags.isb  )  ==  11  ){ //___electrons____
		n_Px = c_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_e ) );
		n_Py = c_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_e ) );
		n_Pz = c_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_e ) );
		//n_Pt = c_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_e ) );
		//n_E  = c_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_e ) );
	} else if (  abs(c_lepWFlags.isb) == 13 ){ //_____muons______
		n_Px = c_lepWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_m ) );
		n_Py = c_lepWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_m ) );
		n_Pz = c_lepWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_m ) );
		//n_Pt = c_lepWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_m ) );
		//n_E  = c_lepWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_m ) );
	}
	// Recalculate c_lep
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + c_lepWFlags.M()*c_lepWFlags.M() );
	c_lep.SetPx( n_Px );	// Change Px 				
	c_lep.SetPy( n_Py ); 	// Change Py 	
	c_lep.SetPz( n_Pz ); 	// Change Pz 
	c_lep.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = c_lepWFlags.Px() - n_Px; 
	delPy = c_lepWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero

	// _______________________________
	// _______z_bj____________________
	// _______________________________
	n_Px = z_bjWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_j ) );
	n_Py = z_bjWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_j ) );
	n_Pz = z_bjWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_j ) );
	//n_Pt = z_bjWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_j ) );
	//n_E  = z_bjWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_j ) );
	// Recalculate z_bj
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + z_bjWFlags.M()*z_bjWFlags.M() );
	z_bj.SetPx( n_Px );	// Change Px 				
	z_bj.SetPy( n_Py ); 	// Change Py 	
	z_bj.SetPz( n_Pz ); 	// Change Pz 
	z_bj.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = z_bjWFlags.Px() - n_Px; 
	delPy = z_bjWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero


	// _______________________________
	// _______c_bj____________________
	// _______________________________
	n_Px = c_bjWFlags.Px() * ( 1. + t_rnd[thread_id].Gaus( 0., Sx_j ) );
	n_Py = c_bjWFlags.Py() * ( 1. + t_rnd[thread_id].Gaus( 0., Sy_j ) );
	n_Pz = c_bjWFlags.Pz() * ( 1. + t_rnd[thread_id].Gaus( 0., Sz_j ) );
	//n_Pt = c_bjWFlags.Pt() * ( 1. + t_rnd[thread_id].Gaus( 0., St_j ) );
	//n_E  = c_bjWFlags.E()  * ( 1. + t_rnd[thread_id].Gaus( 0., Se_j ) );
	// Recalculate c_bj
	n_E = sqrt ( n_Px*n_Px + n_Py*n_Py + n_Pz*n_Pz + c_bjWFlags.M()*c_bjWFlags.M() );
	c_bj.SetPx( n_Px );	// Change Px 				
	c_bj.SetPy( n_Py ); 	// Change Py 	
	c_bj.SetPz( n_Pz ); 	// Change Pz 
	c_bj.SetE(  n_E  ); 	// Change E 
	// Propagate to MissPx and MissPy
	delPx = c_bjWFlags.Px() - n_Px; 
	delPy = c_bjWFlags.Py() - n_Py;			
	in_mpx[0] += delPx; in_mpx[1] += delPx; // correct miss(Px,Py) neutrino 1
	in_mpy[0] += delPy; in_mpy[1] += delPy; // correct miss(Px,Py) neutrino 2
	in_mpz[0] += 0.   ; in_mpz[1] += 0.;	// initialize neutrinos Pz to zero

	// ---------------------------------------
	// Define TLorentzVectors for (b,l) system
	// ---------------------------------------
	z_bl = z_bj + z_lep;
	c_bl = c_bj + c_lep;

	/*cout << z_bl.Px() << " - " << z_bj.Px() << " - " << z_lep.Px() << endl;
	cout << z_bl.Py() << " - " << z_bj.Py() << " - " << z_lep.Py() << endl;
	cout << z_bl.Pz() << " - " << z_bj.Pz() << " - " << z_lep.Pz() << endl;
	cout << z_bl.E()  << " - " << z_bj.E()  << " - " << z_lep.E()  << endl;
	cout << z_bl.M()  << " - " << z_bj.M()  << " - " << z_lep.M()  << endl;
	exit(0);*/
	#endif
}


// Builds the DilepInput vector with all events
/*std::vector<DilepInput> buildDilepIntputVector (std::vector<Event::EventData> event_vector, double _mt, double _mW, int _ttDKF_JetCombChoice, int _ttDKF_njets, int _ttDKF_njet_UserValue) {
	std::vector<DilepInput> inputs;
	unsigned event_size = event_vector.size();
    double t_m[2] = {_mt, _mt};        	// initialize top quarks masses
    double w_m[2] = {_mW, _mW};        	// initialize W bosons masses
    double in_mpz[2] = {0., 0.};        // initialize neutrinos Pz to zero
    std::vector<TLorentzVectorWFlags> MyChoiceJetVec;

	// Some global settings
	_ttDKF_JetCombChoice = 1;



	//for (Event::event_counter = 0; Event::event_counter < event_size; ++Event::event_counter) {
    	double in_mpx[2] = {event_vector[Event::event_counter].MissPx, event_vector[Event::event_counter].MissPx};    // initialize miss(Px_neutrino1, Px_neutrino2)
    	double in_mpy[2] = {event_vector[Event::event_counter].MissPy, event_vector[Event::event_counter].MissPy};    // initialize miss(Py_neutrino1, Py_neutrino2)
		
		// -----------------------------------------------------------------
		//  ttDKF_JetCombChoice = 1  Use N jets, b and non-b 
		//               NOTE: pass MyChoiceJetVec  to the tool 
		//                     pass ttDKF_njets = number of jets  
		//               (do nothing but pass the vectors)
		//  by: S.Amor 13.Dez.2012
		// -----------------------------------------------------------------
		if ( _ttDKF_JetCombChoice == 1 ){
			for (int jetID=0; jetID<event_vector[Event::event_counter].MyGoodJetVec.size();  ++jetID){
				MyChoiceJetVec.push_back(event_vector[Event::event_counter].MyGoodJetVec[jetID]);
			}
			// -----------------------------------------------------------------
			// USER INPUT NUMBER OF JETS PER EVENT FOR PERMUTATIONS :
			// -----------------------------------------------------------------
			_ttDKF_njets = _ttDKF_njet_UserValue;     // value range: [4; MyGoodJetVec.size()]         

			if ( _ttDKF_njets > event_vector[Event::event_counter].MyGoodJetVec.size() ) {
				_ttDKF_njets = event_vector[Event::event_counter].MyGoodJetVec.size();  // value range: [2; MyGoodJetVec.size()]        
			}
			if (_ttDKF_njets < 4){
				//cout << "WARNING: NUMBER OF JETS INSUFFICIENT FOR KINEMATIC RECONSTRUCTION" << endl;
				_ttDKF_JetCombChoice = 0; // does not compute kinematic fit
			}
    	}

		// build the structure
		if ( _ttDKF_JetCombChoice == 1 ){ 
			for ( int j1=0; j1 < _ttDKF_njets ; j1++){
				for ( int j2=0; j2 < _ttDKF_njets ; j2++){
					if (j1!=j2){
						for ( int j3=0; j3 < _ttDKF_njets-1 ; j3++){
							if (( j3!=j1) && ( j3!=j2)){        // no repetition of jets
								for ( int j4=j3+1; j4 < _ttDKF_njets ; j4++){
									if (( j4!=j1) && ( j4!=j2)){        // no repetition of jets

										DilepInput di (event_vector[Event::event_counter].LeptonVec[0], event_vector[Event::event_counter].LeptonVec[1], MyChoiceJetVec[j1], MyChoiceJetVec[j2], MyChoiceJetVec[j1], MyChoiceJetVec[j2], event_vector[Event::event_counter].LeptonVec[0], event_vector[Event::event_counter].LeptonVec[1], MyChoiceJetVec[j3], MyChoiceJetVec[j4], in_mpx, in_mpy, in_mpz, event_vector[Event::event_counter].MissPx, event_vector[Event::event_counter].MissPy, t_m, w_m);
										inputs.push_back(di);
									}
								}
							}
						}
					}
				}
			}
		}


	//}

	return inputs;
}*/




