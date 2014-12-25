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
#include "function.C"




using namespace std;

double f_syst = 0.15;
TString ntpdir0 = "ntuplesmadgraph/"; 
TString plotdir = "Plots22/"; 






double calcSoSqrtB(double S, double B){

if (B < 1) B = 1;

      if (S >= 3)
         return S / sqrt(B + f_syst*f_syst * B*B);
      else

    return 0.;
}



int maxbin(TH1D* histo){
  int bi = 0;
  double max = 0;
  for( int i = 1; i <= histo->GetNbinsX(); i++){

    //if( histo->GetBinContent(i) > max && histo->GetBinError(i) < histo->GetBinContent(i) ){
    if( histo->GetBinContent(i) > max ){
      max = histo->GetBinContent(i);
      bi = i;
    }
  }
  return bi;
}





void makeCLsCards(TString setup, TString BDT, TString decay_mode, int MSTOP, int MLSP){


          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();


          TString dataset_name;

          if (decay_mode == "T2tt")    {dataset_name = "t2tt_all";}
          if (decay_mode == "T2bw025") {dataset_name = "t2bw_025";}
          if (decay_mode == "T2bw050") {dataset_name = "t2bw_050";}
          if (decay_mode == "T2bw075") {dataset_name = "t2bw_075";}

          TFile ttbar(ntpdir0+"/"+setup+"/"+decay_mode+"/ttbar/output/ttbar_all_full.root");
          TFile wjets(ntpdir0+"/"+setup+"/"+decay_mode+"/wjets/output/wjets_all_0.root");
          TFile others(ntpdir0+"/"+setup+"/"+decay_mode+"/others/output/others_all_0.root");
          TFile sig(ntpdir0+"/"+setup+"/"+decay_mode+"/signal/"+TString(stop)+"/"+TString(neut)+"/output/"+dataset_name+"_0.root");



          TH1D* TTBar= (TH1D*)ttbar.Get(BDT);
          TH1D* WJets= (TH1D*)wjets.Get(BDT);
          TH1D* Others= (TH1D*)others.Get(BDT);
          TH1D* signal= (TH1D*)sig.Get(BDT);


          int nbins = TTBar->GetNbinsX();
          double hmin = TTBar->GetXaxis()->GetBinLowEdge(1);
          double hmax = TTBar->GetXaxis()->GetBinUpEdge(nbins);


          TH1D* FOM = new TH1D("","",nbins,hmin,hmax);
          int max_bin;
          double cutvalue;
          double nsignal = signal->Integral();

   
              TH1D* SoB = new TH1D("","",nbins,hmin,hmax);
              int max_bin;

	
              for(int b=1; b<=nbins; ++b){

              double sig_ = signal->Integral(b,nbins+1);
              double bkg_ = TTBar->Integral(b,nbins+1) + WJets->Integral(b,nbins+1) + Others->Integral(b,nbins+1) ;

              double SoSqrtB = calcSoSqrtB(sig_, bkg_ );


              SoB->SetBinContent(b,SoSqrtB);
              }


            double signalcut = signalcut(decay_mode, MSTOP, MLSP);
            max_bin = TTBar->GetXaxis()->FindBin(signalcut);      
//	           max_bin = maxbin(SoB);


 	    double signal_ = signal->Integral(max_bin,nbins+1);
	    double ttbar_ = TTBar->Integral(max_bin,nbins+1);
	    double wjets_ = WJets->Integral(max_bin,nbins+1);
	    double others_ = Others->Integral(max_bin,nbins+1);


/*  	    cout << setup << endl;
  	    cout << BDT << endl;
	    cout << signalcut << endl;
	    cout << MSTOP << endl;
	    cout << MLSP << endl;
            cout << signal_ << endl;
*/
            createTableCLs(decay_mode, setup, BDT, MSTOP, MLSP,  signal_, ttbar_, wjets_, others_);

}





void makeCards(TString decay_mode){

          gStyle->SetOptStat(0);
          gStyle->SetCanvasColor(0);
          gStyle->SetPadColor(0);
          gStyle->SetMarkerStyle(15);
          gStyle->SetMarkerSize(0.25);
          gStyle->SetTextFont(42);
          gStyle->SetMarkerColor(37);
	  cout << "Making CLs cards" << endl;  


 	 
              for(int x=175; x<=800; x+=25){

	
    	              for(int y=25; y<=700; y+=25){
	
			 if (x - y > 99){  

				int mvaval_ = signalregion(decay_mode, x, y);
		

				std::ostringstream iStr;
				iStr << mvaval_;
				std::string bdtNUM = iStr.str();

				TString BDTval  = "BDT"+bdtNUM;
            
				TString setup = returnSetup(decay_mode, BDTval);

				makeCLsCards(setup, BDTval, decay_mode, x, y);
			}

		  		
			}
	       }	
	   
}








void makeAllPlots(){



makeCards("T2tt");
makeCards("T2bw025");
makeCards("T2bw050");
makeCards("T2bw075");


}



void createTableCLs(TString decay_mode, TString setup, TString BDT, int S, int N, double signal, double ttbar, double wjets, double others){


  char datacardname[100];
  sprintf(datacardname,"datacard-S%d-N%d.txt", S,N);  
 

  ofstream  tablesFile(datacardname);
  tablesFile.setf(ios::fixed);
  tablesFile.precision(1);
 
  tablesFile << "imax 1  number of channels" << endl
             << "jmax 3 number of backgrounds" << endl
             << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl
             << "------------"<<endl
             << "bin 1"<<endl    
             << "observation \t 0.0" << endl
             << "bin            	\t 1              \t 1          	\t  1        \t 1" << endl
             << "process        	\t signal         \t TTJets     	\t  Wjets    \t others" << endl
             << "process        	\t 0              \t 1          	\t  2        \t 3" << endl
             << "rate           	\t " << signal << "  \t \t \t "<< ttbar <<  " \t \t "  << wjets << " \t \t \t " << others << endl
             << "------------" << endl
             << "lumi       \t lnN 	\t 1.022         \t 1.022          	\t 1.022     \t 1.022         \t  lumi affects both signal and mc. lnN = lognormal" << endl
             << "signal_unc \t lnN 	\t 1.1           \t -              	\t -         \t -             \t  stop cross section + signal efficiency + other minor ones." << endl
             << "bkg_unc    \t lnN 	\t -             \t 1.15             	\t 1.15      \t 1.15           \t  15\% uncertainty on the rest of the backgrounds" << endl
             //<< "bkg_unc    \t lnN 	\t -             \t 1.30             	\t 1.30      \t 1.30           \t  30\% uncertainty on the rest of the backgrounds" << endl
             << "------------"<<endl
             << "#DEBUG (setup, BDT region, BDT cut): "  << setup << ", "<< BDT << ", "<< signalcut(decay_mode, S, N) << endl;
 
 
  tablesFile.close();


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/mT100_test/"+TString(decay_mode);
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}
