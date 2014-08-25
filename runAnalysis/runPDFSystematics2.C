// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;

#include <utility>
#include <algorithm>
#include "TColor.h"
#include "TStyle.h"
#include "TRandom.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include "TString.h"
#include "TPRegexp.h"
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <set>
#include <string>
#include <TLorentzVector.h>
#include <iterator>
#include <cstdlib>

// Define format and input file
#include "../selectionDefinitions.h"
#include "../cutAndCountDefinitions.h"
#include "../signalRegionDefinitions.h"

int main (int argc, char *argv[]) {


   TFile *fin = TFile::Open(argv[1]);
   TTree* theInputTree = (TTree*) fin->Get("babyTuple");
   TFile *fout = new TFile(argv[2],"recreate");

   int STOPMASS = atoi(argv[3]);
   int LSPMASS = atoi(argv[4]) ;

   TDirectory *cdtof = fout->mkdir("PDF_syst");
   cdtof->cd();    

   char hname[20];
   char htitle[80];

   for (int i = 0 ; i < theInputTree->GetEntries() ; i++){

  	    intermediatePointers pointers;
	    InitializeBranchesForReading(theInputTree,&myEvent,&pointers);


        if (string(argv[1]).find("ttbar_madgraph") != std::string::npos)    {sampleName = "ttbar_madgraph"; }
        if (string(argv[1]).find("SingleElec") != std::string::npos)        {sampleName = "SingleElec"; }
        if (string(argv[1]).find("SingleMuon") != std::string::npos)        {sampleName = "SingleMuon";}
        if (string(argv[1]).find("DoubleElec") != std::string::npos)        {sampleName = "DoubleElec";}
        if (string(argv[1]).find("DoubleMuon") != std::string::npos)        {sampleName = "DoubleMuon";}
        if (string(argv[1]).find("MuEl") != std::string::npos)              {sampleName = "MuEl";}
        if (string(argv[1]).find("T2") != std::string::npos)                {sampleType = "signal";}
        if ( (sampleName == "SingleElec") || (sampleName == "SingleMuon")
      || (sampleName == "DoubleElec") || (sampleName == "DoubleMuon")
      || (sampleName == "MuEl")) {                       sampleType = "data"; }




            double width = fabs(myEvent.mNeutralino - 1);
                if (width < 0.1) myEvent.mNeutralino = 0; // For the MLSP=0 plane   



//            if (goesInPreselectionMTtail() == true) {


                // BDT STUFF

//                    if (myEvent.isUsedInBDTTraining == 0) {
                    double weight = getWeight() * 2.;

      //              hist_BDT_output_t2bw025_R1->Fill(myEvent.BDT_output_t2bw025_R1, weight);


                        double weight_PDF = weight * myEvent.PDF_Weights_CT10.at(0);
			                        cout << weight_PDF  << endl;

  /*                      for ( int i = 0; i < 1 ; i ++){

					    TH1D* hist_BDT_output_t2bw025_R1[i];
						sprintf(hname,"h%d",i);
						sprintf(htitle,"hist for counter:%d in plane North",i);
         				hist_BDT_output_t2bw025_R1[i] = new TH1D(hname,htitle,100,-2,2);

                        double weight_PDF = weight * myEvent.PDF_Weights_CT10.at(i);

                        hist_BDT_output_t2bw025_R1[i]->Fill(myEvent.BDT_output_t2bw025_R1, weight_PDF);
						cout << weight_PDF  << endl;
                        }
*/
//					}
 
 
/*
   const Int_t nplanes = 10;
   const Int_t ncounters = 100;
   char dirname[50];
   char hname[20];
   char htitle[80];
   Int_t i,j,k;
   TDirectory *cdplane[nplanes];
   TH1F *hn[nplanes][ncounters];
   TH1F *hs[nplanes][ncounters];
   for (i=0;i<nplanes;i++) {
      sprintf(dirname,"S%dN%d",i);
      cdplane[i] = cdtof->mkdir(dirname);
      cdplane[i]->cd();
      // create counter histograms
      for (j=0;j<ncounters;j++) {
         sprintf(hname,"h%d_%dN",i,j);
         sprintf(htitle,"hist for counter:%d in plane:%d North",j,i);
         hn[i][j] = new TH1F(hname,htitle,100,0,100);
         sprintf(hname,"h%d_%dS",i,j);
         sprintf(htitle,"hist for counter:%d in plane:%d South",j,i);
         hs[i][j] = new TH1F(hname,htitle,100,0,100);
      }
      cdtof->cd();  
   }

   TRandom r;
   for (i=0;i<nplanes;i++) {
      cdplane[i]->cd();
      for (j=0;j<ncounters;j++) {
         for (k=0;k<100;k++) {
            hn[i][j]->Fill(100*r.Rndm(),i+j);
            hs[i][j]->Fill(100*r.Rndm(),i+j+k);
         }
      }
   }

*/
//}

}
   fout->Write();
   delete fout;
}

