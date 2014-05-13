#define ttH_dilep_cxx
#include "ttH_dilep.h"

#include <cstdlib>
#include <string>
#include <set>
using namespace std;

#include "myvector.h"
#ifdef D_CUDA
	#include "neut_cuda/neut.h"
#elif D_DICE
    #include "neut_dice/neut.h"
#else
	#include "neut/neut.h"
#endif

//extern int dilep_iterations;

#define RESOLUTION 0.02             // error resolution of de detector

#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <TRandom.h>
#include <TROOT.h>
#include <TLorentzVector.h>
#include <iomanip>
#include <fstream>

#include <cmath>

#include <omp.h>
#include "../../LipMiniAnalysis/src/EventDataInterface.h"
extern std::vector<Event::EventData> events;
std::vector<DilepInput> inputs;


// #############################################################################
ttH_dilep::ttH_dilep():LipMiniAnalysis(){
// #############################################################################
//
//  purpose: this is the constructor of the ttH_dilep class
//
//  authors: fveloso
//  first version: 16.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

  // stuff for cuts
  MaxCuts = 23;

  // -------------------------------
  // define file with pdf histograms
  // -------------------------------
  //fTruth = new TFile("main_ttH_7TeV.root");
  fTruth = new TFile("main_ttH_8TeV.root");

}


// #############################################################################
void ttH_dilep::UserValues(){
// #############################################################################
//
//  purpose: 
//
//  authors: fveloso
//  first version: 26.fev.2007
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################


	// Define W, top and Higgs mass values
	mW_UserValue =  80.40*GeV;   // W mass
  	mt_UserValue = 172.50*GeV;   // top mass
  	mH_UserValue = 125.00*GeV;   // Higgs mass

	// Number of Jets for ttDKF Permutations
  	ttDKF_njet_UserValue = 4 ;   	     // for ttbar+H : >= 4 jets and <= Maximum Number of Jets in Event

        // luminosity
        //Luminosity = 13873.6/1000.;   // evaluated for Top_GRL_K.xml
        //Luminosity = 20339.8/1000.;   // evaluated for Top_GRL_K.xml FDS (Full Data Set)
	Luminosity = 2034/1000.; 	// evaluated for Top_GRL_K.xml

  	// GRL to use
  	GRLXMLFile="TopGRL.xml";  

	// b-tag weight cut
        // BTagCut = 0.601713; 
        // BTagCut = 0.772; 
  	Event::initial_BTagCut = 0.8119;

	// truth lepton separation (for 105200/105205 samples; DO NOT USE THIS for ttH)
	leptonSep = 0;

	// lepton selection: 11 = electron, 13 = muon (single lepton); 21 - ee; 22 - mumu; 23 -e mu
	lepSample = 0;

        // read all data periods (e or mu streams)
        alldata_ele = 0;
        alldata_muo = 0;

        // pile-up
	pileup = 0;

        // RecoType: defines smearing if RecoType=200000 (no smear)
        //                            if RecoType=0   (do default)
	// RecoType = 200000;
        Event::initial_RecoType = 0;

	// ( DOES NOTHING!!!! No New Objects Defined Any Longer )
	doGoodObjSelection = 0;

	// divide samples into S1 B1 S2 B2
	divideSample = 0;

	// swith for trigger cuts ( = -1 to deactivate)
	CutTriggerEle    = -1;
	CutTriggerMuo    = -1;
	CutTriggerEleMuo = -1;

        // hfor ( = -1 no HFOR flag looked at)
        m_hfor    = -1;

	// correction to the MC normalization
	corrnorm_wjets = 1.0;
	corrnorm_zjets = 1.0;
	corrnorm_tt = 1.0;
	corrnorm_wz = 1.0;
	corrnorm_db = 1.0;
	corrnorm_st = 1.0;

	// correction to the luminosity
	corrlum = 1.0;

	// Remove electrons in crack region from good vectors ?
	// RemoveElCrack = 0   Yes, remove tracks
	//               = 1    No, do not remove tracks  
	RemoveElCrack = 0;

	// cuts for photons
	EtaCutPho = 2.5;
	PtCutPho  = 15.*GeV;
	IsoCutPho = 0.4;

        // cuts for electrons
        EtaCutEle =  999.;
        Event::initial_PtCutEle  = -999.*GeV;
        IsoCutEle = 0.4;

        // cuts for muons
        EtaCutMuo =  999.;
        Event::initial_PtCutMuo  = -999.*GeV;
        IsoCutMuo = 0.4;

	// cuts for jets
	EtaCutJet =  999.;
	Event::initial_PtCutJet  = -999.*GeV;
	IsoCutJet = 0.4;

	// cuts for ttH_dilep analysis
	ptcut        =  20.*GeV;
	cutwmass     = 500.*GeV;
	cuttopmass   = 500.*GeV;
	cutptjet     = 300.*GeV;
	deltarmincut = 0.4;
	nlepcut      = 1;
	njetmin      = 4;
	cutsqrtchi2  = 10.;
	cutchi2      = cutsqrtchi2*cutsqrtchi2;

	// discriminant analysis
	LogELikeMinCut = 1;
	LogELikeMaxCut =  99999;
	Log10LikeMinCut = -999.;
	Log10LikeMaxCut = 99999;

	// signal pdf
	sprintf(signalpdf, "signal_pdf.root");

  	// systematics
  	LumSys = 1.;
  	LumSysZj = 1.;
  	LumSysWj = 1.;
  	LumSysWZp = 1.;
  	LumSystt = 1.;
  	LumSysst = 1.;
  	SysPtLep = 1.;
  	SysPtJet = 1.;
  	SysPtPho = 1.;
  	SysPtMiss = 1.;
  	SysEtot = 1.;
  	SysPtGluon = 1.;
  	NBinFactor = 1.;

	// pdf smooth
	for(Int_t i = 0; i < 50; i++)
	{
		PdfSmooth[i] = 10;
	}

}


// #############################################################################
void ttH_dilep::UserCommandLineOptions(char *options, Int_t print) {
// #############################################################################
//
//  purpose:
//
//  authors: fveloso
//  first version: 24.june.2007
//
//  last change: 04.Nov.2012
//  by: A.Onofre
// #############################################################################

  #include "aux_files/UserCommandLineOptions.cxx"

}


// #############################################################################
void ttH_dilep::DefineSamples(){
// #############################################################################
//
//  purpose: the user should declare here the ROOT samples that will be
//  analysed
//
//  authors: fveloso
//  first version: 18.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

  // print info to the log

    cout << endl;
    cout << " ====================================================" << endl;
    cout << "  DefineSamples() :   Running in Mac OS X 10.9    ===" << endl;
    cout << " ====================================================" << endl;
    cout << endl;


    if( RemoveElCrack > 0 && doGoodObjSelection==1 ){
      cout << "  ==============================================================" << endl;
      cout << "   DefineSamples() :  Electrons in Crack Region not considered  " << endl;
      cout << "                      as good!                                  " << endl;
      cout << "  ==============================================================" << endl;
    }

    if( leptonSep==0 ) cout << "  No truth charged lepton separation is being made for samples 105200/105205" << endl;
    if( leptonSep==1 ) cout << "  Only events with one truth electron or muon were considered for samples 105200/105205" << endl;
    if( leptonSep==4 ) cout << "  Only background events (di-leptonic + taus) were considered for samples 105200/105205" << endl;

    // =====New Mini Ntuples FDS @ 8 TeV TRCR14-00-13 (ttbar and ttH with top quark status code 155)
    
    #include "aux_files/define_samples_data_MarkOwen.cxx"
    #include "aux_files/define_samples_simulation_MarkOwen.cxx"
}


// #############################################################################
void ttH_dilep::BookHistograms(THistos &histo){
// #############################################################################
//
//  purpose: to book histograms before the event's loop
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

        // XML file with the Good Run List (GRL)

	char n[100];
	char t[100];


        // =========================================================
        // ===== AO 8 Oct 2010 ===================== above =========
        // =========================================================

        if ( isData == 0 ){

        	myEVE_Total	 =0;
        	//....semileptonic..........
        	myEVE_semi_ele	 =0;
        	myEVE_semi_mu	 =0;
        	myEVE_semi_nontau_ele	 =0;
        	myEVE_semi_nontau_mu	 =0;
        	myEVE_semi_tau	 =0;
        	myEVE_semi_leptau=0;
        	myEVE_semi_eletau=0;
        	myEVE_semi_mutau =0;
        	//....dileptonic............with tau decays....
        	myEVE_di_eleele	 =0;
        	myEVE_di_mumu	 =0;
        	myEVE_di_elemu	 =0;
        	//....dileptonic............without tau decays....
        	myEVE_di_nontau_eleele	 =0;
        	myEVE_di_nontau_elemu	 =0;
        	myEVE_di_nontau_eletau	 =0;
        	myEVE_di_nontau_mumu	 =0;
        	myEVE_di_nontau_mutau	 =0;
        	myEVE_di_nontau_tautau	 =0;
        	//....multileptons..............
        	myEVE_0leptons     = 0;
        	myEVE_3leptons     = 0;
        	myEVE_4leptons     = 0;
       		myEVE_more4leptons = 0;
		//...top quarks
		myEVE_ttbar      =0;
		myEVE_4tops      =0;
		myEVE_nonttbar   =0;
        	//.....................discriminate what ttbar events do we have..... 
        	myttbar_00 = 0;
        	myttbar_01 = 0;
        	myttbar_02 = 0;
        	myttbar_03 = 0;
        	myttbar_10 = 0;
        	myttbar_11 = 0;
        	myttbar_12 = 0;
        	myttbar_13 = 0;
        	myttbar_20 = 0;
        	myttbar_21 = 0;
        	myttbar_22 = 0;
        	myttbar_23 = 0;
        	myttbar_30 = 0;
        	myttbar_31 = 0;
        	myttbar_32 = 0;
       	 	myttbar_33 = 0;
        	//...W bosons
		myEVE_WW	 =0;	
		myEVE_4W      	 =0;
		myEVE_nonWW      =0;
        	//.....................discriminate what ttbar events do we have..... 
        	mybbbar_00 = 0;
        	mybbbar_01 = 0;
        	mybbbar_02 = 0;
       		mybbbar_03 = 0;
        	mybbbar_10 = 0;
        	mybbbar_11 = 0;
        	mybbbar_12 = 0;
        	mybbbar_13 = 0;
        	mybbbar_20 = 0;
        	mybbbar_21 = 0;
        	mybbbar_22 = 0;
        	mybbbar_23 = 0;
        	mybbbar_30 = 0;
        	mybbbar_31 = 0;
        	mybbbar_32 = 0;
        	mybbbar_33 = 0;
        	//...b quarks
		myEVE_bb	 =0;	
		myEVE_4b      	 =0;
		myEVE_nonbb      =0;
        	//.....................discriminate what ttbar events do we have..... 
        	myssbar_00 = 0;
        	myssbar_01 = 0;
        	myssbar_02 = 0;
        	myssbar_03 = 0;
        	myssbar_10 = 0;
        	myssbar_11 = 0;
        	myssbar_12 = 0;
        	myssbar_13 = 0;
        	myssbar_20 = 0;
        	myssbar_21 = 0;
        	myssbar_22 = 0;
        	myssbar_23 = 0;
        	myssbar_30 = 0;
       	 	myssbar_31 = 0;
        	myssbar_32 = 0;
        	myssbar_33 = 0;
        	//...s quarks
		myEVE_ss	 =0;	
		myEVE_4s      	 =0;
		myEVE_nonss      =0;
        	//.....................discriminate what ttbar events do we have..... 
        	myddbar_00 = 0;
        	myddbar_01 = 0;
        	myddbar_02 = 0;
        	myddbar_03 = 0;
        	myddbar_10 = 0;
        	myddbar_11 = 0;
        	myddbar_12 = 0;
        	myddbar_13 = 0;
       	 	myddbar_20 = 0;
        	myddbar_21 = 0;
       	 	myddbar_22 = 0;
        	myddbar_23 = 0;
        	myddbar_30 = 0;
        	myddbar_31 = 0;
        	myddbar_32 = 0;
        	myddbar_33 = 0;
        	//...s quarks
		myEVE_dd	 =0;	
		myEVE_4d      	 =0;
		myEVE_nondd      =0;
        }

        // =========================================================
        // ===== AO 8 Oct 2010 ===================== above =========
        // =========================================================

        // ---------------------
        // ---------------------
        // Define Histogram bins
        // ---------------------
        // ---------------------
        // Ht
        int   bHt =   75 ;
        float lHt =    0.;
        float hHt = 1500.;

        // Pt, Et, P, E
        int   bPt =    75 ;
        float lPt =     0.;
        float hPt =  1500.;

        // Ptmis, Etmis
        int   bMis =   75 ;
        float lMis =    0.;
        float hMis = 1500.;

        // Mll
        int   bM =   40;
        float lM =    0.;
        float hM =  200.;

        // Mlb
        int   bMlb =   20;
        float lMlb =    0.;
        float hMlb =  500.;

        // Mlb2
        int   bMlb2 =   100;
        float lMlb2 =     0.;
        float hMlb2 =  50000.;


        // ---------------------
        // ---------------------

	for(Int_t i = 0; i <= MaxCuts; ++i)
	{

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                             General Histograms for the Dileptonic ttbar Topology                                      ::
                // ::					             from 0 - 99 							    ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                //
		// truth measured information
		histo[i][ 0] = new TH1D(c(n, i, "_ntruthlep"),        c(t, i, ": nr. of truth leptons"),             5, -0.5, 4.5);

		// measured information
		histo[i][ 1] = new TH1D(c(n, i, "_nlep"),             c(t, i, ": nr. leptons"),                      10, -0.5,  9.5);
		histo[i][ 2] = new TH1D(c(n, i, "_njet"),             c(t, i, ": nr. of good jets (b + non-b)"),     20, -0.5, 19.5);
		histo[i][ 3] = new TH1D(c(n, i, "_Ht"),               c(t, i, ": Ht"),                              bHt,  lHt, hHt);
		histo[i][ 4] = new TH1D(c(n, i, "_ptmis"),            c(t, i, ": pt missing"),                     bMis, lMis, hMis);

                // Tracks and Vertices Information
                // vertices
		histo[i][5] = new TH1D(c(n, i, "_X_Vtx"),             c(t, i, ": X-coord Vtx"),                     100, -1., 1.);
		histo[i][6] = new TH1D(c(n, i, "_Y_Vtx"),             c(t, i, ": Y-coord Vtx"),                     100,  0., 2.);
		histo[i][7] = new TH1D(c(n, i, "_Z_Vtx"),             c(t, i, ": Z-coord Vtx"),                     100, -200., 200.);
                // tracks
		histo[i][8] = new TH1D(c(n, i, "_p_Pos_trk"),         c(t, i, ": p Positive tracks"),               200, 0., 200.);
		histo[i][9] = new TH1D(c(n, i, "_p_Neg_ptrk"),        c(t, i, ": p Negative tracks"),               200, 0., 200.);

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                          New histograms for SS-OS Method: Full (in Etmiss bins )                                      ::
                // ::					             from 100 - 199 							    ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                //
                // OS, Full ==================================================================================================================
                Double_t pi=TMath::Pi();
		histo[i][100] = new TH1D(c(n, i, "_njet_OS"),             c(t, i, ": nr. of good jets (b + non-b)-OS"),     20, -0.5,  19.5  );
		histo[i][101] = new TH1D(c(n, i, "_nbjet_OS"),            c(t, i, ": nr. of good jets  b         -OS"),     10, -0.5,   9.5  );
		histo[i][102] = new TH1D(c(n, i, "_Etmis_OS"),            c(t, i, ": Et missing-OS"),                     bMis, lMis, hMis   );
		histo[i][103] = new TH1D(c(n, i, "_PhiDif_OS"),           c(t, i, ": Diff. Phi-OS"),                        20,   0.,  pi    );
		histo[i][104] = new TH1D(c(n, i, "_Mll_OS"),              c(t, i, ": Mll-OS"),                              bM,    lM, hM    );
		histo[i][105] = new TH1D(c(n, i, "_Ht_OS"),               c(t, i, ": Ht-OS"),                              bHt,   lHt, hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][106] = new TH1D(c(n, i, "_ptlep1_OS"),           c(t, i, ": pt  lep 1-OS"),                        bPt,  lPt, hPt   );
	        histo[i][107] = new TH1D(c(n, i, "_philep1_OS"),          c(t, i, ": phi lep 1-OS"),                         50,  -pi, pi    );
	        histo[i][108] = new TH1D(c(n, i, "_etalep1_OS"),          c(t, i, ": eta lep 1-OS"),                         40,  -4., 4.    );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][109] = new TH1D(c(n, i, "_ptlep2_OS"),           c(t, i, ": pt  lep 2-OS"),                        bPt,  lPt, hPt   );
	        histo[i][110] = new TH1D(c(n, i, "_philep2_OS"),          c(t, i, ": phi lep 2-OS"),                         50,  -pi, pi    );
	        histo[i][111] = new TH1D(c(n, i, "_etalep2_OS"),          c(t, i, ": eta lep 2-OS"),                         40,  -4., 4.    );

                            //.........Mll versus Etmis..............................................................................................
//                histo[i][124] = new TH2D( c(n,i,"_XMll_YEtmis_OS"),	  c(t,i,": x=Mll [GeV] y=Etmis [GeV] OS"),   1000,  0.,  1000.,   100, 0., 200. );
//                histo[i][126] = new TH2D( c(n,i,"_XHt_YEtmis_OS"),        c(t,i,": x=Ht  [GeV] y=Etmis [GeV] OS"),   1000,  0.,  1000.,   100, 0., 200. );
                histo[i][188] = new TH1D(c(n, i, "_ZjetsDD_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR OS"),     10, -0.5,  9.5  );
                //
                // SS, Full ==================================================================================================================
		histo[i][112] = new TH1D(c(n, i, "_njet_SS"),             c(t, i, ": nr. of good jets (b + non-b)-SS"),     20, -0.5,  19.5  );
		histo[i][113] = new TH1D(c(n, i, "_nbjet_SS"),            c(t, i, ": nr. of good jets  b         -SS"),     10, -0.5,   9.5  );
		histo[i][114] = new TH1D(c(n, i, "_Etmis_SS"),            c(t, i, ": Et missing-SS"),                     bMis, lMis, hMis   );
		histo[i][115] = new TH1D(c(n, i, "_PhiDif_SS"),           c(t, i, ": Diff. Phi-SS"),                        20,   0.,  pi    );
		histo[i][116] = new TH1D(c(n, i, "_Mll_SS"),              c(t, i, ": Mll-SS"),                              bM,   lM,  hM    );
		histo[i][117] = new TH1D(c(n, i, "_Ht_SS"),               c(t, i, ": Ht-SS"),                              bHt,   lHt, hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][118] = new TH1D(c(n, i, "_ptlep1_SS"),           c(t, i, ": pt  lep 1-SS"),                        bPt,  lPt, hPt  );
	        histo[i][119] = new TH1D(c(n, i, "_philep1_SS"),          c(t, i, ": phi lep 1-SS"),                         50,  -pi, pi   );
	        histo[i][120] = new TH1D(c(n, i, "_etalep1_SS"),          c(t, i, ": eta lep 1-SS"),                         40,  -4., 4.   );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][121] = new TH1D(c(n, i, "_ptlep2_SS"),           c(t, i, ": pt  lep 2-SS"),                        bPt,  lPt, hPt  );
	        histo[i][122] = new TH1D(c(n, i, "_philep2_SS"),          c(t, i, ": phi lep 2-SS"),                         50,  -pi, pi   );
	        histo[i][123] = new TH1D(c(n, i, "_etalep2_SS"),          c(t, i, ": eta lep 2-SS"),                         40,  -4., 4.   );

                            //.........Mll versus Etmis..............................................................................................
//                histo[i][125] = new TH2D( c(n,i,"_XMll_YEtmis_SS"),	  c(t,i,": x=Mll [GeV] y=Etmis [GeV] SS"),   1000,  0.,  1000.,   100, 0., 200. );
//                histo[i][127] = new TH2D( c(n,i,"_XHt_YEtmis_SS"),        c(t,i,": x=Ht  [GeV] y=Etmis [GeV] SS"),   1000,  0.,  1000.,   100, 0., 200. );
                histo[i][189] = new TH1D(c(n, i, "_ZjetsDD_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR SS"),     10, -0.5,  9.5  );

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                            New histograms for SS-OS Method:   Control Region                                          ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                //
                // OS ========================================================================================================================
		histo[i][130] = new TH1D(c(n, i, "_njet_OS_CONTROL"),             c(t, i, ": nr. of good jets (b + non-b)-OS_CONTROL"),     20, -0.5,  19.5  );
		histo[i][131] = new TH1D(c(n, i, "_nbjet_OS_CONTROL"),            c(t, i, ": nr. of good jets  b         -OS_CONTROL"),     10, -0.5,   9.5  );
		histo[i][132] = new TH1D(c(n, i, "_Etmis_OS_CONTROL"),            c(t, i, ": Et missing-OS_CONTROL"),                     bMis, lMis, hMis   );
		histo[i][133] = new TH1D(c(n, i, "_PhiDif_OS_CONTROL"),           c(t, i, ": Diff. Phi-OS_CONTROL"),                        20,   0.,  pi    );
		histo[i][134] = new TH1D(c(n, i, "_Mll_OS_CONTROL"),              c(t, i, ": Mll-OS_CONTROL"),                              bM,   lM,  hM    );
		histo[i][135] = new TH1D(c(n, i, "_Ht_OS_CONTROL"),               c(t, i, ": Ht-OS_CONTROL"),                              bHt,  lHt,  hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][136] = new TH1D(c(n, i, "_ptlep1_OS_CONTROL"),           c(t, i, ": pt  lep 1-OS_CONTROL"),                        bPt,  lPt, hPt  );
	        histo[i][137] = new TH1D(c(n, i, "_philep1_OS_CONTROL"),          c(t, i, ": phi lep 1-OS_CONTROL"),                         50,  -pi, pi   );
	        histo[i][138] = new TH1D(c(n, i, "_etalep1_OS_CONTROL"),          c(t, i, ": eta lep 1-OS_CONTROL"),                         40,  -4., 4.   );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][139] = new TH1D(c(n, i, "_ptlep2_OS_CONTROL"),           c(t, i, ": pt  lep 2-OS_CONTROL"),                        bPt,  lPt, hPt  );
	        histo[i][140] = new TH1D(c(n, i, "_philep2_OS_CONTROL"),          c(t, i, ": phi lep 2-OS_CONTROL"),                         50,  -pi, pi   );
	        histo[i][141] = new TH1D(c(n, i, "_etalep2_OS_CONTROL"),          c(t, i, ": eta lep 2-OS_CONTROL"),                         40,  -4., 4.   );

                            //.........Mll versus Etmis..............................................................................................
//                histo[i][154] = new TH2D( c(n,i,"_XMll_YEtmis_OS_CONTROL"),	c(t,i,": x=Mll [GeV] y=Etmis [GeV] OS CONTROL"),   1000,  0.,  1000.,   100, 0., 200. );
//                histo[i][156] = new TH2D( c(n,i,"_XHt_YEtmis_OS_CONTROL"),        c(t,i,": x=Ht  [GeV] y=Etmis [GeV] OS CONTROL"),   1000,  0.,  1000.,   100, 0., 200. );

                //___20 bins (A+,A-,AFB)_________
                histo[i][190] = new TH1D(c(n, i, "_Wpol_coslB_OS_CONTROL"),           c(t, i, ": W pol. cos(l,b) in W"),           20, -1., 1.);
                //___4 bins (A+,A-,AFB)_________
                histo[i][191] = new TH1D(c(n, i, "_Wpol_coslB_4bins_OS_CONTROL"),     c(t, i, ": W pol. cos(l,b) in W 4bins"),     4, -1., 1.);

                //
                // SS ========================================================================================================================
		histo[i][142] = new TH1D(c(n, i, "_njet_SS_CONTROL"),             c(t, i, ": nr. of good jets (b + non-b)-SS_CONTROL"),     20, -0.5,  19.5  );
		histo[i][143] = new TH1D(c(n, i, "_nbjet_SS_CONTROL"),            c(t, i, ": nr. of good jets  b         -SS_CONTROL"),     10, -0.5,   9.5  );
		histo[i][144] = new TH1D(c(n, i, "_Etmis_SS_CONTROL"),            c(t, i, ": Et missing-SS_CONTROL"),                     bMis, lMis, hMis   );
		histo[i][145] = new TH1D(c(n, i, "_PhiDif_SS_CONTROL"),           c(t, i, ": Diff. Phi-SS_CONTROL"),                        20,   0.,  pi    );
		histo[i][146] = new TH1D(c(n, i, "_Mll_SS_CONTROL"),              c(t, i, ": Mll-SS_CONTROL"),                              bM,   lM,  hM    );
		histo[i][147] = new TH1D(c(n, i, "_Ht_SS_CONTROL"),               c(t, i, ": Ht-SS_CONTROL"),                              bHt,  lHt,  hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][148] = new TH1D(c(n, i, "_ptlep1_SS_CONTROL"),           c(t, i, ": pt  lep 1-SS_CONTROL"),                        bPt,  lPt, hPt  );
	        histo[i][149] = new TH1D(c(n, i, "_philep1_SS_CONTROL"),          c(t, i, ": phi lep 1-SS_CONTROL"),                         50,  -pi, pi   );
	        histo[i][150] = new TH1D(c(n, i, "_etalep1_SS_CONTROL"),          c(t, i, ": eta lep 1-SS_CONTROL"),                         40,  -4., 4.   );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][151] = new TH1D(c(n, i, "_ptlep2_SS_CONTROL"),           c(t, i, ": pt  lep 2-SS_CONTROL"),                        bPt,  lPt, hPt  );
	        histo[i][152] = new TH1D(c(n, i, "_philep2_SS_CONTROL"),          c(t, i, ": phi lep 2-SS_CONTROL"),                         50,  -pi,  pi  );
	        histo[i][153] = new TH1D(c(n, i, "_etalep2_SS_CONTROL"),          c(t, i, ": eta lep 2-SS_CONTROL"),                         40,  -4., 4.   );

                            //.........Mll versus Etmis..............................................................................................
//                histo[i][155] = new TH2D( c(n,i,"_XMll_YEtmis_SS_CONTROL"),	c(t,i,": x=Mll [GeV] y=Etmis [GeV] SS CONTROL"),   1000,  0.,  1000.,   100, 0., 200. );
//                histo[i][157] = new TH2D( c(n,i,"_XHt_YEtmis_SS_CONTROL"),        c(t,i,": x=Ht  [GeV] y=Etmis [GeV] SS CONTROL"),   1000,  0.,  1000.,   100, 0., 200. );

                //___20 bins (A+,A-,AFB)_________
                histo[i][192] = new TH1D(c(n, i, "_Wpol_coslB_SS_CONTROL"),           c(t, i, ": W pol. cos(l,b) in W"),           20, -1., 1.);
                //___4 bins  (A+,A-,AFB)_________
                histo[i][193] = new TH1D(c(n, i, "_Wpol_coslB_4bins_SS_CONTROL"),     c(t, i, ": W pol. cos(l,b) in W 4bins"),      4, -1., 1.);

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                            New histograms for SS-OS Method:   Signal Region                                           ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                //
                // OS ========================================================================================================================
		histo[i][160] = new TH1D(c(n, i, "_njet_OS_SIGNAL"),             c(t, i, ": nr. of good jets (b + non-b)-OS_SIGNAL"),     20, -0.5,  19.5  );
		histo[i][161] = new TH1D(c(n, i, "_nbjet_OS_SIGNAL"),            c(t, i, ": nr. of good jets  b         -OS_SIGNAL"),     10, -0.5,   9.5  );
		histo[i][162] = new TH1D(c(n, i, "_Etmis_OS_SIGNAL"),            c(t, i, ": Et missing-OS_SIGNAL"),                     bMis, lMis, hMis   );
		histo[i][163] = new TH1D(c(n, i, "_PhiDif_OS_SIGNAL"),           c(t, i, ": Diff. Phi-OS_SIGNAL"),                        20,   0.,  pi    );
		histo[i][164] = new TH1D(c(n, i, "_Mll_OS_SIGNAL"),              c(t, i, ": Mll-OS_SIGNAL"),                              bM,   lM,  hM    );
		histo[i][165] = new TH1D(c(n, i, "_Ht_OS_SIGNAL"),               c(t, i, ": Ht-OS_SIGNAL"),                              bHt,   lHt, hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][166] = new TH1D(c(n, i, "_ptlep1_OS_SIGNAL"),           c(t, i, ": pt  lep 1-OS_SIGNAL"),                        bPt,  lPt, hPt  );
	        histo[i][167] = new TH1D(c(n, i, "_philep1_OS_SIGNAL"),          c(t, i, ": phi lep 1-OS_SIGNAL"),                         50,  -pi, pi   );
	        histo[i][168] = new TH1D(c(n, i, "_etalep1_OS_SIGNAL"),          c(t, i, ": eta lep 1-OS_SIGNAL"),                         40,  -4., 4.   );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][169] = new TH1D(c(n, i, "_ptlep2_OS_SIGNAL"),           c(t, i, ": pt  lep 2-OS_SIGNAL"),                        bPt,  lPt, hPt  );
	        histo[i][170] = new TH1D(c(n, i, "_philep2_OS_SIGNAL"),          c(t, i, ": phi lep 2-OS_SIGNAL"),                         50,  -pi,  pi  );
	        histo[i][171] = new TH1D(c(n, i, "_etalep2_OS_SIGNAL"),          c(t, i, ": eta lep 2-OS_SIGNAL"),                         40,  -4., 4.   );

                //___20 bins (A+,A-,AFB)_________
                histo[i][194] = new TH1D(c(n, i, "_Wpol_coslB_OS_SIGNAL"),           c(t, i, ": W pol. cos(l,b) in W"),           20, -1., 1.);
                //___4 bins (A+,A-,AFB)_________
                histo[i][195] = new TH1D(c(n, i, "_Wpol_coslB_4bins_OS_SIGNAL"),     c(t, i, ": W pol. cos(l,b) in W 4bins"),     4, -1., 1.);

                //
                // SS ========================================================================================================================
		histo[i][172] = new TH1D(c(n, i, "_njet_SS_SIGNAL"),             c(t, i, ": nr. of good jets (b + non-b)-SS_SIGNAL"),     20,  -0.5,  19.5  );
		histo[i][173] = new TH1D(c(n, i, "_nbjet_SS_SIGNAL"),            c(t, i, ": nr. of good jets  b         -SS_SIGNAL"),     10,  -0.5,   9.5  );
		histo[i][174] = new TH1D(c(n, i, "_Etmis_SS_SIGNAL"),            c(t, i, ": Et missing-SS_SIGNAL"),                      bMis, lMis, hMis   );
		histo[i][175] = new TH1D(c(n, i, "_PhiDif_SS_SIGNAL"),           c(t, i, ": Diff. Phi-SS_SIGNAL"),                        20,    0.,  pi    );
		histo[i][176] = new TH1D(c(n, i, "_Mll_SS_SIGNAL"),              c(t, i, ": Mll-SS_SIGNAL"),                              bM,    lM,  hM    );
		histo[i][177] = new TH1D(c(n, i, "_Ht_SS_SIGNAL"),               c(t, i, ": Ht-SS_SIGNAL"),                              bHt,   lHt,  hHt   );
                            //.........etas, phis and pts.........................................lepton 1....................................
	        histo[i][178] = new TH1D(c(n, i, "_ptlep1_SS_SIGNAL"),           c(t, i, ": pt  lep 1-SS_SIGNAL"),                       bPt,  lPt, hPt  );
	        histo[i][179] = new TH1D(c(n, i, "_philep1_SS_SIGNAL"),          c(t, i, ": phi lep 1-SS_SIGNAL"),                         50,  -pi, pi  );
	        histo[i][180] = new TH1D(c(n, i, "_etalep1_SS_SIGNAL"),          c(t, i, ": eta lep 1-SS_SIGNAL"),                         40,  -4., 4.  );
                            //.........etas, phis and pts.........................................lepton 2....................................
	        histo[i][181] = new TH1D(c(n, i, "_ptlep2_SS_SIGNAL"),           c(t, i, ": pt  lep 2-SS_SIGNAL"),                       bPt,  lPt, hPt  );
	        histo[i][182] = new TH1D(c(n, i, "_philep2_SS_SIGNAL"),          c(t, i, ": phi lep 2-SS_SIGNAL"),                         50,  -pi, pi  );
	        histo[i][183] = new TH1D(c(n, i, "_etalep2_SS_SIGNAL"),          c(t, i, ": eta lep 2-SS_SIGNAL"),                         40,  -4., 4.  );

                //___20 bins (A+,A-,AFB)_________
                histo[i][196] = new TH1D(c(n, i, "_Wpol_coslB_SS_SIGNAL"),           c(t, i, ": W pol. cos(l,b) in W"),           20, -1., 1.);
                //___4 bins (A+,A-,AFB)_________
                histo[i][197] = new TH1D(c(n, i, "_Wpol_coslB_4bins_SS_SIGNAL"),     c(t, i, ": W pol. cos(l,b) in W 4bins"),     4, -1., 1.);

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                                   Additional Histograms from Truth information                                            ::
                // ::					             from 200 - 299 							        ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// truth reconstructed information
		histo[i][200] = new TH1D(c(n, i, "_truth_pt_neutrino"), 	c(t, i, ": truth neutrino pt"), 	bPt,  lPt, hPt );
		histo[i][201] = new TH1D(c(n, i, "_truth_e_neutrino"),  	c(t, i, ": neutrino energy"),   	bPt,  lPt, hPt );
		histo[i][202] = new TH1D(c(n, i, "_truth_pt_anti-neutrino"), 	c(t, i, ": truth anti-neutrino pt"), 	bPt,  lPt, hPt );
		histo[i][203] = new TH1D(c(n, i, "_truth_e_anti_neutrino"), 	c(t, i, ": anti neutrino energy"), 	bPt,  lPt, hPt );
		// (Note Histograms 204->209 are also occupied by pdfs) AO 31 Dec 2011, see below)			

                // top quarks and W bosons_____________________________________________________________________
    		histo[i][210] = new TH1D(c(n,i,"_truth_m_Wp"),       	c(t,i,": truth m W+ [GeV]"),          	50, 0.0,  500.0);
    		histo[i][211] = new TH1D(c(n,i,"_truth_m_Wn"),       	c(t,i,": truth m W- [GeV]"),          	50, 0.0,  500.0);
    		histo[i][212] = new TH1D(c(n,i,"_truth_m_t"),     	c(t,i,": truth m t  [GeV]"), 		50, 0.0,  500.0);
    		histo[i][213] = new TH1D(c(n,i,"_truth_m_tbar"),     	c(t,i,": truth m tbar [GeV]"),		50, 0.0,  500.0);
    		histo[i][214] = new TH1D(c(n,i,"_truth_m_ttbar"),       c(t,i,": truth m t#bar{t} [GeV]"),      50, 0.0, 1000.0);
                //
    		histo[i][215] = new TH1D(c(n,i,"_truth_pt_Wp"),       	c(t,i,": truth p_{T} (W+)   [GeV]"),    bPt,  lPt, hPt );
    		histo[i][216] = new TH1D(c(n,i,"_truth_pt_Wn"),       	c(t,i,": truth p_{T} (W-)   [GeV]"),    bPt,  lPt, hPt );
    		histo[i][217] = new TH1D(c(n,i,"_truth_pt_t"),    	c(t,i,": truth p_{T} (t)    [GeV]"),    bPt,  lPt, hPt );
    		histo[i][218] = new TH1D(c(n,i,"_truth_pt_tbar"),    	c(t,i,": truth p_{T} (tbar) [GeV]"), 	bPt,  lPt, hPt );
    		histo[i][219] = new TH1D(c(n,i,"_truth_pt_TTbar"),    	c(t,i,": truth p_{T} (t tbar) [GeV]"),  bPt,  lPt, hPt );
		//
    		histo[i][220] = new TH1D(c(n,i,"_truth_eta_Wp"),     	c(t,i,": truth #eta (W+)"),           	40, -4.0, 4.0);
    		histo[i][221] = new TH1D(c(n,i,"_truth_eta_Wn"),     	c(t,i,": truth #eta (W-)"),           	40, -4.0, 4.0);
    		histo[i][222] = new TH1D(c(n,i,"_truth_eta_t"),   	c(t,i,": truth #eta (t)"), 		40, -4.0, 4.0);
    		histo[i][223] = new TH1D(c(n,i,"_truth_eta_tbar"),   	c(t,i,": truth #eta (tbar)"),		40, -4.0, 4.0);
    		histo[i][224] = new TH1D(c(n,i,"_truth_eta_TTbar"),   	c(t,i,": truth #eta (t tbar)"),       	40, -4.0, 4.0);
		// (Note Histograms 225->229 are also occupied by pdfs) AO 31 Dec 2011, see below)			

		// TRUTH spin correlations distributions___________________________________________________________________________________________
		histo[i][230] = new TH1D(c(n, i, "_truth_spincorr_coslp_cosln"), c(t, i, ": truth spin corr. cos(l+)xcos(l-)"), 	20, -1., 1.);
		histo[i][231] = new TH1D(c(n, i, "_truth_spincorr_cosb_cosln"),  c(t, i, ": truth spin corr. cos(b)xcos(l-)"), 		20, -1., 1.);
		histo[i][232] = new TH1D(c(n, i, "_truth_spincorr_coslp_cosbb"), c(t, i, ": truth spin corr. cos(l+)xcos(bbar)"), 	20, -1., 1.);
		histo[i][233] = new TH1D(c(n, i, "_truth_spincorr_cosb_cosl"),   c(t, i, ": truth spin corr. cos(l)xcos(b)"), 		20, -1., 1.);
                //___2 bins____
		histo[i][234] = new TH1D(c(n, i, "_truth_spincorr_coslp_cosln_2bins"), c(t, i, ": truth spin corr. cos(l+)xcos(l-) 2bins"), 	2, -1., 1.);
		histo[i][235] = new TH1D(c(n, i, "_truth_spincorr_cosb_cosln_2bins"),  c(t, i, ": truth spin corr. cos(b)xcos(l-) 2bins"), 	2, -1., 1.);
		histo[i][236] = new TH1D(c(n, i, "_truth_spincorr_coslp_cosbb_2bins"), c(t, i, ": truth spin corr. cos(l+)xcos(bbar) 2bins"), 	2, -1., 1.);
		histo[i][237] = new TH1D(c(n, i, "_truth_spincorr_cosb_cosl_2bins"),   c(t, i, ": truth spin corr. cos(l)xcos(b) 2bins"), 	2, -1., 1.);

		// TRUTH W polarizations distributions_____________________________________________________________________________________________
		histo[i][240] = new TH1D(c(n, i, "_truth_Wpol_coslpB"), 	 c(t, i, ": truth W pol. cos(l+,b) in W+"), 	20, -1., 1.);
		histo[i][241] = new TH1D(c(n, i, "_truth_Wpol_coslnBbar"), 	 c(t, i, ": truth W pol. cos(l-,bbar) in W-"), 	20, -1., 1.);
		histo[i][242] = new TH1D(c(n, i, "_truth_Wpol_coslB"), 	 	 c(t, i, ": truth W pol. cos(l,b) in W"), 	20, -1., 1.);
                //___2 bins____
		histo[i][243] = new TH1D(c(n, i, "_truth_Wpol_coslpB_2bins"), 	 c(t, i, ": truth W pol. cos(l+,b) in W+ 2bins"), 	2, -1., 1.);
		histo[i][244] = new TH1D(c(n, i, "_truth_Wpol_coslnBbar_2bins"), c(t, i, ": truth W pol. cos(l-,bbar) in W- 2bins"), 	2, -1., 1.);
		histo[i][245] = new TH1D(c(n, i, "_truth_Wpol_coslB_2bins"), 	 c(t, i, ": truth W pol. cos(l,b) in W 2bins"), 	2, -1., 1.);
		//___4 bins (A+,A-,AFB)_________
		histo[i][246] = new TH1D(c(n, i, "_truth_Wpol_coslpB_4bins"), 	 c(t, i, ": truth W pol. cos(l+,b) in W+ 4bins"), 	4, -1., 1.);
		histo[i][247] = new TH1D(c(n, i, "_truth_Wpol_coslnBbar_4bins"), c(t, i, ": truth W pol. cos(l-,bbar) in W- 4bins"), 	4, -1., 1.);
		histo[i][248] = new TH1D(c(n, i, "_truth_Wpol_coslB_4bins"), 	 c(t, i, ": truth W pol. cos(l,b) in W 4bins"), 	4, -1., 1.);

                //___20 bins from Mlb____
		histo[i][249] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslpB"), 	c(t, i, ": truth Mlb W pol. cos(l+,b) in W+"), 		20, -1., 1.);
		histo[i][250] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslnBbar"), 	c(t, i, ": truth Mlb W pol. cos(l-,bbar) in W-"), 	20, -1., 1.);
		histo[i][251] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslB"), 	c(t, i, ": truth Mlb W pol. cos(l,b) in W"), 		20, -1., 1.);
                //___2 bins from Mlb____
		histo[i][252] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslpB_2bins"), 	c(t, i, ": truth Mlb W pol. cos(l+,b) in W+ 2bins"), 		2, -1., 1.);
		histo[i][253] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslnBbar_2bins"), 	c(t, i, ": truth Mlb W pol. cos(l-,bbar) in W- 2bins"), 	2, -1., 1.);
		histo[i][254] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslB_2bins"), 	c(t, i, ": truth Mlb W pol. cos(l,b) in W 2bins"), 		2, -1., 1.);
		//___4 bins (A+,A-,AFB) from Mlb_________
		histo[i][255] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslpB_4bins"), 	c(t, i, ": truth Mlb W pol. cos(l+,b) in W+ 4bins"), 		4, -1., 1.);
		histo[i][256] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslnBbar_4bins"), 	c(t, i, ": truth Mlb W pol. cos(l-,bbar) in W- 4bins"), 	4, -1., 1.);
		histo[i][257] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslB_4bins"), 	c(t, i, ": truth Mlb W pol. cos(l,b) in W 4bins"), 		4, -1., 1.);
		//___4 bins (A+,A-,AFB) from Mlb_________NO LIMITS______
		histo[i][258] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslpB_4bins_FULL"), 		c(t, i, ": truth Mlb W pol. cos(l+,b) in W+ 4bins FULL"), 	4, -1., 1.);
		histo[i][259] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslnBbar_4bins_FULL"), 	c(t, i, ": truth Mlb W pol. cos(l-,bbar) in W- 4bins FULL"), 	4, -1., 1.);
		histo[i][260] = new TH1D(c(n, i, "_truth_Mlb_Wpol_coslB_4bins_FULL"), 		c(t, i, ": truth Mlb W pol. cos(l,b) in W 4bins FULL"), 	4, -1., 1.);

		// Mlb mass distributions
		histo[i][261] = new TH1D(c(n, i, "_truth_Mlb_for_lp"),     		c(t, i, ": truth Mlb (l+)"),               bMlb,  lMlb, hMlb);
		histo[i][262] = new TH1D(c(n, i, "_truth_Mlb_for_ln"),     		c(t, i, ": truth Mlb (l-)"),               bMlb,  lMlb, hMlb);
		histo[i][263] = new TH1D(c(n, i, "_truth_Mlb"),            		c(t, i, ": truth Mlb (l+,l-)"),            bMlb,  lMlb, hMlb);
		// Mlb**2 mass distributions
		histo[i][264] = new TH1D(c(n, i, "_truth_Mlb2_for_lp"),     		c(t, i, ": truth Mlb2 (l+)"),              bMlb2,  lMlb2, hMlb2);
		histo[i][265] = new TH1D(c(n, i, "_truth_Mlb2_for_ln"),     		c(t, i, ": truth Mlb2 (l-)"),              bMlb2,  lMlb2, hMlb2);
		histo[i][266] = new TH1D(c(n, i, "_truth_Mlb2"),            		c(t, i, ": truth Mlb2 (l+,l-)"),           bMlb2,  lMlb2, hMlb2);


		// ________________________________________________________________________________________________________________________________
		// Histograms for p.d.f.s__________________________________________________________________________________________________________ 
		// ________________________________________________________________________________________________________________________________
		// Lowest pT Lepton (l1)------------------------------------------------------------------------------------------------
    		histo[i][204] = new TH1D(c(n,i,"_pdf_e___l1"),       	c(t,i,": pdf l1 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][205] = new TH1D(c(n,i,"_pdf_pt__l1"),       	c(t,i,": pdf l1  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][206] = new TH1D(c(n,i,"_pdf_eta_l1"),       	c(t,i,": pdf l1 #eta         "),     		80, -4.0, 4.0);
    		histo[i][207] = new TH1D(c(n,i,"_pdf_phi_l1"),      	c(t,i,": pdf l1 #phi         "),     		80, -4.0, 4.0);
		// Neutrino for (l1)
    		histo[i][208] = new TH1D(c(n,i,"_pdf_e___n1"),       	c(t,i,": pdf n1 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][209] = new TH1D(c(n,i,"_pdf_pt__n1"),       	c(t,i,": pdf n1  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][225] = new TH1D(c(n,i,"_pdf_eta_n1"),       	c(t,i,": pdf n1 #eta         "),     		80, -4.0, 4.0);
    		histo[i][226] = new TH1D(c(n,i,"_pdf_phi_n1"),      	c(t,i,": pdf n1 #phi         "),     		80, -4.0, 4.0);
		// b-quark for (l1)
    		histo[i][227] = new TH1D(c(n,i,"_pdf_e___b1"),       	c(t,i,": pdf b1 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][228] = new TH1D(c(n,i,"_pdf_pt__b1"),       	c(t,i,": pdf b1  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][229] = new TH1D(c(n,i,"_pdf_eta_b1"),       	c(t,i,": pdf b1 #eta         "),     		80, -4.0, 4.0);
    		histo[i][267] = new TH1D(c(n,i,"_pdf_phi_b1"),      	c(t,i,": pdf b1 #phi         "),     		80, -4.0, 4.0);
		// W-boson for (l1)
    		histo[i][268] = new TH1D(c(n,i,"_pdf_e___W1"),       	c(t,i,": pdf W1 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][269] = new TH1D(c(n,i,"_pdf_pt__W1"),       	c(t,i,": pdf W1  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][270] = new TH1D(c(n,i,"_pdf_eta_W1"),       	c(t,i,": pdf W1 #eta         "),     		80, -4.0, 4.0);
    		histo[i][271] = new TH1D(c(n,i,"_pdf_phi_W1"),      	c(t,i,": pdf W1 #phi         "),     		80, -4.0, 4.0);
    		histo[i][272] = new TH1D(c(n,i,"_pdf_m___W1"),     	c(t,i,": pdf W1 mass [GeV]"),			50, 0.0,  500.0);
		// t-quark for (l1)
    		histo[i][273] = new TH1D(c(n,i,"_pdf_e___t1"),       	c(t,i,": pdf t1 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][274] = new TH1D(c(n,i,"_pdf_pt__t1"),       	c(t,i,": pdf t1  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][275] = new TH1D(c(n,i,"_pdf_eta_t1"),       	c(t,i,": pdf t1 #eta         "),     		80, -4.0, 4.0);
    		histo[i][276] = new TH1D(c(n,i,"_pdf_phi_t1"),      	c(t,i,": pdf t1 #phi         "),     		80, -4.0, 4.0);
    		histo[i][277] = new TH1D(c(n,i,"_pdf_m___t1"),     	c(t,i,": pdf t1 mass [GeV]"),			50, 0.0,  500.0);
		// Lowest pT Lepton (l2)------------------------------------------------------------------------------------------------
    		histo[i][278] = new TH1D(c(n,i,"_pdf_e___l2"),       	c(t,i,": pdf l2 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][279] = new TH1D(c(n,i,"_pdf_pt__l2"),       	c(t,i,": pdf l2  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][280] = new TH1D(c(n,i,"_pdf_eta_l2"),       	c(t,i,": pdf l2 #eta         "),     		80, -4.0, 4.0);
    		histo[i][281] = new TH1D(c(n,i,"_pdf_phi_l2"),      	c(t,i,": pdf l2 #phi         "),     		80, -4.0, 4.0);
		// Neutrino for (l2)
    		histo[i][282] = new TH1D(c(n,i,"_pdf_e___n2"),       	c(t,i,": pdf n2 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][283] = new TH1D(c(n,i,"_pdf_pt__n2"),       	c(t,i,": pdf n2  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][284] = new TH1D(c(n,i,"_pdf_eta_n2"),       	c(t,i,": pdf n2 #eta         "),     		80, -4.0, 4.0);
    		histo[i][285] = new TH1D(c(n,i,"_pdf_phi_n2"),      	c(t,i,": pdf n2 #phi         "),     		80, -4.0, 4.0);
		// b-quark for (l2)
    		histo[i][286] = new TH1D(c(n,i,"_pdf_e___b2"),       	c(t,i,": pdf b2 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][287] = new TH1D(c(n,i,"_pdf_pt__b2"),       	c(t,i,": pdf b2  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][288] = new TH1D(c(n,i,"_pdf_eta_b2"),       	c(t,i,": pdf b2 #eta         "),     		80, -4.0, 4.0);
    		histo[i][289] = new TH1D(c(n,i,"_pdf_phi_b2"),      	c(t,i,": pdf b2 #phi         "),     		80, -4.0, 4.0);
		// W-boson for (l2)
    		histo[i][290] = new TH1D(c(n,i,"_pdf_e___W2"),       	c(t,i,": pdf W2 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][291] = new TH1D(c(n,i,"_pdf_pt__W2"),       	c(t,i,": pdf W2  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][292] = new TH1D(c(n,i,"_pdf_eta_W2"),       	c(t,i,": pdf W2 #eta         "),     		80, -4.0, 4.0);
    		histo[i][293] = new TH1D(c(n,i,"_pdf_phi_W2"),      	c(t,i,": pdf W2 #phi         "),     		80, -4.0, 4.0);
    		histo[i][294] = new TH1D(c(n,i,"_pdf_m___W2"),     	c(t,i,": pdf W2 mass [GeV]"),			50, 0.0,  500.0);
		// t-quark for (l2)
    		histo[i][295] = new TH1D(c(n,i,"_pdf_e___t2"),       	c(t,i,": pdf t2 Energy [GeV]"),  		bPt,  lPt, hPt);
    		histo[i][296] = new TH1D(c(n,i,"_pdf_pt__t2"),       	c(t,i,": pdf t2  p_{T} [GeV]"), 		bPt,  lPt, hPt);
    		histo[i][297] = new TH1D(c(n,i,"_pdf_eta_t2"),       	c(t,i,": pdf t2 #eta         "),     		80, -4.0, 4.0);
    		histo[i][298] = new TH1D(c(n,i,"_pdf_phi_t2"),      	c(t,i,": pdf t2 #phi         "),     		80, -4.0, 4.0);
    		histo[i][299] = new TH1D(c(n,i,"_pdf_m___t2"),     	c(t,i,": pdf t2 mass [GeV]"),			50, 0.0,  500.0);
		// ________________________________________________________________________________________________________________________________
		// Histograms for p.d.f.s__________________________________________________________________________________________________________ 
		// ________________________________________________________________________________________________________________________________



                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                                   Additional Histograms from Reco information                                             ::
                // ::					             from 300 - 399 							        ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// reconstructed information
		histo[i][300] = new TH1D(c(n, i, "_pt_neutrino"),      c(t, i, ": pt Neutrino "),           bPt,  lPt, hPt);
		histo[i][301] = new TH1D(c(n, i, "_e_neutrino"),       c(t, i, ": E  Neutrino "),           bPt,  lPt, hPt);
		histo[i][302] = new TH1D(c(n, i, "_pt_AntiNeutrino"),  c(t, i, ": pt Anti Neutrino "),      bPt,  lPt, hPt);
		histo[i][303] = new TH1D(c(n, i, "_e_AntiNeutrino"),   c(t, i, ": E  Anti Neutrino "),      bPt,  lPt, hPt);

                // top quarks,  W bosons, Higgs  _____________________________________________________________________
    		histo[i][310] = new TH1D(c(n,i,"_m_Wp"),       	c(t,i,": m W+ [GeV]"),            100, 0.0,  500.0);
    		histo[i][311] = new TH1D(c(n,i,"_m_Wn"),       	c(t,i,": m W- [GeV]"),            100, 0.0,  500.0);
    		histo[i][312] = new TH1D(c(n,i,"_m_t"),     	c(t,i,": m t  [GeV]"), 		  100, 0.0,  500.0);
    		histo[i][313] = new TH1D(c(n,i,"_m_tbar"),     	c(t,i,": m tbar [GeV]"),	  100, 0.0,  500.0);
    		histo[i][314] = new TH1D(c(n,i,"_m_ttbar"),     c(t,i,": m t#bar{t} [GeV]"),      100, 0.0, 1000.0);
    		histo[i][325] = new TH1D(c(n,i,"_m_Higgs"),     c(t,i,": m Higgs [GeV]"),      	  100, 0.0, 1000.0);
		//samor
    		histo[i][361] = new TH1D(c(n,i,"_m_Higgs_from_jet1"),     c(t,i,": m Higgs from jet1 [GeV]"),      	  	100, 0.0, 1000.0);
    		histo[i][362] = new TH1D(c(n,i,"_m_Higgs_from_jet2"),     c(t,i,": m Higgs from jet2 [GeV]"),      	  	100, 0.0, 1000.0);
    		histo[i][363] = new TH1D(c(n,i,"_m_Higgs_from_jets"),     c(t,i,": m Higgs from jets (2 entries) [GeV]"),      	20, 0.0, 400.0);
		// (jet,btag) multiplicity
		histo[i][328] = new TH1D(c(n, i, "_mult_jet_btag"),        c(t, i, ": mult. jets and btaggs"),             	12, 0.5, 12.5);

                //
    		histo[i][315] = new TH1D(c(n,i,"_pt_Wp"),       c(t,i,": p_{T} (W+)   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][316] = new TH1D(c(n,i,"_pt_Wn"),       c(t,i,": p_{T} (W-)   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][317] = new TH1D(c(n,i,"_pt_t"),    	c(t,i,": p_{T} (t)    [GeV]"), 	  bPt,  lPt, hPt);
    		histo[i][318] = new TH1D(c(n,i,"_pt_tbar"),    	c(t,i,": p_{T} (tbar) [GeV]"), 	  bPt,  lPt, hPt);
    		histo[i][319] = new TH1D(c(n,i,"_pt_TTbar"),    c(t,i,": p_{T} (t tbar) [GeV]"),  bPt,  lPt, hPt);
    		histo[i][326] = new TH1D(c(n,i,"_pt_Higgs"),    c(t,i,": p_{T} (Higgs) [GeV]"),   bPt,  lPt, hPt);

    		histo[i][364] = new TH1D(c(n,i,"_deltaR_Higgs"),    	c(t,i,": #Delta_{R} (Higgs)"),    	50,  0., 10.);
    		histo[i][365] = new TH1D(c(n,i,"_Total_Prob"),    	c(t,i,": Total Probability of ttH"),    100, 0., 50.);
		//
    		histo[i][320] = new TH1D(c(n,i,"_eta_Wp"),     	c(t,i,": #eta (W+)"),             80, -4.0, 4.0);
    		histo[i][321] = new TH1D(c(n,i,"_eta_Wn"),     	c(t,i,": #eta (W-)"),             80, -4.0, 4.0);
    		histo[i][322] = new TH1D(c(n,i,"_eta_t"),   	c(t,i,": #eta (t)"), 		  80, -4.0, 4.0);
    		histo[i][323] = new TH1D(c(n,i,"_eta_tbar"),   	c(t,i,": #eta (tbar)"),		  80, -4.0, 4.0);
    		histo[i][324] = new TH1D(c(n,i,"_eta_TTbar"),   c(t,i,": #eta (t tbar)"),         80, -4.0, 4.0);
    		histo[i][327] = new TH1D(c(n,i,"_eta_Higgs"),   c(t,i,": #eta (Higgs)"),          80, -4.0, 4.0);

		// RECO spin correlations distributions____________________________________________________________________________________________
		histo[i][330] = new TH1D(c(n, i, "_spincorr_coslp_cosln"), c(t, i, ": spin corr. cos(l+)xcos(l-)"), 	20, -1., 1.);
		histo[i][331] = new TH1D(c(n, i, "_spincorr_cosb_cosln"),  c(t, i, ": spin corr. cos(b)xcos(l-)"), 	20, -1., 1.);
		histo[i][332] = new TH1D(c(n, i, "_spincorr_coslp_cosbb"), c(t, i, ": spin corr. cos(l+)xcos(bbar)"), 	20, -1., 1.);
		histo[i][333] = new TH1D(c(n, i, "_spincorr_cosb_cosl"),   c(t, i, ": spin corr. cos(l)xcos(b)"), 	20, -1., 1.);
                //___2 bins____
		histo[i][334] = new TH1D(c(n, i, "_spincorr_coslp_cosln_2bins"), c(t, i, ": spin corr. cos(l+)xcos(l-) 2bins"), 	2, -1., 1.);
		histo[i][335] = new TH1D(c(n, i, "_spincorr_cosb_cosln_2bins"),  c(t, i, ": spin corr. cos(b)xcos(l-) 2bins"), 		2, -1., 1.);
		histo[i][336] = new TH1D(c(n, i, "_spincorr_coslp_cosbb_2bins"), c(t, i, ": spin corr. cos(l+)xcos(bbar) 2bins"), 	2, -1., 1.);
		histo[i][337] = new TH1D(c(n, i, "_spincorr_cosb_cosl_2bins"),   c(t, i, ": spin corr. cos(l)xcos(b) 2bins"), 		2, -1., 1.);

		// RECO W polarizations distributions______________________________________________________________________________________
		histo[i][340] = new TH1D(c(n, i, "_Wpol_coslpB"), 	   c(t, i, ": W pol. cos(l+,b) in W+"), 	20, -1., 1.);
		histo[i][341] = new TH1D(c(n, i, "_Wpol_coslnBbar"), 	   c(t, i, ": W pol. cos(l-,bbar) in W-"), 	20, -1., 1.);
		histo[i][342] = new TH1D(c(n, i, "_Wpol_coslB"), 	   c(t, i, ": W pol. cos(l,b) in W"), 		20, -1., 1.);
                //___2 bins____
		histo[i][343] = new TH1D(c(n, i, "_Wpol_coslpB_2bins"),    c(t, i, ": W pol. cos(l+,b) in W+ 2bins"), 	2, -1., 1.);
		histo[i][344] = new TH1D(c(n, i, "_Wpol_coslnBbar_2bins"), c(t, i, ": W pol. cos(l-,bbar) in W- 2bins"),2, -1., 1.);
		histo[i][345] = new TH1D(c(n, i, "_Wpol_coslB_2bins"), 	   c(t, i, ": W pol. cos(l,b) in W 2bins"), 	2, -1., 1.);
		//___4 bins (A+,A-,AFB)_________
		histo[i][346] = new TH1D(c(n, i, "_Wpol_coslpB_4bins"),    c(t, i, ": W pol. cos(l+,b) in W+ 4bins"), 	4, -1., 1.);
		histo[i][347] = new TH1D(c(n, i, "_Wpol_coslnBbar_4bins"), c(t, i, ": W pol. cos(l-,bbar) in W- 4bins"),4, -1., 1.);
		histo[i][348] = new TH1D(c(n, i, "_Wpol_coslB_4bins"), 	   c(t, i, ": W pol. cos(l,b) in W 4bins"), 	4, -1., 1.);

                //___20 bins from Mlb____
		histo[i][349] = new TH1D(c(n, i, "_Mlb_Wpol_coslpB"), 		c(t, i, ": Mlb W pol. cos(l+,b) in W+"), 		20, -1., 1.);
		histo[i][350] = new TH1D(c(n, i, "_Mlb_Wpol_coslnBbar"), 	c(t, i, ": Mlb W pol. cos(l-,bbar) in W-"), 		20, -1., 1.);
		histo[i][351] = new TH1D(c(n, i, "_Mlb_Wpol_coslB"), 		c(t, i, ": Mlb W pol. cos(l,b) in W"), 			20, -1., 1.);
                //___2 bins from Mlb____
		histo[i][352] = new TH1D(c(n, i, "_Mlb_Wpol_coslpB_2bins"), 	c(t, i, ": Mlb W pol. cos(l+,b) in W+ 2bins"), 		2, -1., 1.);
		histo[i][353] = new TH1D(c(n, i, "_Mlb_Wpol_coslnBbar_2bins"), 	c(t, i, ": Mlb W pol. cos(l-,bbar) in W- 2bins"), 	2, -1., 1.);
		histo[i][354] = new TH1D(c(n, i, "_Mlb_Wpol_coslB_2bins"), 	c(t, i, ": Mlb W pol. cos(l,b) in W 2bins"), 		2, -1., 1.);
		//___4 bins (A+,A-,AFB) from Mlb_________
		histo[i][355] = new TH1D(c(n, i, "_Mlb_Wpol_coslpB_4bins"), 	c(t, i, ": Mlb W pol. cos(l+,b) in W+ 4bins"), 		4, -1., 1.);
		histo[i][356] = new TH1D(c(n, i, "_Mlb_Wpol_coslnBbar_4bins"), 	c(t, i, ": Mlb W pol. cos(l-,bbar) in W- 4bins"), 	4, -1., 1.);
		histo[i][357] = new TH1D(c(n, i, "_Mlb_Wpol_coslB_4bins"), 	c(t, i, ": Mlb W pol. cos(l,b) in W 4bins"), 		4, -1., 1.);
		//___4 bins (A+,A-,AFB) from Mlb_________NO LIMITS
		histo[i][358] = new TH1D(c(n, i, "_Mlb_Wpol_coslpB_4bins_FULL"), 	c(t, i, ": Mlb W pol. cos(l+,b) in W+ 4bins FULL"), 	4, -1., 1.);
		histo[i][359] = new TH1D(c(n, i, "_Mlb_Wpol_coslnBbar_4bins_FULL"), 	c(t, i, ": Mlb W pol. cos(l-,bbar) in W- 4bins FULL"), 	4, -1., 1.);
		histo[i][360] = new TH1D(c(n, i, "_Mlb_Wpol_coslB_4bins_FULL"), 	c(t, i, ": Mlb W pol. cos(l,b) in W 4bins FULL"), 	4, -1., 1.);

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                                   Histograms for Object from Dilepton Topology                                            ::
                // ::					             from 400 - 499 							        ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// Lepton 1
    		histo[i][400] = new TH1D(c(n,i,"_pt_lep_1"),       c(t,i,": lep 1: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][401] = new TH1D(c(n,i,"_eta_lep_1"),      c(t,i,": lep 1: #eta         "),     40, -4.0, 4.0);
    		histo[i][402] = new TH1D(c(n,i,"_phi_lep_1"),      c(t,i,": lep 1: #phi         "),     40, -4.0, 4.0);
		// Lepton 2
    		histo[i][403] = new TH1D(c(n,i,"_pt_lep_2"),       c(t,i,": lep 2: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][404] = new TH1D(c(n,i,"_eta_lep_2"),      c(t,i,": lep 2: #eta         "),     40, -4.0, 4.0);
    		histo[i][405] = new TH1D(c(n,i,"_phi_lep_2"),      c(t,i,": lep 2: #phi         "),     40, -4.0, 4.0);
		//  jet 1
    		histo[i][406] = new TH1D(c(n,i,"_pt_jet_1"),       c(t,i,": jet 1: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][407] = new TH1D(c(n,i,"_eta_jet_1"),      c(t,i,": jet 1: #eta         "),     40, -4.0, 4.0);
    		histo[i][408] = new TH1D(c(n,i,"_phi_jet_1"),      c(t,i,": jet 1: #phi         "),     40, -4.0, 4.0);
		//  jet 2
    		histo[i][409] = new TH1D(c(n,i,"_pt_jet_2"),       c(t,i,": jet 2: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][410] = new TH1D(c(n,i,"_eta_jet_2"),      c(t,i,": jet 2: #eta         "),     40, -4.0, 4.0);
    		histo[i][411] = new TH1D(c(n,i,"_phi_jet_2"),      c(t,i,": jet 2: #phi         "),     40, -4.0, 4.0);
                // 
		// event properties
    		histo[i][412] = new TH1D(c(n,i,"_sphericity"),     c(t,i,": Event Sphericity"), 	51, -0.01, 0.5);
    		histo[i][413] = new TH1D(c(n,i,"_aplanarity"),     c(t,i,": Event Aplanarity"), 	51, -0.01, 0.5);
    		histo[i][414] = new TH1D(c(n,i,"_planarity"),      c(t,i,": Event Planarity"),  	50, -0.,   0.5);

		// Mlb mass distributions
		histo[i][415] = new TH1D(c(n, i, "_Mlb_for_lp"),     		c(t, i, ": Mlb (l+)"),               bMlb,  lMlb, hMlb);
		histo[i][416] = new TH1D(c(n, i, "_Mlb_for_ln"),     		c(t, i, ": Mlb (l-)"),               bMlb,  lMlb, hMlb);
		histo[i][417] = new TH1D(c(n, i, "_Mlb"),            		c(t, i, ": Mlb (l+,l-)"),            bMlb,  lMlb, hMlb);

		// Angular distributions from Mlb
		histo[i][418] = new TH1D(c(n, i, "_coslpB_from_Mlb_for_lp"), 	c(t, i, ": cos(l+,b) in W+ from M(l+b)"),      20,   -1.,   1.);
		histo[i][419] = new TH1D(c(n, i, "_coslnB_from_Mlb_for_ln"), 	c(t, i, ": cos(l-,b) in W- from M(l-b)"),      20,   -1.,   1.);
		histo[i][420] = new TH1D(c(n, i, "_coslB_from_Mlb"), 		c(t, i, ": cos(l,b)  in W  from M(lb) "),      20,   -1.,   1.);
                // Angular distributions from Mlb 2 bins from -1. to 1.
		histo[i][421] = new TH1D(c(n, i, "_coslpB_from_Mlb_2bins"),    	c(t, i, ": cos(l+,b) in W+ from M(l+b) 2bins"), 	2, -1., 1.);
		histo[i][422] = new TH1D(c(n, i, "_coslnB_from_Mlb_2bins"), 	c(t, i, ": cos(l-,b) in W- from M(l-b) 2bins"),		2, -1., 1.);
		histo[i][423] = new TH1D(c(n, i, "_coslB_from_Mlb_2bins"),	c(t, i, ": cos(l,b)  in W  from M(lb) 2bins"), 		2, -1., 1.);
		// Angular distributions from Mlb 4 bins from -1. to 1.
		histo[i][424] = new TH1D(c(n, i, "_coslpB_from_Mlb_4bins"), 	c(t, i, ": cos(l+,b) in W+ from M(l+b) 4bins"),      4,   -1.,   1.);
		histo[i][425] = new TH1D(c(n, i, "_coslnB_from_Mlb_4bins"), 	c(t, i, ": cos(l-,b) in W- from M(l-b) 4bins"),      4,   -1.,   1.);
		histo[i][426] = new TH1D(c(n, i, "_coslB_from_Mlb_4bins"), 	c(t, i, ": cos(l,b)  in W  from M(lb)  4bins"),      4,   -1.,   1.);
		// Angular distributions from Mlb 4 bins with NO LIMITS
		histo[i][427] = new TH1D(c(n, i, "_coslpB_from_Mlb_4bins_FULL"), 	c(t, i, ": cos(l+,b) in W+ from M(l+b) 4bins FULL"),      4,   -1.,   1.);
		histo[i][428] = new TH1D(c(n, i, "_coslnB_from_Mlb_4bins_FULL"), 	c(t, i, ": cos(l-,b) in W- from M(l-b) 4bins FULL"),      4,   -1.,   1.);
		histo[i][429] = new TH1D(c(n, i, "_coslB_from_Mlb_4bins_FULL"), 	c(t, i, ": cos(l,b)  in W  from M(lb)  4bins FULL"),      4,   -1.,   1.);

		// Mlb**2 mass distributions
		histo[i][430] = new TH1D(c(n, i, "_Mlb2_for_lp"),     		c(t, i, ": Mlb2 (l+)"),               bMlb2,  lMlb2, hMlb2);
		histo[i][431] = new TH1D(c(n, i, "_Mlb2_for_ln"),     		c(t, i, ": Mlb2 (l-)"),               bMlb2,  lMlb2, hMlb2);
		histo[i][432] = new TH1D(c(n, i, "_Mlb2"),            		c(t, i, ": Mlb2 (l+,l-)"),            bMlb2,  lMlb2, hMlb2);


                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                // ::                                         TRUTH VS RECONSTRUCTION COMPARISON                                                ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                histo[i][500] = new TH2D( c(n,i,"_Xtruth_Yrec_m_ttbar"),    c(t,i,": x=truth y=rec m t#bar{t} [GeV]"),   50, 0., 1000., 50, 0., 1000.);

/*
                // TRUTH vs Rec spin correlations distributions___________________________________________________________________________________________
                histo[i][530] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_coslp_cosln"), c(t, i, ": Xtruth_Yrec spin corr. cos(l+)xcos(l-)"),    20, -1., 1., 20, -1., 1.);
                histo[i][531] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_cosb_cosln"),  c(t, i, ": Xtruth_Yrec spin corr. cos(b)xcos(l-)"),     20, -1., 1., 20, -1., 1.);
                histo[i][532] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_coslp_cosbb"), c(t, i, ": Xtruth_Yrec spin corr. cos(l+)xcos(bbar)"),  20, -1., 1., 20, -1., 1.);
                histo[i][533] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_cosb_cosl"),   c(t, i, ": Xtruth_Yrec spin corr. cos(l)xcos(b)"),      20, -1., 1., 20, -1., 1.);
                //___2 bins____
                histo[i][534] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_coslp_cosln_2bins"), c(t, i, ": Xtruth_Yrec spin corr. cos(l+)xcos(l-) 2bins"),   2, -1., 1., 2, -1., 1.);
                histo[i][535] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_cosb_cosln_2bins"),  c(t, i, ": Xtruth_Yrec spin corr. cos(b)xcos(l-) 2bins"),    2, -1., 1., 2, -1., 1.);
                histo[i][536] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_coslp_cosbb_2bins"), c(t, i, ": Xtruth_Yrec spin corr. cos(l+)xcos(bbar) 2bins"), 2, -1., 1., 2, -1., 1.);
                histo[i][537] = new TH2D(c(n, i, "_Xtruth_Yrec_spincorr_cosb_cosl_2bins"),   c(t, i, ": Xtruth_Yrec spin corr. cos(l)xcos(b) 2bins"),     2, -1., 1., 2, -1., 1.);

                // Xtruth_Yrec W polarizations distributions_____________________________________________________________________________________________
                histo[i][540] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslpB"),    c(t, i, ": Xtruth_Yrec W pol. cos(l+,b) in W+"),            20, -1., 1., 20, -1., 1.);
                histo[i][541] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslnBbar"),         c(t, i, ": Xtruth_Yrec W pol. cos(l-,bbar) in W-"), 20, -1., 1., 20, -1., 1.);
                histo[i][542] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslB"),             c(t, i, ": Xtruth_Yrec W pol. cos(l,b) in W"),      20, -1., 1., 20, -1., 1.);
                //___2 bins____
                histo[i][543] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslpB_2bins"),	 c(t, i, ": Xtruth_Yrec W pol. cos(l+,b) in W+ 2bins"),  2, -1., 1., 2, -1., 1.);
                histo[i][544] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslnBbar_2bins"), c(t, i, ": Xtruth_Yrec W pol. cos(l-,bbar) in W- 2bins"), 2, -1., 1., 2, -1., 1.);
                histo[i][545] = new TH2D(c(n, i, "_Xtruth_Yrec_Wpol_coslB_2bins"),	 c(t, i, ": Xtruth_Yrec W pol. cos(l,b) in W 2bins"),    2, -1., 1., 2, -1., 1.);

               //___20 bins from Mlb____
                histo[i][549] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslpB"),	c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l+,b) in W+"),              20, -1., 1., 20, -1., 1.);
                histo[i][550] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslnBbar"),    c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l-,bbar) in W-"),           20, -1., 1., 20, -1., 1.);
                histo[i][551] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslB"),        c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l,b) in W"),                20, -1., 1., 20, -1., 1.);
                //___2 bins from Mlb____
                histo[i][552] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslpB_2bins"),         c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l+,b) in W+ 2bins"),    2, -1., 1., 2, -1., 1.);
                histo[i][553] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslnBbar_2bins"),	c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l-,bbar) in W- 2bins"), 2, -1., 1., 2, -1., 1.);
                histo[i][554] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_Wpol_coslB_2bins"),  c(t, i, ": Xtruth_Yrec Mlb W pol. cos(l,b) in W 2bins"),              2, -1., 1., 2, -1., 1.);

                // Mlb mass distributions
                histo[i][561] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_for_lp"),                    c(t, i, ": Xtruth_Yrec Mlb (l+)"),               bMlb,  lMlb, hMlb, bMlb,  lMlb, hMlb);
                histo[i][562] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb_for_ln"),                    c(t, i, ": Xtruth_Yrec Mlb (l-)"),               bMlb,  lMlb, hMlb, bMlb,  lMlb, hMlb);
                histo[i][563] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb"),                           c(t, i, ": Xtruth_Yrec Mlb (l+,l-)"),            bMlb,  lMlb, hMlb, bMlb,  lMlb, hMlb);
                // Mlb**2 mass distributions
                histo[i][564] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb2_for_lp"),                   c(t, i, ": Xtruth_Yrec Mlb2 (l+)"),              bMlb2,  lMlb2, hMlb2, bMlb2,  lMlb2, hMlb2);
                histo[i][565] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb2_for_ln"),                   c(t, i, ": Xtruth_Yrec Mlb2 (l-)"),              bMlb2,  lMlb2, hMlb2, bMlb2,  lMlb2, hMlb2);
                histo[i][566] = new TH2D(c(n, i, "_Xtruth_Yrec_Mlb2"),                          c(t, i, ": Xtruth_Yrec Mlb2 (l+,l-)"),           bMlb2,  lMlb2, hMlb2, bMlb2,  lMlb2, hMlb2);
*/
                // Resolution plots for Cos(theta*), pT and pZ of neutrinos
                histo[i][567] = new TH1D(c(n, i, "_Resol_Wpol_coslpB"),                         c(t, i, ": Resolution cos(l+,b) in W+"),      100,   -2.,   2.);
                histo[i][568] = new TH1D(c(n, i, "_Resol_Wpol_coslnB"),                         c(t, i, ": Resolution cos(l-,b) in W-"),      100,   -2.,   2.);
                histo[i][569] = new TH1D(c(n, i, "_Resol_Wpol_coslB"),                          c(t, i, ": Resolution cos(l,b) in W  "),      100,   -2.,   2.);
                // neutrino......
                histo[i][570] = new TH1D(c(n, i, "_Resol_pT_neutrino"),                         c(t, i, ": Resolution pT Neutrino  "),        100,   -20.,   20.);
                histo[i][571] = new TH1D(c(n, i, "_Resol_pZ_neutrino"),                         c(t, i, ": Resolution pZ Neutrino  "),        100,  -100.,  100.);
                // neutrino......
                histo[i][572] = new TH1D(c(n, i, "_Resol_pT_Anti_neutrino"),                    c(t, i, ": Resolution pT Anti-Neutrino  "),        100,   -20.,   20.);
                histo[i][573] = new TH1D(c(n, i, "_Resol_pZ_Anti_neutrino"),                    c(t, i, ": Resolution pZ Anti-Neutrino  "),        100,  -100.,  100.);


		// Mlb mass distributions Reconstruction Level 
                histo[i][574] = new TH1D(c(n, i, "_Mlb_reco_right"),                         	c(t, i, ": Mlb_reco_right"),            bMlb,  lMlb, hMlb);
                histo[i][575] = new TH1D(c(n, i, "_Mlb_reco_wrong"),                         	c(t, i, ": Mlb_reco_wrong"),            bMlb,  lMlb, hMlb);
                histo[i][576] = new TH1D(c(n, i, "_Mlb_reco_diff"),                          	c(t, i, ": Mlb_reco_diff"),           2*bMlb, -hMlb, hMlb);
		// Mlb mass distributions Truth Level
                histo[i][577] = new TH1D(c(n, i, "_Mlb_truth_right"),                         	c(t, i, ": Mlb_truth_right"),            bMlb,  lMlb, hMlb);
                histo[i][578] = new TH1D(c(n, i, "_Mlb_truth_wrong"),                         	c(t, i, ": Mlb_truth_wrong"),            bMlb,  lMlb, hMlb);
                histo[i][579] = new TH1D(c(n, i, "_Mlb_truth_diff"),                          	c(t, i, ": Mlb_truth_diff"),           2*bMlb, -hMlb, hMlb);


		// Scale factors 2D Distributions
		// ______matched electrons_______
                histo[i][582] = new TH2D(c(n, i, "_ele_matched_reco_SF_pT"),            c(t, i, ": reco_SF    vs pT (matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][583] = new TH2D(c(n, i, "_ele_matched_ID_SF_pT"),              c(t, i, ": ID_SF      vs pT (matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][584] = new TH2D(c(n, i, "_ele_matched_trigger_SF_pT"),         c(t, i, ": trigger_SF vs pT (matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
		// ____non_matched electrons_____
                histo[i][585] = new TH2D(c(n, i, "_ele_non_matched_reco_SF_pT"),        c(t, i, ": reco_SF    vs pT (non matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][586] = new TH2D(c(n, i, "_ele_non_matched_ID_SF_pT"),          c(t, i, ": ID_SF      vs pT (non matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][587] = new TH2D(c(n, i, "_ele_non_matched_trigger_SF_pT"),     c(t, i, ": trigger_SF vs pT (non matched ele)"),  bPt, lPt, hPt,  600,  -5., 25.);
		// _________muons________________
                histo[i][588] = new TH2D(c(n, i, "_muon_reco_SF_pT"),            	c(t, i, ": reco_SF     vs pT (muon)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][589] = new TH2D(c(n, i, "_muon_ID_SF_pT"),              	c(t, i, ": ID_SF       vs pT (muon)"),  bPt, lPt, hPt,  600,  -5., 25.);
                histo[i][590] = new TH2D(c(n, i, "_muon_trigger_eff_pT"),         	c(t, i, ": trigger eff vs pT (muon)"),  bPt, lPt, hPt,  600,  -5., 25.);
		// _______event weights__________
                histo[i][591] = new TH1D(c(n, i, "_event_weights_pT"),            	c(t, i, ": event weights  vs pT "),  600,  -5., 25.);


		// Positive Lepton
    		histo[i][592] = new TH1D(c(n,i,"_pt_lep_pos"),       c(t,i,": lep pos: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][593] = new TH1D(c(n,i,"_eta_lep_pos"),      c(t,i,": lep pos: #eta         "),     40, -4.0, 4.0);
    		histo[i][594] = new TH1D(c(n,i,"_phi_lep_pos"),      c(t,i,": lep pos: #phi         "),     40, -4.0, 4.0);
		// Negative Lepton
    		histo[i][595] = new TH1D(c(n,i,"_pt_lep_neg"),       c(t,i,": lep neg: p_{T}   [GeV]"),    bPt,  lPt, hPt);
    		histo[i][596] = new TH1D(c(n,i,"_eta_lep_neg"),      c(t,i,": lep neg: #eta         "),     40, -4.0, 4.0);
    		histo[i][597] = new TH1D(c(n,i,"_phi_lep_neg"),      c(t,i,": lep neg: #phi         "),     40, -4.0, 4.0);

		histo[i][598] = new TH1D(c(n, i, "_ll_pz"),                                     c(t, i, ": pz (ll)"),                              100,     0., 1000.);
		histo[i][599] = new TH1D(c(n, i, "_ll_pt"),                                     c(t, i, ": pt (ll)"),                               40,     0.,  400.);


                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                                   Additional Histograms for OBJECT Resolution ( Truth - Rec )                             ::
                // ::					             from 600 - 699 							        ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	        // Resolution for leptons
        	int   nRlep =  100 ;
        	float lRlep =   -1.0;
        	float hRlep =   +1.0;
		float eRlep =    1.;  // scale factor for energy
                // electrons......
                histo[i][600] = new TH1D(c(n, i, "_Resol_pX_electrons"),                         c(t, i, ": Resolution pX electrons  "),        nRlep,        lRlep,       hRlep);
                histo[i][601] = new TH1D(c(n, i, "_Resol_pY_electrons"),                         c(t, i, ": Resolution pY electrons  "),        nRlep,        lRlep,       hRlep);
                histo[i][602] = new TH1D(c(n, i, "_Resol_pZ_electrons"),                         c(t, i, ": Resolution pZ electrons  "),        nRlep,        lRlep,       hRlep);
                histo[i][603] = new TH1D(c(n, i, "_Resol_pT_electrons"),                         c(t, i, ": Resolution pT electrons  "),        nRlep,        lRlep,       hRlep);
                histo[i][604] = new TH1D(c(n, i, "_Resol_E_electrons"),                          c(t, i, ": Resolution E  electrons  "),        nRlep,  eRlep*lRlep, eRlep*hRlep);
                // muons......
                histo[i][605] = new TH1D(c(n, i, "_Resol_pX_muons"),                             c(t, i, ": Resolution pX muons  "),            nRlep,        lRlep,       hRlep);
                histo[i][606] = new TH1D(c(n, i, "_Resol_pY_muons"),                             c(t, i, ": Resolution pY muons  "),            nRlep,        lRlep,       hRlep);
                histo[i][607] = new TH1D(c(n, i, "_Resol_pZ_muons"),                             c(t, i, ": Resolution pZ muons  "),            nRlep,        lRlep,       hRlep);
                histo[i][608] = new TH1D(c(n, i, "_Resol_pT_muons"),                             c(t, i, ": Resolution pT muons  "),            nRlep,        lRlep,       hRlep);
                histo[i][609] = new TH1D(c(n, i, "_Resol_E_muons"),                              c(t, i, ": Resolution E  muons  "),            nRlep,  eRlep*lRlep, eRlep*hRlep);
		//
	        // Resolution for jets
        	int   nRjet =  100 ;
        	float lRjet =   -1.5;
        	float hRjet =   +1.5;
		float eRjet =    1.;  // scale factor for energy
                // b-jets..........
                histo[i][610] = new TH1D(c(n, i, "_Resol_pX_bjets"),                             c(t, i, ": Resolution pX bjets  "),            nRjet,        lRjet,       hRjet);
                histo[i][611] = new TH1D(c(n, i, "_Resol_pY_bjets"),                             c(t, i, ": Resolution pY bjets  "),            nRjet,        lRjet,       hRjet);
                histo[i][612] = new TH1D(c(n, i, "_Resol_pZ_bjets"),                             c(t, i, ": Resolution pZ bjets  "),            nRjet,        lRjet,       hRjet);
                histo[i][613] = new TH1D(c(n, i, "_Resol_pT_bjets"),                             c(t, i, ": Resolution pT bjets  "),            nRjet,        lRjet,       hRjet);
                histo[i][614] = new TH1D(c(n, i, "_Resol_E_bjets"),                              c(t, i, ": Resolution E  bjets  "),            nRjet,  eRjet*lRjet, eRjet*hRjet);
		//
	        // Resolution for Ptmis
        	int   nRmis =  100 ;
        	float lRmis =   -1.5;
        	float hRmis =   +1.5;
                // non b-jets......
                histo[i][615] = new TH1D(c(n, i, "_Resol_pXmis"),                                c(t, i, ": Resolution pXmis  "),               nRmis,        lRmis,       hRmis);
                histo[i][616] = new TH1D(c(n, i, "_Resol_pYmis"),                                c(t, i, ": Resolution pYmis  "),               nRmis,        lRmis,       hRmis);
                histo[i][617] = new TH1D(c(n, i, "_Resol_pTmis"),                                c(t, i, ": Resolution pTmis  "),               nRmis,        lRmis,       hRmis);

	        //
	        // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                            Reserved (see below): p.d.f.s Histograms and cloned ones to Level 0                            ::
	        // ::					            numbers between 700 - 799   				        	::
	        // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                // ::                                        Additional Histograms for Z Data Driven Methods                                    ::
                // ::                                                from   800  OS                                                             ::
                // ::                                                from   1200 SS                                                             ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ================= OS Distributions =========================
                //.........Mll versus Etmis Z DD OS ...........................
                // Nj>=2 
                histo[i][800] = new TH2D( c(n,i,"_XMll_YMET_NjGe2NbGe0_OS"), c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2NbGe0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][801] = new TH2D( c(n,i,"_XMll_YMET_NjGe2Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2Nb0 OS"),     130,  0.,  260.,  100, 0., 200. );
                histo[i][802] = new TH2D( c(n,i,"_XMll_YMET_NjGe2Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2Nb1 OS"),     130,  0.,  260.,  100, 0., 200. );
                histo[i][803] = new TH2D( c(n,i,"_XMll_YMET_NjGe2NbGe2_OS"), c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2NbGe2 OS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=2 
                histo[i][804] = new TH2D( c(n,i,"_XMll_YMET_Nj2Pre_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Pre OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][805] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][806] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb1 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][807] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb2_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb2 OS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=3
                histo[i][808] = new TH2D( c(n,i,"_XMll_YMET_Nj3Pre_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Pre OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][809] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][810] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb1 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][811] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb2_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb2 OS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=4
                histo[i][812] = new TH2D( c(n,i,"_XMll_YMET_Nj4Pre_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Pre OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][813] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][814] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb1 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][815] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb2_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb2 OS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=5
                histo[i][816] = new TH2D( c(n,i,"_XMll_YMET_Nj5Pre_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Pre OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][817] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][818] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb1 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][819] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb2_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb2 OS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj>=6
                histo[i][820] = new TH2D( c(n,i,"_XMll_YMET_Nj6Pre_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Pre OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][821] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb0_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb0 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][822] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb1_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb1 OS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][823] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb2_OS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb2 OS"),   130,  0.,  260.,  100, 0., 200. );

                // Nj>=2 Nb0>=0 Counters --------------------------------------
                histo[i][830] = new TH1D(c(n, i, "_ZjetsDD_NjGe2NbGe0_OS"),      c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe0 OS"),  10, -0.5,  9.5  );
                histo[i][831] = new TH1D(c(n, i, "_ZjetsDD_NjGe2Nb0_OS"),        c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb0 OS"),    10, -0.5,  9.5  );
                histo[i][832] = new TH1D(c(n, i, "_ZjetsDD_NjGe2Nb1_OS"),        c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb1 OS"),    10, -0.5,  9.5  );
                histo[i][833] = new TH1D(c(n, i, "_ZjetsDD_NjGe2NbGe2_OS"),      c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe2 OS"),  10, -0.5,  9.5  );
                // Nj=2 Counters 
                histo[i][834] = new TH1D(c(n, i, "_ZjetsDD_Nj2Pre_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Pre OS"),     10, -0.5,  9.5  );
                histo[i][835] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb0_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][836] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb1_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][837] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb2_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=3 Counters
                histo[i][838] = new TH1D(c(n, i, "_ZjetsDD_Nj3Pre_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Pre OS"),     10, -0.5,  9.5  );
                histo[i][839] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb0_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][840] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb1_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][841] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb2_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=4 Counters
                histo[i][842] = new TH1D(c(n, i, "_ZjetsDD_Nj4Pre_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Pre OS"),     10, -0.5,  9.5  );
                histo[i][843] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb0_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][844] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb1_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][845] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb2_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=5 Counters
                histo[i][846] = new TH1D(c(n, i, "_ZjetsDD_Nj5Pre_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Pre OS"),     10, -0.5,  9.5  );
                histo[i][847] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb0_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][848] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb1_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][849] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb2_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb2 OS"),     10, -0.5,  9.5  );
                // Nj>=6 Counters
                histo[i][850] = new TH1D(c(n, i, "_ZjetsDD_Nj6Pre_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Pre OS"),     10, -0.5,  9.5  );
                histo[i][851] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb0_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][852] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb1_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][853] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb2_OS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb2 OS"),     10, -0.5,  9.5  );

                //Nj>=2 btag>=0 ----------------------------------------------
                histo[i][860] = new TH1D(c(n, i, "_Mll_NjGe2NbGe0_OS"),          c(t, i, ": Mll Nj2GeNbGe0 OS"),                      bM,    lM, hM    );
                histo[i][861] = new TH1D(c(n, i, "_Mll_NjGe2Nb0_OS"),            c(t, i, ": Mll Nj2GeNb0 OS"),                        bM,    lM, hM    );
                histo[i][862] = new TH1D(c(n, i, "_Mll_NjGe2Nb1_OS"),            c(t, i, ": Mll Nj2GeNb1 OS"),                        bM,    lM, hM    );
                histo[i][863] = new TH1D(c(n, i, "_Mll_NjGe2NbGe2_OS"),          c(t, i, ": Mll Nj2GeNbGe2 OS"),                      bM,    lM, hM    );
                // Nj=2 
                histo[i][864] = new TH1D(c(n, i, "_Mll_Nj2Pre_OS"),              c(t, i, ": Mll Nj2Pre OS"),                          bM,    lM, hM    );
                histo[i][865] = new TH1D(c(n, i, "_Mll_Nj2Nb0_OS"),              c(t, i, ": Mll Nj2Nb0 OS"),                          bM,    lM, hM    );
                histo[i][866] = new TH1D(c(n, i, "_Mll_Nj2Nb1_OS"),              c(t, i, ": Mll Nj2Nb1 OS"),                          bM,    lM, hM    );
                histo[i][867] = new TH1D(c(n, i, "_Mll_Nj2Nb2_OS"),              c(t, i, ": Mll Nj2Nb2 OS"),                          bM,    lM, hM    );
                // Nj=3
                histo[i][868] = new TH1D(c(n, i, "_Mll_Nj3Pre_OS"),              c(t, i, ": Mll Nj3Pre OS"),                          bM,    lM, hM    );
                histo[i][869] = new TH1D(c(n, i, "_Mll_Nj3Nb0_OS"),              c(t, i, ": Mll Nj3Nb0 OS"),                          bM,    lM, hM    );
                histo[i][870] = new TH1D(c(n, i, "_Mll_Nj3Nb1_OS"),              c(t, i, ": Mll Nj3Nb1 OS"),                          bM,    lM, hM    );
                histo[i][871] = new TH1D(c(n, i, "_Mll_Nj3Nb2_OS"),              c(t, i, ": Mll Nj3Nb2 OS"),                          bM,    lM, hM    );
                // Nj=4
                histo[i][872] = new TH1D(c(n, i, "_Mll_Nj4Pre_OS"),              c(t, i, ": Mll Nj4Pre OS"),                          bM,    lM, hM    );
                histo[i][873] = new TH1D(c(n, i, "_Mll_Nj4Nb0_OS"),              c(t, i, ": Mll Nj4Nb0 OS"),                          bM,    lM, hM    );
                histo[i][874] = new TH1D(c(n, i, "_Mll_Nj4Nb1_OS"),              c(t, i, ": Mll Nj4Nb1 OS"),                          bM,    lM, hM    );
                histo[i][875] = new TH1D(c(n, i, "_Mll_Nj4Nb2_OS"),              c(t, i, ": Mll Nj4Nb2 OS"),                          bM,    lM, hM    );
                // Nj=5
                histo[i][876] = new TH1D(c(n, i, "_Mll_Nj5Pre_OS"),              c(t, i, ": Mll Nj5Pre OS"),                          bM,    lM, hM    );
                histo[i][877] = new TH1D(c(n, i, "_Mll_Nj5Nb0_OS"),              c(t, i, ": Mll Nj5Nb0 OS"),                          bM,    lM, hM    );
                histo[i][878] = new TH1D(c(n, i, "_Mll_Nj5Nb1_OS"),              c(t, i, ": Mll Nj5Nb1 OS"),                          bM,    lM, hM    );
                histo[i][879] = new TH1D(c(n, i, "_Mll_Nj5Nb2_OS"),              c(t, i, ": Mll Nj5Nb2 OS"),                          bM,    lM, hM    );
                // Nj>=6
                histo[i][880] = new TH1D(c(n, i, "_Mll_Nj6Pre_OS"),              c(t, i, ": Mll Nj6Pre OS"),                          bM,    lM, hM    );
                histo[i][881] = new TH1D(c(n, i, "_Mll_Nj6Nb0_OS"),              c(t, i, ": Mll Nj6Nb0 OS"),                          bM,    lM, hM    );
                histo[i][882] = new TH1D(c(n, i, "_Mll_Nj6Nb1_OS"),              c(t, i, ": Mll Nj6Nb1 OS"),                          bM,    lM, hM    );
                histo[i][883] = new TH1D(c(n, i, "_Mll_Nj6Nb2_OS"),              c(t, i, ": Mll Nj6Nb2 OS"),                          bM,    lM, hM    );

                //Nj>=2 btag>=0 ---- PT -----------------------------------------
                histo[i][890] = new TH1D(c(n, i, "_PTll_NjGe2NbGe0_OS"),          c(t, i, ": PTll Nj2GeNbGe0 OS"),                      bPt,    lPt, hPt    );
                histo[i][891] = new TH1D(c(n, i, "_PTll_NjGe2Nb0_OS"),            c(t, i, ": PTll Nj2GeNb0 OS"),                        bPt,    lPt, hPt    );
                histo[i][892] = new TH1D(c(n, i, "_PTll_NjGe2Nb1_OS"),            c(t, i, ": PTll Nj2GeNb1 OS"),                        bPt,    lPt, hPt    );
                histo[i][893] = new TH1D(c(n, i, "_PTll_NjGe2NbGe2_OS"),          c(t, i, ": PTll Nj2GeNbGe2 OS"),                      bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][894] = new TH1D(c(n, i, "_PTll_Nj2Pre_OS"),              c(t, i, ": PTll Nj2Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][895] = new TH1D(c(n, i, "_PTll_Nj2Nb0_OS"),              c(t, i, ": PTll Nj2Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][896] = new TH1D(c(n, i, "_PTll_Nj2Nb1_OS"),              c(t, i, ": PTll Nj2Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][897] = new TH1D(c(n, i, "_PTll_Nj2Nb2_OS"),              c(t, i, ": PTll Nj2Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][898] = new TH1D(c(n, i, "_PTll_Nj3Pre_OS"),              c(t, i, ": PTll Nj3Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][899] = new TH1D(c(n, i, "_PTll_Nj3Nb0_OS"),              c(t, i, ": PTll Nj3Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][900] = new TH1D(c(n, i, "_PTll_Nj3Nb1_OS"),              c(t, i, ": PTll Nj3Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][901] = new TH1D(c(n, i, "_PTll_Nj3Nb2_OS"),              c(t, i, ": PTll Nj3Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][902] = new TH1D(c(n, i, "_PTll_Nj4Pre_OS"),              c(t, i, ": PTll Nj4Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][903] = new TH1D(c(n, i, "_PTll_Nj4Nb0_OS"),              c(t, i, ": PTll Nj4Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][904] = new TH1D(c(n, i, "_PTll_Nj4Nb1_OS"),              c(t, i, ": PTll Nj4Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][905] = new TH1D(c(n, i, "_PTll_Nj4Nb2_OS"),              c(t, i, ": PTll Nj4Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][906] = new TH1D(c(n, i, "_PTll_Nj5Pre_OS"),              c(t, i, ": PTll Nj5Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][907] = new TH1D(c(n, i, "_PTll_Nj5Nb0_OS"),              c(t, i, ": PTll Nj5Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][908] = new TH1D(c(n, i, "_PTll_Nj5Nb1_OS"),              c(t, i, ": PTll Nj5Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][909] = new TH1D(c(n, i, "_PTll_Nj5Nb2_OS"),              c(t, i, ": PTll Nj5Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][910] = new TH1D(c(n, i, "_PTll_Nj6Pre_OS"),              c(t, i, ": PTll Nj6Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][911] = new TH1D(c(n, i, "_PTll_Nj6Nb0_OS"),              c(t, i, ": PTll Nj6Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][912] = new TH1D(c(n, i, "_PTll_Nj6Nb1_OS"),              c(t, i, ": PTll Nj6Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][913] = new TH1D(c(n, i, "_PTll_Nj6Nb2_OS"),              c(t, i, ": PTll Nj6Nb2 OS"),                          bPt,    lPt, hPt    );

                // Nj>=2 ---- PT -------------CONTROL---------------------
                histo[i][920] = new TH1D(c(n, i, "_PTll_NjGe2NbGe0_OS_CONTROL"),          c(t, i, ": PTll Nj2GeNbGe0 OS Control"),                      bPt,    lPt, hPt    );
                histo[i][921] = new TH1D(c(n, i, "_PTll_NjGe2Nb0_OS_CONTROL"),            c(t, i, ": PTll Nj2GeNb0 OS Control"),                        bPt,    lPt, hPt    );
                histo[i][922] = new TH1D(c(n, i, "_PTll_NjGe2Nb1_OS_CONTROL"),            c(t, i, ": PTll Nj2GeNb1 OS Control"),                        bPt,    lPt, hPt    );
                histo[i][923] = new TH1D(c(n, i, "_PTll_NjGe2NbGe2_OS_CONTROL"),          c(t, i, ": PTll Nj2GeNbGe2 OS Control"),                      bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][924] = new TH1D(c(n, i, "_PTll_Nj2Pre_OS_CONTROL"),              c(t, i, ": PTll Nj2Pre OS Control"),                          bPt,    lPt, hPt    );
                histo[i][925] = new TH1D(c(n, i, "_PTll_Nj2Nb0_OS_CONTROL"),              c(t, i, ": PTll Nj2Nb0 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][926] = new TH1D(c(n, i, "_PTll_Nj2Nb1_OS_CONTROL"),              c(t, i, ": PTll Nj2Nb1 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][927] = new TH1D(c(n, i, "_PTll_Nj2Nb2_OS_CONTROL"),              c(t, i, ": PTll Nj2Nb2 OS Control"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][928] = new TH1D(c(n, i, "_PTll_Nj3Pre_OS_CONTROL"),              c(t, i, ": PTll Nj3Pre OS Control"),                          bPt,    lPt, hPt    );
                histo[i][929] = new TH1D(c(n, i, "_PTll_Nj3Nb0_OS_CONTROL"),              c(t, i, ": PTll Nj3Nb0 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][930] = new TH1D(c(n, i, "_PTll_Nj3Nb1_OS_CONTROL"),              c(t, i, ": PTll Nj3Nb1 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][931] = new TH1D(c(n, i, "_PTll_Nj3Nb2_OS_CONTROL"),              c(t, i, ": PTll Nj3Nb2 OS Control"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][932] = new TH1D(c(n, i, "_PTll_Nj4Pre_OS_CONTROL"),              c(t, i, ": PTll Nj4Pre OS Control"),                          bPt,    lPt, hPt    );
                histo[i][933] = new TH1D(c(n, i, "_PTll_Nj4Nb0_OS_CONTROL"),              c(t, i, ": PTll Nj4Nb0 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][934] = new TH1D(c(n, i, "_PTll_Nj4Nb1_OS_CONTROL"),              c(t, i, ": PTll Nj4Nb1 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][935] = new TH1D(c(n, i, "_PTll_Nj4Nb2_OS_CONTROL"),              c(t, i, ": PTll Nj4Nb2 OS Control"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][936] = new TH1D(c(n, i, "_PTll_Nj5Pre_OS_CONTROL"),              c(t, i, ": PTll Nj5Pre OS Control"),                          bPt,    lPt, hPt    );
                histo[i][937] = new TH1D(c(n, i, "_PTll_Nj5Nb0_OS_CONTROL"),              c(t, i, ": PTll Nj5Nb0 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][938] = new TH1D(c(n, i, "_PTll_Nj5Nb1_OS_CONTROL"),              c(t, i, ": PTll Nj5Nb1 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][939] = new TH1D(c(n, i, "_PTll_Nj5Nb2_OS_CONTROL"),              c(t, i, ": PTll Nj5Nb2 OS Control"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][940] = new TH1D(c(n, i, "_PTll_Nj6Pre_OS_CONTROL"),              c(t, i, ": PTll Nj6Pre OS Control"),                          bPt,    lPt, hPt    );
                histo[i][941] = new TH1D(c(n, i, "_PTll_Nj6Nb0_OS_CONTROL"),              c(t, i, ": PTll Nj6Nb0 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][942] = new TH1D(c(n, i, "_PTll_Nj6Nb1_OS_CONTROL"),              c(t, i, ": PTll Nj6Nb1 OS Control"),                          bPt,    lPt, hPt    );
                histo[i][943] = new TH1D(c(n, i, "_PTll_Nj6Nb2_OS_CONTROL"),              c(t, i, ": PTll Nj6Nb2 OS Control"),                          bPt,    lPt, hPt    );

                // Nj>=2 ---- ETA -----------------------------------------
                histo[i][950] = new TH1D(c(n, i, "_Etall_NjGe2NbGe0_OS"),          c(t, i, ": Etall Nj2GeNbGe0 OS"),                     40, -4.0, 4.0);
                histo[i][951] = new TH1D(c(n, i, "_Etall_NjGe2Nb0_OS"),            c(t, i, ": Etall Nj2GeNb0 OS"),                       40, -4.0, 4.0);
                histo[i][952] = new TH1D(c(n, i, "_Etall_NjGe2Nb1_OS"),            c(t, i, ": Etall Nj2GeNb1 OS"),                       40, -4.0, 4.0);
                histo[i][953] = new TH1D(c(n, i, "_Etall_NjGe2NbGe2_OS"),          c(t, i, ": Etall Nj2GeNbGe2 OS"),                     40, -4.0, 4.0);
                // Nj=2
                histo[i][954] = new TH1D(c(n, i, "_Etall_Nj2Pre_OS"),              c(t, i, ": Etall Nj2Pre OS"),                          40, -4.0, 4.0);
                histo[i][955] = new TH1D(c(n, i, "_Etall_Nj2Nb0_OS"),              c(t, i, ": Etall Nj2Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][956] = new TH1D(c(n, i, "_Etall_Nj2Nb1_OS"),              c(t, i, ": Etall Nj2Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][957] = new TH1D(c(n, i, "_Etall_Nj2Nb2_OS"),              c(t, i, ": Etall Nj2Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][958] = new TH1D(c(n, i, "_Etall_Nj3Pre_OS"),              c(t, i, ": Etall Nj3Pre OS"),                          40, -4.0, 4.0);
                histo[i][959] = new TH1D(c(n, i, "_Etall_Nj3Nb0_OS"),              c(t, i, ": Etall Nj3Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][960] = new TH1D(c(n, i, "_Etall_Nj3Nb1_OS"),              c(t, i, ": Etall Nj3Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][961] = new TH1D(c(n, i, "_Etall_Nj3Nb2_OS"),              c(t, i, ": Etall Nj3Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][962] = new TH1D(c(n, i, "_Etall_Nj4Pre_OS"),              c(t, i, ": Etall Nj4Pre OS"),                          40, -4.0, 4.0);
                histo[i][963] = new TH1D(c(n, i, "_Etall_Nj4Nb0_OS"),              c(t, i, ": Etall Nj4Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][964] = new TH1D(c(n, i, "_Etall_Nj4Nb1_OS"),              c(t, i, ": Etall Nj4Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][965] = new TH1D(c(n, i, "_Etall_Nj4Nb2_OS"),              c(t, i, ": Etall Nj4Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][966] = new TH1D(c(n, i, "_Etall_Nj5Pre_OS"),              c(t, i, ": Etall Nj5Pre OS"),                          40, -4.0, 4.0);
                histo[i][967] = new TH1D(c(n, i, "_Etall_Nj5Nb0_OS"),              c(t, i, ": Etall Nj5Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][968] = new TH1D(c(n, i, "_Etall_Nj5Nb1_OS"),              c(t, i, ": Etall Nj5Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][969] = new TH1D(c(n, i, "_Etall_Nj5Nb2_OS"),              c(t, i, ": Etall Nj5Nb2 OS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][970] = new TH1D(c(n, i, "_Etall_Nj6Pre_OS"),              c(t, i, ": Etall Nj6Pre OS"),                          40, -4.0, 4.0);
                histo[i][971] = new TH1D(c(n, i, "_Etall_Nj6Nb0_OS"),              c(t, i, ": Etall Nj6Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][972] = new TH1D(c(n, i, "_Etall_Nj6Nb1_OS"),              c(t, i, ": Etall Nj6Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][973] = new TH1D(c(n, i, "_Etall_Nj6Nb2_OS"),              c(t, i, ": Etall Nj6Nb2 OS"),                          40, -4.0, 4.0);

                // Nj>=2 ---- ETA CONTROL -----------------------------------------
                histo[i][980] = new TH1D(c(n, i, "_Etall_NjGe2NbGe0_OS_CONTROL"),         c(t, i, ": Etall Nj2GeNbGe0 OS Control"),                     40, -4.0, 4.0);
                histo[i][981] = new TH1D(c(n, i, "_Etall_NjGe2Nb0_OS_CONTROL"),           c(t, i, ": Etall Nj2GeNb0 OS Control"),                       40, -4.0, 4.0);
                histo[i][982] = new TH1D(c(n, i, "_Etall_NjGe2Nb1_OS_CONTROL"),           c(t, i, ": Etall Nj2GeNb1 OS Control"),                       40, -4.0, 4.0);
                histo[i][983] = new TH1D(c(n, i, "_Etall_NjGe2NbGe2_OS_CONTROL"),         c(t, i, ": Etall Nj2GeNbGe2 OS Control"),                     40, -4.0, 4.0);
                // Nj=2
                histo[i][984] = new TH1D(c(n, i, "_Etall_Nj2Pre_OS_CONTROL"),              c(t, i, ": Etall Nj2Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][985] = new TH1D(c(n, i, "_Etall_Nj2Nb0_OS_CONTROL"),              c(t, i, ": Etall Nj2Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][986] = new TH1D(c(n, i, "_Etall_Nj2Nb1_OS_CONTROL"),              c(t, i, ": Etall Nj2Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][987] = new TH1D(c(n, i, "_Etall_Nj2Nb2_OS_CONTROL"),              c(t, i, ": Etall Nj2Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][988] = new TH1D(c(n, i, "_Etall_Nj3Pre_OS_CONTROL"),              c(t, i, ": Etall Nj3Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][989] = new TH1D(c(n, i, "_Etall_Nj3Nb0_OS_CONTROL"),              c(t, i, ": Etall Nj3Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][990] = new TH1D(c(n, i, "_Etall_Nj3Nb1_OS_CONTROL"),              c(t, i, ": Etall Nj3Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][991] = new TH1D(c(n, i, "_Etall_Nj3Nb2_OS_CONTROL"),              c(t, i, ": Etall Nj3Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][992] = new TH1D(c(n, i, "_Etall_Nj4Pre_OS_CONTROL"),              c(t, i, ": Etall Nj4Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][993] = new TH1D(c(n, i, "_Etall_Nj4Nb0_OS_CONTROL"),              c(t, i, ": Etall Nj4Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][994] = new TH1D(c(n, i, "_Etall_Nj4Nb1_OS_CONTROL"),              c(t, i, ": Etall Nj4Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][995] = new TH1D(c(n, i, "_Etall_Nj4Nb2_OS_CONTROL"),              c(t, i, ": Etall Nj4Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][996] = new TH1D(c(n, i, "_Etall_Nj5Pre_OS_CONTROL"),              c(t, i, ": Etall Nj5Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][997] = new TH1D(c(n, i, "_Etall_Nj5Nb0_OS_CONTROL"),              c(t, i, ": Etall Nj5Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][998] = new TH1D(c(n, i, "_Etall_Nj5Nb1_OS_CONTROL"),              c(t, i, ": Etall Nj5Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][999] = new TH1D(c(n, i, "_Etall_Nj5Nb2_OS_CONTROL"),              c(t, i, ": Etall Nj5Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][1000] = new TH1D(c(n, i, "_Etall_Nj6Pre_OS_CONTROL"),              c(t, i, ": Etall Nj6Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1001] = new TH1D(c(n, i, "_Etall_Nj6Nb0_OS_CONTROL"),              c(t, i, ": Etall Nj6Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1002] = new TH1D(c(n, i, "_Etall_Nj6Nb1_OS_CONTROL"),              c(t, i, ": Etall Nj6Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1003] = new TH1D(c(n, i, "_Etall_Nj6Nb2_OS_CONTROL"),              c(t, i, ": Etall Nj6Nb2 OS Control"),                          40, -4.0, 4.0);

                // Nj>=2 ---- PHI -----------------------------------------
                histo[i][1010] = new TH1D(c(n, i, "_Phill_NjGe2NbGe0_OS"),          c(t, i, ": Phill Nj2GeNbGe0 OS"),                     40, -4.0, 4.0);
                histo[i][1011] = new TH1D(c(n, i, "_Phill_NjGe2Nb0_OS"),            c(t, i, ": Phill Nj2GeNb0 OS"),                       40, -4.0, 4.0);
                histo[i][1012] = new TH1D(c(n, i, "_Phill_NjGe2Nb1_OS"),            c(t, i, ": Phill Nj2GeNb1 OS"),                       40, -4.0, 4.0);
                histo[i][1013] = new TH1D(c(n, i, "_Phill_NjGe2NbGe2_OS"),          c(t, i, ": Phill Nj2GeNbGe2 OS"),                     40, -4.0, 4.0);
                // Nj=2
                histo[i][1014] = new TH1D(c(n, i, "_Phill_Nj2Pre_OS"),              c(t, i, ": Phill Nj2Pre OS"),                          40, -4.0, 4.0);
                histo[i][1015] = new TH1D(c(n, i, "_Phill_Nj2Nb0_OS"),              c(t, i, ": Phill Nj2Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1016] = new TH1D(c(n, i, "_Phill_Nj2Nb1_OS"),              c(t, i, ": Phill Nj2Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1017] = new TH1D(c(n, i, "_Phill_Nj2Nb2_OS"),              c(t, i, ": Phill Nj2Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][1018] = new TH1D(c(n, i, "_Phill_Nj3Pre_OS"),              c(t, i, ": Phill Nj3Pre OS"),                          40, -4.0, 4.0);
                histo[i][1019] = new TH1D(c(n, i, "_Phill_Nj3Nb0_OS"),              c(t, i, ": Phill Nj3Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1020] = new TH1D(c(n, i, "_Phill_Nj3Nb1_OS"),              c(t, i, ": Phill Nj3Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1021] = new TH1D(c(n, i, "_Phill_Nj3Nb2_OS"),              c(t, i, ": Phill Nj3Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][1022] = new TH1D(c(n, i, "_Phill_Nj4Pre_OS"),              c(t, i, ": Phill Nj4Pre OS"),                          40, -4.0, 4.0);
                histo[i][1023] = new TH1D(c(n, i, "_Phill_Nj4Nb0_OS"),              c(t, i, ": Phill Nj4Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1024] = new TH1D(c(n, i, "_Phill_Nj4Nb1_OS"),              c(t, i, ": Phill Nj4Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1025] = new TH1D(c(n, i, "_Phill_Nj4Nb2_OS"),              c(t, i, ": Phill Nj4Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][1026] = new TH1D(c(n, i, "_Phill_Nj5Pre_OS"),              c(t, i, ": Phill Nj5Pre OS"),                          40, -4.0, 4.0);
                histo[i][1027] = new TH1D(c(n, i, "_Phill_Nj5Nb0_OS"),              c(t, i, ": Phill Nj5Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1028] = new TH1D(c(n, i, "_Phill_Nj5Nb1_OS"),              c(t, i, ": Phill Nj5Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1029] = new TH1D(c(n, i, "_Phill_Nj5Nb2_OS"),              c(t, i, ": Phill Nj5Nb2 OS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][1030] = new TH1D(c(n, i, "_Phill_Nj6Pre_OS"),              c(t, i, ": Phill Nj6Pre OS"),                          40, -4.0, 4.0);
                histo[i][1031] = new TH1D(c(n, i, "_Phill_Nj6Nb0_OS"),              c(t, i, ": Phill Nj6Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1032] = new TH1D(c(n, i, "_Phill_Nj6Nb1_OS"),              c(t, i, ": Phill Nj6Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1033] = new TH1D(c(n, i, "_Phill_Nj6Nb2_OS"),              c(t, i, ": Phill Nj6Nb2 OS"),                          40, -4.0, 4.0);

                // Nj>=2 ---- Phi CONTROL -----------------------------------------
                histo[i][1040] = new TH1D(c(n, i, "_Phill_NjGe2NbGe0_OS_CONTROL"),          c(t, i, ": Phill Nj2GeNbGe0 OS Control"),                      40, -4.0, 4.0);
                histo[i][1041] = new TH1D(c(n, i, "_Phill_NjGe2Nb0_OS_CONTROL"),            c(t, i, ": Phill Nj2GeNb0 OS Control"),                        40, -4.0, 4.0);
                histo[i][1042] = new TH1D(c(n, i, "_Phill_NjGe2Nb1_OS_CONTROL"),            c(t, i, ": Phill Nj2GeNb1 OS Control"),                        40, -4.0, 4.0);
                histo[i][1043] = new TH1D(c(n, i, "_Phill_NjGe2NbGe2_OS_CONTROL"),          c(t, i, ": Phill Nj2GeNbGe2 OS Control"),                      40, -4.0, 4.0);
                // Nj=2
                histo[i][1044] = new TH1D(c(n, i, "_Phill_Nj2Pre_OS_CONTROL"),              c(t, i, ": Phill Nj2Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1045] = new TH1D(c(n, i, "_Phill_Nj2Nb0_OS_CONTROL"),              c(t, i, ": Phill Nj2Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1046] = new TH1D(c(n, i, "_Phill_Nj2Nb1_OS_CONTROL"),              c(t, i, ": Phill Nj2Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1047] = new TH1D(c(n, i, "_Phill_Nj2Nb2_OS_CONTROL"),              c(t, i, ": Phill Nj2Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][1048] = new TH1D(c(n, i, "_Phill_Nj3Pre_OS_CONTROL"),              c(t, i, ": Phill Nj3Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1049] = new TH1D(c(n, i, "_Phill_Nj3Nb0_OS_CONTROL"),              c(t, i, ": Phill Nj3Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1050] = new TH1D(c(n, i, "_Phill_Nj3Nb1_OS_CONTROL"),              c(t, i, ": Phill Nj3Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1051] = new TH1D(c(n, i, "_Phill_Nj3Nb2_OS_CONTROL"),              c(t, i, ": Phill Nj3Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][1052] = new TH1D(c(n, i, "_Phill_Nj4Pre_OS_CONTROL"),              c(t, i, ": Phill Nj4Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1053] = new TH1D(c(n, i, "_Phill_Nj4Nb0_OS_CONTROL"),              c(t, i, ": Phill Nj4Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1054] = new TH1D(c(n, i, "_Phill_Nj4Nb1_OS_CONTROL"),              c(t, i, ": Phill Nj4Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1055] = new TH1D(c(n, i, "_Phill_Nj4Nb2_OS_CONTROL"),              c(t, i, ": Phill Nj4Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][1056] = new TH1D(c(n, i, "_Phill_Nj5Pre_OS_CONTROL"),              c(t, i, ": Phill Nj5Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1057] = new TH1D(c(n, i, "_Phill_Nj5Nb0_OS_CONTROL"),              c(t, i, ": Phill Nj5Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1058] = new TH1D(c(n, i, "_Phill_Nj5Nb1_OS_CONTROL"),              c(t, i, ": Phill Nj5Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1059] = new TH1D(c(n, i, "_Phill_Nj5Nb2_OS_CONTROL"),              c(t, i, ": Phill Nj5Nb2 OS Control"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][1060] = new TH1D(c(n, i, "_Phill_Nj6Pre_OS_CONTROL"),              c(t, i, ": Phill Nj6Pre OS Control"),                          40, -4.0, 4.0);
                histo[i][1061] = new TH1D(c(n, i, "_Phill_Nj6Nb0_OS_CONTROL"),              c(t, i, ": Phill Nj6Nb0 OS Control"),                          40, -4.0, 4.0);
                histo[i][1062] = new TH1D(c(n, i, "_Phill_Nj6Nb1_OS_CONTROL"),              c(t, i, ": Phill Nj6Nb1 OS Control"),                          40, -4.0, 4.0);
                histo[i][1063] = new TH1D(c(n, i, "_Phill_Nj6Nb2_OS_CONTROL"),              c(t, i, ": Phill Nj6Nb2 OS Control"),                          40, -4.0, 4.0);

		// ================= SS Distributions =========================
                //.........Mll versus Etmis Z DD SS ...........................
                // Nj>=2 
                histo[i][400+800] = new TH2D( c(n,i,"_XMll_YMET_NjGe2NbGe0_SS"), c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2NbGe0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+801] = new TH2D( c(n,i,"_XMll_YMET_NjGe2Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2Nb0 SS"),     130,  0.,  260.,  100, 0., 200. );
                histo[i][400+802] = new TH2D( c(n,i,"_XMll_YMET_NjGe2Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2Nb1 SS"),     130,  0.,  260.,  100, 0., 200. );
                histo[i][400+803] = new TH2D( c(n,i,"_XMll_YMET_NjGe2NbGe2_SS"), c(t,i,": x=Mll [GeV] y=MET [GeV] NjGe2NbGe2 SS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=2 
                histo[i][400+804] = new TH2D( c(n,i,"_XMll_YMET_Nj2Pre_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Pre SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+805] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+806] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb1 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+807] = new TH2D( c(n,i,"_XMll_YMET_Nj2Nb2_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj2Nb2 SS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=3
                histo[i][400+808] = new TH2D( c(n,i,"_XMll_YMET_Nj3Pre_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Pre SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+809] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+810] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb1 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+811] = new TH2D( c(n,i,"_XMll_YMET_Nj3Nb2_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj3Nb2 SS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=4
                histo[i][400+812] = new TH2D( c(n,i,"_XMll_YMET_Nj4Pre_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Pre SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+813] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+814] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb1 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+815] = new TH2D( c(n,i,"_XMll_YMET_Nj4Nb2_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj4Nb2 SS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj=5
                histo[i][400+816] = new TH2D( c(n,i,"_XMll_YMET_Nj5Pre_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Pre SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+817] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+818] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb1 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+819] = new TH2D( c(n,i,"_XMll_YMET_Nj5Nb2_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj5Nb2 SS"),   130,  0.,  260.,  100, 0., 200. );
                // Nj>=6
                histo[i][400+820] = new TH2D( c(n,i,"_XMll_YMET_Nj6Pre_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Pre SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+821] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb0_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb0 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+822] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb1_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb1 SS"),   130,  0.,  260.,  100, 0., 200. );
                histo[i][400+823] = new TH2D( c(n,i,"_XMll_YMET_Nj6Nb2_SS"),   c(t,i,": x=Mll [GeV] y=MET [GeV] Nj6Nb2 SS"),   130,  0.,  260.,  100, 0., 200. );

                // Nj>=2 Nb0>=0 Counters --------------------------------------
                histo[i][400+830] = new TH1D(c(n, i, "_ZjetsDD_NjGe2NbGe0_SS"),      c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe0 SS"),  10, -0.5,  9.5  );
                histo[i][400+831] = new TH1D(c(n, i, "_ZjetsDD_NjGe2Nb0_SS"),        c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb0 SS"),    10, -0.5,  9.5  );
                histo[i][400+832] = new TH1D(c(n, i, "_ZjetsDD_NjGe2Nb1_SS"),        c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb1 SS"),    10, -0.5,  9.5  );
                histo[i][400+833] = new TH1D(c(n, i, "_ZjetsDD_NjGe2NbGe2_SS"),      c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe2 SS"),  10, -0.5,  9.5  );
                // Nj=2 Counters
                histo[i][400+834] = new TH1D(c(n, i, "_ZjetsDD_Nj2Pre_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+835] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb0_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+836] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb1_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+837] = new TH1D(c(n, i, "_ZjetsDD_Nj2Nb2_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj2Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=3 Counters
                histo[i][400+838] = new TH1D(c(n, i, "_ZjetsDD_Nj3Pre_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+839] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb0_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+840] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb1_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+841] = new TH1D(c(n, i, "_ZjetsDD_Nj3Nb2_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj3Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=4 Counters
                histo[i][400+842] = new TH1D(c(n, i, "_ZjetsDD_Nj4Pre_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+843] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb0_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+844] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb1_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+845] = new TH1D(c(n, i, "_ZjetsDD_Nj4Nb2_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj4Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=5 Counters
                histo[i][400+846] = new TH1D(c(n, i, "_ZjetsDD_Nj5Pre_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+847] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb0_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+848] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb1_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+849] = new TH1D(c(n, i, "_ZjetsDD_Nj5Nb2_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj5Nb2 SS"),     10, -0.5,  9.5  );
                // Nj>=6 Counters
                histo[i][400+850] = new TH1D(c(n, i, "_ZjetsDD_Nj6Pre_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+851] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb0_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+852] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb1_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+853] = new TH1D(c(n, i, "_ZjetsDD_Nj6Nb2_SS"),          c(t, i, ": ZjetsDD 1=SR, 2=CR, 3=SR Nj6Nb2 SS"),     10, -0.5,  9.5  );

                //Nj>=2 btag>=0 ----------------------------------------------
                histo[i][400+860] = new TH1D(c(n, i, "_Mll_NjGe2NbGe0_SS"),          c(t, i, ": Mll Nj2GeNbGe0 SS"),                      bM,    lM, hM    );
                histo[i][400+861] = new TH1D(c(n, i, "_Mll_NjGe2Nb0_SS"),            c(t, i, ": Mll Nj2GeNb0 SS"),                        bM,    lM, hM    );
                histo[i][400+862] = new TH1D(c(n, i, "_Mll_NjGe2Nb1_SS"),            c(t, i, ": Mll Nj2GeNb1 SS"),                        bM,    lM, hM    );
                histo[i][400+863] = new TH1D(c(n, i, "_Mll_NjGe2NbGe2_SS"),          c(t, i, ": Mll Nj2GeNbGe2 SS"),                      bM,    lM, hM    );
                // Nj=2 
                histo[i][400+864] = new TH1D(c(n, i, "_Mll_Nj2Pre_SS"),              c(t, i, ": Mll Nj2Pre SS"),                          bM,    lM, hM    );
                histo[i][400+865] = new TH1D(c(n, i, "_Mll_Nj2Nb0_SS"),              c(t, i, ": Mll Nj2Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+866] = new TH1D(c(n, i, "_Mll_Nj2Nb1_SS"),              c(t, i, ": Mll Nj2Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+867] = new TH1D(c(n, i, "_Mll_Nj2Nb2_SS"),              c(t, i, ": Mll Nj2Nb2 SS"),                          bM,    lM, hM    );
                // Nj=3
                histo[i][400+868] = new TH1D(c(n, i, "_Mll_Nj3Pre_SS"),              c(t, i, ": Mll Nj3Pre SS"),                          bM,    lM, hM    );
                histo[i][400+869] = new TH1D(c(n, i, "_Mll_Nj3Nb0_SS"),              c(t, i, ": Mll Nj3Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+870] = new TH1D(c(n, i, "_Mll_Nj3Nb1_SS"),              c(t, i, ": Mll Nj3Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+871] = new TH1D(c(n, i, "_Mll_Nj3Nb2_SS"),              c(t, i, ": Mll Nj3Nb2 SS"),                          bM,    lM, hM    );
                // Nj=4
                histo[i][400+872] = new TH1D(c(n, i, "_Mll_Nj4Pre_SS"),              c(t, i, ": Mll Nj4Pre SS"),                          bM,    lM, hM    );
                histo[i][400+873] = new TH1D(c(n, i, "_Mll_Nj4Nb0_SS"),              c(t, i, ": Mll Nj4Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+874] = new TH1D(c(n, i, "_Mll_Nj4Nb1_SS"),              c(t, i, ": Mll Nj4Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+875] = new TH1D(c(n, i, "_Mll_Nj4Nb2_SS"),              c(t, i, ": Mll Nj4Nb2 SS"),                          bM,    lM, hM    );
                // Nj=5
                histo[i][400+876] = new TH1D(c(n, i, "_Mll_Nj5Pre_SS"),              c(t, i, ": Mll Nj5Pre SS"),                          bM,    lM, hM    );
                histo[i][400+877] = new TH1D(c(n, i, "_Mll_Nj5Nb0_SS"),              c(t, i, ": Mll Nj5Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+878] = new TH1D(c(n, i, "_Mll_Nj5Nb1_SS"),              c(t, i, ": Mll Nj5Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+879] = new TH1D(c(n, i, "_Mll_Nj5Nb2_SS"),              c(t, i, ": Mll Nj5Nb2 SS"),                          bM,    lM, hM    );
                // Nj>=6
                histo[i][400+880] = new TH1D(c(n, i, "_Mll_Nj6Pre_SS"),              c(t, i, ": Mll Nj6Pre SS"),                          bM,    lM, hM    );
                histo[i][400+881] = new TH1D(c(n, i, "_Mll_Nj6Nb0_SS"),              c(t, i, ": Mll Nj6Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+882] = new TH1D(c(n, i, "_Mll_Nj6Nb1_SS"),              c(t, i, ": Mll Nj6Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+883] = new TH1D(c(n, i, "_Mll_Nj6Nb2_SS"),              c(t, i, ": Mll Nj6Nb2 SS"),                          bM,    lM, hM    );

                //Nj>=2 btag>=0 ---- PT -----------------------------------------
                histo[i][400+890] = new TH1D(c(n, i, "_PTll_NjGe2NbGe0_SS"),          c(t, i, ": PTll Nj2GeNbGe0 SS"),                      bPt,    lPt, hPt    );
                histo[i][400+891] = new TH1D(c(n, i, "_PTll_NjGe2Nb0_SS"),            c(t, i, ": PTll Nj2GeNb0 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+892] = new TH1D(c(n, i, "_PTll_NjGe2Nb1_SS"),            c(t, i, ": PTll Nj2GeNb1 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+893] = new TH1D(c(n, i, "_PTll_NjGe2NbGe2_SS"),          c(t, i, ": PTll Nj2GeNbGe2 SS"),                      bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+894] = new TH1D(c(n, i, "_PTll_Nj2Pre_SS"),              c(t, i, ": PTll Nj2Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+895] = new TH1D(c(n, i, "_PTll_Nj2Nb0_SS"),              c(t, i, ": PTll Nj2Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+896] = new TH1D(c(n, i, "_PTll_Nj2Nb1_SS"),              c(t, i, ": PTll Nj2Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+897] = new TH1D(c(n, i, "_PTll_Nj2Nb2_SS"),              c(t, i, ": PTll Nj2Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+898] = new TH1D(c(n, i, "_PTll_Nj3Pre_SS"),              c(t, i, ": PTll Nj3Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+899] = new TH1D(c(n, i, "_PTll_Nj3Nb0_SS"),              c(t, i, ": PTll Nj3Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+900] = new TH1D(c(n, i, "_PTll_Nj3Nb1_SS"),              c(t, i, ": PTll Nj3Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+901] = new TH1D(c(n, i, "_PTll_Nj3Nb2_SS"),              c(t, i, ": PTll Nj3Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+902] = new TH1D(c(n, i, "_PTll_Nj4Pre_SS"),              c(t, i, ": PTll Nj4Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+903] = new TH1D(c(n, i, "_PTll_Nj4Nb0_SS"),              c(t, i, ": PTll Nj4Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+904] = new TH1D(c(n, i, "_PTll_Nj4Nb1_SS"),              c(t, i, ": PTll Nj4Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+905] = new TH1D(c(n, i, "_PTll_Nj4Nb2_SS"),              c(t, i, ": PTll Nj4Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+906] = new TH1D(c(n, i, "_PTll_Nj5Pre_SS"),              c(t, i, ": PTll Nj5Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+907] = new TH1D(c(n, i, "_PTll_Nj5Nb0_SS"),              c(t, i, ": PTll Nj5Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+908] = new TH1D(c(n, i, "_PTll_Nj5Nb1_SS"),              c(t, i, ": PTll Nj5Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+909] = new TH1D(c(n, i, "_PTll_Nj5Nb2_SS"),              c(t, i, ": PTll Nj5Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+910] = new TH1D(c(n, i, "_PTll_Nj6Pre_SS"),              c(t, i, ": PTll Nj6Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+911] = new TH1D(c(n, i, "_PTll_Nj6Nb0_SS"),              c(t, i, ": PTll Nj6Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+912] = new TH1D(c(n, i, "_PTll_Nj6Nb1_SS"),              c(t, i, ": PTll Nj6Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+913] = new TH1D(c(n, i, "_PTll_Nj6Nb2_SS"),              c(t, i, ": PTll Nj6Nb2 SS"),                          bPt,    lPt, hPt    );

                // Nj>=2 ---- PT -------------CONTROL---------------------
                histo[i][400+920] = new TH1D(c(n, i, "_PTll_NjGe2NbGe0_SS_CONTROL"),          c(t, i, ": PTll Nj2GeNbGe0 SS Control"),                      bPt,    lPt, hPt    );
                histo[i][400+921] = new TH1D(c(n, i, "_PTll_NjGe2Nb0_SS_CONTROL"),            c(t, i, ": PTll Nj2GeNb0 SS Control"),                        bPt,    lPt, hPt    );
                histo[i][400+922] = new TH1D(c(n, i, "_PTll_NjGe2Nb1_SS_CONTROL"),            c(t, i, ": PTll Nj2GeNb1 SS Control"),                        bPt,    lPt, hPt    );
                histo[i][400+923] = new TH1D(c(n, i, "_PTll_NjGe2NbGe2_SS_CONTROL"),          c(t, i, ": PTll Nj2GeNbGe2 SS Control"),                      bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+924] = new TH1D(c(n, i, "_PTll_Nj2Pre_SS_CONTROL"),              c(t, i, ": PTll Nj2Pre SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+925] = new TH1D(c(n, i, "_PTll_Nj2Nb0_SS_CONTROL"),              c(t, i, ": PTll Nj2Nb0 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+926] = new TH1D(c(n, i, "_PTll_Nj2Nb1_SS_CONTROL"),              c(t, i, ": PTll Nj2Nb1 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+927] = new TH1D(c(n, i, "_PTll_Nj2Nb2_SS_CONTROL"),              c(t, i, ": PTll Nj2Nb2 SS Control"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+928] = new TH1D(c(n, i, "_PTll_Nj3Pre_SS_CONTROL"),              c(t, i, ": PTll Nj3Pre SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+929] = new TH1D(c(n, i, "_PTll_Nj3Nb0_SS_CONTROL"),              c(t, i, ": PTll Nj3Nb0 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+930] = new TH1D(c(n, i, "_PTll_Nj3Nb1_SS_CONTROL"),              c(t, i, ": PTll Nj3Nb1 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+931] = new TH1D(c(n, i, "_PTll_Nj3Nb2_SS_CONTROL"),              c(t, i, ": PTll Nj3Nb2 SS Control"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+932] = new TH1D(c(n, i, "_PTll_Nj4Pre_SS_CONTROL"),              c(t, i, ": PTll Nj4Pre SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+933] = new TH1D(c(n, i, "_PTll_Nj4Nb0_SS_CONTROL"),              c(t, i, ": PTll Nj4Nb0 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+934] = new TH1D(c(n, i, "_PTll_Nj4Nb1_SS_CONTROL"),              c(t, i, ": PTll Nj4Nb1 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+935] = new TH1D(c(n, i, "_PTll_Nj4Nb2_SS_CONTROL"),              c(t, i, ": PTll Nj4Nb2 SS Control"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+936] = new TH1D(c(n, i, "_PTll_Nj5Pre_SS_CONTROL"),              c(t, i, ": PTll Nj5Pre SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+937] = new TH1D(c(n, i, "_PTll_Nj5Nb0_SS_CONTROL"),              c(t, i, ": PTll Nj5Nb0 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+938] = new TH1D(c(n, i, "_PTll_Nj5Nb1_SS_CONTROL"),              c(t, i, ": PTll Nj5Nb1 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+939] = new TH1D(c(n, i, "_PTll_Nj5Nb2_SS_CONTROL"),              c(t, i, ": PTll Nj5Nb2 SS Control"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+940] = new TH1D(c(n, i, "_PTll_Nj6Pre_SS_CONTROL"),              c(t, i, ": PTll Nj6Pre SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+941] = new TH1D(c(n, i, "_PTll_Nj6Nb0_SS_CONTROL"),              c(t, i, ": PTll Nj6Nb0 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+942] = new TH1D(c(n, i, "_PTll_Nj6Nb1_SS_CONTROL"),              c(t, i, ": PTll Nj6Nb1 SS Control"),                          bPt,    lPt, hPt    );
                histo[i][400+943] = new TH1D(c(n, i, "_PTll_Nj6Nb2_SS_CONTROL"),              c(t, i, ": PTll Nj6Nb2 SS Control"),                          bPt,    lPt, hPt    );

                // Nj>=2 ---- ETA -----------------------------------------
                histo[i][400+950] = new TH1D(c(n, i, "_Etall_NjGe2NbGe0_SS"),          c(t, i, ": Etall Nj2GeNbGe0 SS"),                     40, -4.0, 4.0);
                histo[i][400+951] = new TH1D(c(n, i, "_Etall_NjGe2Nb0_SS"),            c(t, i, ": Etall Nj2GeNb0 SS"),                       40, -4.0, 4.0);
                histo[i][400+952] = new TH1D(c(n, i, "_Etall_NjGe2Nb1_SS"),            c(t, i, ": Etall Nj2GeNb1 SS"),                       40, -4.0, 4.0);
                histo[i][400+953] = new TH1D(c(n, i, "_Etall_NjGe2NbGe2_SS"),          c(t, i, ": Etall Nj2GeNbGe2 SS"),                     40, -4.0, 4.0);
                // Nj=2 
                histo[i][400+954] = new TH1D(c(n, i, "_Etall_Nj2Pre_SS"),              c(t, i, ": Etall Nj2Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+955] = new TH1D(c(n, i, "_Etall_Nj2Nb0_SS"),              c(t, i, ": Etall Nj2Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+956] = new TH1D(c(n, i, "_Etall_Nj2Nb1_SS"),              c(t, i, ": Etall Nj2Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+957] = new TH1D(c(n, i, "_Etall_Nj2Nb2_SS"),              c(t, i, ": Etall Nj2Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+958] = new TH1D(c(n, i, "_Etall_Nj3Pre_SS"),              c(t, i, ": Etall Nj3Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+959] = new TH1D(c(n, i, "_Etall_Nj3Nb0_SS"),              c(t, i, ": Etall Nj3Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+960] = new TH1D(c(n, i, "_Etall_Nj3Nb1_SS"),              c(t, i, ": Etall Nj3Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+961] = new TH1D(c(n, i, "_Etall_Nj3Nb2_SS"),              c(t, i, ": Etall Nj3Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+962] = new TH1D(c(n, i, "_Etall_Nj4Pre_SS"),              c(t, i, ": Etall Nj4Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+963] = new TH1D(c(n, i, "_Etall_Nj4Nb0_SS"),              c(t, i, ": Etall Nj4Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+964] = new TH1D(c(n, i, "_Etall_Nj4Nb1_SS"),              c(t, i, ": Etall Nj4Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+965] = new TH1D(c(n, i, "_Etall_Nj4Nb2_SS"),              c(t, i, ": Etall Nj4Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+966] = new TH1D(c(n, i, "_Etall_Nj5Pre_SS"),              c(t, i, ": Etall Nj5Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+967] = new TH1D(c(n, i, "_Etall_Nj5Nb0_SS"),              c(t, i, ": Etall Nj5Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+968] = new TH1D(c(n, i, "_Etall_Nj5Nb1_SS"),              c(t, i, ": Etall Nj5Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+969] = new TH1D(c(n, i, "_Etall_Nj5Nb2_SS"),              c(t, i, ": Etall Nj5Nb2 SS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+970] = new TH1D(c(n, i, "_Etall_Nj6Pre_SS"),              c(t, i, ": Etall Nj6Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+971] = new TH1D(c(n, i, "_Etall_Nj6Nb0_SS"),              c(t, i, ": Etall Nj6Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+972] = new TH1D(c(n, i, "_Etall_Nj6Nb1_SS"),              c(t, i, ": Etall Nj6Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+973] = new TH1D(c(n, i, "_Etall_Nj6Nb2_SS"),              c(t, i, ": Etall Nj6Nb2 SS"),                          40, -4.0, 4.0);

                // Nj>=2 ---- ETA CONTROL -----------------------------------------
                histo[i][400+980] = new TH1D(c(n, i, "_Etall_NjGe2NbGe0_SS_CONTROL"),         c(t, i, ": Etall Nj2GeNbGe0 SS Control"),                     40, -4.0, 4.0);
                histo[i][400+981] = new TH1D(c(n, i, "_Etall_NjGe2Nb0_SS_CONTROL"),           c(t, i, ": Etall Nj2GeNb0 SS Control"),                       40, -4.0, 4.0);
                histo[i][400+982] = new TH1D(c(n, i, "_Etall_NjGe2Nb1_SS_CONTROL"),           c(t, i, ": Etall Nj2GeNb1 SS Control"),                       40, -4.0, 4.0);
                histo[i][400+983] = new TH1D(c(n, i, "_Etall_NjGe2NbGe2_SS_CONTROL"),         c(t, i, ": Etall Nj2GeNbGe2 SS Control"),                     40, -4.0, 4.0);
                // Nj=2
                histo[i][400+984] = new TH1D(c(n, i, "_Etall_Nj2Pre_SS_CONTROL"),              c(t, i, ": Etall Nj2Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+985] = new TH1D(c(n, i, "_Etall_Nj2Nb0_SS_CONTROL"),              c(t, i, ": Etall Nj2Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+986] = new TH1D(c(n, i, "_Etall_Nj2Nb1_SS_CONTROL"),              c(t, i, ": Etall Nj2Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+987] = new TH1D(c(n, i, "_Etall_Nj2Nb2_SS_CONTROL"),              c(t, i, ": Etall Nj2Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+988] = new TH1D(c(n, i, "_Etall_Nj3Pre_SS_CONTROL"),              c(t, i, ": Etall Nj3Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+989] = new TH1D(c(n, i, "_Etall_Nj3Nb0_SS_CONTROL"),              c(t, i, ": Etall Nj3Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+990] = new TH1D(c(n, i, "_Etall_Nj3Nb1_SS_CONTROL"),              c(t, i, ": Etall Nj3Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+991] = new TH1D(c(n, i, "_Etall_Nj3Nb2_SS_CONTROL"),              c(t, i, ": Etall Nj3Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+992] = new TH1D(c(n, i, "_Etall_Nj4Pre_SS_CONTROL"),              c(t, i, ": Etall Nj4Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+993] = new TH1D(c(n, i, "_Etall_Nj4Nb0_SS_CONTROL"),              c(t, i, ": Etall Nj4Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+994] = new TH1D(c(n, i, "_Etall_Nj4Nb1_SS_CONTROL"),              c(t, i, ": Etall Nj4Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+995] = new TH1D(c(n, i, "_Etall_Nj4Nb2_SS_CONTROL"),              c(t, i, ": Etall Nj4Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+996] = new TH1D(c(n, i, "_Etall_Nj5Pre_SS_CONTROL"),              c(t, i, ": Etall Nj5Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+997] = new TH1D(c(n, i, "_Etall_Nj5Nb0_SS_CONTROL"),              c(t, i, ": Etall Nj5Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+998] = new TH1D(c(n, i, "_Etall_Nj5Nb1_SS_CONTROL"),              c(t, i, ": Etall Nj5Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+999] = new TH1D(c(n, i, "_Etall_Nj5Nb2_SS_CONTROL"),              c(t, i, ": Etall Nj5Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+1000] = new TH1D(c(n, i, "_Etall_Nj6Pre_SS_CONTROL"),              c(t, i, ": Etall Nj6Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1001] = new TH1D(c(n, i, "_Etall_Nj6Nb0_SS_CONTROL"),              c(t, i, ": Etall Nj6Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1002] = new TH1D(c(n, i, "_Etall_Nj6Nb1_SS_CONTROL"),              c(t, i, ": Etall Nj6Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1003] = new TH1D(c(n, i, "_Etall_Nj6Nb2_SS_CONTROL"),              c(t, i, ": Etall Nj6Nb2 SS Control"),                          40, -4.0, 4.0);

                // Nj>=2 ---- PHI -----------------------------------------
                histo[i][400+1010] = new TH1D(c(n, i, "_Phill_NjGe2NbGe0_SS"),          c(t, i, ": Phill Nj2GeNbGe0 SS"),                     40, -4.0, 4.0);
                histo[i][400+1011] = new TH1D(c(n, i, "_Phill_NjGe2Nb0_SS"),            c(t, i, ": Phill Nj2GeNb0 SS"),                       40, -4.0, 4.0);
                histo[i][400+1012] = new TH1D(c(n, i, "_Phill_NjGe2Nb1_SS"),            c(t, i, ": Phill Nj2GeNb1 SS"),                       40, -4.0, 4.0);
                histo[i][400+1013] = new TH1D(c(n, i, "_Phill_NjGe2NbGe2_SS"),          c(t, i, ": Phill Nj2GeNbGe2 SS"),                     40, -4.0, 4.0);
                // Nj=2
                histo[i][400+1014] = new TH1D(c(n, i, "_Phill_Nj2Pre_SS"),              c(t, i, ": Phill Nj2Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1015] = new TH1D(c(n, i, "_Phill_Nj2Nb0_SS"),              c(t, i, ": Phill Nj2Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1016] = new TH1D(c(n, i, "_Phill_Nj2Nb1_SS"),              c(t, i, ": Phill Nj2Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1017] = new TH1D(c(n, i, "_Phill_Nj2Nb2_SS"),              c(t, i, ": Phill Nj2Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+1018] = new TH1D(c(n, i, "_Phill_Nj3Pre_SS"),              c(t, i, ": Phill Nj3Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1019] = new TH1D(c(n, i, "_Phill_Nj3Nb0_SS"),              c(t, i, ": Phill Nj3Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1020] = new TH1D(c(n, i, "_Phill_Nj3Nb1_SS"),              c(t, i, ": Phill Nj3Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1021] = new TH1D(c(n, i, "_Phill_Nj3Nb2_SS"),              c(t, i, ": Phill Nj3Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+1022] = new TH1D(c(n, i, "_Phill_Nj4Pre_SS"),              c(t, i, ": Phill Nj4Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1023] = new TH1D(c(n, i, "_Phill_Nj4Nb0_SS"),              c(t, i, ": Phill Nj4Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1024] = new TH1D(c(n, i, "_Phill_Nj4Nb1_SS"),              c(t, i, ": Phill Nj4Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1025] = new TH1D(c(n, i, "_Phill_Nj4Nb2_SS"),              c(t, i, ": Phill Nj4Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+1026] = new TH1D(c(n, i, "_Phill_Nj5Pre_SS"),              c(t, i, ": Phill Nj5Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1027] = new TH1D(c(n, i, "_Phill_Nj5Nb0_SS"),              c(t, i, ": Phill Nj5Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1028] = new TH1D(c(n, i, "_Phill_Nj5Nb1_SS"),              c(t, i, ": Phill Nj5Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1029] = new TH1D(c(n, i, "_Phill_Nj5Nb2_SS"),              c(t, i, ": Phill Nj5Nb2 SS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+1030] = new TH1D(c(n, i, "_Phill_Nj6Pre_SS"),              c(t, i, ": Phill Nj6Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1031] = new TH1D(c(n, i, "_Phill_Nj6Nb0_SS"),              c(t, i, ": Phill Nj6Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1032] = new TH1D(c(n, i, "_Phill_Nj6Nb1_SS"),              c(t, i, ": Phill Nj6Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1033] = new TH1D(c(n, i, "_Phill_Nj6Nb2_SS"),              c(t, i, ": Phill Nj6Nb2 SS"),                          40, -4.0, 4.0);

                // Nj>=2 ---- Phi CONTROL -----------------------------------------
                histo[i][400+1040] = new TH1D(c(n, i, "_Phill_NjGe2NbGe0_SS_CONTROL"),          c(t, i, ": Phill Nj2GeNbGe0 SS Control"),                      40, -4.0, 4.0);
                histo[i][400+1041] = new TH1D(c(n, i, "_Phill_NjGe2Nb0_SS_CONTROL"),            c(t, i, ": Phill Nj2GeNb0 SS Control"),                        40, -4.0, 4.0);
                histo[i][400+1042] = new TH1D(c(n, i, "_Phill_NjGe2Nb1_SS_CONTROL"),            c(t, i, ": Phill Nj2GeNb1 SS Control"),                        40, -4.0, 4.0);
                histo[i][400+1043] = new TH1D(c(n, i, "_Phill_NjGe2NbGe2_SS_CONTROL"),          c(t, i, ": Phill Nj2GeNbGe2 SS Control"),                      40, -4.0, 4.0);
                // Nj=2
                histo[i][400+1044] = new TH1D(c(n, i, "_Phill_Nj2Pre_SS_CONTROL"),              c(t, i, ": Phill Nj2Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1045] = new TH1D(c(n, i, "_Phill_Nj2Nb0_SS_CONTROL"),              c(t, i, ": Phill Nj2Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1046] = new TH1D(c(n, i, "_Phill_Nj2Nb1_SS_CONTROL"),              c(t, i, ": Phill Nj2Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1047] = new TH1D(c(n, i, "_Phill_Nj2Nb2_SS_CONTROL"),              c(t, i, ": Phill Nj2Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+1048] = new TH1D(c(n, i, "_Phill_Nj3Pre_SS_CONTROL"),              c(t, i, ": Phill Nj3Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1049] = new TH1D(c(n, i, "_Phill_Nj3Nb0_SS_CONTROL"),              c(t, i, ": Phill Nj3Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1050] = new TH1D(c(n, i, "_Phill_Nj3Nb1_SS_CONTROL"),              c(t, i, ": Phill Nj3Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1051] = new TH1D(c(n, i, "_Phill_Nj3Nb2_SS_CONTROL"),              c(t, i, ": Phill Nj3Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+1052] = new TH1D(c(n, i, "_Phill_Nj4Pre_SS_CONTROL"),              c(t, i, ": Phill Nj4Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1053] = new TH1D(c(n, i, "_Phill_Nj4Nb0_SS_CONTROL"),              c(t, i, ": Phill Nj4Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1054] = new TH1D(c(n, i, "_Phill_Nj4Nb1_SS_CONTROL"),              c(t, i, ": Phill Nj4Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1055] = new TH1D(c(n, i, "_Phill_Nj4Nb2_SS_CONTROL"),              c(t, i, ": Phill Nj4Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+1056] = new TH1D(c(n, i, "_Phill_Nj5Pre_SS_CONTROL"),              c(t, i, ": Phill Nj5Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1057] = new TH1D(c(n, i, "_Phill_Nj5Nb0_SS_CONTROL"),              c(t, i, ": Phill Nj5Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1058] = new TH1D(c(n, i, "_Phill_Nj5Nb1_SS_CONTROL"),              c(t, i, ": Phill Nj5Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1059] = new TH1D(c(n, i, "_Phill_Nj5Nb2_SS_CONTROL"),              c(t, i, ": Phill Nj5Nb2 SS Control"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+1060] = new TH1D(c(n, i, "_Phill_Nj6Pre_SS_CONTROL"),              c(t, i, ": Phill Nj6Pre SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1061] = new TH1D(c(n, i, "_Phill_Nj6Nb0_SS_CONTROL"),              c(t, i, ": Phill Nj6Nb0 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1062] = new TH1D(c(n, i, "_Phill_Nj6Nb1_SS_CONTROL"),              c(t, i, ": Phill Nj6Nb1 SS Control"),                          40, -4.0, 4.0);
                histo[i][400+1063] = new TH1D(c(n, i, "_Phill_Nj6Nb2_SS_CONTROL"),              c(t, i, ": Phill Nj6Nb2 SS Control"),                          40, -4.0, 4.0);

                //
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                // ::                                        Additional Histograms for ttbar Data Driven Methods                                ::
                // ::                                                from   1800  OS                                                            ::
                // ::                                                from   2200 SS                                                             ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ================= OS Distributions =========================
                // Nj>=2 Nb0>=0 Average pT(l+l-) ------------------------------
                histo[i][1800] = new TH1D(c(n, i, "_AvPTll_NjGe2NbGe0_OS"),          c(t, i, ": AvPTll Nj2GeNbGe0 OS"),                      bPt,    lPt, hPt    );
                histo[i][1801] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb0_OS"),            c(t, i, ": AvPTll Nj2GeNb0 OS"),                        bPt,    lPt, hPt    );
                histo[i][1802] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb1_OS"),            c(t, i, ": AvPTll Nj2GeNb1 OS"),                        bPt,    lPt, hPt    );
                histo[i][1803] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb2_OS"),            c(t, i, ": AvPTll Nj2GeNb2 OS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][1804] = new TH1D(c(n, i, "_AvPTll_Nj2Pre_OS"),              c(t, i, ": AvPTll Nj2Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1805] = new TH1D(c(n, i, "_AvPTll_Nj2Nb0_OS"),              c(t, i, ": AvPTll Nj2Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1806] = new TH1D(c(n, i, "_AvPTll_Nj2Nb1_OS"),              c(t, i, ": AvPTll Nj2Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1807] = new TH1D(c(n, i, "_AvPTll_Nj2Nb2_OS"),              c(t, i, ": AvPTll Nj2Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][1808] = new TH1D(c(n, i, "_AvPTll_Nj3Pre_OS"),              c(t, i, ": AvPTll Nj3Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1809] = new TH1D(c(n, i, "_AvPTll_Nj3Nb0_OS"),              c(t, i, ": AvPTll Nj3Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1810] = new TH1D(c(n, i, "_AvPTll_Nj3Nb1_OS"),              c(t, i, ": AvPTll Nj3Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1811] = new TH1D(c(n, i, "_AvPTll_Nj3Nb2_OS"),              c(t, i, ": AvPTll Nj3Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][1812] = new TH1D(c(n, i, "_AvPTll_Nj4Pre_OS"),              c(t, i, ": AvPTll Nj4Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1813] = new TH1D(c(n, i, "_AvPTll_Nj4Nb0_OS"),              c(t, i, ": AvPTll Nj4Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1814] = new TH1D(c(n, i, "_AvPTll_Nj4Nb1_OS"),              c(t, i, ": AvPTll Nj4Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1815] = new TH1D(c(n, i, "_AvPTll_Nj4Nb2_OS"),              c(t, i, ": AvPTll Nj4Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][1816] = new TH1D(c(n, i, "_AvPTll_Nj5Pre_OS"),              c(t, i, ": AvPTll Nj5Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1817] = new TH1D(c(n, i, "_AvPTll_Nj5Nb0_OS"),              c(t, i, ": AvPTll Nj5Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1818] = new TH1D(c(n, i, "_AvPTll_Nj5Nb1_OS"),              c(t, i, ": AvPTll Nj5Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1819] = new TH1D(c(n, i, "_AvPTll_Nj5Nb2_OS"),              c(t, i, ": AvPTll Nj5Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][1820] = new TH1D(c(n, i, "_AvPTll_Nj6Pre_OS"),              c(t, i, ": AvPTll Nj6Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1821] = new TH1D(c(n, i, "_AvPTll_Nj6Nb0_OS"),              c(t, i, ": AvPTll Nj6Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1822] = new TH1D(c(n, i, "_AvPTll_Nj6Nb1_OS"),              c(t, i, ": AvPTll Nj6Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1823] = new TH1D(c(n, i, "_AvPTll_Nj6Nb2_OS"),              c(t, i, ": AvPTll Nj6Nb2 OS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 Counters --------------------------------------
                histo[i][1830] = new TH1D(c(n, i, "_ttjetsDD_NjGe2NbGe0_OS"),      c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe0 OS"),  10, -0.5,  9.5  );
                histo[i][1831] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb0_OS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb0 OS"),    10, -0.5,  9.5  );
                histo[i][1832] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb1_OS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb1 OS"),    10, -0.5,  9.5  );
                histo[i][1833] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb2_OS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb2 OS"),    10, -0.5,  9.5  );
                // Nj=2 Counters 
                histo[i][1834] = new TH1D(c(n, i, "_ttjetsDD_Nj2Pre_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Pre OS"),     10, -0.5,  9.5  );
                histo[i][1835] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb0_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][1836] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb1_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][1837] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb2_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=3 Counters
                histo[i][1838] = new TH1D(c(n, i, "_ttjetsDD_Nj3Pre_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Pre OS"),     10, -0.5,  9.5  );
                histo[i][1839] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb0_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][1840] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb1_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][1841] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb2_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=4 Counters
                histo[i][1842] = new TH1D(c(n, i, "_ttjetsDD_Nj4Pre_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Pre OS"),     10, -0.5,  9.5  );
                histo[i][1843] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb0_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][1844] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb1_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][1845] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb2_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb2 OS"),     10, -0.5,  9.5  );
                // Nj=5 Counters
                histo[i][1846] = new TH1D(c(n, i, "_ttjetsDD_Nj5Pre_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Pre OS"),     10, -0.5,  9.5  );
                histo[i][1847] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb0_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][1848] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb1_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][1849] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb2_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb2 OS"),     10, -0.5,  9.5  );
                // Nj>=6 Counters
                histo[i][1850] = new TH1D(c(n, i, "_ttjetsDD_Nj6Pre_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Pre OS"),     10, -0.5,  9.5  );
                histo[i][1851] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb0_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb0 OS"),     10, -0.5,  9.5  );
                histo[i][1852] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb1_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb1 OS"),     10, -0.5,  9.5  );
                histo[i][1853] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb2_OS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb2 OS"),     10, -0.5,  9.5  );

                // Nj>=2 Nb0>=0 Mass(ll) --------------------------------------
                histo[i][1860] = new TH1D(c(n, i, "_ttMll_NjGe2NbGe0_OS"),          c(t, i, ": ttMll Nj2GeNbGe0 OS"),                      bM,    lM, hM    );
                histo[i][1861] = new TH1D(c(n, i, "_ttMll_NjGe2Nb0_OS"),            c(t, i, ": ttMll Nj2GeNb0 OS"),                        bM,    lM, hM    );
                histo[i][1862] = new TH1D(c(n, i, "_ttMll_NjGe2Nb1_OS"),            c(t, i, ": ttMll Nj2GeNb1 OS"),                        bM,    lM, hM    );
                histo[i][1863] = new TH1D(c(n, i, "_ttMll_NjGe2Nb2_OS"),            c(t, i, ": ttMll Nj2GeNb2 OS"),                        bM,    lM, hM    );
                // Nj=2 
                histo[i][1864] = new TH1D(c(n, i, "_ttMll_Nj2Pre_OS"),              c(t, i, ": ttMll Nj2Pre OS"),                          bM,    lM, hM    );
                histo[i][1865] = new TH1D(c(n, i, "_ttMll_Nj2Nb0_OS"),              c(t, i, ": ttMll Nj2Nb0 OS"),                          bM,    lM, hM    );
                histo[i][1866] = new TH1D(c(n, i, "_ttMll_Nj2Nb1_OS"),              c(t, i, ": ttMll Nj2Nb1 OS"),                          bM,    lM, hM    );
                histo[i][1867] = new TH1D(c(n, i, "_ttMll_Nj2Nb2_OS"),              c(t, i, ": ttMll Nj2Nb2 OS"),                          bM,    lM, hM    );
                // Nj=3
                histo[i][1868] = new TH1D(c(n, i, "_ttMll_Nj3Pre_OS"),              c(t, i, ": ttMll Nj3Pre OS"),                          bM,    lM, hM    );
                histo[i][1869] = new TH1D(c(n, i, "_ttMll_Nj3Nb0_OS"),              c(t, i, ": ttMll Nj3Nb0 OS"),                          bM,    lM, hM    );
                histo[i][1870] = new TH1D(c(n, i, "_ttMll_Nj3Nb1_OS"),              c(t, i, ": ttMll Nj3Nb1 OS"),                          bM,    lM, hM    );
                histo[i][1871] = new TH1D(c(n, i, "_ttMll_Nj3Nb2_OS"),              c(t, i, ": ttMll Nj3Nb2 OS"),                          bM,    lM, hM    );
                // Nj=4
                histo[i][1872] = new TH1D(c(n, i, "_ttMll_Nj4Pre_OS"),              c(t, i, ": ttMll Nj4Pre OS"),                          bM,    lM, hM    );
                histo[i][1873] = new TH1D(c(n, i, "_ttMll_Nj4Nb0_OS"),              c(t, i, ": ttMll Nj4Nb0 OS"),                          bM,    lM, hM    );
                histo[i][1874] = new TH1D(c(n, i, "_ttMll_Nj4Nb1_OS"),              c(t, i, ": ttMll Nj4Nb1 OS"),                          bM,    lM, hM    );
                histo[i][1875] = new TH1D(c(n, i, "_ttMll_Nj4Nb2_OS"),              c(t, i, ": ttMll Nj4Nb2 OS"),                          bM,    lM, hM    );
                // Nj=5
                histo[i][1876] = new TH1D(c(n, i, "_ttMll_Nj5Pre_OS"),              c(t, i, ": ttMll Nj5Pre OS"),                          bM,    lM, hM    );
                histo[i][1877] = new TH1D(c(n, i, "_ttMll_Nj5Nb0_OS"),              c(t, i, ": ttMll Nj5Nb0 OS"),                          bM,    lM, hM    );
                histo[i][1878] = new TH1D(c(n, i, "_ttMll_Nj5Nb1_OS"),              c(t, i, ": ttMll Nj5Nb1 OS"),                          bM,    lM, hM    );
                histo[i][1879] = new TH1D(c(n, i, "_ttMll_Nj5Nb2_OS"),              c(t, i, ": ttMll Nj5Nb2 OS"),                          bM,    lM, hM    );
                // Nj>=6
                histo[i][1880] = new TH1D(c(n, i, "_ttMll_Nj6Pre_OS"),              c(t, i, ": ttMll Nj6Pre OS"),                          bM,    lM, hM    );
                histo[i][1881] = new TH1D(c(n, i, "_ttMll_Nj6Nb0_OS"),              c(t, i, ": ttMll Nj6Nb0 OS"),                          bM,    lM, hM    );
                histo[i][1882] = new TH1D(c(n, i, "_ttMll_Nj6Nb1_OS"),              c(t, i, ": ttMll Nj6Nb1 OS"),                          bM,    lM, hM    );
                histo[i][1883] = new TH1D(c(n, i, "_ttMll_Nj6Nb2_OS"),              c(t, i, ": ttMll Nj6Nb2 OS"),                          bM,    lM, hM    );

                // Nj>=2 Nb0>=0 Pt (ttbar) ------------------------------------
                histo[i][1890] = new TH1D(c(n, i, "_PTtt_NjGe2NbGe0_OS"),          c(t, i, ": PTtt Nj2GeNbGe0 OS"),                      bPt,    lPt, hPt    );
                histo[i][1891] = new TH1D(c(n, i, "_PTtt_NjGe2Nb0_OS"),            c(t, i, ": PTtt Nj2GeNb0 OS"),                        bPt,    lPt, hPt    );
                histo[i][1892] = new TH1D(c(n, i, "_PTtt_NjGe2Nb1_OS"),            c(t, i, ": PTtt Nj2GeNb1 OS"),                        bPt,    lPt, hPt    );
                histo[i][1893] = new TH1D(c(n, i, "_PTtt_NjGe2Nb2_OS"),            c(t, i, ": PTtt Nj2GeNb2 OS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][1894] = new TH1D(c(n, i, "_PTtt_Nj2Pre_OS"),              c(t, i, ": PTtt Nj2Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1895] = new TH1D(c(n, i, "_PTtt_Nj2Nb0_OS"),              c(t, i, ": PTtt Nj2Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1896] = new TH1D(c(n, i, "_PTtt_Nj2Nb1_OS"),              c(t, i, ": PTtt Nj2Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1897] = new TH1D(c(n, i, "_PTtt_Nj2Nb2_OS"),              c(t, i, ": PTtt Nj2Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][1898] = new TH1D(c(n, i, "_PTtt_Nj3Pre_OS"),              c(t, i, ": PTtt Nj3Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1899] = new TH1D(c(n, i, "_PTtt_Nj3Nb0_OS"),              c(t, i, ": PTtt Nj3Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1900] = new TH1D(c(n, i, "_PTtt_Nj3Nb1_OS"),              c(t, i, ": PTtt Nj3Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1901] = new TH1D(c(n, i, "_PTtt_Nj3Nb2_OS"),              c(t, i, ": PTtt Nj3Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][1902] = new TH1D(c(n, i, "_PTtt_Nj4Pre_OS"),              c(t, i, ": PTtt Nj4Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1903] = new TH1D(c(n, i, "_PTtt_Nj4Nb0_OS"),              c(t, i, ": PTtt Nj4Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1904] = new TH1D(c(n, i, "_PTtt_Nj4Nb1_OS"),              c(t, i, ": PTtt Nj4Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1905] = new TH1D(c(n, i, "_PTtt_Nj4Nb2_OS"),              c(t, i, ": PTtt Nj4Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][1906] = new TH1D(c(n, i, "_PTtt_Nj5Pre_OS"),              c(t, i, ": PTtt Nj5Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1907] = new TH1D(c(n, i, "_PTtt_Nj5Nb0_OS"),              c(t, i, ": PTtt Nj5Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1908] = new TH1D(c(n, i, "_PTtt_Nj5Nb1_OS"),              c(t, i, ": PTtt Nj5Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1909] = new TH1D(c(n, i, "_PTtt_Nj5Nb2_OS"),              c(t, i, ": PTtt Nj5Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][1910] = new TH1D(c(n, i, "_PTtt_Nj6Pre_OS"),              c(t, i, ": PTtt Nj6Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1911] = new TH1D(c(n, i, "_PTtt_Nj6Nb0_OS"),              c(t, i, ": PTtt Nj6Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1912] = new TH1D(c(n, i, "_PTtt_Nj6Nb1_OS"),              c(t, i, ": PTtt Nj6Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1913] = new TH1D(c(n, i, "_PTtt_Nj6Nb2_OS"),              c(t, i, ": PTtt Nj6Nb2 OS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 Average pT(bbbar) -----------------------------
                histo[i][1920] = new TH1D(c(n, i, "_AvPTbb_NjGe2NbGe0_OS"),          c(t, i, ": AvPTbb Nj2GeNbGe0 OS"),                      bPt,    lPt, hPt    );
                histo[i][1921] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb0_OS"),            c(t, i, ": AvPTbb Nj2GeNb0 OS"),                        bPt,    lPt, hPt    );
                histo[i][1922] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb1_OS"),            c(t, i, ": AvPTbb Nj2GeNb1 OS"),                        bPt,    lPt, hPt    );
                histo[i][1923] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb2_OS"),            c(t, i, ": AvPTbb Nj2GeNb2 OS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][1924] = new TH1D(c(n, i, "_AvPTbb_Nj2Pre_OS"),              c(t, i, ": AvPTbb Nj2Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1925] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb0_OS"),              c(t, i, ": AvPTbb Nj2Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1926] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb1_OS"),              c(t, i, ": AvPTbb Nj2Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1927] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb2_OS"),              c(t, i, ": AvPTbb Nj2Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][1928] = new TH1D(c(n, i, "_AvPTbb_Nj3Pre_OS"),              c(t, i, ": AvPTbb Nj3Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1929] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb0_OS"),              c(t, i, ": AvPTbb Nj3Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1930] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb1_OS"),              c(t, i, ": AvPTbb Nj3Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1931] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb2_OS"),              c(t, i, ": AvPTbb Nj3Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][1932] = new TH1D(c(n, i, "_AvPTbb_Nj4Pre_OS"),              c(t, i, ": AvPTbb Nj4Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1933] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb0_OS"),              c(t, i, ": AvPTbb Nj4Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1934] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb1_OS"),              c(t, i, ": AvPTbb Nj4Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1935] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb2_OS"),              c(t, i, ": AvPTbb Nj4Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][1936] = new TH1D(c(n, i, "_AvPTbb_Nj5Pre_OS"),              c(t, i, ": AvPTbb Nj5Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1937] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb0_OS"),              c(t, i, ": AvPTbb Nj5Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1938] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb1_OS"),              c(t, i, ": AvPTbb Nj5Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1939] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb2_OS"),              c(t, i, ": AvPTbb Nj5Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][1940] = new TH1D(c(n, i, "_AvPTbb_Nj6Pre_OS"),              c(t, i, ": AvPTbb Nj6Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1941] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb0_OS"),              c(t, i, ": AvPTbb Nj6Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1942] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb1_OS"),              c(t, i, ": AvPTbb Nj6Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1943] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb2_OS"),              c(t, i, ": AvPTbb Nj6Nb2 OS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 ETA (l+l-) ------------------------------------
                histo[i][1950] = new TH1D(c(n, i, "_ttEtall_NjGe2NbGe0_OS"),          c(t, i, ": ttEtall Nj2GeNbGe0 OS"),                     40, -4.0, 4.0);
                histo[i][1951] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb0_OS"),            c(t, i, ": ttEtall Nj2GeNb0 OS"),                       40, -4.0, 4.0);
                histo[i][1952] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb1_OS"),            c(t, i, ": ttEtall Nj2GeNb1 OS"),                       40, -4.0, 4.0);
                histo[i][1953] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb2_OS"),            c(t, i, ": ttEtall Nj2GeNb2 OS"),                       40, -4.0, 4.0);
                // Nj=2 
                histo[i][1954] = new TH1D(c(n, i, "_ttEtall_Nj2Pre_OS"),              c(t, i, ": ttEtall Nj2Pre OS"),                          40, -4.0, 4.0);
                histo[i][1955] = new TH1D(c(n, i, "_ttEtall_Nj2Nb0_OS"),              c(t, i, ": ttEtall Nj2Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1956] = new TH1D(c(n, i, "_ttEtall_Nj2Nb1_OS"),              c(t, i, ": ttEtall Nj2Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1957] = new TH1D(c(n, i, "_ttEtall_Nj2Nb2_OS"),              c(t, i, ": ttEtall Nj2Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][1958] = new TH1D(c(n, i, "_ttEtall_Nj3Pre_OS"),              c(t, i, ": ttEtall Nj3Pre OS"),                          40, -4.0, 4.0);
                histo[i][1959] = new TH1D(c(n, i, "_ttEtall_Nj3Nb0_OS"),              c(t, i, ": ttEtall Nj3Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1960] = new TH1D(c(n, i, "_ttEtall_Nj3Nb1_OS"),              c(t, i, ": ttEtall Nj3Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1961] = new TH1D(c(n, i, "_ttEtall_Nj3Nb2_OS"),              c(t, i, ": ttEtall Nj3Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][1962] = new TH1D(c(n, i, "_ttEtall_Nj4Pre_OS"),              c(t, i, ": ttEtall Nj4Pre OS"),                          40, -4.0, 4.0);
                histo[i][1963] = new TH1D(c(n, i, "_ttEtall_Nj4Nb0_OS"),              c(t, i, ": ttEtall Nj4Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1964] = new TH1D(c(n, i, "_ttEtall_Nj4Nb1_OS"),              c(t, i, ": ttEtall Nj4Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1965] = new TH1D(c(n, i, "_ttEtall_Nj4Nb2_OS"),              c(t, i, ": ttEtall Nj4Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][1966] = new TH1D(c(n, i, "_ttEtall_Nj5Pre_OS"),              c(t, i, ": ttEtall Nj5Pre OS"),                          40, -4.0, 4.0);
                histo[i][1967] = new TH1D(c(n, i, "_ttEtall_Nj5Nb0_OS"),              c(t, i, ": ttEtall Nj5Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1968] = new TH1D(c(n, i, "_ttEtall_Nj5Nb1_OS"),              c(t, i, ": ttEtall Nj5Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1969] = new TH1D(c(n, i, "_ttEtall_Nj5Nb2_OS"),              c(t, i, ": ttEtall Nj5Nb2 OS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][1970] = new TH1D(c(n, i, "_ttEtall_Nj6Pre_OS"),              c(t, i, ": ttEtall Nj6Pre OS"),                          40, -4.0, 4.0);
                histo[i][1971] = new TH1D(c(n, i, "_ttEtall_Nj6Nb0_OS"),              c(t, i, ": ttEtall Nj6Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][1972] = new TH1D(c(n, i, "_ttEtall_Nj6Nb1_OS"),              c(t, i, ": ttEtall Nj6Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][1973] = new TH1D(c(n, i, "_ttEtall_Nj6Nb2_OS"),              c(t, i, ": ttEtall Nj6Nb2 OS"),                          40, -4.0, 4.0);

                // Nj>=2 Nb0>=0 Pt (ttbar+jj=ALL jets+lep+miss) ---------------
                histo[i][1980] = new TH1D(c(n, i, "_AllPTtt_NjGe2NbGe0_OS"),          c(t, i, ": AllPTtt Nj2GeNbGe0 OS"),                      bPt,    lPt, hPt    );
                histo[i][1981] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb0_OS"),            c(t, i, ": AllPTtt Nj2GeNb0 OS"),                        bPt,    lPt, hPt    );
                histo[i][1982] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb1_OS"),            c(t, i, ": AllPTtt Nj2GeNb1 OS"),                        bPt,    lPt, hPt    );
                histo[i][1983] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb2_OS"),            c(t, i, ": AllPTtt Nj2GeNb2 OS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][1984] = new TH1D(c(n, i, "_AllPTtt_Nj2Pre_OS"),              c(t, i, ": AllPTtt Nj2Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1985] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb0_OS"),              c(t, i, ": AllPTtt Nj2Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1986] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb1_OS"),              c(t, i, ": AllPTtt Nj2Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1987] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb2_OS"),              c(t, i, ": AllPTtt Nj2Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][1988] = new TH1D(c(n, i, "_AllPTtt_Nj3Pre_OS"),              c(t, i, ": AllPTtt Nj3Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1989] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb0_OS"),              c(t, i, ": AllPTtt Nj3Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1990] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb1_OS"),              c(t, i, ": AllPTtt Nj3Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1991] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb2_OS"),              c(t, i, ": AllPTtt Nj3Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][1992] = new TH1D(c(n, i, "_AllPTtt_Nj4Pre_OS"),              c(t, i, ": AllPTtt Nj4Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1993] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb0_OS"),              c(t, i, ": AllPTtt Nj4Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1994] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb1_OS"),              c(t, i, ": AllPTtt Nj4Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1995] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb2_OS"),              c(t, i, ": AllPTtt Nj4Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][1996] = new TH1D(c(n, i, "_AllPTtt_Nj5Pre_OS"),              c(t, i, ": AllPTtt Nj5Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][1997] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb0_OS"),              c(t, i, ": AllPTtt Nj5Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][1998] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb1_OS"),              c(t, i, ": AllPTtt Nj5Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][1999] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb2_OS"),              c(t, i, ": AllPTtt Nj5Nb2 OS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][2000] = new TH1D(c(n, i, "_AllPTtt_Nj6Pre_OS"),              c(t, i, ": AllPTtt Nj6Pre OS"),                          bPt,    lPt, hPt    );
                histo[i][2001] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb0_OS"),              c(t, i, ": AllPTtt Nj6Nb0 OS"),                          bPt,    lPt, hPt    );
                histo[i][2002] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb1_OS"),              c(t, i, ": AllPTtt Nj6Nb1 OS"),                          bPt,    lPt, hPt    );
                histo[i][2003] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb2_OS"),              c(t, i, ": AllPTtt Nj6Nb2 OS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 PHI (l+l-) ------------------------------------
                histo[i][2010] = new TH1D(c(n, i, "_ttPhill_NjGe2NbGe0_OS"),          c(t, i, ": ttPhill Nj2GeNbGe0 OS"),                     40, -4.0, 4.0);
                histo[i][2011] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb0_OS"),            c(t, i, ": ttPhill Nj2GeNb0 OS"),                       40, -4.0, 4.0);
                histo[i][2012] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb1_OS"),            c(t, i, ": ttPhill Nj2GeNb1 OS"),                       40, -4.0, 4.0);
                histo[i][2013] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb2_OS"),            c(t, i, ": ttPhill Nj2GeNb2 OS"),                       40, -4.0, 4.0);
                // Nj=2
                histo[i][2014] = new TH1D(c(n, i, "_ttPhill_Nj2Pre_OS"),              c(t, i, ": ttPhill Nj2Pre OS"),                          40, -4.0, 4.0);
                histo[i][2015] = new TH1D(c(n, i, "_ttPhill_Nj2Nb0_OS"),              c(t, i, ": ttPhill Nj2Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][2016] = new TH1D(c(n, i, "_ttPhill_Nj2Nb1_OS"),              c(t, i, ": ttPhill Nj2Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][2017] = new TH1D(c(n, i, "_ttPhill_Nj2Nb2_OS"),              c(t, i, ": ttPhill Nj2Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][2018] = new TH1D(c(n, i, "_ttPhill_Nj3Pre_OS"),              c(t, i, ": ttPhill Nj3Pre OS"),                          40, -4.0, 4.0);
                histo[i][2019] = new TH1D(c(n, i, "_ttPhill_Nj3Nb0_OS"),              c(t, i, ": ttPhill Nj3Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][2020] = new TH1D(c(n, i, "_ttPhill_Nj3Nb1_OS"),              c(t, i, ": ttPhill Nj3Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][2021] = new TH1D(c(n, i, "_ttPhill_Nj3Nb2_OS"),              c(t, i, ": ttPhill Nj3Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][2022] = new TH1D(c(n, i, "_ttPhill_Nj4Pre_OS"),              c(t, i, ": ttPhill Nj4Pre OS"),                          40, -4.0, 4.0);
                histo[i][2023] = new TH1D(c(n, i, "_ttPhill_Nj4Nb0_OS"),              c(t, i, ": ttPhill Nj4Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][2024] = new TH1D(c(n, i, "_ttPhill_Nj4Nb1_OS"),              c(t, i, ": ttPhill Nj4Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][2025] = new TH1D(c(n, i, "_ttPhill_Nj4Nb2_OS"),              c(t, i, ": ttPhill Nj4Nb2 OS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][2026] = new TH1D(c(n, i, "_ttPhill_Nj5Pre_OS"),              c(t, i, ": ttPhill Nj5Pre OS"),                          40, -4.0, 4.0);
                histo[i][2027] = new TH1D(c(n, i, "_ttPhill_Nj5Nb0_OS"),              c(t, i, ": ttPhill Nj5Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][2028] = new TH1D(c(n, i, "_ttPhill_Nj5Nb1_OS"),              c(t, i, ": ttPhill Nj5Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][2029] = new TH1D(c(n, i, "_ttPhill_Nj5Nb2_OS"),              c(t, i, ": ttPhill Nj5Nb2 OS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][2030] = new TH1D(c(n, i, "_ttPhill_Nj6Pre_OS"),              c(t, i, ": ttPhill Nj6Pre OS"),                          40, -4.0, 4.0);
                histo[i][2031] = new TH1D(c(n, i, "_ttPhill_Nj6Nb0_OS"),              c(t, i, ": ttPhill Nj6Nb0 OS"),                          40, -4.0, 4.0);
                histo[i][2032] = new TH1D(c(n, i, "_ttPhill_Nj6Nb1_OS"),              c(t, i, ": ttPhill Nj6Nb1 OS"),                          40, -4.0, 4.0);
                histo[i][2033] = new TH1D(c(n, i, "_ttPhill_Nj6Nb2_OS"),              c(t, i, ": ttPhill Nj6Nb2 OS"),                          40, -4.0, 4.0);


		// ================= SS Distributions =========================
                // Nj>=2 Nb0>=0 Average pT(l+l-) ------------------------------
                histo[i][400+1800] = new TH1D(c(n, i, "_AvPTll_NjGe2NbGe0_SS"),          c(t, i, ": AvPTll Nj2GeNbGe0 SS"),                      bPt,    lPt, hPt    );
                histo[i][400+1801] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb0_SS"),            c(t, i, ": AvPTll Nj2GeNb0 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1802] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb1_SS"),            c(t, i, ": AvPTll Nj2GeNb1 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1803] = new TH1D(c(n, i, "_AvPTll_NjGe2Nb2_SS"),            c(t, i, ": AvPTll Nj2GeNb2 SS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+1804] = new TH1D(c(n, i, "_AvPTll_Nj2Pre_SS"),              c(t, i, ": AvPTll Nj2Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1805] = new TH1D(c(n, i, "_AvPTll_Nj2Nb0_SS"),              c(t, i, ": AvPTll Nj2Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1806] = new TH1D(c(n, i, "_AvPTll_Nj2Nb1_SS"),              c(t, i, ": AvPTll Nj2Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1807] = new TH1D(c(n, i, "_AvPTll_Nj2Nb2_SS"),              c(t, i, ": AvPTll Nj2Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+1808] = new TH1D(c(n, i, "_AvPTll_Nj3Pre_SS"),              c(t, i, ": AvPTll Nj3Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1809] = new TH1D(c(n, i, "_AvPTll_Nj3Nb0_SS"),              c(t, i, ": AvPTll Nj3Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1810] = new TH1D(c(n, i, "_AvPTll_Nj3Nb1_SS"),              c(t, i, ": AvPTll Nj3Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1811] = new TH1D(c(n, i, "_AvPTll_Nj3Nb2_SS"),              c(t, i, ": AvPTll Nj3Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+1812] = new TH1D(c(n, i, "_AvPTll_Nj4Pre_SS"),              c(t, i, ": AvPTll Nj4Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1813] = new TH1D(c(n, i, "_AvPTll_Nj4Nb0_SS"),              c(t, i, ": AvPTll Nj4Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1814] = new TH1D(c(n, i, "_AvPTll_Nj4Nb1_SS"),              c(t, i, ": AvPTll Nj4Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1815] = new TH1D(c(n, i, "_AvPTll_Nj4Nb2_SS"),              c(t, i, ": AvPTll Nj4Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+1816] = new TH1D(c(n, i, "_AvPTll_Nj5Pre_SS"),              c(t, i, ": AvPTll Nj5Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1817] = new TH1D(c(n, i, "_AvPTll_Nj5Nb0_SS"),              c(t, i, ": AvPTll Nj5Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1818] = new TH1D(c(n, i, "_AvPTll_Nj5Nb1_SS"),              c(t, i, ": AvPTll Nj5Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1819] = new TH1D(c(n, i, "_AvPTll_Nj5Nb2_SS"),              c(t, i, ": AvPTll Nj5Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+1820] = new TH1D(c(n, i, "_AvPTll_Nj6Pre_SS"),              c(t, i, ": AvPTll Nj6Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1821] = new TH1D(c(n, i, "_AvPTll_Nj6Nb0_SS"),              c(t, i, ": AvPTll Nj6Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1822] = new TH1D(c(n, i, "_AvPTll_Nj6Nb1_SS"),              c(t, i, ": AvPTll Nj6Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1823] = new TH1D(c(n, i, "_AvPTll_Nj6Nb2_SS"),              c(t, i, ": AvPTll Nj6Nb2 SS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 Counters --------------------------------------
                histo[i][400+1830] = new TH1D(c(n, i, "_ttjetsDD_NjGe2NbGe0_SS"),      c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2NbGe0 SS"),  10, -0.5,  9.5  );
                histo[i][400+1831] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb0_SS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb0 SS"),    10, -0.5,  9.5  );
                histo[i][400+1832] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb1_SS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb1 SS"),    10, -0.5,  9.5  );
                histo[i][400+1833] = new TH1D(c(n, i, "_ttjetsDD_NjGe2Nb2_SS"),        c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR NjGe2Nb2 SS"),    10, -0.5,  9.5  );
                // Nj=2 Counters 
                histo[i][400+1834] = new TH1D(c(n, i, "_ttjetsDD_Nj2Pre_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+1835] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb0_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+1836] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb1_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+1837] = new TH1D(c(n, i, "_ttjetsDD_Nj2Nb2_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj2Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=3 Counters
                histo[i][400+1838] = new TH1D(c(n, i, "_ttjetsDD_Nj3Pre_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+1839] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb0_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+1840] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb1_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+1841] = new TH1D(c(n, i, "_ttjetsDD_Nj3Nb2_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj3Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=4 Counters
                histo[i][400+1842] = new TH1D(c(n, i, "_ttjetsDD_Nj4Pre_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+1843] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb0_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+1844] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb1_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+1845] = new TH1D(c(n, i, "_ttjetsDD_Nj4Nb2_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj4Nb2 SS"),     10, -0.5,  9.5  );
                // Nj=5 Counters
                histo[i][400+1846] = new TH1D(c(n, i, "_ttjetsDD_Nj5Pre_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+1847] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb0_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+1848] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb1_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+1849] = new TH1D(c(n, i, "_ttjetsDD_Nj5Nb2_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj5Nb2 SS"),     10, -0.5,  9.5  );
                // Nj>=6 Counters
                histo[i][400+1850] = new TH1D(c(n, i, "_ttjetsDD_Nj6Pre_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Pre SS"),     10, -0.5,  9.5  );
                histo[i][400+1851] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb0_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb0 SS"),     10, -0.5,  9.5  );
                histo[i][400+1852] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb1_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb1 SS"),     10, -0.5,  9.5  );
                histo[i][400+1853] = new TH1D(c(n, i, "_ttjetsDD_Nj6Nb2_SS"),          c(t, i, ": ttjetsDD 1=SR, 2=CR, 3=SR Nj6Nb2 SS"),     10, -0.5,  9.5  );

                // Nj>=2 Nb0>=0 Mass(ll) --------------------------------------
                histo[i][400+1860] = new TH1D(c(n, i, "_ttMll_NjGe2NbGe0_SS"),          c(t, i, ": ttMll Nj2GeNbGe0 SS"),                      bM,    lM, hM    );
                histo[i][400+1861] = new TH1D(c(n, i, "_ttMll_NjGe2Nb0_SS"),            c(t, i, ": ttMll Nj2GeNb0 SS"),                        bM,    lM, hM    );
                histo[i][400+1862] = new TH1D(c(n, i, "_ttMll_NjGe2Nb1_SS"),            c(t, i, ": ttMll Nj2GeNb1 SS"),                        bM,    lM, hM    );
                histo[i][400+1863] = new TH1D(c(n, i, "_ttMll_NjGe2Nb2_SS"),            c(t, i, ": ttMll Nj2GeNb2 SS"),                        bM,    lM, hM    );
                // Nj=2 
                histo[i][400+1864] = new TH1D(c(n, i, "_ttMll_Nj2Pre_SS"),              c(t, i, ": ttMll Nj2Pre SS"),                          bM,    lM, hM    );
                histo[i][400+1865] = new TH1D(c(n, i, "_ttMll_Nj2Nb0_SS"),              c(t, i, ": ttMll Nj2Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+1866] = new TH1D(c(n, i, "_ttMll_Nj2Nb1_SS"),              c(t, i, ": ttMll Nj2Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+1867] = new TH1D(c(n, i, "_ttMll_Nj2Nb2_SS"),              c(t, i, ": ttMll Nj2Nb2 SS"),                          bM,    lM, hM    );
                // Nj=3
                histo[i][400+1868] = new TH1D(c(n, i, "_ttMll_Nj3Pre_SS"),              c(t, i, ": ttMll Nj3Pre SS"),                          bM,    lM, hM    );
                histo[i][400+1869] = new TH1D(c(n, i, "_ttMll_Nj3Nb0_SS"),              c(t, i, ": ttMll Nj3Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+1870] = new TH1D(c(n, i, "_ttMll_Nj3Nb1_SS"),              c(t, i, ": ttMll Nj3Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+1871] = new TH1D(c(n, i, "_ttMll_Nj3Nb2_SS"),              c(t, i, ": ttMll Nj3Nb2 SS"),                          bM,    lM, hM    );
                // Nj=4
                histo[i][400+1872] = new TH1D(c(n, i, "_ttMll_Nj4Pre_SS"),              c(t, i, ": ttMll Nj4Pre SS"),                          bM,    lM, hM    );
                histo[i][400+1873] = new TH1D(c(n, i, "_ttMll_Nj4Nb0_SS"),              c(t, i, ": ttMll Nj4Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+1874] = new TH1D(c(n, i, "_ttMll_Nj4Nb1_SS"),              c(t, i, ": ttMll Nj4Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+1875] = new TH1D(c(n, i, "_ttMll_Nj4Nb2_SS"),              c(t, i, ": ttMll Nj4Nb2 SS"),                          bM,    lM, hM    );
                // Nj=5
                histo[i][400+1876] = new TH1D(c(n, i, "_ttMll_Nj5Pre_SS"),              c(t, i, ": ttMll Nj5Pre SS"),                          bM,    lM, hM    );
                histo[i][400+1877] = new TH1D(c(n, i, "_ttMll_Nj5Nb0_SS"),              c(t, i, ": ttMll Nj5Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+1878] = new TH1D(c(n, i, "_ttMll_Nj5Nb1_SS"),              c(t, i, ": ttMll Nj5Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+1879] = new TH1D(c(n, i, "_ttMll_Nj5Nb2_SS"),              c(t, i, ": ttMll Nj5Nb2 SS"),                          bM,    lM, hM    );
                // Nj>=6
                histo[i][400+1880] = new TH1D(c(n, i, "_ttMll_Nj6Pre_SS"),              c(t, i, ": ttMll Nj6Pre SS"),                          bM,    lM, hM    );
                histo[i][400+1881] = new TH1D(c(n, i, "_ttMll_Nj6Nb0_SS"),              c(t, i, ": ttMll Nj6Nb0 SS"),                          bM,    lM, hM    );
                histo[i][400+1882] = new TH1D(c(n, i, "_ttMll_Nj6Nb1_SS"),              c(t, i, ": ttMll Nj6Nb1 SS"),                          bM,    lM, hM    );
                histo[i][400+1883] = new TH1D(c(n, i, "_ttMll_Nj6Nb2_SS"),              c(t, i, ": ttMll Nj6Nb2 SS"),                          bM,    lM, hM    );

                // Nj>=2 Nb0>=0 Pt (ttbar) ------------------------------------
                histo[i][400+1890] = new TH1D(c(n, i, "_PTtt_NjGe2NbGe0_SS"),          c(t, i, ": PTtt Nj2GeNbGe0 SS"),                      bPt,    lPt, hPt    );
                histo[i][400+1891] = new TH1D(c(n, i, "_PTtt_NjGe2Nb0_SS"),            c(t, i, ": PTtt Nj2GeNb0 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1892] = new TH1D(c(n, i, "_PTtt_NjGe2Nb1_SS"),            c(t, i, ": PTtt Nj2GeNb1 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1893] = new TH1D(c(n, i, "_PTtt_NjGe2Nb2_SS"),            c(t, i, ": PTtt Nj2GeNb2 SS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+1894] = new TH1D(c(n, i, "_PTtt_Nj2Pre_SS"),              c(t, i, ": PTtt Nj2Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1895] = new TH1D(c(n, i, "_PTtt_Nj2Nb0_SS"),              c(t, i, ": PTtt Nj2Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1896] = new TH1D(c(n, i, "_PTtt_Nj2Nb1_SS"),              c(t, i, ": PTtt Nj2Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1897] = new TH1D(c(n, i, "_PTtt_Nj2Nb2_SS"),              c(t, i, ": PTtt Nj2Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+1898] = new TH1D(c(n, i, "_PTtt_Nj3Pre_SS"),              c(t, i, ": PTtt Nj3Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1899] = new TH1D(c(n, i, "_PTtt_Nj3Nb0_SS"),              c(t, i, ": PTtt Nj3Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1900] = new TH1D(c(n, i, "_PTtt_Nj3Nb1_SS"),              c(t, i, ": PTtt Nj3Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1901] = new TH1D(c(n, i, "_PTtt_Nj3Nb2_SS"),              c(t, i, ": PTtt Nj3Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+1902] = new TH1D(c(n, i, "_PTtt_Nj4Pre_SS"),              c(t, i, ": PTtt Nj4Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1903] = new TH1D(c(n, i, "_PTtt_Nj4Nb0_SS"),              c(t, i, ": PTtt Nj4Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1904] = new TH1D(c(n, i, "_PTtt_Nj4Nb1_SS"),              c(t, i, ": PTtt Nj4Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1905] = new TH1D(c(n, i, "_PTtt_Nj4Nb2_SS"),              c(t, i, ": PTtt Nj4Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+1906] = new TH1D(c(n, i, "_PTtt_Nj5Pre_SS"),              c(t, i, ": PTtt Nj5Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1907] = new TH1D(c(n, i, "_PTtt_Nj5Nb0_SS"),              c(t, i, ": PTtt Nj5Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1908] = new TH1D(c(n, i, "_PTtt_Nj5Nb1_SS"),              c(t, i, ": PTtt Nj5Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1909] = new TH1D(c(n, i, "_PTtt_Nj5Nb2_SS"),              c(t, i, ": PTtt Nj5Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+1910] = new TH1D(c(n, i, "_PTtt_Nj6Pre_SS"),              c(t, i, ": PTtt Nj6Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1911] = new TH1D(c(n, i, "_PTtt_Nj6Nb0_SS"),              c(t, i, ": PTtt Nj6Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1912] = new TH1D(c(n, i, "_PTtt_Nj6Nb1_SS"),              c(t, i, ": PTtt Nj6Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1913] = new TH1D(c(n, i, "_PTtt_Nj6Nb2_SS"),              c(t, i, ": PTtt Nj6Nb2 SS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 Average pT(bbbar) -----------------------------
                histo[i][400+1920] = new TH1D(c(n, i, "_AvPTbb_NjGe2NbGe0_SS"),          c(t, i, ": AvPTbb Nj2GeNbGe0 SS"),                      bPt,    lPt, hPt    );
                histo[i][400+1921] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb0_SS"),            c(t, i, ": AvPTbb Nj2GeNb0 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1922] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb1_SS"),            c(t, i, ": AvPTbb Nj2GeNb1 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1923] = new TH1D(c(n, i, "_AvPTbb_NjGe2Nb2_SS"),            c(t, i, ": AvPTbb Nj2GeNb2 SS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+1924] = new TH1D(c(n, i, "_AvPTbb_Nj2Pre_SS"),              c(t, i, ": AvPTbb Nj2Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1925] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb0_SS"),              c(t, i, ": AvPTbb Nj2Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1926] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb1_SS"),              c(t, i, ": AvPTbb Nj2Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1927] = new TH1D(c(n, i, "_AvPTbb_Nj2Nb2_SS"),              c(t, i, ": AvPTbb Nj2Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+1928] = new TH1D(c(n, i, "_AvPTbb_Nj3Pre_SS"),              c(t, i, ": AvPTbb Nj3Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1929] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb0_SS"),              c(t, i, ": AvPTbb Nj3Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1930] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb1_SS"),              c(t, i, ": AvPTbb Nj3Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1931] = new TH1D(c(n, i, "_AvPTbb_Nj3Nb2_SS"),              c(t, i, ": AvPTbb Nj3Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+1932] = new TH1D(c(n, i, "_AvPTbb_Nj4Pre_SS"),              c(t, i, ": AvPTbb Nj4Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1933] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb0_SS"),              c(t, i, ": AvPTbb Nj4Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1934] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb1_SS"),              c(t, i, ": AvPTbb Nj4Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1935] = new TH1D(c(n, i, "_AvPTbb_Nj4Nb2_SS"),              c(t, i, ": AvPTbb Nj4Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+1936] = new TH1D(c(n, i, "_AvPTbb_Nj5Pre_SS"),              c(t, i, ": AvPTbb Nj5Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1937] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb0_SS"),              c(t, i, ": AvPTbb Nj5Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1938] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb1_SS"),              c(t, i, ": AvPTbb Nj5Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1939] = new TH1D(c(n, i, "_AvPTbb_Nj5Nb2_SS"),              c(t, i, ": AvPTbb Nj5Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+1940] = new TH1D(c(n, i, "_AvPTbb_Nj6Pre_SS"),              c(t, i, ": AvPTbb Nj6Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1941] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb0_SS"),              c(t, i, ": AvPTbb Nj6Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1942] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb1_SS"),              c(t, i, ": AvPTbb Nj6Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1943] = new TH1D(c(n, i, "_AvPTbb_Nj6Nb2_SS"),              c(t, i, ": AvPTbb Nj6Nb2 SS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 ETA (l+l-) ------------------------------------
                histo[i][400+1950] = new TH1D(c(n, i, "_ttEtall_NjGe2NbGe0_SS"),          c(t, i, ": ttEtall Nj2GeNbGe0 SS"),                     40, -4.0, 4.0);
                histo[i][400+1951] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb0_SS"),            c(t, i, ": ttEtall Nj2GeNb0 SS"),                       40, -4.0, 4.0);
                histo[i][400+1952] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb1_SS"),            c(t, i, ": ttEtall Nj2GeNb1 SS"),                       40, -4.0, 4.0);
                histo[i][400+1953] = new TH1D(c(n, i, "_ttEtall_NjGe2Nb2_SS"),            c(t, i, ": ttEtall Nj2GeNb2 SS"),                       40, -4.0, 4.0);
                // Nj=2 
                histo[i][400+1954] = new TH1D(c(n, i, "_ttEtall_Nj2Pre_SS"),              c(t, i, ": ttEtall Nj2Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1955] = new TH1D(c(n, i, "_ttEtall_Nj2Nb0_SS"),              c(t, i, ": ttEtall Nj2Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1956] = new TH1D(c(n, i, "_ttEtall_Nj2Nb1_SS"),              c(t, i, ": ttEtall Nj2Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1957] = new TH1D(c(n, i, "_ttEtall_Nj2Nb2_SS"),              c(t, i, ": ttEtall Nj2Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+1958] = new TH1D(c(n, i, "_ttEtall_Nj3Pre_SS"),              c(t, i, ": ttEtall Nj3Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1959] = new TH1D(c(n, i, "_ttEtall_Nj3Nb0_SS"),              c(t, i, ": ttEtall Nj3Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1960] = new TH1D(c(n, i, "_ttEtall_Nj3Nb1_SS"),              c(t, i, ": ttEtall Nj3Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1961] = new TH1D(c(n, i, "_ttEtall_Nj3Nb2_SS"),              c(t, i, ": ttEtall Nj3Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+1962] = new TH1D(c(n, i, "_ttEtall_Nj4Pre_SS"),              c(t, i, ": ttEtall Nj4Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1963] = new TH1D(c(n, i, "_ttEtall_Nj4Nb0_SS"),              c(t, i, ": ttEtall Nj4Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1964] = new TH1D(c(n, i, "_ttEtall_Nj4Nb1_SS"),              c(t, i, ": ttEtall Nj4Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1965] = new TH1D(c(n, i, "_ttEtall_Nj4Nb2_SS"),              c(t, i, ": ttEtall Nj4Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+1966] = new TH1D(c(n, i, "_ttEtall_Nj5Pre_SS"),              c(t, i, ": ttEtall Nj5Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1967] = new TH1D(c(n, i, "_ttEtall_Nj5Nb0_SS"),              c(t, i, ": ttEtall Nj5Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1968] = new TH1D(c(n, i, "_ttEtall_Nj5Nb1_SS"),              c(t, i, ": ttEtall Nj5Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1969] = new TH1D(c(n, i, "_ttEtall_Nj5Nb2_SS"),              c(t, i, ": ttEtall Nj5Nb2 SS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+1970] = new TH1D(c(n, i, "_ttEtall_Nj6Pre_SS"),              c(t, i, ": ttEtall Nj6Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+1971] = new TH1D(c(n, i, "_ttEtall_Nj6Nb0_SS"),              c(t, i, ": ttEtall Nj6Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+1972] = new TH1D(c(n, i, "_ttEtall_Nj6Nb1_SS"),              c(t, i, ": ttEtall Nj6Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+1973] = new TH1D(c(n, i, "_ttEtall_Nj6Nb2_SS"),              c(t, i, ": ttEtall Nj6Nb2 SS"),                          40, -4.0, 4.0);

                // Nj>=2 Nb0>=0 Pt (ttbar+jj=ALL jets+lep+miss) ---------------
                histo[i][400+1980] = new TH1D(c(n, i, "_AllPTtt_NjGe2NbGe0_SS"),          c(t, i, ": AllPTtt Nj2GeNbGe0 SS"),                      bPt,    lPt, hPt    );
                histo[i][400+1981] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb0_SS"),            c(t, i, ": AllPTtt Nj2GeNb0 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1982] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb1_SS"),            c(t, i, ": AllPTtt Nj2GeNb1 SS"),                        bPt,    lPt, hPt    );
                histo[i][400+1983] = new TH1D(c(n, i, "_AllPTtt_NjGe2Nb2_SS"),            c(t, i, ": AllPTtt Nj2GeNb2 SS"),                        bPt,    lPt, hPt    );
                // Nj=2 
                histo[i][400+1984] = new TH1D(c(n, i, "_AllPTtt_Nj2Pre_SS"),              c(t, i, ": AllPTtt Nj2Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1985] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb0_SS"),              c(t, i, ": AllPTtt Nj2Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1986] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb1_SS"),              c(t, i, ": AllPTtt Nj2Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1987] = new TH1D(c(n, i, "_AllPTtt_Nj2Nb2_SS"),              c(t, i, ": AllPTtt Nj2Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=3
                histo[i][400+1988] = new TH1D(c(n, i, "_AllPTtt_Nj3Pre_SS"),              c(t, i, ": AllPTtt Nj3Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1989] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb0_SS"),              c(t, i, ": AllPTtt Nj3Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1990] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb1_SS"),              c(t, i, ": AllPTtt Nj3Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1991] = new TH1D(c(n, i, "_AllPTtt_Nj3Nb2_SS"),              c(t, i, ": AllPTtt Nj3Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=4
                histo[i][400+1992] = new TH1D(c(n, i, "_AllPTtt_Nj4Pre_SS"),              c(t, i, ": AllPTtt Nj4Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1993] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb0_SS"),              c(t, i, ": AllPTtt Nj4Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1994] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb1_SS"),              c(t, i, ": AllPTtt Nj4Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1995] = new TH1D(c(n, i, "_AllPTtt_Nj4Nb2_SS"),              c(t, i, ": AllPTtt Nj4Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj=5
                histo[i][400+1996] = new TH1D(c(n, i, "_AllPTtt_Nj5Pre_SS"),              c(t, i, ": AllPTtt Nj5Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1997] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb0_SS"),              c(t, i, ": AllPTtt Nj5Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1998] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb1_SS"),              c(t, i, ": AllPTtt Nj5Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+1999] = new TH1D(c(n, i, "_AllPTtt_Nj5Nb2_SS"),              c(t, i, ": AllPTtt Nj5Nb2 SS"),                          bPt,    lPt, hPt    );
                // Nj>=6
                histo[i][400+2000] = new TH1D(c(n, i, "_AllPTtt_Nj6Pre_SS"),              c(t, i, ": AllPTtt Nj6Pre SS"),                          bPt,    lPt, hPt    );
                histo[i][400+2001] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb0_SS"),              c(t, i, ": AllPTtt Nj6Nb0 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+2002] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb1_SS"),              c(t, i, ": AllPTtt Nj6Nb1 SS"),                          bPt,    lPt, hPt    );
                histo[i][400+2003] = new TH1D(c(n, i, "_AllPTtt_Nj6Nb2_SS"),              c(t, i, ": AllPTtt Nj6Nb2 SS"),                          bPt,    lPt, hPt    );

                // Nj>=2 Nb0>=0 PHI (l+l-) ------------------------------------
                histo[i][400+2010] = new TH1D(c(n, i, "_ttPhill_NjGe2NbGe0_SS"),          c(t, i, ": ttPhill Nj2GeNbGe0 SS"),                     40, -4.0, 4.0);
                histo[i][400+2011] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb0_SS"),            c(t, i, ": ttPhill Nj2GeNb0 SS"),                       40, -4.0, 4.0);
                histo[i][400+2012] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb1_SS"),            c(t, i, ": ttPhill Nj2GeNb1 SS"),                       40, -4.0, 4.0);
                histo[i][400+2013] = new TH1D(c(n, i, "_ttPhill_NjGe2Nb2_SS"),            c(t, i, ": ttPhill Nj2GeNb2 SS"),                       40, -4.0, 4.0);
                // Nj=2
                histo[i][400+2014] = new TH1D(c(n, i, "_ttPhill_Nj2Pre_SS"),              c(t, i, ": ttPhill Nj2Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+2015] = new TH1D(c(n, i, "_ttPhill_Nj2Nb0_SS"),              c(t, i, ": ttPhill Nj2Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+2016] = new TH1D(c(n, i, "_ttPhill_Nj2Nb1_SS"),              c(t, i, ": ttPhill Nj2Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+2017] = new TH1D(c(n, i, "_ttPhill_Nj2Nb2_SS"),              c(t, i, ": ttPhill Nj2Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=3
                histo[i][400+2018] = new TH1D(c(n, i, "_ttPhill_Nj3Pre_SS"),              c(t, i, ": ttPhill Nj3Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+2019] = new TH1D(c(n, i, "_ttPhill_Nj3Nb0_SS"),              c(t, i, ": ttPhill Nj3Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+2020] = new TH1D(c(n, i, "_ttPhill_Nj3Nb1_SS"),              c(t, i, ": ttPhill Nj3Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+2021] = new TH1D(c(n, i, "_ttPhill_Nj3Nb2_SS"),              c(t, i, ": ttPhill Nj3Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=4
                histo[i][400+2022] = new TH1D(c(n, i, "_ttPhill_Nj4Pre_SS"),              c(t, i, ": ttPhill Nj4Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+2023] = new TH1D(c(n, i, "_ttPhill_Nj4Nb0_SS"),              c(t, i, ": ttPhill Nj4Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+2024] = new TH1D(c(n, i, "_ttPhill_Nj4Nb1_SS"),              c(t, i, ": ttPhill Nj4Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+2025] = new TH1D(c(n, i, "_ttPhill_Nj4Nb2_SS"),              c(t, i, ": ttPhill Nj4Nb2 SS"),                          40, -4.0, 4.0);
                // Nj=5
                histo[i][400+2026] = new TH1D(c(n, i, "_ttPhill_Nj5Pre_SS"),              c(t, i, ": ttPhill Nj5Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+2027] = new TH1D(c(n, i, "_ttPhill_Nj5Nb0_SS"),              c(t, i, ": ttPhill Nj5Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+2028] = new TH1D(c(n, i, "_ttPhill_Nj5Nb1_SS"),              c(t, i, ": ttPhill Nj5Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+2029] = new TH1D(c(n, i, "_ttPhill_Nj5Nb2_SS"),              c(t, i, ": ttPhill Nj5Nb2 SS"),                          40, -4.0, 4.0);
                // Nj>=6
                histo[i][400+2030] = new TH1D(c(n, i, "_ttPhill_Nj6Pre_SS"),              c(t, i, ": ttPhill Nj6Pre SS"),                          40, -4.0, 4.0);
                histo[i][400+2031] = new TH1D(c(n, i, "_ttPhill_Nj6Nb0_SS"),              c(t, i, ": ttPhill Nj6Nb0 SS"),                          40, -4.0, 4.0);
                histo[i][400+2032] = new TH1D(c(n, i, "_ttPhill_Nj6Nb1_SS"),              c(t, i, ": ttPhill Nj6Nb1 SS"),                          40, -4.0, 4.0);
                histo[i][400+2033] = new TH1D(c(n, i, "_ttPhill_Nj6Nb2_SS"),              c(t, i, ": ttPhill Nj6Nb2 SS"),                          40, -4.0, 4.0);

		// ...Initialize histograms......
		for(Int_t j = 0; j <= 2500; ++j)
		{
			if(histo[i][j]) histo[i][j]->Sumw2();
		}
	}

        //
        // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ::                                   Make p.d.f.s Histograms and Clone them to Level 0                                       ::
        // ::					             from 760 - 779 (non smoothed) 				        	::
        // ::					             from 780 - 799 (non smoothed) 				        	::
        // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// -----------------------------------------
	// Get pdf histograms for neutrino solutions
	// -----------------------------------------
        double IntPDF; 
	// Define number of pdfs
	myNpdfKinFit = 2;

	// Get relevant pdfs
        for (int n = 0; n < myNpdfKinFit; n++){

			if ( n == 0 ) pdfKinFit[n] = (TH1D*)fTruth->Get("sel00_pdf_pt__n1"); // 1st pdf: pT neutrino 1
			if ( n == 1 ) pdfKinFit[n] = (TH1D*)fTruth->Get("sel00_pdf_pt__n2"); // 2nd pdf: pT neutrino 2

			// normalize to unity and save histos
			IntPDF = pdfKinFit[n]->Integral();
			if ( IntPDF != 0 ) pdfKinFit[n]->Scale(1./IntPDF);
			if ( n == 0 ) {histo[0][760] = (TH1D*)pdfKinFit[n]->Clone("pdf1_pTnu1");}          // 1st pdf: pT neutrino 1 
			if ( n == 1 ) {histo[0][761] = (TH1D*)pdfKinFit[n]->Clone("pdf2_pTnu2");}          // 2nd pdf: pT neutrino 2 

			// smooth histos and save them
			pdfKinFit[n]->Smooth(3);
			if ( n == 0 ) {histo[0][780] = (TH1D*)pdfKinFit[n]->Clone("pdf1_pTnu1_smoothed");} // 1st pdf: pT neutrino 1 Smoothed Distribution
			if ( n == 1 ) {histo[0][781] = (TH1D*)pdfKinFit[n]->Clone("pdf2_pTnu2_smoothed");} // 2nd pdf: pT neutrino 2 Smoothed Distribution

			// Get pdfs into vectors
			NBins[n] = pdfKinFit[n]->GetNbinsX();
			pdfKinFitVec[n] = new double[NBins[n]+2];
			LowerEdge[n] = pdfKinFit[n]->GetBinLowEdge(1);
			UpperEdge[n] = pdfKinFit[n]->GetBinLowEdge(NBins[n]+1);
			Scale[n] = double(NBins[n])/(UpperEdge[n]-LowerEdge[n]);

			// Input pdfKinFitVec
			for (int bin = 0; bin < NBins[n]+2; bin++){
				pdfKinFitVec[n][bin] = pdfKinFit[n]->GetBinContent(bin);
			}
	}
}


// #############################################################################
void ttH_dilep::BookPdfHistos(Int_t i_syst){
// #############################################################################
//
//  purpose: to book histograms to be used as probability density functions
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

	char t[5];

	TH1D *pdf0 = new TH1D(pdf(t, 0), "pdf_0: Pt Miss ", 18, 20., 200.);
	pdf0->Sumw2();
	PdfVec[i_syst].push_back(pdf0);

	TH1D *pdf1 = new TH1D(pdf(t, 1), "pdf_1: ll Mass ", 10, 20., 120.);
	pdf1->Sumw2();
	PdfVec[i_syst].push_back(pdf1);
	
	TH1D *pdf2 = new TH1D(pdf(t, 2), "pdf_2: Pt Lep  ", 18, 20., 200.);
	pdf2->Sumw2();
	PdfVec[i_syst].push_back(pdf2);

}

// #############################################################################
void ttH_dilep::BookLikeHistos(){
// #############################################################################
//
//  purpose: to book histograms to be used as discriminant variables
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

	LogELikeSHist = new TH1D("LogELikeS", "Ln(L_S)", 50, -40, 20);
	LogELikeSHist->Sumw2();

	LogELikeBHist = new TH1D("LogELikeB", "Ln(L_B)", 50, -50, 10);
	LogELikeBHist->Sumw2();

	LogELikelihoodHist = new TH1D("LogELikelihood", "Ln(L_S/L_B)", 75, -5, 10);
	LogELikelihoodHist->Sumw2();

	Log10LikeSHist = new TH1D("Log10LikeS", "Log(L_S)", 120, -60, 0.);
	Log10LikeSHist->Sumw2();

	Log10LikeBHist = new TH1D("Log10LikeB", "Log(L_B)", 120, -60, 0.);
	Log10LikeBHist->Sumw2();

	Log10LikelihoodHist = new TH1D("Log10Likelihood", "Log(L_S/L_B)", 100, -5, 5);
	Log10LikelihoodHist->Sumw2();


}


// #############################################################################
void ttH_dilep::PdfValues(){
// #############################################################################
//
//  purpose: to define the pdf values of each event
//
//  authors: fveloso
//  first version: 20.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

	ThisEventPdfValues[0] = MissPt/GeV;
	ThisEventPdfValues[1] = ll.M()/GeV;
	ThisEventPdfValues[2] = LeptonVec[0].Pt()/GeV;

}


// #############################################################################
void ttH_dilep::DefineSignalPdfSamples(){
// #############################################################################
//
//  purpose: the user should declare here the ROOT samples that will be
//  used as probability density functions
//
//  notes: should be replaced by the user!
//
//  authors: fveloso
//  first version: 18.jun.2007
//
// #############################################################################

	SignalPdfFiles.push_back(signalpdf);

}


// #############################################################################
void ttH_dilep::FillHistograms(THistos &histo){
// #############################################################################
//
//  purpose: to fill histograms inside the event's loop
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 04.Nov.2012
//  by: A.Onofre
//
// #############################################################################

                
	// Loop over all levels
	for(Int_t i = 0; i <= LastCut; ++i){

		// ======== AO 16 Octobre 2011 =================
                // Output Event Weights
                histo[i][591]->Fill(Weight, 1.);
		// ======== AO 16 Octobre 2011 =================


		// -------------------------
		// truth measured information
		// -------------------------
		histo[i][0]->Fill(ntruthlep, Weight);


		// ============================================================
		// ============================================================
		//        TRUTH INFORMATION FOR PDFs and RESOLUTION PLOTS
		//	  Note: - Matching is NOT required for PDFs
		//		- Matching is     required for RESOLUTION plots
		// ============================================================
		// ============================================================
		if ( TruthHasSolution > 0  &&  myTruth_WtauDecay == 0 ){

			// ----------------------------------------------------
			// Truth Distributions (without matching)
			// ----------------------------------------------------
			// double myWei = Weight;			
			double myWei = 1.;			
			int kh = 0;
			int kl = 1;

            cout << "Event: " << Event::event_counter << endl;
            cout << "1 -> " << myTruthLepVec[0].Pt() << endl;
			if ( myTruthLepVec[1].Pt() > myTruthLepVec[0].Pt() ) { kh = 1 ; kl = 0 ;}
			// Highest pT lepton l1-------------------------------------------
			int ip = kh;
			histo[i][204]->Fill(          myTruthLepVec[ip].E()/GeV	, myWei);
			histo[i][205]->Fill(          myTruthLepVec[ip].Pt()/GeV, myWei);
			histo[i][206]->Fill(          myTruthLepVec[ip].Eta()	, myWei);
			histo[i][207]->Fill(          myTruthLepVec[ip].Phi()	, myWei);
			// n1
			histo[i][208]->Fill(          myTruthNeuVec[ip].E()/GeV	, myWei);
			histo[i][209]->Fill(          myTruthNeuVec[ip].Pt()/GeV, myWei);
			histo[i][225]->Fill(          myTruthNeuVec[ip].Eta()	, myWei);
			histo[i][226]->Fill(          myTruthNeuVec[ip].Phi()	, myWei);
			// b1
			histo[i][227]->Fill(          myTruth_b_Vec[ip].E()/GeV	, myWei);
			histo[i][228]->Fill(          myTruth_b_Vec[ip].Pt()/GeV, myWei);
			histo[i][229]->Fill(          myTruth_b_Vec[ip].Eta()	, myWei);
			histo[i][267]->Fill(          myTruth_b_Vec[ip].Phi()	, myWei);
			// W1
			histo[i][268]->Fill(          myTruth_W_Vec[ip].E()/GeV	, myWei);
			histo[i][269]->Fill(          myTruth_W_Vec[ip].Pt()/GeV, myWei);
			histo[i][270]->Fill(          myTruth_W_Vec[ip].Eta()	, myWei);
			histo[i][271]->Fill(          myTruth_W_Vec[ip].Phi()	, myWei);
			histo[i][272]->Fill(          myTruth_W_Vec[ip].M()/GeV	, myWei);
			// t1
			histo[i][273]->Fill(          myTruth_t_Vec[ip].E()/GeV	, myWei);
			histo[i][274]->Fill(          myTruth_t_Vec[ip].Pt()/GeV, myWei);
			histo[i][275]->Fill(          myTruth_t_Vec[ip].Eta()	, myWei);
			histo[i][276]->Fill(          myTruth_t_Vec[ip].Phi()	, myWei);
			histo[i][277]->Fill(          myTruth_t_Vec[ip].M()/GeV	, myWei);
			// Lowest pT lepton l2-------------------------------------------
			ip = kl;
			histo[i][278]->Fill(          myTruthLepVec[ip].E()/GeV	, myWei);
			histo[i][279]->Fill(          myTruthLepVec[ip].Pt()/GeV, myWei);
			histo[i][280]->Fill(          myTruthLepVec[ip].Eta()	, myWei);
			histo[i][281]->Fill(          myTruthLepVec[ip].Phi()	, myWei);
			// n2
			histo[i][282]->Fill(          myTruthNeuVec[ip].E()/GeV	, myWei);
			histo[i][283]->Fill(          myTruthNeuVec[ip].Pt()/GeV, myWei);
			histo[i][284]->Fill(          myTruthNeuVec[ip].Eta()	, myWei);
			histo[i][285]->Fill(          myTruthNeuVec[ip].Phi()	, myWei);
			// b2
			histo[i][286]->Fill(          myTruth_b_Vec[ip].E()/GeV	, myWei);
			histo[i][287]->Fill(          myTruth_b_Vec[ip].Pt()/GeV, myWei);
			histo[i][288]->Fill(          myTruth_b_Vec[ip].Eta()	, myWei);
			histo[i][289]->Fill(          myTruth_b_Vec[ip].Phi()	, myWei);
			// W2
			histo[i][290]->Fill(          myTruth_W_Vec[ip].E()/GeV	, myWei);
			histo[i][291]->Fill(          myTruth_W_Vec[ip].Pt()/GeV, myWei);
			histo[i][292]->Fill(          myTruth_W_Vec[ip].Eta()	, myWei);
			histo[i][293]->Fill(          myTruth_W_Vec[ip].Phi()	, myWei);
			histo[i][294]->Fill(          myTruth_W_Vec[ip].M()/GeV	, myWei);
			// t2
			histo[i][295]->Fill(          myTruth_t_Vec[ip].E()/GeV	, myWei);
			histo[i][296]->Fill(          myTruth_t_Vec[ip].Pt()/GeV, myWei);
			histo[i][297]->Fill(          myTruth_t_Vec[ip].Eta()	, myWei);
			histo[i][298]->Fill(          myTruth_t_Vec[ip].Phi()	, myWei);
			histo[i][299]->Fill(          myTruth_t_Vec[ip].M()/GeV	, myWei);

			// --------------------------------------------------------------
			// Resolution Distributions
			// --------------------------------------------------------------
			// leptons-------------------------------------------------------
                	for( int ilep = 0; ilep < myResolution_Truth_Lep.size(); ++ilep){
				double delTa;
				// Px
				if (   myResolution_Truth_Lep[ilep].Px() != 0. ) {
					delTa = ( myResolution_Reco_Lep[ilep].Px() - myResolution_Truth_Lep[ilep].Px() ) / myResolution_Truth_Lep[ilep].Px() ;  
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 11 ) histo[i][600]->Fill( delTa , myWei);
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 13 ) histo[i][605]->Fill( delTa , myWei);
				}
				// Py
				if (   myResolution_Truth_Lep[ilep].Py() != 0. ) {
					delTa = ( myResolution_Reco_Lep[ilep].Py() - myResolution_Truth_Lep[ilep].Py() ) / myResolution_Truth_Lep[ilep].Py() ;  
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 11 ) histo[i][601]->Fill( delTa , myWei);
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 13 ) histo[i][606]->Fill( delTa , myWei);
				}
				// Pz
				if (   myResolution_Truth_Lep[ilep].Pz() != 0. ) {
					delTa = ( myResolution_Reco_Lep[ilep].Pz() - myResolution_Truth_Lep[ilep].Pz() ) / myResolution_Truth_Lep[ilep].Pz() ;  
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 11 ) histo[i][602]->Fill( delTa , myWei);
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 13 ) histo[i][607]->Fill( delTa , myWei);
				}
				// Pt
				if (   myResolution_Truth_Lep[ilep].Pt() != 0. ) {
					delTa = ( myResolution_Reco_Lep[ilep].Pt() - myResolution_Truth_Lep[ilep].Pt() ) / myResolution_Truth_Lep[ilep].Pt() ;  
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 11 ) histo[i][603]->Fill( delTa , myWei);
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 13 ) histo[i][608]->Fill( delTa , myWei);
				}
				// E
				if (   myResolution_Truth_Lep[ilep].E() != 0. ) {
					delTa = ( myResolution_Reco_Lep[ilep].E() - myResolution_Truth_Lep[ilep].E() ) / myResolution_Truth_Lep[ilep].E() ;  
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 11 ) histo[i][604]->Fill( delTa , myWei);
                        		if ( abs(myResolution_Truth_Lep[ilep].isb) == 13 ) histo[i][609]->Fill( delTa , myWei);
				}
			}
			// jets----------------------------------------------------------
                	for( int ijet = 0; ijet < myResolution_Truth_Jet.size(); ++ijet){
				double delTa;
				// Px
				if (   myResolution_Truth_Jet[ijet].Px() != 0. ) {
					delTa = ( myResolution_Reco_Jet[ijet].Px() - myResolution_Truth_Jet[ijet].Px() ) / myResolution_Truth_Jet[ijet].Px() ;  
                        		histo[i][610]->Fill( delTa , myWei);
				}
				// Py
				if (   myResolution_Truth_Jet[ijet].Py() != 0. ) {
					delTa = ( myResolution_Reco_Jet[ijet].Py() - myResolution_Truth_Jet[ijet].Py() ) / myResolution_Truth_Jet[ijet].Py() ;  
                        		histo[i][611]->Fill( delTa , myWei);
				}
				// Pz
				if (   myResolution_Truth_Jet[ijet].Pz() != 0. ) {
					delTa = ( myResolution_Reco_Jet[ijet].Pz() - myResolution_Truth_Jet[ijet].Pz() ) / myResolution_Truth_Jet[ijet].Pz() ;  
                        		histo[i][612]->Fill( delTa , myWei);
				}
				// Pt
				if (   myResolution_Truth_Jet[ijet].Pt() != 0. ) {
					delTa = ( myResolution_Reco_Jet[ijet].Pt() - myResolution_Truth_Jet[ijet].Pt() ) / myResolution_Truth_Jet[ijet].Pt() ;  
                        		histo[i][613]->Fill( delTa , myWei);
				}
				// E
				if (   myResolution_Truth_Jet[ijet].E() != 0. ) {
					delTa = ( myResolution_Reco_Jet[ijet].E() - myResolution_Truth_Jet[ijet].E() ) / myResolution_Truth_Jet[ijet].E() ;  
                        		histo[i][614]->Fill( delTa , myWei);
				}
			}
			// Miss-----------------------------------------------------------
                	for( int im = 0; im < myResolution_Truth_Mis.size(); ++im){
				double delTa;
				// Px
				if (   myResolution_Truth_Mis[im].Px() != 0. ) {
					delTa = ( myResolution_Reco_Mis[im].Px() - myResolution_Truth_Mis[im].Px() ) / myResolution_Truth_Mis[im].Px() ;  
                        		histo[i][615]->Fill( delTa , myWei);
				}
				// Py
				if (   myResolution_Truth_Mis[im].Py() != 0. ) {
					delTa = ( myResolution_Reco_Mis[im].Py() - myResolution_Truth_Mis[im].Py() ) / myResolution_Truth_Mis[im].Py() ;  
                        		histo[i][616]->Fill( delTa , myWei);
				}
				// Pt
				if (   myResolution_Truth_Mis[im].Pt() != 0. ) {
					delTa = ( myResolution_Reco_Mis[im].Pt() - myResolution_Truth_Mis[im].Pt() ) / myResolution_Truth_Mis[im].Pt() ;  
                        		histo[i][617]->Fill( delTa , myWei);
				}
			}
		}
		// --------------------------------
		// --------------------------------

		// -------------------------
		// measured information
		// -------------------------
		histo[i][1]->Fill(LeptonVec.size(), Weight);
		histo[i][2]->Fill(MyGoodJetVec.size(), Weight);
		histo[i][3]->Fill(Ht/GeV, Weight);
		histo[i][4]->Fill(MissPt/GeV, Weight);

		// -------------------------
		// (jet,btag) multiplicity
		// -------------------------
	        int myNjet  = MyGoodJetVec.size();
	        int myNBtag = MyGoodBtaggedJetVec.size();
		// Njet=2
		if ( myNjet == 2 && myNBtag == 0 ) 	histo[i][328]->Fill(	1., Weight);
		if ( myNjet == 2 && myNBtag == 1 ) 	histo[i][328]->Fill(	2., Weight);
		if ( myNjet == 2 && myNBtag == 2 ) 	histo[i][328]->Fill(	3., Weight);
		// Njet=3
		if ( myNjet == 3 && myNBtag == 0 ) 	histo[i][328]->Fill(	4., Weight);
		if ( myNjet == 3 && myNBtag == 1 ) 	histo[i][328]->Fill(	5., Weight);
		if ( myNjet == 3 && myNBtag == 2 ) 	histo[i][328]->Fill(	6., Weight);
		if ( myNjet == 3 && myNBtag == 3 ) 	histo[i][328]->Fill(	7., Weight);
		// Njet>=4
		if ( myNjet >= 4 && myNBtag == 0 ) 	histo[i][328]->Fill(	8., Weight);
		if ( myNjet >= 4 && myNBtag == 1 ) 	histo[i][328]->Fill(	9., Weight);
		if ( myNjet >= 4 && myNBtag == 2 ) 	histo[i][328]->Fill(   10., Weight);
		if ( myNjet >= 4 && myNBtag == 3 ) 	histo[i][328]->Fill(   11., Weight);
		if ( myNjet >= 4 && myNBtag >= 4 ) 	histo[i][328]->Fill(   12., Weight);

                // -----------------------------------------------
                // Fill up histograms for Z DD studies (OS and SS)
                //    (requires 2 leptons and at least 2 jets)
                // -----------------------------------------------
                myNjet  = MyGoodJetVec.size();
                myNBtag = MyGoodBtaggedJetVec.size();
                int nH    =  800;  // initialize as OS for ZDD
                int nHtt  = 1800;  // initialize as OS for ttbarDD

                // Check there are 2 leptons and at least 2 jets BUT NOT MORE THEN 2 btags
                if( LeptonVec.size()>1 && MyGoodJetVec.size()>1 && myNBtag <= 2 ){

                   // check OS or SS leptons and define nH correctly
                   if ( (LeptonVec[0].isb)*(LeptonVec[1].isb) > 0 ) { nH = 800+400;  nHtt  = 1800+400; } // check if it is SS

                   // define histogram id for all ZDD-like combinations
		   // (still picking up distributions from ZDD to be filled up for ttDD methods)
                   int nH_id ;
                   int nHpre ;
                   int nH_idGe2 ;
                   int nHpreGe2 ;
                   // define histogram id for all ttbar DD combinations
                   int nHtt_id ;
                   int nHttpre ;
                   int nHtt_idGe2 ;
                   int nHttpreGe2 ;

		   // ----------------------------------------
                   // define x and y variables for ZDD studies
		   // ----------------------------------------
                   double xVar   = ll.M()/GeV ;
                   double yVar   = MissPt/GeV ;
                   double ptVar  = ll.Pt()/GeV ;
                   double etaVar = ll.Eta() ;
                   double phiVar = ll.Phi() ;

		   // ----------------------------------------
                   // define variables for ttbar DD studies
		   // ----------------------------------------
		   // pT of 2jets+2leptons+miss
		   double PTtt_x = MyGoodJetVec[0].Px()/GeV + MyGoodJetVec[1].Px()/GeV + LeptonVec[0].Px()/GeV + LeptonVec[1].Px()/GeV + MissPx/GeV ;
		   double PTtt_y = MyGoodJetVec[0].Py()/GeV + MyGoodJetVec[1].Py()/GeV + LeptonVec[0].Py()/GeV + LeptonVec[1].Py()/GeV + MissPy/GeV ;
		   double PTtt   = sqrt( PTtt_x*PTtt_x + PTtt_y*PTtt_y );
		   // pT of ALL objects (ttbar+jets incluing missing)
		   double AllPTtt_x = MissPx/GeV;
		   double AllPTtt_y = MissPy/GeV;
		   double AllPTtt   = 0.;
	           for(int jej=0; jej<MyGoodJetVec.size(); jej++){
			AllPTtt_x += MyGoodJetVec[jej].Px()/GeV;
			AllPTtt_y += MyGoodJetVec[jej].Py()/GeV;
            	   }
	           for(int lel=0; lel<LeptonVec.size(); lel++){
			AllPTtt_x += LeptonVec[lel].Px()/GeV;
			AllPTtt_y += LeptonVec[lel].Py()/GeV;
            	   }
		   AllPTtt = sqrt( AllPTtt_x*AllPTtt_x + AllPTtt_y*AllPTtt_y );	   
		   // Average (b,bbar) pT
		   double AvPTbb = 0.5 * ( MyGoodJetVec[0].Pt()/GeV + MyGoodJetVec[1].Pt()/GeV );
		   // Average (l+,l-) pT
		   double AvPTll = 0.5 * (    LeptonVec[0].Pt()/GeV +    LeptonVec[1].Pt()/GeV );

		   // ==============================================================================
		   // 		      Z-like histograms for Data Driven 
		   //                 From now on also useful for ttbar 
		   //                        **** 3 Aug 2013 ****
		   // ==============================================================================
                   // Njet >= 2 --------------------------------------------------------------------
                   if ( myNjet >= 2 && myNBtag <= 2 ) nHpreGe2 = nH ;      // Pretag
                   if ( myNjet >= 2 && myNBtag == 0 ) nH_idGe2 = nH + 1 ;  // 0-tag
                   if ( myNjet >= 2 && myNBtag == 1 ) nH_idGe2 = nH + 2 ;  // 1-tag
                   if ( myNjet >= 2 && myNBtag == 2 ) nH_idGe2 = nH + 3 ;  // 2-tag
                   // Njet = 2 ---------------------------------------------------------------------
                   if ( myNjet == 2 && myNBtag <= 2 ) nHpre = nH + 4 ;  // Pretag
                   if ( myNjet == 2 && myNBtag == 0 ) nH_id = nH + 5 ;  // 0-tag
                   if ( myNjet == 2 && myNBtag == 1 ) nH_id = nH + 6 ;  // 1-tag
                   if ( myNjet == 2 && myNBtag == 2 ) nH_id = nH + 7 ;  // 2-tag
                   // Njet = 3 ---------------------------------------------------------------------
                   if ( myNjet == 3 && myNBtag <= 2 ) nHpre = nH + 8 ;  // Pretag
                   if ( myNjet == 3 && myNBtag == 0 ) nH_id = nH + 9 ;  // 0-tag
                   if ( myNjet == 3 && myNBtag == 1 ) nH_id = nH +10 ;  // 1-tag
                   if ( myNjet == 3 && myNBtag == 2 ) nH_id = nH +11 ;  // 2-tag
                   // Njet = 4 ---------------------------------------------------------------------
                   if ( myNjet == 4 && myNBtag <= 2 ) nHpre = nH +12 ;  // Pretag
                   if ( myNjet == 4 && myNBtag == 0 ) nH_id = nH +13 ;  // 0-tag
                   if ( myNjet == 4 && myNBtag == 1 ) nH_id = nH +14 ;  // 1-tag
                   if ( myNjet == 4 && myNBtag == 2 ) nH_id = nH +15 ;  // 2-tag
                   // Njet = 5 ---------------------------------------------------------------------
                   if ( myNjet == 5 && myNBtag <= 2 ) nHpre = nH +16 ;  // Pretag
                   if ( myNjet == 5 && myNBtag == 0 ) nH_id = nH +17 ;  // 0-tag
                   if ( myNjet == 5 && myNBtag == 1 ) nH_id = nH +18 ;  // 1-tag
                   if ( myNjet == 5 && myNBtag == 2 ) nH_id = nH +19 ;  // 2-tag
                   // Njet>= 6 ---------------------------------------------------------------------
                   if ( myNjet >= 6 && myNBtag <= 2 ) nHpre = nH +20 ;  // Pretag
                   if ( myNjet >= 6 && myNBtag == 0 ) nH_id = nH +21 ;  // 0-tag
                   if ( myNjet >= 6 && myNBtag == 1 ) nH_id = nH +22 ;  // 1-tag
                   if ( myNjet >= 6 && myNBtag == 2 ) nH_id = nH +23 ;  // 2-tag
		   // ==============================================================================

		   //
		   // ==============================================================================
		   // 				    ttbar Data Driven 
		   // ==============================================================================
                   // Njet >= 2 --------------------------------------------------------------------
                   if ( myNjet >= 2 && myNBtag <= 2 ) nHttpreGe2 = nHtt ;      // Pretag
                   if ( myNjet >= 2 && myNBtag == 0 ) nHtt_idGe2 = nHtt + 1 ;  // 0-tag
                   if ( myNjet >= 2 && myNBtag == 1 ) nHtt_idGe2 = nHtt + 2 ;  // 1-tag
                   if ( myNjet >= 2 && myNBtag == 2 ) nHtt_idGe2 = nHtt + 3 ;  // 2-tag
                   // Njet = 2 ---------------------------------------------------------------------
                   if ( myNjet == 2 && myNBtag <= 2 ) nHttpre = nHtt + 4 ;  // Pretag
                   if ( myNjet == 2 && myNBtag == 0 ) nHtt_id = nHtt + 5 ;  // 0-tag
                   if ( myNjet == 2 && myNBtag == 1 ) nHtt_id = nHtt + 6 ;  // 1-tag
                   if ( myNjet == 2 && myNBtag == 2 ) nHtt_id = nHtt + 7 ;  // 2-tag
                   // Njet = 3 ---------------------------------------------------------------------
                   if ( myNjet == 3 && myNBtag <= 2 ) nHttpre = nHtt + 8 ;  // Pretag
                   if ( myNjet == 3 && myNBtag == 0 ) nHtt_id = nHtt + 9 ;  // 0-tag
                   if ( myNjet == 3 && myNBtag == 1 ) nHtt_id = nHtt +10 ;  // 1-tag
                   if ( myNjet == 3 && myNBtag == 2 ) nHtt_id = nHtt +11 ;  // 2-tag
                   // Njet = 4 ---------------------------------------------------------------------
                   if ( myNjet == 4 && myNBtag <= 2 ) nHttpre = nHtt +12 ;  // Pretag
                   if ( myNjet == 4 && myNBtag == 0 ) nHtt_id = nHtt +13 ;  // 0-tag
                   if ( myNjet == 4 && myNBtag == 1 ) nHtt_id = nHtt +14 ;  // 1-tag
                   if ( myNjet == 4 && myNBtag == 2 ) nHtt_id = nHtt +15 ;  // 2-tag
                   // Njet = 5 ---------------------------------------------------------------------
                   if ( myNjet == 5 && myNBtag <= 2 ) nHttpre = nHtt +16 ;  // Pretag
                   if ( myNjet == 5 && myNBtag == 0 ) nHtt_id = nHtt +17 ;  // 0-tag
                   if ( myNjet == 5 && myNBtag == 1 ) nHtt_id = nHtt +18 ;  // 1-tag
                   if ( myNjet == 5 && myNBtag == 2 ) nHtt_id = nHtt +19 ;  // 2-tag
                   // Njet>= 6 ---------------------------------------------------------------------
                   if ( myNjet >= 6 && myNBtag <= 2 ) nHttpre = nHtt +20 ;  // Pretag
                   if ( myNjet >= 6 && myNBtag == 0 ) nHtt_id = nHtt +21 ;  // 0-tag
                   if ( myNjet >= 6 && myNBtag == 1 ) nHtt_id = nHtt +22 ;  // 1-tag
                   if ( myNjet >= 6 && myNBtag == 2 ) nHtt_id = nHtt +23 ;  // 2-tag
		   // ==============================================================================
	

		   // ==============================================================================
                   // Fill Up histograms for ZDD-like studies (useful for ttDD)
		   // ==============================================================================
                   // MET vs Mll (jet,btag combination) - pretag needs to be filled irrespective to the tags
                   ((TH2D*)histo[i][nHpreGe2])->Fill( xVar, yVar, Weight);
                   ((TH2D*)histo[i][nH_idGe2])->Fill( xVar, yVar, Weight);
                   ((TH2D*)histo[i][nHpre])->Fill( xVar, yVar, Weight);
                   ((TH2D*)histo[i][nH_id])->Fill( xVar, yVar, Weight);
                   // Z like Mll counter
                   histo[i][nHpreGe2+30]->Fill(2.,Weight);
                   histo[i][nH_idGe2+30]->Fill(2.,Weight);
                   histo[i][nHpre+30]->Fill(2.,Weight);
                   histo[i][nH_id+30]->Fill(2.,Weight);
                   if (yVar > 60.) {
                                histo[i][nHpreGe2+30]->Fill(5.,Weight);
                                histo[i][nH_idGe2+30]->Fill(5.,Weight);
                                histo[i][nHpre+30]->Fill(5.,Weight);
                                histo[i][nH_id+30]->Fill(5.,Weight);
                   }
		   // Fill pt distributions
                   histo[i][nHpreGe2+120]->Fill(ptVar,Weight);
                   histo[i][nH_idGe2+120]->Fill(ptVar,Weight);
                   histo[i][nHpre+120]->Fill(ptVar,Weight);
                   histo[i][nH_id+120]->Fill(ptVar,Weight);
		   // Fill eta distributions
                   histo[i][nHpreGe2+180]->Fill(etaVar,Weight);
                   histo[i][nH_idGe2+180]->Fill(etaVar,Weight);
                   histo[i][nHpre+180]->Fill(etaVar,Weight);
                   histo[i][nH_id+180]->Fill(etaVar,Weight);
		   // Fill phi distributions
                   histo[i][nHpreGe2+240]->Fill(phiVar,Weight);
                   histo[i][nH_idGe2+240]->Fill(phiVar,Weight);
                   histo[i][nHpre+240]->Fill(phiVar,Weight);
                   histo[i][nH_id+240]->Fill(phiVar,Weight);
                   // Mll mass distribution
                   histo[i][nHpreGe2+60]->Fill( xVar, Weight);
                   histo[i][nH_idGe2+60]->Fill( xVar, Weight);
                   histo[i][nHpre+60]->Fill( xVar, Weight);
                   histo[i][nH_id+60]->Fill( xVar, Weight);
                   // ll pT distribution			
                   histo[i][nHpreGe2+90]->Fill(ptVar,Weight);
                   histo[i][nH_idGe2+90]->Fill(ptVar,Weight);
                   histo[i][nHpre+90]->Fill(ptVar,Weight);
                   histo[i][nH_id+90]->Fill(ptVar,Weight);
		   // Fill eta distributions
                   histo[i][nHpreGe2+150]->Fill(etaVar,Weight);
                   histo[i][nH_idGe2+150]->Fill(etaVar,Weight);
                   histo[i][nHpre+150]->Fill(etaVar,Weight);
                   histo[i][nH_id+150]->Fill(etaVar,Weight);
		   // Fill phi distributions
                   histo[i][nHpreGe2+210]->Fill(phiVar,Weight);
                   histo[i][nH_idGe2+210]->Fill(phiVar,Weight);
                   histo[i][nHpre+210]->Fill(phiVar,Weight);
                   histo[i][nH_id+210]->Fill(phiVar,Weight);
		   // ==============================================================================

		   // ==============================================================================
                   // Fill Up histograms for ttbar DD studies
		   // ==============================================================================
                   // Average pT(l+,l-) - pretag needs to be filled irrespective to the tags (OS: 1800-1823, SS: add 400)
                   histo[i][nHttpreGe2]->Fill( AvPTll, Weight);
                   histo[i][nHtt_idGe2]->Fill( AvPTll, Weight);
                   histo[i][nHttpre]->Fill( AvPTll, Weight);
                   histo[i][nHtt_id]->Fill( AvPTll, Weight);
                   // ttbar counters, x=2. (pTmiss>0.), x=5. (pTmiss>60.GeV) (OS: 1830-1853, SS: add 400)
                   histo[i][nHttpreGe2+30]->Fill(2.,Weight);
                   histo[i][nHtt_idGe2+30]->Fill(2.,Weight);
                   histo[i][nHttpre+30]->Fill(2.,Weight);
                   histo[i][nHtt_id+30]->Fill(2.,Weight);
                   if (yVar > 60.) {
                                histo[i][nHttpreGe2+30]->Fill(5.,Weight);
                                histo[i][nHtt_idGe2+30]->Fill(5.,Weight);
                                histo[i][nHttpre+30]->Fill(5.,Weight);
                                histo[i][nHtt_id+30]->Fill(5.,Weight);
                   }
                   // Mll mass distribution
                   histo[i][nHttpreGe2+60]->Fill( xVar, Weight);
                   histo[i][nHtt_idGe2+60]->Fill( xVar, Weight);
                   histo[i][nHttpre+60]->Fill( xVar, Weight);
                   histo[i][nHtt_id+60]->Fill( xVar, Weight);
                   // ttbar system pT distribution			
                   histo[i][nHttpreGe2+90]->Fill( PTtt, Weight);
                   histo[i][nHtt_idGe2+90]->Fill( PTtt, Weight);
                   histo[i][nHttpre+90]->Fill( PTtt, Weight);
                   histo[i][nHtt_id+90]->Fill( PTtt, Weight);
                   // Average pT(b,bbar) - pretag needs to be filled irrespective to the tags (OS: 1920-1943, SS: add 400)
                   histo[i][nHttpreGe2+120]->Fill( AvPTbb, Weight);
                   histo[i][nHtt_idGe2+120]->Fill( AvPTbb, Weight);
                   histo[i][nHttpre+120]->Fill( AvPTbb, Weight);
                   histo[i][nHtt_id+120]->Fill( AvPTbb, Weight);
	           // Fill eta distributions
                   histo[i][nHttpreGe2+150]->Fill( etaVar, Weight);
                   histo[i][nHtt_idGe2+150]->Fill( etaVar, Weight);
                   histo[i][nHttpre+150]->Fill( etaVar, Weight);
                   histo[i][nHtt_id+150]->Fill( etaVar, Weight);
                   // ttbar+jets system pT distribution			
                   histo[i][nHttpreGe2+180]->Fill( AllPTtt, Weight);
                   histo[i][nHtt_idGe2+180]->Fill( AllPTtt, Weight);
                   histo[i][nHttpre+180]->Fill( AllPTtt, Weight);
                   histo[i][nHtt_id+180]->Fill( AllPTtt, Weight);
		   // Fill phi distributions
                   histo[i][nHttpreGe2+210]->Fill( phiVar, Weight);
                   histo[i][nHtt_idGe2+210]->Fill( phiVar, Weight);
                   histo[i][nHttpre+210]->Fill( phiVar, Weight);
                   histo[i][nHtt_id+210]->Fill( phiVar, Weight);
                }
		// ==============================================================================


		// -------------------------
		// Event Topology Histograms
		// -------------------------
                // Leptons
                if(LeptonVec.size()>0){
                    // Lepton 1
		    histo[i][400]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		    histo[i][401]->Fill(LeptonVec[0].Eta(), Weight);
		    histo[i][402]->Fill(LeptonVec[0].Phi(), Weight);
                }		
                if(LeptonVec.size()>1){
                    // Lepton 2
		    histo[i][403]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		    histo[i][404]->Fill(LeptonVec[1].Eta(), Weight);
		    histo[i][405]->Fill(LeptonVec[1].Phi(), Weight);
                }		

		// Fill Only in case of 2 Leptons
                if( LeptonVec.size() == 2 ){
		    // Fill here positive and negative lepton distributions
		    for(Int_t ilep = 0; ilep < LeptonVec.size(); ++ilep){		    
			// Positive leptons
                       	if ( LeptonVec[ilep].isb < 0 ){
			    histo[i][592]->Fill(LeptonVec[ilep].Pt()/GeV, Weight);
			    histo[i][593]->Fill(LeptonVec[ilep].Eta(), Weight);
			    histo[i][594]->Fill(LeptonVec[ilep].Phi(), Weight);
			}
			// Negative leptons
                       	if ( LeptonVec[ilep].isb > 0 ){
			    histo[i][595]->Fill(LeptonVec[ilep].Pt()/GeV, Weight);
			    histo[i][596]->Fill(LeptonVec[ilep].Eta(), Weight);
			    histo[i][597]->Fill(LeptonVec[ilep].Phi(), Weight);
			}
		    }
		}

                // Jets
                if(MyGoodJetVec.size()>0){
                    // Jet 1
		    histo[i][406]->Fill(MyGoodJetVec[0].Pt()/GeV, Weight);
		    histo[i][407]->Fill(MyGoodJetVec[0].Eta(), Weight);
		    histo[i][408]->Fill(MyGoodJetVec[0].Phi(), Weight);
                }
                if(MyGoodJetVec.size()>1){
                    // Jet 2
		    histo[i][409]->Fill(MyGoodJetVec[1].Pt()/GeV, Weight);
		    histo[i][410]->Fill(MyGoodJetVec[1].Eta(), Weight);
		    histo[i][411]->Fill(MyGoodJetVec[1].Phi(), Weight);
                }


                // Event Properties
    		histo[i][412]->Fill(Sphericity,Weight);
    		histo[i][413]->Fill(Aplanarity,Weight);
    		histo[i][414]->Fill(Planarity,Weight);

                if(LeptonVec.size()>1 && MyGoodJetVec.size()>1 ){

			TLorentzVector  mylb_lp,     mylb_ln;
			double      myCosMlb_lp, myCosMlb_ln;
			double           df_mlb, mt, mW;			

                        // ------------------------------------------
			// Calculate Mlb.............................
                        // ------------------------------------------
 			mylb_lp  = (RecLepP + RecB);
 			mylb_ln  = (RecLepN + RecBbar);
                        //..l+
    			histo[i][415]->Fill( mylb_lp.M()/GeV,Weight);
    			histo[i][430]->Fill( (mylb_lp.M()/GeV)*(mylb_lp.M()/GeV),Weight);
                        //..l-
    			histo[i][416]->Fill( mylb_ln.M()/GeV,Weight);
    			histo[i][431]->Fill( (mylb_ln.M()/GeV)*(mylb_ln.M()/GeV),Weight);
                        //..l+ and l-
    			histo[i][417]->Fill( mylb_lp.M()/GeV,Weight);
    			histo[i][417]->Fill( mylb_ln.M()/GeV,Weight);
    			histo[i][432]->Fill( (mylb_lp.M()/GeV)*(mylb_lp.M()/GeV),Weight);
    			histo[i][432]->Fill( (mylb_ln.M()/GeV)*(mylb_ln.M()/GeV),Weight);

 			// Reconstructed information
                        histo[i][574]->Fill(Ml1b1,Weight);
                        histo[i][574]->Fill(Ml2b2,Weight);
                        histo[i][575]->Fill(Ml2b1,Weight);
                        histo[i][575]->Fill(Ml1b2,Weight);
                        histo[i][576]->Fill(Ml1b1+Ml2b2-Ml2b1-Ml1b2,Weight);

 			// Truth information
                        histo[i][577]->Fill(Ml1b1_truth,Weight);
                        histo[i][577]->Fill(Ml2b2_truth,Weight);
                        histo[i][578]->Fill(Ml2b1_truth,Weight);
                        histo[i][578]->Fill(Ml1b2_truth,Weight);
                        histo[i][579]->Fill(Ml1b1_truth+Ml2b2_truth-Ml2b1_truth-Ml1b2_truth,Weight);

                        // ------------------------------------------
			// Calculate Cos from Mlb....................
                        // ------------------------------------------
  			mt = mt_UserValue;
  			mW = mW_UserValue;
			//...l+
 			df_mlb      =  mylb_lp.M();
			myCosMlb_lp = ((2*df_mlb*df_mlb)/((mt*mt)-(mW*mW)))-1;			
    			histo[i][418]->Fill(myCosMlb_lp,Weight);
			if( HasSolution > 0 ){
    				histo[i][349]->Fill(myCosMlb_lp,Weight);
			}
			//    ...2 bins...
    			histo[i][421]->Fill(myCosMlb_lp,Weight);
			if( HasSolution > 0 ){
    				histo[i][352]->Fill(myCosMlb_lp,Weight);
			}
			//...l-
 			df_mlb      =  mylb_ln.M();
			myCosMlb_ln = ((2*df_mlb*df_mlb)/((mt*mt)-(mW*mW)))-1;			
    			histo[i][419]->Fill(myCosMlb_ln,Weight);
			if( HasSolution > 0 ){
    				histo[i][350]->Fill(myCosMlb_ln,Weight);
			}
			//    ...2 bins...
    			histo[i][422]->Fill(myCosMlb_ln,Weight);
			if( HasSolution > 0 ){
    				histo[i][353]->Fill(myCosMlb_ln,Weight);
			}
			//...l+ and l-
    			histo[i][420]->Fill(myCosMlb_lp,Weight);
    			histo[i][420]->Fill(myCosMlb_ln,Weight);
			if( HasSolution > 0 ){
    				histo[i][351]->Fill(myCosMlb_lp,Weight);
    				histo[i][351]->Fill(myCosMlb_ln,Weight);
			}
			//    ...2 bins...
    			histo[i][423]->Fill(myCosMlb_lp,Weight);
    			histo[i][423]->Fill(myCosMlb_ln,Weight);
			if( HasSolution > 0 ){
    				histo[i][354]->Fill(myCosMlb_lp,Weight);
    				histo[i][354]->Fill(myCosMlb_ln,Weight);
			}

	                //____4 bins__________________
                        Double_t   ynew = 0.587401052;
                        //      ....(l+,b)....
			Double_t ctheta = myCosMlb_lp;
     			if(ctheta < -ynew && ctheta >= -1. )   	{  histo[i][424]->Fill(-0.75,Weight); histo[i][426]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  			{  histo[i][424]->Fill(-0.25,Weight); histo[i][426]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) 			{  histo[i][424]->Fill( 0.25,Weight); histo[i][426]->Fill( 0.25,Weight); }
     			else if(ctheta <= 1. )                  {  histo[i][424]->Fill( 0.75,Weight); histo[i][426]->Fill( 0.75,Weight); }
			if( HasSolution > 0 ){
     				if(ctheta < -ynew && ctheta >= -1. )   	{  histo[i][355]->Fill(-0.75,Weight); histo[i][357]->Fill(-0.75,Weight); }
     				else if(ctheta < 0. )  			{  histo[i][355]->Fill(-0.25,Weight); histo[i][357]->Fill(-0.25,Weight); }
     				else if(ctheta < ynew) 			{  histo[i][355]->Fill( 0.25,Weight); histo[i][357]->Fill( 0.25,Weight); }
     				else if(ctheta <= 1. )                  {  histo[i][355]->Fill( 0.75,Weight); histo[i][357]->Fill( 0.75,Weight); }
			}
                        //      ....(l-,bbar)....
			ctheta = myCosMlb_ln;
     			if(ctheta < -ynew && ctheta >= -1. )    {  histo[i][425]->Fill(-0.75,Weight); histo[i][426]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  			{  histo[i][425]->Fill(-0.25,Weight); histo[i][426]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) 			{  histo[i][425]->Fill( 0.25,Weight); histo[i][426]->Fill( 0.25,Weight); }
     			else if(ctheta <= 1. )                  {  histo[i][425]->Fill( 0.75,Weight); histo[i][426]->Fill( 0.75,Weight); }	
			if( HasSolution > 0 ){
     				if(ctheta < -ynew && ctheta >= -1. )   	{  histo[i][356]->Fill(-0.75,Weight); histo[i][357]->Fill(-0.75,Weight); }
     				else if(ctheta < 0. )  			{  histo[i][356]->Fill(-0.25,Weight); histo[i][357]->Fill(-0.25,Weight); }
     				else if(ctheta < ynew) 			{  histo[i][356]->Fill( 0.25,Weight); histo[i][357]->Fill( 0.25,Weight); }
     				else if(ctheta <= 1. )                  {  histo[i][356]->Fill( 0.75,Weight); histo[i][357]->Fill( 0.75,Weight); }
			}

	                //____4 bins__________________NO LIMITS ON RANGE_________________
                        //      ....(l+,b)....
			ctheta = myCosMlb_lp;
     			if(ctheta < -ynew)     {  histo[i][427]->Fill(-0.75,Weight); histo[i][429]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][427]->Fill(-0.25,Weight); histo[i][429]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][427]->Fill( 0.25,Weight); histo[i][429]->Fill( 0.25,Weight); }
     			else                   {  histo[i][427]->Fill( 0.75,Weight); histo[i][429]->Fill( 0.75,Weight); }
			if( HasSolution > 0 ){
     				if(ctheta < -ynew)     {  histo[i][358]->Fill(-0.75,Weight); histo[i][360]->Fill(-0.75,Weight); }
     				else if(ctheta < 0. )  {  histo[i][358]->Fill(-0.25,Weight); histo[i][360]->Fill(-0.25,Weight); }
     				else if(ctheta < ynew) {  histo[i][358]->Fill( 0.25,Weight); histo[i][360]->Fill( 0.25,Weight); }
     				else                   {  histo[i][358]->Fill( 0.75,Weight); histo[i][360]->Fill( 0.75,Weight); }
			}
                        //      ....(l-,bbar)....
			ctheta = myCosMlb_ln;
     			if(ctheta < -ynew)     {  histo[i][428]->Fill(-0.75,Weight); histo[i][429]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][428]->Fill(-0.25,Weight); histo[i][429]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][428]->Fill( 0.25,Weight); histo[i][429]->Fill( 0.25,Weight); }
     			else                   {  histo[i][428]->Fill( 0.75,Weight); histo[i][429]->Fill( 0.75,Weight); }
			if( HasSolution > 0 ){
     				if(ctheta < -ynew)     {  histo[i][359]->Fill(-0.75,Weight); histo[i][360]->Fill(-0.75,Weight); }
     				else if(ctheta < 0. )  {  histo[i][359]->Fill(-0.25,Weight); histo[i][360]->Fill(-0.25,Weight); }
     				else if(ctheta < ynew) {  histo[i][359]->Fill( 0.25,Weight); histo[i][360]->Fill( 0.25,Weight); }
     				else                   {  histo[i][359]->Fill( 0.75,Weight); histo[i][360]->Fill( 0.75,Weight); }
			}
		}


		// -------------------------
                // Vertices and tracks
		// -------------------------
	        for(Int_t l = 0; l < Vtx.size(); ++l)
	        {
                	histo[i][5]->Fill(Vtx[l].X(), Weight);
                	histo[i][6]->Fill(Vtx[l].Y(), Weight);
                	histo[i][7]->Fill(Vtx[l].Z(), Weight);
                }

                // Make sure we have 2 leptons
                if( LeptonVec.size() >=2 )
                {
	 	   TVector3 v0( LeptonVec[0].X(), LeptonVec[0].Y(), 0. );
	 	   TVector3 v1( LeptonVec[1].X(), LeptonVec[1].Y(), 0. );
                   Double_t  DelPhi = v0.Angle(v1);

                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                       New histograms for SS-OS Method: Full Etmis                             ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                // 
                //   ==== OS, Full ===================================================================================
	             if( ( LeptonVec[0].isb )*( LeptonVec[1].isb ) < 0 )
	             {
		        histo[i][100]->Fill(MyGoodJetVec.size(), Weight);
		        histo[i][101]->Fill(BTaggedJetVec.size(), Weight);
		        histo[i][102]->Fill(MissPt/GeV, Weight);
		        histo[i][103]->Fill(DelPhi, Weight);
		        histo[i][104]->Fill(ll.M()/GeV, Weight);
		        histo[i][105]->Fill(Ht/GeV, Weight);

		        histo[i][598]->Fill(ll.Pz()/GeV, Weight);
		        histo[i][599]->Fill(ll.Pt()/GeV, Weight);

                            //.........etas, phis and pts.........................................lepton 1............
		        histo[i][106]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        histo[i][107]->Fill(LeptonVec[0].Phi(), Weight);
		        histo[i][108]->Fill(LeptonVec[0].Eta(), Weight);
                            //.........etas, phis and pts.........................................lepton 2............
		        histo[i][109]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        histo[i][110]->Fill(LeptonVec[1].Phi(), Weight);
		        histo[i][111]->Fill(LeptonVec[1].Eta(), Weight);
                            //.........Mll versus Etmis...............................................................
//                        ((TH2D*)histo[i][124])->Fill(ll.M()/GeV, MissPt/GeV, Weight);
                            //.........Ht versus Etmis...............................................................
//                        ((TH2D*)histo[i][126])->Fill(Ht/GeV, MissPt/GeV, Weight);

                        // ------------------------------------------------------------------------------------------------------
                        //........................Mll versus Etmis Counters......................................................
                        // ------------------------------------------------------------------------------------------------------
                        if( fabs(ll.M()/GeV-91.) < 10. ){
                                if( (MissPt >  30.*GeV) ) histo[i][188]->Fill(1.,Weight);
                                if( (MissPt >  35.*GeV) ) histo[i][188]->Fill(2.,Weight);
                                if( (MissPt >  25.*GeV) ) histo[i][188]->Fill(3.,Weight);
                        } else {
                                if( (MissPt >  60.*GeV) && ( (ll.M()/GeV-91.)<= -10. ) ) histo[i][188]->Fill(0.,Weight);
                                if( (MissPt >  60.*GeV) && ( (ll.M()/GeV-91.)>= +10. ) ) histo[i][188]->Fill(0.,Weight);
                  	}
                        // ------------------------------------------------------------------------------------------------------

                        // Do OS distributions for Control Region
                        if ( MissPt/GeV > 30. && fabs(ll.M()/GeV-91.) < 10. )
                        {
  		        	histo[i][130]->Fill(MyGoodJetVec.size(), Weight);
		        	histo[i][131]->Fill(BTaggedJetVec.size(), Weight);
		        	histo[i][132]->Fill(MissPt/GeV, Weight);
		        	histo[i][133]->Fill(DelPhi, Weight);
		        	histo[i][134]->Fill(ll.M()/GeV, Weight);
		        	histo[i][135]->Fill(Ht/GeV, Weight);
                            	//.........etas, phis and pts.........................................lepton 1............
		        	histo[i][136]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        	histo[i][137]->Fill(LeptonVec[0].Phi(), Weight);
		        	histo[i][138]->Fill(LeptonVec[0].Eta(), Weight);
                            	//.........etas, phis and pts.........................................lepton 2............
		        	histo[i][139]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        	histo[i][140]->Fill(LeptonVec[1].Phi(), Weight);
		        	histo[i][141]->Fill(LeptonVec[1].Eta(), Weight);
                                    //.........Mll versus Etmis...............................................................
        //                        ((TH2D*)histo[i][154])->Fill(ll.M()/GeV, MissPt/GeV, Weight);
                                    //.........Ht versus Etmis...............................................................
        //                        ((TH2D*)histo[i][156])->Fill(Ht/GeV, MissPt/GeV, Weight);

                               // W Polarizations...........................................
                               //____2 entries per event_____
                               histo[i][190]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
                               histo[i][190]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
                               //____4 entries per event_____
                               Double_t   ynew = 0.587401052;
                               //    ....(l+,b)....
                               Double_t ctheta = RecCos_LepP_B_BoostedtoWp;
                               if(ctheta < -ynew)     {  histo[i][191]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][191]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][191]->Fill( 0.25,Weight); }
                               else                   {  histo[i][191]->Fill( 0.75,Weight); }
                               //    ....(l-,bbar)....
                               ctheta = RecCos_LepN_Bbar_BoostedtoWn;
                               if(ctheta < -ynew)     {  histo[i][191]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][191]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][191]->Fill( 0.25,Weight); }
                               else                   {  histo[i][191]->Fill( 0.75,Weight); }

                        }

                        // Do OS distributions for Signal Region 
                        if ( MissPt/GeV > 60. && fabs(ll.M()/GeV-91.) >= 10. )
                        {
  		        	histo[i][160]->Fill(MyGoodJetVec.size(), Weight);
		        	histo[i][161]->Fill(BTaggedJetVec.size(), Weight);
		        	histo[i][162]->Fill(MissPt/GeV, Weight);
		        	histo[i][163]->Fill(DelPhi, Weight);
		        	histo[i][164]->Fill(ll.M()/GeV, Weight);
		        	histo[i][165]->Fill(Ht/GeV, Weight);
                            	//.........etas, phis and pts.........................................lepton 1............
		        	histo[i][166]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        	histo[i][167]->Fill(LeptonVec[0].Phi(), Weight);
		        	histo[i][168]->Fill(LeptonVec[0].Eta(), Weight);
                            	//.........etas, phis and pts.........................................lepton 2............
		        	histo[i][169]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        	histo[i][170]->Fill(LeptonVec[1].Phi(), Weight);
		        	histo[i][171]->Fill(LeptonVec[1].Eta(), Weight);

                               // W Polarizations...........................................
                               //____2 entries per event_____
                               histo[i][194]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
                               histo[i][194]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
                               //____4 entries per event_____
                               Double_t   ynew = 0.587401052;
                               //    ....(l+,b)....
                               Double_t ctheta = RecCos_LepP_B_BoostedtoWp;
                               if(ctheta < -ynew)     {  histo[i][195]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][195]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][195]->Fill( 0.25,Weight); }
                               else                   {  histo[i][195]->Fill( 0.75,Weight); }
                               //    ....(l-,bbar)....
                               ctheta = RecCos_LepN_Bbar_BoostedtoWn;
                               if(ctheta < -ynew)     {  histo[i][195]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][195]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][195]->Fill( 0.25,Weight); }
                               else                   {  histo[i][195]->Fill( 0.75,Weight); }

                        }

                     }

                //   ==== SS, Full ===================================================================================
	             if( ( LeptonVec[0].isb )*( LeptonVec[1].isb ) > 0 )
	             {
		        histo[i][112]->Fill(MyGoodJetVec.size(), Weight);
		        histo[i][113]->Fill(BTaggedJetVec.size(), Weight);
		        histo[i][114]->Fill(MissPt/GeV, Weight);
		        histo[i][115]->Fill(DelPhi, Weight);
		        histo[i][116]->Fill(ll.M()/GeV, Weight);
		        histo[i][117]->Fill(Ht/GeV, Weight);
                            //.........etas, phis and pts.........................................lepton 1............
		        histo[i][118]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        histo[i][119]->Fill(LeptonVec[0].Phi(), Weight);
		        histo[i][120]->Fill(LeptonVec[0].Eta(), Weight);
                            //.........etas, phis and pts.........................................lepton 2............
		        histo[i][121]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        histo[i][122]->Fill(LeptonVec[1].Phi(), Weight);
		        histo[i][123]->Fill(LeptonVec[1].Eta(), Weight);

                            //.........Mll versus Etmis...............................................................
//                        ((TH2D*)histo[i][125])->Fill(ll.M()/GeV, MissPt/GeV, Weight);
                            //.........Ht versus Etmis...............................................................
//                        ((TH2D*)histo[i][127])->Fill(Ht/GeV, MissPt/GeV, Weight);

                        // ------------------------------------------------------------------------------------------------------
                        // .......................Mll versus Etmis Counters......................................................
                        // ------------------------------------------------------------------------------------------------------
                        if( fabs(ll.M()/GeV-91.) < 10. ){
                                if( (MissPt >  30.*GeV) ) histo[i][189]->Fill(1.,Weight);
                                if( (MissPt >  35.*GeV) ) histo[i][189]->Fill(2.,Weight);
                                if( (MissPt >  25.*GeV) ) histo[i][189]->Fill(3.,Weight);
                        } else {
                                if( (MissPt >  60.*GeV) && ( (ll.M()/GeV-91.)<= -10. ) ) histo[i][189]->Fill(0.,Weight);
                                if( (MissPt >  60.*GeV) && ( (ll.M()/GeV-91.)>= +10. ) ) histo[i][189]->Fill(0.,Weight);
                  	}
                        // ------------------------------------------------------------------------------------------------------

                        // Do SS distributions for Control Region 
                        if ( MissPt/GeV > 30. && fabs(ll.M()/GeV-91.) < 10. )
                        {
  		        	histo[i][142]->Fill(MyGoodJetVec.size(), Weight);
		        	histo[i][143]->Fill(BTaggedJetVec.size(), Weight);
		        	histo[i][144]->Fill(MissPt/GeV, Weight);
		        	histo[i][145]->Fill(DelPhi, Weight);
		        	histo[i][146]->Fill(ll.M()/GeV, Weight);
		        	histo[i][147]->Fill(Ht/GeV, Weight);
                            	//.........etas, phis and pts.........................................lepton 1............
		        	histo[i][148]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        	histo[i][149]->Fill(LeptonVec[0].Phi(), Weight);
		        	histo[i][150]->Fill(LeptonVec[0].Eta(), Weight);
                            	//.........etas, phis and pts.........................................lepton 2............
		        	histo[i][151]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        	histo[i][152]->Fill(LeptonVec[1].Phi(), Weight);
		        	histo[i][153]->Fill(LeptonVec[1].Eta(), Weight);

                                    //.........Mll versus Etmis...............................................................
        //                        ((TH2D*)histo[i][155])->Fill(ll.M()/GeV, MissPt/GeV, Weight);
                                    //.........Ht versus Etmis...............................................................
        //                        ((TH2D*)histo[i][157])->Fill(Ht/GeV, MissPt/GeV, Weight);

                               // W Polarizations...........................................
                               //____2 entries per event_____
                               histo[i][192]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
                               histo[i][192]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
                               //____4 entries per event_____
                               Double_t   ynew = 0.587401052;
                               //    ....(l+,b)....
                               Double_t ctheta = RecCos_LepP_B_BoostedtoWp;
                               if(ctheta < -ynew)     {  histo[i][193]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][193]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][193]->Fill( 0.25,Weight); }
                               else                   {  histo[i][193]->Fill( 0.75,Weight); }
                               //    ....(l-,bbar)....
                               ctheta = RecCos_LepN_Bbar_BoostedtoWn;
                               if(ctheta < -ynew)     {  histo[i][193]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][193]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][193]->Fill( 0.25,Weight); }
                               else                   {  histo[i][193]->Fill( 0.75,Weight); }

                        }

                        // Do SS distributions for Signal Region 
                        if ( MissPt/GeV > 60. && fabs(ll.M()/GeV-91.) >= 10. )
                        {
  		        	histo[i][172]->Fill(MyGoodJetVec.size(), Weight);
		        	histo[i][173]->Fill(BTaggedJetVec.size(), Weight);
		        	histo[i][174]->Fill(MissPt/GeV, Weight);
		        	histo[i][175]->Fill(DelPhi, Weight);
		        	histo[i][176]->Fill(ll.M()/GeV, Weight);
		        	histo[i][177]->Fill(Ht/GeV, Weight);
                            	//.........etas, phis and pts.........................................lepton 1............
		        	histo[i][178]->Fill(LeptonVec[0].Pt()/GeV, Weight);
		        	histo[i][179]->Fill(LeptonVec[0].Phi(), Weight);
		        	histo[i][180]->Fill(LeptonVec[0].Eta(), Weight);
                            	//.........etas, phis and pts.........................................lepton 2............
		        	histo[i][181]->Fill(LeptonVec[1].Pt()/GeV, Weight);
		        	histo[i][182]->Fill(LeptonVec[1].Phi(), Weight);
		        	histo[i][183]->Fill(LeptonVec[1].Eta(), Weight);
                
                               // W Polarizations...........................................
                               //____2 entries per event_____
                               histo[i][196]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
                               histo[i][196]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
                               //____4 entries per event_____
                               Double_t   ynew = 0.587401052;
                               //    ....(l+,b)....
                               Double_t ctheta = RecCos_LepP_B_BoostedtoWp;
                               if(ctheta < -ynew)     {  histo[i][197]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][197]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][197]->Fill( 0.25,Weight); }
                               else                   {  histo[i][197]->Fill( 0.75,Weight); }
                               //    ....(l-,bbar)....
                               ctheta = RecCos_LepN_Bbar_BoostedtoWn;
                               if(ctheta < -ynew)     {  histo[i][197]->Fill(-0.75,Weight); }
                               else if(ctheta < 0. )  {  histo[i][197]->Fill(-0.25,Weight); }
                               else if(ctheta < ynew) {  histo[i][197]->Fill( 0.25,Weight); }
                               else                   {  histo[i][197]->Fill( 0.75,Weight); }

                        }

                     }


	        }
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		// ::                          New histograms for SS-OS Method                                      ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


		// truth reconstructed information.....................................
		if ( TruthHasSolution > 0 ){


			TLorentzVector  mylb_lp,     mylb_ln;
			double      myCosMlb_lp, myCosMlb_ln;
			double           df_mlb, mt, mW;			

                        // ------------------------------------------
			// Calculate Mlb.............................
                        // ------------------------------------------
 			mylb_lp  = (TruthLepP + TruthB);
 			mylb_ln  = (TruthLepN + TruthBbar);
                        //..l+
    			histo[i][261]->Fill( mylb_lp.M()/GeV,Weight);
    			histo[i][264]->Fill( (mylb_lp.M()/GeV)*(mylb_lp.M()/GeV),Weight);
                        //..l-
    			histo[i][262]->Fill( mylb_ln.M()/GeV,Weight);
    			histo[i][265]->Fill( (mylb_ln.M()/GeV)*(mylb_ln.M()/GeV),Weight);
                        //..l+ and l-
    			histo[i][263]->Fill( mylb_lp.M()/GeV,Weight);
    			histo[i][263]->Fill( mylb_ln.M()/GeV,Weight);
    			histo[i][266]->Fill( (mylb_lp.M()/GeV)*(mylb_lp.M()/GeV),Weight);
    			histo[i][266]->Fill( (mylb_ln.M()/GeV)*(mylb_ln.M()/GeV),Weight);

                        // ------------------------------------------
			// Calculate Cos from Mlb....................
                        // ------------------------------------------
  			mt = mt_UserValue;
  			mW = mW_UserValue;
			//...l+
 			df_mlb      =  mylb_lp.M();
			myCosMlb_lp = ((2*df_mlb*df_mlb)/((mt*mt)-(mW*mW)))-1;			
    			histo[i][249]->Fill(myCosMlb_lp,Weight);
			//    ...2 bins...
    			histo[i][252]->Fill(myCosMlb_lp,Weight);
			//...l-
 			df_mlb      =  mylb_ln.M();
			myCosMlb_ln = ((2*df_mlb*df_mlb)/((mt*mt)-(mW*mW)))-1;			
    			histo[i][250]->Fill(myCosMlb_ln,Weight);
			//    ...2 bins...
    			histo[i][253]->Fill(myCosMlb_ln,Weight);
			//...l+ and l-
    			histo[i][251]->Fill(myCosMlb_lp,Weight);
    			histo[i][251]->Fill(myCosMlb_ln,Weight);
			//    ...2 bins...
    			histo[i][254]->Fill(myCosMlb_lp,Weight);
    			histo[i][254]->Fill(myCosMlb_ln,Weight);

	                //____4 bins__________________
                        Double_t   ynew = 0.587401052;
                        //      ....(l+,b)....
			Double_t ctheta = myCosMlb_lp;
     			if(ctheta < -ynew && ctheta >= -1. )   	{  histo[i][255]->Fill(-0.75,Weight); histo[i][257]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  			{  histo[i][255]->Fill(-0.25,Weight); histo[i][257]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) 			{  histo[i][255]->Fill( 0.25,Weight); histo[i][257]->Fill( 0.25,Weight); }
     			else if(ctheta <= 1. )                  {  histo[i][255]->Fill( 0.75,Weight); histo[i][257]->Fill( 0.75,Weight); }
                        //      ....(l-,bbar)....
			ctheta = myCosMlb_ln;
     			if(ctheta < -ynew && ctheta >= -1. )    {  histo[i][256]->Fill(-0.75,Weight); histo[i][257]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  			{  histo[i][256]->Fill(-0.25,Weight); histo[i][257]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) 			{  histo[i][256]->Fill( 0.25,Weight); histo[i][257]->Fill( 0.25,Weight); }
     			else if(ctheta <= 1. )                  {  histo[i][256]->Fill( 0.75,Weight); histo[i][257]->Fill( 0.75,Weight); }	

	                //____4 bins__________________NO LIMITS ON RANGE_________________
                        //      ....(l+,b)....
			ctheta = myCosMlb_lp;
     			if(ctheta < -ynew)     {  histo[i][258]->Fill(-0.75,Weight); histo[i][260]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][258]->Fill(-0.25,Weight); histo[i][260]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][258]->Fill( 0.25,Weight); histo[i][260]->Fill( 0.25,Weight); }
     			else                   {  histo[i][258]->Fill( 0.75,Weight); histo[i][260]->Fill( 0.75,Weight); }
                        //      ....(l-,bbar)....
			ctheta = myCosMlb_ln;
     			if(ctheta < -ynew)     {  histo[i][259]->Fill(-0.75,Weight); histo[i][260]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][259]->Fill(-0.25,Weight); histo[i][260]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][259]->Fill( 0.25,Weight); histo[i][260]->Fill( 0.25,Weight); }
     			else                   {  histo[i][259]->Fill( 0.75,Weight); histo[i][260]->Fill( 0.75,Weight); }

			// --------------------------------
			// information from matched leptons
			// --------------------------------
			// Neutrinos
			histo[i][200]->Fill(TruthNeu.Pt()/GeV, Weight);
			histo[i][201]->Fill(TruthNeu.E()/GeV, Weight);
			histo[i][202]->Fill(TruthNeubar.Pt()/GeV, Weight);
			histo[i][203]->Fill(TruthNeubar.E()/GeV, Weight);

                        //____Mass PLots_____
			histo[i][210]->Fill(           TruthWp.M()/GeV, Weight);
			histo[i][211]->Fill(           TruthWn.M()/GeV, Weight);
			histo[i][212]->Fill(            TruthT.M()/GeV, Weight);
			histo[i][213]->Fill(         TruthTbar.M()/GeV, Weight);
			histo[i][214]->Fill((TruthT+TruthTbar).M()/GeV, Weight);

                        //____Pt PLots_____
			histo[i][215]->Fill(           TruthWp.Pt()/GeV, Weight);
			histo[i][216]->Fill(           TruthWn.Pt()/GeV, Weight);
			histo[i][217]->Fill(            TruthT.Pt()/GeV, Weight);
			histo[i][218]->Fill(         TruthTbar.Pt()/GeV, Weight);
			histo[i][219]->Fill((TruthT+TruthTbar).Pt()/GeV, Weight);

                        //____Eta PLots_____
			histo[i][220]->Fill(           TruthWp.Eta(), Weight);
			histo[i][221]->Fill(           TruthWn.Eta(), Weight);
			histo[i][222]->Fill(            TruthT.Eta(), Weight);
			histo[i][223]->Fill(         TruthTbar.Eta(), Weight);
			histo[i][224]->Fill((TruthT+TruthTbar).Eta(), Weight);


			// truth spin correlations
	                //___cos(l+)cos(l-)________________
			histo[i][230]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][234]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
	                //___cos(b)cos(l-)________________
			histo[i][231]->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][235]->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
	                //___cos(l+)cos(bbar)________________
			histo[i][232]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][236]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar, Weight);
			//___cos(l)cos(b)________________
			histo[i][233]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][237]->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][233]->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][237]->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar, Weight);
	
			// W polarizations
	                //___cos(l+,b)________________
			histo[i][240]->Fill(TruthCos_LepP_B_BoostedtoWp, Weight);
			histo[i][243]->Fill(TruthCos_LepP_B_BoostedtoWp, Weight);
	                //___cos(l-,bbar)_____________
			histo[i][241]->Fill(TruthCos_LepN_Bbar_BoostedtoWn, Weight);
			histo[i][244]->Fill(TruthCos_LepN_Bbar_BoostedtoWn, Weight);
	                //____2 entries per event_____
			histo[i][242]->Fill(TruthCos_LepP_B_BoostedtoWp, Weight);
			histo[i][245]->Fill(TruthCos_LepP_B_BoostedtoWp, Weight);
			histo[i][242]->Fill(TruthCos_LepN_Bbar_BoostedtoWn, Weight);
			histo[i][245]->Fill(TruthCos_LepN_Bbar_BoostedtoWn, Weight);

	                //____4 bins__________________
                        ynew = 0.587401052;
                        //      ....(l+,b)....
			ctheta = TruthCos_LepP_B_BoostedtoWp;
     			if(ctheta < -ynew)     {  histo[i][246]->Fill(-0.75,Weight); histo[i][248]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][246]->Fill(-0.25,Weight); histo[i][248]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][246]->Fill( 0.25,Weight); histo[i][248]->Fill( 0.25,Weight); }
     			else                   {  histo[i][246]->Fill( 0.75,Weight); histo[i][248]->Fill( 0.75,Weight); }
                        //      ....(l-,bbar)....
			ctheta = TruthCos_LepN_Bbar_BoostedtoWn;
     			if(ctheta < -ynew)     {  histo[i][247]->Fill(-0.75,Weight); histo[i][248]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][247]->Fill(-0.25,Weight); histo[i][248]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][247]->Fill( 0.25,Weight); histo[i][248]->Fill( 0.25,Weight); }
     			else                   {  histo[i][247]->Fill( 0.75,Weight); histo[i][248]->Fill( 0.75,Weight); }	
		}


		// reconstructed information...........................................
		if( HasSolution > 0 ){
			histo[i][300]->Fill(Neutrino.Pt()/GeV, Weight);
			histo[i][301]->Fill(Neutrino.E()/GeV, Weight);
			histo[i][302]->Fill(Antineutrino.Pt()/GeV, Weight);
			histo[i][303]->Fill(Antineutrino.E()/GeV, Weight);

                        //____Mass PLots_____
			histo[i][310]->Fill(           RecWp.M()/GeV, Weight);
			histo[i][311]->Fill(           RecWn.M()/GeV, Weight);
			histo[i][312]->Fill(            RecT.M()/GeV, Weight);
			histo[i][313]->Fill(         RecTbar.M()/GeV, Weight);
			histo[i][314]->Fill(  (RecT+RecTbar).M()/GeV, Weight);
			histo[i][325]->Fill(        RecHiggs.M()/GeV, Weight);
			//samor
			histo[i][361]->Fill(        RecMassHiggsJet1/GeV, Weight);
			histo[i][362]->Fill(        RecMassHiggsJet2/GeV, Weight);
			// Mass Higgs From the 2 jets -> 2 entries!! 
			histo[i][363]->Fill(        RecMassHiggsJet1/GeV, Weight);
			histo[i][363]->Fill(        RecMassHiggsJet2/GeV, Weight);

                        //____Pt PLots_____
			histo[i][315]->Fill(           RecWp.Pt()/GeV, Weight);
			histo[i][316]->Fill(           RecWn.Pt()/GeV, Weight);
			histo[i][317]->Fill(            RecT.Pt()/GeV, Weight);
			histo[i][318]->Fill(         RecTbar.Pt()/GeV, Weight);
			histo[i][319]->Fill(  (RecT+RecTbar).Pt()/GeV, Weight);
			histo[i][326]->Fill(        RecHiggs.Pt()/GeV, Weight);

			histo[i][364]->Fill(  RecHiggsB1.DeltaR(RecHiggsB2), Weight);
			histo[i][365]->Fill(         -log(RecProbTotal_ttH), Weight);

                        //____Eta PLots_____
			histo[i][320]->Fill(           RecWp.Eta(), Weight);
			histo[i][321]->Fill(           RecWn.Eta(), Weight);
			histo[i][322]->Fill(            RecT.Eta(), Weight);
			histo[i][323]->Fill(         RecTbar.Eta(), Weight);
			histo[i][324]->Fill(  (RecT+RecTbar).Eta(), Weight);
			histo[i][327]->Fill(        RecHiggs.Eta(), Weight);


			// Reco spin correlations
	                //___cos(l+)cos(l-)________________
			histo[i][330]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][334]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
	                //___cos(b)cos(l-)________________
			histo[i][331]->Fill(RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][335]->Fill(RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
	                //___cos(l+)cos(bbar)________________
			histo[i][332]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][336]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
			//___cos(l)cos(b)________________
			histo[i][333]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][337]->Fill(RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
			histo[i][333]->Fill(RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
			histo[i][337]->Fill(RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
	
			// W polarizations
	                //___cos(l+,b)________________
			histo[i][340]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
			histo[i][343]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
	                //___cos(l-,bbar)_____________
			histo[i][341]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
			histo[i][344]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);

	                //____2 entries per event_____
			histo[i][342]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
			histo[i][345]->Fill(RecCos_LepP_B_BoostedtoWp, Weight);
			histo[i][342]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);
			histo[i][345]->Fill(RecCos_LepN_Bbar_BoostedtoWn, Weight);

	                //____4 entries per event_____
                        Double_t   ynew = 0.587401052;
                        //      ....(l+,b)....
			Double_t ctheta = RecCos_LepP_B_BoostedtoWp;
     			if(ctheta < -ynew)     {  histo[i][346]->Fill(-0.75,Weight); histo[i][348]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][346]->Fill(-0.25,Weight); histo[i][348]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][346]->Fill( 0.25,Weight); histo[i][348]->Fill( 0.25,Weight); }
     			else                   {  histo[i][346]->Fill( 0.75,Weight); histo[i][348]->Fill( 0.75,Weight); }
                        //      ....(l-,bbar)....
			ctheta = RecCos_LepN_Bbar_BoostedtoWn;
     			if(ctheta < -ynew)     {  histo[i][347]->Fill(-0.75,Weight); histo[i][348]->Fill(-0.75,Weight); }
     			else if(ctheta < 0. )  {  histo[i][347]->Fill(-0.25,Weight); histo[i][348]->Fill(-0.25,Weight); }
     			else if(ctheta < ynew) {  histo[i][347]->Fill( 0.25,Weight); histo[i][348]->Fill( 0.25,Weight); }
     			else                   {  histo[i][347]->Fill( 0.75,Weight); histo[i][348]->Fill( 0.75,Weight); }	
		}

                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                // ::                                     Histograms for Truth versus Reconstructed                                             ::
                // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                if ( TruthHasSolution > 0 && HasSolution > 0 ){
//                        ((TH2D*)histo[i][500])->Fill( (TruthT+TruthTbar).M()/GeV , (RecT+RecTbar).M()/GeV, Weight);

                        // Resolution plots for Neutrino and Anti-neutrino pT and pZ
                        if (     TruthNeu.Pt() != 0.) histo[i][570]->Fill(  (     Neutrino.Pt() - TruthNeu.Pt()    )/TruthNeu.Pt(), Weight);
                        if (     TruthNeu.Pz() != 0.) histo[i][571]->Fill(  (     Neutrino.Pz() - TruthNeu.Pz()    )/TruthNeu.Pz(), Weight);
                        if (  TruthNeubar.Pt() != 0.) histo[i][572]->Fill(  ( Antineutrino.Pt() - TruthNeubar.Pt() )/TruthNeubar.Pt(), Weight);
                        if (  TruthNeubar.Pz() != 0.) histo[i][573]->Fill(  ( Antineutrino.Pz() - TruthNeubar.Pz() )/TruthNeubar.Pz(), Weight);

                        // Spin Correlations
                        //___cos(l+)cos(l-)________________
//                        ((TH2D*)histo[i][530])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][534])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
                        //___cos(b)cos(l-)________________
//                        ((TH2D*)histo[i][531])->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,  RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][535])->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,  RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
                        //___cos(l+)cos(bbar)________________
//                        ((TH2D*)histo[i][532])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][536])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
                        //___cos(l)cos(b)________________
//                        ((TH2D*)histo[i][533])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][537])->Fill(TruthCos_LepP_T_BoostedtoT*TruthCos_Bbar_Tbar_BoostedtoTbar,RecCos_LepP_T_BoostedtoT*RecCos_Bbar_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][533])->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,  RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);
//                        ((TH2D*)histo[i][537])->Fill(TruthCos_B_T_BoostedtoT*TruthCos_LepN_Tbar_BoostedtoTbar,  RecCos_B_T_BoostedtoT*RecCos_LepN_Tbar_BoostedtoTbar, Weight);

                        // W polarizations
                        //___cos(l+,b)________________
//                        ((TH2D*)histo[i][540])->Fill(TruthCos_LepP_B_BoostedtoWp,	RecCos_LepP_B_BoostedtoWp, Weight);
//                        ((TH2D*)histo[i][543])->Fill(TruthCos_LepP_B_BoostedtoWp,	RecCos_LepP_B_BoostedtoWp, Weight);
                        //___cos(l-,bbar)_____________
//                        ((TH2D*)histo[i][541])->Fill(TruthCos_LepN_Bbar_BoostedtoWn,    RecCos_LepN_Bbar_BoostedtoWn, Weight);
//                        ((TH2D*)histo[i][544])->Fill(TruthCos_LepN_Bbar_BoostedtoWn,    RecCos_LepN_Bbar_BoostedtoWn, Weight);
                        //____2 entries per event_____
//                        ((TH2D*)histo[i][542])->Fill(TruthCos_LepP_B_BoostedtoWp,	RecCos_LepP_B_BoostedtoWp, Weight);
//                        ((TH2D*)histo[i][545])->Fill(TruthCos_LepP_B_BoostedtoWp,	RecCos_LepP_B_BoostedtoWp, Weight);
//                        ((TH2D*)histo[i][542])->Fill(TruthCos_LepN_Bbar_BoostedtoWn,    RecCos_LepN_Bbar_BoostedtoWn, Weight);
//                        ((TH2D*)histo[i][545])->Fill(TruthCos_LepN_Bbar_BoostedtoWn,    RecCos_LepN_Bbar_BoostedtoWn, Weight);

                        //___Resolution Plots_________
                        if (TruthCos_LepP_B_BoostedtoWp != 0. ) {
                                histo[i][567]->Fill( (RecCos_LepP_B_BoostedtoWp - TruthCos_LepP_B_BoostedtoWp)/TruthCos_LepP_B_BoostedtoWp, Weight);
                                histo[i][569]->Fill( (RecCos_LepP_B_BoostedtoWp - TruthCos_LepP_B_BoostedtoWp)/TruthCos_LepP_B_BoostedtoWp, Weight);
                        }
                        if (TruthCos_LepN_Bbar_BoostedtoWn != 0. ) {
                                histo[i][568]->Fill( (RecCos_LepN_Bbar_BoostedtoWn - TruthCos_LepN_Bbar_BoostedtoWn)/TruthCos_LepN_Bbar_BoostedtoWn, Weight);
                                histo[i][569]->Fill( (RecCos_LepN_Bbar_BoostedtoWn - TruthCos_LepN_Bbar_BoostedtoWn)/TruthCos_LepN_Bbar_BoostedtoWn, Weight);
                        }

                        //___cos(l+,b)__from_Mlb____
//                        ((TH2D*)histo[i][549])->Fill( Truth_myCosMlb_lp, Rec_myCosMlb_lp ,Weight);
//                        ((TH2D*)histo[i][551])->Fill( Truth_myCosMlb_lp, Rec_myCosMlb_lp ,Weight);
//                        ((TH2D*)histo[i][550])->Fill( Truth_myCosMlb_ln, Rec_myCosMlb_ln ,Weight);
//                        ((TH2D*)histo[i][551])->Fill( Truth_myCosMlb_ln, Rec_myCosMlb_ln ,Weight);
                        //____2 bins________________
//                        ((TH2D*)histo[i][552])->Fill( Truth_myCosMlb_lp, Rec_myCosMlb_lp ,Weight);
//                        ((TH2D*)histo[i][554])->Fill( Truth_myCosMlb_lp, Rec_myCosMlb_lp ,Weight);
//                        ((TH2D*)histo[i][553])->Fill( Truth_myCosMlb_ln, Rec_myCosMlb_ln ,Weight);
//                        ((TH2D*)histo[i][554])->Fill( Truth_myCosMlb_ln, Rec_myCosMlb_ln ,Weight);

                        //______Mlb__and__Mlb2______
//                        ((TH2D*)histo[i][561])->Fill( Truth_mylbMass_lp/GeV, Rec_mylbMass_lp/GeV, Weight);
//                        ((TH2D*)histo[i][562])->Fill( Truth_mylbMass_ln/GeV, Rec_mylbMass_ln/GeV, Weight);
//                        ((TH2D*)histo[i][563])->Fill( Truth_mylbMass_lp/GeV, Rec_mylbMass_lp/GeV, Weight);
//                        ((TH2D*)histo[i][563])->Fill( Truth_mylbMass_ln/GeV, Rec_mylbMass_ln/GeV, Weight);
                        //____Mlb2__________________
//                        ((TH2D*)histo[i][564])->Fill( (Truth_mylbMass_lp/GeV)*(Truth_mylbMass_lp/GeV), (Rec_mylbMass_lp/GeV)*(Rec_mylbMass_lp/GeV), Weight);
//                        ((TH2D*)histo[i][565])->Fill( (Truth_mylbMass_ln/GeV)*(Truth_mylbMass_ln/GeV), (Rec_mylbMass_ln/GeV)*(Rec_mylbMass_ln/GeV), Weight);
//                        ((TH2D*)histo[i][566])->Fill( (Truth_mylbMass_lp/GeV)*(Truth_mylbMass_lp/GeV), (Rec_mylbMass_lp/GeV)*(Rec_mylbMass_lp/GeV), Weight);
//                        ((TH2D*)histo[i][566])->Fill( (Truth_mylbMass_ln/GeV)*(Truth_mylbMass_ln/GeV), (Rec_mylbMass_ln/GeV)*(Rec_mylbMass_ln/GeV), Weight);
                }
	}
}

// #############################################################################
void ttH_dilep::DoCuts(){
// #############################################################################
//
//  purpose: to do the selection cuts
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 02.Jan.2013
//  by: A.Onofre
//
// #############################################################################


        //=============================================
        //     Do Not Consider Zero Weight Events
        //=============================================
      	if(Weight==0) return; 
        //if(  ( isData == 1 ) && ( alldata_ele == 1 ) && ( ElectronTrigger != 1 ) )  return; // Egamma stream
        //if(  ( isData == 1 ) && ( alldata_muo == 1 ) && (     MuonTrigger != 1 ) )  return; // Muon   stream
        LastCut++;	// LastCut=1

        // Needed calculations to fill the variables
        Calculations();
        //=============================================
        //=============================================
        //   Find Signal True dilepton events in MC
        //   Note: this cut was applied in the past 
	//         to ttbar events from MC@NLO samples
	//         with semi+dilep events
	//	   -> this required separation at MC
	//	      to compute dilep efficiencies
	//   Flag used (passed from *.sh script): 
	//	leptonSep != 0  yes, separation required     
        //=============================================
        //=============================================

        //=============================================
        //        Example from ttbar...No problem
	//     to keep this code here once by default
	//                leptonSep == 0
        //  (perform channel separation if necessary)
        //  ......Calculations2 is called here........
        //=============================================
        if( lepSample==21 ){ // ee sample
            if(leptonSep == 1)
            {
               if( (ntruthele+ntrutheletau) != 2) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthele+ntrutheletau) == 2) return;
            }
        }
        if( lepSample==22 ){ // mumu sample
            if(leptonSep == 1)
            {
               if( (ntruthmu+ntruthmutau) != 2) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthmu+ntruthmutau) == 2) return;
            }
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            if(leptonSep == 1)
            {
               if( (ntruthele+ntrutheletau) != 1 || (ntruthmu+ntruthmutau) != 1) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthele+ntrutheletau) == 1 && (ntruthmu+ntruthmutau) == 1) return;
            }
        }
        LastCut++;	// LastCut=2
//        cout << "Truth Separation:   runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C0) Select events which pass a good runs list
        //     Veto duplicate events
	//     (duplicate = events with same Run and
	//	Event number; nothing else here)
        //=============================================
        //=============================================
        if(  ( isData == 1 ) && ( GoodRL == 0 ) )  return;
        LastCut++;	// LastCut=3
//       cout << "C0 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C1) Require Trigger
        //=============================================
        //=============================================
        // trigger CutTriggerXXX < 0 means that no cut is applied
        if( CutTriggerEle >= 0){
            if( ElectronTrigger != CutTriggerEle ) return;
        }
        if( CutTriggerMuo >= 0){
            if(     MuonTrigger != CutTriggerMuo ) return;
        }
        if( CutTriggerEleMuo > 0){
            if( ElectronTrigger != 1 && MuonTrigger != 1  ) return;
        }
        LastCut++;	// LastCut=4
//        cout << "C1 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;


        //=============================================
        //=============================================
        // C2) Apply the cosmic event rejection 
        //=============================================
        //=============================================
        if ( Cosmic ) return;
        LastCut++;	// LastCut=5
//        cout << "C2 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C3) Number of Vertices with  
        //=============================================
        //=============================================
        if ( Vtx.size() == 0 ) return;
        LastCut++;	// LastCut=6
//        cout << "C3 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C4) Request Two Leptons with pt > 15GeV
        // a) at least 2 lep && separation in ee, mumu and emu 
        // b) exactly 2 lept 
        //=============================================
        //=============================================
        if( LeptonVec.size() < 2 )        return;
        // Separation in ee, em and mumu channels
        if( lepSample==21 ){ // ee sample
            int nele = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 11) nele = nele + 1;
            }
            if (nele < 2) return;
        }
        if( lepSample==22 ){ // mumu sample
            int nmuo = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 13) nmuo = nmuo + 1;
            }
            if (nmuo < 2) return;
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            int nele = 0;
            int nmuo = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 11) nele = nele + 1;
               if (abs(LeptonVec[i].isb) == 13) nmuo = nmuo + 1;
            }
            if (nele < 1) return;
            if (nmuo < 1) return;
        }

        LastCut++;	// LastCut=7
//        cout << "C4 a) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C4) b) Require exactly 2 isolated leptons 
        //=============================================
        //=============================================
        if ( LeptonVec.size() != 2 )        return;

        if( lepSample==21 ){ // ee sample
            if( abs(LeptonVec[0].isb) != 11 || abs(LeptonVec[1].isb) != 11) return;
        }
        if( lepSample==22 ){ // mumu sample
            if( abs(LeptonVec[0].isb) != 13 || abs(LeptonVec[1].isb) != 13) return;
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            if( (abs(LeptonVec[0].isb) != 11 || abs(LeptonVec[1].isb) != 13) && (abs(LeptonVec[0].isb) != 13 || abs(LeptonVec[1].isb) != 11) ) return;
        }
        LastCut++;	// LastCut=8
//        cout << "C4 b) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C5) At Least 1 lepton pt >= 25GeV
        //=============================================
        //=============================================
        if ( LeptonVec[0].Pt() < 25.*GeV ) return;
        LastCut++;	// LastCut=9
//        cout << "C5) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;
        //=============================================

        //=============================================
        //=============================================
        // C6) Require Lepton trigger Matched
        //=============================================
        //=============================================
        Int_t HasElectronMatchingTrigger = 0;
        Int_t     HasMuonMatchingTrigger = 0;

        for (Int_t i=0; i<LeptonVec.size(); ++i) {
                Int_t ii = LeptonVec[i].idx;
                // check leptons are trigger matched
                if (abs(LeptonVec[ii].isb) == 11 && LeptonVec[ii].itrigMatch == 1 ) HasElectronMatchingTrigger = 1;
                if (abs(LeptonVec[ii].isb) == 13 && LeptonVec[ii].itrigMatch == 1 ) HasMuonMatchingTrigger = 1;
        }

        Bool_t ElectronTriggerOK = ( ElectronTrigger != 0 ) && ( HasElectronMatchingTrigger != 0 );
        Bool_t     MuonTriggerOK = (     MuonTrigger != 0 ) && (     HasMuonMatchingTrigger != 0 );

        if( lepSample==21 ){
           if ( !ElectronTriggerOK ) return;
        }
        if( lepSample==22 ){
           if ( !MuonTriggerOK     ) return;
        }
        if( lepSample==23 ){
          if ( isData == 1 ) {
           if ( ( ElectronTrigger == 1 && MuonTrigger == 0 ) && ( !ElectronTriggerOK ) ) return;
           if ( ( ElectronTrigger == 0 && MuonTrigger == 1 ) && (     !MuonTriggerOK ) ) return;
          } else if ( !(ElectronTriggerOK || MuonTriggerOK) ) return;
        }
        LastCut++;	// LastCut=10
//        cout << "C6 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C7) E-Mu Overlap removal
        //=============================================
        //=============================================
        if (EleMuoOverlap !=0) return; 
	LastCut++;	// LastCut=11

	
        //=============================================
        //=============================================
        // C8) Jet Cleaning
        //=============================================
        //=============================================
	if (JetCleanning != 0) return;
	LastCut++; 	//LastCut=12
        

        //=============================================
        //=============================================
        // C8) No Pt missing cut for ee, mumu   
        //     Ht cut (emu)       
        //=============================================
        //=============================================
        if( lepSample==21 ){ // ee sample
          //if(MissPt <= 60.*GeV) return;
        }
        if( lepSample==22 ){ // mumu sample
          //if(MissPt <= 60.*GeV) return;
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
          if(Ht <= 130.*GeV) return;
        }
        LastCut++;	// LastCut=13
//        cout << "C8 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C9) Njets>=2 from Minintuple (jet_n)
        //=============================================
        //=============================================
        if ( jet_n_Mini != 2 ) return;
        LastCut++;	// LastCut=14
//        cout << "C9 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C10) Two Opposite Sign (OS) Leptons 
        //=============================================
        //=============================================
        if ( LeptonVec[0].isb*LeptonVec[1].isb >= 0. ) return;
        LastCut++;	// LastCut=15
//        cout << "C10 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C11)  Z Mass(l+,l-) cut: Mll > 15 GeV
        //=============================================
        //=============================================
        if( lepSample==21 ){ // ee sample
          if( ll.M()/GeV <= 15. ) return;
        }
        if( lepSample==22 ){ // mumu sample
          if( ll.M()/GeV <= 15. ) return;
        }
        if( lepSample==23 ){ // mumu sample
          if( ll.M()/GeV <= 15. ) return;
        }
        LastCut++;	// LastCut=16
//        cout << "C11) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;


        //=============================================
        //=============================================
        // C12) MC Matches Truth 
        //=============================================
        //=============================================
        if ( isData != 1  ){
                if ( LeptonVec[0].itruthMatch != 1 )  return;
                if ( LeptonVec[1].itruthMatch != 1 )  return;
        }
        LastCut++;	// LastCut=17
//        cout << "C12 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C13)  Z Mass cut: |M(ll)-91|>=8 GeV     ====
        //=============================================
        //=============================================
        if( lepSample==21 ){ // ee sample
          if( fabs(ll.M()/GeV-91.) < 8. ) return;
        }
        if( lepSample==22 ){ // mumu sample
          if( fabs(ll.M()/GeV-91.) < 8. ) return;
        }
        LastCut++;	// LastCut=18
//        cout << "C13 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

/*
        //=============================================
        //=============================================
        // C5) Remove events based on HFOR == 4 if defined
        //=============================================
        //=============================================
        if ( isData != 1 && m_hfor != -1 && HforFlag == 4 ) return;
        if ( isData != 1 && m_hfor != -1 && HforFlag != m_hfor ) return;
        LastCut++;      // LastCut=11
//        cout << "C5 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C7) Veto Duplicate Events (DATA Only)
        //=============================================
        //=============================================
        if ( isData == 1 && !(CheckDoubleEvents(  Isub, EveNumber )) ) return;
        LastCut++;      // LastCut=13
//        cout << "C7 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

*/
        //=============================================
        //=============================================
        // C14) At least 1-btag 
        //      (MV1 weight > 0.8119)
        //=============================================
        //=============================================
        if ( NbtagJet < 1 ) return;  
        LastCut++;	// LastCut=19
//        cout << "C14 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C15) Exactly 2 jets and 2 btag 
        //=============================================
        //=============================================
        if ( NbtagJet != 2 ) return;  
        LastCut++;	// LastCut=20
//        cout << "C15 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;



        //=============================================
        //=============================================
        // END OF Dilepton Challenge
        //=============================================
        //=============================================
        if( isData == 1 ){
/*
                cout << "  " << endl;
                cout << "  " << endl;
                cout << "====================================================================================" << endl;
                cout << "========== New Event Sellected =====================================================" << endl;
                cout << "====================================================================================" << endl;
                cout << " runNumber = " << Isub << " Event Number =" << EveNumber << endl;
                cout << "====================================================================================" << endl;
                cout << "   Lepton=l0:   Px=" << LeptonVec[0].Px() << " Py=" << LeptonVec[0].Py() << " Pz=" << LeptonVec[0].Pz() << " E=" << LeptonVec[0].E() <<
                                " Pt=" << LeptonVec[0].Pt() << " Eta=" << LeptonVec[0].Eta() << " Phi=" << LeptonVec[0].Phi() << " Charge=" << LeptonVec[0].isb << endl;
                cout << "   Lepton=l1:   Px=" << LeptonVec[1].Px() << " Py=" << LeptonVec[1].Py() << " Pz=" << LeptonVec[1].Pz() << " E=" << LeptonVec[1].E() <<
                                " Pt=" << LeptonVec[1].Pt() << " Eta=" << LeptonVec[1].Eta() << " Phi=" << LeptonVec[1].Phi() << " Charge=" << LeptonVec[1].isb << endl;
                cout << " MyGoodJet 1:   Px=" << MyGoodJetVec[0].Px() << " Py=" << MyGoodJetVec[0].Py() << " Pz=" << MyGoodJetVec[0].Pz() << " E=" << MyGoodJetVec[0].E() <<
                                " Pt=" << MyGoodJetVec[0].Pt() << " Eta=" << MyGoodJetVec[0].Eta() << " Phi=" << MyGoodJetVec[0].Phi() << endl;
                cout << " MyGoodJet 2:   Px=" << MyGoodJetVec[1].Px() << " Py=" << MyGoodJetVec[1].Py() << " Pz=" << MyGoodJetVec[1].Pz() << " E=" << MyGoodJetVec[1].E() <<
                                " Pt=" << MyGoodJetVec[1].Pt() << " Eta=" << MyGoodJetVec[1].Eta() << " Phi=" << MyGoodJetVec[1].Phi() << endl;
                cout << "    Miss Px=    " << MissPx << "   Miss Py=   " << MissPy << endl;
                cout << "====================================================================================" << endl;
*/
 	}

        //=============================================
        //=============================================
        // C11) Njets>=4, pT>25GeV, |eta|<2.5 
        //=============================================
        //=============================================
        //if ( MyGoodJetVec.size() < 4 ) return;
        LastCut++;	// LastCut=21
//        cout << "C11 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //====   Do tt System Reconstruction   ========
        //=============================================
        ttDilepKinFit();

        //=============================================
        //=============================================
        // C12) Check if there is a solution   ========
        //=============================================
        //=============================================
        //if(HasSolution == 0) return;
        LastCut++;	// LastCut=22
//        cout << "C12 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        if( isData == 1 ){
/*
                cout << "=========================event was reconstructed successfully=======================" << endl;
                cout << "     Lepton=l0 :  Px=" << RecLepP.Px() << " Py=" << RecLepP.Py() << " Pz=" << RecLepP.Pz() << " E=" << RecLepP.E() <<
                                         " Pt=" << RecLepP.Pt() << " Eta=" << RecLepP.Eta() << " Phi=" << RecLepP.Phi() << endl;
                cout << "     Lepton=l1 :  Px=" << RecLepN.Px() << " Py=" << RecLepN.Py() << " Pz=" << RecLepN.Pz() << " E=" << RecLepN.E() <<
                                         " Pt=" << RecLepN.Pt() << " Eta=" << RecLepN.Eta() << " Phi=" << RecLepN.Phi() << endl;
                cout << "          b(l0):  Px=" << RecB.Px() << " Py=" << RecB.Py() << " Pz=" << RecB.Pz() << " E=" << RecB.E() << " M=" << RecB.M() <<
                                         " Pt=" << RecB.Pt() << " Eta=" << RecB.Eta() << " Phi=" << RecB.Phi() << endl;
                cout << "          b(l1):  Px=" << RecBbar.Px() << " Py=" << RecBbar.Py() << " Pz=" << RecBbar.Pz() << " E=" << RecBbar.E() << " M=" << RecBbar.M() <<
                                         " Pt=" << RecBbar.Pt() << " Eta=" << RecBbar.Eta() << " Phi=" << RecBbar.Phi() << endl;
                cout << "   Neutrino(l0):  Px=" << RecNeu.Px() << " Py=" << RecNeu.Py() << " Pz=" << RecNeu.Pz() << " E=" << RecNeu.E() <<
                                         " Pt=" << RecNeu.Pt() << " Eta=" << RecNeu.Eta() << " Phi=" << RecNeu.Phi() << endl;
                cout << "   Neutrino(l1):  Px=" << RecNeubar.Px() << " Py=" << RecNeubar.Py() << " Pz=" << RecNeubar.Pz() << " E=" << RecNeubar.E() <<
                                         " Pt=" << RecNeubar.Pt() << " Eta=" << RecNeubar.Eta() << " Phi=" << RecNeubar.Phi() << endl;
                cout << "          W(l0):  Px=" << RecWp.Px() << " Py=" << RecWp.Py() << " Pz=" << RecWp.Pz() << " E=" << RecWp.E() << " M=" << RecWp.M() <<
                                         " Pt=" << RecWp.Pt() << " Eta=" << RecWp.Eta() << " Phi=" << RecWp.Phi() << endl;
                cout << "          W(l1):  Px=" << RecWn.Px() << " Py=" << RecWn.Py() << " Pz=" << RecWn.Pz() << " E=" << RecWn.E() << " M=" << RecWn.M() <<
                                         " Pt=" << RecWn.Pt() << " Eta=" << RecWn.Eta() << " Phi=" << RecWn.Phi() << endl;
                cout << "          t(l0):  Px=" << RecT.Px() << " Py=" << RecT.Py() << " Pz=" << RecT.Pz() << " E=" << RecT.E() << " M=" << RecT.M() <<
                                         " Pt=" << RecT.Pt() << " Eta=" << RecT.Eta() << " Phi=" << RecT.Phi() << endl;
                cout << "          t(l1):  Px=" << RecTbar.Px() << " Py=" << RecTbar.Py() << " Pz=" << RecTbar.Pz() << " E=" << RecTbar.E() << " M=" << RecTbar.M() <<
                                         " Pt=" << RecTbar.Pt() << " Eta=" << RecTbar.Eta() << " Phi=" << RecTbar.Phi() << endl;
                cout << "================================= Debug Equations ==================================" << endl;
                cout << "Miss-(Neu 0+Neu 1) Px=" << MissPx - (RecNeu.Px() + RecNeubar.Px()) << endl;
                cout << "                   Py=" << MissPy - (RecNeu.Py() + RecNeubar.Py()) << endl;
                cout << "====================================================================================" << endl;
*/
        }

        //=============================================
        //=============================================
        // C13) At least 2 jets are required to be 
	//      b-tagged (MV1 weight > 0.8119)
        //=============================================
        //=============================================
	//if ( NbtagJet < 2) return; 
        LastCut++;	// LastCut=23
//        cout << "C13 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

}

void ttH_dilep::first_DoCuts(){
    // #############################################################################
//
//  purpose: to do the selection cuts
//
//  authors: fveloso
//  first version: 15.nov.2006
//
//  last change: 02.Jan.2013
//  by: A.Onofre
//
// #############################################################################


        //=============================================
        //     Do Not Consider Zero Weight Events
        //=============================================
        if(Weight==0) return; 
        //if(  ( isData == 1 ) && ( alldata_ele == 1 ) && ( ElectronTrigger != 1 ) )  return; // Egamma stream
        //if(  ( isData == 1 ) && ( alldata_muo == 1 ) && (     MuonTrigger != 1 ) )  return; // Muon   stream
        LastCut++; // LastCut=1

        // Needed calculations to fill the variables
        #pragma omp critical
        Calculations();
        //=============================================
        //=============================================
        //   Find Signal True dilepton events in MC
        //   Note: this cut was applied in the past 
    //         to ttbar events from MC@NLO samples
    //         with semi+dilep events
    //     -> this required separation at MC
    //        to compute dilep efficiencies
    //   Flag used (passed from *.sh script): 
    //  leptonSep != 0  yes, separation required     
        //=============================================
        //=============================================

        //=============================================
        //        Example from ttbar...No problem
    //     to keep this code here once by default
    //                leptonSep == 0
        //  (perform channel separation if necessary)
        //  ......Calculations2 is called here........
        //=============================================
        if( lepSample==21 ){ // ee sample
            if(leptonSep == 1)
            {
               if( (ntruthele+ntrutheletau) != 2) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthele+ntrutheletau) == 2) return;
            }
        }
        if( lepSample==22 ){ // mumu sample
            if(leptonSep == 1)
            {
               if( (ntruthmu+ntruthmutau) != 2) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthmu+ntruthmutau) == 2) return;
            }
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            if(leptonSep == 1)
            {
               if( (ntruthele+ntrutheletau) != 1 || (ntruthmu+ntruthmutau) != 1) return;
               //_____get truth information_____________ 
               Calculations2();
            }
            else if(leptonSep == 2)
            {
               if( (ntruthele+ntrutheletau) == 1 && (ntruthmu+ntruthmutau) == 1) return;
            }
        }
        LastCut++; // LastCut=2
//        cout << "Truth Separation:   runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C0) Select events which pass a good runs list
        //     Veto duplicate events
    //     (duplicate = events with same Run and
    //  Event number; nothing else here)
        //=============================================
        //=============================================
        if(  ( isData == 1 ) && ( GoodRL == 0 ) )  return;
        LastCut++; // LastCut=3
//       cout << "C0 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C1) Require Trigger
        //=============================================
        //=============================================
        // trigger CutTriggerXXX < 0 means that no cut is applied
        if( CutTriggerEle >= 0){
            if( ElectronTrigger != CutTriggerEle ) return;
        }
        if( CutTriggerMuo >= 0){
            if(     MuonTrigger != CutTriggerMuo ) return;
        }
        if( CutTriggerEleMuo > 0){
            if( ElectronTrigger != 1 && MuonTrigger != 1  ) return;
        }
        LastCut++; // LastCut=4
//        cout << "C1 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;


        //=============================================
        //=============================================
        // C2) Apply the cosmic event rejection 
        //=============================================
        //=============================================
        if ( Cosmic ) return;
        LastCut++; // LastCut=5
//        cout << "C2 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C3) Number of Vertices with  
        //=============================================
        //=============================================
        if ( Vtx.size() == 0 ) return;
        LastCut++; // LastCut=6
//        cout << "C3 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C4) Request Two Leptons with pt > 15GeV
        // a) at least 2 lep && separation in ee, mumu and emu 
        // b) exactly 2 lept 
        //=============================================
        //=============================================
        if( LeptonVec.size() < 2 )        return;
        // Separation in ee, em and mumu channels
        if( lepSample==21 ){ // ee sample
            int nele = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 11) nele = nele + 1;
            }
            if (nele < 2) return;
        }
        if( lepSample==22 ){ // mumu sample
            int nmuo = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 13) nmuo = nmuo + 1;
            }
            if (nmuo < 2) return;
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            int nele = 0;
            int nmuo = 0;
            for(int i=0; i<LeptonVec.size(); i++){
               if (abs(LeptonVec[i].isb) == 11) nele = nele + 1;
               if (abs(LeptonVec[i].isb) == 13) nmuo = nmuo + 1;
            }
            if (nele < 1) return;
            if (nmuo < 1) return;
        }

        LastCut++; // LastCut=7
//        cout << "C4 a) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C4) b) Require exactly 2 isolated leptons 
        //=============================================
        //=============================================
        if ( LeptonVec.size() != 2 )        return;

        if( lepSample==21 ){ // ee sample
            if( abs(LeptonVec[0].isb) != 11 || abs(LeptonVec[1].isb) != 11) return;
        }
        if( lepSample==22 ){ // mumu sample
            if( abs(LeptonVec[0].isb) != 13 || abs(LeptonVec[1].isb) != 13) return;
        }
        if( lepSample==23 ){ // e mu (+mu e) sample
            if( (abs(LeptonVec[0].isb) != 11 || abs(LeptonVec[1].isb) != 13) && (abs(LeptonVec[0].isb) != 13 || abs(LeptonVec[1].isb) != 11) ) return;
        }
        LastCut++; // LastCut=8
//        cout << "C4 b) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C5) At Least 1 lepton pt >= 25GeV
        //=============================================
        //=============================================
        if ( LeptonVec[0].Pt() < 25.*GeV ) 
        	return;

        LastCut++; // LastCut=9
//        cout << "C5) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;
        //=============================================

        //=============================================
        //=============================================
        // C6) Require Lepton trigger Matched
        //=============================================
        //=============================================
        Int_t HasElectronMatchingTrigger = 0;
        Int_t     HasMuonMatchingTrigger = 0;

        for (Int_t i=0; i<LeptonVec.size(); ++i) {
                Int_t ii = LeptonVec[i].idx;
                // check leptons are trigger matched
                if (abs(LeptonVec[ii].isb) == 11 && LeptonVec[ii].itrigMatch == 1 ) 
                	HasElectronMatchingTrigger = 1;
                if (abs(LeptonVec[ii].isb) == 13 && LeptonVec[ii].itrigMatch == 1 ) 
                	HasMuonMatchingTrigger = 1;
        }

        Bool_t ElectronTriggerOK = ( ElectronTrigger != 0 ) && ( HasElectronMatchingTrigger != 0 );
        Bool_t     MuonTriggerOK = (     MuonTrigger != 0 ) && (     HasMuonMatchingTrigger != 0 );

        if( lepSample==21 ){
           if ( !ElectronTriggerOK ) 
           	return;
        }
        if( lepSample==22 ){
           if ( !MuonTriggerOK     ) 
           	return;
        }
        if( lepSample==23 ){
          if ( isData == 1 ) {
           if ( ( ElectronTrigger == 1 && MuonTrigger == 0 ) && ( !ElectronTriggerOK ) ) 
           	return;

           if ( ( ElectronTrigger == 0 && MuonTrigger == 1 ) && (     !MuonTriggerOK ) ) 
           	return;

          } else if ( !(ElectronTriggerOK || MuonTriggerOK) ) 
          		return;
        }
        LastCut++; // LastCut=10
//        cout << "C6 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C7) E-Mu Overlap removal
        //=============================================
        //=============================================
        if (EleMuoOverlap !=0) 
        	return;

    LastCut++; // LastCut=11

    
        //=============================================
        //=============================================
        // C8) Jet Cleaning
        //=============================================
        //=============================================
    if (JetCleanning != 0) 
    	return;

    LastCut++;     //LastCut=12
        

        //=============================================
        //=============================================
        // C8) No Pt missing cut for ee, mumu   
        //     Ht cut (emu)       
        //=============================================
        //=============================================

        if( lepSample==23 ){ // e mu (+mu e) sample
          if(Ht <= 130.*GeV) 
          	return;
        }

        LastCut++; // LastCut=13
//        cout << "C8 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C9) Njets>=2 from Minintuple (jet_n)
        //=============================================
        //=============================================
        if ( jet_n_Mini != 2 ) 
        	return;

        LastCut++; // LastCut=14
//        cout << "C9 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C10) Two Opposite Sign (OS) Leptons 
        //=============================================
        //=============================================
        if ( LeptonVec[0].isb*LeptonVec[1].isb >= 0. ) 
        	return;

        LastCut++; // LastCut=15
//        cout << "C10 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C11)  Z Mass(l+,l-) cut: Mll > 15 GeV
        //=============================================
        //=============================================
        if( lepSample==21 ){ // ee sample
          if( ll.M()/GeV <= 15. ) 
          	return;
        }
        if( lepSample==22 ){ // mumu sample
          if( ll.M()/GeV <= 15. ) 
          	return;
        }
        if( lepSample==23 ){ // mumu sample
          if( ll.M()/GeV <= 15. )
            return;
        }
        LastCut++; // LastCut=16
//        cout << "C11) runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;


        //=============================================
        //=============================================
        // C12) MC Matches Truth 
        //=============================================
        //=============================================
        if ( isData != 1  ){
                if ( LeptonVec[0].itruthMatch != 1 )  
                	return;
                if ( LeptonVec[1].itruthMatch != 1 )  
                	return;
        }
        LastCut++; // LastCut=17
//        cout << "C12 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C13)  Z Mass cut: |M(ll)-91|>=8 GeV     ====
        //=============================================
        //=============================================
        if( lepSample==21 ){ // ee sample
          if( fabs(ll.M()/GeV-91.) < 8. )
          	return;
        }
        if( lepSample==22 ){ // mumu sample
          if( fabs(ll.M()/GeV-91.) < 8. )
          	return;
        }
        LastCut++; // LastCut=18
//        cout << "C13 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

/*
        //=============================================
        //=============================================
        // C5) Remove events based on HFOR == 4 if defined
        //=============================================
        //=============================================
        if ( isData != 1 && m_hfor != -1 && HforFlag == 4 ) return;
        if ( isData != 1 && m_hfor != -1 && HforFlag != m_hfor ) return;
        LastCut++;      // LastCut=11
//        cout << "C5 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C7) Veto Duplicate Events (DATA Only)
        //=============================================
        //=============================================
        if ( isData == 1 && !(CheckDoubleEvents(  Isub, EveNumber )) ) return;
        LastCut++;      // LastCut=13
//        cout << "C7 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

*/
        //=============================================
        //=============================================
        // C14) At least 1-btag 
        //      (MV1 weight > 0.8119)
        //=============================================
        //=============================================
        if ( NbtagJet < 1 ) return;  
        LastCut++; // LastCut=19
//        cout << "C14 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

        //=============================================
        //=============================================
        // C15) Exactly 2 jets and 2 btag 
        //=============================================
        //=============================================
        if ( NbtagJet != 2 )
        	return;  
        
        LastCut++; // LastCut=20
//        cout << "C15 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;



        //=============================================
        //=============================================
        // END OF Dilepton Challenge
        //=============================================
        //=============================================


        //=============================================
        //=============================================
        // C11) Njets>=4, pT>25GeV, |eta|<2.5 
        //=============================================
        //=============================================
        //if ( MyGoodJetVec.size() < 4 ) return;
        LastCut++; // LastCut=21
//        cout << "C11 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;
}

void ttH_dilep::second_DoCuts() {

	ttDilepKinFit();

	//=============================================
	//=============================================
	// C12) Check if there is a solution   ========
	//=============================================
	//=============================================
	//if(HasSolution == 0) return;
	for(Event::event_counter = 0; Event::event_counter < events.size(); Event::event_counter++) { 
		LastCut++; // LastCut=22
		//        cout << "C12 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;

		//=============================================
		//=============================================
		// C13) At least 2 jets are required to be 
		//      b-tagged (MV1 weight > 0.8119)
		//=============================================
		//=============================================
		//if ( NbtagJet < 2) return; 
		LastCut++; // LastCut=23
		//        cout << "C13 runNumber=" << RunNumber << " eventNumber=" << EveNumber << endl;
	}
}




// Builds the DilepInput vector with all events
void ttH_dilep::buildDIVec (double _mt, double _mW, int _ttDKF_njet_UserValue) {
	unsigned event_size = events.size();
    double t_m[2] = {_mt, _mt};        	// initialize top quarks masses
    double w_m[2] = {_mW, _mW};        	// initialize W bosons masses
    double in_mpz[2] = {0., 0.};        // initialize neutrinos Pz to zero
    int _ttDKF_njets;
	int _ttDKF_JetCombChoice = 1;
    std::vector<TLorentzVectorWFlags> MyChoiceJetVec;


	unsigned counter = 0;


	double in_mpx[2] = {MissPx, MissPx};    // initialize miss(Px_neutrino1, Px_neutrino2)
	double in_mpy[2] = {MissPy, MissPy};    // initialize miss(Py_neutrino1, Py_neutrino2)
	
	// -----------------------------------------------------------------
	//  ttDKF_JetCombChoice = 1  Use N jets, b and non-b 
	//               NOTE: pass MyChoiceJetVec  to the tool 
	//                     pass ttDKF_njets = number of jets  
	//               (do nothing but pass the vectors)
	//  by: S.Amor 13.Dez.2012
	// -----------------------------------------------------------------
	if ( _ttDKF_JetCombChoice == 1 ){
		for (int jetID=0; jetID<MyGoodJetVec.size();  ++jetID){
			MyChoiceJetVec.push_back(MyGoodJetVec[jetID]);
		}
		// -----------------------------------------------------------------
		// USER INPUT NUMBER OF JETS PER EVENT FOR PERMUTATIONS :
		// -----------------------------------------------------------------
		_ttDKF_njets = _ttDKF_njet_UserValue;     // value range: [4; MyGoodJetVec.size()]         

		if ( _ttDKF_njets > MyGoodJetVec.size() ) {
			_ttDKF_njets = MyGoodJetVec.size();  // value range: [2; MyGoodJetVec.size()]        
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
									//for (int asd = 0; asd < dilep_iterations; ++asd) {
										counter++;

										DilepInput di (LeptonVec[0], LeptonVec[1], MyChoiceJetVec[j1], MyChoiceJetVec[j2], MyChoiceJetVec[j1], MyChoiceJetVec[j2], LeptonVec[0], LeptonVec[1], MyChoiceJetVec[j3], MyChoiceJetVec[j4], in_mpx, in_mpy, in_mpz, MissPx, MissPy, t_m, w_m, Event::event_counter);
										
										//di.applyVariance(RESOLUTION);
										//#pragma omp critical
										inputs.push_back(di);
									//}
								}
							}
						}
					}
				}
			}
		}
	}
	num_Combs = counter;
}


void ttH_dilep::preKinFit() {

	buildDIVec (mt, mW, ttDKF_njet_UserValue);

    cout << endl << "Structure size: " << inputs.size() * sizeof(DilepInput) << endl << endl;
}

void ttH_dilep::ttDilepKinFit(){
    // #############################################################################
    //
    //  Description:Make Kinematic Fit of ttH Dileptonic Events  (ttH->bWbWbb->blnublnubb)
    //
    //  Input:  1) =2 leptons 
    //              2) >=N jets:    N>=4 jets for ttbar + H->bbbar
    //      3) missing energy
    //
    //  Output: Best solution for (2)neutrinos 4-vectors according to method:
    //      i)  ttDKF_SolutionChoice = 1  Lowest nupT1*nupT2 value  
    //      ii) ttDKF_SolutionChoice = 2  nupT1,nupT2 p.d.fs 
    //
    //  Coded by:   A.Onofre
    //  Date:       20/12/2011 (1st version)
    //  Last Changed by:   S.Amor
    //  Date:       13/12/2012 (2nd version)
    //
    // #############################################################################


    // =================================================================================================================
    // =================================================================================================================
    //          I N P U T     F I T    P A R A M E T E R S 
    // =================================================================================================================
    // =================================================================================================================
    // Define Jets Combination Method: 
    //  ttDKF_JetCombChoice = 1     (use N jets (ttDKF_njets) to test combinations)
    //                  (ttDKF_njets chosen by user; <= total number of jets) 
    //                  (deal with ttbar and H->bb at the same time)  
    ttDKF_JetCombChoice     = 1;
    // ------------------------------------------------------------------------------------------------------------------
    // Define method used to get the best solution of the Neutrino and Anti-neutrino: 
    //  ttDKF_SolutionChoice = 1    Lowest nupT1*nupT2 value 
    //  ttDKF_SolutionChoice = 2    nupT1,nupT2 p.d.fs used  
    // ttDKF_SolutionChoice = 1;
    ttDKF_SolutionChoice    = 2;
    // ------------------------------------------------------------------------------------------------------------------
    // Define method used to chose best Higgs: 
    //  ttDKF_HiggsChoice = 1       Mass Constraint         (mj1j2 closest to mH_UserValue)
    //  ttDKF_HiggsChoice = 2       Transverse Momentum Constraint  (pT_Higgs = - pT_ttbar)
    //  ttDKF_HiggsChoice = 3       Mass from Angle Constraint  (mj1 = mj2)
    ttDKF_HiggsChoice   = 3;
    // =================================================================================================================
    // =================================================================================================================


    // =================================================================================================================
    // Define usefull variables 
    // =================================================================================================================
    
    //if (Event::event_counter == 5703)
    //	cout << "Tamanho: " << inputs.size() << " - " << sizeof(inputs[0]) << endl;
    
    // ---------------------------------------
    // by: S.Amor 13.Dez.2012
    //
    // ttDKF_JetCombChoice = 1  
    //               N jets = ttDKF_njets
    //               2 jets for ttbar
    //               2 jet for H->bbbar
    // ---------------------------------------


    // inputs.size() * dilep_iterations e igual ao num total de iteracoes por evento
    
	long long int tp = LIP::KinFit::startTimer();

	#ifdef D_CUDA
		Dilep::GPU::dilep(inputs);
	#elif D_DICE
		cout << "Size of inputs: " << inputs.size() << endl;
        Dilep::DICE::dilep();
    #else
		#pragma omp parallel
		{
			float task_id;
			DilepInput di;

			#pragma omp for schedule(dynamic) nowait
			for (unsigned counter = 0; counter < inputs.size()/* * dilep_iterations*/; ++counter) {
				//inputs[counter].applyVariance(RESOLUTION);
				// Run the dileptonic reconstruction 
				Dilep::CPU::dilep(inputs[counter]);
			}
		}
	#endif

	long long int res = LIP::KinFit::stopTimer(tp);
	cout << "Total: " << res << " us" << endl;

	// =================================================================  \\
	//                  Kinematic Fit to tt System                		  \\
	// -----------------------------------------------------------------  \\
	//  Assumptions:    -Reconst. Top quark mass fixed to mt        	  \\
	//          -Reconst.  W  boson mass fixed to mW          			  \\
	//          -Try all Permutations for leptons and bjets   			  \\
	//           (do not use Chuenlei criteria)              			  \\
	//          -Vary (E,pt) within Resolution              			  \\
	//      Output:     -Best solution of top's  according to method:	  \\
	//           ttDKF_SolutionChoice = 1 Lowest nupT1*nupT2 			  \\
	//           ttDKF_SolutionChoice = 2 nupT1,nupT2 p.d.fs 			  \\
	// =================================================================  \\
	// initialize Best Solution Methods (ttDKF_SolutionChoice = 1 and = 2)
	// index of best solution (if any)

	// ---------------------------------------
	// Get info from all possible solutions
	// ---------------------------------------

    unsigned total_counter = 0;

    long long int tp2 = LIP::KinFit::startTimer();
    #pragma omp parallel
    {
	    // ttbar variables
	    double myttbar_px;
	    double myttbar_py;
	    double myttbar_pz;
	    double myttbar_E;

	    // Higgs helpfull variables
	    double theta_jet1_HiggsFromTTbar;
	    double theta_jet2_HiggsFromTTbar;
	    double fac_j1j2H_ttbar;
	    double mass_j1H_ttbar;
	    double mass_j2H_ttbar;
	    DilepInput di;
	    #pragma omp for schedule(dynamic) nowait
	    for (Event::event_counter = 0; Event::event_counter < events.size(); ++Event::event_counter){
	    	
			int n_ttDKF_Best = -999;

		    // ttbar Probability Factors
		    double nu_sele_pt   =  10e+15;
		    double nu_sele_pdf  = -10e+15;
		    // H->bbar Probability Factors
		    double higgs_sele_pt    =   0.;
		    double higgs_sele_ang   = -10e+15;

		    // ttH->lnublnubbbar Probability Factors
		    double MaxTotalProb = -10e+15;
		    double MaxHiggsProb = -10e+15;

		    int  nTSol =  0;            // initialize Total number of solutions counter

		    // result of kinematic fit
		    std::vector<myvector> *result = new std::vector<myvector> ();

		    // =================================================================
		    // Initialize Solutions Flag
		    // =================================================================
		    HasSolution = 0;

		    // =================================================================
		    // Reset all solutions for tt Dileptonic Kinematical Fit:
		    // If solutions exist:  -There are 4 of them per combination
		    //           (solutions from quartic equations due to
		    //           momentum-energy conservation + mW + mT)
		    // =================================================================
		    // top quark 1
		    
			std::vector<TLorentzVectorWFlags> b1_ttDKF;
			std::vector<TLorentzVectorWFlags> l1_ttDKF;
			std::vector<TLorentzVectorWFlags> n1_ttDKF;
			std::vector<TLorentzVectorWFlags> W1_ttDKF;
			std::vector<TLorentzVectorWFlags> t1_ttDKF;
			// top quark 2
			std::vector<TLorentzVectorWFlags> b2_ttDKF;
			std::vector<TLorentzVectorWFlags> l2_ttDKF;
			std::vector<TLorentzVectorWFlags> n2_ttDKF;
			std::vector<TLorentzVectorWFlags> W2_ttDKF;
			std::vector<TLorentzVectorWFlags> t2_ttDKF;
			// ttbar system
			std::vector<TLorentzVectorWFlags> ttbar_ttDKF;
			// Higgs
			std::vector<TLorentzVectorWFlags> b1_Higgs_ttDKF;
			std::vector<TLorentzVectorWFlags> b2_Higgs_ttDKF;
			std::vector<TLorentzVectorWFlags> Higgs_ttDKF;
			std::vector<double> mHiggsJet1_ttDKF;
			std::vector<double> mHiggsJet2_ttDKF;

			std::vector<double> ProbHiggs_ttDKF;
			std::vector<double> ProbTTbar_ttDKF;
			std::vector<double> ProbTotal_ttDKF;

			#ifdef D_DICE
			for (unsigned partial_counter = 0; partial_counter < num_Combs * dilep_iterations; ++partial_counter) {

				float task_id = (float) partial_counter / (float) dilep_iterations;
				unsigned current_variation = partial_counter % dilep_iterations;

				// Check if it needs to pick a new combo
				if (task_id == (int) task_id) {
					di = inputs[total_counter];
					total_counter++;
				}

				//cout << inputs.size() << " - " << total_counter <<endl;
				// result on local variable since it will be accessed plenty of times
				*result = di.getResult(current_variation);
				HasSolution += di.getHasSol(current_variation);

				current_variation++;
			#else
		    for (unsigned partial_counter = 0; partial_counter < num_Combs; ++partial_counter, ++total_counter) {
				

		    	//task_id = (float) counter / (float) dilep_iterations;

		        // Check if it needs to pick a new combo
		       // if (task_id == (int) task_id)
		    	//cout << inputs.size() << " - " << total_counter <<endl;
		        di = inputs[total_counter];


		        //cout << "Event: " << Event::event_counter << " partial: " << partial_counter << " total " << total_counter << endl;


		        // result on local variable since it will be accessed plenty of times
		        *result = di.getResult();
		        HasSolution += di.getHasSol();
		    #endif
		        std::vector<myvector>::iterator pp;

		        for ( pp = result->begin(); pp < result->end(); pp++) {
		        	//cout << "Event: " << Event::event_counter << " - " << result->size() << endl;

		            double   px,  py,  pz,  E, 
		                     apx, apy, apz, aE;
		            int     iPDGnu1, iPDGW1, iPDGt1;
		            int     iPDGnu2, iPDGW2, iPDGt2;

		            // -------------------------------
		            //  1st top quark Reconstruction
		            // -------------------------------
		            // b-quark 1
		            b1_ttDKF.push_back(di.getZbjW());
		            // lepton 1
		            l1_ttDKF.push_back(di.getZlepW());          
		            if ( di.getZlepW().isb ==  11 ) { iPDGnu1 = -12; iPDGW1 = -24; iPDGt1 = -6; }
		            if ( di.getZlepW().isb == -11 ) { iPDGnu1 = +12; iPDGW1 = +24; iPDGt1 = +6; }
		            if ( di.getZlepW().isb ==  13 ) { iPDGnu1 = -14; iPDGW1 = -24; iPDGt1 = -6; }
		            if ( di.getZlepW().isb == -13 ) { iPDGnu1 = +14; iPDGW1 = +24; iPDGt1 = +6; }
		            // neutrino 1
		            px = pp->Px();
		            py = pp->Py();
		            pz = pp->Pz();
		            E  = sqrt(px*px + py*py + pz*pz);
		            TLorentzVector n1;
		            n1.SetPxPyPzE(  px,   py,   pz,  E);
		            TLorentzVectorWFlags nu1(n1,0,iPDGnu1,999.,-1,-1);
		            n1_ttDKF.push_back(nu1);
		            // W boson 1
		            TLorentzVector w1;
		            w1.SetPxPyPzE(  px + di.getZlepW().Px(), 
		                    py + di.getZlepW().Py(), 
		                    pz + di.getZlepW().Pz(), 
		                    E  + di.getZlepW().E()   );
		            TLorentzVectorWFlags ww1(w1,0,iPDGW1,999.,-1,-1);
		            W1_ttDKF.push_back(ww1);
		            // top quark 1
		            TLorentzVector t1;
		            t1.SetPxPyPzE(  px + di.getZlepW().Px() + di.getZbjW().Px(), 
		                    py + di.getZlepW().Py() + di.getZbjW().Py(), 
		                    pz + di.getZlepW().Pz() + di.getZbjW().Pz(), 
		                    E  + di.getZlepW().E()  + di.getZbjW().E() );
		            TLorentzVectorWFlags tt1(t1,0,iPDGt1,999.,-1,-1);
		            t1_ttDKF.push_back(tt1);

		            // -------------------------------
		            //  2nd top quark reconstruction
		            // -------------------------------
		            // b-quark 2
		            b2_ttDKF.push_back(di.getCbjW());
		            // lepton 2
		            l2_ttDKF.push_back(di.getClepW());
		            if ( di.getClepW().isb ==  11 ) { iPDGnu2 = -12; iPDGW2 = -24; iPDGt2 = -6; }
		            if ( di.getClepW().isb == -11 ) { iPDGnu2 = +12; iPDGW2 = +24; iPDGt2 = +6; }
		            if ( di.getClepW().isb ==  13 ) { iPDGnu2 = -14; iPDGW2 = -24; iPDGt2 = -6; }
		            if ( di.getClepW().isb == -13 ) { iPDGnu2 = +14; iPDGW2 = +24; iPDGt2 = +6; }
		            // neutrino 2
		            apx = di.getMissPx()-px;
		            apy = di.getMissPy()-py;
		            apz = pp->aPz();
		            aE  = sqrt(apx*apx + apy*apy + apz*apz);
		            TLorentzVector n2;
		            n2.SetPxPyPzE( apx,  apy,  apz, aE);
		            TLorentzVectorWFlags nu2(n2,0,iPDGnu2,999.,-1,-1);
		            n2_ttDKF.push_back(nu2);
		            // W boson 2
		            TLorentzVector w2;
		            w2.SetPxPyPzE(  apx + di.getClepW().Px(), 
		                    apy + di.getClepW().Py(), 
		                    apz + di.getClepW().Pz(), 
		                    aE  + di.getClepW().E()   );
		            TLorentzVectorWFlags ww2(w2,0,iPDGW2,999.,-1,-1);
		            W2_ttDKF.push_back(ww2);
		            // top quark 2
		            TLorentzVector t2;
		            t2.SetPxPyPzE(  apx + di.getClepW().Px() + di.getCbjW().Px(), 
		                    apy + di.getClepW().Py() + di.getCbjW().Py(), 
		                    apz + di.getClepW().Pz() + di.getCbjW().Pz(), 
		                    aE  + di.getClepW().E()  + di.getCbjW().E() );
		            TLorentzVectorWFlags tt2(t2,0,iPDGt2,999.,-1,-1);
		            t2_ttDKF.push_back(tt2);

		            // -------------------------------
		            //  (t,tbar) system reconstruction
		            // -------------------------------
		            TLorentzVector ttbar;
		            myttbar_px = px + di.getZlepW().Px() + di.getZbjW().Px() + apx + di.getClepW().Px() + di.getCbjW().Px();
		            myttbar_py = py + di.getZlepW().Py() + di.getZbjW().Py() + apy + di.getClepW().Py() + di.getCbjW().Py(); 
		            myttbar_pz = pz + di.getZlepW().Pz() + di.getZbjW().Pz() + apz + di.getClepW().Pz() + di.getCbjW().Pz();
		            myttbar_E  = E  + di.getZlepW().E()  + di.getZbjW().E()  + aE  + di.getClepW().E()  + di.getCbjW().E(); 
		            ttbar.SetPxPyPzE( myttbar_px, myttbar_py, myttbar_pz, myttbar_E);
		            TLorentzVectorWFlags ttbar2(ttbar,0, 999,999.,-1,-1);
		            ttbar_ttDKF.push_back(ttbar2);

		            // -------------------------------
		            //   Higgs system reconstruction
		            // -------------------------------
		            // jet 1 from Higgs
		            b1_Higgs_ttDKF.push_back( di.getJet1HiggsW() );
		            // jet 2 from Higgs
		            b2_Higgs_ttDKF.push_back( di.getJet2HiggsW() );
		            // Higgs itself
		            TLorentzVector myHiggs;
		            myHiggs.SetPxPyPzE( di.getJet1HiggsW().Px() + di.getJet2HiggsW().Px(), 
		                    di.getJet1HiggsW().Py() + di.getJet2HiggsW().Py(), 
		                    di.getJet1HiggsW().Pz() + di.getJet2HiggsW().Pz(), 
		                    di.getJet1HiggsW().E()  + di.getJet2HiggsW().E() );
		            TLorentzVectorWFlags Higgs(myHiggs,0, 25 ,999.,-1,-1);
		            Higgs_ttDKF.push_back( Higgs );


		            // -----------------------------------------------------------------------------
		            // Compute best solution for H->bb
		            // -----------------------------------------------------------------------------
		            // Three methods: 1) Use Mass Constraint          (mj1j2 closest to mH_UserValue)
		            //        2) Use Transverse Momentum Constraint ( pT_Higgs = - pT_ttbar )
		            //        3) Use Mass from Angle Constraint
		            // -----------------------------------------------------------------------------

		            // -----------------------------------------------------------------------------
		            // Method 1:
		            // -----------------------------------------------------------------------------
		            // Mass Constraint: mj1j2 = mH_UserValue
		            // -----------------------------------------------------------------------------
		            double myHiggs_MassDiff = fabs( myHiggs.M() - mH_UserValue );   

		            // -----------------------------------------------------------------------------
		            // Method 2:
		            // -----------------------------------------------------------------------------
		            // Transverse Momentum Constraint: pT_Higgs = - pT_ttbar
		            // -----------------------------------------------------------------------------                
		            double myHiggs_PxDiff = fabs( myHiggs.Px() - ttbar.Px() );  
		            double myHiggs_PyDiff = fabs( myHiggs.Py() - ttbar.Py() );  
		            double myHiggs_pTDiff = sqrt( myHiggs_PxDiff*myHiggs_PxDiff + myHiggs_PyDiff*myHiggs_PyDiff );

		            // -----------------------------------------------------------------------------                
		            // Method 3 : 
		            // -----------------------------------------------------------------------------                
		            // Mass from Angle Constraint:  mj1 = mj2 (from the hard process)
		            //              Compute Hard Process Kinematics for H->bb
		            // -----------------------------------------------------------------------------                
		            // Mass Initialization 
		            mass_j1H_ttbar = -999.;
		            mass_j2H_ttbar = -999.;

		            // Higgs Momenta from ttbar system
		            //TVector3 HiggsFromTTbar( - ttbar.Px(), - ttbar.Py(), (Hz - ttbar.Pz()) ); 
		            // Try to compute ttbar. without NU !! CHECK!!
		            TVector3 HiggsFromTTbar( - ttbar.Px(), - ttbar.Py(), (Hz + n1.Pz() + n2.Pz() - ttbar.Pz() ) );  
		            // Test jets for Higgs
		            TVector3  jet1_vec( di.getJet1HiggsW().Px(), di.getJet1HiggsW().Py(), di.getJet1HiggsW().Pz() );
		            TVector3  jet2_vec( di.getJet2HiggsW().Px(), di.getJet2HiggsW().Py(), di.getJet2HiggsW().Pz() );
		            // check jet angle with respect to ttbar direction
		            theta_jet1_HiggsFromTTbar = jet1_vec.Angle( HiggsFromTTbar );
		            theta_jet2_HiggsFromTTbar = jet2_vec.Angle( HiggsFromTTbar );

		            if ( sin(theta_jet1_HiggsFromTTbar)*sin(theta_jet2_HiggsFromTTbar) ) { 
		                fac_j1j2H_ttbar = 1. + ( 1. - cos(theta_jet1_HiggsFromTTbar)*cos(theta_jet2_HiggsFromTTbar) ) 
		                    / ( sin(theta_jet1_HiggsFromTTbar)*sin(theta_jet2_HiggsFromTTbar) ) ;
		                mass_j1H_ttbar  = sqrt( 2. * fac_j1j2H_ttbar ) * sin( theta_jet1_HiggsFromTTbar ) * di.getJet1HiggsW().P()  ;
		                mass_j2H_ttbar  = sqrt( 2. * fac_j1j2H_ttbar ) * sin( theta_jet2_HiggsFromTTbar ) * di.getJet2HiggsW().P()  ;

		                higgs_sele_ang  = fabs( ( mass_j1H_ttbar + mass_j2H_ttbar ) / ( mass_j1H_ttbar - mass_j2H_ttbar ) ) ;
		            }

		            //Save Higgs Mass from Angular Kinematic Equations of bjet 1 and bjet 2                 
		            mHiggsJet1_ttDKF.push_back(mass_j1H_ttbar); 
		            mHiggsJet2_ttDKF.push_back(mass_j2H_ttbar);

		            /*cout << "Jet1: Pt = " << jet1_vec.Pt() << " mass_j1H_ttbar = " << mass_j1H_ttbar << endl;
		              cout << "Jet2: Pt = " << jet2_vec.Pt() << " mass_j2H_ttbar = " << mass_j2H_ttbar << endl;
		              cout << "nTSol = " << nTSol << " mass_j1H_ttbar - mass_j2H_ttbar " << mass_j1H_ttbar - mass_j2H_ttbar <<  endl; 
		              cout << " " << endl; 
		             */

		            // -----------------------------------------------------------------------------
		            // Higgs Probability : 
		            // -----------------------------------------------------------------------------
		            // Method 1:  Use Mass Constraint  (mj1j2 closest to mH_UserValue)
		            if ( ttDKF_HiggsChoice == 1 ) ProbHiggs_ttDKF.push_back(   1./myHiggs_MassDiff  );          
		            // -----------------------------------------------------------------------------
		            // Method 2:  Use Transverse Momentum Constraint (pT_Higgs = - pT_ttbar)
		            if ( ttDKF_HiggsChoice == 2 ) ProbHiggs_ttDKF.push_back(   1./myHiggs_pTDiff    );          
		            // -----------------------------------------------------------------------------
		            // Method 3: Use Mass from Angle Constraint
		            if ( ttDKF_HiggsChoice == 3 ) ProbHiggs_ttDKF.push_back(   higgs_sele_ang   );          


		            // -------------------------------
		            // Test Best Solution Now:
		            // (i)  ttDKF_SolutionChoice = 1 
		            //   (Lowest nupT1*nupT2)
		            // (ii) ttDKF_SolutionChoice = 2 
		            //   (nupT1,nupT2 p.d.fs)
		            // -------------------------------
		            // (i) Lowest nupT1*nupT2
		            if ( ttDKF_SolutionChoice == 1 ) {
		                double nu_pt_cand =     sqrt( n1_ttDKF[nTSol].Px() * n1_ttDKF[nTSol].Px() +
		                        n1_ttDKF[nTSol].Py() * n1_ttDKF[nTSol].Py() ) *     
		                    sqrt( n2_ttDKF[nTSol].Px() * n2_ttDKF[nTSol].Px() +
		                            n2_ttDKF[nTSol].Py() * n2_ttDKF[nTSol].Py() );  

		                // ------------------------------------------
		                // ttbar System Probability : 
		                // ------------------------------------------
		                ProbHiggs_ttDKF.push_back( 1./ nu_pt_cand);

		                // before checking ttbar take Higgs into account also
		                // nu_pt_cand *= 1./ProbHiggs_ttDKF(nTSol);
		                // decide here !!!!!
		                //if ( nu_pt_cand < nu_sele_pt ) { nu_sele_pt = nu_pt_cand; n_ttDKF_Best = nTSol;}
		            }

		            // (ii) nupT1,nupT2 from p.d.fs
		            if ( ttDKF_SolutionChoice == 2 ) {

		                // Define used pdf variables (make sure the range of variables meets histos)
		                std::vector<double> Xpdf;
		                Xpdf.push_back(n1_ttDKF[nTSol].Pt()/GeV); // 1st pdf: pT neutrino 1
		                Xpdf.push_back(n2_ttDKF[nTSol].Pt()/GeV); // 2nd pdf: pT neutrino 2

		                // Loop over all pdf available and evaluate the pdf product (if it is possible)
		                double myProdXpdf    = 1.;
		                for ( Int_t i_pdf = 0; i_pdf < Xpdf.size() ; ++i_pdf){
		                    // get bin for Xpdf[i_pdf]
		                    int xBin = int( ( Xpdf[i_pdf] - LowerEdge[i_pdf] ) * Scale[i_pdf] ) + 1;
		                    if (  ( xBin >= 1 )  && ( xBin <= NBins[i_pdf] ) ){
		                        myProdXpdf   *= pdfKinFitVec[i_pdf][xBin];
		                    } else {
		                        myProdXpdf   *= 0.;
		                    }   
		                }

		                // ------------------------------------------
		                // ttbar System Probability : 
		                // ------------------------------------------
		                ProbHiggs_ttDKF.push_back( myProdXpdf );


		                // before checking ttbar take Higgs into account also
		                // myProdXpdf *= ProbHiggs_ttDKF(nTSol);
		                // decide here !!!!!
		                //if ( ( myProdXpdf > nu_sele_pdf ) && ( myProdXpdf != 0. ) ) { nu_sele_pdf = myProdXpdf ; n_ttDKF_Best = nTSol;}

		            }
		            // -------------------------------
		            // Last Action Before Exit:
		            //   Increment Solutions Counter
		            //  (its also the index vectors)
		            // -------------------------------
		            nTSol++;

		        }
		        // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		        // %      Code to Evaluate Solutions     %
		        // %      Solutions Found Are Stored     %
		        // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

		    // ###################################################################
		    //   C H A N G E   O B J E C T S   W I T H I N   R E S O L U T I O N #
		    // ###################################################################
		    }


		    // ==================================================================
		    // Solutions Cycle
		    // ==================================================================


		    for ( int iSol = 0; iSol < nTSol; iSol++) {     

		        ProbTotal_ttDKF.push_back( ProbHiggs_ttDKF[iSol]*ProbHiggs_ttDKF[iSol] );
		        if ( ( ProbTotal_ttDKF[iSol] > MaxTotalProb ) && ( ProbTotal_ttDKF[iSol] != 0. ) ) { MaxTotalProb = ProbTotal_ttDKF[iSol] ; n_ttDKF_Best = iSol;}

		        //cout << "ProbHiggs_ttDKF[iSol] " << ProbHiggs_ttDKF[iSol] << "; ProbHiggs_ttDKF[iSol] " << ProbHiggs_ttDKF[iSol] << "; ProbTotal_ttDKF[iSol] " << ProbTotal_ttDKF[iSol] << endl;

		        //if ( ( ProbHiggs_ttDKF[iSol] > MaxHiggsProb ) && ( ProbHiggs_ttDKF[iSol] != 0. ) ) { MaxHiggsProb = ProbHiggs_ttDKF[iSol] ; n_ttDKF_Best = iSol;}

		    } // Solutions Cicle

		    // -------------------------------------------------------------------
		    // Redefine HasSolution if no other reconstruction criteria met
		    // -------------------------------------------------------------------
		    HasSolution = (n_ttDKF_Best >= 0) ? HasSolution : 0;

		    // -------------------------------------------------------------------
		    // Make sure backward compatibility is preserved + Few Calculations
		    // -------------------------------------------------------------------
		    if(  HasSolution > 0  )
		    {


		        // -------------------------------------------------------------------
		        Neutrino     = n1_ttDKF[n_ttDKF_Best];      // Neutrino 1
		        Antineutrino = n2_ttDKF[n_ttDKF_Best];      // Neutrino 2       
		        // ###  leptons  ###
		        RecLepP     = l1_ttDKF[n_ttDKF_Best];
		        RecLepN     = l2_ttDKF[n_ttDKF_Best];
		        // ###  b-quarks ###
		        RecB        = b1_ttDKF[n_ttDKF_Best];
		        RecBbar     = b2_ttDKF[n_ttDKF_Best];
		        // ### Neutrinos ###
		        RecNeu      = n1_ttDKF[n_ttDKF_Best];
		        RecNeubar   = n2_ttDKF[n_ttDKF_Best];
		        // ###  W bosons ###
		        RecWp       = W1_ttDKF[n_ttDKF_Best];
		        RecWn       = W2_ttDKF[n_ttDKF_Best];
		        // ###  t-quarks ###
		        RecT        = t1_ttDKF[n_ttDKF_Best];
		        RecTbar     = t2_ttDKF[n_ttDKF_Best];
		        // ###  ttbar system ###
		        RecTTbar        = ttbar_ttDKF[n_ttDKF_Best];
		        // ###  Higgs system ###
		        RecHiggs          = Higgs_ttDKF[n_ttDKF_Best];
		        RecHiggsB1    = b1_Higgs_ttDKF[n_ttDKF_Best];
		        RecHiggsB2    = b2_Higgs_ttDKF[n_ttDKF_Best];
		        RecMassHiggsJet1  = mHiggsJet1_ttDKF[n_ttDKF_Best]; //samor 16.Dec.2012
		        RecMassHiggsJet2  = mHiggsJet2_ttDKF[n_ttDKF_Best];

		        RecProbTotal_ttH  = ProbTotal_ttDKF[n_ttDKF_Best];


		        //      cout << "n_ttDKF_Best = " << n_ttDKF_Best << " ; RecMassHiggsJet1 " << RecMassHiggsJet1 << " ; RecMassHiggsJet2 " << RecMassHiggsJet2 << endl;
		        //      cout << "   " << endl;

		        // -------------------------------------------------------------------


		        // ################################
		        // ##    t(tbar) c.m. systems    ##
		        // ################################
		        //...t/tbar...
		        TVector3       t_boost, tb_boost, tt_boost;

		        //...get top boosts................
		        t_boost  =  -(RecT).BoostVector();
		        tb_boost =  -(RecTbar).BoostVector();
		        tt_boost =  -(RecT + RecTbar).BoostVector();

		        //.................................
		        //...make boost  to t..............
		        //.................................
		        //___b____
		        RecB_BoostedtoT    = RecB;
		        RecB_BoostedtoT.Boost(t_boost);
		        //___W+___
		        RecWp_BoostedtoT   = RecWp;
		        RecWp_BoostedtoT.Boost(t_boost);
		        //___l+___
		        RecLepP_BoostedtoT = RecLepP;
		        RecLepP_BoostedtoT.Boost(t_boost);
		        //___neu__
		        RecNeu_BoostedtoT  = RecNeu;
		        RecNeu_BoostedtoT.Boost(t_boost);


		        //.................................
		        //...make boost  to tbar...........
		        //.................................
		        //___bbar___
		        RecBbar_BoostedtoTbar   = RecBbar;
		        RecBbar_BoostedtoTbar.Boost(tb_boost);
		        //____W-____
		        RecWn_BoostedtoTbar     = RecWn;
		        RecWn_BoostedtoTbar.Boost(tb_boost);
		        //____l-____
		        RecLepN_BoostedtoTbar   = RecLepN;
		        RecLepN_BoostedtoTbar.Boost(tb_boost);
		        //__neubar__
		        RecNeubar_BoostedtoTbar = RecNeubar;
		        RecNeubar_BoostedtoTbar.Boost(tb_boost);


		        //.................................
		        //...make boost to ttbar...........
		        //.................................
		        //___t____
		        RecT_Boostedtottbar   =  RecT;
		        RecT_Boostedtottbar.Boost(tt_boost);
		        //__tbar__
		        RecTbar_Boostedtottbar  =  RecTbar;
		        RecTbar_Boostedtottbar.Boost(tt_boost);


		        //.................................
		        //....Spin Correlations............
		        //.................................
		        //_____l+__in_t__________
		        RecCos_LepP_T_BoostedtoT = cos(  RecLepP_BoostedtoT   .Angle (    RecT_Boostedtottbar.Vect()));
		        //_____nu__in_t__________
		        RecCos_Neu_T_BoostedtoT  = cos(   RecNeu_BoostedtoT   .Angle (    RecT_Boostedtottbar.Vect()));
		        //_____b__in_t___________
		        RecCos_B_T_BoostedtoT    = cos(     RecB_BoostedtoT   .Angle (    RecT_Boostedtottbar.Vect()));


		        //_____l-__in_tbar_______
		        RecCos_LepN_Tbar_BoostedtoTbar    = cos(  RecLepN_BoostedtoTbar   .Angle ( RecTbar_Boostedtottbar.Vect()));
		        //_____nu__in_t__________
		        RecCos_Neubar_Tbar_BoostedtoTbar  = cos(RecNeubar_BoostedtoTbar   .Angle ( RecTbar_Boostedtottbar.Vect()));
		        //_____b__in_t___________
		        RecCos_Bbar_Tbar_BoostedtoTbar    = cos(  RecBbar_BoostedtoTbar   .Angle ( RecTbar_Boostedtottbar.Vect()));


		        // ################################
		        // ##     W+/- c.m. systems  ##
		        // ################################
		        //...W+/-...
		        TVector3       Wp_boost, Wn_boost;

		        //...get W+/- boosts................
		        Wp_boost  =  -(RecWp).BoostVector();
		        Wn_boost  =  -(RecWn).BoostVector();

		        //.................................
		        //...make boost  to W+.............
		        //.................................
		        //___l+___
		        RecLepP_BoostedtoWp = RecLepP;
		        RecLepP_BoostedtoWp.Boost(Wp_boost);
		        //___b____
		        RecB_BoostedtoWp    = RecB;
		        RecB_BoostedtoWp.Boost(Wp_boost);
		        //__neu___
		        RecNeu_BoostedtoWp = RecNeu;
		        RecNeu_BoostedtoWp.Boost(Wp_boost);

		        //.................................
		        //...make boost  to W-.............
		        //.................................
		        //____l-____
		        RecLepN_BoostedtoWn   = RecLepN;
		        RecLepN_BoostedtoWn.Boost(Wn_boost);
		        //__bbar____
		        RecBbar_BoostedtoWn   = RecBbar;
		        RecBbar_BoostedtoWn.Boost(Wn_boost);
		        //__neu___
		        RecNeubar_BoostedtoWn = RecNeubar;
		        RecNeubar_BoostedtoWn.Boost(Wn_boost);

		        //.................................
		        //....W Polarizations..............
		        //.................................
		        //_____(l+,b)__in_W+__________
		        RecCos_LepP_B_BoostedtoWp =  -cos(  RecLepP_BoostedtoWp   .Angle (  RecB_BoostedtoWp.Vect()));
		        //_____(l-,bbar)__in_W-_______
		        RecCos_LepN_Bbar_BoostedtoWn =  -cos(  RecLepN_BoostedtoWn   .Angle (  RecBbar_BoostedtoWn.Vect()));

		    }
		}
	}
	//#pragma omp barrier
	long long int res2 = LIP::KinFit::stopTimer(tp2);
    cout << "Total2: " << res2 << " us - " << inputs.size() * sizeof(DilepInput) << " bytes" << endl;

}

// #############################################################################
void ttH_dilep::PostLoopCalculations(){
// #############################################################################
//
//  purpose: to compute things after the events loop (eg. asymmetries)
//
//  notes: should be replaced by the user!
//
//  authors: nfcastro, fveloso
//  first version: ??.???.????
//
//  last change: 05.nov.2012
//  by: A.Onofre
//
// #############################################################################

  of.close();
  f2.close();


	// write truth efficiency
	//cout << NumberGoodSolutions << " / " << NumberGoodEvents << " = " << NumberGoodSolutions/NumberGoodEvents << endl;

        // =========================================================
        // ===== AO 8 Oct 2010 ===================== above =========
        // =========================================================
        if ( ( isData == 0 ) && ( events[0].myRunNumber ==105200 ) ){

                cout << "    " << endl;
                cout << "    " << endl;
                cout << " ======================================================== " << endl;
                cout << " ======================================================== " << endl;
                cout << "                  MC  Event Statistcs                     " << endl;
                cout << " ======================================================== " << endl;
                cout << " ======================================================== " << endl;
                cout << " Total  Number of Events: " << myEVE_Total << endl;
                cout << " 1]--Semileptonic--Events--Summary----------------------- " << endl;
                //....semileptonic................................................
                cout << "     ttbar -> bW(qq) bW(nu_e el): " << myEVE_semi_nontau_ele << endl;
                cout << "     ttbar -> bW(qq) bW(nu_m mu): " << myEVE_semi_nontau_mu << endl;
                cout << "  ttbar -> bW(qq) bW(nu_tau tau): " << myEVE_semi_tau << endl;
                cout << "     semil. decay With Taus (el): " << myEVE_semi_ele << endl;
                cout << "     semil. decay With Taus (mu): " << myEVE_semi_mu << endl;
                cout << "                     (taus->lep): " << myEVE_semi_leptau << endl;
                cout << "                     (taus->ele): " << myEVE_semi_eletau << endl;
                cout << "                   (taus->muons): " << myEVE_semi_mutau << endl;
                //....dileptonic..................................................
                cout << " 2]---Dileptonic--Events--Summary------------------------ " << endl;
                cout << " ttbar->bW(nu_e el) bW(nu_e el ): " << myEVE_di_nontau_eleele << endl;
                cout << " ttbar->bW(nu_e el) bW(nu_m mu ): " << myEVE_di_nontau_elemu << endl;
                cout << " ttbar->bW(nu_e el) bW(nu_t tau): " << myEVE_di_nontau_eletau << endl;
                cout << " ttbar->bW(nu_m mu) bW(nu_m mu ): " << myEVE_di_nontau_mumu << endl;
                cout << " ttbar->bW(nu_m mu) bW(nu_t tau): " << myEVE_di_nontau_mutau << endl;
                cout << "ttbar->bW(nu_t tau) bW(nu_t tau): " << myEVE_di_nontau_tautau << endl;
                cout << "               With Taus (el el): " << myEVE_di_eleele << endl;
                cout << "               With Taus (mu mu): " << myEVE_di_mumu << endl;
                cout << "               With Taus (el mu): " << myEVE_di_elemu << endl;
                //...top quarks
                cout << " 3]---Multileptonic--Events--Summary--------------------- " << endl;
                cout << "          Events with  0 leptons: " << myEVE_0leptons << endl;
                cout << "          Events with  3 leptons: " << myEVE_3leptons << endl;
                cout << "          Events with  4 leptons: " << myEVE_4leptons << endl;
                cout << "          Events with >4 leptons: " << myEVE_more4leptons << endl;
                cout << " 4] ---t-quark---Structure---Summary--------------------- " << endl;
                cout << "    2 top quark evt. (IQ1=IQ2=1): " << myEVE_ttbar << endl;
                cout << "    Non ttbar Events(IQ1,IQ2<>1): " << myEVE_nonttbar << endl;
                cout << "                  (4 top quarks): " << myEVE_4tops << endl;
                cout << "               Top quark Details: " << endl;
                cout << "                t=0 (tbar=0-->3): " << myttbar_00 << "---" << myttbar_01 << "---" << myttbar_02 << "---" << myttbar_03 << "---" << endl;
                cout << "                t=1 (tbar=0-->3): " << myttbar_10 << "---" << myttbar_11 << "---" << myttbar_12 << "---" << myttbar_13 << "---" << endl;
                cout << "                t=2 (tbar=0-->3): " << myttbar_20 << "---" << myttbar_21 << "---" << myttbar_22 << "---" << myttbar_23 << "---" << endl;
                cout << "                t=3 (tbar=0-->3): " << myttbar_30 << "---" << myttbar_31 << "---" << myttbar_32 << "---" << myttbar_33 << "---" << endl;
                //...W bosons
                cout << " 5] ---W---Structure--for-ttbar---Summary---------------- " << endl;
                cout << "	Events with >= 2 W bosons: " << myEVE_WW << endl;
                cout << "               Non >= 2 W Events: " << myEVE_nonWW << endl;
                //...b quarks
                cout << " 6] ---b-quark--Structure-for-ttbar--Summary------------- " << endl;
                cout << "          Events with 2 b quarks: " << myEVE_bb << endl;
                cout << "                  Non 2 b Events: " << myEVE_nonbb << endl;
                cout << "     b quark Details (IQ1=IQ2=1): " << endl;
                cout << "                b=0 (bbar=0-->3): " << mybbbar_00 << "---" << mybbbar_01 << "---" << mybbbar_02 << "---" << mybbbar_03 << "---" << endl;
                cout << "                b=1 (bbar=0-->3): " << mybbbar_10 << "---" << mybbbar_11 << "---" << mybbbar_12 << "---" << mybbbar_13 << "---" << endl;
                cout << "                b=2 (bbar=0-->3): " << mybbbar_20 << "---" << mybbbar_21 << "---" << mybbbar_22 << "---" << mybbbar_23 << "---" << endl;
                cout << "                b=3 (bbar=0-->3): " << mybbbar_30 << "---" << mybbbar_31 << "---" << mybbbar_32 << "---" << mybbbar_33 << "---" << endl;
                //...b quarks
                cout << " 7] ---s-quark--Structure-for-ttbar--Summary------------- " << endl;
                cout << "          Events with 2 s quarks: " << myEVE_ss << endl;
                cout << "                  Non 2 s Events: " << myEVE_nonss << endl;
                cout << "     s quark Details (IQ1=IQ2=1): " << endl;
                cout << "                s=0 (sbar=0-->3): " << myssbar_00 << "---" << myssbar_01 << "---" << myssbar_02 << "---" << myssbar_03 << "---" << endl;
                cout << "                s=1 (sbar=0-->3): " << myssbar_10 << "---" << myssbar_11 << "---" << myssbar_12 << "---" << myssbar_13 << "---" << endl;
                cout << "                s=2 (sbar=0-->3): " << myssbar_20 << "---" << myssbar_21 << "---" << myssbar_22 << "---" << myssbar_23 << "---" << endl;
                cout << "                s=3 (sbar=0-->3): " << myssbar_30 << "---" << myssbar_31 << "---" << myssbar_32 << "---" << myssbar_33 << "---" << endl;
                //...d quarks
                cout << " 8] ---d-quark--Structure-for-ttbar--Summary------------- " << endl;
                cout << "          Events with 2 d quarks: " << myEVE_dd << endl;
                cout << "                  Non 2 d Events: " << myEVE_nondd << endl;
                cout << "     d quark Details (IQ1=IQ2=1): " << endl;
                cout << "                d=0 (dbar=0-->3): " << myddbar_00 << "---" << myddbar_01 << "---" << myddbar_02 << "---" << myddbar_03 << "---" << endl;
                cout << "                d=1 (dbar=0-->3): " << myddbar_10 << "---" << myddbar_11 << "---" << myddbar_12 << "---" << myddbar_13 << "---" << endl;
                cout << "                d=2 (dbar=0-->3): " << myddbar_20 << "---" << myddbar_21 << "---" << myddbar_22 << "---" << myddbar_23 << "---" << endl;
                cout << "                d=3 (dbar=0-->3): " << myddbar_30 << "---" << myddbar_31 << "---" << myddbar_32 << "---" << myddbar_33 << "---" << endl;
                cout << " ======================================================== " << endl;
                cout << " ======================================================== " << endl;
                cout << "    " << endl;
                cout << "    " << endl;
                //
	}
}

// #############################################################################
bool ttH_dilep::CheckDoubleEvents(int run, int event) {
// #############################################################################
   static std::set<std::pair<int, int> > fRunEventPair;
   //check whether pair is already in set and processed, otherwise insert it in set
   return fRunEventPair.insert(std::make_pair(run,event)).second;
}


// #############################################################################
double ttH_dilep::DeltaR2( double eta1, double eta2, double phi1, double phi2){
// #############################################################################

  double deltaEta = eta1 - eta2 ; 
  double deltaPhi =
    (   phi1 > phi2 )?
    ( + phi1 - phi2 ):
    ( - phi1 + phi2 );
  if( deltaPhi > M_PI ) deltaPhi = 2 * M_PI - deltaPhi ; 
  
  double deltaR2 = pow( deltaEta, 2) + pow( deltaPhi, 2 );
  return deltaR2;

}


// #############################################################################
Int_t main(Int_t argc, char *argv[]){
// #############################################################################

	// run the analysis
	ttH_dilep *t = new ttH_dilep();
	t->Start(argc, argv);
	// exits
	return(0);

}


