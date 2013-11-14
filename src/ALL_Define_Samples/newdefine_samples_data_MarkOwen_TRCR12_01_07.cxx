if (isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Data (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  if(alldata_ele){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_MarkOwen_TRCR12_01_07.cxx " << endl;
	Input.File(ntu, "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Egamma_8TeV.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Egamma_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Egamma_8TeV_Make-TMonteCarlo.txt"
  }

/*
  if(alldata_muo){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_MarkOwen_TRCR12_01_07.cxx " << endl;
	Input.File(ntu, "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Muons_8TeV.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Muons_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_MC_MarkOwen_8TeV_TRCR12_01_07/NewData_Muons_8TeV_Make-TMonteCarlo.txt"
  }
*/

  if(alldata_muo){
        // input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_MarkOwen_TRCR12_01_07.cxx BUT USING newdefine_samples_data_MarkOwen.cxx for muons" << endl;
        Input.File(ntu, "../Links/NewData_MC_MarkOwen_8TeV/NewData_Muons_8TeV.root");
        // input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV/NewData_Muons_8TeV_Make-TMonteCarlo.txt" << endl;
        #include "../Links/NewData_MC_MarkOwen_8TeV/NewData_Muons_8TeV_Make-TMonteCarlo.txt"
  }

}
