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




using namespace std;
void rootlogon();


TString savedir = "~/www/";





void plot_limit(TString dir){

  /*        gStyle->SetOptStat(0);
          gStyle->SetCanvasColor(0);
          gStyle->SetPadColor(0);
          gStyle->SetMarkerStyle(15);
          gStyle->SetMarkerSize(0.25);
          gStyle->SetTextFont(42);
          gStyle->SetMarkerColor(37);
*/

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

   if (dir == "T2bw025") {dataset_name = "T2bw025"; shell = 80. / 0.25;}
   if (dir == "T2bw050") {dataset_name = "T2bw050"; shell = 80. / 0.50;}
   if (dir == "T2bw075") {dataset_name = "T2bw075"; shell = 80. / 0.75;}
   if (dir == "T2tt")    {dataset_name = "T2tt";    shell = 173.;}



   TH2D *SMS = new TH2D("SMS","",26,162.5, 812.5, 16, 12.5,412.5); 
   TH2D *SMSp = new TH2D("SMSp","",26,162.5, 812.5, 16, 12.5,412.5); 
   TH2D *SMSm = new TH2D("SMSm","",26,162.5, 812.5, 16, 12.5,412.5); 


              for(int x=175; x<=800; x+=25){


                      for(int y=25; y<=700; y+=25){


  		  char shortfilename[500];
  		  char filename[500];


                  sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/May5/mT100_Sig30/%s/higgsCombineS%d-N%d.Asymptotic.mH120.root", dataset_name, x, y);

   
                  ifstream ifile(filename);
	          if (!ifile.good()) continue; 

	         
		  TFile* file  = new TFile(filename, "READ");  
		  char* name = (char*)file->GetName();



TTree *limittree = (TTree*)file->Get("limit");


double high_val = 100.;


TH1F* obs = new TH1F("obs","",100,0,high_val);
limittree->Draw("limit>>obs", "quantileExpected==-1");
TH1F* expm2 = new TH1F("expm2","",100,0,high_val);
limittree->Draw("limit>>expm2", "quantileExpected>0.02 && quantileExpected<0.03");
TH1F* expm1 = new TH1F("expm1","",100,0,high_val);
limittree->Draw("limit>>expm1", "quantileExpected>0.15 && quantileExpected<0.16");
TH1F* exp = new TH1F("exp","",100,0,high_val);
limittree->Draw("limit>>exp", "quantileExpected==0.5");
TH1F* expp1 = new TH1F("expp1","",100,0,high_val);
limittree->Draw("limit>>expp1", "quantileExpected>0.83 && quantileExpected<0.84");
TH1F* expp2 = new TH1F("expp2","",100,0,high_val);
limittree->Draw("limit>>expp2", "quantileExpected>0.97 && quantileExpected<0.98");



//	  if (exp->GetMean() < 1.0) {
	   SMS->Fill(x,y,1./exp->GetMean());
	   SMSp->Fill(x,y,expp1->GetMean());
	   SMSm->Fill(x,y,expm1->GetMean());
 
		  file->Close();
			}
		}
//	  }

	
              TAxis *data_yaxis = SMS->GetYaxis();
              TAxis *data_xaxis = SMS->GetXaxis();

              data_xaxis->SetTitle("Mass STOP");
              data_yaxis->SetTitle("Mass LSP");



	      // Hack to get the contours to work properly

            for(int x=175; x<=800; x+=25){

                      for(int y=25; y<=700; y+=25){
	
			if (x-y > 75) continue;

		           SMS->Fill(x,y,1./1.1);
		           SMSp->Fill(x,y,1.1);
		           SMSm->Fill(x,y,1.1);

			}

		}		


  SMS->SetFillColor(1);
  SMSp->SetFillColor(2);
  SMSm->SetFillColor(4);

  int colors[3] = {1,2,4}; //red, blue,black
  gStyle->SetPalette(3,colors);  


  SMS->SetContour(3);
  SMS->SetContourLevel(0,1e9); //value for your first level
  SMS->SetContourLevel(1,1.); //non-existing high level
  SMS->SetContourLevel(2,1e6); //non-existing high level
  SMS->SetLineColor(1);
  SMS->Draw("cont1");

  SMSp->SetContour(3);
  SMSp->SetContourLevel(0,1.0); //value for your first level
  SMSp->SetContourLevel(1,1e6); //non-existing high level
  SMSp->SetContourLevel(2,1e9); //non-existing high level
  SMSp->SetLineColor(2);
  //SMSp->Draw("cont1 same");

  SMSm->SetContour(3);
  SMSm->SetContourLevel(0,0.99); //value for your first level
  SMSm->SetContourLevel(1,1e6); //non-existing high level
  SMSm->SetContourLevel(2,1e9); //non-existing high level
  SMSm->SetLineColor(4);
  //SMSm->Draw("cont1 same");





  TLegendEntry *legge;
  TLegend *leg;
  leg = new TLegend(0.4,0.55,0.7,0.85);
  leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
  legge = leg->AddEntry(SMS,   "Expected U.L. @95\% CL", "l");
//  legge = leg->AddEntry(SMSp,   "Exp plus", "l");
//  legge = leg->AddEntry(SMSm,   "Exp minus", "l");
  leg->SetFillColor(0);
  leg->Draw();
//  SMS->Draw("colz");

   c1->SaveAs("~/www/test.png");


}

