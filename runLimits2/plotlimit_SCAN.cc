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

                  sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_16/%s/ASYMPTOTIC_CLS_RESULT_S%d-N%d.root", dataset_name,x, y);


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
	
            for(int x=100; x<800; x+=25){

                      for(int y=0; y<=400; y+=25){

                               if (x - y > 99){


					double limits[11] = {

					return_limit(decay_mode,x,y,-0.2),
					return_limit(decay_mode,x,y,-0.15),
					return_limit(decay_mode,x,y,-0.1),
					return_limit(decay_mode,x,y,-0.05),
					return_limit(decay_mode,x,y,0),
					return_limit(decay_mode,x,y,0.05),
					return_limit(decay_mode,x,y,0.1),
					return_limit(decay_mode,x,y,0.15),
					return_limit(decay_mode,x,y,0.2),
					return_limit(decay_mode,x,y,0.25),
					return_limit(decay_mode,x,y,0.3)
					};
							


					double temp = 1000.;
					int mvaval = -1;

					// Get the maximum of each point for all MVAs
           				for(int i=0;i<11;i++){

						if( (limits[i]<temp) && limits[i] > 0. ){
	
							 temp    = limits[i];                     
							 mvaval  = i;
						}
					}
							

					//	cout << temp << endl;
					  if ( temp < 1.0 ) {
						SMS->Fill(x,y,temp);
						SMS2->Fill(x,y,mvaval+1);
					//	SMS3->Fill(x,y,optimcut);

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
		   SMS2->GetZaxis()->SetTitle("Optimal BDT cut off-set"); 

//	   SMS->GetZaxis()->SetRangeUser(1,12);
 

	   TPaveText* key = new TPaveText( 0.6, 0.65, 0.8, 0.92, "brNDC" );
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
           SMS2->Draw("COLZ TEXT");

  	   key->Draw("same");
           c1.RedrawAxis();
           c1.SaveAs("~/www/"+TString(decay_mode)+"_P.png");

      fout->cd();
      fout->Write();
      fout->Close();	  
}
