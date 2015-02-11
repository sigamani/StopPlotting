#include "TColor.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TF2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include "TF1.h"
#include "TGaxis.h"

#include <iomanip>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>

#include "../stopCrossSections.h"


using namespace std;
void rootlogon();


void ReturnTGraph(TH2D *, int);



// create temp output file
TFile *fout = new TFile("temp_results.root","recreate");




double ReturnUpperLimit(int stopmass, int lspmass, TString decay_mode, TString Exp){


   TString Exp0;

   TFile* file = TFile::Open(decay_mode+".root");

   if (Exp == "Exp") {
    Exp0 = "Exp";
   }
   if (Exp == "ExpM") {
    Exp0 = "Exp_OneSigDown";
   }
   if (Exp == "ExpP") {
    Exp0 = "Exp_OneSigUp";
   }
   if (Exp == "Obs") {
    Exp0 = "Obs";
   }
   if (Exp == "ObsM") {
    Exp0 = "Obs_OneSigDown";
   }
   if (Exp == "ObsP") {
    Exp0 = "Obs_OneSigUp";
   }


   TH2D* hist = (TH2D*)file->Get("h_SigStrengthLimitHist_LPS_"+Exp0);

   int X = hist->GetXaxis()->FindBin(stopmass);
   int Y = hist->GetYaxis()->FindBin(lspmass);
   double limit = hist->GetBinContent(X,Y);


    file->Close();

    return limit;
}




void ReturnTGraph(TH2D *input_hist, TString Exp){

   TCanvas* c = new TCanvas("c","Contour List",0,0,600,600);

   input_hist->SetContour(3);
   input_hist->SetContourLevel(0, 0); //value for your first level
   input_hist->SetContourLevel(1, 1.); //non-existing high level
   input_hist->SetContourLevel(2, 1e9); //non-existing high level
   input_hist->Draw("CONT Z LIST"); 
   c->Update();

   TObjArray *conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TList* contLevel = NULL;
   TGraph* curv     = NULL;
   TGraph* gc       = NULL;
   double contours[] = NULL; 

   Int_t TotalConts = conts->GetSize();
   Double_t x0, y0, z0;

   for(int i = 0; i < TotalConts; i++){
      contLevel = (TList*)conts->At(i);
      curv = (TGraph*)contLevel->First();

		for(int j = 0; j < contLevel->GetSize(); j++){
			curv->GetPoint(0, x0, y0);

			gc = (TGraph*)curv->Clone();

		}
   }

         if (Exp == "Exp") {
         gc->SetName("graph_smoothed_Exp");
     }
         if (Exp == "ExpM") {
         gc->SetName("graph_smoothed_ExpM");
     }
         if (Exp == "ExpP") {
         gc->SetName("graph_smoothed_ExpP");
     }
         if (Exp == "Obs") {
         gc->SetName("graph_smoothed_Obs");
     }
         if (Exp == "ObsM") {
         gc->SetName("graph_smoothed_ObsM");
     }
         if (Exp == "ObsP") {
         gc->SetName("graph_smoothed_ObsP");
     }
         if (Exp == "Exp_OffShell") {
         gc->SetName("graph_smoothed_Exp_OffShell");
     }
         if (Exp == "ExpM_OffShell") {
         gc->SetName("graph_smoothed_ExpM_OffShell");
     }
         if (Exp == "ExpP_OffShell") {
         gc->SetName("graph_smoothed_ExpP_OffShell");
     }
         if (Exp == "Obs_OffShell") {
         gc->SetName("graph_smoothed_Obs_OffShell");
     }
         if (Exp == "ObsM_OffShell") {
         gc->SetName("graph_smoothed_ObsM_OffShell");
     }
         if (Exp == "ObsP_OffShell") {
         gc->SetName("graph_smoothed_ObsP_OffShell");
     }

   fout->cd();
   gc->Write();
	
   delete c;

}





void plot_limit_contour_T2bw(TString decay_mode, TString Exp){



   TH2D *hist = new TH2D("hist","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = ReturnUpperLimit(x, y, decay_mode, Exp);
                        hist->Fill(x,y,1./ limit);

                        }
            }

    	ReturnTGraph(hist, Exp);

  delete hist;

}



void plot_limit_contour_T2ttOnShell(TString Exp){



   TH2D *hist = new TH2D("hist","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y <= 150) continue;

                        double limit = ReturnUpperLimit(x, y, "T2tt", Exp);
                        hist->Fill(x,y,1./ limit);

                        }
            }

    	ReturnTGraph(hist, Exp);

  delete hist;

}






void plot_limit_contour_T2ttOffShell(TString Exp){



   TH2D *hist = new TH2D("hist","",29,87.5, 812.5, 17, -12.5,412.5);


              	for(int x=100; x<=800; x+=25){

                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;
                        if (x - y > 150) continue;

                        double limit = ReturnUpperLimit(x, y, "T2tt", Exp);
                        hist->Fill(x,y,1./ limit);

                        }
            	}

    		ReturnTGraph(hist, "T2tt_OffShell");

	delete hist;

}





void Return2DTemperatureMap(TString decay_mode, TString Exp){


   TH2D *hXsec_exp_corr = new TH2D("hXsec_exp_corr","",29,87.5, 812.5, 17, -12.5,412.5); 

              	for(int x=100; x<=800; x+=25){

                	for(int y=0; y<=400; y+=25){

                        if (x-y >= 100) { 

                        double limit = ReturnUpperLimit(x, y, decay_mode, Exp);
						double upperlimit = limit * stopCrossSection(x).first ; 
						hXsec_exp_corr->Fill(x,y, upperlimit);

	 				    }	
						   else  hXsec_exp_corr->Fill(x,y, 0);

					}
	  			}


  fout->cd();
  fout->Write();

  delete hXsec_exp_corr; 

}




void doAll(TString decay_mode){


  cout << "Running over "<< decay_mode << endl;

  if (decay_mode == "T2tt") {

 Return2DTemperatureMap("T2tt", "Exp");
 cout << "1/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("Exp");
 plot_limit_contour_T2ttOnShell("Exp");
 cout << "2/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("ExpM");
 plot_limit_contour_T2ttOnShell("ExpM");
 cout << "3/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("ExpP");
 plot_limit_contour_T2ttOnShell("ExpP");
 cout << "4/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("Obs");
 plot_limit_contour_T2ttOnShell("Obs");
 cout << "5/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("ObsM");
 plot_limit_contour_T2ttOnShell("ObsM");
 cout << "6/7 plots done"<< endl;
 plot_limit_contour_T2ttOffShell("ObsP");
 plot_limit_contour_T2ttOnShell("ObsP");
 cout << "7/7 plots done"<< endl;


 } else 


    Return2DTemperatureMap(decay_mode, "Exp");
    cout << "1/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "Exp");
    cout << "2/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "ExpM");
    cout << "3/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "ExpP");
    cout << "4/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "Obs");
    cout << "5/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "ObsP");
    cout << "6/7 plots done"<< endl;
    plot_limit_contour_T2bw(decay_mode, "ObsM");
    cout << "7/7 plots done"<< endl;

    fout->Close();

    gSystem->Exec("mv temp_results.root config/SUS14015-SUS13025-Combination/"+decay_mode+"_results.root");
 
}
