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





double return_limit(TString dir, int x, int y, int SR){


   double limit;
   double shell;
   //TString SR_;

   if (dir == "T2bw025") {dataset_name = "T2bw025"; shell = 80. / 0.25;}
   if (dir == "T2bw050") {dataset_name = "T2bw050"; shell = 80. / 0.50;}
   if (dir == "T2bw075") {dataset_name = "T2bw075"; shell = 80. / 0.75;}
   if (dir == "T2tt")    {dataset_name = "T2tt";    shell = 173.;}



   if (dataset_name == "T2bw025") {	 

	   if (SR == 3)    {SR_ = "highMasses";}
	   if (SR == 2)    {SR_ = "lowMasses";}
	   if (SR == 1)    {SR_ = "offShell";}

   }


   if (dataset_name == "T2bw050") {	 

	   if (SR == 4)    {SR_ = "highDeltaM";}
	   if (SR == 3)    {SR_ = "mediumDeltaM";}
	   if (SR == 2)    {SR_ = "lowMasses";}
	   if (SR == 1)    {SR_ = "offShell";}

   }


   if (dataset_name == "T2bw075") {	 

	   if (SR == 3)    {SR_ = "highDeltaM";}
	   if (SR == 2)    {SR_ = "mediumDeltaM";}
	   if (SR == 1)    {SR_ = "lowDeltaM";}

   }


   if (dataset_name == "T2tt") {	 

	   if (SR == 5)    {SR_ = "highDeltaM";}
	   if (SR == 4)    {SR_ = "mediumDeltaM";}
	   if (SR == 3)    {SR_ = "lowDeltaM";}
	   if (SR == 2)    {SR_ = "offShellTight";}
	   if (SR == 1)    {SR_ = "offShellLoose";}

   }




  		  char shortfilename[500];
  		  char filename[500];

                  sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsCNC_9_mT100/%s/%s/ASYMPTOTIC_CLS_RESULT_S%d-N%d.root", dataset_name, SR_, x, y);


   
	         
		  TFile* file  = new TFile(filename, "READ");  
		  char* name = (char*)file->GetName();



			TTree *limittree = (TTree*)file->Get("limit");
			double high_val = 100.;
			TH1F* exp = new TH1F("exp","",100,0,high_val);
			limittree->Draw("limit>>exp", "quantileExpected==0.5");

			limit =  exp->GetMean(); 
		  	file->Close();



 return limit; 	

}




void plot_limit(TString decay_mode){

   TFile *fout = new TFile(decay_mode+"_CNC.root","recreate");
	
   int SR;

   TH2D *SMS = new TH2D(decay_mode,"",26,162.5, 812.5, 17, -12.5,412.5);
   TH2D *SMS2 = new TH2D(decay_mode,"SRs",29,87.5, 812.5, 17, -12.5,412.5);
	
              for(int x=100; x<800; x+=25){

                      for(int y=0; y<=700; y+=25){

                               if (x - y > 75){

						if (decay_mode == "T2tt") {
							SR =5; 
							double limits[5] = {

							return_limit(decay_mode,x,y,1),
							return_limit(decay_mode,x,y,2),
							return_limit(decay_mode,x,y,3),
							return_limit(decay_mode,x,y,4),
							return_limit(decay_mode,x,y,5),
							};

						}


						if (decay_mode == "T2bw025") {
                                                        SR =3;

							double limits[3] = {

							return_limit(decay_mode,x,y,1),
							return_limit(decay_mode,x,y,2),
							return_limit(decay_mode,x,y,3)
							};

						}

						if (decay_mode == "T2bw050") {
                                                        SR =4;

							double limits[4] = {

							return_limit(decay_mode,x,y,1),
							return_limit(decay_mode,x,y,2),
							return_limit(decay_mode,x,y,3),
							return_limit(decay_mode,x,y,4)
							};

						}

						if (decay_mode == "T2bw075") {
                                                        SR =3;

							double limits[3] = {

							return_limit(decay_mode,x,y,1),
							return_limit(decay_mode,x,y,2),
							return_limit(decay_mode,x,y,3)
							};

						}


						double temp = 1000.;
						int mvaval = -1;

        					// Get the maximum of each point for all MVAs
                   				for(int i=0;i<SR;i++){
        
							if( (limits[i]<temp) && limits[i] > 0. ){
		
								
								 temp    = limits[i];                     
								 mvaval  = i;
													   
																   
							}
                                                                                                                                             
						}

						//cout << "STOPLSP: "<< x << ", "<< y<< endl;
						//cout << "i: "<< mvaval + 1 << endl;  
                                                //cout << "val: "<< temp << endl; 

						  if (temp < 1.0) {
							SMS->Fill(x,y,temp);
							SMS2->Fill(x,y,mvaval+1);

						  }
				}
		}
	  }

          gStyle->SetOptStat(0);
          gStyle->SetCanvasColor(0);
          gStyle->SetPadColor(0);
          gStyle->SetMarkerStyle(15);
          gStyle->SetMarkerSize(0.25);
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

           TAxis *data_yaxis = SMS->GetYaxis();
           TAxis *data_xaxis = SMS->GetXaxis();

           SMS2->GetXaxis()->SetTitle("Mass STOP");
           SMS2->GetYaxis()->SetTitle("Mass LSP");
	   SMS2->GetZaxis()->SetTitle("Best performing SR"); 
	   SMS2->GetZaxis()->SetRangeUser(1,SR);


           TCanvas c1("c1","c1",800,600);
           c1.SetLeftMargin(0.1706731);
           c1.SetRightMargin(0.1983173);
           c1.SetTopMargin(0.04895105);
           c1.SetBottomMargin(0.1416084);
           c1.Range(-289.7381,-191.8196,1334.643,1074.487);
           SMS2->SetMarkerSize(1.);
           SMS2->SetMarkerColor(kWhite);
           SMS2->Draw("COLZ TEXT");

	   TLegendEntry *legge;
	   TLegend *leg;
	   leg = new TLegend(0.4,0.55,0.7,0.85);
	   leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
	   legge = leg->AddEntry(SMS2,   "Expected U.L. @95\% CL", "l");
	   leg->SetFillColor(0);
	   leg->Draw();
//	   SMS2->Draw("colz");
	  
           c1.SaveAs("~/www/test.png");

      fout->cd();
      fout->Write();
      fout->Close();	  
}
