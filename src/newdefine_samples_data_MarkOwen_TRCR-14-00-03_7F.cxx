if (isData) {

  cout <<      "\n   ATLAS LIP Mini (8TeV) ttH (dilep) Analysis" << endl;
  cout <<      "\n   Mini TopTools Data (MiniTTHReader)"<< std::endl;
  const char *  ntu = "MiniTTHReader";

  if(alldata_ele){
	// input data root files from Egamma stream
        cout << " Define Samples Selected:    newdefine_samples_data_MarkOwen_TRCR-14-00-03_7F.cxx " << endl;
	Input.File(ntu, "../../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Egamma_8TeV.root");
	// input TMonteCarlo file from Egamma stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Egamma_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Egamma_8TeV_Make-TMonteCarlo.txt"
  }

  if(alldata_muo){
	// input data root files from Muon stream
        cout << " Define Samples Selected:    newdefine_samples_data_MarkOwen_TRCR-14-00-03_7F.cxx " << endl;
	Input.File(ntu, "../../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Muons_8TeV.root");
	// input TMonteCarlo file from Muon stream
        cout << "               Runs List:    ../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Muons_8TeV_Make-TMonteCarlo.txt" << endl;
	#include "../../Links/NewData_MC_MarkOwen_8TeV_TRCR14-00-03/NewData_Muons_8TeV_Make-TMonteCarlo.txt"
  }

}
