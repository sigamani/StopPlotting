// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;
      
#include <algorithm>
#include "TColor.h"
#include "TStyle.h"
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
      
// ROOT headers
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <set>
#include <string>
#include <TLorentzVector.h>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "LHAPDF/LHAPDF.h"


// Define format of input file
#include "Reader.h" 

using namespace TMVA;

void printProgressBar(int current, int max);

int main (int argc, char *argv[])
{

  // ################################
  // ##       Open the tree        ##
  // ################################


  TFile *fin = TFile::Open(argv[1]);
  TTree* theInputTree = (TTree*) fin->Get("babyTuple");
  TFile *fout = new TFile(argv[2],"recreate");


  babyEvent myEvent;
  intermediatePointers pointers;
  InitializeBranchesForReading(theInputTree,&myEvent,&pointers);

  TTree* theOutputTree = new TTree("babyTuple","");
  InitializeBranchesForWriting(theOutputTree,&myEvent);


  vector<double> PDF_Weights_CT10, PDF_Weights_MSTW08, PDF_Weights_NNPDF21; 


  theOutputTree->Branch("PDF_Weights_CT10",     "std::vector<double>",          &(PDF_Weights_CT10));
  theOutputTree->Branch("PDF_Weights_MSTW08",   "std::vector<double>",          &(PDF_Weights_MSTW08));
  theOutputTree->Branch("PDF_Weights_NNPDF21",  "std::vector<double>",          &(PDF_Weights_NNPDF21));



  // ########################################
  // ##        Run over the events         ##
  // ########################################


  for (int i = 0; i < theInputTree->GetEntries() ; i++)
  {
  
      if (i % (theInputTree->GetEntries() / 50) == 0) 
              printProgressBar(i,theInputTree->GetEntries());

      // Read entry from input tree 
      
      ReadEvent(theInputTree,i,&pointers,&myEvent);


        if (  !((myEvent.mStop ==  atoi(argv[3]) ) && (myEvent.mNeutralino ==  atoi(argv[4])  )) ) continue;  

		

	         int genset_ = 1;
	         int genset1_ = 2;
	         int genset2_ = 3;
   	         int set_ = 4;
	         int set1_ = 5;
	         int set2_ = 6;


	    	 LHAPDF::setVerbosity(0); 
			 double pdf_weight = 0;
	     
			 LHAPDF::initPDFSetM(genset_, "CT10");
			 LHAPDF::initPDFM(genset_, 0); 

			 LHAPDF::initPDFSetM(genset1_, "MSTW2008lo68cl");
			 LHAPDF::initPDFM(genset1_, 0); 

			 LHAPDF::initPDFSetM(genset2_, "NNPDF21_lo_as_0119_100");
			 LHAPDF::initPDFM(genset2_, 0); 


	         PDF_Weights_CT10.clear();           
			 PDF_Weights_MSTW08.clear();
			 PDF_Weights_NNPDF21.clear();

			 for (int n = 1 ; n <= 52 ; n += 1){
			 LHAPDF::initPDFSetM(set_, "CT10");
			 LHAPDF::initPDFM(set_,n);


			 double fx1Q0gen = LHAPDF::xfx(genset_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton;
             double fx2Q0gen = LHAPDF::xfx(genset_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton;

             double fx1Qi = LHAPDF::xfx(set_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton; 
             double fx2Qi = LHAPDF::xfx(set_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton; 

			 if (fx1Q0gen == 0 || fx2Q0gen == 0 || fx1Qi == 0 || fx2Qi == 0) pdf_weight = 1.; 

				else  pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));
         
      		 PDF_Weights_CT10.push_back(pdf_weight);


	     }

	   

			 for (int n = 1 ; n <= 40 ; n += 1){
			 LHAPDF::initPDFSetM(set1_, "MSTW2008lo68cl");
			 LHAPDF::initPDFM(set1_,n);


			 double fx1Q0gen = LHAPDF::xfx(genset1_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton;
             double fx2Q0gen = LHAPDF::xfx(genset1_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton;

             double fx1Qi = LHAPDF::xfx(set1_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton; 
             double fx2Qi = LHAPDF::xfx(set1_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton; 
             pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));

             if (fx1Q0gen == 0 || fx2Q0gen == 0 || fx1Qi == 0 || fx2Qi == 0) pdf_weight = 1.;

                else  pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));
         
      		 PDF_Weights_MSTW08.push_back(pdf_weight);

	     }


			 for (int n = 1 ; n <= 100 ; n += 1){
			 LHAPDF::initPDFSetM(set2_, "NNPDF21_lo_as_0119_100");
			 LHAPDF::initPDFM(set2_,n);


			 double fx1Q0gen = LHAPDF::xfx(genset2_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton;
             double fx2Q0gen = LHAPDF::xfx(genset2_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton;

             double fx1Qi = LHAPDF::xfx(set2_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton; 
             double fx2Qi = LHAPDF::xfx(set2_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton; 

             if (fx1Q0gen == 0 || fx2Q0gen == 0 || fx1Qi == 0 || fx2Qi == 0) pdf_weight = 1.;

                else  pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));
         
      		 PDF_Weights_NNPDF21.push_back(pdf_weight);

	     }



        theOutputTree->Fill();

  }           

  printProgressBar(theInputTree->GetEntries(),theInputTree->GetEntries());
  cout << endl;

  theOutputTree->Write(0, TObject::kOverwrite); 


  fout->cd();
  fout->Write();
  fout->Close();

 return (0); 

}             

void printProgressBar(int current, int max)
{
    std::string bar;
    int percent = 100 * (float) current / (float) max;

    for(int i = 0; i < 50; i++)
    {
        if( i < (percent/2))       bar.replace(i,1,"=");
        else if( i == (percent/2)) bar.replace(i,1,">");
        else                       bar.replace(i,1," ");
    }

    std::cout << "  [Progress]  ";
    std::cout << "[" << bar << "] ";
    std::cout.width( 3 );
    std::cout << percent << "%     ";
    std::cout << "(" << current << " / " << max << ")" << "\r" << std::flush;
}


