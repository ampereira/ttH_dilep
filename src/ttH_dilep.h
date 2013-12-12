
#ifndef ttH_dilep_h
#define ttH_dilep_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
//#include "TLorentzVector.h"
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include "dilep_input.h"
#include "Riostream.h"
#include "../../LipMiniAnalysis/src/LipMiniAnalysis.h"

using std::cout;
using std::endl;

extern Int_t myEVE_Total;
//....semileptonic....
extern Int_t myEVE_semi_ele;
extern Int_t myEVE_semi_mu;
extern Int_t myEVE_semi_nontau_ele;
extern Int_t myEVE_semi_nontau_mu;
extern Int_t myEVE_semi_tau;
extern Int_t myEVE_semi_leptau;
extern Int_t myEVE_semi_eletau;
extern Int_t myEVE_semi_mutau;
//....dileptonic............with taus....
extern Int_t myEVE_di_eleele;
extern Int_t myEVE_di_mumu;
extern Int_t myEVE_di_elemu;
//....dileptonic............without taus....
extern Int_t myEVE_di_nontau_eleele;
extern Int_t myEVE_di_nontau_elemu;
extern Int_t myEVE_di_nontau_eletau;
extern Int_t myEVE_di_nontau_mumu;
extern Int_t myEVE_di_nontau_mutau;
extern Int_t myEVE_di_nontau_tautau;
//....multileptons............
extern Int_t myEVE_0leptons;
extern Int_t myEVE_3leptons;
extern Int_t myEVE_4leptons;
extern Int_t myEVE_more4leptons;
//...top quarks
extern Int_t myEVE_ttbar;
extern Int_t myEVE_4tops;
extern Int_t myEVE_nonttbar;
//.....................discriminate what ttbar events do we have.....
extern Int_t myttbar_00;
extern Int_t myttbar_01;
extern Int_t myttbar_02;
extern Int_t myttbar_03;
extern Int_t myttbar_10;
extern Int_t myttbar_11;
extern Int_t myttbar_12;
extern Int_t myttbar_13;
extern Int_t myttbar_20;
extern Int_t myttbar_21;
extern Int_t myttbar_22;
extern Int_t myttbar_23;
extern Int_t myttbar_30;
extern Int_t myttbar_31;
extern Int_t myttbar_32;
extern Int_t myttbar_33;
//...W bosons
extern Int_t myEVE_WW;
extern Int_t myEVE_4W;
extern Int_t myEVE_nonWW;
//.....................discriminate what bbbar events do we have.....
extern Int_t mybbbar_00;
extern Int_t mybbbar_01;
extern Int_t mybbbar_02;
extern Int_t mybbbar_03;
extern Int_t mybbbar_10;
extern Int_t mybbbar_11;
extern Int_t mybbbar_12;
extern Int_t mybbbar_13;
extern Int_t mybbbar_20;
extern Int_t mybbbar_21;
extern Int_t mybbbar_22;
extern Int_t mybbbar_23;
extern Int_t mybbbar_30;
extern Int_t mybbbar_31;
extern Int_t mybbbar_32;
extern Int_t mybbbar_33;
//...b quarks
extern Int_t myEVE_bb;
extern Int_t myEVE_4b;
extern Int_t myEVE_nonbb;
//.....................discriminate what ssbar events do we have.....
extern Int_t myssbar_00;
extern Int_t myssbar_01;
extern Int_t myssbar_02;
extern Int_t myssbar_03;
extern Int_t myssbar_10;
extern Int_t myssbar_11;
extern Int_t myssbar_12;
extern Int_t myssbar_13;
extern Int_t myssbar_20;
extern Int_t myssbar_21;
extern Int_t myssbar_22;
extern Int_t myssbar_23;
extern Int_t myssbar_30;
extern Int_t myssbar_31;
extern Int_t myssbar_32;
extern Int_t myssbar_33;
//...s quarks
extern Int_t myEVE_ss;
extern Int_t myEVE_4s;
extern Int_t myEVE_nonss;
//.....................discriminate what ddbar events do we have.....
extern Int_t myddbar_00;
extern Int_t myddbar_01;
extern Int_t myddbar_02;
extern Int_t myddbar_03;
extern Int_t myddbar_10;
extern Int_t myddbar_11;
extern Int_t myddbar_12;
extern Int_t myddbar_13;
extern Int_t myddbar_20;
extern Int_t myddbar_21;
extern Int_t myddbar_22;
extern Int_t myddbar_23;
extern Int_t myddbar_30;
extern Int_t myddbar_31;
extern Int_t myddbar_32;
extern Int_t myddbar_33;
//...d quarks
extern Int_t myEVE_dd;
extern Int_t myEVE_4d;
extern Int_t myEVE_nondd;
// #############################################################################
class ttH_dilep : public LipMiniAnalysis {
// #############################################################################
public:

  ttH_dilep();

  // signal pdf name
//  char* signalpdf;
  char signalpdf[100];

  // amostras para ler
  virtual void DefineSamples();
  virtual void UserValues();
  virtual void UserCommandLineOptions(char*, Int_t);
  virtual void DefineSignalPdfSamples();

  // stuff for selection levels
  virtual void DoCuts();
  virtual void first_DoCuts();
  virtual void second_DoCuts();

  // stuff for histograms
  virtual void BookHistograms(THistos&);
  virtual void FillHistograms(THistos&);

  // stuff for pdf
  virtual void BookPdfHistos(Int_t i_syst);
  virtual void PdfValues();

  virtual void preKinFit();
  // stuf for likelihoods
  virtual void BookLikeHistos();

  std::vector<DilepInput> inputs;

  // stuff for calculations

  Int_t event_counter;
  Int_t divideSample;
  
  Int_t leptonSep;
  Int_t lepSample;
  Int_t pileup;
  Int_t CutTriggerEle;
  Int_t CutTriggerMuo;
  Int_t CutTriggerEleMuo;
  Int_t m_hfor;

  Int_t alldata_ele;
  Int_t alldata_muo;

  Int_t ss_lep;
  Int_t ss_jets;
  Int_t ss_bjets;
  Int_t ss_goodbtaggedjet;
  Int_t ss_hardntjet;
 
  Double_t WtMass ;
  Double_t ctln ;

  Int_t ngs;

  // #############################################
  // Define Reference Mass Values
  // #############################################
  Double_t mW_UserValue ;   // W mass
  Double_t mt_UserValue ;   // top mass
  Double_t mH_UserValue ;   // Higgs mass

  // #############################################
  // stuff for ttDilepKinFit 20 December 2011
  // Objects are identified with  _ttDKF
  // #############################################
  // Solution Choice
  int ttDKF_SolutionChoice;
  // Choice of Jet Combination Scheme
  int ttDKF_JetCombChoice; 
  // Choice of Jet Combination Scheme
  int ttDKF_HiggsChoice; 
  // Choice of Number of Jets for Permutations
  int ttDKF_njet_UserValue; 
  int ttDKF_njets; 
  // top quark 1
  

  // ======================================================================================
  // Probabilities for reconstruction ....... samor 16.Dec.2012 ...........................
  // ======================================================================================


  // -----------------------------
  // Define pdf for Kinematcal Fit
  // -----------------------------
  int myNpdfKinFit;
  TH1D *pdfKinFit[100];
        double *pdfKinFitVec[100];
        int NBins[100];
  double LowerEdge[100], UpperEdge[100], Scale[100];

        TFile * fTruth;
  // -----------------------------


 // #############################################

        // #####################################################################
        // Miguel Fiolhais 10 Nov 2010  
        // #####################################################################
       /* int NbtagJet;
        std::vector<TLorentzVectorWFlags> MyGoodJetVec;
        std::vector<TLorentzVectorWFlags> MyGoodBtaggedJetVec;
        std::vector<TLorentzVectorWFlags> MyGoodNonBtaggedJetVec;*/
        

	// ######################################################################################
	// introduced by Miki + AO, Ocotber 17
	// ######################################################################################

	// measured variables
	/*double Ht;
	double Hz; //samor*/

        double pnupanu[4];

        // ======================================================================================
	// truth variables.......................................................................
        // ======================================================================================
        

	double Truth_WCosTheta1, Truth_WCosTheta2;
        
        // ======================================================================================
	// reconstructed variables...............................................................
        // ======================================================================================
        double NumberGoodSolutions, NumberGoodEvents, CosTheta1, CosTheta2;
	TLorentzVector Lepton1, Lepton2, B1, B2, Top1, Top2;

        

	double WCosTheta1, WCosTheta2;

        //_____Higgs Masses______


        // ======================================================================================
        // Truth versus Rec variables............................................................
        // ======================================================================================
        double Truth_myCosMlb_lp, Truth_myCosMlb_ln,
                 Rec_myCosMlb_lp,   Rec_myCosMlb_ln;
        double Truth_mylbMass_lp, Truth_mylbMass_ln,
                 Rec_mylbMass_lp,   Rec_mylbMass_ln;

        // ======================================================================================
        // Truth Leptons Reconstructed Correctly.................................................
        // ======================================================================================
        Int_t  Dilep_Truth_Reco_Match;
        // ======================================================================================
        // Matched Truth with Reconstructed Leptons, jets and missing for Resolution Studies.....
        // ======================================================================================

	// Random variables
	//TRandom3 rnd;

	// ######################################################################################

  double root1;

  Double_t corrlum;
  Double_t corrnorm_wjets;
  Double_t corrnorm_zjets;
  Double_t corrnorm_tt;
  Double_t corrnorm_wz;
  Double_t corrnorm_db;
  Double_t corrnorm_st;

  Double_t ptcut;
  Double_t cutwmass;
  Double_t cuttopmass;
  Double_t cutptjet;
  Double_t deltarmincut;
  Double_t cutsqrtchi2; 
  Double_t cutchi2;

  Int_t    nlepcut;
  Int_t    njetmin;

  Int_t ntagged;
  double ref_weight;


	// ######################################################################################
	// introduced by AO
	// ######################################################################################

        // =========================================================
        // ===== AO 8 Oct 2010 ===================== below =========
        // =========================================================
        //           Get MY OWN variables out of the box
        // =========================================================
        // ===== AO 8 Oct 2010 ===================== below =========
        // =========================================================

       /* Int_t myRunNumber;       //...run number

        //.................t
        Int_t my_ITQ;            //...line for top quark
        Int_t my_IQ1;            //...counter for top quark
        TLorentzVector my_t;
        //.................tbar
        Int_t my_ITB;            //...line for anti top quark
        Int_t my_IQ2;            //...counter for anti top quark
        TLorentzVector my_tb;


        //.................W+
        Int_t my_IWP;            //...line for W+
        Int_t my_IW1;            //...counter for W+
        TLorentzVector my_Wp;
        //.................W-
        Int_t my_IWN;            //...line for W-
        Int_t my_IW2;            //...counter for W-
        TLorentzVector my_Wn;


        //.................b
        Int_t my_IBQ;            //...line for b
        Int_t my_IB1;            //...counter for bb
        TLorentzVector my_b;
        //.................bb
        Int_t my_IBB;            //...line for bb
        Int_t my_IB2;            //...counter for bb
        TLorentzVector my_bb;


        //.................s
        Int_t my_ISQ;            //...line for s
        Int_t my_IS1;            //...counter for s
        TLorentzVector my_s;
        //.................sb
        Int_t my_ISB;            //...line for sb
        Int_t my_IS2;            //...counter for sb
        TLorentzVector my_sb;


        //.................d
        Int_t my_IDWQ;            //...line for d
        Int_t my_IDW1;            //...counter for d
        TLorentzVector my_dw;
        //.................db
        Int_t my_IDWB;            //...line for db
        Int_t my_IDW2;            //...counter for db
        TLorentzVector my_dwb;


        //.................W+->f1f2
        Int_t my_IWPf1;          //...line for f1
       	Int_t my_IWPf2;          //...line for f2
        Int_t my_IWPf1_Coun;     //...counter for f1
        Int_t my_IWPf2_Coun;     //...counter for f2
        Int_t my_IWPtau_Neu;     //...counter for Tau Neutrinos
        Int_t my_IWPtau_elNeu;   //...counter for ele Neutrinos (from tau decay)
        Int_t my_IWPtau_muNeu;   //...counter for muo Neutrino  (from tau decay)
        Int_t my_pdgID_Wp_dw;    //...Code of 1st W+ Daughter
        Int_t my_pdgID_Wp_up;    //...Code of 2nd W+ Daughter
        TLorentzVector my_Wpf1;
        TLorentzVector my_Wpf2;
        //.................W-->f1f2
        Int_t my_IWNf1;          //...line for f1
        Int_t my_IWNf2;          //...line for f2
        Int_t my_IWNf1_Coun;     //...counter for f1
        Int_t my_IWNf2_Coun;     //...counter for f2
        Int_t my_IWNtau_Neu;     //...counter for Tau Neutrinos
        Int_t my_IWNtau_elNeu;   //...counter for ele Neutrinos (from tau decay)
        Int_t my_IWNtau_muNeu;   //...counter for muo Neutrino  (from tau decay)
        Int_t my_pdgID_Wn_dw;    //...Code of 1st W- Daughter
        Int_t my_pdgID_Wn_up;    //...Code of 2nd W- Daughter
        TLorentzVector my_Wnf1;
        TLorentzVector my_Wnf2;*/
        // =========================================================
        // ===== AO 8 Oct 2010 ===================== above =========
        // =========================================================
        
        // =========================================================
        // ===== AO 8 Oct 2010 ===================== above =========
        // =========================================================
	// ######################################################################################

  /*Int_t ntruthlep;
  Int_t ntruthele;
  Int_t ntruthmu;
  Int_t ntrutheletau;
  Int_t ntruthmutau;
  Int_t ntruthtau;
  Int_t ntruthleptau;*/

  Double_t NonbJet1_weight;
  Double_t NonbJet2_weight;
  Double_t Leptonicb_weight;
  Double_t Hadronicb_weight;

  Double_t jet_weight[30];
  Int_t jet_ntracks[30];

  /*TLorentzVector ll;
  TLorentzVector llmiss;*/

  Int_t           PassedEF_mu20;
  Int_t           PassedEF_e20_loose;
  Int_t           PassedEF_mu10; //4 fev 2010 samor
  Int_t           PassedEF_e10_medium;

  Int_t           Passed_L1_EM2;//24.05.10 samor
  Int_t           Passed_L1_MU0;

  // AO 05.nov.2012 ================================================
  // New systematic error stuff
  double LumSys;
  double LumSysZj;
  double LumSysWj;
  double LumSysWZp;
  double LumSystt;
  double LumSysst;
  double SysPtLep;
  double SysPtJet;
  double SysPtPho;
  double SysPtMiss;
  double SysEtot;
  double SysPtGluon;
  double NBinFactor;
  // AO 05.nov.2012 ================================================

  ofstream of;
  ofstream f2;

  void Calculations();
  void Calculations2();
  void Calculations3();
  void ttDilepKinFit();

  std::vector<DilepInput> asdf (double, double, int, int, int);

  //stuff for after events loop
  virtual void PostLoopCalculations();

  TH2D *histo2D[50];

  // New stuff for duplicated events
  bool CheckDoubleEvents(int run, int event);

  // New stuff for Truth Matching
  bool isTruthMatched_Electron( int el_idx );
  bool isTruthMatched_Muon( int mu_idx );

  // Returns Delta R*R .
  virtual double DeltaR2( double eta1, double eta2, double phi1, double phi2);

};

#endif
