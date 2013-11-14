if (isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Data (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  if(alldata_ele){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_Bruno_7TeV.cxx " << endl;
	Input.File(ntu, "../Links/NewData_Bruno_7TeV/NewData_Egamma_7TeV.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_Bruno_7TeV/NewData_Egamma_7TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_Bruno_7TeV/NewData_Egamma_7TeV_Make-TMonteCarlo.txt"
  }

  if(alldata_muo){
	// input data root files from Muon stream
        cout << " Define Samples Selected:    newdefine_samples_data_Bruno_7TeV.cxx " << endl;
	Input.File(ntu, "../Links/NewData_Bruno_7TeV/NewData_Muons_7TeV.root");
	// input TMonteCarlo file from Muon stream
        cout << "               Runs List:    ../Links/NewData_Bruno_7TeV/NewData_Muons_7TeV_Make-TMonteCarlo.txt" << endl;
	#include "../Links/NewData_Bruno_7TeV/NewData_Muons_7TeV_Make-TMonteCarlo.txt"
  }

}
