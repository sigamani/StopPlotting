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

#include "smooth.C"
#include "../stopCrossSectionsErr.h"



using namespace std;
void rootlogon();


TString savedir = "~/www/";





double return_limit(TString dir, int x, int y, int SR, TString Exp){


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

               sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsCNC_22_SC/%s/%s/ASYMPTOTIC_CLS_RESULT_S%d-N%d.root", dataset_name, SR_, x, y);

	   	       TFile* file  = new TFile(filename, "READ");  


               ifstream ifile(filename);

			   if (ifile.good()) { 

			   TTree *limittree = (TTree*)file->Get("limit");
			   double high_val = 100.;
			   TH1F* obs = new TH1F("obs","",100,0,high_val);
			   limittree->Draw("limit>>obs", "quantileExpected==-1");
               TH1F* expm1 = new TH1F("expm1","",100,0,high_val);
               limittree->Draw("limit>>expm1", "quantileExpected>0.15 && quantileExpected<0.16");
               TH1F* exp = new TH1F("exp","",100,0,high_val);
               limittree->Draw("limit>>exp", "quantileExpected==0.5");
               TH1F* expp1 = new TH1F("expp1","",100,0,high_val);
               limittree->Draw("limit>>expp1", "quantileExpected>0.83 && quantileExpected<0.84");

               double ObsSigmaP = 1 - stopCrossSectionErr(x) / 100.;
               double ObsSigmaM = 1 + stopCrossSectionErr(x) / 100.;

               if ( Exp == "Obs" )  limit =  obs->GetMean();
               if ( Exp == "ObsM" ) limit =  obs->GetMean() * ObsSigmaM;
               if ( Exp == "ObsP" ) limit =  obs->GetMean() * ObsSigmaP;
               if ( Exp == "Exp" )  limit =  exp->GetMean();
               if ( Exp == "ExpM" ) limit =  expm1->GetMean();
               if ( Exp == "ExpP" ) limit =  expp1->GetMean();



  		  	   file->Close(); return limit;

				} else return 1.1;


}




void plot_limit(TString decay_mode, TString Exp){

   TFile *fout = new TFile(decay_mode+"_"+Exp+"_CNC.root","recreate");
	
   int SR;

   TH2D *SMS = new TH2D(decay_mode+"_"+Exp,"",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMS2 = new TH2D(decay_mode+"_"+Exp,"",29,87.5, 812.5, 17, -12.5,412.5);
	
              for(int x=125; x<=800; x+=25){

                      for(int y=0; y<=375; y+=25){

                                 if (x - y > 99){

						if (decay_mode == "T2tt") {
							SR =5; 
							double limits[5] = {

							return_limit(decay_mode,x,y,1, "Exp"),
							return_limit(decay_mode,x,y,2, "Exp"),
							return_limit(decay_mode,x,y,3, "Exp"),
							return_limit(decay_mode,x,y,4, "Exp"),
							return_limit(decay_mode,x,y,5, "Exp"),
							};

						}


						if (decay_mode == "T2bw025") {
                                                        
 							SR =3;
							double limits[3] = {

							return_limit(decay_mode,x,y,1, "Exp"),
							return_limit(decay_mode,x,y,2, "Exp"),
							return_limit(decay_mode,x,y,3, "Exp")
							};                           
                                                                                     
						}

						if (decay_mode == "T2bw050") {
                                                        
							SR =4;
							double limits[4] = {

							return_limit(decay_mode,x,y,1, "Exp"),
							return_limit(decay_mode,x,y,2, "Exp"),
							return_limit(decay_mode,x,y,3, "Exp"),
							return_limit(decay_mode,x,y,4, "Exp")
							};

						}

						if (decay_mode == "T2bw075") {
                                                        
							SR =3;
							double limits[3] = {

							return_limit(decay_mode,x,y,1, "Exp"),
							return_limit(decay_mode,x,y,2, "Exp"),
							return_limit(decay_mode,x,y,3, "Exp")
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


						if ( Exp == "Obs" )  exp = 0;
						if ( Exp == "ExpM" ) exp = 1;
						if ( Exp == "Exp" )  exp = 2;
						if ( Exp == "ExpP" ) exp = 3;

        				  double limit = temp; 
								    							
						  if (mvaval+1 > 0) double limit = return_limit(decay_mode,x,y, mvaval+1, Exp);
			      		  //double limit_smooth = ReturnCleanedLimit( x, y, limit, decay_mode, false, exp);

						  if (limit < 1.0) {
							SMS->Fill(x,y, limit);
							//SMS2->Fill(x,y,mvaval+1);
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
           TAxis *data_zaxis = SMS->GetZaxis();

	   data_xaxis->SetTitle("m_{#tilde{t}} (GeV)");
	   data_yaxis->SetTitle("m_{#tilde{#chi}^{0}_{1}} (GeV)");
//	   data_zaxis->SetTitle("Best performing SR"); 
//	   data_zaxis->SetRangeUser(1,SR);


           TCanvas c1("c1","c1",800,600);
           c1.SetLeftMargin(0.1706731);
           c1.SetRightMargin(0.1983173);
           c1.SetTopMargin(0.04895105);
           c1.SetBottomMargin(0.1416084);
           c1.Range(-289.7381,-191.8196,1334.643,1074.487);
           SMS->SetMarkerSize(1.);
           SMS->SetMarkerColor(kWhite);
           SMS->Draw("COLZ TEXT");

  /*         double level = 1.0;
           double contours[1];
           contours[0] = level;
           SMS->SetContour(1,contours);
           SMS->Draw("cont3c");
           SMS->SetLineColor(kRed);
           SMS->SetLineWidth(2);
*/
	   TLegendEntry *legge;
	   TLegend *leg;
	   leg = new TLegend(0.4,0.55,0.7,0.85);
	   leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
       legge = leg->AddEntry(SMS,   "#color[2]{Expected U.L. @95\% CL}", "");
	   leg->SetFillColor(0);
	   leg->Draw();
	   SMS->Draw("colz");

	   TLatex l1;
	   l1.SetTextAlign(12);
	   l1.SetTextSize(0.04);
	   l1.SetNDC();
	   l1.DrawLatex(0.155, 0.98, "CMS Preliminary");
	   l1.DrawLatex(0.7, 0.98, "20 fb^{-1} (8 TeV)");
	  
       c1.SaveAs("~/www/"+decay_mode+"_"+Exp+".png");
       //c1.SaveAs("~/www/"+decay_mode+"_PDF.png");

      fout->cd();
      SMS->Write();
      fout->Close();	  
}
