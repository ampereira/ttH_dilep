  if(McAtNloJimmy_CT10_ttbar_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.EndProcMark.MINI.e1513_a159_a171_r3549_p1400.130524204306.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105200(1, 105200, 11099268.502869/129.271124/1000*LumSys, 14410795, "105200_McAtNloJimmy_CT10_ttbar_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105200);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_allhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105204.McAtNloJimmy_AUET2CT10_ttbar_allhad.EndProcMark.MINI.e1576_s1499_s1504_r3658_r3549_p1400.130524210355.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105204(1, 105204, 920838.522749/108.794462/1000*LumSys, 1196168, "105204_McAtNloJimmy_AUET2CT10_ttbar_allhad", MaxCuts);
    MonteCarlo.push_back(mc_105204);
  }

  if(PowhegJimmy_AUET2CT10_ttbar_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105860.PowhegJimmy_AUET2CT10_ttbar_LeptonFilter.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130524210739.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105860(1, 105860, 8076524.810161/129.265416/1000*LumSys, 8076526, "105860_PowhegJimmy_AUET2CT10_ttbar_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105860);
  }

  if(PowhegPythia_AUET2BCT10_ttbar_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter.EndProcMark.MINI.e1317_a159_a165_r3549_p1400.130524211735_1_rev43797.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105861(1, 105861, 9509180.655859/129.271124/1000*LumSys, 9509179, "105861_PowhegPythia_AUET2BCT10_ttbar_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_105861);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmenuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105921.McAtNloJimmy_AUET2CT10_WpWmenuenu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213541.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105921(1, 105921, 43898.843247/0.638145/1000*LumSys, 62179, "105921_McAtNloJimmy_AUET2CT10_WpWmenuenu", MaxCuts);
    MonteCarlo.push_back(mc_105921);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmenumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105922.McAtNloJimmy_AUET2CT10_WpWmenumunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213609.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105922(1, 105922, 140341.742947/0.638168/1000*LumSys, 199656, "105922_McAtNloJimmy_AUET2CT10_WpWmenumunu", MaxCuts);
    MonteCarlo.push_back(mc_105922);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmenutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105923.McAtNloJimmy_AUET2CT10_WpWmenutaunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213634.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105923(1, 105923, 140900.244880/0.638164/1000*LumSys, 199837, "105923_McAtNloJimmy_AUET2CT10_WpWmenutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105923);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmmunuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105924.McAtNloJimmy_AUET2CT10_WpWmmunuenu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213656.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105924(1, 105924, 140307.741179/0.638161/1000*LumSys, 199102, "105924_McAtNloJimmy_AUET2CT10_WpWmmunuenu", MaxCuts);
    MonteCarlo.push_back(mc_105924);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmmunumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105925.McAtNloJimmy_AUET2CT10_WpWmmunumunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213721.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105925(1, 105925, 140559.818411/0.638110/1000*LumSys, 199393, "105925_McAtNloJimmy_AUET2CT10_WpWmmunumunu", MaxCuts);
    MonteCarlo.push_back(mc_105925);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmmunutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105926.McAtNloJimmy_AUET2CT10_WpWmmunutaunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213747.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105926(1, 105926, 139932.916107/0.638113/1000*LumSys, 198720, "105926_McAtNloJimmy_AUET2CT10_WpWmmunutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105926);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmtaunuenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105927.McAtNloJimmy_AUET2CT10_WpWmtaunuenu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213814.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105927(1, 105927, 140131.825617/0.638152/1000*LumSys, 199089, "105927_McAtNloJimmy_AUET2CT10_WpWmtaunuenu", MaxCuts);
    MonteCarlo.push_back(mc_105927);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmtaunumunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105928.McAtNloJimmy_AUET2CT10_WpWmtaunumunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213839.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105928(1, 105928, 140194.395287/0.638152/1000*LumSys, 199138, "105928_McAtNloJimmy_AUET2CT10_WpWmtaunumunu", MaxCuts);
    MonteCarlo.push_back(mc_105928);
  }

  if(McAtNloJimmy_AUET2CT10_WpWmtaunutaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105929.McAtNloJimmy_AUET2CT10_WpWmtaunutaunu.EndProcMark.MINI.e1554_s1499_s1504_r3658_r3549_p1400.130524213908.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105929(1, 105929, 54467.475922/0.638137/1000*LumSys, 77656, "105929_McAtNloJimmy_AUET2CT10_WpWmtaunutaunu", MaxCuts);
    MonteCarlo.push_back(mc_105929);
  }

  if(Herwig_AUET2CTEQ6L1_WW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105985.Herwig_AUET2CTEQ6L1_WW.EndProcMark.MINI.e1576_s1499_s1504_r3658_r3549_p1400.130524213939.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105985(1, 105985, 2489461.145835/20.899853/1000*LumSys, 2489462, "105985_Herwig_AUET2CTEQ6L1_WW", MaxCuts);
    MonteCarlo.push_back(mc_105985);
  }

  if(Herwig_AUET2CTEQ6L1_ZZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105986.Herwig_AUET2CTEQ6L1_ZZ.EndProcMark.MINI.e1576_s1499_s1504_r3658_r3549_p1400.130524214106.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105986(1, 105986, 243659.688344/1.537885/1000*LumSys, 243661, "105986_Herwig_AUET2CTEQ6L1_ZZ", MaxCuts);
    MonteCarlo.push_back(mc_105986);
  }

  if(Herwig_AUET2CTEQ6L1_WZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.105987.Herwig_AUET2CTEQ6L1_WZ.EndProcMark.MINI.e1576_s1499_s1504_r3658_r3549_p1400.130524214139.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_105987(1, 105987, 996214.329673/6.970573/1000*LumSys, 996214, "105987_Herwig_AUET2CTEQ6L1_WZ", MaxCuts);
    MonteCarlo.push_back(mc_105987);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_170GeV_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.106201.McAtNloJimmy_AUET2CT10_ttbar_170GeV_LeptonFilter.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130524214236_rev43817.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106201(1, 106201, 3535450.816040/139.182645/1000*LumSys, 4593494, "106201_McAtNloJimmy_AUET2CT10_ttbar_170GeV_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106201);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_175GeV_LeptonFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.106206.McAtNloJimmy_AUET2CT10_ttbar_175GeV_LeptonFilter.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130524215143.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_106206(1, 106206, 4254858.969986/120.157122/1000*LumSys, 5518138, "106206_McAtNloJimmy_AUET2CT10_ttbar_175GeV_LeptonFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_106206);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107100.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524215819.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107100(1, 107100, 254262.501738/3.073058/1000*LumSys, 254263, "107100_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107100);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107101.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524215849_rev43515.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107101(1, 107101, 124339.401320/1.537267/1000*LumSys, 124339, "107101_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107101);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107102.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524215910.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107102(1, 107102, 59997.857222/0.728574/1000*LumSys, 59997, "107102_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107102);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107103.AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524215929.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107103(1, 107103, 34759.182845/0.404248/1000*LumSys, 34759, "107103_AlpgenJimmy_AUET2CTEQ6L1_WWlnulnuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107103);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107104.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524215948_rev43767.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107104(1, 107104, 398202.293880/1.024871/1000*LumSys, 398203, "107104_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107104);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107105.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220017.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107105(1, 107105, 258640.821493/0.670023/1000*LumSys, 258640, "107105_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107105);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107106.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220042_rev43517.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107106(1, 107106, 149309.616320/0.376953/1000*LumSys, 149310, "107106_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107106);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107107.AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220105_rev43495.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107107(1, 107107, 94304.598005/0.233429/1000*LumSys, 94305, "107107_AlpgenJimmy_AUET2CTEQ6L1_WZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107107);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107108.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220128.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107108(1, 107108, 607142.938958/0.832134/1000*LumSys, 607145, "107108_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp0", MaxCuts);
    MonteCarlo.push_back(mc_107108);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107109.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220159.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107109(1, 107109, 288864.879500/0.396354/1000*LumSys, 288864, "107109_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp1", MaxCuts);
    MonteCarlo.push_back(mc_107109);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107110.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220221_rev43451.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107110(1, 107110, 119576.291181/0.162599/1000*LumSys, 119577, "107110_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp2", MaxCuts);
    MonteCarlo.push_back(mc_107110);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107111.AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130524220242.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107111(1, 107111, 59704.826776/0.077127/1000*LumSys, 59705, "107111_AlpgenJimmy_AUET2CTEQ6L1_ZZincllNp3", MaxCuts);
    MonteCarlo.push_back(mc_107111);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WbbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107280.AlpgenJimmy_AUET2CTEQ6L1_WbbNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524220300.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107280(1, 107280, 443278.949989/65.460864/1000*LumSys, 443279, "107280_AlpgenJimmy_AUET2CTEQ6L1_WbbNp0", MaxCuts);
    MonteCarlo.push_back(mc_107280);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WbbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107281.AlpgenJimmy_AUET2CTEQ6L1_WbbNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524220325.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107281(1, 107281, 324974.466051/53.218704/1000*LumSys, 324975, "107281_AlpgenJimmy_AUET2CTEQ6L1_WbbNp1", MaxCuts);
    MonteCarlo.push_back(mc_107281);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WbbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107282.AlpgenJimmy_AUET2CTEQ6L1_WbbNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524220350_rev43543.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107282(1, 107282, 155751.875668/27.232632/1000*LumSys, 155751, "107282_AlpgenJimmy_AUET2CTEQ6L1_WbbNp2", MaxCuts);
    MonteCarlo.push_back(mc_107282);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WbbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107283.AlpgenJimmy_AUET2CTEQ6L1_WbbNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524220412.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107283(1, 107283, 42844.024761/13.167672/1000*LumSys, 42844, "107283_AlpgenJimmy_AUET2CTEQ6L1_WbbNp3", MaxCuts);
    MonteCarlo.push_back(mc_107283);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524220439.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107650(1, 107650, 6339615.758506/874.753040/1000*LumSys, 6339621, "107650_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0", MaxCuts);
    MonteCarlo.push_back(mc_107650);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524220851.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107651(1, 107651, 1191741.119110/190.740800/1000*LumSys, 1191740, "107651_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1", MaxCuts);
    MonteCarlo.push_back(mc_107651);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524220958_rev43781.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107652(1, 107652, 343649.912164/59.900231/1000*LumSys, 343649, "107652_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2", MaxCuts);
    MonteCarlo.push_back(mc_107652);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221049_rev43537.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107653(1, 107653, 89880.139813/17.478838/1000*LumSys, 89880, "107653_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3", MaxCuts);
    MonteCarlo.push_back(mc_107653);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221131_rev43457.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107654(1, 107654, 24097.367767/4.605186/1000*LumSys, 24098, "107654_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4", MaxCuts);
    MonteCarlo.push_back(mc_107654);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221211.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107655(1, 107655, 7832.962801/1.344772/1000*LumSys, 7833, "107655_AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5", MaxCuts);
    MonteCarlo.push_back(mc_107655);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221234_rev43839.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107660(1, 107660, 6353637.366641/875.121740/1000*LumSys, 6353635, "107660_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107660);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221641_rev43559.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107661(1, 107661, 1180157.602327/190.224620/1000*LumSys, 1180158, "107661_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107661);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221752_rev43497.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107662(1, 107662, 342984.952927/60.078436/1000*LumSys, 342985, "107662_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107662);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524221932_rev43829.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107663(1, 107663, 89800.018185/17.446884/1000*LumSys, 89800, "107663_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107663);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524222016.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107664(1, 107664, 23907.559870/4.673150/1000*LumSys, 23908, "107664_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4", MaxCuts);
    MonteCarlo.push_back(mc_107664);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525145843.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107665(1, 107665, 7752.245386/1.363453/1000*LumSys, 7752, "107665_AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5", MaxCuts);
    MonteCarlo.push_back(mc_107665);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107670.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524222123_rev43565.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107670(1, 107670, 6351855.140437/874.912810/1000*LumSys, 6351856, "107670_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0", MaxCuts);
    MonteCarlo.push_back(mc_107670);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107671.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524222535_rev43563.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107671(1, 107671, 1192461.689374/190.605610/1000*LumSys, 1192462, "107671_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1", MaxCuts);
    MonteCarlo.push_back(mc_107671);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107672.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524222640_rev43561.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107672(1, 107672, 341661.054762/59.981345/1000*LumSys, 341662, "107672_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2", MaxCuts);
    MonteCarlo.push_back(mc_107672);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107673.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150304.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107673(1, 107673, 89955.404149/17.378060/1000*LumSys, 89956, "107673_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3", MaxCuts);
    MonteCarlo.push_back(mc_107673);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107674.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150349.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107674(1, 107674, 24009.075594/4.634682/1000*LumSys, 24009, "107674_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4", MaxCuts);
    MonteCarlo.push_back(mc_107674);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107675.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150427.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107675(1, 107675, 7773.343891/1.366894/1000*LumSys, 7773, "107675_AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5", MaxCuts);
    MonteCarlo.push_back(mc_107675);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107680.AlpgenJimmy_AUET2CTEQ6L1_WenuNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150525.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107680(1, 107680, 3308716.835772/9452.452800/1000*LumSys, 3308717, "107680_AlpgenJimmy_AUET2CTEQ6L1_WenuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107680);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107681.AlpgenJimmy_AUET2CTEQ6L1_WenuNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150727.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107681(1, 107681, 2130980.712469/1857.492000/1000*LumSys, 2130981, "107681_AlpgenJimmy_AUET2CTEQ6L1_WenuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107681);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107682.AlpgenJimmy_AUET2CTEQ6L1_WenuNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525150929.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107682(1, 107682, 2976457.198776/561.316560/1000*LumSys, 2976453, "107682_AlpgenJimmy_AUET2CTEQ6L1_WenuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107682);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107683.AlpgenJimmy_AUET2CTEQ6L1_WenuNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525151205.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107683(1, 107683, 764084.082223/157.454640/1000*LumSys, 764085, "107683_AlpgenJimmy_AUET2CTEQ6L1_WenuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107683);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107684.AlpgenJimmy_AUET2CTEQ6L1_WenuNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525151303.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107684(1, 107684, 184820.211889/41.882064/1000*LumSys, 184820, "107684_AlpgenJimmy_AUET2CTEQ6L1_WenuNp4", MaxCuts);
    MonteCarlo.push_back(mc_107684);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WenuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107685.AlpgenJimmy_AUET2CTEQ6L1_WenuNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525151346.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107685(1, 107685, 50628.536635/12.400920/1000*LumSys, 50628, "107685_AlpgenJimmy_AUET2CTEQ6L1_WenuNp5", MaxCuts);
    MonteCarlo.push_back(mc_107685);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107690.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524223738.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107690(1, 107690, 3332291.810439/9456.098400/1000*LumSys, 3332292, "107690_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107690);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107691.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524223959.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107691(1, 107691, 2130808.453597/1859.256000/1000*LumSys, 2130805, "107691_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107691);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107692.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524224204.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107692(1, 107692, 2976536.523164/561.575280/1000*LumSys, 2976536, "107692_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107692);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107693.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525151956.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107693(1, 107693, 765325.663169/157.384080/1000*LumSys, 765327, "107693_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107693);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107694.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525152101.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107694(1, 107694, 189590.872178/41.840904/1000*LumSys, 189592, "107694_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4", MaxCuts);
    MonteCarlo.push_back(mc_107694);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107695.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525152206.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107695(1, 107695, 14481.074745/12.419736/1000*LumSys, 14481, "107695_AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5", MaxCuts);
    MonteCarlo.push_back(mc_107695);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107700.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525152304_rev43743.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107700(1, 107700, 3231433.181456/9450.571200/1000*LumSys, 3231433, "107700_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0", MaxCuts);
    MonteCarlo.push_back(mc_107700);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107701.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524224841.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107701(1, 107701, 2258457.996996/1857.492000/1000*LumSys, 2258460, "107701_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1", MaxCuts);
    MonteCarlo.push_back(mc_107701);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107702.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130524225052.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107702(1, 107702, 2937040.455076/561.540000/1000*LumSys, 2937041, "107702_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2", MaxCuts);
    MonteCarlo.push_back(mc_107702);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107703.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525152917.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107703(1, 107703, 766307.755221/157.325280/1000*LumSys, 766307, "107703_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3", MaxCuts);
    MonteCarlo.push_back(mc_107703);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107704.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525153009_rev43747.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107704(1, 107704, 184624.056042/41.857368/1000*LumSys, 184624, "107704_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4", MaxCuts);
    MonteCarlo.push_back(mc_107704);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.107705.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5.EndProcMark.MINI.e1571_s1499_s1504_r3658_r3549_p1400.130525153110.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_107705(1, 107705, 47000.927841/12.387984/1000*LumSys, 47001, "107705_AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5", MaxCuts);
    MonteCarlo.push_back(mc_107705);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWenu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu.EndProcMark.MINI.e1525_a159_a171_r3549_p1400.130525153208.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108343(1, 108343, 1009892.832806/0.605908/1000*LumSys, 1194486, "108343_McAtNloJimmy_AUET2CT10_SingleTopSChanWenu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_108343);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu.EndProcMark.MINI.e1525_a159_a171_r3549_p1400.130525153336.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108344(1, 108344, 1010672.183605/0.605889/1000*LumSys, 1195120, "108344_McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_108344);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu.EndProcMark.MINI.e1525_a159_a171_r3549_p1400.130525153506.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108345(1, 108345, 1011106.396083/0.605875/1000*LumSys, 1195558, "108345_McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_108345);
  }

  if(McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.EndProcMark.MINI.e1525_a159_a171_r3549_p1400.130525153643.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_108346(1, 108346, 6160159.376349/22.370945/1000*LumSys, 6969419, "108346_McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_108346);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154028.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109300(1, 109300, 146053.275907/10.306148/1000*LumSys, 146053, "109300_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109300);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154101.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109301(1, 109301, 75516.098485/4.003345/1000*LumSys, 75516, "109301_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109301);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154131.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109302(1, 109302, 41438.031776/1.472465/1000*LumSys, 41438, "109302_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109302);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154203.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109303(1, 109303, 4505.220383/0.625991/1000*LumSys, 4505, "109303_AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109303);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109305.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154231_rev43741.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109305(1, 109305, 145650.733414/10.297299/1000*LumSys, 145651, "109305_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109305);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109306.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154302.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109306(1, 109306, 75776.175130/4.014529/1000*LumSys, 75776, "109306_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109306);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109307.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154330.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109307(1, 109307, 41310.838488/1.459315/1000*LumSys, 41311, "109307_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109307);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109308.AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154356.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109308(1, 109308, 4419.321009/0.621112/1000*LumSys, 4419, "109308_AlpgenJimmy_AUET2CTEQ6L1_ZmumubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109308);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109310.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154421_rev43751.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109310(1, 109310, 146131.521929/10.309835/1000*LumSys, 146132, "109310_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_109310);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109311.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525154448.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109311(1, 109311, 75641.495430/3.998183/1000*LumSys, 75642, "109311_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_109311);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109312.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524231631.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109312(1, 109312, 41442.415154/1.469392/1000*LumSys, 41442, "109312_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_109312);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.109313.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130524231648.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_109313(1, 109313, 4465.574005/0.624578/1000*LumSys, 4466, "109313_AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_109313);
  }

  if(McAtNloJimmy_CT10_ttbar_dilepton_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110001.McAtNloJimmy_CT10_ttbar_dilepton.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130525154605.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110001(1, 110001, 7679830.909442/24.991968/1000*LumSys, 9967339, "110001_McAtNloJimmy_CT10_ttbar_dilepton_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110001);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110002.McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130525155528.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110002(1, 110002, 3867091.699295/26.909393/1000*LumSys, 5023291, "110002_McAtNloJimmy_AUET2CT10_ttbar_170GeV_dilepton_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110002);
  }

  if(McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110003.McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton.EndProcMark.MINI.e1576_a159_a171_r3549_p1400.130525160042.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110003(1, 110003, 1512208.174674/23.228186/1000*LumSys, 1960002, "110003_McAtNloJimmy_AUET2CT10_ttbar_175GeV_dilepton_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110003);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110600.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep.EndProcMark.MINI.e1731_a188_a171_r3549_p1400.130525160512.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110600(1, 110600, 597323.313512/-1.000000/1000*LumSys, 597322, "110600_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110600);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110601.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170.EndProcMark.MINI.e1731_a188_a171_r3549_p1400.130525160618.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110601(1, 110601, 298535.520593/-1.000000/1000*LumSys, 298535, "110601_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt170_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110601);
  }

  if(ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110602.ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175.EndProcMark.MINI.e1731_a188_a171_r3549_p1400.130525160644.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110602(1, 110602, 298699.918754/-1.000000/1000*LumSys, 298701, "110602_ProtosPythia_P2011CCTEQ6L1_tt_bWuZlep_mt175_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110602);
  }

  if(ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110603.ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep.EndProcMark.MINI.e1731_a188_a171_r3549_p1400.130525160711.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110603(1, 110603, 298144.408935/-1.000000/1000*LumSys, 298145, "110603_ProtosPythia_P2011CCTEQ6L1_LessPS_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110603);
  }

  if(ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110604.ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep.EndProcMark.MINI.e1731_a188_a171_r3549_p1400.130525160752.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110604(1, 110604, 298764.336094/-1.000000/1000*LumSys, 298765, "110604_ProtosPythia_P2011CCTEQ6L1_MorePS_tt_bWuZlep_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_110604);
  }

  if(AlpgenPythia_P2011C_WbbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110801.AlpgenPythia_P2011C_WbbNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525160816.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110801(1, 110801, 441277.785452/59.204915/1000*LumSys, 441278, "110801_AlpgenPythia_P2011C_WbbNp0", MaxCuts);
    MonteCarlo.push_back(mc_110801);
  }

  if(AlpgenPythia_P2011C_WbbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110802.AlpgenPythia_P2011C_WbbNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525160844.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110802(1, 110802, 320943.401135/51.596820/1000*LumSys, 320944, "110802_AlpgenPythia_P2011C_WbbNp1", MaxCuts);
    MonteCarlo.push_back(mc_110802);
  }

  if(AlpgenPythia_P2011C_WbbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110803.AlpgenPythia_P2011C_WbbNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525160911.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110803(1, 110803, 151835.047240/26.819243/1000*LumSys, 151835, "110803_AlpgenPythia_P2011C_WbbNp2", MaxCuts);
    MonteCarlo.push_back(mc_110803);
  }

  if(AlpgenPythia_P2011C_WbbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110804.AlpgenPythia_P2011C_WbbNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130524233108.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110804(1, 110804, 41489.524298/14.190825/1000*LumSys, 41490, "110804_AlpgenPythia_P2011C_WbbNp3", MaxCuts);
    MonteCarlo.push_back(mc_110804);
  }

  if(AlpgenPythia_P2011C_ZeeccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110805.AlpgenPythia_P2011C_ZeeccNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525160943.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110805(1, 110805, 577875.711694/17.826260/1000*LumSys, 577877, "110805_AlpgenPythia_P2011C_ZeeccNp0", MaxCuts);
    MonteCarlo.push_back(mc_110805);
  }

  if(AlpgenPythia_P2011C_ZeeccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110806.AlpgenPythia_P2011C_ZeeccNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130524233158_rev43831.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110806(1, 110806, 233945.429193/8.511458/1000*LumSys, 233946, "110806_AlpgenPythia_P2011C_ZeeccNp1", MaxCuts);
    MonteCarlo.push_back(mc_110806);
  }

  if(AlpgenPythia_P2011C_ZeeccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110807.AlpgenPythia_P2011C_ZeeccNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161026.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110807(1, 110807, 94471.258880/3.577760/1000*LumSys, 94471, "110807_AlpgenPythia_P2011C_ZeeccNp2", MaxCuts);
    MonteCarlo.push_back(mc_110807);
  }

  if(AlpgenPythia_P2011C_ZeeccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110808.AlpgenPythia_P2011C_ZeeccNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161053.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110808(1, 110808, 31537.533358/1.388506/1000*LumSys, 31538, "110808_AlpgenPythia_P2011C_ZeeccNp3", MaxCuts);
    MonteCarlo.push_back(mc_110808);
  }

  if(AlpgenPythia_P2011C_ZmumuccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110809.AlpgenPythia_P2011C_ZmumuccNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161116_rev43755.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110809(1, 110809, 573771.119331/17.835700/1000*LumSys, 573771, "110809_AlpgenPythia_P2011C_ZmumuccNp0", MaxCuts);
    MonteCarlo.push_back(mc_110809);
  }

  if(AlpgenPythia_P2011C_ZmumuccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110810.AlpgenPythia_P2011C_ZmumuccNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161153.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110810(1, 110810, 238666.220600/8.493640/1000*LumSys, 238666, "110810_AlpgenPythia_P2011C_ZmumuccNp1", MaxCuts);
    MonteCarlo.push_back(mc_110810);
  }

  if(AlpgenPythia_P2011C_ZmumuccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110811.AlpgenPythia_P2011C_ZmumuccNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161219.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110811(1, 110811, 99189.536169/3.575754/1000*LumSys, 99189, "110811_AlpgenPythia_P2011C_ZmumuccNp2", MaxCuts);
    MonteCarlo.push_back(mc_110811);
  }

  if(AlpgenPythia_P2011C_ZmumuccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110812.AlpgenPythia_P2011C_ZmumuccNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161243.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110812(1, 110812, 31599.147895/1.385084/1000*LumSys, 31599, "110812_AlpgenPythia_P2011C_ZmumuccNp3", MaxCuts);
    MonteCarlo.push_back(mc_110812);
  }

  if(AlpgenPythia_P2011C_ZtautauccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110813.AlpgenPythia_P2011C_ZtautauccNp0.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130524233434.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110813(1, 110813, 567701.413578/17.840420/1000*LumSys, 567703, "110813_AlpgenPythia_P2011C_ZtautauccNp0", MaxCuts);
    MonteCarlo.push_back(mc_110813);
  }

  if(AlpgenPythia_P2011C_ZtautauccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110814.AlpgenPythia_P2011C_ZtautauccNp1.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161317.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110814(1, 110814, 238135.551943/8.497888/1000*LumSys, 238136, "110814_AlpgenPythia_P2011C_ZtautauccNp1", MaxCuts);
    MonteCarlo.push_back(mc_110814);
  }

  if(AlpgenPythia_P2011C_ZtautauccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110815.AlpgenPythia_P2011C_ZtautauccNp2.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161345_rev43757.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110815(1, 110815, 98921.838803/3.585430/1000*LumSys, 98922, "110815_AlpgenPythia_P2011C_ZtautauccNp2", MaxCuts);
    MonteCarlo.push_back(mc_110815);
  }

  if(AlpgenPythia_P2011C_ZtautauccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110816.AlpgenPythia_P2011C_ZtautauccNp3.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161408.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110816(1, 110816, 31514.863100/1.377886/1000*LumSys, 31515, "110816_AlpgenPythia_P2011C_ZtautauccNp3", MaxCuts);
    MonteCarlo.push_back(mc_110816);
  }

  if(AlpgenPythia_P2011C_ZeebbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110817.AlpgenPythia_P2011C_ZeebbNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161430.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110817(1, 110817, 145783.785802/9.486846/1000*LumSys, 145784, "110817_AlpgenPythia_P2011C_ZeebbNp0", MaxCuts);
    MonteCarlo.push_back(mc_110817);
  }

  if(AlpgenPythia_P2011C_ZeebbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110818.AlpgenPythia_P2011C_ZeebbNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161454.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110818(1, 110818, 75043.841343/3.817654/1000*LumSys, 75044, "110818_AlpgenPythia_P2011C_ZeebbNp1", MaxCuts);
    MonteCarlo.push_back(mc_110818);
  }

  if(AlpgenPythia_P2011C_ZeebbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110819.AlpgenPythia_P2011C_ZeebbNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161527.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110819(1, 110819, 40656.083655/1.343784/1000*LumSys, 40656, "110819_AlpgenPythia_P2011C_ZeebbNp2", MaxCuts);
    MonteCarlo.push_back(mc_110819);
  }

  if(AlpgenPythia_P2011C_ZeebbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110820.AlpgenPythia_P2011C_ZeebbNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161547.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110820(1, 110820, 4355.600168/0.578979/1000*LumSys, 4356, "110820_AlpgenPythia_P2011C_ZeebbNp3", MaxCuts);
    MonteCarlo.push_back(mc_110820);
  }

  if(AlpgenPythia_P2011C_ZmumubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110821.AlpgenPythia_P2011C_ZmumubbNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161607.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110821(1, 110821, 145622.348333/9.489796/1000*LumSys, 145623, "110821_AlpgenPythia_P2011C_ZmumubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_110821);
  }

  if(AlpgenPythia_P2011C_ZmumubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110822.AlpgenPythia_P2011C_ZmumubbNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525212836_rev43857.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110822(1, 110822, 75047.508712/3.794290/1000*LumSys, 75048, "110822_AlpgenPythia_P2011C_ZmumubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_110822);
  }

  if(AlpgenPythia_P2011C_ZmumubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110823.AlpgenPythia_P2011C_ZmumubbNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161650.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110823(1, 110823, 40682.623590/1.345200/1000*LumSys, 40683, "110823_AlpgenPythia_P2011C_ZmumubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_110823);
  }

  if(AlpgenPythia_P2011C_ZmumubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110824.AlpgenPythia_P2011C_ZmumubbNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525161708.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110824(1, 110824, 4223.045219/0.601127/1000*LumSys, 4223, "110824_AlpgenPythia_P2011C_ZmumubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_110824);
  }

  if(AlpgenPythia_P2011C_ZtautaubbNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110825.AlpgenPythia_P2011C_ZtautaubbNp0.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161727.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110825(1, 110825, 145891.852504/9.482244/1000*LumSys, 145891, "110825_AlpgenPythia_P2011C_ZtautaubbNp0", MaxCuts);
    MonteCarlo.push_back(mc_110825);
  }

  if(AlpgenPythia_P2011C_ZtautaubbNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110826.AlpgenPythia_P2011C_ZtautaubbNp1.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161748.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110826(1, 110826, 75037.641863/3.811282/1000*LumSys, 75037, "110826_AlpgenPythia_P2011C_ZtautaubbNp1", MaxCuts);
    MonteCarlo.push_back(mc_110826);
  }

  if(AlpgenPythia_P2011C_ZtautaubbNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110827.AlpgenPythia_P2011C_ZtautaubbNp2.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161809.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110827(1, 110827, 40656.904124/1.350510/1000*LumSys, 40657, "110827_AlpgenPythia_P2011C_ZtautaubbNp2", MaxCuts);
    MonteCarlo.push_back(mc_110827);
  }

  if(AlpgenPythia_P2011C_ZtautaubbNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110828.AlpgenPythia_P2011C_ZtautaubbNp3.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525161830.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110828(1, 110828, 4289.868321/0.581339/1000*LumSys, 4290, "110828_AlpgenPythia_P2011C_ZtautaubbNp3", MaxCuts);
    MonteCarlo.push_back(mc_110828);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110829.AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp0.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130525212948.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110829(1, 110829, 990499.055221/12.808774/1000*LumSys, 990498, "110829_AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp0", MaxCuts);
    MonteCarlo.push_back(mc_110829);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110830.AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp1.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130525161933.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110830(1, 110830, 492800.010439/6.434478/1000*LumSys, 492799, "110830_AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp1", MaxCuts);
    MonteCarlo.push_back(mc_110830);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110831.AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp2.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130525162002.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110831(1, 110831, 233968.850134/3.035795/1000*LumSys, 233969, "110831_AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp2", MaxCuts);
    MonteCarlo.push_back(mc_110831);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.110832.AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp3.EndProcMark.MINI.e1596_s1499_s1504_r3658_r3549_p1400.130525162031.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_110832(1, 110832, 129306.140939/1.685996/1000*LumSys, 129307, "110832_AlpgenJimmy_AUET2CTEQ6L1_WWqqlnuNp3", MaxCuts);
    MonteCarlo.push_back(mc_110832);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbbincl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.116108.AlpgenJimmy_AUET2CTEQ6L1_ttbbincl.EndProcMark.MINI.e1533_a159_a171_r3549_p1400.130524235315.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116108(1, 116108, 1769225.901596/2.424222/1000*LumSys, 1769224, "116108_AlpgenJimmy_AUET2CTEQ6L1_ttbbincl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_116108);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttccincl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.116109.AlpgenJimmy_AUET2CTEQ6L1_ttccincl.EndProcMark.MINI.e1533_a159_a171_r3549_p1400.130524235411.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_116109(1, 116109, 2020939.238863/4.582257/1000*LumSys, 2020941, "116109_AlpgenJimmy_AUET2CTEQ6L1_ttccincl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_116109);
  }

  if(PowhegPythia_P2011C_ttbar){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117050.PowhegPythia_P2011C_ttbar.EndProcMark.MINI.e1728_s1581_s1586_r3658_r3549_p1400.130524202653.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117050(1, 117050, 8988174.075315/129.270659/1000*LumSys, 8988179, "117050_PowhegPythia_P2011C_ttbar", MaxCuts);
    MonteCarlo.push_back(mc_117050);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117209.AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525162537.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117209(1, 117209, 5494028.390505/129.264832/1000*LumSys, 5494020, "117209_AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_noallhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117209);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117210.AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525163259.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117210(1, 117210, 5950468.841975/129.266458/1000*LumSys, 5950474, "117210_AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_noallhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117210);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_allhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117211.AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_allhad.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525163925.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117211(1, 117211, 1194605.766916/108.788411/1000*LumSys, 1194605, "117211_AcerMCPythia_AUET2BCTEQ6L1_MorePS_ttbar_allhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117211);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_allhad_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117212.AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_allhad.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164009.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117212(1, 117212, 1194696.583195/108.786238/1000*LumSys, 1194698, "117212_AcerMCPythia_AUET2BCTEQ6L1_LessPS_ttbar_allhad_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117212);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_e_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117213.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_e.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164108.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117213(1, 117213, 199023.157840/0.605878/1000*LumSys, 199023, "117213_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_e_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117213);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_e_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117214.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_e.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164131.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117214(1, 117214, 199322.829030/0.605885/1000*LumSys, 199322, "117214_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_e_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117214);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_mu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117215.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_mu.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164153_rev43761.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117215(1, 117215, 198747.716918/0.605898/1000*LumSys, 198748, "117215_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_mu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117215);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_mu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117216.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_mu.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164216.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117216(1, 117216, 199102.355799/0.605881/1000*LumSys, 199103, "117216_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_mu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117216);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_tau_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117217.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_tau.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000720.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117217(1, 117217, 199392.607732/0.605866/1000*LumSys, 199393, "117217_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_schan_tau_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117217);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_tau_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117218.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_tau.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000752.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117218(1, 117218, 199266.487956/0.605893/1000*LumSys, 199266, "117218_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_schan_tau_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117218);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_e_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117219.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_e.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000815.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117219(1, 117219, 255856.633858/9.478489/1000*LumSys, 298694, "117219_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_e_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117219);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_e_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117220.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_e.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000839.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117220(1, 117220, 256307.364794/9.478048/1000*LumSys, 299154, "117220_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_e_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117220);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_mu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117221.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_mu.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525164310.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117221(1, 117221, 255834.401335/9.478061/1000*LumSys, 298884, "117221_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_mu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117221);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_mu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117222.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_mu.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000927.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117222(1, 117222, 256300.002653/9.477840/1000*LumSys, 299276, "117222_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_mu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117222);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_tau_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117223.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_tau.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525000949.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117223(1, 117223, 255450.186204/9.477740/1000*LumSys, 298407, "117223_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_tchan_tau_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117223);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_tau_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117224.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_tau.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525001011.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117224(1, 117224, 255633.389841/9.478156/1000*LumSys, 298542, "117224_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_tchan_tau_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117224);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_Wtchan_incl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117245.AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_Wtchan_incl.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525001034.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117245(1, 117245, 994754.920877/22.369986/1000*LumSys, 994754, "117245_AcerMCPythia_AUET2BCTEQ6L1_MorePS_singletop_Wtchan_incl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117245);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_Wtchan_incl_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117246.AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_Wtchan_incl.EndProcMark.MINI.e1378_a159_a171_r3549_p1400.130525001109.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117246(1, 117246, 996139.112797/22.369986/1000*LumSys, 996140, "117246_AcerMCPythia_AUET2BCTEQ6L1_LessPS_singletop_Wtchan_incl_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117246);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117284.AlpgenJimmy_AUET2CTEQ6L1_WccNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001150.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117284(1, 117284, 1206627.208925/176.599920/1000*LumSys, 1206625, "117284_AlpgenJimmy_AUET2CTEQ6L1_WccNp0", MaxCuts);
    MonteCarlo.push_back(mc_117284);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117285.AlpgenJimmy_AUET2CTEQ6L1_WccNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001224.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117285(1, 117285, 962857.569553/156.043440/1000*LumSys, 962856, "117285_AlpgenJimmy_AUET2CTEQ6L1_WccNp1", MaxCuts);
    MonteCarlo.push_back(mc_117285);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117286.AlpgenJimmy_AUET2CTEQ6L1_WccNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001258.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117286(1, 117286, 474089.140016/84.481488/1000*LumSys, 474090, "117286_AlpgenJimmy_AUET2CTEQ6L1_WccNp2", MaxCuts);
    MonteCarlo.push_back(mc_117286);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117287.AlpgenJimmy_AUET2CTEQ6L1_WccNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001324.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117287(1, 117287, 146762.700801/35.581056/1000*LumSys, 146762, "117287_AlpgenJimmy_AUET2CTEQ6L1_WccNp3", MaxCuts);
    MonteCarlo.push_back(mc_117287);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WcNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117293.AlpgenJimmy_AUET2CTEQ6L1_WcNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001351.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117293(1, 117293, 6446665.030101/1228.129600/1000*LumSys, 6446659, "117293_AlpgenJimmy_AUET2CTEQ6L1_WcNp0", MaxCuts);
    MonteCarlo.push_back(mc_117293);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WcNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117294.AlpgenJimmy_AUET2CTEQ6L1_WcNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001603.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117294(1, 117294, 2035721.410935/406.843200/1000*LumSys, 2035723, "117294_AlpgenJimmy_AUET2CTEQ6L1_WcNp1", MaxCuts);
    MonteCarlo.push_back(mc_117294);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WcNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117295.AlpgenJimmy_AUET2CTEQ6L1_WcNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001653.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117295(1, 117295, 505015.362435/106.234320/1000*LumSys, 505015, "117295_AlpgenJimmy_AUET2CTEQ6L1_WcNp2", MaxCuts);
    MonteCarlo.push_back(mc_117295);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WcNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117296.AlpgenJimmy_AUET2CTEQ6L1_WcNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001720.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117296(1, 117296, 105358.110688/31.257280/1000*LumSys, 105358, "117296_AlpgenJimmy_AUET2CTEQ6L1_WcNp3", MaxCuts);
    MonteCarlo.push_back(mc_117296);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WcNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117297.AlpgenJimmy_AUET2CTEQ6L1_WcNp4.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525001742.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117297(1, 117297, 18968.708129/6.548464/1000*LumSys, 18969, "117297_AlpgenJimmy_AUET2CTEQ6L1_WcNp4", MaxCuts);
    MonteCarlo.push_back(mc_117297);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e.EndProcMark.MINI.e1346_a159_a171_r3549_p1400.130525001804.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117360(1, 117360, 1959998.104481/9.478355/1000*LumSys, 2290484, "117360_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117360);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu.EndProcMark.MINI.e1346_a159_a171_r3549_p1400.130525001945.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117361(1, 117361, 1957636.997388/9.477851/1000*LumSys, 2286106, "117361_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117361);
  }

  if(AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau.EndProcMark.MINI.e1346_a159_a171_r3549_p1400.130525002111.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117362(1, 117362, 1960839.233983/9.477714/1000*LumSys, 2288917, "117362_AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_117362);
  }

  if(AlpgenPythia_P2011C_ZeeNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002238.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117650(1, 117650, 6277940.467894/848.290200/1000*LumSys, 6277941, "117650_AlpgenPythia_P2011C_ZeeNp0", MaxCuts);
    MonteCarlo.push_back(mc_117650);
  }

  if(AlpgenPythia_P2011C_ZeeNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002426.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117651(1, 117651, 1150680.630105/207.208000/1000*LumSys, 1150681, "117651_AlpgenPythia_P2011C_ZeeNp1", MaxCuts);
    MonteCarlo.push_back(mc_117651);
  }

  if(AlpgenPythia_P2011C_ZeeNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002505.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117652(1, 117652, 327668.980151/69.441820/1000*LumSys, 327669, "117652_AlpgenPythia_P2011C_ZeeNp2", MaxCuts);
    MonteCarlo.push_back(mc_117652);
  }

  if(AlpgenPythia_P2011C_ZeeNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002529.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117653(1, 117653, 82274.785431/18.360800/1000*LumSys, 82275, "117653_AlpgenPythia_P2011C_ZeeNp3", MaxCuts);
    MonteCarlo.push_back(mc_117653);
  }

  if(AlpgenPythia_P2011C_ZeeNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002552.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117654(1, 117654, 21332.706377/4.639996/1000*LumSys, 21333, "117654_AlpgenPythia_P2011C_ZeeNp4", MaxCuts);
    MonteCarlo.push_back(mc_117654);
  }

  if(AlpgenPythia_P2011C_ZeeNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002610.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117655(1, 117655, 6645.047938/1.415292/1000*LumSys, 6645, "117655_AlpgenPythia_P2011C_ZeeNp5", MaxCuts);
    MonteCarlo.push_back(mc_117655);
  }

  if(AlpgenPythia_P2011C_ZmumuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002640.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117660(1, 117660, 6269941.469643/848.313800/1000*LumSys, 6269943, "117660_AlpgenPythia_P2011C_ZmumuNp0", MaxCuts);
    MonteCarlo.push_back(mc_117660);
  }

  if(AlpgenPythia_P2011C_ZmumuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002815.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117661(1, 117661, 1156134.164596/207.455800/1000*LumSys, 1156136, "117661_AlpgenPythia_P2011C_ZmumuNp1", MaxCuts);
    MonteCarlo.push_back(mc_117661);
  }

  if(AlpgenPythia_P2011C_ZmumuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002851.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117662(1, 117662, 328614.165573/69.389900/1000*LumSys, 328614, "117662_AlpgenPythia_P2011C_ZmumuNp2", MaxCuts);
    MonteCarlo.push_back(mc_117662);
  }

  if(AlpgenPythia_P2011C_ZmumuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002916.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117663(1, 117663, 82310.034916/18.395020/1000*LumSys, 82309, "117663_AlpgenPythia_P2011C_ZmumuNp3", MaxCuts);
    MonteCarlo.push_back(mc_117663);
  }

  if(AlpgenPythia_P2011C_ZmumuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002936.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117664(1, 117664, 21378.104126/4.610496/1000*LumSys, 21378, "117664_AlpgenPythia_P2011C_ZmumuNp4", MaxCuts);
    MonteCarlo.push_back(mc_117664);
  }

  if(AlpgenPythia_P2011C_ZmumuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525002953.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117665(1, 117665, 6615.301088/1.408094/1000*LumSys, 6615, "117665_AlpgenPythia_P2011C_ZmumuNp5", MaxCuts);
    MonteCarlo.push_back(mc_117665);
  }

  if(AlpgenPythia_P2011C_ZtautauNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117670.AlpgenPythia_P2011C_ZtautauNp0.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003020.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117670(1, 117670, 6275574.181888/848.184000/1000*LumSys, 6275577, "117670_AlpgenPythia_P2011C_ZtautauNp0", MaxCuts);
    MonteCarlo.push_back(mc_117670);
  }

  if(AlpgenPythia_P2011C_ZtautauNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117671.AlpgenPythia_P2011C_ZtautauNp1.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003210.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117671(1, 117671, 1156641.457290/207.479400/1000*LumSys, 1156644, "117671_AlpgenPythia_P2011C_ZtautauNp1", MaxCuts);
    MonteCarlo.push_back(mc_117671);
  }

  if(AlpgenPythia_P2011C_ZtautauNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117672.AlpgenPythia_P2011C_ZtautauNp2.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003253.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117672(1, 117672, 327666.180909/69.183400/1000*LumSys, 327666, "117672_AlpgenPythia_P2011C_ZtautauNp2", MaxCuts);
    MonteCarlo.push_back(mc_117672);
  }

  if(AlpgenPythia_P2011C_ZtautauNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117673.AlpgenPythia_P2011C_ZtautauNp3.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003317.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117673(1, 117673, 82316.120879/18.299440/1000*LumSys, 82316, "117673_AlpgenPythia_P2011C_ZtautauNp3", MaxCuts);
    MonteCarlo.push_back(mc_117673);
  }

  if(AlpgenPythia_P2011C_ZtautauNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117674.AlpgenPythia_P2011C_ZtautauNp4.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003336.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117674(1, 117674, 21575.524376/4.664068/1000*LumSys, 21576, "117674_AlpgenPythia_P2011C_ZtautauNp4", MaxCuts);
    MonteCarlo.push_back(mc_117674);
  }

  if(AlpgenPythia_P2011C_ZtautauNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117675.AlpgenPythia_P2011C_ZtautauNp5.EndProcMark.MINI.e1711_s1581_s1586_r3658_r3549_p1400.130525003354_rev43835.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117675(1, 117675, 6602.887452/1.392990/1000*LumSys, 6603, "117675_AlpgenPythia_P2011C_ZtautauNp5", MaxCuts);
    MonteCarlo.push_back(mc_117675);
  }

  if(AlpgenPythia_P2011C_WenuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117680.AlpgenPythia_P2011C_WenuNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003412.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117680(1, 117680, 3286824.375304/9218.994400/1000*LumSys, 3286824, "117680_AlpgenPythia_P2011C_WenuNp0", MaxCuts);
    MonteCarlo.push_back(mc_117680);
  }

  if(AlpgenPythia_P2011C_WenuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117681.AlpgenPythia_P2011C_WenuNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003454.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117681(1, 117681, 2071355.290215/2029.769500/1000*LumSys, 2071353, "117681_AlpgenPythia_P2011C_WenuNp1", MaxCuts);
    MonteCarlo.push_back(mc_117681);
  }

  if(AlpgenPythia_P2011C_WenuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117682.AlpgenPythia_P2011C_WenuNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003532.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117682(1, 117682, 2794944.294321/613.632800/1000*LumSys, 2794943, "117682_AlpgenPythia_P2011C_WenuNp2", MaxCuts);
    MonteCarlo.push_back(mc_117682);
  }

  if(AlpgenPythia_P2011C_WenuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117683.AlpgenPythia_P2011C_WenuNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003625.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117683(1, 117683, 698742.149288/166.154450/1000*LumSys, 698741, "117683_AlpgenPythia_P2011C_WenuNp3", MaxCuts);
    MonteCarlo.push_back(mc_117683);
  }

  if(AlpgenPythia_P2011C_WenuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117684.AlpgenPythia_P2011C_WenuNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003658.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117684(1, 117684, 164664.945122/42.299422/1000*LumSys, 164664, "117684_AlpgenPythia_P2011C_WenuNp4", MaxCuts);
    MonteCarlo.push_back(mc_117684);
  }

  if(AlpgenPythia_P2011C_WenuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117685.AlpgenPythia_P2011C_WenuNp5.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003725.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117685(1, 117685, 43662.613203/12.865215/1000*LumSys, 43662, "117685_AlpgenPythia_P2011C_WenuNp5", MaxCuts);
    MonteCarlo.push_back(mc_117685);
  }

  if(AlpgenPythia_P2011C_WmunuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117690.AlpgenPythia_P2011C_WmunuNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003754.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117690(1, 117690, 3294292.442151/9215.142200/1000*LumSys, 3294286, "117690_AlpgenPythia_P2011C_WmunuNp0", MaxCuts);
    MonteCarlo.push_back(mc_117690);
  }

  if(AlpgenPythia_P2011C_WmunuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117691.AlpgenPythia_P2011C_WmunuNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003848.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117691(1, 117691, 2072276.340342/2031.129100/1000*LumSys, 2072276, "117691_AlpgenPythia_P2011C_WmunuNp1", MaxCuts);
    MonteCarlo.push_back(mc_117691);
  }

  if(AlpgenPythia_P2011C_WmunuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117692.AlpgenPythia_P2011C_WmunuNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525003934.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117692(1, 117692, 2792567.936153/613.258910/1000*LumSys, 2792573, "117692_AlpgenPythia_P2011C_WmunuNp2", MaxCuts);
    MonteCarlo.push_back(mc_117692);
  }

  if(AlpgenPythia_P2011C_WmunuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117693.AlpgenPythia_P2011C_WmunuNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004102.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117693(1, 117693, 698256.368850/165.973170/1000*LumSys, 698255, "117693_AlpgenPythia_P2011C_WmunuNp3", MaxCuts);
    MonteCarlo.push_back(mc_117693);
  }

  if(AlpgenPythia_P2011C_WmunuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117694.AlpgenPythia_P2011C_WmunuNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004132.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117694(1, 117694, 168390.771739/42.307353/1000*LumSys, 168391, "117694_AlpgenPythia_P2011C_WmunuNp4", MaxCuts);
    MonteCarlo.push_back(mc_117694);
  }

  if(AlpgenPythia_P2011C_WmunuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117695.AlpgenPythia_P2011C_WmunuNp5.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004153.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117695(1, 117695, 39223.558257/12.875412/1000*LumSys, 39223, "117695_AlpgenPythia_P2011C_WmunuNp5", MaxCuts);
    MonteCarlo.push_back(mc_117695);
  }

  if(AlpgenPythia_P2011C_WtaunuNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117700.AlpgenPythia_P2011C_WtaunuNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004211.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117700(1, 117700, 3247178.586059/9217.748100/1000*LumSys, 3247180, "117700_AlpgenPythia_P2011C_WtaunuNp0", MaxCuts);
    MonteCarlo.push_back(mc_117700);
  }

  if(AlpgenPythia_P2011C_WtaunuNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117701.AlpgenPythia_P2011C_WtaunuNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004301.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117701(1, 117701, 2073708.129613/2032.262100/1000*LumSys, 2073709, "117701_AlpgenPythia_P2011C_WtaunuNp1", MaxCuts);
    MonteCarlo.push_back(mc_117701);
  }

  if(AlpgenPythia_P2011C_WtaunuNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117702.AlpgenPythia_P2011C_WtaunuNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004355.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117702(1, 117702, 2796151.483081/613.224920/1000*LumSys, 2796155, "117702_AlpgenPythia_P2011C_WtaunuNp2", MaxCuts);
    MonteCarlo.push_back(mc_117702);
  }

  if(AlpgenPythia_P2011C_WtaunuNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117703.AlpgenPythia_P2011C_WtaunuNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004509.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117703(1, 117703, 699919.833702/165.961840/1000*LumSys, 699921, "117703_AlpgenPythia_P2011C_WtaunuNp3", MaxCuts);
    MonteCarlo.push_back(mc_117703);
  }

  if(AlpgenPythia_P2011C_WtaunuNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117704.AlpgenPythia_P2011C_WtaunuNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004546.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117704(1, 117704, 165485.171434/42.310752/1000*LumSys, 165486, "117704_AlpgenPythia_P2011C_WtaunuNp4", MaxCuts);
    MonteCarlo.push_back(mc_117704);
  }

  if(AlpgenPythia_P2011C_WtaunuNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117705.AlpgenPythia_P2011C_WtaunuNp5.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525004608.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117705(1, 117705, 40562.409313/13.003441/1000*LumSys, 40563, "117705_AlpgenPythia_P2011C_WtaunuNp5", MaxCuts);
    MonteCarlo.push_back(mc_117705);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117706.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525004627_rev43845.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117706(1, 117706, 582621.122798/19.241224/1000*LumSys, 582620, "117706_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0", MaxCuts);
    MonteCarlo.push_back(mc_117706);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117707.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525004650.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117707(1, 117707, 247532.451648/8.477642/1000*LumSys, 247533, "117707_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1", MaxCuts);
    MonteCarlo.push_back(mc_117707);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117708.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525004712.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117708(1, 117708, 105077.109042/3.570982/1000*LumSys, 105077, "117708_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2", MaxCuts);
    MonteCarlo.push_back(mc_117708);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117709.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525004731_rev43823.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117709(1, 117709, 35049.151695/1.398110/1000*LumSys, 35049, "117709_AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3", MaxCuts);
    MonteCarlo.push_back(mc_117709);
  }

  if(Sherpa_CT10_TtbarLeptLept){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117800.Sherpa_CT10_TtbarLeptLept.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525004749.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117800(1, 117800, 1791285.410063/11.107321/1000*LumSys, 1791283, "117800_Sherpa_CT10_TtbarLeptLept", MaxCuts);
    MonteCarlo.push_back(mc_117800);
  }

  if(Sherpa_CT10_TtbarLeptTaulept){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117801.Sherpa_CT10_TtbarLeptTaulept.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525004838.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117801(1, 117801, 596257.493926/3.909754/1000*LumSys, 596257, "117801_Sherpa_CT10_TtbarLeptTaulept", MaxCuts);
    MonteCarlo.push_back(mc_117801);
  }

  if(Sherpa_CT10_TtbarTauleptTaulept){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117802.Sherpa_CT10_TtbarTauleptTaulept.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525004904.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117802(1, 117802, 54724.815835/0.344064/1000*LumSys, 54725, "117802_Sherpa_CT10_TtbarTauleptTaulept", MaxCuts);
    MonteCarlo.push_back(mc_117802);
  }

  if(Sherpa_CT10_TtbarLeptHad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117803.Sherpa_CT10_TtbarLeptHad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525004923.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117803(1, 117803, 7367725.988562/69.519427/1000*LumSys, 7367728, "117803_Sherpa_CT10_TtbarLeptHad", MaxCuts);
    MonteCarlo.push_back(mc_117803);
  }

  if(Sherpa_CT10_TtbarLeptTauhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117804.Sherpa_CT10_TtbarLeptTauhad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525005402.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117804(1, 117804, 1095034.334614/7.197240/1000*LumSys, 1095034, "117804_Sherpa_CT10_TtbarLeptTauhad", MaxCuts);
    MonteCarlo.push_back(mc_117804);
  }

  if(Sherpa_CT10_TtbarTauleptHad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117805.Sherpa_CT10_TtbarTauleptHad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525005446.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117805(1, 117805, 1791101.317390/12.236142/1000*LumSys, 1791102, "117805_Sherpa_CT10_TtbarTauleptHad", MaxCuts);
    MonteCarlo.push_back(mc_117805);
  }

  if(Sherpa_CT10_TtbarTauleptTauhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117806.Sherpa_CT10_TtbarTauleptTauhad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525005538.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117806(1, 117806, 198951.514195/1.266680/1000*LumSys, 198952, "117806_Sherpa_CT10_TtbarTauleptTauhad", MaxCuts);
    MonteCarlo.push_back(mc_117806);
  }

  if(Sherpa_CT10_TtbarHadHad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117807.Sherpa_CT10_TtbarHadHad.EndProcMark.MINI.e1583_s1499_s1504_r3658_r3549_p1400.130525005559.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117807(1, 117807, 5474362.038923/108.785125/1000*LumSys, 5474361, "117807_Sherpa_CT10_TtbarHadHad", MaxCuts);
    MonteCarlo.push_back(mc_117807);
  }

  if(Sherpa_CT10_TtbarHadTauhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117808.Sherpa_CT10_TtbarHadTauhad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525005807.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117808(1, 117808, 3183876.379147/22.524651/1000*LumSys, 3183882, "117808_Sherpa_CT10_TtbarHadTauhad", MaxCuts);
    MonteCarlo.push_back(mc_117808);
  }

  if(Sherpa_CT10_TtbarTauhadTauhad){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.117809.Sherpa_CT10_TtbarTauhadTauhad.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525005921.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_117809(1, 117809, 179128.888329/1.165923/1000*LumSys, 179129, "117809_Sherpa_CT10_TtbarTauhadTauhad", MaxCuts);
    MonteCarlo.push_back(mc_117809);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.EndProcMark.MINI.e1352_s1499_s1504_r3658_r3549_p1400.130525005943.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119353(1, 119353, 398472.107766/0.122317/1000*LumSys, 398471, "119353_MadGraphPythia_AUET2BCTEQ6L1_ttbarW", MaxCuts);
    MonteCarlo.push_back(mc_119353);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarWj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.EndProcMark.MINI.e1352_s1499_s1504_r3658_r3549_p1400.130525010009.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119354(1, 119354, 398678.188975/0.109665/1000*LumSys, 398680, "119354_MadGraphPythia_AUET2BCTEQ6L1_ttbarWj", MaxCuts);
    MonteCarlo.push_back(mc_119354);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.EndProcMark.MINI.e1352_s1499_s1504_r3658_r3549_p1400.130525010038.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119355(1, 119355, 398234.630567/0.090705/1000*LumSys, 398233, "119355_MadGraphPythia_AUET2BCTEQ6L1_ttbarZ", MaxCuts);
    MonteCarlo.push_back(mc_119355);
  }

  if(MadGraphPythia_AUET2BCTEQ6L1_ttbarZj){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.EndProcMark.MINI.e1352_s1499_s1504_r3658_r3549_p1400.130525010109.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119356(1, 119356, 398115.781553/0.117034/1000*LumSys, 398115, "119356_MadGraphPythia_AUET2BCTEQ6L1_ttbarZj", MaxCuts);
    MonteCarlo.push_back(mc_119356);
  }

  if(MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.EndProcMark.MINI.e1543_s1499_s1504_r3658_r3549_p1400.130525010136.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_119583(1, 119583, 10059.916650/0.000919/1000*LumSys, 10060, "119583_MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW", MaxCuts);
    MonteCarlo.push_back(mc_119583);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126414.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010155.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126414(1, 126414, 586421.814045/19.246140/1000*LumSys, 586422, "126414_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0", MaxCuts);
    MonteCarlo.push_back(mc_126414);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010221.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126415(1, 126415, 243090.791567/8.478871/1000*LumSys, 243091, "126415_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1", MaxCuts);
    MonteCarlo.push_back(mc_126415);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010243.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126416(1, 126416, 100687.951550/3.590892/1000*LumSys, 100688, "126416_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2", MaxCuts);
    MonteCarlo.push_back(mc_126416);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010303.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126417(1, 126417, 34955.114977/1.397496/1000*LumSys, 34955, "126417_AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3", MaxCuts);
    MonteCarlo.push_back(mc_126417);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126418.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010321.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126418(1, 126418, 582531.861248/19.230163/1000*LumSys, 582532, "126418_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0", MaxCuts);
    MonteCarlo.push_back(mc_126418);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126419.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010345.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126419(1, 126419, 248139.766991/8.474570/1000*LumSys, 248140, "126419_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1", MaxCuts);
    MonteCarlo.push_back(mc_126419);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126420.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010406_rev43815.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126420(1, 126420, 104827.842841/3.579340/1000*LumSys, 104828, "126420_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2", MaxCuts);
    MonteCarlo.push_back(mc_126420);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126421.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525010425.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126421(1, 126421, 34986.225708/1.395775/1000*LumSys, 34986, "126421_AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3", MaxCuts);
    MonteCarlo.push_back(mc_126421);
  }

  if(AlpgenPythia_P2011C_WcNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126601.AlpgenPythia_P2011C_WcNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010444.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126601(1, 126601, 6406627.483384/1153.573600/1000*LumSys, 6406625, "126601_AlpgenPythia_P2011C_WcNp0", MaxCuts);
    MonteCarlo.push_back(mc_126601);
  }

  if(AlpgenPythia_P2011C_WcNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126602.AlpgenPythia_P2011C_WcNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010559.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126602(1, 126602, 2022766.040265/416.844800/1000*LumSys, 2022766, "126602_AlpgenPythia_P2011C_WcNp1", MaxCuts);
    MonteCarlo.push_back(mc_126602);
  }

  if(AlpgenPythia_P2011C_WcNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126603.AlpgenPythia_P2011C_WcNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010641.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126603(1, 126603, 500756.885814/108.883680/1000*LumSys, 500758, "126603_AlpgenPythia_P2011C_WcNp2", MaxCuts);
    MonteCarlo.push_back(mc_126603);
  }

  if(AlpgenPythia_P2011C_WcNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126604.AlpgenPythia_P2011C_WcNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010708.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126604(1, 126604, 104333.594079/24.966000/1000*LumSys, 104334, "126604_AlpgenPythia_P2011C_WcNp3", MaxCuts);
    MonteCarlo.push_back(mc_126604);
  }

  if(AlpgenPythia_P2011C_WcNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126605.AlpgenPythia_P2011C_WcNp4.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010732.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126605(1, 126605, 18556.017697/7.215136/1000*LumSys, 18556, "126605_AlpgenPythia_P2011C_WcNp4", MaxCuts);
    MonteCarlo.push_back(mc_126605);
  }

  if(AlpgenPythia_P2011C_WccNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126606.AlpgenPythia_P2011C_WccNp0.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010750.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126606(1, 126606, 1192700.667805/162.098310/1000*LumSys, 1192702, "126606_AlpgenPythia_P2011C_WccNp0", MaxCuts);
    MonteCarlo.push_back(mc_126606);
  }

  if(AlpgenPythia_P2011C_WccNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126607.AlpgenPythia_P2011C_WccNp1.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010822.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126607(1, 126607, 930784.726689/162.789440/1000*LumSys, 930784, "126607_AlpgenPythia_P2011C_WccNp1", MaxCuts);
    MonteCarlo.push_back(mc_126607);
  }

  if(AlpgenPythia_P2011C_WccNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126608.AlpgenPythia_P2011C_WccNp2.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010848.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126608(1, 126608, 449596.489612/91.503346/1000*LumSys, 449596, "126608_AlpgenPythia_P2011C_WccNp2", MaxCuts);
    MonteCarlo.push_back(mc_126608);
  }

  if(AlpgenPythia_P2011C_WccNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126609.AlpgenPythia_P2011C_WccNp3.EndProcMark.MINI.e1477_s1499_s1504_r3658_r3549_p1400.130525010911.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126609(1, 126609, 133429.176677/40.710956/1000*LumSys, 133429, "126609_AlpgenPythia_P2011C_WccNp3", MaxCuts);
    MonteCarlo.push_back(mc_126609);
  }

  if(Sherpa_CT10_enugammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126739.Sherpa_CT10_enugammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525010931.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126739(1, 126739, 1791807.051136/163.110000/1000*LumSys, 1791806, "126739_Sherpa_CT10_enugammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_126739);
  }

  if(Sherpa_CT10_munugammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126742.Sherpa_CT10_munugammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011011.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126742(1, 126742, 1792663.750187/162.740000/1000*LumSys, 1792661, "126742_Sherpa_CT10_munugammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_126742);
  }

  if(Sherpa_CT10_tautaugammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126854.Sherpa_CT10_tautaugammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011057.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126854(1, 126854, 995497.426056/32.331000/1000*LumSys, 995498, "126854_Sherpa_CT10_tautaugammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_126854);
  }

  if(Sherpa_CT10_taunugammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126856.Sherpa_CT10_taunugammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011125.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126856(1, 126856, 1791970.075780/162.920000/1000*LumSys, 1791966, "126856_Sherpa_CT10_taunugammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_126856);
  }

  if(Sherpa_CT10_llnunu_WW){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126892.Sherpa_CT10_llnunu_WW.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011201.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126892(1, 126892, 2686680.775254/5.883930/1000*LumSys, 2686680, "126892_Sherpa_CT10_llnunu_WW", MaxCuts);
    MonteCarlo.push_back(mc_126892);
  }

  if(Sherpa_CT10_lllnu_WZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126893.Sherpa_CT10_lllnu_WZ.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011250.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126893(1, 126893, 2689255.189895/10.335848/1000*LumSys, 2689258, "126893_Sherpa_CT10_lllnu_WZ", MaxCuts);
    MonteCarlo.push_back(mc_126893);
  }

  if(Sherpa_CT10_llll_ZZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126894.Sherpa_CT10_llll_ZZ.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011340.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126894(1, 126894, 3782845.134590/9.701733/1000*LumSys, 3782845, "126894_Sherpa_CT10_llll_ZZ", MaxCuts);
    MonteCarlo.push_back(mc_126894);
  }

  if(Sherpa_CT10_llnunu_ZZ){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126895.Sherpa_CT10_llnunu_ZZ.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525011503.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126895(1, 126895, 895505.732110/0.565451/1000*LumSys, 895505, "126895_Sherpa_CT10_llnunu_ZZ", MaxCuts);
    MonteCarlo.push_back(mc_126895);
  }

  if(PowhegPythia8_AU2CT10_WpWm_ee){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126928.PowhegPythia8_AU2CT10_WpWm_ee.EndProcMark.MINI.e1280_s1469_s1470_r3752_r3549_p1400.130525011530.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126928(1, 126928, 177979.524449/0.638386/1000*LumSys, 297756, "126928_PowhegPythia8_AU2CT10_WpWm_ee", MaxCuts);
    MonteCarlo.push_back(mc_126928);
  }

  if(PowhegPythia8_AU2CT10_WpWm_me){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126929.PowhegPythia8_AU2CT10_WpWm_me.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011551.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126929(1, 126929, 178406.399168/0.638183/1000*LumSys, 298609, "126929_PowhegPythia8_AU2CT10_WpWm_me", MaxCuts);
    MonteCarlo.push_back(mc_126929);
  }

  if(PowhegPythia8_AU2CT10_WpWm_te){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126930.PowhegPythia8_AU2CT10_WpWm_te.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011613.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126930(1, 126930, 178654.584277/0.638162/1000*LumSys, 298992, "126930_PowhegPythia8_AU2CT10_WpWm_te", MaxCuts);
    MonteCarlo.push_back(mc_126930);
  }

  if(PowhegPythia8_AU2CT10_WpWm_em){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126931.PowhegPythia8_AU2CT10_WpWm_em.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011637.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126931(1, 126931, 178455.777279/0.638365/1000*LumSys, 298575, "126931_PowhegPythia8_AU2CT10_WpWm_em", MaxCuts);
    MonteCarlo.push_back(mc_126931);
  }

  if(PowhegPythia8_AU2CT10_WpWm_mm){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126932.PowhegPythia8_AU2CT10_WpWm_mm.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011700.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126932(1, 126932, 178206.459589/0.638450/1000*LumSys, 298401, "126932_PowhegPythia8_AU2CT10_WpWm_mm", MaxCuts);
    MonteCarlo.push_back(mc_126932);
  }

  if(PowhegPythia8_AU2CT10_WpWm_tm){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126933.PowhegPythia8_AU2CT10_WpWm_tm.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011724.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126933(1, 126933, 178378.575923/0.637991/1000*LumSys, 298617, "126933_PowhegPythia8_AU2CT10_WpWm_tm", MaxCuts);
    MonteCarlo.push_back(mc_126933);
  }

  if(PowhegPythia8_AU2CT10_WpWm_et){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126934.PowhegPythia8_AU2CT10_WpWm_et.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011746.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126934(1, 126934, 178350.110996/0.638182/1000*LumSys, 298745, "126934_PowhegPythia8_AU2CT10_WpWm_et", MaxCuts);
    MonteCarlo.push_back(mc_126934);
  }

  if(PowhegPythia8_AU2CT10_WpWm_mt){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126935.PowhegPythia8_AU2CT10_WpWm_mt.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011810.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126935(1, 126935, 178735.779734/0.638344/1000*LumSys, 299036, "126935_PowhegPythia8_AU2CT10_WpWm_mt", MaxCuts);
    MonteCarlo.push_back(mc_126935);
  }

  if(PowhegPythia8_AU2CT10_WpWm_tt){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126936.PowhegPythia8_AU2CT10_WpWm_tt.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011833.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126936(1, 126936, 178666.916324/0.638226/1000*LumSys, 298985, "126936_PowhegPythia8_AU2CT10_WpWm_tt", MaxCuts);
    MonteCarlo.push_back(mc_126936);
  }

  if(PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525011900.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126937(1, 126937, 1094728.773692/0.069778/1000*LumSys, 1094729, "126937_PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126937);
  }

  if(PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3752_r3549_p1400.130525012030.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126938(1, 126938, 1591680.263231/0.145390/1000*LumSys, 1591681, "126938_PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126938);
  }

  if(PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525012158.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126939(1, 126939, 596968.722533/0.102140/1000*LumSys, 596969, "126939_PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126939);
  }

  if(PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3752_r3549_p1400.130525012243.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126940(1, 126940, 1094879.605846/0.070067/1000*LumSys, 1094879, "126940_PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126940);
  }

  if(PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3752_r3549_p1400.130525012357.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126941(1, 126941, 597591.496234/0.103010/1000*LumSys, 597590, "126941_PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126941);
  }

  if(PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525012443.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126942(1, 126942, 299055.605359/0.008149/1000*LumSys, 299055, "126942_PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5", MaxCuts);
    MonteCarlo.push_back(mc_126942);
  }

  if(PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4.EndProcMark.MINI.e1280_s1469_s1470_r3752_r3549_p1400.130525012505.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126949(1, 126949, 299178.886870/0.054310/1000*LumSys, 299180, "126949_PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4", MaxCuts);
    MonteCarlo.push_back(mc_126949);
  }

  if(PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525012530.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126950(1, 126950, 299038.600874/0.054310/1000*LumSys, 299038, "126950_PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4", MaxCuts);
    MonteCarlo.push_back(mc_126950);
  }

  if(PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.EndProcMark.MINI.e1280_s1469_s1470_r3542_r3549_p1400.130525012555.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_126951(1, 126951, 298851.584184/0.054310/1000*LumSys, 298851, "126951_PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4", MaxCuts);
    MonteCarlo.push_back(mc_126951);
  }

  if(Pythia8_AU2CTEQ6L1_perf_JF17){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129160.Pythia8_AU2CTEQ6L1_perf_JF17.EndProcMark.MINI.e1130_s1472_s1473_r3542_r3549_p1400.130526125444.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129160(1, 129160, 995279.009284/93074955.000000/1000*LumSys, 995278, "129160_Pythia8_AU2CTEQ6L1_perf_JF17", MaxCuts);
    MonteCarlo.push_back(mc_129160);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129820.AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012646.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129820(1, 129820, 119752.428833/0.027036/1000*LumSys, 119752, "129820_AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp0", MaxCuts);
    MonteCarlo.push_back(mc_129820);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129821.AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012705.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129821(1, 129821, 119376.115246/0.021605/1000*LumSys, 119376, "129821_AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp1", MaxCuts);
    MonteCarlo.push_back(mc_129821);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129822.AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012725.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129822(1, 129822, 119674.153353/0.013953/1000*LumSys, 119675, "129822_AlpgenJimmy_AUET2_CTEQ6L1_WenugammagammaNp2", MaxCuts);
    MonteCarlo.push_back(mc_129822);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129823.AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012744.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129823(1, 129823, 119253.523127/0.026986/1000*LumSys, 119254, "129823_AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp0", MaxCuts);
    MonteCarlo.push_back(mc_129823);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129824.AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012803.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129824(1, 129824, 119616.677051/0.021595/1000*LumSys, 119616, "129824_AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp1", MaxCuts);
    MonteCarlo.push_back(mc_129824);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129825.AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012823.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129825(1, 129825, 119510.592977/0.013910/1000*LumSys, 119511, "129825_AlpgenJimmy_AUET2_CTEQ6L1_WmunugammagammaNp2", MaxCuts);
    MonteCarlo.push_back(mc_129825);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129826.AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012841.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129826(1, 129826, 119548.754467/0.026971/1000*LumSys, 119548, "129826_AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp0", MaxCuts);
    MonteCarlo.push_back(mc_129826);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129827.AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012859.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129827(1, 129827, 119202.861636/0.021552/1000*LumSys, 119203, "129827_AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp1", MaxCuts);
    MonteCarlo.push_back(mc_129827);
  }

  if(AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.129828.AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525012919.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_129828(1, 129828, 119437.972610/0.013965/1000*LumSys, 119438, "129828_AlpgenJimmy_AUET2_CTEQ6L1_WtaunugammagammaNp2", MaxCuts);
    MonteCarlo.push_back(mc_129828);
  }

  if(Sherpa_CT10_eegammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.145161.Sherpa_CT10_eegammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525012946.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_145161(1, 145161, 1186476.486792/32.295000/1000*LumSys, 1186480, "145161_Sherpa_CT10_eegammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_145161);
  }

  if(Sherpa_CT10_mumugammaPt10){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.145162.Sherpa_CT10_mumugammaPt10.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525013015.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_145162(1, 145162, 1195089.495743/32.323000/1000*LumSys, 1195089, "145162_Sherpa_CT10_mumugammaPt10", MaxCuts);
    MonteCarlo.push_back(mc_145162);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146430.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp0.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013046.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146430(1, 146430, 49908.137734/230.200000/1000*LumSys, 49908, "146430_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp0", MaxCuts);
    MonteCarlo.push_back(mc_146430);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146431.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp1.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013104.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146431(1, 146431, 49748.478607/59.213000/1000*LumSys, 49748, "146431_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp1", MaxCuts);
    MonteCarlo.push_back(mc_146431);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146432.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp2.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013123.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146432(1, 146432, 49858.287746/21.506000/1000*LumSys, 49858, "146432_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp2", MaxCuts);
    MonteCarlo.push_back(mc_146432);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146433.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp3.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013141.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146433(1, 146433, 49848.573204/7.106500/1000*LumSys, 49849, "146433_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp3", MaxCuts);
    MonteCarlo.push_back(mc_146433);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146434.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp4.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013159.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146434(1, 146434, 363226.149728/2.121900/1000*LumSys, 363226, "146434_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp4", MaxCuts);
    MonteCarlo.push_back(mc_146434);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_WgammaNp5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146435.AlpgenJimmy_AUET2CTEQ6L1_WgammaNp5.EndProcMark.MINI.e1601_s1499_s1504_r3658_r3549_p1400.130525013220.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146435(1, 146435, 59895.953259/0.465630/1000*LumSys, 59896, "146435_AlpgenJimmy_AUET2CTEQ6L1_WgammaNp5", MaxCuts);
    MonteCarlo.push_back(mc_146435);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013237.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146830(1, 146830, 996017.650048/4156.090500/1000*LumSys, 996019, "146830_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146830);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013306.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146831(1, 146831, 299055.769226/130.111600/1000*LumSys, 299055, "146831_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146831);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013327.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146832(1, 146832, 467962.185028/62.917945/1000*LumSys, 467962, "146832_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146832);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013353.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146833(1, 146833, 143504.383838/13.514255/1000*LumSys, 143504, "146833_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146833);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013416.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146834(1, 146834, 38552.106604/3.076288/1000*LumSys, 38552, "146834_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146834);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146835.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013434_rev43819.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146835(1, 146835, 78968.096373/0.827071/1000*LumSys, 78968, "146835_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146835);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146840.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013453.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146840(1, 146840, 995793.234686/4155.971000/1000*LumSys, 995793, "146840_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146840);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146841.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013522.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146841(1, 146841, 298795.942457/129.812850/1000*LumSys, 298796, "146841_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146841);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146842.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130526125952.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146842(1, 146842, 467397.714620/62.946625/1000*LumSys, 467399, "146842_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146842);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146843.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013608_rev43821.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146843(1, 146843, 143255.157693/13.483185/1000*LumSys, 143255, "146843_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146843);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146844.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013629_rev43843.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146844(1, 146844, 37159.717082/3.069955/1000*LumSys, 37160, "146844_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146844);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146845.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013647.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146845(1, 146845, 79079.306640/0.829748/1000*LumSys, 79080, "146845_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146845);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146850.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013713.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146850(1, 146850, 995741.418225/4156.329500/1000*LumSys, 995741, "146850_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146850);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146851.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013747.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146851(1, 146851, 298363.071581/130.075750/1000*LumSys, 298363, "146851_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146851);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146852.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013808.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146852(1, 146852, 467893.960687/63.068515/1000*LumSys, 467894, "146852_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146852);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146853.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013830.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146853(1, 146853, 144082.530565/13.497525/1000*LumSys, 144083, "146853_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146853);
  }

  if(AlpgenJimmy_Auto_AUET3CTEQ6L1_ZtautauNp4Excl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146854.AlpgenJimmy_Auto_AUET3CTEQ6L1_ZtautauNp4Excl_Mll10to60.EndProcMark.MINI.e1551_s1499_s1504_r3658_r3549_p1400.130525013850.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146854(1, 146854, 218474.168295/3.094931/1000*LumSys, 218474, "146854_AlpgenJimmy_Auto_AUET3CTEQ6L1_ZtautauNp4Excl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146854);
  }

  if(AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.146855.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60.EndProcMark.MINI.e1600_s1499_s1504_r3658_r3549_p1400.130525013911.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_146855(1, 146855, 119372.390014/0.828099/1000*LumSys, 119373, "146855_AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60", MaxCuts);
    MonteCarlo.push_back(mc_146855);
  }

  if(Sherpa_CT10_Zee){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147770.Sherpa_CT10_Zee.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525013952.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147770(1, 147770, 24700917054841.300781/1241.618400/1000*LumSys, 9958655, "147770_Sherpa_CT10_Zee", MaxCuts);
    MonteCarlo.push_back(mc_147770);
  }

  if(Sherpa_CT10_Zmumu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147771.Sherpa_CT10_Zmumu.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525014211.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147771(1, 147771, 23443593610449.281250/1241.515600/1000*LumSys, 9955520, "147771_Sherpa_CT10_Zmumu", MaxCuts);
    MonteCarlo.push_back(mc_147771);
  }

  if(Sherpa_CT10_Ztautau){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147772.Sherpa_CT10_Ztautau.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525014438.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147772(1, 147772, 10522334985244.869141/1240.693200/1000*LumSys, 4977822, "147772_Sherpa_CT10_Ztautau", MaxCuts);
    MonteCarlo.push_back(mc_147772);
  }

  if(Sherpa_CT10_Znunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147773.Sherpa_CT10_Znunu.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525014614.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147773(1, 147773, 54043069946667.390625/6702.971200/1000*LumSys, 4977777, "147773_Sherpa_CT10_Znunu", MaxCuts);
    MonteCarlo.push_back(mc_147773);
  }

  if(Sherpa_CT10_Wenu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147774.Sherpa_CT10_Wenu.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525014747.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147774(1, 147774, 433493501275846.687500/12086.707600/1000*LumSys, 11252196, "147774_Sherpa_CT10_Wenu", MaxCuts);
    MonteCarlo.push_back(mc_147774);
  }

  if(Sherpa_CT10_Wmunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147775.Sherpa_CT10_Wmunu.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525015653.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147775(1, 147775, 396943324766387.750000/12086.539500/1000*LumSys, 16599808, "147775_Sherpa_CT10_Wmunu", MaxCuts);
    MonteCarlo.push_back(mc_147775);
  }

  if(Sherpa_CT10_Wtaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147776.Sherpa_CT10_Wtaunu.EndProcMark.MINI.e1434_s1499_s1504_r3658_r3549_p1400.130525020615.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147776(1, 147776, 181169768685102.625000/12086.859400/1000*LumSys, 6973029, "147776_Sherpa_CT10_Wtaunu", MaxCuts);
    MonteCarlo.push_back(mc_147776);
  }

  if(PowhegPythia8_AU2CT10_Wplusenu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147800.PowhegPythia8_AU2CT10_Wplusenu.EndProcMark.MINI.e1169_a159_a165_r3549_p1400.130525020820.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147800(1, 147800, 23400955.440530/6891.000000/1000*LumSys, 23400956, "147800_PowhegPythia8_AU2CT10_Wplusenu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_147800);
  }

  if(PowhegPythia8_AU2CT10_Wplusmunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147801.PowhegPythia8_AU2CT10_Wplusmunu.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130525021618.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147801(1, 147801, 22832281.599988/6891.000000/1000*LumSys, 22832288, "147801_PowhegPythia8_AU2CT10_Wplusmunu", MaxCuts);
    MonteCarlo.push_back(mc_147801);
  }

  if(PowhegPythia8_AU2CT10_Wplustaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147802.PowhegPythia8_AU2CT10_Wplustaunu.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130525022210.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147802(1, 147802, 3980310.432588/6889.800000/1000*LumSys, 3980312, "147802_PowhegPythia8_AU2CT10_Wplustaunu", MaxCuts);
    MonteCarlo.push_back(mc_147802);
  }

  if(PowhegPythia8_AU2CT10_Wminenu_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147803.PowhegPythia8_AU2CT10_Wminenu.EndProcMark.MINI.e1169_a159_a165_r3549_p1400.130525022312.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147803(1, 147803, 13555830.548401/4790.200000/1000*LumSys, 13555826, "147803_PowhegPythia8_AU2CT10_Wminenu_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_147803);
  }

  if(PowhegPythia8_AU2CT10_Wminmunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147804.PowhegPythia8_AU2CT10_Wminmunu.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130525022921_1_rev43571.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147804(1, 147804, 11781064.368209/4790.200000/1000*LumSys, 11781059, "147804_PowhegPythia8_AU2CT10_Wminmunu", MaxCuts);
    MonteCarlo.push_back(mc_147804);
  }

  if(PowhegPythia8_AU2CT10_Wmintaunu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147805.PowhegPythia8_AU2CT10_Wmintaunu.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130526130826.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147805(1, 147805, 2982827.882849/4790.900000/1000*LumSys, 2982829, "147805_PowhegPythia8_AU2CT10_Wmintaunu", MaxCuts);
    MonteCarlo.push_back(mc_147805);
  }

  if(PowhegPythia8_AU2CT10_Zee_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147806.PowhegPythia8_AU2CT10_Zee.EndProcMark.MINI.e1169_a159_a165_r3549_p1400.130525023443_1_rev43593.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147806(1, 147806, 12002959.633515/1109.900000/1000*LumSys, 12002953, "147806_PowhegPythia8_AU2CT10_Zee_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_147806);
  }

  if(PowhegPythia8_AU2CT10_Zmumu){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147807.PowhegPythia8_AU2CT10_Zmumu.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130525024152.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147807(1, 147807, 5641392.629087/1109.800000/1000*LumSys, 5641396, "147807_PowhegPythia8_AU2CT10_Zmumu", MaxCuts);
    MonteCarlo.push_back(mc_147807);
  }

  if(PowhegPythia8_AU2CT10_Ztautau){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147808.PowhegPythia8_AU2CT10_Ztautau.EndProcMark.MINI.e1169_s1469_s1470_r3542_r3549_p1400.130525024458_rev43589.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147808(1, 147808, 4978189.142191/1109.900000/1000*LumSys, 4978190, "147808_PowhegPythia8_AU2CT10_Ztautau", MaxCuts);
    MonteCarlo.push_back(mc_147808);
  }

  if(Pythia8_AU2CT10_jetjet_JZ0){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147900.Pythia8_AU2CT10_jetjet_JZ0.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024624_rev43605.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147900(1, 147900, 995950.653224/71790032500.000000/1000*LumSys, 995950, "147900_Pythia8_AU2CT10_jetjet_JZ0", MaxCuts);
    MonteCarlo.push_back(mc_147900);
  }

  if(Pythia8_AU2CT10_jetjet_JZ1){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147901.Pythia8_AU2CT10_jetjet_JZ1.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024650.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147901(1, 147901, 995293.911854/1053483850.000000/1000*LumSys, 995295, "147901_Pythia8_AU2CT10_jetjet_JZ1", MaxCuts);
    MonteCarlo.push_back(mc_147901);
  }

  if(Pythia8_AU2CT10_jetjet_JZ2){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147902.Pythia8_AU2CT10_jetjet_JZ2.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024723.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147902(1, 147902, 995994.681019/2836013.000000/1000*LumSys, 995998, "147902_Pythia8_AU2CT10_jetjet_JZ2", MaxCuts);
    MonteCarlo.push_back(mc_147902);
  }

  if(Pythia8_AU2CT10_jetjet_JZ3){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147903.Pythia8_AU2CT10_jetjet_JZ3.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024757.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147903(1, 147903, 995919.592031/34891.000000/1000*LumSys, 995916, "147903_Pythia8_AU2CT10_jetjet_JZ3", MaxCuts);
    MonteCarlo.push_back(mc_147903);
  }

  if(Pythia8_AU2CT10_jetjet_JZ4){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147904.Pythia8_AU2CT10_jetjet_JZ4.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024834_rev43609.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147904(1, 147904, 995116.270423/199.290000/1000*LumSys, 995115, "147904_Pythia8_AU2CT10_jetjet_JZ4", MaxCuts);
    MonteCarlo.push_back(mc_147904);
  }

  if(Pythia8_AU2CT10_jetjet_JZ5){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147905.Pythia8_AU2CT10_jetjet_JZ5.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525220807.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147905(1, 147905, 995568.109761/1.371100/1000*LumSys, 995563, "147905_Pythia8_AU2CT10_jetjet_JZ5", MaxCuts);
    MonteCarlo.push_back(mc_147905);
  }

  if(Pythia8_AU2CT10_jetjet_JZ6){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147906.Pythia8_AU2CT10_jetjet_JZ6.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525024954.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147906(1, 147906, 994296.473649/0.026164/1000*LumSys, 994298, "147906_Pythia8_AU2CT10_jetjet_JZ6", MaxCuts);
    MonteCarlo.push_back(mc_147906);
  }

  if(Pythia8_AU2CT10_jetjet_JZ7){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147907.Pythia8_AU2CT10_jetjet_JZ7.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025035.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147907(1, 147907, 994828.628304/0.000594/1000*LumSys, 994827, "147907_Pythia8_AU2CT10_jetjet_JZ7", MaxCuts);
    MonteCarlo.push_back(mc_147907);
  }

  if(Pythia8_AU2CT10_jetjet_JZ0W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147910.Pythia8_AU2CT10_jetjet_JZ0W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025114.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147910(1, 147910, 1493923.317256/71796589000.000000/1000*LumSys, 1493924, "147910_Pythia8_AU2CT10_jetjet_JZ0W", MaxCuts);
    MonteCarlo.push_back(mc_147910);
  }

  if(Pythia8_AU2CT10_jetjet_JZ1W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147911.Pythia8_AU2CT10_jetjet_JZ1W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025148.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147911(1, 147911, 166989985.741878/9396193.000000/1000*LumSys, 1494295, "147911_Pythia8_AU2CT10_jetjet_JZ1W", MaxCuts);
    MonteCarlo.push_back(mc_147911);
  }

  if(Pythia8_AU2CT10_jetjet_JZ2W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147912.Pythia8_AU2CT10_jetjet_JZ2W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025247.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147912(1, 147912, 160837551.681365/105175.000000/1000*LumSys, 5971009, "147912_Pythia8_AU2CT10_jetjet_JZ2W", MaxCuts);
    MonteCarlo.push_back(mc_147912);
  }

  if(Pythia8_AU2CT10_jetjet_JZ3W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147913.Pythia8_AU2CT10_jetjet_JZ3W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025550.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147913(1, 147913, 312809847.927550/664.990000/1000*LumSys, 5971781, "147913_Pythia8_AU2CT10_jetjet_JZ3W", MaxCuts);
    MonteCarlo.push_back(mc_147913);
  }

  if(Pythia8_AU2CT10_jetjet_JZ4W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147914.Pythia8_AU2CT10_jetjet_JZ4W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525025859_rev43581.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147914(1, 147914, 259380473.303046/4.565800/1000*LumSys, 5965100, "147914_Pythia8_AU2CT10_jetjet_JZ4W", MaxCuts);
    MonteCarlo.push_back(mc_147914);
  }

  if(Pythia8_AU2CT10_jetjet_JZ5W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147915.Pythia8_AU2CT10_jetjet_JZ5W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525030219.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147915(1, 147915, 48198008.481189/0.085502/1000*LumSys, 2984582, "147915_Pythia8_AU2CT10_jetjet_JZ5W", MaxCuts);
    MonteCarlo.push_back(mc_147915);
  }

  if(Pythia8_AU2CT10_jetjet_JZ6W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147916.Pythia8_AU2CT10_jetjet_JZ6W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525030404_rev43595.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147916(1, 147916, 39936094.522613/0.001946/1000*LumSys, 2981405, "147916_Pythia8_AU2CT10_jetjet_JZ6W", MaxCuts);
    MonteCarlo.push_back(mc_147916);
  }

  if(Pythia8_AU2CT10_jetjet_JZ7W){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.147917.Pythia8_AU2CT10_jetjet_JZ7W.EndProcMark.MINI.e1126_s1469_s1470_r3542_r3549_p1400.130525030544.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_147917(1, 147917, 2982635.739653/0.000593/1000*LumSys, 2982634, "147917_Pythia8_AU2CT10_jetjet_JZ7W", MaxCuts);
    MonteCarlo.push_back(mc_147917);
  }

  if(MadGraphPythia8_AU2CTEQ6L1_ttbarWW_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.158813.MadGraphPythia8_AU2CTEQ6L1_ttbarWW.EndProcMark.MINI.e1632_a159_a171_r3549_p1400.130525030730_rev43599.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_158813(1, 158813, 198573.585008/0.001797/1000*LumSys, 198574, "158813_MadGraphPythia8_AU2CTEQ6L1_ttbarWW_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_158813);
  }

  if(MadgraphPythia8_AU2_MSTW2008LO_ttbarWW_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.158814.MadgraphPythia8_AU2_MSTW2008LO_ttbarWW.EndProcMark.MINI.e1632_a159_a171_r3549_p1400.130525030756.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_158814(1, 158814, 199262.759285/0.002180/1000*LumSys, 199262, "158814_MadgraphPythia8_AU2_MSTW2008LO_ttbarWW_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_158814);
  }

  if(MadGraphPythia8_AU2CTEQ6L1_SSWWjj_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.158818.MadGraphPythia8_AU2CTEQ6L1_SSWWjj.EndProcMark.MINI.e1632_a159_a171_r3549_p1400.130525030819.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_158818(1, 158818, 189285.155325/0.344420/1000*LumSys, 189285, "158818_MadGraphPythia8_AU2CTEQ6L1_SSWWjj_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_158818);
  }

  if(MadgraphPythia8_AU2_MSTW2008LO_SSWWjj_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.158819.MadgraphPythia8_AU2_MSTW2008LO_SSWWjj.EndProcMark.MINI.e1632_a159_a171_r3549_p1400.130525030840.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_158819(1, 158819, 194083.255301/0.369360/1000*LumSys, 194085, "158819_MadgraphPythia8_AU2_MSTW2008LO_SSWWjj_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_158819);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_gamgam){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.160069.Pythia8_AU2CTEQ6L1_ttH125_gamgam.EndProcMark.MINI.e1189_s1469_s1470_r3542_r3549_p1400.130524203548.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_160069(1, 160069, 300403.872773/0.000297/1000*LumSys, 298606, "160069_Pythia8_AU2CTEQ6L1_ttH125_gamgam", MaxCuts);
    MonteCarlo.push_back(mc_160069);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_WWinclusive){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive.EndProcMark.MINI.e1530_s1499_s1504_r3658_r3549_p1400.130524203637.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161305(1, 161305, 195393.987697/0.027993/1000*LumSys, 194151, "161305_Pythia8_AU2CTEQ6L1_ttH125_WWinclusive", MaxCuts);
    MonteCarlo.push_back(mc_161305);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_tautaull){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.161708.Pythia8_AU2CTEQ6L1_ttH125_tautaull.EndProcMark.MINI.e1530_s1499_s1504_r3658_r3549_p1400.130524203721.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161708(1, 161708, 30201.389766/0.001020/1000*LumSys, 29976, "161708_Pythia8_AU2CTEQ6L1_ttH125_tautaull", MaxCuts);
    MonteCarlo.push_back(mc_161708);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_tautaulh){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.161719.Pythia8_AU2CTEQ6L1_ttH125_tautaulh.EndProcMark.MINI.e1530_s1499_s1504_r3658_r3549_p1400.130524203745.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161719(1, 161719, 30207.287250/0.003752/1000*LumSys, 29923, "161719_Pythia8_AU2CTEQ6L1_ttH125_tautaulh", MaxCuts);
    MonteCarlo.push_back(mc_161719);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_tautauhh){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.161730.Pythia8_AU2CTEQ6L1_ttH125_tautauhh.EndProcMark.MINI.e1530_s1499_s1504_r3658_r3549_p1400.130524203803.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161730(1, 161730, 30127.660995/0.003456/1000*LumSys, 29935, "161730_Pythia8_AU2CTEQ6L1_ttH125_tautauhh", MaxCuts);
    MonteCarlo.push_back(mc_161730);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.161871.Pythia8_AU2CTEQ6L1_ttH125_dilepbb.EndProcMark.MINI.e1441_a159_a171_r3549_p1400.130524203823.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_161871(1, 161871, 1503045.440153/0.007884/1000*LumSys, 1493665, "161871_Pythia8_AU2CTEQ6L1_ttH125_dilepbb_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_161871);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164440.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525030901.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164440(1, 164440, 813344.862210/7.831599/1000*LumSys, 813345, "164440_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp0_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164440);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164441.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525171842.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164441(1, 164441, 834777.387864/8.281112/1000*LumSys, 834777, "164441_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp1_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164441);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164442.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525031118_rev43587.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164442(1, 164442, 585832.621145/5.322428/1000*LumSys, 585831, "164442_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp2_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164442);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164443.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525031244.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164443(1, 164443, 384139.426344/3.555257/1000*LumSys, 384138, "164443_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnlnNp3p_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164443);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp0_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164450.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp0_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525031353.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164450(1, 164450, 3398491.194809/32.666486/1000*LumSys, 3398487, "164450_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp0_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164450);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp1_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164451.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp1_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525031549.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164451(1, 164451, 3517805.532312/34.530176/1000*LumSys, 3517811, "164451_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp1_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164451);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp2_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164452.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp2_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525032425.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164452(1, 164452, 2456310.930241/22.270670/1000*LumSys, 2456308, "164452_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp2_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164452);
  }

  if(AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp3p_baseline_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.164453.AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp3p_baseline.EndProcMark.MINI.e1527_a159_a171_r3549_p1400.130525033223.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_164453(1, 164453, 1553505.135729/14.794124/1000*LumSys, 1553509, "164453_AlpgenJimmy_AUET2CTEQ6L1_ttbarlnqqNp3p_baseline_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_164453);
  }

  if(Sherpa_CT10_WenuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167740.Sherpa_CT10_WenuMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525033828.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167740(1, 167740, 2583182.800422/140.340000/1000*LumSys, 8885805, "167740_Sherpa_CT10_WenuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167740);
  }

  if(Sherpa_CT10_WenuMassiveCBPt0_CJetFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167741.Sherpa_CT10_WenuMassiveCBPt0_CJetFilterBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525034517.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167741(1, 167741, 3037155.335922/537.840000/1000*LumSys, 9959944, "167741_Sherpa_CT10_WenuMassiveCBPt0_CJetFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167741);
  }

  if(Sherpa_CT10_WenuMassiveCBPt0_CJetVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167742.Sherpa_CT10_WenuMassiveCBPt0_CJetVetoBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525034855.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167742(1, 167742, 5210939.298454/10298.000000/1000*LumSys, 9286359, "167742_Sherpa_CT10_WenuMassiveCBPt0_CJetVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167742);
  }

  if(Sherpa_CT10_WmunuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167743.Sherpa_CT10_WmunuMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525035305.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167743(1, 167743, 2403369.893801/140.390000/1000*LumSys, 8272584, "167743_Sherpa_CT10_WmunuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167743);
  }

  if(Sherpa_CT10_WmunuMassiveCBPt0_CJetFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167744.Sherpa_CT10_WmunuMassiveCBPt0_CJetFilterBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525035643.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167744(1, 167744, 2864221.829548/466.470000/1000*LumSys, 9953212, "167744_Sherpa_CT10_WmunuMassiveCBPt0_CJetFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167744);
  }

  if(Sherpa_CT10_WmunuMassiveCBPt0_CJetVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167745.Sherpa_CT10_WmunuMassiveCBPt0_CJetVetoBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525035929.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167745(1, 167745, 2902923.831326/10367.000000/1000*LumSys, 5179725, "167745_Sherpa_CT10_WmunuMassiveCBPt0_CJetVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167745);
  }

  if(Sherpa_CT10_WtaunuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167746.Sherpa_CT10_WtaunuMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525040253.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167746(1, 167746, 2337753.622673/140.340000/1000*LumSys, 8040313, "167746_Sherpa_CT10_WtaunuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167746);
  }

  if(Sherpa_CT10_WtaunuMassiveCBPt0_CJetFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167747.Sherpa_CT10_WtaunuMassiveCBPt0_CJetFilterBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525040730.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167747(1, 167747, 2960884.763363/505.450000/1000*LumSys, 9956722, "167747_Sherpa_CT10_WtaunuMassiveCBPt0_CJetFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167747);
  }

  if(Sherpa_CT10_WtaunuMassiveCBPt0_CJetVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167748.Sherpa_CT10_WtaunuMassiveCBPt0_CJetVetoBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041003.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167748(1, 167748, 5847309.683574/10326.000000/1000*LumSys, 10427152, "167748_Sherpa_CT10_WtaunuMassiveCBPt0_CJetVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167748);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041338.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167749(1, 167749, 1092839.551334/31.046000/1000*LumSys, 3983269, "167749_Sherpa_CT10_ZeeMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167749);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041448.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167750(1, 167750, 1434053.498619/314.260000/1000*LumSys, 2987081, "167750_Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167750);
  }

  if(Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041539.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167751(1, 167751, 566662.131475/763.050000/1000*LumSys, 996864, "167751_Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167751);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041613.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167752(1, 167752, 1091279.698434/31.036000/1000*LumSys, 3979397, "167752_Sherpa_CT10_ZmumuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167752);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041713.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167753(1, 167753, 1434221.141555/314.800000/1000*LumSys, 2986045, "167753_Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167753);
  }

  if(Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041822.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167754(1, 167754, 565854.906717/764.010000/1000*LumSys, 996153, "167754_Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167754);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525041852.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167755(1, 167755, 1091671.486613/31.008000/1000*LumSys, 3981757, "167755_Sherpa_CT10_ZtautauMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167755);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto.EndProcMark.MINI.e1587_a159_a171_r3549_p1400.130525042012.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167756(1, 167756, 1433128.688599/314.490000/1000*LumSys, 2985445, "167756_Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167756);
  }

  if(Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto.EndProcMark.MINI.e1587_a159_a171_r3549_p1400.130525042059.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167757(1, 167757, 565839.076987/764.690000/1000*LumSys, 994806, "167757_Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167757);
  }

  if(Sherpa_CT10_ZnunuMassiveCBPt0_BFilter_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167758.Sherpa_CT10_ZnunuMassiveCBPt0_BFilter.EndProcMark.MINI.e1585_a159_a171_r3549_p1400.130525042137.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167758(1, 167758, 1193571.607358/176.020000/1000*LumSys, 4379576, "167758_Sherpa_CT10_ZnunuMassiveCBPt0_BFilter_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167758);
  }

  if(Sherpa_CT10_ZnunuMassiveCBPt0_CFilterBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167759.Sherpa_CT10_ZnunuMassiveCBPt0_CFilterBVeto.EndProcMark.MINI.e1587_a159_a171_r3549_p1400.130525042830.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167759(1, 167759, 3618482.289032/1677.600000/1000*LumSys, 7624085, "167759_Sherpa_CT10_ZnunuMassiveCBPt0_CFilterBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167759);
  }

  if(Sherpa_CT10_ZnunuMassiveCBPt0_CVetoBVeto_atlasfast){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.167760.Sherpa_CT10_ZnunuMassiveCBPt0_CVetoBVeto.EndProcMark.MINI.e1587_a159_a171_r3549_p1400.130525043258.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_167760(1, 167760, 3323640.955085/4136.200000/1000*LumSys, 5915716, "167760_Sherpa_CT10_ZnunuMassiveCBPt0_CVetoBVeto_atlasfast", MaxCuts);
    MonteCarlo.push_back(mc_167760);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_gg){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.169070.Pythia8_AU2CTEQ6L1_ttH125_gg.EndProcMark.MINI.e1685_s1581_s1586_r3658_r3549_p1400.130524204105.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169070(1, 169070, 100268.124111/0.011158/1000*LumSys, 99687, "169070_Pythia8_AU2CTEQ6L1_ttH125_gg", MaxCuts);
    MonteCarlo.push_back(mc_169070);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_cc){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.169071.Pythia8_AU2CTEQ6L1_ttH125_cc.EndProcMark.MINI.e1685_s1581_s1586_r3658_r3549_p1400.130524204128.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169071(1, 169071, 100228.845057/0.003789/1000*LumSys, 99622, "169071_Pythia8_AU2CTEQ6L1_ttH125_cc", MaxCuts);
    MonteCarlo.push_back(mc_169071);
  }

  if(Pythia8_AU2CTEQ6L1_ttH125_ZZinclusive){
    ifstream in;
    in.open("/Users/antonioonofre/ATLAS/analises/LipTool/NewMiniNtuples/Make_MC_Define_Samples/input_txt_newMiniNtuples_TRCR-14-00-03_FCNCqzl.dir//user.galhardo.21.mc12_8TeV.169072.Pythia8_AU2CTEQ6L1_ttH125_ZZinclusive.EndProcMark.MINI.e1685_s1581_s1586_r3658_r3549_p1400.130524204148.txt");
    while (1) {
      std::string rootfile;
      in >> rootfile; if (!in.good()) break;
      Input.File(ntu, rootfile);
    }
    in.close();
    TMonteCarlo mc_169072(1, 169072, 100353.322678/0.003437/1000*LumSys, 99708, "169072_Pythia8_AU2CTEQ6L1_ttH125_ZZinclusive", MaxCuts);
    MonteCarlo.push_back(mc_169072);
  }

