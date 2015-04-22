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
#include "../backgroundPrediction_BDT_SignalContamination.C"
#include "../backgroundPrediction.h"

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
 	  if (SignalRegion == "T2bw025_3")  {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw025_4_lowLSP")  {SignalRegion_ = "R4";   }
	  if (SignalRegion == "T2bw025_4_highLSP")  {SignalRegion_ = "R4";   }
   	  if (SignalRegion == "T2bw025_6")  {SignalRegion_ = "R6";   }

	  if (SignalRegion == "T2bw050_1_lowDM_lowLSP") {SignalRegion_ = "R1"; }
	  if (SignalRegion == "T2bw050_1_highDM") {SignalRegion_ = "R1"; }
	  if (SignalRegion == "T2bw050_1_lowDM_highLSP") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw050_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw050_4")   {SignalRegion_ = "R4";   }
	  if (SignalRegion == "T2bw050_5")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw050_6")   {SignalRegion_ = "R6";   }

 	  if (SignalRegion == "T2bw075_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2bw075_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2bw075_3")   {SignalRegion_ = "R3";   }
   	  if (SignalRegion == "T2bw075_5_lowDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw075_5_highDM")   {SignalRegion_ = "R5";   }

 	  if (SignalRegion == "T2tt_1_lowLSP")   {SignalRegion_ = "R1";   }   
 	  if (SignalRegion == "T2tt_1_mediumLSP")   {SignalRegion_ = "R1";   }   
 	  if (SignalRegion == "T2tt_1_highLSP")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2tt_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_5_lowDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2tt_5_highDM")   {SignalRegion_ = "R5";   }


      TFile sig("ntp8/"+decay_mode+".root");
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


      TFile datafile("ntp8/data.root");
      TH1D* datahist= (TH1D*)datafile.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_S0_N0");


      int nbins = signal->GetNbinsX();

      double BDTdefCut =  BDTcut(SignalRegion) ; 
	  double cut = BDTdefCut; 

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

	  double B = 0.; 
      double B_err = 0.; 

	  double Bp = backgroundPrediction_BDT_SignalContamination(decay_mode,MSTOP,MLSP).first  ; 
	  double Bp_err = backgroundPrediction_BDT_SignalContamination(decay_mode,MSTOP,MLSP).second ; 

        if (SignalRegion == "T2bw025_1") {
        B = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw025_3") {
        B = backgroundPrediction_BDT_T2bw025_3(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw025_3(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw025_4_lowLSP") {
        B = backgroundPrediction_BDT_T2bw025_4_lowLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw025_4_lowLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw025_4_highLSP") {
        B = backgroundPrediction_BDT_T2bw025_4_highLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw025_4_highLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw025_6") {
        B = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_1_lowDM_lowLSP") {
        B = backgroundPrediction_BDT_T2bw050_1_lowDM_lowLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_1_lowDM_lowLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_1_lowDM_highLSP") {
        B = backgroundPrediction_BDT_T2bw050_1_lowDM_highLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_1_lowDM_highLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_1_highDM") {
        B = backgroundPrediction_BDT_T2bw050_1_highDM(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_1_highDM(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_3") {
        B = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_4") {
        B = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_5") {
        B = backgroundPrediction_BDT_T2bw050_5(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_5(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw050_6") {
        B = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw075_1") {
        B = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw075_2") {
        B = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw075_3") {
        B = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw075_5_lowDM") {
        B = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2bw075_5_highDM") {
        B = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_1_lowLSP") {
        B = backgroundPrediction_BDT_T2tt_1_lowLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_1_lowLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_1_mediumLSP") {
        B = backgroundPrediction_BDT_T2tt_1_mediumLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_1_mediumLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_1_highLSP") {
        B = backgroundPrediction_BDT_T2tt_1_highLSP(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_1_highLSP(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_2") {
        B = backgroundPrediction_BDT_T2tt_2(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_2(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_5_lowDM") {
        B = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).second ;
        }

        if (SignalRegion == "T2tt_5_highDM") {
        B = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).first  ;
        B_err = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).second ;
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

      double PDF_err = 5.;
      double ISR_err;

      if ( decay_mode == "T2bw025" )  ISR_err = 8.;
	  if ( decay_mode == "T2bw050" )  ISR_err = 10.;
	  if ( decay_mode == "T2bw075" )  ISR_err = 8.;
	  if ( decay_mode == "T2tt" )     ISR_err = 8.;

      if (JEStot > 20.) JEStot = 20.;	// put upper bound on JES uncertainty
      if (BVetotot > 10.) BVetotot = 10.;	// put upper bound on JES uncertainty

      if (stat_err != stat_err) stat_err = 0.;
      if (BVetotot != BVetotot) BVetotot = 0.;
      if (JEStot != JEStot) JEStot = 0.;
     
      double S_err = sqrt(stat_err*stat_err + BVetotot*BVetotot + JEStot*JEStot + 3*3 + 5*5 + 2.6*2.6 + PDF_err*PDF_err + ISR_err*ISR_err)/100.;
	  double S_err_abs = nsignal * S_err;


      double DeltaB = Bp - B; // signal contamination factor
      double SigmaTot = sqrt(S_err_abs*S_err_abs + B_err*B_err + Bp_err*Bp_err  -  2 * B_err * Bp_err);
	  double nsignal_new = nsignal + DeltaB;
	  if (S_err != S_err) {S_err_abs =0; SigmaTot = 0;}

      double ErrSp = B_err*B_err + Bp_err*Bp_err  -  2 * B_err * Bp_err;



	  if (nsignal_new < 0) nsignal_new = 0;
	  //cout << "S: "<< nsignal << " +/- " << S_err_abs << endl;
	  //cout << "S': "<< nsignal_new << " +/- " << SigmaTot << endl;

	  double sig_err_percentage = S_err + 1.;
      double bkg_err_percentage = (B_err / B) + 1. ;

	  // SC	
      createTableCLsBDT(decay_mode, BDTdefCutOffset, SignalRegion, MSTOP, MLSP, ndata, nsignal_new, 1+ BVetotot/100, 1+JEStot/100, 1+ISR_err/100, 1 + stat_err/100, 1+PDF_err/100, 1+ErrSp/100,B, bkg_err_percentage);
	  //No SC
      //createTableCLsBDT(decay_mode, BDTdefCutOffset, SignalRegion, MSTOP, MLSP, ndata, nsignal, 1+ BVetotot/100, 1+JEStot/100, 1+ISR_err/100, 1 + stat_err/100, 1+PDF_err/100,B, bkg_err_percentage);
	 
}




void makeCards(TString decay_mode ){

      cout << decay_mode << endl;  
      int start = 0;
      int end = 0;

      for(int z= start; z<= end; z+=1){

	double BDTdefCutOffset  = float(z) / 20.;

	
              for(int x=525; x<=800; x+=25){
	
    	              for(int y=0; y<=400; y+=25){

				 if (x - y > 99){  
					 cout << "S"<<x << "N"<<y<<endl;	
					 makeCLsCards(decay_mode, BDTdefCutOffset, x, y);
				 }

		  		
			}
	      }	
        }	   
}






void createTableCLsBDT(TString decay_mode, double BDTdefCutOffset, TString SignalRegion, int S, int N, double ndata, 
						double signal, double BVetotot, double JES, double ISR_err, double stat_err, double PDF_err, double SigmaSp, 
						double bkg, double bkg_err_percentage){

  
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
             << "kmax 9  number of nuisance parameters (sources of systematical uncertainties)" << endl
             << " ------------ "<<endl
             << "bin 1"<<endl    
             << "observation \t " << ndata << endl
             << "bin            	\t\t 1              \t 1          	" << endl
             << "process        	\t\t signal         \t bkg     		" << endl
             << "process        	\t\t 0              \t 1          	" << endl
             << "rate           	\t\t " << signal << "  \t\t \t "<< bkg << endl
             << " ------------ " << endl
             << "Lumi \t lnN 	\t   " << 1.026 << "          \t\t -      \t   Luminosity " << endl
             << "LeptEff lnN	\t\t\t " << 1.058 << "          \t -     \t   Combined Lepton ID/Isolation with Trigger Efficiency" << endl
             << "BTag \t lnN 	\t   " << BVetotot << "          \t\t -      \t   BTagging " << endl
             << "JES \t lnN 	\t   " << JES << "          \t\t -      \t   Jet Energy Scale" << endl
             << "ISR \t lnN 	\t   " << ISR_err << "          \t\t -      \t   Initial State Radiation" << endl
             << "Stat \t lnN 	\t   " << stat_err << "          \t\t -     \t\t   MC Statistics" << endl
             << "PDF \t lnN 	\t   " << PDF_err << "          \t\t -      \t   Parton Distribution Functions " << endl
             << "SigmaSp lnN 	\t   " << SigmaSp << "          \t\t -      \t   Uncertainty on signal from contamination (B') " << endl
             << "BkgErr \t lnN \t\t\t -  \t\t\t\t "<< bkg_err_percentage <<"   \t  Total uncertainty on the background " << endl
             << " ------------ "<<endl 
             << "#DEBUG (SR): "  << TString(SignalRegion) << endl;
 
   
  tablesFile.close();


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_26/"+TString(decay_mode)+"/";
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){

makeCards("T2bw025");
makeCards("T2bw050");
makeCards("T2bw075");
makeCards("T2tt");

}
