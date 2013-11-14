if (isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Data (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  if(alldata_ele){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_JaredVasquez_combined_7F_8TeV.cxx " << endl;
	Input.File(ntu, "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F_8TeV_Make-TMonteCarlo.txt"
  }

  if(alldata_muo){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_JaredVasquez_combined_7F_8TeV.cxx " << endl;
	Input.File(ntu, "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_JaredVasquez_combined_7F_8TeV_Make-TMonteCarlo.txt"
  }

}
