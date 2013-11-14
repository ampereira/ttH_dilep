if (!isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Monte Carlo (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  double LumSys = corrlum;

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
  //
  #include "ALL_Define_Samples/DefineSamples_MC_variables_TRCR-12-01-07_7F.cxx"

  // -----------------------------------------------------------
  // Use samples already available in case selected
  // -----------------------------------------------------------
  // ttbar+LF Alpgen
  if (Sample == 801) {cout << "TTbarLF_Alpgen_8TeV" << endl;
    TTbarLF_Alpgen_8TeV  = 1;
  }
  // ttH ( mH = 125 GeV )
  if (Sample == 901) {cout << "Pythia8_AU2CTEQ6L1_ttH125_dilepbb_TEST" << endl;
    Pythia8_AU2CTEQ6L1_ttH125_dilepbb = 1;
  }

    // switch sample
    switch(Sample)
    {
	// =============================================================
        // ttbar -- AO 22 Mar 2013 --
	// =============================================================
        case 1: 
		// Alpgen+Jimmy
		AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ttbbincl = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ttccincl = 1;
                break;
        case 2: 
		// Powheg+Jimmy AUET2
		PowhegJimmy_AUET2CT10_ttbar_LeptonFilter_atlasfast = 1;
                break;
        case 3: 
		// Powheg+Pythia AUET2B
		PowhegPythia_AUET2BCT10_ttbar_LeptonFilter_atlasfast = 1;
                break;
        case 4: 
		// Powheg+Pythia P2011C
		PowhegPythia_P2011C_ttbar_atlasfast = 1;
                break;
        case 5: 
		// Acermc+Pythia AUET2B MorePS
		AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad_atlasfast = 1;
                break;
        case 6: 
		// Acermc+Pythia AUET2B LessPS
		AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad_atlasfast = 1;
                break;
        case 7: 
		// McAtNlo+Jimmy CT10
		McAtNloJimmy_CT10_ttbar_dilepton = 1;
                break;
        case 8: 
		// McAtNlo+Jimmy AUET2CT10 170GeV
		McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton_atlasfast = 1;
                break;
        case 9: 
		// McAtNlo+Jimmy AUET2CT10 175GeV
		McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton_atlasfast = 1;
                break;

	// =============================================================
        // single top -- AO 22 Mar 2013 --
	// =============================================================
        case 10: 
		// McAtNlo+Jimmy and AcerMC+Pythia
		McAtNloJimmy_AUET2CT10_SingleTopSChanWenu = 1;
		McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu = 1;
		McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu = 1;
		McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl = 1;
		AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e = 1;
		AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu = 1;
		AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau = 1;
                break;
/*
        // W+jets
        case 20:
                AlpgenPythia_P2011C_WenuNp0 = 1;
                AlpgenPythia_P2011C_WenuNp1 = 1;
                AlpgenPythia_P2011C_WenuNp2 = 1;
                AlpgenPythia_P2011C_WenuNp3 = 1;
                AlpgenPythia_P2011C_WenuNp4 = 1;
                AlpgenPythia_P2011C_WenuNp5 = 1;
                AlpgenPythia_P2011C_WmunuNp0 = 1;
                AlpgenPythia_P2011C_WmunuNp1 = 1;
                AlpgenPythia_P2011C_WmunuNp2 = 1;
                AlpgenPythia_P2011C_WmunuNp3 = 1;
                AlpgenPythia_P2011C_WmunuNp4 = 1;
                AlpgenPythia_P2011C_WmunuNp5 = 1;
                AlpgenPythia_P2011C_WtaunuNp0 = 1;
                AlpgenPythia_P2011C_WtaunuNp1 = 1;
                AlpgenPythia_P2011C_WtaunuNp2 = 1;
                AlpgenPythia_P2011C_WtaunuNp3 = 1;
                AlpgenPythia_P2011C_WtaunuNp4 = 1;
                AlpgenPythia_P2011C_WtaunuNp5 = 1;
                AlpgenPythia_P2011C_WbbNp0 = 1;
                AlpgenPythia_P2011C_WbbNp1 = 1;
                AlpgenPythia_P2011C_WbbNp2 = 1;
                AlpgenPythia_P2011C_WbbNp3 = 1;
                AlpgenPythia_P2011C_WcNp0 = 1;
                AlpgenPythia_P2011C_WcNp1 = 1;
                AlpgenPythia_P2011C_WcNp2 = 1;
                AlpgenPythia_P2011C_WcNp3 = 1;
                AlpgenPythia_P2011C_WcNp4 = 1;
                AlpgenPythia_P2011C_WccNp0 = 1;
                AlpgenPythia_P2011C_WccNp1 = 1;
                AlpgenPythia_P2011C_WccNp2 = 1;
                AlpgenPythia_P2011C_WccNp3 = 1;
                break;
*/
	// =============================================================
        // Z+jets -- 24 Mar 2013 --
	// =============================================================
        case 30:
		// Alpgen+Jimmy e,mu
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2 = 1;
                AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3 = 1;
                break;
	// =============================================================
        // Z+jets low mass samples -- 24 Mar 2013 --
	// =============================================================
        case 31:
		// Alpgen+Jimmy
		// Low Z mass samples e, mu ===
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60 = 1;
                AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60 = 1;
                break;
	// =============================================================
        // Ztautau+jets -- 24 Mar 2013 --
	// =============================================================
        case 32:
		// Alpgen+Jimmy taus
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3 = 1;
                break;
	// =============================================================
        // Z+jets low mass samples -- 24 Mar 2013 --
	// =============================================================
        case 33:
		// Alpgen+Jimmy
		// Low Z mass samples tau ===
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60 = 1;
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60 = 1;
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60 = 1;
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60 = 1;
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp4Excl_Mll10to60 = 1;
		AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60 = 1;
                break;
	// =============================================================
        // Z+jets -- 24 Mar 2013 --
	// =============================================================
        case 34:
		// Alpgen+Pythia e,mu
		AlpgenPythia_P2011C_ZeeNp0 = 1;
		AlpgenPythia_P2011C_ZeeNp1 = 1;
		AlpgenPythia_P2011C_ZeeNp2 = 1;
		AlpgenPythia_P2011C_ZeeNp3 = 1;
		AlpgenPythia_P2011C_ZeeNp4 = 1;
		AlpgenPythia_P2011C_ZeeNp5 = 1;
		AlpgenPythia_P2011C_ZmumuNp0 = 1;
		AlpgenPythia_P2011C_ZmumuNp1 = 1;
		AlpgenPythia_P2011C_ZmumuNp2 = 1;
		AlpgenPythia_P2011C_ZmumuNp3 = 1;
		AlpgenPythia_P2011C_ZmumuNp4 = 1;
		AlpgenPythia_P2011C_ZmumuNp5 = 1;
		AlpgenPythia_P2011C_ZeeccNp0 = 1;
		AlpgenPythia_P2011C_ZeeccNp1 = 1;
		AlpgenPythia_P2011C_ZeeccNp2 = 1;
		AlpgenPythia_P2011C_ZeeccNp3 = 1;
		AlpgenPythia_P2011C_ZmumuccNp0 = 1;
		AlpgenPythia_P2011C_ZmumuccNp1 = 1;
		AlpgenPythia_P2011C_ZmumuccNp2 = 1;
		AlpgenPythia_P2011C_ZmumuccNp3 = 1;
		AlpgenPythia_P2011C_ZeebbNp0 = 1;
		AlpgenPythia_P2011C_ZeebbNp1 = 1;
		AlpgenPythia_P2011C_ZeebbNp2 = 1;
		AlpgenPythia_P2011C_ZeebbNp3 = 1;
		AlpgenPythia_P2011C_ZmumubbNp0 = 1;
		AlpgenPythia_P2011C_ZmumubbNp1 = 1;
		AlpgenPythia_P2011C_ZmumubbNp2 = 1;
		AlpgenPythia_P2011C_ZmumubbNp3 = 1;
                break;
	// =============================================================
        // Ztautau+jets -- 24 Mar 2013 --
	// =============================================================
        case 35:
		// Alpgen+Pythia taus
		AlpgenPythia_P2011C_ZtautauNp0 = 1;
		AlpgenPythia_P2011C_ZtautauNp1 = 1;
		AlpgenPythia_P2011C_ZtautauNp2 = 1;
		AlpgenPythia_P2011C_ZtautauNp3 = 1;
		AlpgenPythia_P2011C_ZtautauNp4 = 1;
		AlpgenPythia_P2011C_ZtautauNp5 = 1;
		AlpgenPythia_P2011C_ZtautauccNp0 = 1;
		AlpgenPythia_P2011C_ZtautauccNp1 = 1;
		AlpgenPythia_P2011C_ZtautauccNp2 = 1;
		AlpgenPythia_P2011C_ZtautauccNp3 = 1;
		AlpgenPythia_P2011C_ZtautaubbNp0 = 1;
		AlpgenPythia_P2011C_ZtautaubbNp1 = 1;
		AlpgenPythia_P2011C_ZtautaubbNp2 = 1;
		AlpgenPythia_P2011C_ZtautaubbNp3 = 1;
                break;
	// =============================================================
        // Z+jets -- 24 Mar 2013 --
	// =============================================================
        case 36:
		// Sherpa e,mu
		Sherpa_CT10_Zee = 1;
		Sherpa_CT10_Zmumu = 1;
                break;
        case 136:
		// Sherpa e,mu MassiveCBPt0_BFilter
		Sherpa_CT10_ZeeMassiveCBPt0_BFilter_atlasfast = 1;
		Sherpa_CT10_ZmumuMassiveCBPt0_BFilter_atlasfast = 1;
                break;
        case 236:
		// Sherpa e,mu MassiveCBPt0_CFilterBVeto
		Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto_atlasfast = 1;
		Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto_atlasfast = 1;
                break;
        case 336:
		// Sherpa e,mu MassiveCBPt0_CVetoBVeto
		Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto_atlasfast = 1;
		Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto_atlasfast = 1;
                break;
	// =============================================================
        // Ztautau+jets -- 24 Mar 2013 --
	// =============================================================
        case 37:
		// Sherpa taus
		Sherpa_CT10_Ztautau = 1;
                break;
        case 137:
		// Sherpa taus MassiveCBPt0_BFilter
		Sherpa_CT10_ZtautauMassiveCBPt0_BFilter_atlasfast = 1;
                break;
        case 237:
		// Sherpa taus MassiveCBPt0_CFilterBVeto
		Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto_atlasfast = 1;
                break;
        case 337:
		// Sherpa taus MassiveCBPt0_CVetoBVeto
		Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto_atlasfast = 1;
                break;

	// =============================================================
        // Dibosons -- AO 22 Mar 2013 --
	// =============================================================
        case 40:
		AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2 = 1;
		AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3 = 1;
                break;

	// =============================================================
        // ttbar+X -- AO 22 Mar 2013 --
	// =============================================================
        case 50:
		MadGraphPythia_AUET2BCTEQ6L1_ttbarW = 1;
		MadGraphPythia_AUET2BCTEQ6L1_ttbarWj = 1;
		MadGraphPythia_AUET2BCTEQ6L1_ttbarZ = 1;
		MadGraphPythia_AUET2BCTEQ6L1_ttbarZj = 1;
		MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW = 1;
                break;

	// =============================================================
	// Signal -- AO 22 Mar 2013 --
	// =============================================================
        case 1000:
		Pythia8_AU2CTEQ6L1_ttH115_dilepbb = 1;
                break;
        case 1001:
		Pythia8_AU2CTEQ6L1_ttH120_dilepbb = 1;
                break;
        case 1002:
		Pythia8_AU2CTEQ6L1_ttH125_dilepbb = 1;
                break;
        case 1003: 
		Pythia8_AU2CTEQ6L1_ttH130_dilepbb = 1;
                break;
        case 1004: 
		Pythia8_AU2CTEQ6L1_ttH135_dilepbb = 1;
                break;
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

  #include "ALL_Define_Samples/DefineSamples_MC_code_TRCR-12-01-07_7F.cxx"

}
