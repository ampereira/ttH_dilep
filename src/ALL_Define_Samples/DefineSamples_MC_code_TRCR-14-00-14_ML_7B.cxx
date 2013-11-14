  if(PowhegJimmy_AUET2CT10_ttbar_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.105860.PowhegJimmy_AUET2CT10_ttbar_LeptonFilter.EndProcMark.merge.NTUP_TOP.e1576_a159_a171_r3549_p1400v141.v1.130821151922_1.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105860(1, 105860, 14830403.587768/129.265416/1000*LumSys, 14830404, "105860_PowhegJimmy_AUET2CT10_ttbar_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105860);
  }

  if(PowhegPythia_AUET2BCT10_ttbar_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter.EndProcMark.merge.NTUP_TOP.e1317_a159_a165_r3549_p1400v141.v1.130821154317_1.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105861(1, 105861, 29552042.996559/129.271124/1000*LumSys, 29552043, "105861_PowhegPythia_AUET2BCT10_ttbar_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105861);
  }

  if(McAtNloJimmy_CT10_ttbar_dilepton){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.110001.McAtNloJimmy_CT10_ttbar_dilepton.EndProcMark.merge.NTUP_TOP.e1576_s1499_s1504_r3658_r3549_p1400v141.v1.130821142930.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110001(1, 110001, 7510580.469946/26.426691/1000*LumSys, 7510580, "110001_McAtNloJimmy_CT10_ttbar_dilepton", MaxCuts);
    MonteCarlo.push_back(mc_110001);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.110002.McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton.EndProcMark.merge.NTUP_TOP.e1576_a159_a171_r3549_p1400v141.v1.130821161122.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110002(1, 110002, 7529397.708910/26.787323/1000*LumSys, 7529398, "110002_McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110002);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.110003.McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton.EndProcMark.merge.NTUP_TOP.e1576_a159_a171_r3549_p1400v141.v1.130821162424_1.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110003(1, 110003, 7564388.564535/23.122750/1000*LumSys, 7564389, "110003_McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110003);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbbincl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.116108.AlpgenJimmy_AUET2CTEQ6L1_ttbbincl.EndProcMark.merge.NTUP_TOP.e1533_a159_a171_r3549_p1400v141.v1.130821144730.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116108(1, 116108, 1511172.759213/2.424222/1000*LumSys, 1511173, "116108_AlpgenJimmy_AUET2CTEQ6L1_ttbbincl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_116108);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbbincl){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.116108.AlpgenJimmy_AUET2CTEQ6L1_ttbbincl.EndProcMark.merge.NTUP_TOP.e1533_s1499_s1504_r3658_r3549_p1400v141.v1.130821144555.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116108(1, 116108, 259809.901187/2.424222/1000*LumSys, 259810, "116108_AlpgenJimmy_AUET2CTEQ6L1_ttbbincl", MaxCuts);
    MonteCarlo.push_back(mc_116108);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttccincl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.116109.AlpgenJimmy_AUET2CTEQ6L1_ttccincl.EndProcMark.merge.NTUP_TOP.e1533_a159_a171_r3549_p1400v141.v1.130821145144.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116109(1, 116109, 1575198.619746/4.582257/1000*LumSys, 1575198, "116109_AlpgenJimmy_AUET2CTEQ6L1_ttccincl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_116109);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttccincl){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.116109.AlpgenJimmy_AUET2CTEQ6L1_ttccincl.EndProcMark.merge.NTUP_TOP.e1533_s1499_s1504_r3658_r3549_p1400v141.v1.130821144642.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116109(1, 116109, 436884.193404/4.582257/1000*LumSys, 436884, "116109_AlpgenJimmy_AUET2CTEQ6L1_ttccincl", MaxCuts);
    MonteCarlo.push_back(mc_116109);
  }

  if(PowhegPythia_P2011C_ttbar){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.117050.PowhegPythia_P2011C_ttbar.EndProcMark.merge.NTUP_TOP.e1728_s1581_s1586_r3658_r3549_p1400v141.v1.130821150300.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117050(1, 117050, 3220890.837089/137.320392/1000*LumSys, 27449736, "117050_PowhegPythia_P2011C_ttbar", MaxCuts);
    MonteCarlo.push_back(mc_117050);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.117209.AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad.EndProcMark.merge.NTUP_TOP.e1378_a159_a171_r3549_p1400v141.v1.130821163745_1.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117209(1, 117209, 14813426.862720/129.264832/1000*LumSys, 14813426, "117209_AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117209);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.117210.AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad.EndProcMark.merge.NTUP_TOP.e1378_a159_a171_r3549_p1400v141.v1.130821165954.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117210(1, 117210, 14703279.877983/129.266458/1000*LumSys, 14703280, "117210_AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117210);
  }

  if(Pythia8_AU2CTEQ6L1_ttH115_dilepbb){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161869.Pythia8_AU2CTEQ6L1_ttH115_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_s1499_s1504_r3658_r3549_p1400v141.v1.130821141749.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161869(1, 161869, 49435.171938/0.012190/1000*LumSys, 49435, "161869_Pythia8_AU2CTEQ6L1_ttH115_dilepbb", MaxCuts);
    MonteCarlo.push_back(mc_161869);
  }

  if(Pythia8_AU2CTEQ6L1_ttH120_dilepbb){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161870.Pythia8_AU2CTEQ6L1_ttH120_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_s1499_s1504_r3658_r3549_p1400v141.v1.130821141815.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161870(1, 161870, 49399.242375/0.009921/1000*LumSys, 49399, "161870_Pythia8_AU2CTEQ6L1_ttH120_dilepbb", MaxCuts);
    MonteCarlo.push_back(mc_161870);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161871.Pythia8_AU2CTEQ6L1_ttH125_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_a159_a171_r3549_p1400v141.v1.130821141949.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161871(1, 161871, 991762.507345/0.007830/1000*LumSys, 991762, "161871_Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_161871);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_dilepbb){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161871.Pythia8_AU2CTEQ6L1_ttH125_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_s1499_s1504_r3658_r3549_p1400v141.v1.130821141857.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161871(1, 161871, 492908.324447/0.007830/1000*LumSys, 492908, "161871_Pythia8_AU2CTEQ6L1_ttH125_dilepbb", MaxCuts);
    MonteCarlo.push_back(mc_161871);
  }

  if(Pythia8_AU2CTEQ6L1_ttH130_dilepbb){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161872.Pythia8_AU2CTEQ6L1_ttH130_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_s1499_s1504_r3658_r3549_p1400v141.v1.130821142241.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161872(1, 161872, 49343.588718/0.005956/1000*LumSys, 49344, "161872_Pythia8_AU2CTEQ6L1_ttH130_dilepbb", MaxCuts);
    MonteCarlo.push_back(mc_161872);
  }

  if(Pythia8_AU2CTEQ6L1_ttH135_dilepbb){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.161873.Pythia8_AU2CTEQ6L1_ttH135_dilepbb.EndProcMark.merge.NTUP_TOP.e1441_s1499_s1504_r3658_r3549_p1400v141.v1.130821142304.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161873(1, 161873, 49303.610179/0.004346/1000*LumSys, 49304, "161873_Pythia8_AU2CTEQ6L1_ttH135_dilepbb", MaxCuts);
    MonteCarlo.push_back(mc_161873);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.164440.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline.EndProcMark.merge.NTUP_TOP.e1527_s1499_s1504_r3658_r3549_p1400v141.v1.130821144101.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164440(1, 164440, 741168.694089/8.320474/1000*LumSys, 741169, "164440_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline", MaxCuts);
    MonteCarlo.push_back(mc_164440);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.164441.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline.EndProcMark.merge.NTUP_TOP.e1527_s1499_s1504_r3658_r3549_p1400v141.v1.130821144153.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164441(1, 164441, 718527.647445/8.798048/1000*LumSys, 718528, "164441_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline", MaxCuts);
    MonteCarlo.push_back(mc_164441);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.164442.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline.EndProcMark.merge.NTUP_TOP.e1527_s1499_s1504_r3658_r3549_p1400v141.v1.130821144244.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164442(1, 164442, 453234.033050/5.654673/1000*LumSys, 453233, "164442_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline", MaxCuts);
    MonteCarlo.push_back(mc_164442);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.164443.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline.EndProcMark.merge.NTUP_TOP.e1527_s1499_s1504_r3658_r3549_p1400v141.v1.130821144432.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164443(1, 164443, 294822.526307/3.777189/1000*LumSys, 294823, "164443_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline", MaxCuts);
    MonteCarlo.push_back(mc_164443);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_allhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169887.PowhegPythia8_AU2CT10_PowHelttH125inc_allhad.EndProcMark.merge.NTUP_TOP.e2052_s1581_s1586_r4485_r4540_p1400v141.v6b.130924175359.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169887(1, 169887, 128321.882532/0.059090/1000*LumSys, 128322, "169887_PowhegPythia8_AU2CT10_PowHelttH125inc_allhad", MaxCuts);
    MonteCarlo.push_back(mc_169887);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_allhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169887.PowhegPythia8_AU2CT10_PowHelttH125inc_allhad.EndProcMark.merge.NTUP_TOP.e2053_a188_a205_r4540_p1400v141.v6b.130924175514.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169887(1, 169887, 128029.526192/0.059090/1000*LumSys, 128030, "169887_PowhegPythia8_AU2CT10_PowHelttH125inc_allhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_169887);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_ljets){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169888.PowhegPythia8_AU2CT10_PowHelttH125inc_ljets.EndProcMark.merge.NTUP_TOP.e2052_s1581_s1586_r4485_r4540_p1400v141.v6b.130924175609.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169888(1, 169888, 126127.717548/0.056635/1000*LumSys, 126128, "169888_PowhegPythia8_AU2CT10_PowHelttH125inc_ljets", MaxCuts);
    MonteCarlo.push_back(mc_169888);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_ljets_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169888.PowhegPythia8_AU2CT10_PowHelttH125inc_ljets.EndProcMark.merge.NTUP_TOP.e2053_a188_a205_r4540_p1400v141.v6b.130924175738.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169888(1, 169888, 125695.836588/0.056635/1000*LumSys, 125696, "169888_PowhegPythia8_AU2CT10_PowHelttH125inc_ljets_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_169888);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_dil){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169889.PowhegPythia8_AU2CT10_PowHelttH125inc_dil.EndProcMark.merge.NTUP_TOP.e2052_s1581_s1586_r4485_r4540_p1400v141.v6b.130924175835.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169889(1, 169889, 124113.946510/0.013513/1000*LumSys, 124114, "169889_PowhegPythia8_AU2CT10_PowHelttH125inc_dil", MaxCuts);
    MonteCarlo.push_back(mc_169889);
  }

  if(PowhegPythia8_AU2CT10_PowHelttH125inc_dil_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.169889.PowhegPythia8_AU2CT10_PowHelttH125inc_dil.EndProcMark.merge.NTUP_TOP.e2053_a188_a205_r4540_p1400v141.v6b.130924175943.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169889(1, 169889, 114131.461582/0.013513/1000*LumSys, 114131, "169889_PowhegPythia8_AU2CT10_PowHelttH125inc_dil_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_169889);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbbinclNp0_dilep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.181106.AlpgenJimmy_AUET2CTEQ6L1_ttbbinclNp0_dilep.EndProcMark.merge.NTUP_TOP.e2194_a159_a171_r3549_p1569v141.v6b.130915151129.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_181106(1, 181106, 875331.731946/0.254542/1000*LumSys, 875332, "181106_AlpgenJimmy_AUET2CTEQ6L1_ttbbinclNp0_dilep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_181106);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttccinclNp0_dilep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.181108.AlpgenJimmy_AUET2CTEQ6L1_ttccinclNp0_dilep.EndProcMark.merge.NTUP_TOP.e2194_a159_a171_r3549_p1569v141.v6b.130915151049.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_181108(1, 181108, 382020.562911/0.481124/1000*LumSys, 382020, "181108_AlpgenJimmy_AUET2CTEQ6L1_ttccinclNp0_dilep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_181108);
  }

  if(Sherpa_CT10_TTbarLeptLeptMassiveCB){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.jahreda.mc12_8TeV.181380.Sherpa_CT10_TTbarLeptLeptMassiveCB.EndProcMark.merge.NTUP_TOP.e2130_s1581_s1586_r4485_r4540_p1400v141.v1.130821171831.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_181380(1, 181380, 608001.741014/11.885892/1000*LumSys, 608002, "181380_Sherpa_CT10_TTbarLeptLeptMassiveCB", MaxCuts);
    MonteCarlo.push_back(mc_181380);
  }

  if(PowhegPythia_P2011C_HERAPDF15NLO_ttbar_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.markowen.mc12_8TeV.117001.PowhegPythia_P2011C_HERAPDF15NLO_ttbar.EndProcMark.merge.NTUP_TOP.e2077_a188_a205_r4540_p1400v141.v1.130828094017.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117001(1, 117001, 981634.322011/137.319205/1000*LumSys, 981634, "117001_PowhegPythia_P2011C_HERAPDF15NLO_ttbar_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117001);
  }

  if(PowhegPythia8_AU2CT10_Zee){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.markowen.mc12_8TeV.147806.PowhegPythia8_AU2CT10_Zee.EndProcMark.merge.NTUP_TOP.e1169_s1469_s1470_r3542_r3549_p1400v141.v3.130902200637.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147806(1, 147806, 1841679.146413/1109.900000/1000*LumSys, 1841679, "147806_PowhegPythia8_AU2CT10_Zee", MaxCuts);
    MonteCarlo.push_back(mc_147806);
  }

  if(PowhegPythia8_AU2CT10_Zmumu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.markowen.mc12_8TeV.147807.PowhegPythia8_AU2CT10_Zmumu.EndProcMark.merge.NTUP_TOP.e1169_s1469_s1470_r3542_r3549_p1400v141.v3.130902200206.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147807(1, 147807, 2594068.128373/1109.800000/1000*LumSys, 2594068, "147807_PowhegPythia8_AU2CT10_Zmumu", MaxCuts);
    MonteCarlo.push_back(mc_147807);
  }

  if(PowhegPythia8_AU2CT10_Ztautau){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.markowen.mc12_8TeV.147808.PowhegPythia8_AU2CT10_Ztautau.EndProcMark.merge.NTUP_TOP.e1169_s1469_s1470_r3542_r3549_p1400v141.v3.130902200825.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147808(1, 147808, 2081008.124070/1109.900000/1000*LumSys, 2081008, "147808_PowhegPythia8_AU2CT10_Ztautau", MaxCuts);
    MonteCarlo.push_back(mc_147808);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107100.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122041.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107100(1, 107100, 249540.220437/3.073058/1000*LumSys, 249540, "107100_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107100);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107101.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122053.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107101(1, 107101, 121959.501905/1.537267/1000*LumSys, 121960, "107101_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107101);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107102.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122110.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107102(1, 107102, 58825.559384/0.728574/1000*LumSys, 58826, "107102_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107102);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107103.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v1.130823195055.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107103(1, 107103, 34103.611593/0.404248/1000*LumSys, 34104, "107103_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107103);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107104.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v2.130825202756.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107104(1, 107104, 104861.087481/1.024871/1000*LumSys, 104861, "107104_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107104);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107105.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122123.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107105(1, 107105, 252989.054497/0.670023/1000*LumSys, 252989, "107105_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107105);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107106.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v2.130825202831.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107106(1, 107106, 145992.454961/0.376953/1000*LumSys, 145992, "107106_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107106);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107107.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122137.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107107(1, 107107, 92240.989715/0.233429/1000*LumSys, 92241, "107107_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107107);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107108.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v1.130823195221.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107108(1, 107108, 594954.201760/0.832134/1000*LumSys, 594954, "107108_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107108);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107109.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v2.130825202908.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107109(1, 107109, 282830.094118/0.396354/1000*LumSys, 282830, "107109_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107109);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107110.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v2.130825202928.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107110(1, 107110, 117166.658897/0.162599/1000*LumSys, 117167, "107110_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107110);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107111.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3.EndProcMark.merge.NTUP_TOP.e1596_s1499_s1504_r3658_r3549_p1400v141.v3.130826122149.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107111(1, 107111, 1338.283289/0.077127/1000*LumSys, 1338, "107111_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107111);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v2.130823183958.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107650(1, 107650, 2791532.038827/874.753040/1000*LumSys, 2791532, "107650_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0", MaxCuts);
    MonteCarlo.push_back(mc_107650);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171211.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107651(1, 107651, 44666.803171/190.740800/1000*LumSys, 44667, "107651_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1", MaxCuts);
    MonteCarlo.push_back(mc_107651);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171245.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107652(1, 107652, 269270.670401/59.900231/1000*LumSys, 269271, "107652_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2", MaxCuts);
    MonteCarlo.push_back(mc_107652);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171318.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107653(1, 107653, 31402.332325/17.478838/1000*LumSys, 31402, "107653_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3", MaxCuts);
    MonteCarlo.push_back(mc_107653);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171333.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107654(1, 107654, 23101.444900/4.605186/1000*LumSys, 23101, "107654_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4", MaxCuts);
    MonteCarlo.push_back(mc_107654);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171349.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107655(1, 107655, 7512.858128/1.344772/1000*LumSys, 7513, "107655_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5", MaxCuts);
    MonteCarlo.push_back(mc_107655);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171410.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107660(1, 107660, 2914253.586760/875.121740/1000*LumSys, 2914254, "107660_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107660);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v2.130823184222.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107661(1, 107661, 933601.626575/190.224620/1000*LumSys, 933602, "107661_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107661);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171708.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107662(1, 107662, 267737.126652/60.078436/1000*LumSys, 267737, "107662_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107662);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171729.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107663(1, 107663, 89304.683670/17.446884/1000*LumSys, 89305, "107663_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107663);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171745.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107664(1, 107664, 23782.405565/4.673150/1000*LumSys, 23783, "107664_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4", MaxCuts);
    MonteCarlo.push_back(mc_107664);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822171818.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107665(1, 107665, 7722.417488/1.363453/1000*LumSys, 7722, "107665_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5", MaxCuts);
    MonteCarlo.push_back(mc_107665);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107670.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v3.130825203117.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107670(1, 107670, 3442447.647077/874.912810/1000*LumSys, 3442448, "107670_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0", MaxCuts);
    MonteCarlo.push_back(mc_107670);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107671.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822172132.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107671(1, 107671, 934589.761630/190.605610/1000*LumSys, 934590, "107671_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1", MaxCuts);
    MonteCarlo.push_back(mc_107671);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107672.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822172201.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107672(1, 107672, 99323.000423/59.981345/1000*LumSys, 99323, "107672_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2", MaxCuts);
    MonteCarlo.push_back(mc_107672);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107673.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822172234.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107673(1, 107673, 89540.075716/17.378060/1000*LumSys, 89540, "107673_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3", MaxCuts);
    MonteCarlo.push_back(mc_107673);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107674.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v2.130823184507.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107674(1, 107674, 23919.843704/4.634682/1000*LumSys, 23920, "107674_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4", MaxCuts);
    MonteCarlo.push_back(mc_107674);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.107675.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5.EndProcMark.merge.NTUP_TOP.e1571_s1499_s1504_r3658_r3549_p1400v141.v1.130822172302.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107675(1, 107675, 7735.659709/1.366894/1000*LumSys, 7736, "107675_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5", MaxCuts);
    MonteCarlo.push_back(mc_107675);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu.EndProcMark.merge.NTUP_TOP.e1525_s1499_s1504_r3658_r3549_p1400v141.v1.130823194735.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108343(1, 108343, 818.728262/0.605908/1000*LumSys, 819, "108343_McAtNloJimmy_AUET2CT10_SingleTopSChanWenu", MaxCuts);
    MonteCarlo.push_back(mc_108343);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu.EndProcMark.merge.NTUP_TOP.e1525_s1499_s1504_r3658_r3549_p1400v141.v1.130823194751.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108344(1, 108344, 168215.186418/0.605889/1000*LumSys, 168215, "108344_McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu", MaxCuts);
    MonteCarlo.push_back(mc_108344);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu.EndProcMark.merge.NTUP_TOP.e1525_s1499_s1504_r3658_r3549_p1400v141.v1.130823194807.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108345(1, 108345, 28434.838504/0.605875/1000*LumSys, 28435, "108345_McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu", MaxCuts);
    MonteCarlo.push_back(mc_108345);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.EndProcMark.merge.NTUP_TOP.e1525_s1499_s1504_r3658_r3549_p1400v141.v1.130823194822.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108346(1, 108346, 1752053.019001/22.370945/1000*LumSys, 1752053, "108346_McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl", MaxCuts);
    MonteCarlo.push_back(mc_108346);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172315.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109300(1, 109300, 139699.222251/10.306148/1000*LumSys, 139699, "109300_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109300);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172330.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109301(1, 109301, 72262.331735/4.003345/1000*LumSys, 72262, "109301_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109301);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172345.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109302(1, 109302, 39669.409617/1.472465/1000*LumSys, 39669, "109302_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109302);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172401.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109303(1, 109303, 4332.536902/0.625991/1000*LumSys, 4333, "109303_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109303);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109305.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172414.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109305(1, 109305, 144762.175665/10.297299/1000*LumSys, 144762, "109305_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109305);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109306.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172429.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109306(1, 109306, 75326.696083/4.014529/1000*LumSys, 75327, "109306_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109306);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109307.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172443.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109307(1, 109307, 41084.206539/1.459315/1000*LumSys, 41084, "109307_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109307);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109308.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v3.130825203404.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109308(1, 109308, 4396.668466/0.621112/1000*LumSys, 4397, "109308_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109308);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109310.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172509.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109310(1, 109310, 145828.770583/10.309835/1000*LumSys, 145829, "109310_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109310);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109311.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172527.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109311(1, 109311, 75500.376183/3.998183/1000*LumSys, 75500, "109311_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109311);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109312.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172542.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109312(1, 109312, 41415.237522/1.469392/1000*LumSys, 41415, "109312_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109312);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.109313.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172556.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109313(1, 109313, 4470.493739/0.624578/1000*LumSys, 4470, "109313_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109313);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e.EndProcMark.merge.NTUP_TOP.e1346_s1499_s1504_r3658_r3549_p1400v141.v1.130823194900.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117360(1, 117360, 250341.407116/9.478355/1000*LumSys, 250341, "117360_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e", MaxCuts);
    MonteCarlo.push_back(mc_117360);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu.EndProcMark.merge.NTUP_TOP.e1346_s1499_s1504_r3658_r3549_p1400v141.v1.130823194916.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117361(1, 117361, 139437.096530/9.477851/1000*LumSys, 139437, "117361_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu", MaxCuts);
    MonteCarlo.push_back(mc_117361);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau.EndProcMark.merge.NTUP_TOP.e1346_s1499_s1504_r3658_r3549_p1400v141.v1.130823194935.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117362(1, 117362, 6454.461862/9.477714/1000*LumSys, 6454, "117362_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau", MaxCuts);
    MonteCarlo.push_back(mc_117362);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117706.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172807.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117706(1, 117706, 449341.508227/19.241224/1000*LumSys, 449342, "117706_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0", MaxCuts);
    MonteCarlo.push_back(mc_117706);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117707.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172824.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117707(1, 117707, 246635.512247/8.477642/1000*LumSys, 246636, "117707_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1", MaxCuts);
    MonteCarlo.push_back(mc_117707);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117708.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172846.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117708(1, 117708, 104691.078361/3.570982/1000*LumSys, 104691, "117708_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2", MaxCuts);
    MonteCarlo.push_back(mc_117708);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.117709.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v2.130823184538.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117709(1, 117709, 34889.164334/1.398110/1000*LumSys, 34889, "117709_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3", MaxCuts);
    MonteCarlo.push_back(mc_117709);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.EndProcMark.merge.NTUP_TOP.e1352_s1499_s1504_r3658_r3549_p1400v141.v1.130823194613.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119353(1, 119353, 394724.565654/0.121797/1000*LumSys, 394725, "119353_MadGraphPythia_AUET2BCTEQ6L1_ttbarW", MaxCuts);
    MonteCarlo.push_back(mc_119353);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarWj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.EndProcMark.merge.NTUP_TOP.e1352_s1499_s1504_r3658_r3549_p1400v141.v1.130823194631.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119354(1, 119354, 396556.428842/0.109198/1000*LumSys, 396556, "119354_MadGraphPythia_AUET2BCTEQ6L1_ttbarWj", MaxCuts);
    MonteCarlo.push_back(mc_119354);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.EndProcMark.merge.NTUP_TOP.e1352_s1499_s1504_r3658_r3549_p1400v141.v1.130823194647.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119355(1, 119355, 394735.881404/0.091382/1000*LumSys, 394736, "119355_MadGraphPythia_AUET2BCTEQ6L1_ttbarZ", MaxCuts);
    MonteCarlo.push_back(mc_119355);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarZj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.EndProcMark.merge.NTUP_TOP.e1352_s1499_s1504_r3658_r3549_p1400v141.v2.130825202652.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119356(1, 119356, 396715.086378/0.117908/1000*LumSys, 396715, "119356_MadGraphPythia_AUET2BCTEQ6L1_ttbarZj", MaxCuts);
    MonteCarlo.push_back(mc_119356);
  }

  if(MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.EndProcMark.merge.NTUP_TOP.e1543_s1499_s1504_r3658_r3549_p1400v141.v1.130823194723.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119583(1, 119583, 9975.053853/0.001901/1000*LumSys, 9975, "119583_MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW", MaxCuts);
    MonteCarlo.push_back(mc_119583);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126414.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172608.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126414(1, 126414, 222000.722976/19.246140/1000*LumSys, 222001, "126414_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0", MaxCuts);
    MonteCarlo.push_back(mc_126414);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172626.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126415(1, 126415, 232441.643193/8.478871/1000*LumSys, 232442, "126415_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1", MaxCuts);
    MonteCarlo.push_back(mc_126415);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172641.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126416(1, 126416, 96325.194356/3.590892/1000*LumSys, 96325, "126416_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2", MaxCuts);
    MonteCarlo.push_back(mc_126416);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172655.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126417(1, 126417, 33466.995376/1.397496/1000*LumSys, 33467, "126417_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3", MaxCuts);
    MonteCarlo.push_back(mc_126417);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126418.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172708.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126418(1, 126418, 22228.054263/19.230163/1000*LumSys, 22228, "126418_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0", MaxCuts);
    MonteCarlo.push_back(mc_126418);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126419.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172725.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126419(1, 126419, 246519.199628/8.474570/1000*LumSys, 246519, "126419_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1", MaxCuts);
    MonteCarlo.push_back(mc_126419);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126420.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172739.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126420(1, 126420, 104221.709514/3.579340/1000*LumSys, 104222, "126420_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2", MaxCuts);
    MonteCarlo.push_back(mc_126420);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.126421.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3.EndProcMark.merge.NTUP_TOP.e1601_s1499_s1504_r3658_r3549_p1400v141.v1.130822172753.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126421(1, 126421, 34822.374618/1.395775/1000*LumSys, 34822, "126421_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3", MaxCuts);
    MonteCarlo.push_back(mc_126421);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822172913.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146830(1, 146830, 517357.345105/4156.090500/1000*LumSys, 517357, "146830_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146830);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822172932.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146831(1, 146831, 191887.496740/130.111600/1000*LumSys, 191887, "146831_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146831);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822172946.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146832(1, 146832, 186155.057041/62.917945/1000*LumSys, 186155, "146832_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146832);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173017.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146833(1, 146833, 141353.436930/13.514255/1000*LumSys, 141353, "146833_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146833);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173042.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146834(1, 146834, 37782.390674/3.076288/1000*LumSys, 37782, "146834_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146834);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146835.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173057.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146835(1, 146835, 77776.250802/0.827071/1000*LumSys, 77776, "146835_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146835);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146840.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173117.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146840(1, 146840, 589954.316237/4155.971000/1000*LumSys, 589954, "146840_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146840);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146841.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173137.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146841(1, 146841, 110047.803580/129.812850/1000*LumSys, 110048, "146841_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146841);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146842.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173201.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146842(1, 146842, 153302.465417/62.946625/1000*LumSys, 153302, "146842_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146842);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146843.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173224.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146843(1, 146843, 16164.078271/13.483185/1000*LumSys, 16164, "146843_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146843);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146844.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173238.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146844(1, 146844, 37075.096538/3.069955/1000*LumSys, 37075, "146844_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146844);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146845.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173306.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146845(1, 146845, 78989.455134/0.829748/1000*LumSys, 78989, "146845_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146845);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146850.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173328.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146850(1, 146850, 996127.233325/4156.329500/1000*LumSys, 996127, "146850_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146850);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146851.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173347.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146851(1, 146851, 126277.124459/130.075750/1000*LumSys, 126277, "146851_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146851);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146852.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173406.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146852(1, 146852, 74654.080131/63.068515/1000*LumSys, 74654, "146852_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146852);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146853.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v2.130823184551.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146853(1, 146853, 4324.329007/13.497525/1000*LumSys, 4324, "146853_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146853);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146854.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp4Excl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1551_s1499_s1504_r3658_r3549_p1400v141.v1.130822173516.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146854(1, 146854, 124823.775359/3.094931/1000*LumSys, 124824, "146854_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146854);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.146855.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60.EndProcMark.merge.NTUP_TOP.e1600_s1499_s1504_r3658_r3549_p1400v141.v1.130822173532.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146855(1, 146855, 54891.520811/0.828099/1000*LumSys, 54891, "146855_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146855);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200206.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167749(1, 167749, 1071785.983368/31.046000/1000*LumSys, 1071786, "167749_Sherpa_CT10_ZeeMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167749);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200245.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167750(1, 167750, 417828.814382/314.260000/1000*LumSys, 417829, "167750_Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167750);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200317.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167751(1, 167751, 478087.208726/763.050000/1000*LumSys, 478087, "167751_Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167751);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200342.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167752(1, 167752, 1085207.596171/31.036000/1000*LumSys, 1085208, "167752_Sherpa_CT10_ZmumuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167752);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200435.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167753(1, 167753, 436267.708991/314.800000/1000*LumSys, 436268, "167753_Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167753);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200505.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167754(1, 167754, 435232.090382/764.010000/1000*LumSys, 435232, "167754_Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167754);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter.EndProcMark.merge.NTUP_TOP.e1585_a159_a171_r3549_p1400v141.v1.131001200526.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167755(1, 167755, 1090907.486250/31.008000/1000*LumSys, 1090907, "167755_Sherpa_CT10_ZtautauMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167755);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto.EndProcMark.merge.NTUP_TOP.e1587_a159_a171_r3549_p1400v141.v1.131001200608.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167756(1, 167756, 68065.955712/314.490000/1000*LumSys, 68066, "167756_Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167756);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.samor.mc12_8TeV.167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto.EndProcMark.merge.NTUP_TOP.e1587_a159_a171_r3549_p1400v141.v1.131001200643.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167757(1, 167757, 417448.376249/764.690000/1000*LumSys, 417448, "167757_Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167757);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_dilepton_noSpinCorr_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.tneep.mc12_8TeV.117200.McAtNloJimmy_AUET2CT10_ttbar_dilepton_noSpinCorr.EndProcMark.merge.NTUP_TOP.e1990_a188_a171_r3549_p1400v141.v1.130822103734_1.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117200(1, 117200, 646492.570183/26.427379/1000*LumSys, 646493, "117200_McAtNloJimmy_AUET2CT10_ttbar_dilepton_noSpinCorr_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117200);
  }

  if(Sherpa_CT10_Zee){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.tneep.mc12_8TeV.147770.Sherpa_CT10_Zee.EndProcMark.merge.NTUP_TOP.e1434_s1499_s1504_r3658_r3549_p1400v141.v1.130822103319.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147770(1, 147770, 9773766690946.623047/1241.618400/1000*LumSys, 9773766690947, "147770_Sherpa_CT10_Zee", MaxCuts);
    MonteCarlo.push_back(mc_147770);
  }

  if(Sherpa_CT10_Zmumu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.tneep.mc12_8TeV.147771.Sherpa_CT10_Zmumu.EndProcMark.merge.NTUP_TOP.e1434_s1499_s1504_r3658_r3549_p1400v141.v1.130822103411.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147771(1, 147771, 9554538577524.128906/1241.515600/1000*LumSys, 9554538577524, "147771_Sherpa_CT10_Zmumu", MaxCuts);
    MonteCarlo.push_back(mc_147771);
  }

  if(Sherpa_CT10_Ztautau){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool-8TeV-TRC-14-00-14/LipTool/NewMiniNtuples/ntuples_ttHdilep_TRCR14-00-14/Lists_byRuns_NamesCorr_ML_7B.root_in_mc12_8TeV//user.tneep.mc12_8TeV.147772.Sherpa_CT10_Ztautau.EndProcMark.merge.NTUP_TOP.e1434_s1499_s1504_r3658_r3549_p1400v141.v1.130822103630.merge.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147772(1, 147772, 10400671182582.171875/1240.693200/1000*LumSys, 10400671182582, "147772_Sherpa_CT10_Ztautau", MaxCuts);
    MonteCarlo.push_back(mc_147772);
  }

