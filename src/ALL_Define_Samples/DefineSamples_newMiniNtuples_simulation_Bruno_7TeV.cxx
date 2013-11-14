if (!isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Monte Carlo (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  cout << "\n   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
  cout << "\n   ||         Non-existant Case(s): 1000, 1001, 1003, 1004        ||" << endl;
  cout << "\n   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

  double LumSys    = corrlum;
  double Lumm_syst = corrlum;

  double LumSysZj  = corrnorm_zjets;
  double LumSysWj  = corrnorm_wjets;
  double LumSystt  = corrnorm_tt;
  double LumSysWZp = corrnorm_db;
  double LumSysst  = corrnorm_st;

  double MCatNLOlum;

  // ------------------------------------------------------------
  // Initialize variables associated to samples already available
  // ------------------------------------------------------------
  Int_t Pythia8_AU2CTEQ6L1_ttH125_dilepbb_TEST = 0; 	// ttH ( mH = 125 GeV )
  Int_t TTbarLF_Alpgen_8TeV = 0;			// ttbar+LF Alpgen @ 8 TeV
  // .....intitalize non-existing ones in Bruno FDS as well............
  Int_t Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast = 0;
  Int_t Pythia8_AU2CTEQ6L1_ttH115_dilepbb = 0;
  Int_t Pythia8_AU2CTEQ6L1_ttH120_dilepbb = 0;
  Int_t Pythia8_AU2CTEQ6L1_ttH130_dilepbb = 0;
  Int_t Pythia8_AU2CTEQ6L1_ttH135_dilepbb = 0;
  //
  #include "ALL_Define_Samples/DefineSamples_MC_variables_Bruno_7TeV.cxx"

  // -----------------------------------------------------------
  // Use samples already available in case selected
  // -----------------------------------------------------------
  // ttbar+LF Alpgen
  if (Sample == 801) {cout << "TTbarLF_Alpgen_8TeV" << endl;
    TTbarLF_Alpgen_8TeV  = 1;
  }
  // ttH ( mH = 125 GeV )
  if (Sample == 901) {cout << "Pythia8_AU2CTEQ6L1_ttH125_dilepbb" << endl;
    Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast = 1;
  }

    // switch sample
    switch(Sample)
    {
	// =============================================================
        // ttbar FDS -- AO 18 May 2013 --
	// =============================================================
        case 7: // *** done ***
		// McAtNlo+Jimmy
		T1_McAtNlo_Jimmy_atlasfast = 1;
                break;
        case 2: // *** done ***
		// Powheg+Jimmy  ---------------------------------------------
		TTbar_PowHeg_Jimmy = 1;
                break;
        case 4: // *** done ***
		// Powheg+Pythia ---------------------------------------------
		TTbar_PowHeg_Pythia = 1;
                break;

	// =============================================================
        // single top FDS -- AO 18 May 2013 --
	// =============================================================
        case 10:// *** done ***
		// McAtNlo+Jimmy and AcerMC+Pythia
		st_tchan_enu_AcerMC   = 1;
		st_tchan_munu_AcerMC  = 1;
		st_tchan_taunu_AcerMC = 1;
		st_schan_enu_McAtNlo_Jimmy  = 1;
		st_schan_munu_McAtNlo_Jimmy = 1;
		st_schan_taunu_McAtNlo_Jimmy = 1;
		st_Wt_McAtNlo_Jimmy = 1;
                break;

	// =============================================================
        // W+jets
	// =============================================================
        case 20:// *** done ***
 		// Alpgen+Jimmy
		AlpgenJimmyWenuNp0_pt20 = 1;
		AlpgenJimmyWenuNp1_pt20 = 1;
		AlpgenJimmyWenuNp2_pt20 = 1;
		AlpgenJimmyWenuNp3_pt20 = 1;
		AlpgenJimmyWenuNp4_pt20 = 1;
		AlpgenJimmyWenuNp5_pt20 = 1;
		AlpgenJimmyWmunuNp0_pt20 = 1;
		AlpgenJimmyWmunuNp1_pt20 = 1;
		AlpgenJimmyWmunuNp2_pt20 = 1;
		AlpgenJimmyWmunuNp3_pt20 = 1;
		AlpgenJimmyWmunuNp4_pt20 = 1;
		AlpgenJimmyWmunuNp5_pt20 = 1;
		AlpgenJimmyWtaunuNp0_pt20 = 1;
		AlpgenJimmyWtaunuNp1_pt20 = 1;
		AlpgenJimmyWtaunuNp2_pt20 = 1;
		AlpgenJimmyWtaunuNp3_pt20 = 1;
		AlpgenJimmyWtaunuNp4_pt20 = 1;
		AlpgenJimmyWtaunuNp5_pt20 = 1;
		AlpgenJimmyWbbFullNp0_pt20 = 1;
		AlpgenJimmyWbbFullNp1_pt20 = 1;
		AlpgenJimmyWbbFullNp2_pt20 = 1;
		AlpgenJimmyWbbFullNp3_pt20 = 1;
		AlpgenWccFullNp0_pt20 = 1;
		AlpgenWccFullNp1_pt20 = 1;
		AlpgenWccFullNp2_pt20 = 1;
		AlpgenWccFullNp3_pt20 = 1;
		AlpgenWcNp0_pt20 = 1;
		AlpgenWcNp1_pt20 = 1;
		AlpgenWcNp2_pt20 = 1;
		AlpgenWcNp3_pt20 = 1;
		AlpgenWcNp4_pt20 = 1;
                break;

	// =============================================================
        // Z+jets FDS -- AO 18 May 2013 --
	// =============================================================
        case 30:// *** done ***
		// Alpgen+Jimmy e,mu
		AlpgenJimmyZeeNp0_pt20 = 1;
		AlpgenJimmyZeeNp1_pt20_atlasfast = 1;
		AlpgenJimmyZeeNp2_pt20_atlasfast = 1;
		AlpgenJimmyZeeNp3_pt20_atlasfast = 1;
		AlpgenJimmyZeeNp4_pt20_atlasfast = 1;
		AlpgenJimmyZeeNp5_pt20_atlasfast = 1;		
		AlpgenJimmyZmumuNp0_pt20 = 1;
		AlpgenJimmyZmumuNp1_pt20 = 1;
		AlpgenJimmyZmumuNp2_pt20 = 1;
		AlpgenJimmyZmumuNp3_pt20 = 1;
		AlpgenJimmyZmumuNp4_pt20_atlasfast = 1;
		AlpgenJimmyZmumuNp5_pt20_atlasfast = 1;		
		AlpgenJimmyZeebbNp0_nofilter = 1;
		AlpgenJimmyZeebbNp1_nofilter = 1;
		AlpgenJimmyZeebbNp2_nofilter = 1;
		AlpgenJimmyZeebbNp3_nofilter = 1;
		AlpgenJimmyZmumubbNp0_nofilter = 1;
		AlpgenJimmyZmumubbNp1_nofilter = 1;
		AlpgenJimmyZmumubbNp2_nofilter = 1;
		AlpgenJimmyZmumubbNp3_nofilter = 1;
                break;

	// =============================================================
        // Z+jets low mass samples FDS -- AO 18 May 2013 --
	// =============================================================
        case 31:// *** done ***
		// Alpgen+Jimmy
		// Low Z mass samples e, mu ===
		AlpgenJimmyZeeNp0_Mll10to40_pt20 = 1;
		AlpgenJimmyZeeNp1_Mll10to40_pt20 = 1;
		AlpgenJimmyZeeNp2_Mll10to40_pt20 = 1;
		AlpgenJimmyZeeNp3_Mll10to40_pt20 = 1;
		AlpgenJimmyZeeNp4_Mll10to40_pt20 = 1;
		AlpgenJimmyZeeNp5_Mll10to40_pt20_atlasfast = 1;
		AlpgenJimmyZmumuNp0_Mll10to40_pt20 = 1;
		AlpgenJimmyZmumuNp1_Mll10to40_pt20 = 1;
		AlpgenJimmyZmumuNp2_Mll10to40_pt20 = 1;
		AlpgenJimmyZmumuNp3_Mll10to40_pt20 = 1;
		AlpgenJimmyZmumuNp4_Mll10to40_pt20 = 1;
		AlpgenJimmyZmumuNp5_Mll10to40_pt20 = 1;
                break;

	// =============================================================
        // Ztautau+jets FDS -- AO 18 May 2013 --
	// =============================================================
        case 32:// *** done ***
		// Alpgen+Jimmy taus
		AlpgenJimmyZtautauNp0_pt20 = 1;
		AlpgenJimmyZtautauNp1_pt20 = 1;
		AlpgenJimmyZtautauNp2_pt20 = 1;
		AlpgenJimmyZtautauNp3_pt20 = 1;
		AlpgenJimmyZtautauNp4_pt20 = 1;
		AlpgenJimmyZtautauNp5_pt20 = 1;		
		AlpgenJimmyZtautaubbNp0_nofilter = 1;
		AlpgenJimmyZtautaubbNp1_nofilter = 1;
		AlpgenJimmyZtautaubbNp2_nofilter = 1;
		AlpgenJimmyZtautaubbNp3_nofilter = 1;
                break;

	// =============================================================
        // Z+jets FDS low mass samples -- 18 May 2013 --
	// =============================================================
        case 33:// *** done ***
		// Alpgen+Jimmy
		// Low Z mass samples tau ===
		AlpgenJimmyZtautauNp0_Mll10to40_pt20 = 1;
		AlpgenJimmyZtautauNp1_Mll10to40_pt20 = 1;
		AlpgenJimmyZtautauNp2_Mll10to40_pt20 = 1;
		AlpgenJimmyZtautauNp3_Mll10to40_pt20 = 1;
		AlpgenJimmyZtautauNp4_Mll10to40_pt20 = 1;
		AlpgenJimmyZtautauNp5_Mll10to40_pt20 = 1;
                break;

	// =============================================================
        // Dibosons FDS -- AO 18 Mar 2013 --
	// =============================================================
        case 40:// *** done *** 
		AlpgenJimmyWWlnulnuNp0_atlasfast = 1;
		AlpgenJimmyWWlnulnuNp1_atlasfast = 1;
		AlpgenJimmyWWlnulnuNp2_atlasfast = 1;
		AlpgenJimmyWWlnulnuNp3_atlasfast = 1;
		AlpgenJimmyWZincllNp0 = 1;
		AlpgenJimmyWZincllNp1 = 1;
		AlpgenJimmyWZincllNp2 = 1;
		AlpgenJimmyWZincllNp3 = 1;
		AlpgenJimmyZZincllNp0 = 1;
		AlpgenJimmyZZincllNp1 = 1;
		AlpgenJimmyZZincllNp2 = 1;
		AlpgenJimmyZZincllNp3 = 1;

	// =============================================================
        // ttbar+X FDS -- AO 18 May 2013 --
	// =============================================================
        case 50:// *** done ***
		PythiaMadgraph_ttbarW  = 1;
		PythiaMadgraph_ttbarWj = 1;
		PythiaMadgraph_ttbarZ  = 1;
		PythiaMadgraph_ttbarZj = 1;
		PythiaMadgraph_ttbarWW = 1;
                break;

	// -------------- NON EXISTANT SAMPLES IN THE FDS --------------------
        case 1000:// doesnt exist in FDS ---------------------------------------
		Pythia8_AU2CTEQ6L1_ttH115_dilepbb = 1;
                break;
        case 1001:// doesnt exist in FDS ---------------------------------------
		Pythia8_AU2CTEQ6L1_ttH120_dilepbb = 1;
                break;
        case 1003: // doesnt exist in FDS ---------------------------------------
		Pythia8_AU2CTEQ6L1_ttH130_dilepbb = 1;
                break;
        case 1004: // doesnt exist in FDS ---------------------------------------
		Pythia8_AU2CTEQ6L1_ttH135_dilepbb = 1;
                break;
	// -------------- NON EXISTANT SAMPLES IN THE FDS --------------------
    }

  // ----------------------------------------------------------------------------------------------------------------------------------------------- 
  // 								R E A D    N T U P L E S 
  // ----------------------------------------------------------------------------------------------------------------------------------------------- 
  // TMonteCarlo    Name  (1, Run Number, Luminosity, Events,            Label for Output               , MaxCuts); MonteCarlo.push_back(   Name  );
  // ----------------------------------------------------------------------------------------------------------------------------------------------- 
  // ttbar+LF Alpgen
  if ( TTbarLF_Alpgen_8TeV ) { 
    Input.File(ntu, "../Links/Data_MC_MarkOwen_8TeV/MC_Alpgen_tt-LF_8TeV.root");
    MCatNLOlum = Luminosity;   // Luminosity of sample
    TMonteCarlo mc_164440(1,     164440, MCatNLOlum,  106585, "195847_MC_Alpgen_tt-LF_8TeV", MaxCuts); MonteCarlo.push_back(mc_164440);
  }

  // ttH ( mH = 125 GeV )
  if ( Pythia8_AU2CTEQ6L1_ttH125_dilepbb_TEST ) {
    Input.File(ntu, "../Links/mini_Pythia8_AU2CTEQ6L1_ttH125_dilepbb.root");
    MCatNLOlum = Luminosity;   // Luminosity of sample
    TMonteCarlo mc_161871(1,     161871, MCatNLOlum,   5703, "161871_Pythia8_AU2CTEQ6L1_ttH125_dilepbb", MaxCuts); MonteCarlo.push_back(mc_161871);
  }

  #include "ALL_Define_Samples/DefineSamples_MC_code_Bruno_7TeV.cxx"

}
