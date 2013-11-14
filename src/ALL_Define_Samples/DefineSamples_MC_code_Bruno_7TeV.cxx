  if(T1_McAtNlo_Jimmy_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105200.T1_McAtNlo_Jimmy.EndProcMark.MINI.e835_a151_s1353_a145_r2993_p937.130524202952.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105200(1, 105200, 12355809.706670/90.545460/1000*LumSys*Lumm_syst, 15981985, "105200_T1_McAtNlo_Jimmy_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105200);
  }

  if(AcerMCttbar_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105205.AcerMCttbar.EndProcMark.MINI.e825_a131_s1353_a145_r2993_p937.130524203114.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105205(1, 105205, 1998843.919473/89.088840/1000*LumSys*Lumm_syst, 1998844, "105205_AcerMCttbar_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105205);
  }

  if(protos_ttbar_dilep_SM_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105366.protos_ttbar_dilep_SM.EndProcMark.MINI.e995_a131_s1353_a145_r2993_p937.130524202514.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105366(1, 105366, 499678.171175/10.000000/1000*LumSys*Lumm_syst, 499678, "105366_protos_ttbar_dilep_SM_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105366);
  }

  if(protos_ttbar_dilep_FR_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105367.protos_ttbar_dilep_FR.EndProcMark.MINI.e995_a131_s1353_a145_r2993_p937.130524202537.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105367(1, 105367, 1498452.280220/10.000000/1000*LumSys*Lumm_syst, 1498453, "105367_protos_ttbar_dilep_FR_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105367);
  }

  if(protos_ttbar_dilep_FL_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105368.protos_ttbar_dilep_FL.EndProcMark.MINI.e995_a131_s1353_a145_r2993_p937.130524202626.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105368(1, 105368, 1499031.296894/10.000000/1000*LumSys*Lumm_syst, 1499032, "105368_protos_ttbar_dilep_FL_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105368);
  }

  if(protos_ttbar_dilep_F0_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105369.protos_ttbar_dilep_F0.EndProcMark.MINI.e995_a131_s1353_a145_r2993_p937.130524202709.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105369(1, 105369, 1497618.203052/10.000000/1000*LumSys*Lumm_syst, 1497619, "105369_protos_ttbar_dilep_F0_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105369);
  }

  if(AcerMC_Wt){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105500.AcerMC_Wt.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524203137.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105500(1, 105500, 995085.403020/15.736560/1000*LumSys, 995084, "105500_AcerMC_Wt", MaxCuts);
    MonteCarlo.push_back(mc_105500);
  }

  if(toprex_tt_bWqgamma){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105510.toprex_tt_bWqgamma.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524203159.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105510(2, 105510, 99765.513041/1/1000*LumSys*Lumm_syst, 99766, "105510_toprex_tt_bWqgamma", MaxCuts);
    MonteCarlo.push_back(mc_105510);
  }

  if(toprex_tt_bWqZlep){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105511.toprex_tt_bWqZlep.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524203218.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105511(2, 105511, 99987.407723/1/1000*LumSys*Lumm_syst, 99987, "105511_toprex_tt_bWqZlep", MaxCuts);
    MonteCarlo.push_back(mc_105511);
  }

  if(toprex_tt_bWqZhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105513.toprex_tt_bWqZhad.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524203238.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105513(2, 105513, 100068.409850/1/1000*LumSys*Lumm_syst, 100068, "105513_toprex_tt_bWqZhad", MaxCuts);
    MonteCarlo.push_back(mc_105513);
  }

  if(toprex_tt_bWqZnu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105516.toprex_tt_bWqZnu.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524203258.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105516(2, 105516, 99925.169474/1/1000*LumSys*Lumm_syst, 99925, "105516_toprex_tt_bWqZnu", MaxCuts);
    MonteCarlo.push_back(mc_105516);
  }

  if(TTbar_PowHeg_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105860.TTbar_PowHeg_Jimmy.EndProcMark.MINI.e873_s1310_s1300_r3043_r2993_p937.130524203317.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105860(1, 105860, 500276.759858/90.552000/1000*LumSys*Lumm_syst, 500278, "105860_TTbar_PowHeg_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_105860);
  }

  if(TTbar_PowHeg_Pythia){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105861.TTbar_PowHeg_Pythia.EndProcMark.MINI.e873_s1372_s1370_r3043_r2993_p937.130524203338.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105861(1, 105861, 1999420.999467/90.570480/1000*LumSys*Lumm_syst, 1999422, "105861_TTbar_PowHeg_Pythia", MaxCuts);
    MonteCarlo.push_back(mc_105861);
  }

  if(McAtNlo_JIMMY_WpWm_enuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105921.McAtNlo_JIMMY_WpWm_enuenu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204246.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105921(1, 105921, 141776.169549/0.507200/1000*LumSys*LumSysWZp, 200024, "105921_McAtNlo_JIMMY_WpWm_enuenu", MaxCuts);
    MonteCarlo.push_back(mc_105921);
  }

  if(McAtNlo_JIMMY_WpWm_enumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105922.McAtNlo_JIMMY_WpWm_enumunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204307.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105922(1, 105922, 141517.177070/0.506200/1000*LumSys*LumSysWZp, 200044, "105922_McAtNlo_JIMMY_WpWm_enumunu", MaxCuts);
    MonteCarlo.push_back(mc_105922);
  }

  if(McAtNlo_JIMMY_WpWm_enutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105923.McAtNlo_JIMMY_WpWm_enutaunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204327.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105923(1, 105923, 141635.692877/0.504900/1000*LumSys*LumSysWZp, 200240, "105923_McAtNlo_JIMMY_WpWm_enutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105923);
  }

  if(McAtNlo_JIMMY_WpWm_munumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105924.McAtNlo_JIMMY_WpWm_munumunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204345.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105924(1, 105924, 140663.654875/0.505900/1000*LumSys*LumSysWZp, 199050, "105924_McAtNlo_JIMMY_WpWm_munumunu", MaxCuts);
    MonteCarlo.push_back(mc_105924);
  }

  if(McAtNlo_JIMMY_WpWm_munuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105925.McAtNlo_JIMMY_WpWm_munuenu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204406.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105925(1, 105925, 141408.867691/0.504300/1000*LumSys*LumSysWZp, 200011, "105925_McAtNlo_JIMMY_WpWm_munuenu", MaxCuts);
    MonteCarlo.push_back(mc_105925);
  }

  if(McAtNlo_JIMMY_WpWm_munutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105926.McAtNlo_JIMMY_WpWm_munutaunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204425.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105926(1, 105926, 141397.575516/0.508700/1000*LumSys*LumSysWZp, 199852, "105926_McAtNlo_JIMMY_WpWm_munutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105926);
  }

  if(McAtNlo_JIMMY_WpWm_taunutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105927.McAtNlo_JIMMY_WpWm_taunutaunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204445.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105927(1, 105927, 354180.312063/0.506300/1000*LumSys*LumSysWZp, 499723, "105927_McAtNlo_JIMMY_WpWm_taunutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105927);
  }

  if(McAtNlo_JIMMY_WpWm_taunuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105928.McAtNlo_JIMMY_WpWm_taunuenu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204505.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105928(1, 105928, 141441.402948/0.504400/1000*LumSys*LumSysWZp, 200048, "105928_McAtNlo_JIMMY_WpWm_taunuenu", MaxCuts);
    MonteCarlo.push_back(mc_105928);
  }

  if(McAtNlo_JIMMY_WpWm_taunumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105929.McAtNlo_JIMMY_WpWm_taunumunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204525.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105929(1, 105929, 141467.383391/0.504900/1000*LumSys*LumSysWZp, 199971, "105929_McAtNlo_JIMMY_WpWm_taunumunu", MaxCuts);
    MonteCarlo.push_back(mc_105929);
  }

  if(McAtNlo_JIMMY_ZZ_llll){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105931.McAtNlo_JIMMY_ZZ_llll.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204543.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105931(1, 105931, 69511.396028/-1.000000/1000*LumSys*LumSysWZp, 100164, "105931_McAtNlo_JIMMY_ZZ_llll", MaxCuts);
    MonteCarlo.push_back(mc_105931);
  }

  if(McAtNlo_JIMMY_ZZ_llnunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105932.McAtNlo_JIMMY_ZZ_llnunu.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204604.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105932(1, 105932, 69818.177534/-1.000000/1000*LumSys*LumSysWZp, 100038, "105932_McAtNlo_JIMMY_ZZ_llnunu", MaxCuts);
    MonteCarlo.push_back(mc_105932);
  }

  if(McAtNlo_JIMMY_WpZ_lnull){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105941.McAtNlo_JIMMY_WpZ_lnull.EndProcMark.MINI.e893_s1310_s1300_r3043_r2993_p937.130524204624.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105941(1, 105941, 18631.604056/-1.000000/1000*LumSys*LumSysWZp, 24970, "105941_McAtNlo_JIMMY_WpZ_lnull", MaxCuts);
    MonteCarlo.push_back(mc_105941);
  }

  if(McAtNlo_JIMMY_WmZ_lnull){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105971.McAtNlo_JIMMY_WmZ_lnull.EndProcMark.MINI.e872_s1310_s1300_r3043_r2993_p937.130524204644.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105971(1, 105971, 74294.356095/-1.000000/1000*LumSys*LumSysWZp, 100127, "105971_McAtNlo_JIMMY_WmZ_lnull", MaxCuts);
    MonteCarlo.push_back(mc_105971);
  }

  if(WW_Herwig){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105985.WW_Herwig.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524204705.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105985(1, 105985, 2489321.864249/17.020444/1000*LumSys*LumSysWZp, 2489323, "105985_WW_Herwig", MaxCuts);
    MonteCarlo.push_back(mc_105985);
  }

  if(ZZ_Herwig){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105986.ZZ_Herwig.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524204750.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105986(1, 105986, 250104.172751/1.263860/1000*LumSys*LumSysWZp, 250104, "105986_ZZ_Herwig", MaxCuts);
    MonteCarlo.push_back(mc_105986);
  }

  if(WZ_Herwig){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.105987.WZ_Herwig.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524204811.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105987(1, 105987, 999930.208528/5.542560/1000*LumSys*LumSysWZp, 999931, "105987_WZ_Herwig", MaxCuts);
    MonteCarlo.push_back(mc_105987);
  }

  if(TTbar_McAtNlo_Jimmy_170GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106201.TTbar_McAtNlo_Jimmy_170GeV.EndProcMark.MINI.e1021_a131_s1353_a145_r2993_p937.130524204834.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106201(1, 106201, 3862210.230080/96.308800/1000*LumSys*Lumm_syst, 4998870, "106201_TTbar_McAtNlo_Jimmy_170GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106201);
  }

  if(TTbar_McAtNlo_Jimmy_180GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106202.TTbar_McAtNlo_Jimmy_180GeV.EndProcMark.MINI.e967_a131_s1353_a145_r2993_p937.130524204906.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106202(1, 106202, 4975526.250601/72.524300/1000*LumSys*Lumm_syst, 6420525, "106202_TTbar_McAtNlo_Jimmy_180GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106202);
  }

  if(TTbar_McAtNlo_Jimmy_160GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106203.TTbar_McAtNlo_Jimmy_160GeV.EndProcMark.MINI.e1021_a131_s1353_a145_r2993_p937.130524205004.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106203(1, 106203, 3836363.439014/131.398400/1000*LumSys*Lumm_syst, 4982918, "106203_TTbar_McAtNlo_Jimmy_160GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106203);
  }

  if(TTbar_McAtNlo_Jimmy_190GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106204.TTbar_McAtNlo_Jimmy_190GeV.EndProcMark.MINI.e1021_a131_s1353_a145_r2993_p937.130524205037.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106204(1, 106204, 3879636.048977/54.017600/1000*LumSys*Lumm_syst, 4993012, "106204_TTbar_McAtNlo_Jimmy_190GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106204);
  }

  if(TTbar_McAtNlo_Jimmy_167GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106205.TTbar_McAtNlo_Jimmy_167GeV.EndProcMark.MINI.e1019_a131_s1353_a145_r2993_p937.130524205110.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106205(1, 106205, 7707332.014814/104.059200/1000*LumSys*Lumm_syst, 9982092, "106205_TTbar_McAtNlo_Jimmy_167GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106205);
  }

  if(TTbar_McAtNlo_Jimmy_175GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106206.TTbar_McAtNlo_Jimmy_175GeV.EndProcMark.MINI.e1021_a131_s1353_a145_r2993_p937.130524205155.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106206(1, 106206, 3857566.868066/83.216000/1000*LumSys*Lumm_syst, 4986478, "106206_TTbar_McAtNlo_Jimmy_175GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106206);
  }

  if(TTbar_McAtNlo_Jimmy_177GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106207.TTbar_McAtNlo_Jimmy_177GeV.EndProcMark.MINI.e1019_a131_s1353_a145_r2993_p937.130524205231.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106207(1, 106207, 7735924.749240/77.089600/1000*LumSys*Lumm_syst, 9990947, "106207_TTbar_McAtNlo_Jimmy_177GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106207);
  }

  if(TTbar_McAtNlo_Jimmy_165GeV_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.106208.TTbar_McAtNlo_Jimmy_165GeV.EndProcMark.MINI.e1021_a131_s1353_a145_r2993_p937.130524205309.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106208(1, 106208, 3856330.094868/112.593600/1000*LumSys*Lumm_syst, 4996216, "106208_TTbar_McAtNlo_Jimmy_165GeV_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106208);
  }

  if(AlpgenJimmyWWlnulnuNp0_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107100.AlpgenJimmyWWlnulnuNp0.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524205340.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107100(1, 107100, 200116.038440/2.639700/1000*LumSys*LumSysWZp, 200116, "107100_AlpgenJimmyWWlnulnuNp0_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107100);
  }

  if(AlpgenJimmyWWlnulnuNp1_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107101.AlpgenJimmyWWlnulnuNp1.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524205401.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107101(1, 107101, 198127.813849/1.255212/1000*LumSys*LumSysWZp, 198127, "107101_AlpgenJimmyWWlnulnuNp1_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107101);
  }

  if(AlpgenJimmyWWlnulnuNp2_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107102.AlpgenJimmyWWlnulnuNp2.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524205442.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107102(1, 107102, 119999.872126/0.572922/1000*LumSys*LumSysWZp, 120000, "107102_AlpgenJimmyWWlnulnuNp2_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107102);
  }

  if(AlpgenJimmyWWlnulnuNp3_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107103.AlpgenJimmyWWlnulnuNp3.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524205531.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107103(1, 107103, 40014.719441/0.221508/1000*LumSys*LumSysWZp, 40015, "107103_AlpgenJimmyWWlnulnuNp3_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107103);
  }

  if(AlpgenJimmyWZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107104.AlpgenJimmyWZincllNp0.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205551.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107104(1, 107104, 59950.437970/0.859904/1000*LumSys*LumSysWZp, 59950, "107104_AlpgenJimmyWZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107104);
  }

  if(AlpgenJimmyWZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107105.AlpgenJimmyWZincllNp1.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205616.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107105(1, 107105, 40019.608017/0.529664/1000*LumSys*LumSysWZp, 40020, "107105_AlpgenJimmyWZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107105);
  }

  if(AlpgenJimmyWZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107106.AlpgenJimmyWZincllNp2.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205638.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107106(1, 107106, 20005.197830/0.287872/1000*LumSys*LumSysWZp, 20005, "107106_AlpgenJimmyWZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107106);
  }

  if(AlpgenJimmyWZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107107.AlpgenJimmyWZincllNp3.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205701.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107107(1, 107107, 20008.973932/0.121600/1000*LumSys*LumSysWZp, 20009, "107107_AlpgenJimmyWZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107107);
  }

  if(AlpgenJimmyZZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107108.AlpgenJimmyZZincllNp0.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205723.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107108(1, 107108, 40025.997177/0.661180/1000*LumSys*LumSysWZp, 40026, "107108_AlpgenJimmyZZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107108);
  }

  if(AlpgenJimmyZZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107109.AlpgenJimmyZZincllNp1.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205745.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107109(1, 107109, 20005.197830/0.304460/1000*LumSys*LumSysWZp, 20005, "107109_AlpgenJimmyZZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107109);
  }

  if(AlpgenJimmyZZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107110.AlpgenJimmyZZincllNp2.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205807.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107110(1, 107110, 19995.427732/0.115180/1000*LumSys*LumSysWZp, 19995, "107110_AlpgenJimmyZZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107110);
  }

  if(AlpgenJimmyZZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107111.AlpgenJimmyZZincllNp3.EndProcMark.MINI.e995_s1372_s1370_r3043_r2993_p937.130524205828.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107111(1, 107111, 10004.045373/0.040820/1000*LumSys*LumSysWZp, 10004, "107111_AlpgenJimmyZZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107111);
  }

  if(AlpgenJimmyWbbFullNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107280.AlpgenJimmyWbbFullNp0_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524205848.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107280(1, 107280, 444683.419484/56.820000/1000*LumSys*LumSysWj, 444684, "107280_AlpgenJimmyWbbFullNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107280);
  }

  if(AlpgenJimmyWbbFullNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107281.AlpgenJimmyWbbFullNp1_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524205907.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107281(1, 107281, 186185.909209/42.912000/1000*LumSys*LumSysWj, 186186, "107281_AlpgenJimmyWbbFullNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107281);
  }

  if(AlpgenJimmyWbbFullNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107282.AlpgenJimmyWbbFullNp2_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524205926.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107282(1, 107282, 155658.362608/20.796000/1000*LumSys*LumSysWj, 155658, "107282_AlpgenJimmyWbbFullNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107282);
  }

  if(AlpgenJimmyWbbFullNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107283.AlpgenJimmyWbbFullNp3_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524205949.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107283(1, 107283, 60198.508467/9.132000/1000*LumSys*LumSysWj, 60199, "107283_AlpgenJimmyWbbFullNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107283);
  }

  if(AlpgenJimmyZeeNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107650.AlpgenJimmyZeeNp0_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524210013.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107650(1, 107650, 6607885.809381/835.400000/1000*LumSys*LumSysZj, 6607887, "107650_AlpgenJimmyZeeNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107650);
  }

  if(AlpgenJimmyZeeNp1_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107651.AlpgenJimmyZeeNp1_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524210145.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107651(1, 107651, 3213006.680206/167.950000/1000*LumSys*LumSysZj, 3213005, "107651_AlpgenJimmyZeeNp1_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107651);
  }

  if(AlpgenJimmyZeeNp2_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107652.AlpgenJimmyZeeNp2_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524210400.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107652(1, 107652, 2829356.838954/50.675000/1000*LumSys*LumSysZj, 2829357, "107652_AlpgenJimmyZeeNp2_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107652);
  }

  if(AlpgenJimmyZeeNp3_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107653.AlpgenJimmyZeeNp3_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524210626.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107653(1, 107653, 875441.020699/13.950000/1000*LumSys*LumSysZj, 875441, "107653_AlpgenJimmyZeeNp3_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107653);
  }

  if(AlpgenJimmyZeeNp4_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107654.AlpgenJimmyZeeNp4_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524210857.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107654(1, 107654, 283674.748802/3.600000/1000*LumSys*LumSysZj, 283674, "107654_AlpgenJimmyZeeNp4_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107654);
  }

  if(AlpgenJimmyZeeNp5_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107655.AlpgenJimmyZeeNp5_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524211005.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107655(1, 107655, 89894.498160/1.037500/1000*LumSys*LumSysZj, 89894, "107655_AlpgenJimmyZeeNp5_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107655);
  }

  if(AlpgenJimmyZmumuNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107660.AlpgenJimmyZmumuNp0_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524211134_rev43493.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107660(1, 107660, 6604415.395412/835.850000/1000*LumSys*LumSysZj, 6604416, "107660_AlpgenJimmyZmumuNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107660);
  }

  if(AlpgenJimmyZmumuNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107661.AlpgenJimmyZmumuNp1_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524211305_rev43277.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107661(1, 107661, 1324673.063566/167.675000/1000*LumSys*LumSysZj, 1324673, "107661_AlpgenJimmyZmumuNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107661);
  }

  if(AlpgenJimmyZmumuNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107662.AlpgenJimmyZmumuNp2_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524211347.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107662(1, 107662, 1968707.586021/50.412500/1000*LumSys*LumSysZj, 1968708, "107662_AlpgenJimmyZmumuNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107662);
  }

  if(AlpgenJimmyZmumuNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107663.AlpgenJimmyZmumuNp3_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524211513.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107663(1, 107663, 535217.891788/13.987500/1000*LumSys*LumSysZj, 535217, "107663_AlpgenJimmyZmumuNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107663);
  }

  if(AlpgenJimmyZmumuNp4_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107664.AlpgenJimmyZmumuNp4_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524211618.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107664(1, 107664, 283784.173386/3.437500/1000*LumSys*LumSysZj, 283784, "107664_AlpgenJimmyZmumuNp4_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107664);
  }

  if(AlpgenJimmyZmumuNp5_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107665.AlpgenJimmyZmumuNp5_pt20.EndProcMark.MINI.e835_a131_s1353_a145_r2993_p937.130524211738.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107665(1, 107665, 89879.878213/0.962500/1000*LumSys*LumSysZj, 89880, "107665_AlpgenJimmyZmumuNp5_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_107665);
  }

  if(AlpgenJimmyZtautauNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107670.AlpgenJimmyZtautauNp0_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524211942_rev43489.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107670(1, 107670, 10597468.054615/835.500000/1000*LumSys*LumSysZj, 10597470, "107670_AlpgenJimmyZtautauNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107670);
  }

  if(AlpgenJimmyZtautauNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107671.AlpgenJimmyZtautauNp1_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524212026_rev43485.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107671(1, 107671, 3310660.456239/168.512500/1000*LumSys*LumSysZj, 3310661, "107671_AlpgenJimmyZtautauNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107671);
  }

  if(AlpgenJimmyZtautauNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107672.AlpgenJimmyZtautauNp2_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524212138.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107672(1, 107672, 989066.836277/50.450000/1000*LumSys*LumSysZj, 989066, "107672_AlpgenJimmyZtautauNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107672);
  }

  if(AlpgenJimmyZtautauNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107673.AlpgenJimmyZtautauNp3_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524212218.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107673(1, 107673, 495749.718343/14.062500/1000*LumSys*LumSysZj, 495750, "107673_AlpgenJimmyZtautauNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107673);
  }

  if(AlpgenJimmyZtautauNp4_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107674.AlpgenJimmyZtautauNp4_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524212240.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107674(1, 107674, 139136.729961/3.487500/1000*LumSys*LumSysZj, 139137, "107674_AlpgenJimmyZtautauNp4_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107674);
  }

  if(AlpgenJimmyZtautauNp5_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107675.AlpgenJimmyZtautauNp5_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524212307_rev43523.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107675(1, 107675, 42627.529570/0.962500/1000*LumSys*LumSysZj, 42628, "107675_AlpgenJimmyZtautauNp5_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107675);
  }

  if(AlpgenJimmyWenuNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107680.AlpgenJimmyWenuNp0_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212413.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107680(1, 107680, 6727746.507550/8288.878000/1000*LumSys*LumSysWj, 6727748, "107680_AlpgenJimmyWenuNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107680);
  }

  if(AlpgenJimmyWenuNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107681.AlpgenJimmyWenuNp1_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212448.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107681(1, 107681, 4312819.491827/1561.138800/1000*LumSys*LumSysWj, 4312820, "107681_AlpgenJimmyWenuNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107681);
  }

  if(AlpgenJimmyWenuNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107682.AlpgenJimmyWenuNp2_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212521.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107682(1, 107682, 3013066.896363/452.243480/1000*LumSys*LumSysWj, 3013065, "107682_AlpgenJimmyWenuNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107682);
  }

  if(AlpgenJimmyWenuNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107683.AlpgenJimmyWenuNp3_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212635.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107683(1, 107683, 777052.701543/121.824560/1000*LumSys*LumSysWj, 777053, "107683_AlpgenJimmyWenuNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107683);
  }

  if(AlpgenJimmyWenuNp4_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107684.AlpgenJimmyWenuNp4_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212710.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107684(1, 107684, 560768.017528/30.713280/1000*LumSys*LumSysWj, 560769, "107684_AlpgenJimmyWenuNp4_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107684);
  }

  if(AlpgenJimmyWenuNp5_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107685.AlpgenJimmyWenuNp5_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212739.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107685(1, 107685, 310528.121686/8.360040/1000*LumSys*LumSysWj, 310528, "107685_AlpgenJimmyWenuNp5_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107685);
  }

  if(AlpgenJimmyWmunuNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107690.AlpgenJimmyWmunuNp0_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212840.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107690(1, 107690, 6737305.825314/8284.218000/1000*LumSys*LumSysWj, 6737306, "107690_AlpgenJimmyWmunuNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107690);
  }

  if(AlpgenJimmyWmunuNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107691.AlpgenJimmyWmunuNp1_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524212951.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107691(1, 107691, 4302524.812989/1560.550500/1000*LumSys*LumSysWj, 4302526, "107691_AlpgenJimmyWmunuNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107691);
  }

  if(AlpgenJimmyWmunuNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107692.AlpgenJimmyWmunuNp2_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524213048.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107692(1, 107692, 3014084.175663/451.793650/1000*LumSys*LumSysWj, 3014082, "107692_AlpgenJimmyWmunuNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107692);
  }

  if(AlpgenJimmyWmunuNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107693.AlpgenJimmyWmunuNp3_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524213116.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107693(1, 107693, 776119.315419/121.710750/1000*LumSys*LumSysWj, 776120, "107693_AlpgenJimmyWmunuNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107693);
  }

  if(AlpgenJimmyWmunuNp4_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107694.AlpgenJimmyWmunuNp4_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524213157.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107694(1, 107694, 568580.849622/30.735400/1000*LumSys*LumSysWj, 568580, "107694_AlpgenJimmyWmunuNp4_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107694);
  }

  if(AlpgenJimmyWmunuNp5_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107695.AlpgenJimmyWmunuNp5_pt20.EndProcMark.MINI.e825_s1299_s1300_r3043_r2993_p937.130524213229_rev43291.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107695(1, 107695, 309038.764372/8.365000/1000*LumSys*LumSysWj, 309039, "107695_AlpgenJimmyWmunuNp5_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107695);
  }

  if(AlpgenJimmyWtaunuNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107700.AlpgenJimmyWtaunuNp0_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213328.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107700(1, 107700, 3307280.057071/8283.501000/1000*LumSys*LumSysWj, 3307282, "107700_AlpgenJimmyWtaunuNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107700);
  }

  if(AlpgenJimmyWtaunuNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107701.AlpgenJimmyWtaunuNp1_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213355.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107701(1, 107701, 2156822.958758/1559.355500/1000*LumSys*LumSysWj, 2156823, "107701_AlpgenJimmyWtaunuNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107701);
  }

  if(AlpgenJimmyWtaunuNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107702.AlpgenJimmyWtaunuNp2_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213439.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107702(1, 107702, 2998688.836838/451.626350/1000*LumSys*LumSysWj, 2998687, "107702_AlpgenJimmyWtaunuNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107702);
  }

  if(AlpgenJimmyWtaunuNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107703.AlpgenJimmyWtaunuNp3_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213510.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107703(1, 107703, 778634.099367/121.842200/1000*LumSys*LumSysWj, 778634, "107703_AlpgenJimmyWtaunuNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107703);
  }

  if(AlpgenJimmyWtaunuNp4_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107704.AlpgenJimmyWtaunuNp4_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213540.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107704(1, 107704, 188417.517352/30.723450/1000*LumSys*LumSysWj, 188418, "107704_AlpgenJimmyWtaunuNp4_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107704);
  }

  if(AlpgenJimmyWtaunuNp5_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.107705.AlpgenJimmyWtaunuNp5_pt20.EndProcMark.MINI.e835_s1299_s1300_r3043_r2993_p937.130524213608.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107705(1, 107705, 48034.285035/8.365000/1000*LumSys*LumSysWj, 48034, "107705_AlpgenJimmyWtaunuNp5_pt20", MaxCuts);
    MonteCarlo.push_back(mc_107705);
  }

  if(st_tchan_enu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108340.st_tchan_enu_McAtNlo_Jimmy.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524213634.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108340(1, 108340, 177112.790203/6.970480/1000*LumSys*LumSysst, 299871, "108340_st_tchan_enu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108340);
  }

  if(st_tchan_munu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108341.st_tchan_munu_McAtNlo_Jimmy.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524213655.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108341(1, 108341, 176650.308657/6.970480/1000*LumSys*LumSysst, 299594, "108341_st_tchan_munu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108341);
  }

  if(st_tchan_taunu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108342.st_tchan_taunu_McAtNlo_Jimmy.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524213718.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108342(1, 108342, 176730.417565/6.972200/1000*LumSys*LumSysst, 300387, "108342_st_tchan_taunu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108342);
  }

  if(st_schan_enu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108343.st_schan_enu_McAtNlo_Jimmy.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524213740.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108343(1, 108343, 253542.738408/0.500080/1000*LumSys*LumSysst, 300101, "108343_st_schan_enu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108343);
  }

  if(st_schan_munu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108344.st_schan_munu_McAtNlo_Jimmy.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130524213809.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108344(1, 108344, 253733.419002/0.500080/1000*LumSys*LumSysst, 300163, "108344_st_schan_munu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108344);
  }

  if(st_schan_taunu_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108345.st_schan_taunu_McAtNlo_Jimmy.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524213830.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108345(1, 108345, 253325.266527/0.500080/1000*LumSys*LumSysst, 299677, "108345_st_schan_taunu_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108345);
  }

  if(st_Wt_McAtNlo_Jimmy){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.108346.st_Wt_McAtNlo_Jimmy.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524213851.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108346(1, 108346, 796850.302585/15.742610/1000*LumSys*LumSysst, 899495, "108346_st_Wt_McAtNlo_Jimmy", MaxCuts);
    MonteCarlo.push_back(mc_108346);
  }

  if(AlpgenJimmyZeebbNp0_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109300.AlpgenJimmyZeebbNp0_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524213921.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109300(1, 109300, 400189.203681/8.212500/1000*LumSys*LumSysZj, 400189, "109300_AlpgenJimmyZeebbNp0_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109300);
  }

  if(AlpgenJimmyZeebbNp1_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109301.AlpgenJimmyZeebbNp1_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214059.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109301(1, 109301, 151612.135993/3.100000/1000*LumSys*LumSysZj, 151612, "109301_AlpgenJimmyZeebbNp1_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109301);
  }

  if(AlpgenJimmyZeebbNp2_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109302.AlpgenJimmyZeebbNp2_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214137.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109302(1, 109302, 55250.229282/1.112500/1000*LumSys*LumSysZj, 55250, "109302_AlpgenJimmyZeebbNp2_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109302);
  }

  if(AlpgenJimmyZeebbNp3_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109303.AlpgenJimmyZeebbNp3_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214159.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109303(1, 109303, 26525.807508/0.487500/1000*LumSys*LumSysZj, 26525, "109303_AlpgenJimmyZeebbNp3_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109303);
  }

  if(AlpgenJimmyZmumubbNp0_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109305.AlpgenJimmyZmumubbNp0_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214246.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109305(1, 109305, 400150.209063/8.200000/1000*LumSys*LumSysZj, 400150, "109305_AlpgenJimmyZmumubbNp0_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109305);
  }

  if(AlpgenJimmyZmumubbNp1_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109306.AlpgenJimmyZmumubbNp1_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214318.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109306(1, 109306, 146542.927095/3.087500/1000*LumSys*LumSysZj, 146543, "109306_AlpgenJimmyZmumubbNp1_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109306);
  }

  if(AlpgenJimmyZmumubbNp2_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109307.AlpgenJimmyZmumubbNp2_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524214351.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109307(1, 109307, 55278.450216/1.112500/1000*LumSys*LumSysZj, 55278, "109307_AlpgenJimmyZmumubbNp2_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109307);
  }

  if(AlpgenJimmyZmumubbNp3_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109308.AlpgenJimmyZmumubbNp3_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524220035.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109308(1, 109308, 26625.234263/0.487500/1000*LumSys*LumSysZj, 26625, "109308_AlpgenJimmyZmumubbNp3_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109308);
  }

  if(AlpgenJimmyZtautaubbNp0_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109310.AlpgenJimmyZtautaubbNp0_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524220144.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109310(1, 109310, 146498.360910/8.212500/1000*LumSys*LumSysZj, 146498, "109310_AlpgenJimmyZtautaubbNp0_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109310);
  }

  if(AlpgenJimmyZtautaubbNp1_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109311.AlpgenJimmyZtautaubbNp1_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524220221.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109311(1, 109311, 94661.187903/3.112500/1000*LumSys*LumSysZj, 94661, "109311_AlpgenJimmyZtautaubbNp1_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109311);
  }

  if(AlpgenJimmyZtautaubbNp2_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109312.AlpgenJimmyZtautaubbNp2_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524220255.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109312(1, 109312, 36798.581427/1.112500/1000*LumSys*LumSysZj, 36799, "109312_AlpgenJimmyZtautaubbNp2_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109312);
  }

  if(AlpgenJimmyZtautaubbNp3_nofilter){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.109313.AlpgenJimmyZtautaubbNp3_nofilter.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130524220335.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109313(1, 109313, 7897.514539/0.487500/1000*LumSys*LumSysZj, 7898, "109313_AlpgenJimmyZtautaubbNp3_nofilter", MaxCuts);
    MonteCarlo.push_back(mc_109313);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.110600.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep.EndProcMark.MINI.e1742_a131_s1353_a145_r2993_p937.130524202751.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110600(1, 110600, 600348.164768/0.000279/1000*LumSys, 600348, "110600_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110600);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.110601.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170.EndProcMark.MINI.e1742_a131_s1353_a145_r2993_p937.130524202830_rev43265.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110601(1, 110601, 299962.236488/0.000287/1000*LumSys, 299962, "110601_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110601);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.110602.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175.EndProcMark.MINI.e1742_a131_s1353_a145_r2993_p937.130524202848.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110602(1, 110602, 299973.775309/0.000271/1000*LumSys, 299974, "110602_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110602);
  }

  if(ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.110603.ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep.EndProcMark.MINI.e1742_a131_s1353_a145_r2993_p937.130524202909.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110603(1, 110603, 300128.886171/0.000279/1000*LumSys, 300129, "110603_ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110603);
  }

  if(ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.110604.ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep.EndProcMark.MINI.e1742_a131_s1353_a145_r2993_p937.130524202930.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110604(1, 110604, 300030.570899/0.000279/1000*LumSys, 300030, "110604_ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110604);
  }

  if(AlpgenJimmyZeeNp0_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116250.AlpgenJimmyZeeNp0_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524220728.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116250(1, 116250, 994706.278844/3819.000000/1000*LumSys*LumSysZj, 994706, "116250_AlpgenJimmyZeeNp0_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116250);
  }

  if(AlpgenJimmyZeeNp1_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116251.AlpgenJimmyZeeNp1_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524220755.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116251(1, 116251, 300020.188943/106.150000/1000*LumSys*LumSysZj, 300020, "116251_AlpgenJimmyZeeNp1_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116251);
  }

  if(AlpgenJimmyZeeNp2_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116252.AlpgenJimmyZeeNp2_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524220821.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116252(1, 116252, 999768.838705/51.750000/1000*LumSys*LumSysZj, 999768, "116252_AlpgenJimmyZeeNp2_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116252);
  }

  if(AlpgenJimmyZeeNp3_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116253.AlpgenJimmyZeeNp3_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524220843.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116253(1, 116253, 149847.219004/10.475000/1000*LumSys*LumSysZj, 149847, "116253_AlpgenJimmyZeeNp3_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116253);
  }

  if(AlpgenJimmyZeeNp4_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116254.AlpgenJimmyZeeNp4_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524220906.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116254(1, 116254, 39976.510880/2.312500/1000*LumSys*LumSysZj, 39977, "116254_AlpgenJimmyZeeNp4_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116254);
  }

  if(AlpgenJimmyZeeNp5_Mll10to40_pt20_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116255.AlpgenJimmyZeeNp5_Mll10to40_pt20.EndProcMark.MINI.e944_a131_s1353_a145_r2993_p937.130524220926.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116255(1, 116255, 20019.028609/0.575000/1000*LumSys*LumSysZj, 20019, "116255_AlpgenJimmyZeeNp5_Mll10to40_pt20_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_116255);
  }

  if(AlpgenJimmyZmumuNp0_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116260.AlpgenJimmyZmumuNp0_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221009.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116260(1, 116260, 999674.878969/3818.625000/1000*LumSys*LumSysZj, 999675, "116260_AlpgenJimmyZmumuNp0_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116260);
  }

  if(AlpgenJimmyZmumuNp1_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116261.AlpgenJimmyZmumuNp1_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221037.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116261(1, 116261, 300144.443770/106.087500/1000*LumSys*LumSysZj, 300144, "116261_AlpgenJimmyZmumuNp1_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116261);
  }

  if(AlpgenJimmyZmumuNp2_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116262.AlpgenJimmyZmumuNp2_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524221102.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116262(1, 116262, 1000211.368234/51.812500/1000*LumSys*LumSysZj, 1000211, "116262_AlpgenJimmyZmumuNp2_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116262);
  }

  if(AlpgenJimmyZmumuNp3_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116263.AlpgenJimmyZmumuNp3_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524221133.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116263(1, 116263, 150092.708169/10.475000/1000*LumSys*LumSysZj, 150093, "116263_AlpgenJimmyZmumuNp3_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116263);
  }

  if(AlpgenJimmyZmumuNp4_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116264.AlpgenJimmyZmumuNp4_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524221153.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116264(1, 116264, 40025.597163/2.312500/1000*LumSys*LumSysZj, 40026, "116264_AlpgenJimmyZmumuNp4_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116264);
  }

  if(AlpgenJimmyZmumuNp5_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116265.AlpgenJimmyZmumuNp5_Mll10to40_pt20.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524221213.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116265(1, 116265, 10014.983237/0.575000/1000*LumSys*LumSysZj, 10015, "116265_AlpgenJimmyZmumuNp5_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116265);
  }

  if(AlpgenJimmyZtautauNp0_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116270.AlpgenJimmyZtautauNp0_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221234.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116270(1, 116270, 999897.822813/3818.875000/1000*LumSys*LumSysZj, 999897, "116270_AlpgenJimmyZtautauNp0_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116270);
  }

  if(AlpgenJimmyZtautauNp1_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116271.AlpgenJimmyZtautauNp1_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221257.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116271(1, 116271, 299988.312464/106.162500/1000*LumSys*LumSysZj, 299988, "116271_AlpgenJimmyZtautauNp1_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116271);
  }

  if(AlpgenJimmyZtautauNp2_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116272.AlpgenJimmyZtautauNp2_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221317.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116272(1, 116272, 498765.877716/51.837500/1000*LumSys*LumSysZj, 498766, "116272_AlpgenJimmyZtautauNp2_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116272);
  }

  if(AlpgenJimmyZtautauNp3_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116273.AlpgenJimmyZtautauNp3_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221339.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116273(1, 116273, 149968.738762/10.450000/1000*LumSys*LumSysZj, 149969, "116273_AlpgenJimmyZtautauNp3_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116273);
  }

  if(AlpgenJimmyZtautauNp4_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116274.AlpgenJimmyZtautauNp4_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130524221359.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116274(1, 116274, 40021.758508/2.312500/1000*LumSys*LumSysZj, 40022, "116274_AlpgenJimmyZtautauNp4_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116274);
  }

  if(AlpgenJimmyZtautauNp5_Mll10to40_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.116275.AlpgenJimmyZtautauNp5_Mll10to40_pt20.EndProcMark.MINI.e959_s1310_s1300_r3043_r2993_p937.130525151624.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116275(1, 116275, 10014.983237/0.575000/1000*LumSys*LumSysZj, 10015, "116275_AlpgenJimmyZtautauNp5_Mll10to40_pt20", MaxCuts);
    MonteCarlo.push_back(mc_116275);
  }

  if(T1_McAtNlo_Jimmy_117200){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117200.T1_McAtNlo_Jimmy.EndProcMark.MINI.e944_s1310_s1300_r3043_r2993_p937.130524221442.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117200(1, 117200, 7724358.874235/89.556320/1000*LumSys*Lumm_syst, 9990568, "117200_T1_McAtNlo_Jimmy_117200", MaxCuts);
    MonteCarlo.push_back(mc_117200);
  }

  if(AcerMCttbar_MorePS_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117209.AcerMCttbar_MorePS.EndProcMark.MINI.e1029_a131_s1353_a145_r2993_p937.130524221524.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117209(1, 117209, 9992635.903763/90.585520/1000*LumSys*Lumm_syst, 9992633, "117209_AcerMCttbar_MorePS_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117209);
  }

  if(AcerMCttbar_LessPS_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117210.AcerMCttbar_LessPS.EndProcMark.MINI.e1029_a131_s1353_a145_r2993_p937.130524221609.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117210(1, 117210, 9973855.029720/90.563850/1000*LumSys*Lumm_syst, 9973850, "117210_AcerMCttbar_LessPS_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117210);
  }

  if(AcerMCttbar_Perugia2011_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117240.AcerMCttbar_Perugia2011.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524221655.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117240(1, 117240, 9997087.068551/90.586440/1000*LumSys*Lumm_syst, 9997088, "117240_AcerMCttbar_Perugia2011_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117240);
  }

  if(AcerMCttbar_Perugia2011NOCR_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117241.AcerMCttbar_Perugia2011NOCR.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524221739.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117241(1, 117241, 9995897.415462/90.586440/1000*LumSys*Lumm_syst, 9995897, "117241_AcerMCttbar_Perugia2011NOCR_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117241);
  }

  if(AcerMCttbar_TuneAPro_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117242.AcerMCttbar_TuneAPro.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524221859.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117242(1, 117242, 9993399.395200/90.566180/1000*LumSys*Lumm_syst, 9993401, "117242_AcerMCttbar_TuneAPro_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117242);
  }

  if(AcerMCttbar_TuneACRPro_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117243.AcerMCttbar_TuneACRPro.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524221955.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117243(1, 117243, 9993348.600096/90.566180/1000*LumSys*Lumm_syst, 9993348, "117243_AcerMCttbar_TuneACRPro_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117243);
  }

  if(AlpgenWccFullNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117284.AlpgenWccFullNp0_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222035.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117284(1, 117284, 1212006.309265/153.036000/1000*LumSys*LumSysWj, 1212006, "117284_AlpgenWccFullNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117284);
  }

  if(AlpgenWccFullNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117285.AlpgenWccFullNp1_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222105.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117285(1, 117285, 967947.348729/125.616000/1000*LumSys*LumSysWj, 967947, "117285_AlpgenWccFullNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117285);
  }

  if(AlpgenWccFullNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117286.AlpgenWccFullNp2_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222125.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117286(1, 117286, 477068.710280/62.496000/1000*LumSys*LumSysWj, 477069, "117286_AlpgenWccFullNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117286);
  }

  if(AlpgenWccFullNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117287.AlpgenWccFullNp3_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222148.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117287(1, 117287, 147612.786910/20.352000/1000*LumSys*LumSysWj, 147613, "117287_AlpgenWccFullNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117287);
  }

  if(AlpgenWcNp0_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117293.AlpgenWcNp0_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222210.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117293(1, 117293, 6476828.375408/979.488000/1000*LumSys*LumSysWj, 6476829, "117293_AlpgenWcNp0_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117293);
  }

  if(AlpgenWcNp1_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117294.AlpgenWcNp1_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222238.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117294(1, 117294, 2044920.092956/311.600000/1000*LumSys*LumSysWj, 2044919, "117294_AlpgenWcNp1_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117294);
  }

  if(AlpgenWcNp2_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117295.AlpgenWcNp2_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222301.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117295(1, 117295, 507309.011709/77.216000/1000*LumSys*LumSysWj, 507309, "117295_AlpgenWcNp2_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117295);
  }

  if(AlpgenWcNp3_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117296.AlpgenWcNp3_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222324.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117296(1, 117296, 110986.455084/17.328000/1000*LumSys*LumSysWj, 110986, "117296_AlpgenWcNp3_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117296);
  }

  if(AlpgenWcNp4_pt20){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117297.AlpgenWcNp4_pt20.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130524222343.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117297(1, 117297, 28541.448184/4.256000/1000*LumSys*LumSysWj, 28541, "117297_AlpgenWcNp4_pt20", MaxCuts);
    MonteCarlo.push_back(mc_117297);
  }

  if(st_schan_PowHeg_Pythia){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117314.st_schan_PowHeg_Pythia.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130525152449.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117314(1, 117314, 200129.324155/1.499810/1000*LumSys*LumSysst, 200129, "117314_st_schan_PowHeg_Pythia", MaxCuts);
    MonteCarlo.push_back(mc_117314);
  }

  if(st_tchan_PowHeg_Pythia){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117315.st_tchan_PowHeg_Pythia.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130526115948.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117315(1, 117315, 190052.984760/20.917350/1000*LumSys*LumSysst, 190053, "117315_st_tchan_PowHeg_Pythia", MaxCuts);
    MonteCarlo.push_back(mc_117315);
  }

  if(singletop_wtch_DR_PowHeg_Pythia){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117316.singletop_wtch_DR_PowHeg_Pythia.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130525152606.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117316(1, 117316, 194375.195707/15.735990/1000*LumSys, 194375, "117316_singletop_wtch_DR_PowHeg_Pythia", MaxCuts);
    MonteCarlo.push_back(mc_117316);
  }

  if(st_tchan_enu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117360.st_tchan_enu_AcerMC.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130525152651.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117360(1, 117360, 843589.725449/6.971900/1000*LumSys*LumSysst, 999446, "117360_st_tchan_enu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117360);
  }

  if(st_tchan_munu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117361.st_tchan_munu_AcerMC.EndProcMark.MINI.e835_s1310_s1300_r3043_r2993_p937.130525152828.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117361(1, 117361, 844245.579563/6.971900/1000*LumSys*LumSysst, 999968, "117361_st_tchan_munu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117361);
  }

  if(st_tchan_taunu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117362.st_tchan_taunu_AcerMC.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130525152923.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117362(1, 117362, 844650.237248/6.963250/1000*LumSys*LumSysst, 998401, "117362_st_tchan_taunu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117362);
  }

  if(st_schan_enu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117363.st_schan_enu_AcerMC.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130525153011.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117363(1, 117363, 200121.746563/-1.000000/1000*LumSys*LumSysst, 200122, "117363_st_schan_enu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117363);
  }

  if(st_schan_munu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117364.st_schan_munu_AcerMC.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130525153109.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117364(1, 117364, 199784.359102/-1.000000/1000*LumSys*LumSysst, 199784, "117364_st_schan_munu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117364);
  }

  if(st_schan_taunu_AcerMC){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117365.st_schan_taunu_AcerMC.EndProcMark.MINI.e825_s1310_s1300_r3043_r2993_p937.130526120151.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117365(1, 117365, 489335.294266/-1.000000/1000*LumSys*LumSysst, 489335, "117365_st_schan_taunu_AcerMC", MaxCuts);
    MonteCarlo.push_back(mc_117365);
  }

  if(st_tchan_enu_AcerMC_HW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117390.st_tchan_enu_AcerMC_HW.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130525153240.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117390(1, 117390, 168721.893793/-1.000000/1000*LumSys*LumSysst, 199981, "117390_st_tchan_enu_AcerMC_HW", MaxCuts);
    MonteCarlo.push_back(mc_117390);
  }

  if(st_tchan_munu_AcerMC_HW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117391.st_tchan_munu_AcerMC_HW.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130524223703.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117391(1, 117391, 168309.192182/-1.000000/1000*LumSys*LumSysst, 199595, "117391_st_tchan_munu_AcerMC_HW", MaxCuts);
    MonteCarlo.push_back(mc_117391);
  }

  if(st_tchan_taunu_AcerMC_HW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117392.st_tchan_taunu_AcerMC_HW.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130524223722.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117392(1, 117392, 169275.426741/-1.000000/1000*LumSys*LumSysst, 200049, "117392_st_tchan_taunu_AcerMC_HW", MaxCuts);
    MonteCarlo.push_back(mc_117392);
  }

  if(st_Wtchan_AcerMC_HW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117396.st_Wtchan_AcerMC_HW.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130524223740.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117396(1, 117396, 299745.939944/-1.000000/1000*LumSys*LumSysst, 299746, "117396_st_Wtchan_AcerMC_HW", MaxCuts);
    MonteCarlo.push_back(mc_117396);
  }

  if(AcerMCttbar_MoreUE_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117403.AcerMCttbar_MoreUE.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524223804.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117403(1, 117403, 9992867.691063/90.563850/1000*LumSys*Lumm_syst, 9992870, "117403_AcerMCttbar_MoreUE_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117403);
  }

  if(AcerMCttbar_LessUE_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117404.AcerMCttbar_LessUE.EndProcMark.MINI.e1085_a131_s1353_a145_r2993_p937.130524223843.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117404(1, 117404, 9992566.890651/90.537980/1000*LumSys*Lumm_syst, 9992564, "117404_AcerMCttbar_LessUE_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117404);
  }

  if(toprex_tt_bWqgamma_mt170){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117560.toprex_tt_bWqgamma_mt170.EndProcMark.MINI.e1039_s1372_s1370_r3043_r2993_p937.130525154125.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117560(2, 117560, 200069.031279/1/1000*LumSys*Lumm_syst, 200069, "117560_toprex_tt_bWqgamma_mt170", MaxCuts);
    MonteCarlo.push_back(mc_117560);
  }

  if(toprex_tt_bWqgamma_mt175){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117561.toprex_tt_bWqgamma_mt175.EndProcMark.MINI.e1039_s1372_s1370_r3043_r2993_p937.130524224757.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117561(2, 117561, 200163.767224/1/1000*LumSys*Lumm_syst, 200164, "117561_toprex_tt_bWqgamma_mt175", MaxCuts);
    MonteCarlo.push_back(mc_117561);
  }

  if(toprex_tt_bWqZlep_mt170){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117570.toprex_tt_bWqZlep_mt170.EndProcMark.MINI.e1039_s1372_s1370_r3043_r2993_p937.130524224816.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117570(2, 117570, 200077.435956/1/1000*LumSys*Lumm_syst, 200078, "117570_toprex_tt_bWqZlep_mt170", MaxCuts);
    MonteCarlo.push_back(mc_117570);
  }

  if(toprex_tt_bWqZlep_mt175){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.117571.toprex_tt_bWqZlep_mt175.EndProcMark.MINI.e1039_s1372_s1370_r3043_r2993_p937.130524224840.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117571(2, 117571, 200073.774991/1/1000*LumSys*Lumm_syst, 200073, "117571_toprex_tt_bWqZlep_mt175", MaxCuts);
    MonteCarlo.push_back(mc_117571);
  }

  if(PythiaMadgraph_ttbarW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.119353.PythiaMadgraph_ttbarW.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130525155007.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119353(1, 119353, 100048.458768/0.097990/1000*LumSys, 100048, "119353_PythiaMadgraph_ttbarW", MaxCuts);
    MonteCarlo.push_back(mc_119353);
  }

  if(PythiaMadgraph_ttbarWj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.119354.PythiaMadgraph_ttbarWj.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130525155046.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119354(1, 119354, 99893.311609/0.076091/1000*LumSys, 99893, "119354_PythiaMadgraph_ttbarWj", MaxCuts);
    MonteCarlo.push_back(mc_119354);
  }

  if(PythiaMadgraph_ttbarZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.119355.PythiaMadgraph_ttbarZ.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130525155129.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119355(1, 119355, 100081.614879/0.064737/1000*LumSys, 100082, "119355_PythiaMadgraph_ttbarZ", MaxCuts);
    MonteCarlo.push_back(mc_119355);
  }

  if(PythiaMadgraph_ttbarZj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.119356.PythiaMadgraph_ttbarZj.EndProcMark.MINI.e887_s1372_s1370_r3043_r2993_p937.130525155207.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119356(1, 119356, 100162.551026/0.071353/1000*LumSys, 100163, "119356_PythiaMadgraph_ttbarZj", MaxCuts);
    MonteCarlo.push_back(mc_119356);
  }

  if(PythiaMadgraph_ttbarWW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_Bruno_7TeV.dir//user.galhardo.FCNCqzl21.mc11_7TeV.119583.PythiaMadgraph_ttbarWW.EndProcMark.MINI.e887_s1310_s1300_r3043_r2993_p937.130525155243.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119583(1, 119583, 100183.438199/0.001249/1000*LumSys, 100183, "119583_PythiaMadgraph_ttbarWW", MaxCuts);
    MonteCarlo.push_back(mc_119583);
  }

