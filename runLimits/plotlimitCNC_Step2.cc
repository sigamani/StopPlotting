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


using namespace std;
void rootlogon();


TString savedecay_mode = "~/www/";

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




void plot_limit(TString decay_mode, TString Exp){

 
  gStyle->SetCanvasColor(0);
  gStyle->SetPadColor(0);
  gStyle->SetMarkerStyle(15);
  gStyle->SetMarkerSize(0.25);
  gStyle->SetPalette(1);
  gStyle->SetTextFont(42);
  gStyle->SetMarkerColor(37);


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


   TFile *fout = new TFile(TString(decay_mode)+"_"+Exp+"_BDT.root","recreate");

   TH2D *hist_limit =  new TH2D(TString(decay_mode)+"_exp" ,"",29,87.5, 812.5, 17, -12.5,412.5); 
 
              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=400; y+=25){


						double limit = return_limit(x, y, decay_mode, Exp);

						double limit_cleaned = ReturnCleanedLimit( x, y, limit, decay_mode, false, Exp);

								if (limit_cleaned < 1.0){
								hist_limit->Fill(x,y,limit_cleaned);
					
						       }
	  				  }

	         }


      TAxis *data_yaxis = hist_limit->GetYaxis();
      TAxis *data_zaxis = hist_limit->GetZaxis();
      TAxis *data_xaxis = hist_limit->GetXaxis();


      data_xaxis->SetTitle("m_{#tilde{t}} (GeV)");
      data_yaxis->SetTitle("m_{#tilde{#chi}^{0}_{1}} (GeV)");


      TCanvas c1("c1","c1",800,600);
      c1.SetLeftMargin(0.1706731);
      c1.SetRightMargin(0.1983173);
      c1.SetTopMargin(0.04895105);
      c1.SetBottomMargin(0.1416084);
      c1.Range(-289.7381,-191.8196,1334.643,1074.487);

        /*
          double level = 1.0;
          double contours[1];
          contours[0] = level;
          hist_limit->SetContour(1,contours);
          hist_limit->Draw("cont3c");
          hist_limit->SetLineColor(4);
          hist_limit->SetLineWidth(2);
		*/

	  TLegendEntry *legge;
	  TLegend *leg;
	  leg = new TLegend(0.4,0.55,0.7,0.85);
	  leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
	  leg->SetFillColor(0);
	  hist_limit->Draw("colz");
	  leg->Draw();


      TLatex l1;
      l1.SetTextAlign(12);
      l1.SetTextSize(0.04);
      l1.SetNDC();
      l1.DrawLatex(0.155, 0.98, "CMS Preliminary");
      l1.DrawLatex(0.7, 0.98, "20 fb^{-1} (8 TeV)");

	  c1.SaveAs("~/www/test.png");

      fout->cd();
      fout->Write();
      fout->Close();

}


