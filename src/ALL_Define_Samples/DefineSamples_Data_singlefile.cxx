if (isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Data (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  if(alldata_ele){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    DefineSamples_Data_TRCR-14-00-14_7B.cxx " << endl;
	Input.File(ntu, "/lstore/atlas/ttHMini/TRC-14-00-14/data12/Egamma/user.guindon.data12_8TeV.periodA.physics_Egamma.PhysCont.NTUP_TOPEL.grp15_v01_p1400_p1401v141.v1.130822142255.merge/user.guindon.004896._00032.merge.ML_7B.root");
	// input TMonteCarlo file from Egamma stream
        cout << " Runs List:  /home/local/atlas/ssantos/analysis/LipTool-8TeV-TRC-14-00-14/LipTool/Links/NewData_ttHMiniMls_8TeV/NewData_singlefile_Make-TMonteCarlo.txt" << endl;
	#include "/home/local/atlas/ssantos/analysis/LipTool-8TeV-TRC-14-00-14/LipTool/Links/NewData_ttHMiniMls_8TeV/NewData_singlefile_Make-TMonteCarlo.txt"
  }

  if(alldata_muo){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    DefineSamples_Data_TRCR-14-00-14_7B.cxx " << endl;
	Input.File(ntu, "/lstore/atlas/ttHMini/TRC-14-00-14/data12/Egamma/user.guindon.data12_8TeV.periodA.physics_Egamma.PhysCont.NTUP_TOPEL.grp15_v01_p1400_p1401v141.v1.130822142255.merge/user.guindon.004896._00032.merge.ML_7B.root");
	// input TMonteCarlo file from Egamma stream
        cout << " Runs List:  /home/local/atlas/ssantos/analysis/LipTool-8TeV-TRC-14-00-14/LipTool/Links/NewData_ttHMiniMls_8TeV/NewData_singlefile_Make-TMonteCarlo.txt" << endl;
	#include "/home/local/atlas/ssantos/analysis/LipTool-8TeV-TRC-14-00-14/LipTool/Links/NewData_ttHMiniMls_8TeV/NewData_singlefile_Make-TMonteCarlo.txt"
  }

}
