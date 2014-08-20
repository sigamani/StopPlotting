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
#include "../backgroundPredictions_MT100.h" 

using namespace std;





void makeCLsCards(TString decay_mode, double BDTdefCutOffset, int MSTOP, int MLSP){


      std::ostringstream ostr1;
      ostr1 << MSTOP;
      std::string stop = ostr1.str();

      std::ostringstream ostr2;
      ostr2 << MLSP;
      std::string neut = ostr2.str();


	  TString decay_mode_; 
	  TString SignalRegion_; 
 	  TString SignalRegion = signalregionName(decay_mode, MSTOP, MLSP); 

	  if (decay_mode == "T2bw025") {decay_mode_ = "t2bw025"; }
 	  if (decay_mode == "T2bw050") {decay_mode_ = "t2bw050"; }   
	  if (decay_mode == "T2bw075") {decay_mode_ = "t2bw075"; }
   	  if (decay_mode == "T2tt")    {decay_mode_ = "t2tt";    }

	  if (SignalRegion == "T2bw025_1") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw025_3_lowDM")   {SignalRegion_ = "R3";   }   
 	  if (SignalRegion == "T2bw025_3_highDM")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw025_4")   {SignalRegion_ = "R4";   }
   	  if (SignalRegion == "T2bw025_6")   {SignalRegion_ = "R6";   }

	  if (SignalRegion == "T2bw050_1_lowLSP") {SignalRegion_ = "R1"; }
	  if (SignalRegion == "T2bw050_1_highLSP") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw050_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw050_4")   {SignalRegion_ = "R4";   }
	  if (SignalRegion == "T2bw050_5_lowDM")   {SignalRegion_ = "R5";   }
	  if (SignalRegion == "T2bw050_5_highDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw050_6")   {SignalRegion_ = "R6";   }

 	  if (SignalRegion == "T2bw075_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2bw075_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2bw075_3")   {SignalRegion_ = "R3";   }
   	  if (SignalRegion == "T2bw075_5_lowDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw075_5_highDM")   {SignalRegion_ = "R5";   }

 	  if (SignalRegion == "T2tt_1_lowLSP")   {SignalRegion_ = "R1";   }   
 	  if (SignalRegion == "T2tt_1_highLSP")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2tt_2_lowDM")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_2_highDM")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_5_lowDM")   {SignalRegion_ = "R5";   }
	  if (SignalRegion == "T2tt_5_mediumDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2tt_5_highDM")   {SignalRegion_ = "R5";   }


      TFile sig("ntp_8/"+decay_mode+".root");
      TH1D* signal= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signal_RAW= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_RAW_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalJESUp= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"JESUp_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalJESDown= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"JESDown_S"+TString(stop)+"_N"+TString(neut));

      TH1D* signalBVetoBCUp= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"BVetoBCUp_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalBVetoBCDown= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"BVetoBCDown_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalBVetoLightUp= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"BVetoLightUp_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalBVetoLightDown= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"BVetoLightDown_S"+TString(stop)+"_N"+TString(neut));

      TH1D* signalGEN = (TH1D*)sig.Get("Events_NGenSignal_S"+TString(stop)+"_N"+TString(neut));
      TH1D* signalPRESEL = (TH1D*)sig.Get("Events_Preselection_S"+TString(stop)+"_N"+TString(neut));


      TFile datafile("ntp_8/data.root");
      TH1D* datahist= (TH1D*)datafile.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_S0_N0");


      int nbins = signal->GetNbinsX();

      double BDTdefCut =  BDTcut(SignalRegion) ; 
	  //double cut = BDTdefCut; 
	  double cut = BDTdefCut + BDTdefCutOffset;  //FOR OFFSET SCAN

      int max_bin = signal->GetXaxis()->FindBin(cut);

      double ndata = datahist->Integral(max_bin,nbins+1);

	  double nsignal = signal->Integral(max_bin,nbins+1);
      double nsignal_RAW = signal_RAW->Integral(max_bin,nbins+1);
      double nsignalJESUp = signalJESUp->Integral(max_bin,nbins+1);
      double nsignalJESDown = signalJESDown->Integral(max_bin,nbins+1);
      double nsignalBVetoBCUp = signalBVetoBCUp->Integral(max_bin,nbins+1);
      double nsignalBVetoBCDown = signalBVetoBCDown->Integral(max_bin,nbins+1);
      double nsignalBVetoLightUp = signalBVetoLightUp->Integral(max_bin,nbins+1);
      double nsignalBVetoLightDown = signalBVetoLightDown->Integral(max_bin,nbins+1);
      double totalsignal = signalGEN->GetMean();	   
      double nsignalpreselection = signalPRESEL->Integral();
      double nsignalpreselection2 = signal->Integral();

	  double bkg = 0.; 
      double bkg_err = 0.; 
      double bkg_err_percentage = 0.; 


		if (SignalRegion == "T2bw025_1") {
		bkg = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw025_3_lowDM") {
		bkg = backgroundPrediction_BDT_T2bw025_3_lowDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw025_3_lowDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw025_3_highDM") {
		bkg = backgroundPrediction_BDT_T2bw025_3_highDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw025_3_highDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw025_4") {
		bkg = backgroundPrediction_BDT_T2bw025_4(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw025_4(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw025_6") {
		bkg = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_1_lowLSP") {
		bkg = backgroundPrediction_BDT_T2bw050_1_lowLSP(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_1_lowLSP(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_1_highLSP") {
		bkg = backgroundPrediction_BDT_T2bw050_1_highLSP(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_1_highLSP(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_3") {
		bkg = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_4") {
		bkg = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_5_lowDM") {
		bkg = backgroundPrediction_BDT_T2bw050_5_lowDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_5_lowDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_5_highDM") {
		bkg = backgroundPrediction_BDT_T2bw050_5_highDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_5_highDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw050_6") {
		bkg = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw075_1") {
		bkg = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw075_2") {
		bkg = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw075_3") {
		bkg = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw075_5_lowDM") {
		bkg = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2bw075_5_highDM") {
		bkg = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_1_lowLSP") {
		bkg = backgroundPrediction_BDT_T2tt_1_lowLSP(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_1_lowLSP(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_1_highLSP") {
		bkg = backgroundPrediction_BDT_T2tt_1_highLSP(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_1_highLSP(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_2_lowDM") {
		bkg = backgroundPrediction_BDT_T2tt_2_lowDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_2_lowDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_2_highDM") {
		bkg = backgroundPrediction_BDT_T2tt_2_highDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_2_highDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_5_lowDM") {
		bkg = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_5_mediumDM") {
		bkg = backgroundPrediction_BDT_T2tt_5_mediumDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_5_mediumDM(BDTdefCutOffset).second ; 
		}

		if (SignalRegion == "T2tt_5_highDM") {
		bkg = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).first  ; 
		bkg_err = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).second ; 
		}

      bkg_err_percentage = (bkg_err / bkg) + 1. ;

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
	  double stat_err = 1. + sqrt (1. /nsignal_RAW + 1. / totalsignal -   1. /   (sqrt(nsignal_RAW * totalsignal)));
      double PDF_err = 10.;
      double ISR_err;

	 
	  if ( decay_mode == "T2bw025" )  ISR_err = 8.;
	  if ( decay_mode == "T2bw050" )  ISR_err = 10.;
	  if ( decay_mode == "T2bw075" )  ISR_err = 8.;
	  if ( decay_mode == "T2tt" )  ISR_err = 8.;

      if (JEStot > 20.) JEStot = 20.;	// put upper bound on JES uncertainty
      if (BVetotot > 10.) BVetotot = 10.;	// put upper bound on JES uncertainty
      if (stat_err != stat_err) stat_err = 0.;
      
      double tot_err = sqrt(stat_err*stat_err + BVetotot*BVetotot + JEStot*JEStot + 3*3 + 5*5 + 2.2*2.2 + PDF_err*PDF_err + ISR_err*ISR_err);
	  double sig_err_percentage = tot_err/100. + 1.;

      createTableCLsBDT(decay_mode, BDTdefCutOffset, SignalRegion, MSTOP, MLSP, ndata, nsignal, sig_err_percentage, bkg, bkg_err_percentage);
	  
}





void makeCards(TString decay_mode ){

      cout << decay_mode << endl;  
      int start = 4;
      int end = 6;

      for(int z= start; z<= end; z+=1){

	double BDTdefCutOffset  = float(z) / 20.;

            //cout << BDTdefCutOffset << endl;
	
              for(int x=100; x<=800; x+=25){
	
    	              for(int y=0; y<=400; y+=25){

				 if (x - y > 99){  
					 cout << "S"<<x << "N"<<y<<endl;	
					 makeCLsCards(decay_mode, BDTdefCutOffset, x, y);
				 }

		  		
			}
	       }	
        }	   
}






void createTableCLsBDT(TString decay_mode, double BDTdefCutOffset, TString SignalRegion, int S, int N, double ndata, double signal, double signal_err_percentage, double bkg, double bkg_err_percentage){

  
  std::ostringstream cut1;
  cut1 << BDTdefCutOffset;
  std::string CUT = cut1.str();

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
             << "observation \t " << ndata << endl
             << "bin            	\t\t 1              \t 1          	" << endl
             << "process        	\t\t signal         \t bkg     		" << endl
             << "process        	\t\t 0              \t 1          	" << endl
             << "rate           	\t\t " << signal << "  \t \t "<< bkg << endl
             << " ------------ " << endl
             << "signal_unc \t lnN 	\t   " << signal_err_percentage << "          \t\t -      \t   Total uncertainty on the signal " << endl
             << "bkg_unc    \t lnN 	\t -             \t\t "<< bkg_err_percentage <<"          \t  Total uncertainty on the background " << endl
             << " ------------ "<<endl 
             << "#DEBUG (SR): "  << TString(SignalRegion) << endl;
 
   
  tablesFile.close();


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_16/"+TString(decay_mode)+"_CUT"+TString(CUT)+"/";
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){

makeCards("T2bw025");
makeCards("T2bw050");
makeCards("T2bw075");
makeCards("T2tt");

}
