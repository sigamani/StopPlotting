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

#include "smooth_SC.C"
#include "../stopCrossSections.h"

using namespace std;
void rootlogon();


void ReturnTGraph(TH2D *, int);


double return_limit(int stopmass, int lspmass, TString decay_mode, TString Exp){

   TFile* file = TFile::Open("CNC.root");
   TH2D* hist = (TH2D*)file->Get(decay_mode+"_"+Exp);

   int X = hist->GetXaxis()->FindBin(stopmass);
   int Y = hist->GetYaxis()->FindBin(lspmass);
   double limit = hist->GetBinContent(X,Y);

    if (limit == 0.) limit = 1.1;

    file->Close();

    return limit;
}


TFile *fout = new TFile("/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/PlotsSMS/config/SUS14015/TEST_results.root","recreate");

void plot_limit_histo(TString decay_mode){



  //palette settings - completely independent
  const Int_t NRGBs = 6;
  const Int_t NCont = 999;

  Double_t stops[NRGBs] = { 0.00, 0.1, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.99, 0.0, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.0, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.99, 0.0, 1.00, 0.12, 0.00, 0.00 };


  //TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  //gStyle->SetNumberContours(NCont);

  gStyle->SetOptStat(0);


   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5);

   TH2D *hXsec_exp_corr = new TH2D("hXsec_exp_corr","",29,87.5, 812.5, 17, -12.5,412.5); 


   Double_t h[100], g[100];
   Int_t n = 20;
   for (Int_t i=0;i<n;i++) {
     h[i] = i*0.1;
     g[i] = 10*sin(h[i]+0.2);
	
   }


   graph_smoothed_Exp  = new TGraph(n,h,g);
   graph_smoothed_ExpM = new TGraph(n,h,g);
   graph_smoothed_ExpP = new TGraph(n,h,g);
   graph_smoothed_Obs  = new TGraph(n,h,g);
   graph_smoothed_ObsM = new TGraph(n,h,g);
   graph_smoothed_ObsP = new TGraph(n,h,g);
   
   graph_smoothed_Exp->SetName("graph_smoothed_Exp");
   graph_smoothed_ExpM->SetName("graph_smoothed_ExpM");
   graph_smoothed_ExpP->SetName("graph_smoothed_ExpP");
   graph_smoothed_Obs->SetName("graph_smoothed_Obs");
   graph_smoothed_ObsM->SetName("graph_smoothed_ObsM");
   graph_smoothed_ObsP->SetName("graph_smoothed_ObsP");
   
                                 
              for(int x=100; x<=800; x+=25){

                      for(int y=0; y<=400; y+=25){

					    if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "Exp");

						double upperlimit = limit * stopCrossSection(x).first ; 

						hXsec_exp_corr->Fill(x,y, upperlimit);
	 

					}
	  		}


	      // Hack to get the contours to work properly

              for(int x=100; x<=800; x+=25){

                      for(int y=0; y<=400; y+=25){

                           if (x - y > 99){

		                hXsec_exp_corr->Fill(x,y, 0. * stopCrossSection(x).first );
		          }		
			}

		}		


  hXsec_exp_corr->SetFillColor(1);

  int colors[3] = {1,2,4}; //red, blue,black
  gStyle->SetPalette(3,colors);  



  fout->cd();
  hXsec_exp_corr->Write();
  graph_smoothed_Exp->Write(); 
  graph_smoothed_ExpM->Write(); 
  graph_smoothed_ExpP->Write();
  graph_smoothed_Obs->Write(); 
  graph_smoothed_ObsM->Write(); 
  graph_smoothed_ObsP->Write(); 

  fout->Write();
  //fout->Close();





}






void ReturnTGraph(TH2D *SMS, int n){

   TCanvas* c = new TCanvas("c","Contour List",0,0,600,600);
   c->SetRightMargin(0.15);
   c->SetTopMargin(0.15);


  SMS->SetContour(3);
  SMS->SetContourLevel(0, 0); //value for your first level
  SMS->SetContourLevel(1, 1.); //non-existing high level
  SMS->SetContourLevel(2, 1e9); //non-existing high level


   SMS->Draw("CONT Z LIST"); 
   c->Update();


   TObjArray *conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TList* contLevel = NULL;
   TGraph* curv     = NULL;
   TGraph* gc       = NULL;
   double contours[] = NULL; 

   Int_t nGraphs    = 0;
   Int_t TotalConts = 0;

   if (conts == NULL){
      printf("*** No Contours Were Extracted!\n");
      TotalConts = 0;
      return;
   } else {
      TotalConts = conts->GetSize();
   }

   printf("TotalConts = %d\n", TotalConts);



  for(int i = 0; i < TotalConts; i++){
      contLevel = (TList*)conts->At(i);
      printf("Contour %d has %d Graphs\n", i, contLevel->GetSize());
      nGraphs += contLevel->GetSize();
   }

   nGraphs = 0;



 
   TCanvas c1("c1","c1",800,600);
   c1.SetLeftMargin(0.1706731);
   c1.SetRightMargin(0.1983173);
   c1.SetTopMargin(0.04895105);
   c1.SetBottomMargin(0.1416084);
   c1.Range(-289.7381,-191.8196,1334.643,1074.487);

   TH2D *hr = new TH2D("hr","",29,87.5, 812.5, 17, -12.5,412.5); 
   hr->Draw();
   Double_t x0, y0, z0;
   TLatex l;
   l.SetTextSize(0.03);
   char val[20];

   for(int i = 0; i < TotalConts; i++){
      contLevel = (TList*)conts->At(i);
      if (i<3) z0 = contours[2-i];
      else     z0 = contours[i];
      printf("Z-Level Passed in as:  Z = %f\n", z0);

      // Get first graph from list on curves on this level
      curv = (TGraph*)contLevel->First();
      for(int j = 0; j < contLevel->GetSize(); j++){
         curv->GetPoint(0, x0, y0);
         if (z0<0) curv->SetLineColor(kRed);
         if (z0>0) curv->SetLineColor(kRed);
         nGraphs ++;
         printf("\tGraph: %d  -- %d Elements\n", nGraphs,curv->GetN());

         gc = (TGraph*)curv->Clone();
         gc->SetLineWidth(2);
         gc->Draw("C");

  
         if (n == 1) {
         gc->SetName("graph_smoothed_Exp");
     }
         if (n == 2) {
         gc->SetName("graph_smoothed_ExpM");
     }
         if (n == 3) {
         gc->SetName("graph_smoothed_ExpP");
     }
         if (n == 4) {
         gc->SetName("graph_smoothed_Obs");
     }
         if (n == 5) {
         gc->SetName("graph_smoothed_ObsM");
     }
         if (n == 6) {
         gc->SetName("graph_smoothed_ObsP");
     }

       sprintf(val,"%g",z0);
        // l.DrawLatex(x0,y0,val);
         curv = (TGraph*)contLevel->After(curv); // Get Next graph
      }
   }

   fout->cd();
   gc->Write();
   fout->Write();
//   fout->Close();

   c1.Update();
   printf("\n\n\tExtracted %d Contours and %d Graphs \n", TotalConts, nGraphs ); 


}






void plot_limit_contourExp(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "Exp");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "Exp");
                        SMS->Fill(x,y,1./ limit_cleaned);

                        }
            }

   ReturnTGraph(SMS, 1);

}





void plot_limit_contourExpM(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5); 


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "ExpM");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "ExpM");
                        SMSm->Fill(x,y,1./ limit_cleaned);

                        }
            }


   ReturnTGraph(SMSm, 2);

}




void plot_limit_contourExpP(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5); 


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "ExpP");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "ExpP");
                        SMSp->Fill(x,y,1./ limit_cleaned);

                        }
            }

   ReturnTGraph(SMSp, 3);

}




void plot_limit_contourObs(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "Obs");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "Obs");
     	          		SMS->Fill(x,y,1/limit_cleaned);

						}
	  		}


   ReturnTGraph(SMS, 4);

}



void plot_limit_contourObsM(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "ObsM");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "ObsM");
     	          		SMS->Fill(x,y,1/limit_cleaned);

						}
	  		}


   ReturnTGraph(SMS, 5);

}





void plot_limit_contourObsP(TString decay_mode){



   gStyle->SetOptStat(0);


   const Int_t NCont = 999;
   gStyle->SetNumberContours(NCont);
   double shell;

   if (decay_mode == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (decay_mode == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (decay_mode == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (decay_mode == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSp = new TH2D("SMSp","",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMSm = new TH2D("SMSm","",29,87.5, 812.5, 17, -12.5,412.5);


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){

                        if (x - y < 100) continue;

                        double limit = return_limit(x, y, decay_mode, "ObsP");
                        double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, "ObsP");
     	          		SMS->Fill(x,y,1/limit_cleaned);

						}
	  		}


   ReturnTGraph(SMS, 6);

}







void makePlotSMSFilesCNC(TString decay_mode){


plot_limit_histo(decay_mode);
plot_limit_contourObs(decay_mode);
plot_limit_contourObsP(decay_mode);
plot_limit_contourObsM(decay_mode);
plot_limit_contourExp(decay_mode);
plot_limit_contourExpP(decay_mode);
plot_limit_contourExpM(decay_mode);

fout->Close();
   
}
