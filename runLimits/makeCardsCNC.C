#include <iostream>   
#include <algorithm>  
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include "TColor.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include <stdio.h>
#include <stdlib.h>



#include "../signalRegionDefinitions.h"
#include "../backgroundPrediction_CNC_SignalContamination.C"
#include "../backgroundPrediction.h"

using namespace std;



void makeCLsCards(TString decay_mode, TString SignalRegion, int MSTOP, int MLSP){


          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();


          TFile sig("ntp_8/"+decay_mode+".root");

          TH1D* signal= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalBVetoBCUp= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"BVetoBCUp_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalBVetoBCDown= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"BVetoBCDown_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalBVetoLightUp= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"BVetoLightUp_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalBVetoLightDown= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"BVetoLightDown_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalJESUp= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"JESUp_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalJESDown= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"JESDown_S"+TString(stop)+"_N"+TString(neut));
          TH1D* signalGEN = (TH1D*)sig.Get("Events_NGenSignal_S"+TString(stop)+"_N"+TString(neut));
      		
      	  TFile datafile("ntp_8/data.root");
          TH1D* datahist= (TH1D*)datafile.Get("Events_"+decay_mode+"_"+SignalRegion+"_S0_N0");

          double nsignal = signal->Integral();
          double nsignal_RAW = signal->GetEntries();
          double nsignalBVetoBCUp = signalBVetoBCUp->Integral();
          double nsignalBVetoBCDown = signalBVetoBCDown->Integral();
          double nsignalBVetoLightUp = signalBVetoLightUp->Integral();
          double nsignalBVetoLightDown = signalBVetoLightDown->Integral();
          double nsignalJESUp = signalJESUp->Integral();
          double nsignalJESDown = signalJESDown->Integral();
          double totalsignal = signalGEN->GetMean();


      	  double ndata = datahist->Integral();

	  	  double B = 0.; 
          double B_err = 0.; 
          double B_err_percentage = 0.; 

		  double Bp; 
		  double Bp_err; 



	  if (decay_mode == "T2bw025") {

		if (SignalRegion == "offShell") {
		  B = backgroundPrediction_cutAndCount_T2bw025_offShell().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw025_offShell().second ; 
		  //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
		  //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ; 
		  }

		if (SignalRegion == "lowMasses") {
		  B = backgroundPrediction_cutAndCount_T2bw025_lowMasses().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw025_lowMasses().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "highMasses") {
		  B = backgroundPrediction_cutAndCount_T2bw025_highMasses().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw025_highMasses().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

	  }



	  else if (decay_mode == "T2bw050") {

		if (SignalRegion == "offShell") {
		  B = backgroundPrediction_cutAndCount_T2bw050_offShell().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw050_offShell().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "lowMasses") {
		  B = backgroundPrediction_cutAndCount_T2bw050_lowMasses().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw050_lowMasses().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "mediumDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2bw050_mediumDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw050_mediumDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "highDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2bw050_highDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw050_highDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

	  }



	   if (decay_mode == "T2bw075") {


		if (SignalRegion == "lowDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2bw075_lowDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw075_lowDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "mediumDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2bw075_mediumDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw075_mediumDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "highDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2bw075_highDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2bw075_highDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

	  }



	  else if (decay_mode == "T2tt") {

		if (SignalRegion == "offShellLoose") {
		  B = backgroundPrediction_cutAndCount_T2tt_offShellLoose().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2tt_offShellLoose().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "offShellTight") {
		  B = backgroundPrediction_cutAndCount_T2tt_offShellTight().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2tt_offShellTight().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "lowDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2tt_lowDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2tt_lowDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "mediumDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2tt_mediumDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2tt_mediumDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

		if (SignalRegion == "highDeltaM") {
		  B = backgroundPrediction_cutAndCount_T2tt_highDeltaM().first  ; 
		  B_err = backgroundPrediction_cutAndCount_T2tt_highDeltaM().second ; 
          //Bp = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).first  ; 
          //Bp_err = backgroundPrediction_CNC_SignalContamination(decay_mode,SignalRegion,MSTOP,MLSP).second ;
		  }

	  }





          double JESUp = 100 * fabs((nsignal - nsignalJESUp ))/nsignal;
          double JESDown = 100 * fabs((nsignal - nsignalJESDown ))/nsignal;
          double JEStot =  (JESUp + JESDown)/ 2.;
          double BVetoBCUp = 100 * fabs((nsignal - nsignalBVetoBCUp ))/nsignal;
          double BVetoBCDown = 100 * fabs((nsignal - nsignalBVetoBCDown ))/nsignal;
          double BVetoBCtot =  (BVetoBCUp + BVetoBCDown)/ 2.;
          double BVetoLightUp = 100 * fabs((nsignal - nsignalBVetoLightUp ))/nsignal;
          double BVetoLightDown = 100 * fabs((nsignal - nsignalBVetoLightDown ))/nsignal;
          double BVetoLighttot =  (BVetoLightUp + BVetoLightDown)/ 2. ;
          double BVetoBCtot =  (BVetoBCUp + BVetoBCDown)/ 2. ;
          double BVetotot = sqrt (BVetoBCtot*BVetoBCtot + BVetoLighttot*BVetoLighttot);

		  double stat_err_a = 1 /nsignal_RAW + 1 / totalsignal;
		  double stat_err_b = 1 /(sqrt(nsignal_RAW * totalsignal));
	      double stat_err;
		  if (stat_err_b > stat_err_a) stat_err = 100 * sqrt(stat_err_a);
			else stat_err = 100 * sqrt(stat_err_a - stat_err_b);

		  TFile PDF_err_file("PDFUncertainties/"+decay_mode+"_presel.root");
		  TH2D* PDF_err_hist= (TH2D*)PDF_err_file.Get("twodplot");
		  int max_binX = PDF_err_hist->GetXaxis()->FindBin(MSTOP);
	      int max_binY = PDF_err_hist->GetYaxis()->FindBin(MLSP);
	  	  double PDF_err = PDF_err_hist->GetBinContent(max_binX,max_binY);

		  if (PDF_err > 25.) PDF_err = 20.;
		  if (PDF_err == 0) PDF_err = 10.;
		  if (PDF_err != PDF_err) PDF_err = 10.;

          if (JEStot > 20.) JEStot = 20.;       // put upper bound on JES uncertainty
          if (BVetotot > 10.) BVetotot = 10.;     // put upper bound on JES uncertainty
          if (stat_err != stat_err) stat_err = 0.;

          double S_err = sqrt(stat_err*stat_err + BVetotot*BVetotot + JEStot*JEStot + 3*3 + 5*5 + 2.2*2.2 + PDF_err*PDF_err);
		  double sig_err_percentage = S_err/100. + 1.;
          B_err_percentage = (B_err / B) + 1. ;


		    double S_err_abs = nsignal * S_err;
			double DeltaB = Bp - B; // signal contamination factor
			double SigmaTot = sqrt(S_err_abs*S_err_abs + B_err*B_err + Bp_err*Bp_err  -  2 * B_err * Bp_err);
			double nsignal_new = nsignal + DeltaB;
				if (nsignal_new < 0) nsignal_new = 0.;

		  // No SC
          createTableCLsCNC(decay_mode, SignalRegion, MSTOP, MLSP, ndata, nsignal, sig_err_percentage, B, B_err_percentage);

		  // SC
          //createTableCLsCNC(decay_mode, SignalRegion, MSTOP, MLSP, ndata, nsignal_new, SigmaTot, B, B_err_percentage);

//      cout << "S: "<< nsignal << " +/- " << S_err_abs << endl;
//      cout << "S': "<< nsignal_new << " +/- " << SigmaTot << endl;
}





void makeCards(TString decay_mode, TString SignalRegion ){



//              for(int x=100; x<=800; x+=25){
              for(int x=125; x<=800; x+=25){ // SC doesnt start at 100

	
    	              //for(int y=0; y<=400; y+=25){  // SC doesnt end at 400
    	              for(int y=0; y<=375; y+=25){

	
				 if (x - y > 99){  
					 cout << "S:"<<x << "N"<<y<<endl;	
					 makeCLsCards(decay_mode, SignalRegion, x, y);
				 }

		  		
			}
	       }	
	   
}








void createTableCLsCNC(TString decay_mode, TString SignalRegion, int S, int N, double ndata, double signal, double signal_err_percentage, double bkg, double bkg_err_percentage){


  char datacardname[100];
  sprintf(datacardname,"datacard-S%d-N%d.txt", S,N);

  ofstream  tablesFile(datacardname);
  tablesFile.setf(ios::fixed);
  tablesFile.precision(3);

  tablesFile << "imax 1  number of channels" << endl
             << "jmax 1  number of backgrounds" << endl
             << "kmax 2  number of nuisance parameters (sources of systematical uncertainties)" << endl
             << " ------------ "<<endl
             << "bin 1"<<endl
             << "observation \t" << ndata << endl
             << "bin                    \t\t 1              \t 1                " << endl
             << "process                \t\t signal         \t bkg              " << endl
             << "process                \t\t 0              \t 1                " << endl
             << "rate                   \t\t " << signal << "  \t \t "<< bkg << endl
             << " ------------ " << endl
             << "signal_unc \t lnN      \t "<< signal_err_percentage << " \t -        \t   Total uncertainty on the signal" << endl
             << "bkg_unc    \t lnN      \t -             \t\t "<< bkg_err_percentage <<"   \t  Total uncertainty on the background" << endl
             << " ------------ "<<endl
             << "#DEBUG (SR): "  << TString(SignalRegion) << endl;


  tablesFile.close();

  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsCNC_22_SC/"+TString(decay_mode)+"/"+TString(SignalRegion);
  //TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsCNC_22_noSC/"+TString(decay_mode)+"/"+TString(SignalRegion);
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){


makeCards("T2tt", "offShellLoose");
makeCards("T2tt", "offShellTight");
makeCards("T2tt", "lowDeltaM");
makeCards("T2tt", "mediumDeltaM");
makeCards("T2tt", "highDeltaM");

makeCards("T2bw025", "offShell");
makeCards("T2bw025", "lowMasses");
makeCards("T2bw025", "highMasses");

makeCards("T2bw050", "offShell");
makeCards("T2bw050", "lowMasses");
makeCards("T2bw050", "mediumDeltaM");
makeCards("T2bw050", "highDeltaM");

makeCards("T2bw075", "lowDeltaM");
makeCards("T2bw075", "mediumDeltaM");
makeCards("T2bw075", "highDeltaM");

}



void makeCardsT2tt(){


makeCards("T2tt", "offShellLoose");
makeCards("T2tt", "offShellTight");
makeCards("T2tt", "lowDeltaM");
makeCards("T2tt", "mediumDeltaM");
makeCards("T2tt", "highDeltaM");


}



void makeCardsT2bw025(){


makeCards("T2bw025", "offShell");
makeCards("T2bw025", "lowMasses");
makeCards("T2bw025", "highMasses");


}


void makeCardsT2bw050(){

makeCards("T2bw050", "offShell");
makeCards("T2bw050", "lowMasses");
makeCards("T2bw050", "mediumDeltaM");
makeCards("T2bw050", "highDeltaM");


}


void makeCardsT2bw075(){


makeCards("T2bw075", "lowDeltaM");
makeCards("T2bw075", "mediumDeltaM");
makeCards("T2bw075", "highDeltaM");

}

