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


#include "../signalRegionDefinitions.h"


using namespace std;
void rootlogon();


TString savedir = "~/www/";





double return_limit(TString dir, int x, int y, double BDTcutoffset){


   double limit = 1000.;
   double shell;


   if ( (dir == "T2bw025") && ( BDTcutoffset == -0.2) )    {dataset_name = "T2bw025_CUT-0.2";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == -0.15) )    {dataset_name = "T2bw025_CUT-0.15";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == -0.1) )    {dataset_name = "T2bw025_CUT-0.1";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == -0.05) )    {dataset_name = "T2bw025_CUT-0.05";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0) )    {dataset_name = "T2bw025_CUT0";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.05) )    {dataset_name = "T2bw025_CUT0.05";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.1) )    {dataset_name = "T2bw025_CUT0.1";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.15) )    {dataset_name = "T2bw025_CUT0.15";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.2) )    {dataset_name = "T2bw025_CUT0.2";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.25) )    {dataset_name = "T2bw025_CUT0.25";  }
   if ( (dir == "T2bw025") && ( BDTcutoffset == 0.3) )    {dataset_name = "T2bw025_CUT0.3";  }
 

   if ( (dir == "T2bw050") && ( BDTcutoffset == -0.2) )    {dataset_name = "T2bw050_CUT-0.2";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == -0.15) )    {dataset_name = "T2bw050_CUT-0.15";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == -0.1) )    {dataset_name = "T2bw050_CUT-0.1";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == -0.05) )    {dataset_name = "T2bw050_CUT-0.05";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0) )    {dataset_name = "T2bw050_CUT0";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.05) )    {dataset_name = "T2bw050_CUT0.05";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.1) )    {dataset_name = "T2bw050_CUT0.1";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.15) )    {dataset_name = "T2bw050_CUT0.15";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.2) )    {dataset_name = "T2bw050_CUT0.2";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.25) )    {dataset_name = "T2bw050_CUT0.25";  }
   if ( (dir == "T2bw050") && ( BDTcutoffset == 0.3) )    {dataset_name = "T2bw050_CUT0.3";  }
 

   if ( (dir == "T2bw075") && ( BDTcutoffset == -0.2) )    {dataset_name = "T2bw075_CUT-0.2";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == -0.15) )    {dataset_name = "T2bw075_CUT-0.15";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == -0.1) )    {dataset_name = "T2bw075_CUT-0.1";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == -0.05) )    {dataset_name = "T2bw075_CUT-0.05";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0) )    {dataset_name = "T2bw075_CUT0";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.05) )    {dataset_name = "T2bw075_CUT0.05";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.1) )    {dataset_name = "T2bw075_CUT0.1";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.15) )    {dataset_name = "T2bw075_CUT0.15";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.2) )    {dataset_name = "T2bw075_CUT0.2";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.25) )    {dataset_name = "T2bw075_CUT0.25";  }
   if ( (dir == "T2bw075") && ( BDTcutoffset == 0.3) )    {dataset_name = "T2bw075_CUT0.3";  }
 
   if ( (dir == "T2tt") && ( BDTcutoffset == -0.2) )    {dataset_name = "T2tt_CUT-0.2";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == -0.15) )    {dataset_name = "T2tt_CUT-0.15";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == -0.1) )    {dataset_name = "T2tt_CUT-0.1";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == -0.05) )    {dataset_name = "T2tt_CUT-0.05";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0) )    {dataset_name = "T2tt_CUT0";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.05) )    {dataset_name = "T2tt_CUT0.05";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.1) )    {dataset_name = "T2tt_CUT0.1";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.15) )    {dataset_name = "T2tt_CUT0.15";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.2) )    {dataset_name = "T2tt_CUT0.2";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.25) )    {dataset_name = "T2tt_CUT0.25";  }
   if ( (dir == "T2tt") && ( BDTcutoffset == 0.3) )    {dataset_name = "T2tt_CUT0.3";  }



  		  char shortfilename[500];
  		  char filename[500];

                  sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_16_UB/%s/ASYMPTOTIC_CLS_RESULT_S%d-N%d.root", dataset_name,x, y);


			  ifstream ifile(filename);

			  TFile* file  = new TFile(filename, "READ");  
			  char* name = (char*)file->GetName();


				if (file->GetListOfKeys()->Contains("limit")) { 

				TTree *limittree = (TTree*)file->Get("limit");
				double high_val = 100.;
				TH1F* exp = new TH1F("exp","",100,0,high_val);
				limittree->Draw("limit>>exp", "quantileExpected==0.5");

				limit =  exp->GetMean(); 

			
				} 

				file->Close();


 return limit; 
	
}




void plot_limit(TString decay_mode){

   TFile *fout = new TFile(decay_mode+"_BDT.root","recreate");
	

   TH2D *SMS = new TH2D(decay_mode,"",29,87.5, 812.5, 17, -12.5,412.5);
   TH2D *SMS2 = new TH2D(decay_mode,"SRs",29,87.5, 812.5, 17, -12.5,412.5);
	
            for(int x=100; x<=800; x+=25){

                      for(int y=0; y<=400; y+=25){

                               if (x - y > 99){


					double limits[10] = {

					return_limit(decay_mode,x,y,-0.2),
					return_limit(decay_mode,x,y,-0.15),
					return_limit(decay_mode,x,y,-0.1),
					return_limit(decay_mode,x,y,-0.05),
					return_limit(decay_mode,x,y,0),
					return_limit(decay_mode,x,y,0.05),
					return_limit(decay_mode,x,y,0.1),
					return_limit(decay_mode,x,y,0.15),
					return_limit(decay_mode,x,y,0.2),
					return_limit(decay_mode,x,y,0.25)
					//return_limit(decay_mode,x,y,0.3)
					};
							


					double temp = 1000.;
					int mvaval = -1;

					// Get the maximum of each point for all MVAs
           				for(int i=0;i<10;i++){

						if( (limits[i]<temp) && limits[i] > 0. ){
	
							 temp    = limits[i];                     
							 mvaval  = i;
						}
					}
							

						SMS2->Fill(x,y,mvaval+1);
						//SMS3->Fill(x,y,optimcut);
						SMS->Fill(x,y,1./temp);
					 
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


            TAxis *data_yaxis = SMS2->GetYaxis();
            TAxis *data_xaxis = SMS2->GetXaxis();
            TAxis *data_zaxis = SMS2->GetZaxis();

       	    data_xaxis->SetTitle("m_{#tilde{t}} (GeV)");
            data_yaxis->SetTitle("m_{#tilde{#chi}^{0}_{1}} (GeV)");
	 	    data_zaxis->SetTitle("Optimal BDT cut off-set"); 
            data_zaxis->SetRangeUser(1,9);


			TPaveText* key = new TPaveText( 0.2, 0.65, 0.4, 0.92, "brNDC" );
			key->SetFillColor(kWhite);
			key->SetTextSize(0.02);
			key->SetTextFont(42);
			key->AddText("1: BDT cut - 0.20");
			key->AddText("2: BDT cut - 0.15");
			key->AddText("3: BDT cut - 0.10");
			key->AddText("4: BDT cut - 0.05");
			key->AddText("5: BDT cut + 0.00");
			key->AddText("6: BDT cut + 0.05");
			key->AddText("7: BDT cut + 0.10");
			key->AddText("8: BDT cut + 0.15");
			key->AddText("9: BDT cut + 0.20");
 


           TCanvas c1("c1","c1",800,600);
           c1.SetLeftMargin(0.1706731);
           c1.SetRightMargin(0.1983173);
           c1.SetTopMargin(0.04895105);
           c1.SetBottomMargin(0.1416084);
           c1.Range(-289.7381,-191.8196,1334.643,1074.487);
           SMS2->SetMarkerSize(1.);
           SMS2->SetMarkerColor(kWhite);
           SMS2->Draw("COLZTEXT");

		   TLegendEntry *legge;
		   TLegend *leg;
	       leg = new TLegend(0.4,0.55,0.7,0.85);
		   leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
		   legge = leg->AddEntry(SMS,   "#color[2]{Expected U.L. @95\% CL}", "");
		   leg->SetFillColor(0);
		   leg->Draw();

           double level = 1.;
           double contours[1];
           contours[0] = level;
           SMS->SetContour(1,contours);
           SMS->Draw("cont3cSAME");
           SMS->SetLineColor(2);
           SMS->SetLineWidth(2); 

  	       key->Draw("same");
           c1.RedrawAxis();
           c1.SaveAs("~/www/LimitTest3/"+TString(decay_mode)+"_EXP.png");

      fout->cd();
      fout->Write();
      fout->Close();	  
}
