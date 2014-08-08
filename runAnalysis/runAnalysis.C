// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;

#include <utility>
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
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <set>
#include <string>
#include <TLorentzVector.h>
#include "LHAPDF/LHAPDF.h" 
#include <iterator>
#include <cstdlib>

// Define format and input file
#include "../selectionDefinitions.h" 
#include "../cutAndCountDefinitions.h" 
#include "../signalRegionDefinitions.h" 





// ###################
// #  Main function  #
// ###################

int main (int argc, char *argv[])
{

   //gSystem->Load("LHAPDF/lib/libLHAPDF.so");

  // ################################
  // ##       Open the tree        ##
  // ################################



   TFile *fin = TFile::Open(argv[1]);
   TTree* theInputTree = (TTree*) fin->Get("babyTuple"); 
   TFile *fout = new TFile(argv[2],"recreate");


   intermediatePointers pointers;
   InitializeBranchesForReading(theInputTree,&myEvent,&pointers);
     

   char name0[100], title0[100];
   char name00[100], title00[100];
   char name000[100], title000[100];

   char name1[100], title1[100];
   char name2[200], title2[200];
   char name3[300], title3[300];
   char name4[400], title4[400];
   char name5[500], title5[500];
   char name7[500], title7[500];
   char name8[500], title8[500];
   char name9[500], title9[500];
   char name10[500], title10[500];
   char name11[500], title11[500];
   char name12[500], title12[500];
   char name13[500], title13[500];
   char name14[500], title14[500];
   char name15[500], title15[500];
   char name16[500], title16[500];


   char name1JESUp[100], title1JESUp[100];
   char name2JESUp[200], title2JESUp[200];
   char name3JESUp[300], title3JESUp[300];
   char name4JESUp[400], title4JESUp[400];
   char name5JESUp[500], title5JESUp[500];
   char name7JESUp[500], title7JESUp[500];
   char name8JESUp[500], title8JESUp[500];
   char name9JESUp[500], title9JESUp[500];
   char name10JESUp[500], title10JESUp[500];
   char name11JESUp[500], title11JESUp[500];
   char name12JESUp[500], title12JESUp[500];
   char name13JESUp[500], title13JESUp[500];
   char name14JESUp[500], title14JESUp[500];
   char name15JESUp[500], title15JESUp[500];
   char name16JESUp[500], title16JESUp[500];


   char name1JESDown[100], title1JESDown[100];
   char name2JESDown[200], title2JESDown[200];
   char name3JESDown[300], title3JESDown[300];
   char name4JESDown[400], title4JESDown[400];
   char name5JESDown[500], title5JESDown[500];
   char name7JESDown[500], title7JESDown[500];
   char name8JESDown[500], title8JESDown[500];
   char name9JESDown[500], title9JESDown[500];
   char name10JESDown[500], title10JESDown[500];
   char name11JESDown[500], title11JESDown[500];
   char name12JESDown[500], title12JESDown[500];
   char name13JESDown[500], title13JESDown[500];
   char name14JESDown[500], title14JESDown[500];
   char name15JESDown[500], title15JESDown[500];
   char name16JESDown[500], title16JESDown[500];

   char name1BVetoBCUp[100], title1BVetoBCUp[100];
   char name1BVetoBCDown[100], title1BVetoBCDown[100];
   char name1BVetoLightUp[100], title1BVetoLightUp[100];
   char name1BVetoLightDown[100], title1BVetoLightDown[100];

   char name2BVetoBCUp[100], title2BVetoBCUp[100];
   char name2BVetoBCDown[100], title2BVetoBCDown[100];
   char name2BVetoLightUp[100], title2BVetoLightUp[100];
   char name2BVetoLightDown[100], title2BVetoLightDown[100];

   char name3BVetoBCUp[100], title3BVetoBCUp[100];
   char name3BVetoBCDown[100], title3BVetoBCDown[100];
   char name3BVetoLightUp[100], title3BVetoLightUp[100];
   char name3BVetoLightDown[100], title3BVetoLightDown[100];

   char name4BVetoBCUp[100], title4BVetoBCUp[100];
   char name4BVetoBCDown[100], title4BVetoBCDown[100];
   char name4BVetoLightUp[100], title4BVetoLightUp[100];
   char name4BVetoLightDown[100], title4BVetoLightDown[100];

   char name5BVetoBCUp[100], title5BVetoBCUp[100];
   char name5BVetoBCDown[100], title5BVetoBCDown[100];
   char name5BVetoLightUp[100], title5BVetoLightUp[100];
   char name5BVetoLightDown[100], title5BVetoLightDown[100];

   char name7BVetoBCUp[100], title7BVetoBCUp[100];
   char name7BVetoBCDown[100], title7BVetoBCDown[100];
   char name7BVetoLightUp[100], title7BVetoLightUp[100];
   char name7BVetoLightDown[100], title7BVetoLightDown[100];

   char name8BVetoBCUp[100], title8BVetoBCUp[100];
   char name8BVetoBCDown[100], title8BVetoBCDown[100];
   char name8BVetoLightUp[100], title8BVetoLightUp[100];
   char name8BVetoLightDown[100], title8BVetoLightDown[100];

   char name9BVetoBCUp[100], title9BVetoBCUp[100];
   char name9BVetoBCDown[100], title9BVetoBCDown[100];
   char name9BVetoLightUp[100], title9BVetoLightUp[100];
   char name9BVetoLightDown[100], title9BVetoLightDown[100];

   char name10BVetoBCUp[100], title10BVetoBCUp[100];
   char name10BVetoBCDown[100], title10BVetoBCDown[100];
   char name10BVetoLightUp[100], title10BVetoLightUp[100];
   char name10BVetoLightDown[100], title10BVetoLightDown[100];

   char name11BVetoBCUp[100], title11BVetoBCUp[100];
   char name11BVetoBCDown[100], title11BVetoBCDown[100];
   char name11BVetoLightUp[100], title11BVetoLightUp[100];
   char name11BVetoLightDown[100], title11BVetoLightDown[100];

   char name12BVetoBCUp[100], title12BVetoBCUp[100];
   char name12BVetoBCDown[100], title12BVetoBCDown[100];
   char name12BVetoLightUp[100], title12BVetoLightUp[100];
   char name12BVetoLightDown[100], title12BVetoLightDown[100];

   char name13BVetoBCUp[100], title13BVetoBCUp[100];
   char name13BVetoBCDown[100], title13BVetoBCDown[100];
   char name13BVetoLightUp[100], title13BVetoLightUp[100];
   char name13BVetoLightDown[100], title13BVetoLightDown[100];

   char name14BVetoBCUp[100], title14BVetoBCUp[100];
   char name14BVetoBCDown[100], title14BVetoBCDown[100];
   char name14BVetoLightUp[100], title14BVetoLightUp[100];
   char name14BVetoLightDown[100], title14BVetoLightDown[100];

   char name15BVetoBCUp[100], title15BVetoBCUp[100];
   char name15BVetoBCDown[100], title15BVetoBCDown[100];
   char name15BVetoLightUp[100], title15BVetoLightUp[100];
   char name15BVetoLightDown[100], title15BVetoLightDown[100];

   char name16BVetoBCUp[100], title16BVetoBCUp[100];
   char name16BVetoBCDown[100], title16BVetoBCDown[100];
   char name16BVetoLightUp[100], title16BVetoLightUp[100];
   char name16BVetoLightDown[100], title16BVetoLightDown[100];

   // BDT stuff

   char name17_RAW[500], title17_RAW[500];
   char name18_RAW[500], title18_RAW[500];
   char name19_RAW[500], title19_RAW[500];
   char name20_RAW[500], title20_RAW[500];
   char name21_RAW[500], title21_RAW[500];
   char name22_RAW[500], title22_RAW[500];
   char name23_RAW[500], title23_RAW[500];
   char name24_RAW[500], title24_RAW[500];
   char name25_RAW[500], title25_RAW[500];
   char name26_RAW[500], title26_RAW[500];
   char name27_RAW[500], title27_RAW[500];
   char name28_RAW[500], title28_RAW[500];
   char name29_RAW[500], title29_RAW[500];
   char name30_RAW[500], title30_RAW[500];
   char name31_RAW[500], title31_RAW[500];
   char name32_RAW[500], title32_RAW[500];

   char name17[500], title17[500];
   char name18[500], title18[500];
   char name19[500], title19[500];
   char name20[500], title20[500];
   char name21[500], title21[500];
   char name22[500], title22[500];
   char name23[500], title23[500];
   char name24[500], title24[500];
   char name25[500], title25[500];
   char name26[500], title26[500];
   char name27[500], title27[500];
   char name28[500], title28[500];
   char name29[500], title29[500];
   char name30[500], title30[500];
   char name31[500], title31[500];
   char name32[500], title32[500];


   char name17JESUp[500], title17JESUp[500];
   char name17JESDown[500], title17JESDown[500];
   char name18JESUp[500], title18JESUp[500];
   char name18JESDown[500], title18JESDown[500];
   char name19JESUp[500], title19JESUp[500];
   char name19JESDown[500], title19JESDown[500];
   char name20JESUp[500], title20JESUp[500];
   char name20JESDown[500], title20JESDown[500];
   char name21JESUp[500], title21JESUp[500];
   char name21JESDown[500], title21JESDown[500];
   char name22JESUp[500], title22JESUp[500];
   char name22JESDown[500], title22JESDown[500];
   char name23JESUp[500], title23JESUp[500];
   char name23JESDown[500], title23JESDown[500];
   char name24JESUp[500], title24JESUp[500];
   char name24JESDown[500], title24JESDown[500];
   char name25JESUp[500], title25JESUp[500];
   char name25JESDown[500], title25JESDown[500];
   char name26JESUp[500], title26JESUp[500];
   char name26JESDown[500], title26JESDown[500];
   char name27JESUp[500], title27JESUp[500];
   char name27JESDown[500], title27JESDown[500];
   char name28JESUp[500], title28JESUp[500];
   char name28JESDown[500], title28JESDown[500];
   char name29JESUp[500], title29JESUp[500];
   char name29JESDown[500], title29JESDown[500];
   char name30JESUp[500], title30JESUp[500];
   char name30JESDown[500], title30JESDown[500];
   char name31JESUp[500], title31JESUp[500];
   char name31JESDown[500], title31JESDown[500];
   char name32JESUp[500], title32JESUp[500];
   char name32JESDown[500], title32JESDown[500];


   char name17BVetoBCUp[500], title17BVetoBCUp[500];
   char name17BVetoBCDown[500], title17BVetoBCDown[500];
   char name17BVetoLightUp[500], title17BVetoLightUp[500];
   char name17BVetoLightDown[500], title17BVetoLightDown[500];

   char name18BVetoBCUp[500], title18BVetoBCUp[500];
   char name18BVetoBCDown[500], title18BVetoBCDown[500];
   char name18BVetoLightUp[500], title18BVetoLightUp[500];
   char name18BVetoLightDown[500], title18BVetoLightDown[500];

   char name19BVetoBCUp[500], title19BVetoBCUp[500];
   char name19BVetoBCDown[500], title19BVetoBCDown[500];
   char name19BVetoLightUp[500], title19BVetoLightUp[500];
   char name19BVetoLightDown[500], title19BVetoLightDown[500];

   char name20BVetoBCUp[500], title20BVetoBCUp[500];
   char name20BVetoBCDown[500], title20BVetoBCDown[500];
   char name20BVetoLightUp[500], title20BVetoLightUp[500];
   char name20BVetoLightDown[500], title20BVetoLightDown[500];

   char name21BVetoBCUp[500], title21BVetoBCUp[500];
   char name21BVetoBCDown[500], title21BVetoBCDown[500];
   char name21BVetoLightUp[500], title21BVetoLightUp[500];
   char name21BVetoLightDown[500], title21BVetoLightDown[500];

   char name22BVetoBCUp[500], title22BVetoBCUp[500];
   char name22BVetoBCDown[500], title22BVetoBCDown[500];
   char name22BVetoLightUp[500], title22BVetoLightUp[500];
   char name22BVetoLightDown[500], title22BVetoLightDown[500];

   char name23BVetoBCUp[500], title23BVetoBCUp[500];
   char name23BVetoBCDown[500], title23BVetoBCDown[500];
   char name23BVetoLightUp[500], title23BVetoLightUp[500];
   char name23BVetoLightDown[500], title23BVetoLightDown[500];

   char name24BVetoBCUp[500], title24BVetoBCUp[500];
   char name24BVetoBCDown[500], title24BVetoBCDown[500];
   char name24BVetoLightUp[500], title24BVetoLightUp[500];
   char name24BVetoLightDown[500], title24BVetoLightDown[500];

   char name25BVetoBCUp[500], title25BVetoBCUp[500];
   char name25BVetoBCDown[500], title25BVetoBCDown[500];
   char name25BVetoLightUp[500], title25BVetoLightUp[500];
   char name25BVetoLightDown[500], title25BVetoLightDown[500];


   char name26BVetoBCUp[500], title26BVetoBCUp[500];
   char name26BVetoBCDown[500], title26BVetoBCDown[500];
   char name26BVetoLightUp[500], title26BVetoLightUp[500];
   char name26BVetoLightDown[500], title26BVetoLightDown[500];

   char name27BVetoBCUp[500], title27BVetoBCUp[500];
   char name27BVetoBCDown[500], title27BVetoBCDown[500];
   char name27BVetoLightUp[500], title27BVetoLightUp[500];
   char name27BVetoLightDown[500], title27BVetoLightDown[500];

   char name28BVetoBCUp[500], title28BVetoBCUp[500];
   char name28BVetoBCDown[500], title28BVetoBCDown[500];
   char name28BVetoLightUp[500], title28BVetoLightUp[500];
   char name28BVetoLightDown[500], title28BVetoLightDown[500];


   char name29BVetoBCUp[500], title29BVetoBCUp[500];
   char name29BVetoBCDown[500], title29BVetoBCDown[500];
   char name29BVetoLightUp[500], title29BVetoLightUp[500];
   char name29BVetoLightDown[500], title29BVetoLightDown[500];


   char name30BVetoBCUp[500], title30BVetoBCUp[500];
   char name30BVetoBCDown[500], title30BVetoBCDown[500];
   char name30BVetoLightUp[500], title30BVetoLightUp[500];
   char name30BVetoLightDown[500], title30BVetoLightDown[500];


   char name31BVetoBCUp[500], title31BVetoBCUp[500];
   char name31BVetoBCDown[500], title31BVetoBCDown[500];
   char name31BVetoLightUp[500], title31BVetoLightUp[500];
   char name31BVetoLightDown[500], title31BVetoLightDown[500];


   char name32BVetoBCUp[500], title32BVetoBCUp[500];
   char name32BVetoBCDown[500], title32BVetoBCDown[500];
   char name32BVetoLightUp[500], title32BVetoLightUp[500];
   char name32BVetoLightDown[500], title32BVetoLightDown[500];


   TH1D* Events_NGenSignal;
   TH1D* Events_NSignal;
   TH1D* Events_Preselection;

   TH1D* Events_T2tt_offShellLoose ; 
   TH1D* Events_T2tt_offShellTight ; 
   TH1D* Events_T2tt_lowDeltaM ; 
   TH1D* Events_T2tt_mediumDeltaM ; 
   TH1D* Events_T2tt_highDeltaM ; 

   TH1D* Events_T2bw025_offShell;
   TH1D* Events_T2bw025_lowMasses; 
   TH1D* Events_T2bw025_highMasses;

   TH1D* Events_T2bw050_offShell;
   TH1D* Events_T2bw050_lowMasses;
   TH1D* Events_T2bw050_mediumDeltaM;
   TH1D* Events_T2bw050_highDeltaM;

   TH1D* Events_T2bw075_lowDeltaM;
   TH1D* Events_T2bw075_mediumDeltaM;
   TH1D* Events_T2bw075_highDeltaM;


   TH1D* hist_BDT_output_t2bw025_R1_RAW;
   TH1D* hist_BDT_output_t2bw025_R3_RAW;
   TH1D* hist_BDT_output_t2bw025_R4_RAW;
   TH1D* hist_BDT_output_t2bw025_R6_RAW;

   TH1D* hist_BDT_output_t2bw050_R1_RAW;
   TH1D* hist_BDT_output_t2bw050_R3_RAW;
   TH1D* hist_BDT_output_t2bw050_R4_RAW;
   TH1D* hist_BDT_output_t2bw050_R5_RAW;
   TH1D* hist_BDT_output_t2bw050_R6_RAW;

   TH1D* hist_BDT_output_t2bw075_R1_RAW;
   TH1D* hist_BDT_output_t2bw075_R2_RAW;
   TH1D* hist_BDT_output_t2bw075_R3_RAW;
   TH1D* hist_BDT_output_t2bw075_R5_RAW;

   TH1D* hist_BDT_output_t2tt_R1_RAW;
   TH1D* hist_BDT_output_t2tt_R2_RAW;
   TH1D* hist_BDT_output_t2tt_R5_RAW;

 
   TH1D* hist_BDT_output_t2bw025_R1;
   TH1D* hist_BDT_output_t2bw025_R3;
   TH1D* hist_BDT_output_t2bw025_R4;
   TH1D* hist_BDT_output_t2bw025_R6;

   TH1D* hist_BDT_output_t2bw050_R1;
   TH1D* hist_BDT_output_t2bw050_R3;
   TH1D* hist_BDT_output_t2bw050_R4;
   TH1D* hist_BDT_output_t2bw050_R5;
   TH1D* hist_BDT_output_t2bw050_R6;

   TH1D* hist_BDT_output_t2bw075_R1;
   TH1D* hist_BDT_output_t2bw075_R2;
   TH1D* hist_BDT_output_t2bw075_R3;
   TH1D* hist_BDT_output_t2bw075_R5;

   TH1D* hist_BDT_output_t2tt_R1;
   TH1D* hist_BDT_output_t2tt_R2;
   TH1D* hist_BDT_output_t2tt_R5;


   // BVETO systematics
  
   TH1D* Events_T2tt_offShellLooseBVetoBCUp ; 
   TH1D* Events_T2tt_offShellLooseBVetoBCDown ; 
   TH1D* Events_T2tt_offShellLooseBVetoLightUp ; 
   TH1D* Events_T2tt_offShellLooseBVetoLightDown ; 

   TH1D* Events_T2tt_offShellTightBVetoBCUp ;        
   TH1D* Events_T2tt_offShellTightBVetoBCDown ;      
   TH1D* Events_T2tt_offShellTightBVetoLightUp ;     
   TH1D* Events_T2tt_offShellTightBVetoLightDown ;   


   TH1D* Events_T2tt_lowDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_lowDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_lowDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_lowDeltaMBVetoLightDown ;   


   TH1D* Events_T2tt_mediumDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_mediumDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_mediumDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_mediumDeltaMBVetoLightDown ;   

   TH1D* Events_T2tt_highDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_highDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_highDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_highDeltaMBVetoLightDown ;   


   TH1D* Events_T2bw025_offShellBVetoBCUp ;      
   TH1D* Events_T2bw025_offShellBVetoBCDown ;   
   TH1D* Events_T2bw025_offShellBVetoLightUp ;  
   TH1D* Events_T2bw025_offShellBVetoLightDown ;

   TH1D* Events_T2bw025_lowMassesBVetoBCUp ;      
   TH1D* Events_T2bw025_lowMassesBVetoBCDown ;    
   TH1D* Events_T2bw025_lowMassesBVetoLightUp ;   
   TH1D* Events_T2bw025_lowMassesBVetoLightDown ; 

   TH1D* Events_T2bw025_highMassesBVetoBCUp ;      
   TH1D* Events_T2bw025_highMassesBVetoBCDown ;   
   TH1D* Events_T2bw025_highMassesBVetoLightUp ;  
   TH1D* Events_T2bw025_highMassesBVetoLightDown ;

   TH1D* Events_T2bw050_offShellBVetoBCUp ;     
   TH1D* Events_T2bw050_offShellBVetoBCDown ;   
   TH1D* Events_T2bw050_offShellBVetoLightUp ;  
   TH1D* Events_T2bw050_offShellBVetoLightDown ;

   TH1D* Events_T2bw050_lowMassesBVetoBCUp ;     
   TH1D* Events_T2bw050_lowMassesBVetoBCDown ;   
   TH1D* Events_T2bw050_lowMassesBVetoLightUp ;  
   TH1D* Events_T2bw050_lowMassesBVetoLightDown ;

   TH1D* Events_T2bw050_mediumDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw050_mediumDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw050_mediumDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw050_mediumDeltaMBVetoLightDown ;

   TH1D* Events_T2bw050_highDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw050_highDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw050_highDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw050_highDeltaMBVetoLightDown ;

   TH1D* Events_T2bw075_lowDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw075_lowDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw075_lowDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw075_lowDeltaMBVetoLightDown ;

   TH1D* Events_T2bw075_mediumDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw075_mediumDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw075_mediumDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw075_mediumDeltaMBVetoLightDown ;

   TH1D* Events_T2bw075_highDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw075_highDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw075_highDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw075_highDeltaMBVetoLightDown ;


 
   TH1D* hist_BDT_output_t2bw025_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R4BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R4BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R4BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R4BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R6BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R6BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R6BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R6BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R4BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R4BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R4BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R4BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R5BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R5BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R5BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R5BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R6BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R6BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R6BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R6BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R2BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R2BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R2BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R2BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R5BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R5BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R5BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R5BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R2BVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R2BVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R2BVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R2BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R5BVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R5BVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R5BVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R5BVetoLightDown;

   // JES systematics
   

   TH1D* Events_T2tt_offShellLooseJESUp ; 
   TH1D* Events_T2tt_offShellTightJESUp ; 
   TH1D* Events_T2tt_lowDeltaMJESUp ; 
   TH1D* Events_T2tt_mediumDeltaMJESUp ; 
   TH1D* Events_T2tt_highDeltaMJESUp ; 

   TH1D* Events_T2bw025_offShellJESUp;
   TH1D* Events_T2bw025_lowMassesJESUp; 
   TH1D* Events_T2bw025_highMassesJESUp;

   TH1D* Events_T2bw050_offShellJESUp;
   TH1D* Events_T2bw050_lowMassesJESUp;
   TH1D* Events_T2bw050_mediumDeltaMJESUp;
   TH1D* Events_T2bw050_highDeltaMJESUp;

   TH1D* Events_T2bw075_lowDeltaMJESUp;
   TH1D* Events_T2bw075_mediumDeltaMJESUp;
   TH1D* Events_T2bw075_highDeltaMJESUp;


   TH1D* Events_T2tt_offShellLooseJESDown ; 
   TH1D* Events_T2tt_offShellTightJESDown ; 
   TH1D* Events_T2tt_lowDeltaMJESDown ; 
   TH1D* Events_T2tt_mediumDeltaMJESDown ; 
   TH1D* Events_T2tt_highDeltaMJESDown ; 

   TH1D* Events_T2bw025_offShellJESDown;
   TH1D* Events_T2bw025_lowMassesJESDown; 
   TH1D* Events_T2bw025_highMassesJESDown;

   TH1D* Events_T2bw050_offShellJESDown;
   TH1D* Events_T2bw050_lowMassesJESDown;
   TH1D* Events_T2bw050_mediumDeltaMJESDown;
   TH1D* Events_T2bw050_highDeltaMJESDown;

   TH1D* Events_T2bw075_lowDeltaMJESDown;
   TH1D* Events_T2bw075_mediumDeltaMJESDown;
   TH1D* Events_T2bw075_highDeltaMJESDown;



   TH1D* hist_BDT_output_t2bw025_R1JESUp;
   TH1D* hist_BDT_output_t2bw025_R3JESUp;
   TH1D* hist_BDT_output_t2bw025_R4JESUp;
   TH1D* hist_BDT_output_t2bw025_R6JESUp;

   TH1D* hist_BDT_output_t2bw050_R1JESUp;
   TH1D* hist_BDT_output_t2bw050_R3JESUp;
   TH1D* hist_BDT_output_t2bw050_R4JESUp;
   TH1D* hist_BDT_output_t2bw050_R5JESUp;
   TH1D* hist_BDT_output_t2bw050_R6JESUp;

   TH1D* hist_BDT_output_t2bw075_R1JESUp;
   TH1D* hist_BDT_output_t2bw075_R2JESUp;
   TH1D* hist_BDT_output_t2bw075_R3JESUp;
   TH1D* hist_BDT_output_t2bw075_R5JESUp;

   TH1D* hist_BDT_output_t2tt_R1JESUp;
   TH1D* hist_BDT_output_t2tt_R2JESUp;
   TH1D* hist_BDT_output_t2tt_R5JESUp;

   TH1D* hist_BDT_output_t2bw025_R1JESDown;
   TH1D* hist_BDT_output_t2bw025_R3JESDown;
   TH1D* hist_BDT_output_t2bw025_R4JESDown;
   TH1D* hist_BDT_output_t2bw025_R6JESDown;

   TH1D* hist_BDT_output_t2bw050_R1JESDown;
   TH1D* hist_BDT_output_t2bw050_R3JESDown;
   TH1D* hist_BDT_output_t2bw050_R4JESDown;
   TH1D* hist_BDT_output_t2bw050_R5JESDown;
   TH1D* hist_BDT_output_t2bw050_R6JESDown;

   TH1D* hist_BDT_output_t2bw075_R1JESDown;
   TH1D* hist_BDT_output_t2bw075_R2JESDown;
   TH1D* hist_BDT_output_t2bw075_R3JESDown;
   TH1D* hist_BDT_output_t2bw075_R5JESDown;

   TH1D* hist_BDT_output_t2tt_R1JESDown;
   TH1D* hist_BDT_output_t2tt_R2JESDown;
   TH1D* hist_BDT_output_t2tt_R5JESDown;

   int STOPMASS = atoi(argv[3]);
   int LSPMASS = atoi(argv[4]);

//   if (LSPMASS == 1) LSPMASS = 0;

   sprintf(name0,"Events_NGenSignal_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title0,"Events_NGenSignal_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name000,"Events_NSignal_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title000,"Events_NSignal_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name00,"Events_Preselection_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title00,"Events_Preselection_S%i_N%i", STOPMASS, LSPMASS);
 
   sprintf(name1,"Events_T2tt_offShellLoose_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1,"Events_T2tt_offShellLoose_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2,"Events_T2tt_offShellTight_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2,"Events_T2tt_offShellTight_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3,"Events_T2tt_lowDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3,"Events_T2tt_lowDeltaM_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4,"Events_T2tt_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4,"Events_T2tt_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5,"Events_T2tt_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5,"Events_T2tt_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name7,"Events_T2bw025_offShell_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7,"Events_T2bw025_offShell_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8,"Events_T2bw025_lowMasses_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8,"Events_T2bw025_lowMasses_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9,"Events_T2bw025_highMasses_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9,"Events_T2bw025_highMasses_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name10,"Events_T2bw050_offShell_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10,"Events_T2bw050_offShell_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11,"Events_T2bw050_lowMasses_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11,"Events_T2bw050_lowMasses_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12,"Events_T2bw050_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12,"Events_T2bw050_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13,"Events_T2bw050_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13,"Events_T2bw050_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name14,"Events_T2bw075_lowDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14,"Events_T2bw075_lowDeltaM_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15,"Events_T2bw075_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15,"Events_T2bw075_mediumDeltaM_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16,"Events_T2bw075_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16,"Events_T2bw075_highDeltaM_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name17_RAW,"hist_BDT_output_t2bw025_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17_RAW,"hist_BDT_output_t2bw025_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name18_RAW,"hist_BDT_output_t2bw025_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18_RAW,"hist_BDT_output_t2bw025_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19_RAW,"hist_BDT_output_t2bw025_R4_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19_RAW,"hist_BDT_output_t2bw025_R4_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20_RAW,"hist_BDT_output_t2bw025_R6_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20_RAW,"hist_BDT_output_t2bw025_R6_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21_RAW,"hist_BDT_output_t2bw050_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21_RAW,"hist_BDT_output_t2bw050_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22_RAW,"hist_BDT_output_t2bw050_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22_RAW,"hist_BDT_output_t2bw050_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23_RAW,"hist_BDT_output_t2bw050_R4_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23_RAW,"hist_BDT_output_t2bw050_R4_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24_RAW,"hist_BDT_output_t2bw050_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24_RAW,"hist_BDT_output_t2bw050_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25_RAW,"hist_BDT_output_t2bw050_R6_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25_RAW,"hist_BDT_output_t2bw050_R6_RAW_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name26_RAW,"hist_BDT_output_t2bw075_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26_RAW,"hist_BDT_output_t2bw075_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27_RAW,"hist_BDT_output_t2bw075_R2_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27_RAW,"hist_BDT_output_t2bw075_R2_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28_RAW,"hist_BDT_output_t2bw075_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28_RAW,"hist_BDT_output_t2bw075_R3_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29_RAW,"hist_BDT_output_t2bw075_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29_RAW,"hist_BDT_output_t2bw075_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name30_RAW,"hist_BDT_output_t2tt_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30_RAW,"hist_BDT_output_t2tt_R1_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31_RAW,"hist_BDT_output_t2tt_R2_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31_RAW,"hist_BDT_output_t2tt_R2_RAW_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32_RAW,"hist_BDT_output_t2tt_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32_RAW,"hist_BDT_output_t2tt_R5_RAW_S%i_N%i", STOPMASS, LSPMASS);



   sprintf(name17,"hist_BDT_output_t2bw025_R1_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17,"hist_BDT_output_t2bw025_R1_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name18,"hist_BDT_output_t2bw025_R3_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18,"hist_BDT_output_t2bw025_R3_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19,"hist_BDT_output_t2bw025_R4_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19,"hist_BDT_output_t2bw025_R4_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20,"hist_BDT_output_t2bw025_R6_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20,"hist_BDT_output_t2bw025_R6_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21,"hist_BDT_output_t2bw050_R1_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21,"hist_BDT_output_t2bw050_R1_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22,"hist_BDT_output_t2bw050_R3_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22,"hist_BDT_output_t2bw050_R3_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23,"hist_BDT_output_t2bw050_R4_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23,"hist_BDT_output_t2bw050_R4_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24,"hist_BDT_output_t2bw050_R5_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24,"hist_BDT_output_t2bw050_R5_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25,"hist_BDT_output_t2bw050_R6_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25,"hist_BDT_output_t2bw050_R6_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name26,"hist_BDT_output_t2bw075_R1_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26,"hist_BDT_output_t2bw075_R1_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27,"hist_BDT_output_t2bw075_R2_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27,"hist_BDT_output_t2bw075_R2_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28,"hist_BDT_output_t2bw075_R3_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28,"hist_BDT_output_t2bw075_R3_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29,"hist_BDT_output_t2bw075_R5_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29,"hist_BDT_output_t2bw075_R5_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name30,"hist_BDT_output_t2tt_R1_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30,"hist_BDT_output_t2tt_R1_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31,"hist_BDT_output_t2tt_R2_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31,"hist_BDT_output_t2tt_R2_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32,"hist_BDT_output_t2tt_R5_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32,"hist_BDT_output_t2tt_R5_S%i_N%i", STOPMASS, LSPMASS);



   sprintf(name1BVetoBCUp,"Events_T2tt_offShellLooseBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1BVetoBCUp,"Events_T2tt_offShellLooseBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name1BVetoBCDown,"Events_T2tt_offShellLooseBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1BVetoBCDown,"Events_T2tt_offShellLooseBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name1BVetoLightUp,"Events_T2tt_offShellLooseBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1BVetoLightUp,"Events_T2tt_offShellLooseBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name1BVetoLightDown,"Events_T2tt_offShellLooseBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1BVetoLightDown,"Events_T2tt_offShellLooseBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name2BVetoBCUp,"Events_T2tt_offShellTightBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2BVetoBCUp,"Events_T2tt_offShellTightBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2BVetoBCDown,"Events_T2tt_offShellTightBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2BVetoBCDown,"Events_T2tt_offShellTightBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2BVetoLightUp,"Events_T2tt_offShellTightBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2BVetoLightUp,"Events_T2tt_offShellTightBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2BVetoLightDown,"Events_T2tt_offShellTightBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2BVetoLightDown,"Events_T2tt_offShellTightBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3BVetoBCUp,"Events_T2tt_lowDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3BVetoBCUp,"Events_T2tt_lowDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3BVetoBCDown,"Events_T2tt_lowDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3BVetoBCDown,"Events_T2tt_lowDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3BVetoLightUp,"Events_T2tt_lowDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3BVetoLightUp,"Events_T2tt_lowDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3BVetoLightDown,"Events_T2tt_lowDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3BVetoLightDown,"Events_T2tt_lowDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4BVetoBCUp,"Events_T2tt_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4BVetoBCUp,"Events_T2tt_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4BVetoBCDown,"Events_T2tt_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4BVetoBCDown,"Events_T2tt_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4BVetoLightUp,"Events_T2tt_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4BVetoLightUp,"Events_T2tt_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4BVetoLightDown,"Events_T2tt_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4BVetoLightDown,"Events_T2tt_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5BVetoBCUp,"Events_T2tt_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5BVetoBCUp,"Events_T2tt_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5BVetoBCDown,"Events_T2tt_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5BVetoBCDown,"Events_T2tt_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5BVetoLightUp,"Events_T2tt_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5BVetoLightUp,"Events_T2tt_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5BVetoLightDown,"Events_T2tt_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5BVetoLightDown,"Events_T2tt_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name7BVetoBCUp,"Events_T2bw025_offShellBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7BVetoBCUp,"Events_T2bw025_offShellBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name7BVetoBCDown,"Events_T2bw025_offShellBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7BVetoBCDown,"Events_T2bw025_offShellBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name7BVetoLightUp,"Events_T2bw025_offShellBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7BVetoLightUp,"Events_T2bw025_offShellBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name7BVetoLightDown,"Events_T2bw025_offShellBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7BVetoLightDown,"Events_T2bw025_offShellBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name8BVetoBCUp,"Events_T2bw025_lowMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8BVetoBCUp,"Events_T2bw025_lowMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8BVetoBCDown,"Events_T2bw025_lowMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8BVetoBCDown,"Events_T2bw025_lowMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8BVetoLightUp,"Events_T2bw025_lowMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8BVetoLightUp,"Events_T2bw025_lowMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8BVetoLightDown,"Events_T2bw025_lowMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8BVetoLightDown,"Events_T2bw025_lowMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name9BVetoBCUp,"Events_T2bw025_highMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9BVetoBCUp,"Events_T2bw025_highMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9BVetoBCDown,"Events_T2bw025_highMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9BVetoBCDown,"Events_T2bw025_highMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9BVetoLightUp,"Events_T2bw025_highMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9BVetoLightUp,"Events_T2bw025_highMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9BVetoLightDown,"Events_T2bw025_highMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9BVetoLightDown,"Events_T2bw025_highMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);




   sprintf(name10BVetoBCUp,"Events_T2bw050_offShellBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10BVetoBCUp,"Events_T2bw050_offShellBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name10BVetoBCDown,"Events_T2bw050_offShellBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10BVetoBCDown,"Events_T2bw050_offShellBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name10BVetoLightUp,"Events_T2bw050_offShellBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10BVetoLightUp,"Events_T2bw050_offShellBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name10BVetoLightDown,"Events_T2bw050_offShellBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10BVetoLightDown,"Events_T2bw050_offShellBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name11BVetoBCUp,"Events_T2bw050_lowMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11BVetoBCUp,"Events_T2bw050_lowMassesBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11BVetoBCDown,"Events_T2bw050_lowMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11BVetoBCDown,"Events_T2bw050_lowMassesBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11BVetoLightUp,"Events_T2bw050_lowMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11BVetoLightUp,"Events_T2bw050_lowMassesBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11BVetoLightDown,"Events_T2bw050_lowMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11BVetoLightDown,"Events_T2bw050_lowMassesBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name12BVetoBCUp,"Events_T2bw050_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12BVetoBCUp,"Events_T2bw050_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12BVetoBCDown,"Events_T2bw050_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12BVetoBCDown,"Events_T2bw050_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12BVetoLightUp,"Events_T2bw050_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12BVetoLightUp,"Events_T2bw050_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12BVetoLightDown,"Events_T2bw050_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12BVetoLightDown,"Events_T2bw050_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name13BVetoBCUp,"Events_T2bw050_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13BVetoBCUp,"Events_T2bw050_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13BVetoBCDown,"Events_T2bw050_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13BVetoBCDown,"Events_T2bw050_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13BVetoLightUp,"Events_T2bw050_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13BVetoLightUp,"Events_T2bw050_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13BVetoLightDown,"Events_T2bw050_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13BVetoLightDown,"Events_T2bw050_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name14BVetoBCUp,"Events_T2bw075_lowDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14BVetoBCUp,"Events_T2bw075_lowDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name14BVetoBCDown,"Events_T2bw075_lowDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14BVetoBCDown,"Events_T2bw075_lowDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name14BVetoLightUp,"Events_T2bw075_lowDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14BVetoLightUp,"Events_T2bw075_lowDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name14BVetoLightDown,"Events_T2bw075_lowDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14BVetoLightDown,"Events_T2bw075_lowDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name15BVetoBCUp,"Events_T2bw075_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15BVetoBCUp,"Events_T2bw075_mediumDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15BVetoBCDown,"Events_T2bw075_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15BVetoBCDown,"Events_T2bw075_mediumDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15BVetoLightUp,"Events_T2bw075_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15BVetoLightUp,"Events_T2bw075_mediumDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15BVetoLightDown,"Events_T2bw075_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15BVetoLightDown,"Events_T2bw075_mediumDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name16BVetoBCUp,"Events_T2bw075_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16BVetoBCUp,"Events_T2bw075_highDeltaMBVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16BVetoBCDown,"Events_T2bw075_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16BVetoBCDown,"Events_T2bw075_highDeltaMBVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16BVetoLightUp,"Events_T2bw075_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16BVetoLightUp,"Events_T2bw075_highDeltaMBVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16BVetoLightDown,"Events_T2bw075_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16BVetoLightDown,"Events_T2bw075_highDeltaMBVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);




   sprintf(name17BVetoBCUp,"hist_BDT_output_t2bw025_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17BVetoBCUp,"hist_BDT_output_t2bw025_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name17BVetoBCDown,"hist_BDT_output_t2bw025_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17BVetoBCDown,"hist_BDT_output_t2bw025_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name17BVetoLightUp,"hist_BDT_output_t2bw025_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17BVetoLightUp,"hist_BDT_output_t2bw025_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name17BVetoLightDown,"hist_BDT_output_t2bw025_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17BVetoLightDown,"hist_BDT_output_t2bw025_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name18BVetoBCUp,"hist_BDT_output_t2bw025_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18BVetoBCUp,"hist_BDT_output_t2bw025_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name18BVetoBCDown,"hist_BDT_output_t2bw025_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18BVetoBCDown,"hist_BDT_output_t2bw025_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name18BVetoLightUp,"hist_BDT_output_t2bw025_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18BVetoLightUp,"hist_BDT_output_t2bw025_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name18BVetoLightDown,"hist_BDT_output_t2bw025_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18BVetoLightDown,"hist_BDT_output_t2bw025_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name19BVetoBCUp,"hist_BDT_output_t2bw025_R4BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19BVetoBCUp,"hist_BDT_output_t2bw025_R4BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19BVetoBCDown,"hist_BDT_output_t2bw025_R4BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19BVetoBCDown,"hist_BDT_output_t2bw025_R4BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19BVetoLightUp,"hist_BDT_output_t2bw025_R4BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19BVetoLightUp,"hist_BDT_output_t2bw025_R4BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19BVetoLightDown,"hist_BDT_output_t2bw025_R4BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19BVetoLightDown,"hist_BDT_output_t2bw025_R4BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name20BVetoBCUp,"hist_BDT_output_t2bw025_R6BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20BVetoBCUp,"hist_BDT_output_t2bw025_R6BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20BVetoBCDown,"hist_BDT_output_t2bw025_R6BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20BVetoBCDown,"hist_BDT_output_t2bw025_R6BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20BVetoLightUp,"hist_BDT_output_t2bw025_R6BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20BVetoLightUp,"hist_BDT_output_t2bw025_R6BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20BVetoLightDown,"hist_BDT_output_t2bw025_R6BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20BVetoLightDown,"hist_BDT_output_t2bw025_R6BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   

   sprintf(name21BVetoBCUp,"hist_BDT_output_t2bw050_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21BVetoBCUp,"hist_BDT_output_t2bw050_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21BVetoBCDown,"hist_BDT_output_t2bw050_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21BVetoBCDown,"hist_BDT_output_t2bw050_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21BVetoLightUp,"hist_BDT_output_t2bw050_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21BVetoLightUp,"hist_BDT_output_t2bw050_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21BVetoLightDown,"hist_BDT_output_t2bw050_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21BVetoLightDown,"hist_BDT_output_t2bw050_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name22BVetoBCUp,"hist_BDT_output_t2bw050_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22BVetoBCUp,"hist_BDT_output_t2bw050_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22BVetoBCDown,"hist_BDT_output_t2bw050_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22BVetoBCDown,"hist_BDT_output_t2bw050_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22BVetoLightUp,"hist_BDT_output_t2bw050_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22BVetoLightUp,"hist_BDT_output_t2bw050_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22BVetoLightDown,"hist_BDT_output_t2bw050_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22BVetoLightDown,"hist_BDT_output_t2bw050_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23BVetoBCUp,"hist_BDT_output_t2bw050_R4BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23BVetoBCUp,"hist_BDT_output_t2bw050_R4BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23BVetoBCDown,"hist_BDT_output_t2bw050_R4BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23BVetoBCDown,"hist_BDT_output_t2bw050_R4BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23BVetoLightUp,"hist_BDT_output_t2bw050_R4BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23BVetoLightUp,"hist_BDT_output_t2bw050_R4BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23BVetoLightDown,"hist_BDT_output_t2bw050_R4BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23BVetoLightDown,"hist_BDT_output_t2bw050_R4BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name24BVetoBCUp,"hist_BDT_output_t2bw050_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24BVetoBCUp,"hist_BDT_output_t2bw050_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24BVetoBCDown,"hist_BDT_output_t2bw050_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24BVetoBCDown,"hist_BDT_output_t2bw050_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24BVetoLightUp,"hist_BDT_output_t2bw050_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24BVetoLightUp,"hist_BDT_output_t2bw050_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24BVetoLightDown,"hist_BDT_output_t2bw050_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24BVetoLightDown,"hist_BDT_output_t2bw050_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25BVetoBCUp,"hist_BDT_output_t2bw050_R6BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25BVetoBCUp,"hist_BDT_output_t2bw050_R6BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25BVetoBCDown,"hist_BDT_output_t2bw050_R6BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25BVetoBCDown,"hist_BDT_output_t2bw050_R6BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25BVetoLightUp,"hist_BDT_output_t2bw050_R6BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25BVetoLightUp,"hist_BDT_output_t2bw050_R6BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25BVetoLightDown,"hist_BDT_output_t2bw050_R6BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25BVetoLightDown,"hist_BDT_output_t2bw050_R6BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name26BVetoBCUp,"hist_BDT_output_t2bw075_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26BVetoBCUp,"hist_BDT_output_t2bw075_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name26BVetoBCDown,"hist_BDT_output_t2bw075_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26BVetoBCDown,"hist_BDT_output_t2bw075_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name26BVetoLightUp,"hist_BDT_output_t2bw075_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26BVetoLightUp,"hist_BDT_output_t2bw075_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name26BVetoLightDown,"hist_BDT_output_t2bw075_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26BVetoLightDown,"hist_BDT_output_t2bw075_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name27BVetoBCUp,"hist_BDT_output_t2bw075_R2BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27BVetoBCUp,"hist_BDT_output_t2bw075_R2BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27BVetoBCDown,"hist_BDT_output_t2bw075_R2BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27BVetoBCDown,"hist_BDT_output_t2bw075_R2BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27BVetoLightUp,"hist_BDT_output_t2bw075_R2BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27BVetoLightUp,"hist_BDT_output_t2bw075_R2BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27BVetoLightDown,"hist_BDT_output_t2bw075_R2BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27BVetoLightDown,"hist_BDT_output_t2bw075_R2BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name28BVetoBCUp,"hist_BDT_output_t2bw075_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28BVetoBCUp,"hist_BDT_output_t2bw075_R3BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28BVetoBCDown,"hist_BDT_output_t2bw075_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28BVetoBCDown,"hist_BDT_output_t2bw075_R3BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28BVetoLightUp,"hist_BDT_output_t2bw075_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28BVetoLightUp,"hist_BDT_output_t2bw075_R3BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28BVetoLightDown,"hist_BDT_output_t2bw075_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28BVetoLightDown,"hist_BDT_output_t2bw075_R3BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29BVetoBCUp,"hist_BDT_output_t2bw075_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29BVetoBCUp,"hist_BDT_output_t2bw075_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29BVetoBCDown,"hist_BDT_output_t2bw075_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29BVetoBCDown,"hist_BDT_output_t2bw075_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29BVetoLightUp,"hist_BDT_output_t2bw075_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29BVetoLightUp,"hist_BDT_output_t2bw075_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29BVetoLightDown,"hist_BDT_output_t2bw075_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29BVetoLightDown,"hist_BDT_output_t2bw075_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);



   sprintf(name30BVetoBCUp,"hist_BDT_output_t2tt_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30BVetoBCUp,"hist_BDT_output_t2tt_R1BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name30BVetoBCDown,"hist_BDT_output_t2tt_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30BVetoBCDown,"hist_BDT_output_t2tt_R1BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name30BVetoLightUp,"hist_BDT_output_t2tt_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30BVetoLightUp,"hist_BDT_output_t2tt_R1BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name30BVetoLightDown,"hist_BDT_output_t2tt_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30BVetoLightDown,"hist_BDT_output_t2tt_R1BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31BVetoBCUp,"hist_BDT_output_t2tt_R2BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31BVetoBCUp,"hist_BDT_output_t2tt_R2BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31BVetoBCDown,"hist_BDT_output_t2tt_R2BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31BVetoBCDown,"hist_BDT_output_t2tt_R2BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31BVetoLightUp,"hist_BDT_output_t2tt_R2BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31BVetoLightUp,"hist_BDT_output_t2tt_R2BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31BVetoLightDown,"hist_BDT_output_t2tt_R2BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31BVetoLightDown,"hist_BDT_output_t2tt_R2BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32BVetoBCUp,"hist_BDT_output_t2tt_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32BVetoBCUp,"hist_BDT_output_t2tt_R5BVetoBCUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32BVetoBCDown,"hist_BDT_output_t2tt_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32BVetoBCDown,"hist_BDT_output_t2tt_R5BVetoBCDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32BVetoLightUp,"hist_BDT_output_t2tt_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32BVetoLightUp,"hist_BDT_output_t2tt_R5BVetoLightUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32BVetoLightDown,"hist_BDT_output_t2tt_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32BVetoLightDown,"hist_BDT_output_t2tt_R5BVetoLightDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name1JESUp,"Events_T2tt_offShellLooseJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1JESUp,"Events_T2tt_offShellLooseJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2JESUp,"Events_T2tt_offShellTightJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2JESUp,"Events_T2tt_offShellTightJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3JESUp,"Events_T2tt_lowDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3JESUp,"Events_T2tt_lowDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4JESUp,"Events_T2tt_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4JESUp,"Events_T2tt_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5JESUp,"Events_T2tt_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5JESUp,"Events_T2tt_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name7JESUp,"Events_T2bw025_offShellJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7JESUp,"Events_T2bw025_offShellJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8JESUp,"Events_T2bw025_lowMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8JESUp,"Events_T2bw025_lowMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9JESUp,"Events_T2bw025_highMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9JESUp,"Events_T2bw025_highMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name10JESUp,"Events_T2bw050_offShellJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10JESUp,"Events_T2bw050_offShellJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11JESUp,"Events_T2bw050_lowMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11JESUp,"Events_T2bw050_lowMassesJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12JESUp,"Events_T2bw050_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12JESUp,"Events_T2bw050_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13JESUp,"Events_T2bw050_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13JESUp,"Events_T2bw050_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name14JESUp,"Events_T2bw075_lowDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14JESUp,"Events_T2bw075_lowDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15JESUp,"Events_T2bw075_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15JESUp,"Events_T2bw075_mediumDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16JESUp,"Events_T2bw075_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16JESUp,"Events_T2bw075_highDeltaMJESUp_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name1JESDown,"Events_T2tt_offShellLooseJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title1JESDown,"Events_T2tt_offShellLooseJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name2JESDown,"Events_T2tt_offShellTightJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title2JESDown,"Events_T2tt_offShellTightJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name3JESDown,"Events_T2tt_lowDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title3JESDown,"Events_T2tt_lowDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name4JESDown,"Events_T2tt_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title4JESDown,"Events_T2tt_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name5JESDown,"Events_T2tt_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title5JESDown,"Events_T2tt_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name7JESDown,"Events_T2bw025_offShellJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title7JESDown,"Events_T2bw025_offShellJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name8JESDown,"Events_T2bw025_lowMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title8JESDown,"Events_T2bw025_lowMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name9JESDown,"Events_T2bw025_highMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title9JESDown,"Events_T2bw025_highMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name10JESDown,"Events_T2bw050_offShellJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title10JESDown,"Events_T2bw050_offShellJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name11JESDown,"Events_T2bw050_lowMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title11JESDown,"Events_T2bw050_lowMassesJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name12JESDown,"Events_T2bw050_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title12JESDown,"Events_T2bw050_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name13JESDown,"Events_T2bw050_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title13JESDown,"Events_T2bw050_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);


   sprintf(name14JESDown,"Events_T2bw075_lowDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title14JESDown,"Events_T2bw075_lowDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name15JESDown,"Events_T2bw075_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title15JESDown,"Events_T2bw075_mediumDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name16JESDown,"Events_T2bw075_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title16JESDown,"Events_T2bw075_highDeltaMJESDown_S%i_N%i", STOPMASS, LSPMASS);



   sprintf(name17JESUp,"hist_BDT_output_t2bw025_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17JESUp,"hist_BDT_output_t2bw025_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name17JESDown,"hist_BDT_output_t2bw025_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title17JESDown,"hist_BDT_output_t2bw025_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name18JESUp,"hist_BDT_output_t2bw025_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18JESUp,"hist_BDT_output_t2bw025_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name18JESDown,"hist_BDT_output_t2bw025_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title18JESDown,"hist_BDT_output_t2bw025_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name19JESUp,"hist_BDT_output_t2bw025_R4JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19JESUp,"hist_BDT_output_t2bw025_R4JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name19JESDown,"hist_BDT_output_t2bw025_R4JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title19JESDown,"hist_BDT_output_t2bw025_R4JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name20JESUp,"hist_BDT_output_t2bw025_R6JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20JESUp,"hist_BDT_output_t2bw025_R6JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name20JESDown,"hist_BDT_output_t2bw025_R6JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title20JESDown,"hist_BDT_output_t2bw025_R6JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name21JESUp,"hist_BDT_output_t2bw050_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21JESUp,"hist_BDT_output_t2bw050_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name21JESDown,"hist_BDT_output_t2bw050_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title21JESDown,"hist_BDT_output_t2bw050_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name22JESUp,"hist_BDT_output_t2bw050_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22JESUp,"hist_BDT_output_t2bw050_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name22JESDown,"hist_BDT_output_t2bw050_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title22JESDown,"hist_BDT_output_t2bw050_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name23JESUp,"hist_BDT_output_t2bw050_R4JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23JESUp,"hist_BDT_output_t2bw050_R4JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name23JESDown,"hist_BDT_output_t2bw050_R4JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title23JESDown,"hist_BDT_output_t2bw050_R4JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name24JESUp,"hist_BDT_output_t2bw050_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24JESUp,"hist_BDT_output_t2bw050_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name24JESDown,"hist_BDT_output_t2bw050_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title24JESDown,"hist_BDT_output_t2bw050_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name25JESUp,"hist_BDT_output_t2bw050_R6JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25JESUp,"hist_BDT_output_t2bw050_R6JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name25JESDown,"hist_BDT_output_t2bw050_R6JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title25JESDown,"hist_BDT_output_t2bw050_R6JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name26JESUp,"hist_BDT_output_t2bw075_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26JESUp,"hist_BDT_output_t2bw075_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name26JESDown,"hist_BDT_output_t2bw075_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title26JESDown,"hist_BDT_output_t2bw075_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name27JESUp,"hist_BDT_output_t2bw075_R2JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27JESUp,"hist_BDT_output_t2bw075_R2JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name27JESDown,"hist_BDT_output_t2bw075_R2JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title27JESDown,"hist_BDT_output_t2bw075_R2JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name28JESUp,"hist_BDT_output_t2bw075_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28JESUp,"hist_BDT_output_t2bw075_R3JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name28JESDown,"hist_BDT_output_t2bw075_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title28JESDown,"hist_BDT_output_t2bw075_R3JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name29JESUp,"hist_BDT_output_t2bw075_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29JESUp,"hist_BDT_output_t2bw075_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name29JESDown,"hist_BDT_output_t2bw075_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title29JESDown,"hist_BDT_output_t2bw075_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name30JESUp,"hist_BDT_output_t2tt_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30JESUp,"hist_BDT_output_t2tt_R1JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name30JESDown,"hist_BDT_output_t2tt_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title30JESDown,"hist_BDT_output_t2tt_R1JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name31JESUp,"hist_BDT_output_t2tt_R2JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31JESUp,"hist_BDT_output_t2tt_R2JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name31JESDown,"hist_BDT_output_t2tt_R2JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title31JESDown,"hist_BDT_output_t2tt_R2JESDown_S%i_N%i", STOPMASS, LSPMASS);

   sprintf(name32JESUp,"hist_BDT_output_t2tt_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32JESUp,"hist_BDT_output_t2tt_R5JESUp_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(name32JESDown,"hist_BDT_output_t2tt_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);
   sprintf(title32JESDown,"hist_BDT_output_t2tt_R5JESDown_S%i_N%i", STOPMASS, LSPMASS);



   Events_Preselection 	= new TH1D(name00,title00,100,0,10000) ;
   Events_NGenSignal 	= new TH1D(name0,title0,100,0,999999) ;
   Events_NSignal 	= new TH1D(name000,title000,100,0,999999) ;

   Events_T2tt_offShellLoose 	= new TH1D(name1,title1,100,0,10000) ; 
   Events_T2tt_offShellTight 	= new TH1D(name2,title2,100,0,10000) ; 
   Events_T2tt_lowDeltaM 	= new TH1D(name3,title3,100,0,10000) ; 
   Events_T2tt_mediumDeltaM 	= new TH1D(name4,title4,100,0,10000) ; 
   Events_T2tt_highDeltaM 	= new TH1D(name5,title5,100,0,10000) ; 

   Events_T2bw025_offShell = new TH1D(name7,title7,100,0,10000);
   Events_T2bw025_lowMasses = new TH1D(name8,title8,100,0,10000); 
   Events_T2bw025_highMasses = new TH1D(name9,title9,100,0,10000);

   Events_T2bw050_offShell = new TH1D(name10,title10,100,0,10000);
   Events_T2bw050_lowMasses = new TH1D(name11,title11,100,0,10000);
   Events_T2bw050_mediumDeltaM = new TH1D(name12,title12,100,0,10000);
   Events_T2bw050_highDeltaM = new TH1D(name13,title13,100,0,10000);

   Events_T2bw075_lowDeltaM = new TH1D(name14,title14,100,0,10000);
   Events_T2bw075_mediumDeltaM = new TH1D(name15,title15,100,0,10000);
   Events_T2bw075_highDeltaM = new TH1D(name16,title16,100,0,10000);


   Events_T2tt_offShellLooseBVetoBCUp 				= new TH1D(name1BVetoBCUp,title1BVetoBCUp,100,0,10000) ; 
   Events_T2tt_offShellLooseBVetoBCDown 			= new TH1D(name1BVetoBCDown,title1BVetoBCDown,100,0,10000) ; 
   Events_T2tt_offShellLooseBVetoLightUp 			= new TH1D(name1BVetoLightUp,title1BVetoLightUp,100,0,10000) ; 
   Events_T2tt_offShellLooseBVetoLightDown 			= new TH1D(name1BVetoLightDown,title1BVetoLightDown,100,0,10000) ; 

   Events_T2tt_offShellTightBVetoBCUp 	    			= new TH1D(name2BVetoBCUp,title2BVetoBCUp,100,0,10000) ;           	
   Events_T2tt_offShellTightBVetoBCDown     	                = new TH1D(name2BVetoBCDown,title2BVetoBCDown,100,0,10000) ; 
   Events_T2tt_offShellTightBVetoLightUp    	                = new TH1D(name2BVetoLightUp,title2BVetoLightUp,100,0,10000) ; 
   Events_T2tt_offShellTightBVetoLightDown  	                = new TH1D(name2BVetoLightDown,title2BVetoLightDown,100,0,10000) ; 

   Events_T2tt_lowDeltaMBVetoBCUp 	    			= new TH1D(name3BVetoBCUp,title3BVetoBCUp,100,0,10000) ;           	
   Events_T2tt_lowDeltaMBVetoBCDown     	                = new TH1D(name3BVetoBCDown,title3BVetoBCDown,100,0,10000) ; 
   Events_T2tt_lowDeltaMBVetoLightUp    	                = new TH1D(name3BVetoLightUp,title3BVetoLightUp,100,0,10000) ; 
   Events_T2tt_lowDeltaMBVetoLightDown  	                = new TH1D(name3BVetoLightDown,title3BVetoLightDown,100,0,10000) ; 

   Events_T2tt_mediumDeltaMBVetoBCUp 	    			= new TH1D(name4BVetoBCUp,title4BVetoBCUp,100,0,10000) ;           	
   Events_T2tt_mediumDeltaMBVetoBCDown     	                = new TH1D(name4BVetoBCDown,title4BVetoBCDown,100,0,10000) ; 
   Events_T2tt_mediumDeltaMBVetoLightUp    	                = new TH1D(name4BVetoLightUp,title4BVetoLightUp,100,0,10000) ; 
   Events_T2tt_mediumDeltaMBVetoLightDown  	                = new TH1D(name4BVetoLightDown,title4BVetoLightDown,100,0,10000) ; 

   Events_T2tt_highDeltaMBVetoBCUp 	    			= new TH1D(name5BVetoBCUp,title5BVetoBCUp,100,0,10000) ;           	
   Events_T2tt_highDeltaMBVetoBCDown     	                = new TH1D(name5BVetoBCDown,title5BVetoBCDown,100,0,10000) ; 
   Events_T2tt_highDeltaMBVetoLightUp    	                = new TH1D(name5BVetoLightUp,title5BVetoLightUp,100,0,10000) ; 
   Events_T2tt_highDeltaMBVetoLightDown  	                = new TH1D(name5BVetoLightDown,title5BVetoLightDown,100,0,10000) ; 


   Events_T2bw025_offShellBVetoBCUp 	   		= new TH1D(name7BVetoBCUp,title7BVetoBCUp,100,0,10000) ;           			 
   Events_T2bw025_offShellBVetoBCDown                    = new TH1D(name7BVetoBCDown,title7BVetoBCDown,100,0,10000) ; 
   Events_T2bw025_offShellBVetoLightUp                   = new TH1D(name7BVetoLightUp,title7BVetoLightUp,100,0,10000) ; 
   Events_T2bw025_offShellBVetoLightDown                 = new TH1D(name7BVetoLightDown,title7BVetoLightDown,100,0,10000) ; 

   Events_T2bw025_lowMassesBVetoBCUp 	   		 = new TH1D(name8BVetoBCUp,title8BVetoBCUp,100,0,10000) ;           	
   Events_T2bw025_lowMassesBVetoBCDown                    = new TH1D(name8BVetoBCDown,title8BVetoBCDown,100,0,10000) ; 
   Events_T2bw025_lowMassesBVetoLightUp                   = new TH1D(name8BVetoLightUp,title8BVetoLightUp,100,0,10000) ; 
   Events_T2bw025_lowMassesBVetoLightDown                 = new TH1D(name8BVetoLightDown,title8BVetoLightDown,100,0,10000) ; 

   Events_T2bw025_highMassesBVetoBCUp 	   			= new TH1D(name9BVetoBCUp,title9BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw025_highMassesBVetoBCDown                        = new TH1D(name9BVetoBCDown,title9BVetoBCDown,100,0,10000) ; 
   Events_T2bw025_highMassesBVetoLightUp                       = new TH1D(name9BVetoLightUp,title9BVetoLightUp,100,0,10000) ; 
   Events_T2bw025_highMassesBVetoLightDown                     = new TH1D(name9BVetoLightDown,title9BVetoLightDown,100,0,10000) ; 

   Events_T2bw050_offShellBVetoBCUp 	   		= new TH1D(name10BVetoBCUp,title10BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw050_offShellBVetoBCDown                    = new TH1D(name10BVetoBCDown,title10BVetoBCDown,100,0,10000) ; 
   Events_T2bw050_offShellBVetoLightUp                   = new TH1D(name10BVetoLightUp,title10BVetoLightUp,100,0,10000) ; 
   Events_T2bw050_offShellBVetoLightDown                 = new TH1D(name10BVetoLightDown,title10BVetoLightDown,100,0,10000) ; 

   Events_T2bw050_lowMassesBVetoBCUp 	   			= new TH1D(name11BVetoBCUp,title11BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw050_lowMassesBVetoBCDown                           = new TH1D(name11BVetoBCDown,title11BVetoBCDown,100,0,10000) ; 
   Events_T2bw050_lowMassesBVetoLightUp                          = new TH1D(name11BVetoLightUp,title11BVetoLightUp,100,0,10000) ; 
   Events_T2bw050_lowMassesBVetoLightDown                        = new TH1D(name11BVetoLightDown,title11BVetoLightDown,100,0,10000) ; 

   Events_T2bw050_mediumDeltaMBVetoBCUp 	   		= new TH1D(name12BVetoBCUp,title12BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw050_mediumDeltaMBVetoBCDown                = new TH1D(name12BVetoBCDown,title12BVetoBCDown,100,0,10000) ; 
   Events_T2bw050_mediumDeltaMBVetoLightUp               = new TH1D(name12BVetoLightUp,title12BVetoLightUp,100,0,10000) ; 
   Events_T2bw050_mediumDeltaMBVetoLightDown             = new TH1D(name12BVetoLightDown,title12BVetoLightDown,100,0,10000) ; 

   Events_T2bw050_highDeltaMBVetoBCUp 	   			= new TH1D(name13BVetoBCUp,title13BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw050_highDeltaMBVetoBCDown                        = new TH1D(name13BVetoBCDown,title13BVetoBCDown,100,0,10000) ; 
   Events_T2bw050_highDeltaMBVetoLightUp                       = new TH1D(name13BVetoLightUp,title13BVetoLightUp,100,0,10000) ; 
   Events_T2bw050_highDeltaMBVetoLightDown                     = new TH1D(name13BVetoLightDown,title13BVetoLightDown,100,0,10000) ; 


   Events_T2bw075_lowDeltaMBVetoBCUp 	   		= new TH1D(name14BVetoBCUp,title14BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw075_lowDeltaMBVetoBCDown                   = new TH1D(name14BVetoBCDown,title14BVetoBCDown,100,0,10000) ; 
   Events_T2bw075_lowDeltaMBVetoLightUp                  = new TH1D(name14BVetoLightUp,title14BVetoLightUp,100,0,10000) ; 
   Events_T2bw075_lowDeltaMBVetoLightDown                = new TH1D(name14BVetoLightDown,title14BVetoLightDown,100,0,10000) ; 

   Events_T2bw075_mediumDeltaMBVetoBCUp    			= new TH1D(name15BVetoBCUp,title15BVetoBCUp,100,0,10000) ;           	
   Events_T2bw075_mediumDeltaMBVetoBCDown                      = new TH1D(name15BVetoBCDown,title15BVetoBCDown,100,0,10000) ; 
   Events_T2bw075_mediumDeltaMBVetoLightUp                     = new TH1D(name15BVetoLightUp,title15BVetoLightUp,100,0,10000) ; 
   Events_T2bw075_mediumDeltaMBVetoLightDown                   = new TH1D(name15BVetoLightDown,title15BVetoLightDown,100,0,10000) ; 

   Events_T2bw075_highDeltaMBVetoBCUp 	   			= new TH1D(name16BVetoBCUp,title16BVetoBCUp,100,0,10000) ;           	 
   Events_T2bw075_highDeltaMBVetoBCDown                        = new TH1D(name16BVetoBCDown,title16BVetoBCDown,100,0,10000) ; 
   Events_T2bw075_highDeltaMBVetoLightUp                       = new TH1D(name16BVetoLightUp,title16BVetoLightUp,100,0,10000) ; 
   Events_T2bw075_highDeltaMBVetoLightDown                     = new TH1D(name16BVetoLightDown,title16BVetoLightDown,100,0,10000) ; 



   Events_T2tt_offShellLooseJESUp 	= new TH1D(name1JESUp,title1JESUp,100,0,10000) ; 
   Events_T2tt_offShellTightJESUp 	= new TH1D(name2JESUp,title2JESUp,100,0,10000) ; 
   Events_T2tt_lowDeltaMJESUp 	= new TH1D(name3JESUp,title3JESUp,100,0,10000) ; 
   Events_T2tt_mediumDeltaMJESUp 	= new TH1D(name4JESUp,title4JESUp,100,0,10000) ; 
   Events_T2tt_highDeltaMJESUp 	= new TH1D(name5JESUp,title5JESUp,100,0,10000) ; 

   Events_T2bw025_offShellJESUp = new TH1D(name7JESUp,title7JESUp,100,0,10000);
   Events_T2bw025_lowMassesJESUp = new TH1D(name8JESUp,title8JESUp,100,0,10000); 
   Events_T2bw025_highMassesJESUp = new TH1D(name9JESUp,title9JESUp,100,0,10000);

   Events_T2bw050_offShellJESUp = new TH1D(name10JESUp,title10JESUp,100,0,10000);
   Events_T2bw050_lowMassesJESUp = new TH1D(name11JESUp,title11JESUp,100,0,10000);
   Events_T2bw050_mediumDeltaMJESUp = new TH1D(name12JESUp,title12JESUp,100,0,10000);
   Events_T2bw050_highDeltaMJESUp = new TH1D(name13JESUp,title13JESUp,100,0,10000);

   Events_T2bw075_lowDeltaMJESUp = new TH1D(name14JESUp,title14JESUp,100,0,10000);
   Events_T2bw075_mediumDeltaMJESUp = new TH1D(name15JESUp,title15JESUp,100,0,10000);
   Events_T2bw075_highDeltaMJESUp = new TH1D(name16JESUp,title16JESUp,100,0,10000);
   

   Events_T2tt_offShellLooseJESDown 	= new TH1D(name1JESDown,title1JESDown,100,0,10000) ; 
   Events_T2tt_offShellTightJESDown 	= new TH1D(name2JESDown,title2JESDown,100,0,10000) ; 
   Events_T2tt_lowDeltaMJESDown 	= new TH1D(name3JESDown,title3JESDown,100,0,10000) ; 
   Events_T2tt_mediumDeltaMJESDown 	= new TH1D(name4JESDown,title4JESDown,100,0,10000) ; 
   Events_T2tt_highDeltaMJESDown 	= new TH1D(name5JESDown,title5JESDown,100,0,10000) ; 

   Events_T2bw025_offShellJESDown = new TH1D(name7JESDown,title7JESDown,100,0,10000);
   Events_T2bw025_lowMassesJESDown = new TH1D(name8JESDown,title8JESDown,100,0,10000); 
   Events_T2bw025_highMassesJESDown = new TH1D(name9JESDown,title9JESDown,100,0,10000);

   Events_T2bw050_offShellJESDown = new TH1D(name10JESDown,title10JESDown,100,0,10000);
   Events_T2bw050_lowMassesJESDown = new TH1D(name11JESDown,title11JESDown,100,0,10000);
   Events_T2bw050_mediumDeltaMJESDown = new TH1D(name12JESDown,title12JESDown,100,0,10000);
   Events_T2bw050_highDeltaMJESDown = new TH1D(name13JESDown,title13JESDown,100,0,10000);

   Events_T2bw075_lowDeltaMJESDown = new TH1D(name14JESDown,title14JESDown,100,0,10000);
   Events_T2bw075_mediumDeltaMJESDown = new TH1D(name15JESDown,title15JESDown,100,0,10000);
   Events_T2bw075_highDeltaMJESDown = new TH1D(name16JESDown,title16JESDown,100,0,10000);

	
   hist_BDT_output_t2bw025_R1_RAW = new TH1D(name17_RAW,title17_RAW,100,-2,2);
   hist_BDT_output_t2bw025_R3_RAW = new TH1D(name18_RAW,title18_RAW,100,-2,2);
   hist_BDT_output_t2bw025_R4_RAW = new TH1D(name19_RAW,title19_RAW,100,-2,2);
   hist_BDT_output_t2bw025_R6_RAW = new TH1D(name20_RAW,title20_RAW,100,-2,2);

   hist_BDT_output_t2bw050_R1_RAW = new TH1D(name21_RAW,title21_RAW,100,-2,2);
   hist_BDT_output_t2bw050_R3_RAW = new TH1D(name22_RAW,title22_RAW,100,-2,2);
   hist_BDT_output_t2bw050_R4_RAW = new TH1D(name23_RAW,title23_RAW,100,-2,2);
   hist_BDT_output_t2bw050_R5_RAW = new TH1D(name24_RAW,title24_RAW,100,-2,2);
   hist_BDT_output_t2bw050_R6_RAW = new TH1D(name25_RAW,title25_RAW,100,-2,2);

   hist_BDT_output_t2bw075_R1_RAW = new TH1D(name26_RAW,title26_RAW,100,-2,2);
   hist_BDT_output_t2bw075_R2_RAW = new TH1D(name27_RAW,title27_RAW,100,-2,2);
   hist_BDT_output_t2bw075_R3_RAW = new TH1D(name28_RAW,title28_RAW,100,-2,2);
   hist_BDT_output_t2bw075_R5_RAW = new TH1D(name29_RAW,title29_RAW,100,-2,2);

   hist_BDT_output_t2tt_R1_RAW = new TH1D(name30_RAW,title30_RAW,100,-2,2);
   hist_BDT_output_t2tt_R2_RAW = new TH1D(name31_RAW,title31_RAW,100,-2,2);
   hist_BDT_output_t2tt_R5_RAW = new TH1D(name32_RAW,title32_RAW,100,-2,2);


   hist_BDT_output_t2bw025_R1 = new TH1D(name17,title17,100,-2,2);
   hist_BDT_output_t2bw025_R3 = new TH1D(name18,title18,100,-2,2);
   hist_BDT_output_t2bw025_R4 = new TH1D(name19,title19,100,-2,2);
   hist_BDT_output_t2bw025_R6 = new TH1D(name20,title20,100,-2,2);

   hist_BDT_output_t2bw050_R1 = new TH1D(name21,title21,100,-2,2);
   hist_BDT_output_t2bw050_R3 = new TH1D(name22,title22,100,-2,2);
   hist_BDT_output_t2bw050_R4 = new TH1D(name23,title23,100,-2,2);
   hist_BDT_output_t2bw050_R5 = new TH1D(name24,title24,100,-2,2);
   hist_BDT_output_t2bw050_R6 = new TH1D(name25,title25,100,-2,2);

   hist_BDT_output_t2bw075_R1 = new TH1D(name26,title26,100,-2,2);
   hist_BDT_output_t2bw075_R2 = new TH1D(name27,title27,100,-2,2);
   hist_BDT_output_t2bw075_R3 = new TH1D(name28,title28,100,-2,2);
   hist_BDT_output_t2bw075_R5 = new TH1D(name29,title29,100,-2,2);


   hist_BDT_output_t2tt_R1 = new TH1D(name30,title30,100,-2,2);
   hist_BDT_output_t2tt_R2 = new TH1D(name31,title31,100,-2,2);
   hist_BDT_output_t2tt_R5 = new TH1D(name32,title32,100,-2,2);

   // BVETO SYST
   
   hist_BDT_output_t2bw025_R1BVetoBCUp = new TH1D(name17BVetoBCUp,title17BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoBCDown = new TH1D(name17BVetoBCDown,title17BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoLightUp = new TH1D(name17BVetoLightUp,title17BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoLightDown = new TH1D(name17BVetoLightDown,title17BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R3BVetoBCUp = new TH1D(name18BVetoBCUp,title18BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoBCDown = new TH1D(name18BVetoBCDown,title18BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoLightUp = new TH1D(name18BVetoLightUp,title18BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoLightDown = new TH1D(name18BVetoLightDown,title18BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R4BVetoBCUp = new TH1D(name19BVetoBCUp,title19BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoBCDown = new TH1D(name19BVetoBCDown,title19BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoLightUp = new TH1D(name19BVetoLightUp,title19BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoLightDown = new TH1D(name19BVetoLightDown,title19BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R6BVetoBCUp = new TH1D(name20BVetoBCUp,title20BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoBCDown = new TH1D(name20BVetoBCDown,title20BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoLightUp = new TH1D(name20BVetoLightUp,title20BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoLightDown = new TH1D(name20BVetoLightDown,title20BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R1BVetoBCUp = new TH1D(name21BVetoBCUp,title21BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R1BVetoBCDown = new TH1D(name21BVetoBCDown,title21BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R1BVetoLightUp = new TH1D(name21BVetoLightUp,title21BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R1BVetoLightDown = new TH1D(name21BVetoLightDown,title21BVetoLightDown,100,-2,2);


   hist_BDT_output_t2bw050_R3BVetoBCUp = new TH1D(name22BVetoBCUp,title22BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoBCDown = new TH1D(name22BVetoBCDown,title22BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoLightUp = new TH1D(name22BVetoLightUp,title22BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoLightDown = new TH1D(name22BVetoLightDown,title22BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R4BVetoBCUp = new TH1D(name23BVetoBCUp,title23BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoBCDown = new TH1D(name23BVetoBCDown,title23BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoLightUp = new TH1D(name23BVetoLightUp,title23BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoLightDown = new TH1D(name23BVetoLightDown,title23BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R5BVetoBCUp = new TH1D(name24BVetoBCUp,title24BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoBCDown = new TH1D(name24BVetoBCDown,title24BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoLightUp = new TH1D(name24BVetoLightUp,title24BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoLightDown = new TH1D(name24BVetoLightDown,title24BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R6BVetoBCUp = new TH1D(name25BVetoBCUp,title25BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoBCDown = new TH1D(name25BVetoBCDown,title25BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoLightUp = new TH1D(name25BVetoLightUp,title25BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoLightDown = new TH1D(name25BVetoLightDown,title25BVetoLightDown,100,-2,2);


   hist_BDT_output_t2bw075_R1BVetoBCUp = new TH1D(name26BVetoBCUp,title26BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoBCDown = new TH1D(name26BVetoBCDown,title26BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoLightUp = new TH1D(name26BVetoLightUp,title26BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoLightDown = new TH1D(name26BVetoLightDown,title26BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R2BVetoBCUp = new TH1D(name27BVetoBCUp,title27BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoBCDown = new TH1D(name27BVetoBCDown,title27BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoLightUp = new TH1D(name27BVetoLightUp,title27BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoLightDown = new TH1D(name27BVetoLightDown,title27BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R3BVetoBCUp = new TH1D(name28BVetoBCUp,title28BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoBCDown = new TH1D(name28BVetoBCDown,title28BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoLightUp = new TH1D(name28BVetoLightUp,title28BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoLightDown = new TH1D(name28BVetoLightDown,title28BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R5BVetoBCUp = new TH1D(name29BVetoBCUp,title29BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoBCDown = new TH1D(name29BVetoBCDown,title29BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoLightUp = new TH1D(name29BVetoLightUp,title29BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoLightDown = new TH1D(name29BVetoLightDown,title29BVetoLightDown,100,-2,2);


   hist_BDT_output_t2tt_R1BVetoBCUp = new TH1D(name30BVetoBCUp,title30BVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoBCDown = new TH1D(name30BVetoBCDown,title30BVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoLightUp = new TH1D(name30BVetoLightUp,title30BVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoLightDown = new TH1D(name30BVetoLightDown,title30BVetoLightDown,100,-2,2);


   hist_BDT_output_t2tt_R2BVetoBCUp = new TH1D(name31BVetoBCUp,title31BVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoBCDown = new TH1D(name31BVetoBCDown,title31BVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoLightUp = new TH1D(name31BVetoLightUp,title31BVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoLightDown = new TH1D(name31BVetoLightDown,title31BVetoLightDown,100,-2,2);

   hist_BDT_output_t2tt_R5BVetoBCUp = new TH1D(name32BVetoBCUp,title32BVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R5BVetoBCDown = new TH1D(name32BVetoBCDown,title32BVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R5BVetoLightUp = new TH1D(name32BVetoLightUp,title32BVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R5BVetoLightDown = new TH1D(name32BVetoLightDown,title32BVetoLightDown,100,-2,2);

   // JES syst 
   hist_BDT_output_t2bw025_R1JESUp = new TH1D(name17JESUp,title17JESUp,100,-2,2);
   hist_BDT_output_t2bw025_R1JESDown = new TH1D(name17JESDown,title17JESDown,100,-2,2);
   hist_BDT_output_t2bw025_R3JESUp = new TH1D(name18JESUp,title18JESUp,100,-2,2);
   hist_BDT_output_t2bw025_R3JESDown = new TH1D(name18JESDown,title18JESDown,100,-2,2);
   hist_BDT_output_t2bw025_R4JESUp = new TH1D(name19JESUp,title19JESUp,100,-2,2);
   hist_BDT_output_t2bw025_R4JESDown = new TH1D(name19JESDown,title19JESDown,100,-2,2);
   hist_BDT_output_t2bw025_R6JESUp = new TH1D(name20JESUp,title20JESUp,100,-2,2);
   hist_BDT_output_t2bw025_R6JESDown = new TH1D(name20JESDown,title20JESDown,100,-2,2);
   hist_BDT_output_t2bw050_R1JESUp = new TH1D(name21JESUp,title21JESUp,100,-2,2);
   hist_BDT_output_t2bw050_R1JESDown = new TH1D(name21JESDown,title21JESDown,100,-2,2);
   hist_BDT_output_t2bw050_R3JESUp = new TH1D(name22JESUp,title22JESUp,100,-2,2);
   hist_BDT_output_t2bw050_R3JESDown = new TH1D(name22JESDown,title22JESDown,100,-2,2);
   hist_BDT_output_t2bw050_R4JESUp = new TH1D(name23JESUp,title23JESUp,100,-2,2);
   hist_BDT_output_t2bw050_R4JESDown = new TH1D(name23JESDown,title23JESDown,100,-2,2);
   hist_BDT_output_t2bw050_R5JESUp = new TH1D(name24JESUp,title24JESUp,100,-2,2);
   hist_BDT_output_t2bw050_R5JESDown = new TH1D(name24JESDown,title24JESDown,100,-2,2);
   hist_BDT_output_t2bw050_R6JESUp = new TH1D(name25JESUp,title25JESUp,100,-2,2);
   hist_BDT_output_t2bw050_R6JESDown = new TH1D(name25JESDown,title25JESDown,100,-2,2);
   hist_BDT_output_t2bw075_R1JESUp = new TH1D(name26JESUp,title26JESUp,100,-2,2);
   hist_BDT_output_t2bw075_R1JESDown = new TH1D(name26JESDown,title26JESDown,100,-2,2);
   hist_BDT_output_t2bw075_R2JESUp = new TH1D(name27JESUp,title27JESUp,100,-2,2);
   hist_BDT_output_t2bw075_R2JESDown = new TH1D(name27JESDown,title27JESDown,100,-2,2);
   hist_BDT_output_t2bw075_R3JESUp = new TH1D(name28JESUp,title28JESUp,100,-2,2);
   hist_BDT_output_t2bw075_R3JESDown = new TH1D(name28JESDown,title28JESDown,100,-2,2);
   hist_BDT_output_t2bw075_R5JESUp = new TH1D(name29JESUp,title29JESUp,100,-2,2);
   hist_BDT_output_t2bw075_R5JESDown = new TH1D(name29JESDown,title29JESDown,100,-2,2);
   hist_BDT_output_t2tt_R1JESUp = new TH1D(name30JESUp,title30JESUp,100,-2,2);
   hist_BDT_output_t2tt_R1JESDown = new TH1D(name30JESDown,title30JESDown,100,-2,2);
   hist_BDT_output_t2tt_R2JESUp = new TH1D(name31JESUp,title31JESUp,100,-2,2);
   hist_BDT_output_t2tt_R2JESDown = new TH1D(name31JESDown,title31JESDown,100,-2,2);
   hist_BDT_output_t2tt_R5JESUp = new TH1D(name32JESUp,title32JESUp,100,-2,2);
   hist_BDT_output_t2tt_R5JESDown = new TH1D(name32JESDown,title32JESDown,100,-2,2);



   // ########################################
   // ##        Run over the events         ##
   // ########################################
   

   int counter = 0; 
   int counter1 = 0; 
   int counter2 = 0; 
   int counter3 = 0; 
   int counter4 = 0; 
   int counter5 = 0; 
   int counter7 = 0; 
   int counter8 = 0; 
   int counter9 = 0; 
   int counter10 = 0; 
   int counter11 = 0; 
   int counter12 = 0; 
   int counter13 = 0; 
   int counter14 = 0; 
   int counter15 = 0; 
   int counter16 = 0; 

   int counter1JESUp = 0; 
   int counter2JESUp = 0; 
   int counter3JESUp = 0; 
   int counter4JESUp = 0; 
   int counter5JESUp = 0; 
   int counter7JESUp = 0; 
   int counter8JESUp = 0; 
   int counter9JESUp = 0; 
   int counter10JESUp = 0; 
   int counter11JESUp = 0; 
   int counter12JESUp = 0; 
   int counter13JESUp = 0; 
   int counter14JESUp = 0; 
   int counter15JESUp = 0; 
   int counter16JESUp = 0; 

   int counter1JESDown = 0; 
   int counter2JESDown = 0; 
   int counter3JESDown = 0; 
   int counter4JESDown = 0; 
   int counter5JESDown = 0; 
   int counter7JESDown = 0; 
   int counter8JESDown = 0; 
   int counter9JESDown = 0; 
   int counter10JESDown = 0; 
   int counter11JESDown = 0; 
   int counter12JESDown = 0; 
   int counter13JESDown = 0; 
   int counter14JESDown = 0; 
   int counter15JESDown = 0; 
   int counter16JESDown = 0; 


   int counter1BVetoBCUp = 0; 
   int counter1BVetoBCDown = 0; 
   int counter1BVetoLightUp = 0; 
   int counter1BVetoLightDown = 0; 

   int counter2BVetoBCUp = 0; 
   int counter2BVetoBCDown = 0; 
   int counter2BVetoLightUp = 0; 
   int counter2BVetoLightDown = 0; 

   int counter3BVetoBCUp = 0; 
   int counter3BVetoBCDown = 0; 
   int counter3BVetoLightUp = 0; 
   int counter3BVetoLightDown = 0; 

   int counter4BVetoBCUp = 0; 
   int counter4BVetoBCDown = 0; 
   int counter4BVetoLightUp = 0; 
   int counter4BVetoLightDown = 0; 

   int counter5BVetoBCUp = 0; 
   int counter5BVetoBCDown = 0; 
   int counter5BVetoLightUp = 0; 
   int counter5BVetoLightDown = 0; 

   int counter7BVetoBCUp = 0; 
   int counter7BVetoBCDown = 0; 
   int counter7BVetoLightUp = 0; 
   int counter7BVetoLightDown = 0; 

   int counter8BVetoBCUp = 0; 
   int counter8BVetoBCDown = 0; 
   int counter8BVetoLightUp = 0; 
   int counter8BVetoLightDown = 0; 

   int counter9BVetoBCUp = 0; 
   int counter9BVetoBCDown = 0; 
   int counter9BVetoLightUp = 0; 
   int counter9BVetoLightDown = 0; 

   int counter10BVetoBCUp = 0; 
   int counter10BVetoBCDown = 0; 
   int counter10BVetoLightUp = 0; 
   int counter10BVetoLightDown = 0; 

   int counter11BVetoBCUp = 0; 
   int counter11BVetoBCDown = 0; 
   int counter11BVetoLightUp = 0; 
   int counter11BVetoLightDown = 0; 

   int counter12BVetoBCUp = 0; 
   int counter12BVetoBCDown = 0; 
   int counter12BVetoLightUp = 0; 
   int counter12BVetoLightDown = 0; 

   int counter13BVetoBCUp = 0; 
   int counter13BVetoBCDown = 0; 
   int counter13BVetoLightUp = 0; 
   int counter13BVetoLightDown = 0; 

   int counter14BVetoBCUp = 0; 
   int counter14BVetoBCDown = 0; 
   int counter14BVetoLightUp = 0; 
   int counter14BVetoLightDown = 0; 

   int counter15BVetoBCUp = 0; 
   int counter15BVetoBCDown = 0; 
   int counter15BVetoLightUp = 0; 
   int counter15BVetoLightDown = 0; 

   int counter16BVetoBCUp = 0; 
   int counter16BVetoBCDown = 0; 
   int counter16BVetoLightUp = 0; 
   int counter16BVetoLightDown = 0; 



   for (int i = 0 ; i < theInputTree->GetEntries() ; i++){


        ReadEvent(theInputTree,i,&pointers,&myEvent);


        if (string(argv[1]).find("ttbar_madgraph") != std::string::npos)   	{sampleName = "ttbar_madgraph"; } 
        if (string(argv[1]).find("SingleElec") != std::string::npos) 		{sampleName = "SingleElec"; } 
        if (string(argv[1]).find("SingleMuon") != std::string::npos) 		{sampleName = "SingleMuon";} 
        if (string(argv[1]).find("DoubleElec") != std::string::npos) 		{sampleName = "DoubleElec";} 
        if (string(argv[1]).find("DoubleMuon") != std::string::npos) 		{sampleName = "DoubleMuon";} 
        if (string(argv[1]).find("MuEl") != std::string::npos) 	     		{sampleName = "MuEl";} 
        if (string(argv[1]).find("T2") != std::string::npos) 	     		{sampleType = "signal";} 
        if ( (sampleName == "SingleElec") || (sampleName == "SingleMuon") 
	  || (sampleName == "DoubleElec") || (sampleName == "DoubleMuon") 
	  || (sampleName == "MuEl")) {						 sampleType = "data"; } 



	     int genset_ = -999;
	     int set_ = -999;

	     LHAPDF::initPDFSetM(genset_, "CT10nlo");
  	     LHAPDF::initPDFM(genset_, 0); 
	     LHAPDF::initPDFSetM(set_, "CT10nlo");
	     LHAPDF::initPDFM(set_,2);

             double fx1Q0gen = LHAPDF::xfxM(genset_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton;
             double fx2Q0gen = LHAPDF::xfxM(genset_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton;

             double fx1Qi = LHAPDF::xfxM(set_, myEvent.x_firstIncomingParton, myEvent.scalePDF, myEvent.flavor_firstIncomingParton) / myEvent.x_firstIncomingParton; 
             double fx2Qi = LHAPDF::xfxM(set_, myEvent.x_secondIncomingParton, myEvent.scalePDF, myEvent.flavor_secondIncomingParton) / myEvent.x_secondIncomingParton; 
         
    	     // calculate weight from ratio
             //double pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));
             double pdf_weight = ((fx1Qi*fx2Qi)/(fx1Q0gen*fx2Q0gen));
             //double pdf_weight = ((fx1Q0gen*fx2Q0gen));

	     cout << pdf_weight << endl;


			double width = fabs(myEvent.mNeutralino - 1);
		        if (width < 0.1) myEvent.mNeutralino = 0; // For the MLSP=0 plane	


			if ( (sampleType == "signal")  &&  !((myEvent.mStop ==  atoi(argv[3]) ) && (myEvent.mNeutralino ==  atoi(argv[4]) )) )continue;
				
			if (goesInPreselectionMTtail() == true) {
			
				Events_NGenSignal->Fill( myEvent.numberOfInitialEvents);

				counter ++;
				Events_NSignal->Fill(  counter);
				Events_Preselection->Fill(  counter , getWeight());

				if ( cutAndCount_T2tt_offShellLoose(true) == true){ 
				counter1 ++;
				Events_T2tt_offShellLoose->Fill(counter1, getWeight());
				}

				if ( cutAndCount_T2tt_offShellTight(true) == true){
				counter2 ++;
				Events_T2tt_offShellTight->Fill(counter2, getWeight());
				}	
				
				if ( cutAndCount_T2tt_lowDeltaM(true) == true){
				counter3 ++;
				Events_T2tt_lowDeltaM->Fill(counter3, getWeight());
				}	

				if ( cutAndCount_T2tt_mediumDeltaM(true) == true){
				counter4 ++;
				Events_T2tt_mediumDeltaM->Fill(counter4, getWeight());
				}	

				if ( cutAndCount_T2tt_highDeltaM(true) == true){
				counter5 ++;
				Events_T2tt_highDeltaM->Fill(counter5, getWeight());
				}	

				if ( cutAndCount_T2bw025_offShell(true) == true){
				counter7 ++;
				Events_T2bw025_offShell->Fill(counter7, getWeight());
				}

				if ( cutAndCount_T2bw025_lowMasses(true) == true){
				counter8 ++;
				Events_T2bw025_lowMasses->Fill(counter8, getWeight());
				}

				if ( cutAndCount_T2bw025_highMasses(true) == true){
				counter9 ++;
				Events_T2bw025_highMasses->Fill(counter9, getWeight());
				}

		
				if ( cutAndCount_T2bw050_offShell(true) == true){
				counter10 ++;
				Events_T2bw050_offShell->Fill(counter10, getWeight());
				}

				if ( cutAndCount_T2bw050_lowMasses(true) == true){
				counter11 ++;
				Events_T2bw050_lowMasses->Fill(counter11, getWeight());
				}

				if ( cutAndCount_T2bw050_mediumDeltaM(true) == true){
				counter12 ++;
				Events_T2bw050_mediumDeltaM->Fill(counter12, getWeight());
				}

				if ( cutAndCount_T2bw050_highDeltaM(true) == true){
				counter13 ++;
				Events_T2bw050_highDeltaM->Fill(counter13, getWeight());
				}


				if ( cutAndCount_T2bw075_lowDeltaM(true) == true){
				counter14 ++;
				Events_T2bw075_lowDeltaM->Fill(counter14, getWeight());
				}

				if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){
				counter15 ++;
				Events_T2bw075_mediumDeltaM->Fill(counter15, getWeight());
				}

				if ( cutAndCount_T2bw075_highDeltaM(true) == true){
				counter16 ++;
				Events_T2bw075_highDeltaM->Fill(counter16, getWeight());
				}

				
				// BDT STUFF
				
					if (myEvent.isUsedInBDTTraining == 0) {
					double weight = getWeight() * 2.; 


					hist_BDT_output_t2bw025_R1_RAW->Fill(myEvent.BDT_output_t2bw025_R1);		
					hist_BDT_output_t2bw025_R3_RAW->Fill(myEvent.BDT_output_t2bw025_R3);		
					hist_BDT_output_t2bw025_R4_RAW->Fill(myEvent.BDT_output_t2bw025_R4);		
					hist_BDT_output_t2bw025_R6_RAW->Fill(myEvent.BDT_output_t2bw025_R6);		

					hist_BDT_output_t2bw050_R1_RAW->Fill(myEvent.BDT_output_t2bw050_R1);		
					hist_BDT_output_t2bw050_R3_RAW->Fill(myEvent.BDT_output_t2bw050_R3);		
					hist_BDT_output_t2bw050_R4_RAW->Fill(myEvent.BDT_output_t2bw050_R4);		
					hist_BDT_output_t2bw050_R5_RAW->Fill(myEvent.BDT_output_t2bw050_R5);		
					hist_BDT_output_t2bw050_R6_RAW->Fill(myEvent.BDT_output_t2bw050_R6);		

					hist_BDT_output_t2bw075_R1_RAW->Fill(myEvent.BDT_output_t2bw075_R1);		
					hist_BDT_output_t2bw075_R2_RAW->Fill(myEvent.BDT_output_t2bw075_R2);		
					hist_BDT_output_t2bw075_R3_RAW->Fill(myEvent.BDT_output_t2bw075_R3);		
					hist_BDT_output_t2bw075_R5_RAW->Fill(myEvent.BDT_output_t2bw075_R5);		

					hist_BDT_output_t2tt_R1_RAW->Fill(myEvent.BDT_output_t2tt_R1);		
					hist_BDT_output_t2tt_R2_RAW->Fill(myEvent.BDT_output_t2tt_R2);		
					hist_BDT_output_t2tt_R5_RAW->Fill(myEvent.BDT_output_t2tt_R5);		

					hist_BDT_output_t2bw025_R1->Fill(myEvent.BDT_output_t2bw025_R1, weight);		
					hist_BDT_output_t2bw025_R3->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
					hist_BDT_output_t2bw025_R4->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
					hist_BDT_output_t2bw025_R6->Fill(myEvent.BDT_output_t2bw025_R6, weight);		

					hist_BDT_output_t2bw050_R1->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
					hist_BDT_output_t2bw050_R3->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
					hist_BDT_output_t2bw050_R4->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
					hist_BDT_output_t2bw050_R5->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
					hist_BDT_output_t2bw050_R6->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

					hist_BDT_output_t2bw075_R1->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
					hist_BDT_output_t2bw075_R2->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
					hist_BDT_output_t2bw075_R3->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
					hist_BDT_output_t2bw075_R5->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

					hist_BDT_output_t2tt_R1->Fill(myEvent.BDT_output_t2tt_R1, weight);		
					hist_BDT_output_t2tt_R2->Fill(myEvent.BDT_output_t2tt_R2, weight);		
					hist_BDT_output_t2tt_R5->Fill(myEvent.BDT_output_t2tt_R5, weight);		

					hist_BDT_output_t2bw025_R1JESUp->Fill(myEvent.BDT_output_t2bw025_R1_JESup, weight);
					hist_BDT_output_t2bw025_R3JESUp->Fill(myEvent.BDT_output_t2bw025_R3_JESup, weight);		
					hist_BDT_output_t2bw025_R4JESUp->Fill(myEvent.BDT_output_t2bw025_R4_JESup, weight);		
					hist_BDT_output_t2bw025_R6JESUp->Fill(myEvent.BDT_output_t2bw025_R6_JESup, weight);		

					hist_BDT_output_t2bw050_R1JESUp->Fill(myEvent.BDT_output_t2bw050_R1_JESup, weight);		
					hist_BDT_output_t2bw050_R3JESUp->Fill(myEvent.BDT_output_t2bw050_R3_JESup, weight);		
					hist_BDT_output_t2bw050_R4JESUp->Fill(myEvent.BDT_output_t2bw050_R4_JESup, weight);		
					hist_BDT_output_t2bw050_R5JESUp->Fill(myEvent.BDT_output_t2bw050_R5_JESup, weight);		
					hist_BDT_output_t2bw050_R6JESUp->Fill(myEvent.BDT_output_t2bw050_R6_JESup, weight);		

					hist_BDT_output_t2bw075_R1JESUp->Fill(myEvent.BDT_output_t2bw075_R1_JESup, weight);		
					hist_BDT_output_t2bw075_R2JESUp->Fill(myEvent.BDT_output_t2bw075_R2_JESup, weight);		
					hist_BDT_output_t2bw075_R3JESUp->Fill(myEvent.BDT_output_t2bw075_R3_JESup, weight);		
					hist_BDT_output_t2bw075_R5JESUp->Fill(myEvent.BDT_output_t2bw075_R5_JESup, weight);		

					hist_BDT_output_t2tt_R1JESUp->Fill(myEvent.BDT_output_t2tt_R1_JESup, weight);		
					hist_BDT_output_t2tt_R2JESUp->Fill(myEvent.BDT_output_t2tt_R2_JESup, weight);		
					hist_BDT_output_t2tt_R5JESUp->Fill(myEvent.BDT_output_t2tt_R5_JESup, weight);		


					hist_BDT_output_t2bw025_R1JESDown->Fill(myEvent.BDT_output_t2bw025_R1_JESdown, weight);
					hist_BDT_output_t2bw025_R3JESDown->Fill(myEvent.BDT_output_t2bw025_R3_JESdown, weight);		
					hist_BDT_output_t2bw025_R4JESDown->Fill(myEvent.BDT_output_t2bw025_R4_JESdown, weight);		
					hist_BDT_output_t2bw025_R6JESDown->Fill(myEvent.BDT_output_t2bw025_R6_JESdown, weight);		

					hist_BDT_output_t2bw050_R1JESDown->Fill(myEvent.BDT_output_t2bw050_R1_JESdown, weight);		
					hist_BDT_output_t2bw050_R3JESDown->Fill(myEvent.BDT_output_t2bw050_R3_JESdown, weight);		
					hist_BDT_output_t2bw050_R4JESDown->Fill(myEvent.BDT_output_t2bw050_R4_JESdown, weight);		
					hist_BDT_output_t2bw050_R5JESDown->Fill(myEvent.BDT_output_t2bw050_R5_JESdown, weight);		
					hist_BDT_output_t2bw050_R6JESDown->Fill(myEvent.BDT_output_t2bw050_R6_JESdown, weight);		

					hist_BDT_output_t2bw075_R1JESDown->Fill(myEvent.BDT_output_t2bw075_R1_JESdown, weight);		
					hist_BDT_output_t2bw075_R2JESDown->Fill(myEvent.BDT_output_t2bw075_R2_JESdown, weight);		
					hist_BDT_output_t2bw075_R3JESDown->Fill(myEvent.BDT_output_t2bw075_R3_JESdown, weight);		
					hist_BDT_output_t2bw075_R5JESDown->Fill(myEvent.BDT_output_t2bw075_R5_JESdown, weight);		

					hist_BDT_output_t2tt_R1JESDown->Fill(myEvent.BDT_output_t2tt_R1_JESdown, weight);		
					hist_BDT_output_t2tt_R2JESDown->Fill(myEvent.BDT_output_t2tt_R2_JESdown, weight);		
					hist_BDT_output_t2tt_R5JESDown->Fill(myEvent.BDT_output_t2tt_R5_JESdown, weight);		
					}
				} 



				int nBJetsUpBC = 0;
				int nBJetsDownBC = 0;
				int nBJetsUpLight = 0;
				int nBJetsDownLight = 0;
	
				for (unsigned i=0; i < myEvent.jets_CSV_reshapedUpBC.size(); i++) {
					     if (myEvent.jets_CSV_reshapedUpBC[i] > 0.679 ) 

						nBJetsUpBC++;			 
				}	

				for (unsigned i=0; i < myEvent.jets_CSV_reshapedDownBC.size(); i++) {
					     if (myEvent.jets_CSV_reshapedDownBC[i] > 0.679 ) 

						nBJetsDownBC++;			 
				}	


				for (unsigned i=0; i < myEvent.jets_CSV_reshapedUpLight.size(); i++) {
					     if (myEvent.jets_CSV_reshapedUpLight[i] > 0.679 ) 

						nBJetsUpLight++;			 
				}	


				for (unsigned i=0; i < myEvent.jets_CSV_reshapedDownLight.size(); i++) {
					     if (myEvent.jets_CSV_reshapedDownLight[i] > 0.679 ) 

						nBJetsDownLight++;			 
				}
	
				/*
				cout <<  "nBTag: " << myEvent.nBTag << endl;
				cout <<  "nBJetsUpBC: " << nBJetsUpBC << endl;
				cout <<  "nBJetsDownBC: " << nBJetsDownBC << endl;
				cout <<  "nBJetsUpLight: " << nBJetsUpLight << endl;
				cout <<  "nBJetsDownLight: " << nBJetsDownLight << endl;
				*/

				if (goesInPreselectionMTtailNoBeto() == true){

				if ( cutAndCount_T2tt_offShellLoose(true) == true){ 

					if (nBJetsUpBC > 0 ){ 
						counter1BVetoBCUp ++;
						Events_T2tt_offShellLooseBVetoBCUp->Fill(counter1BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter1BVetoBCDown ++;
						Events_T2tt_offShellLooseBVetoBCDown->Fill(counter1BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter1BVetoLightUp ++;
						Events_T2tt_offShellLooseBVetoLightUp->Fill(counter1BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter1BVetoLightDown ++;
						Events_T2tt_offShellLooseBVetoLightDown->Fill(counter1BVetoLightDown, getWeight());
					}

			  	}



				if ( cutAndCount_T2tt_offShellTight(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter2BVetoBCUp ++;
						Events_T2tt_offShellTightBVetoBCUp->Fill(counter2BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter2BVetoBCDown ++;
						Events_T2tt_offShellTightBVetoBCDown->Fill(counter2BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter2BVetoLightUp ++;
						Events_T2tt_offShellTightBVetoLightUp->Fill(counter2BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter2BVetoLightDown ++;
						Events_T2tt_offShellTightBVetoLightDown->Fill(counter2BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2tt_lowDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter3BVetoBCUp ++;
						Events_T2tt_lowDeltaMBVetoBCUp->Fill(counter3BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter3BVetoBCDown ++;
						Events_T2tt_lowDeltaMBVetoBCDown->Fill(counter3BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter3BVetoLightUp ++;
						Events_T2tt_lowDeltaMBVetoLightUp->Fill(counter3BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter3BVetoLightDown ++;
						Events_T2tt_lowDeltaMBVetoLightDown->Fill(counter3BVetoLightDown, getWeight());
					}

			  	}



				if ( cutAndCount_T2tt_mediumDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter4BVetoBCUp ++;
						Events_T2tt_mediumDeltaMBVetoBCUp->Fill(counter4BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter4BVetoBCDown ++;
						Events_T2tt_mediumDeltaMBVetoBCDown->Fill(counter4BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter4BVetoLightUp ++;
						Events_T2tt_mediumDeltaMBVetoLightUp->Fill(counter4BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter4BVetoLightDown ++;
						Events_T2tt_mediumDeltaMBVetoLightDown->Fill(counter4BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2tt_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter5BVetoBCUp ++;
						Events_T2tt_highDeltaMBVetoBCUp->Fill(counter5BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter5BVetoBCDown ++;
						Events_T2tt_highDeltaMBVetoBCDown->Fill(counter5BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter5BVetoLightUp ++;
						Events_T2tt_highDeltaMBVetoLightUp->Fill(counter5BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter5BVetoLightDown ++;
						Events_T2tt_highDeltaMBVetoLightDown->Fill(counter5BVetoLightDown, getWeight());
					}

			  	}




				if ( cutAndCount_T2bw025_offShell(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter7BVetoBCUp ++;
						Events_T2bw025_offShellBVetoBCUp->Fill(counter7BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter7BVetoBCDown ++;
						Events_T2bw025_offShellBVetoBCDown->Fill(counter7BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter7BVetoLightUp ++;
						Events_T2bw025_offShellBVetoLightUp->Fill(counter7BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter7BVetoLightDown ++;
						Events_T2bw025_offShellBVetoLightDown->Fill(counter7BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw025_lowMasses(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter8BVetoBCUp ++;
						Events_T2bw025_lowMassesBVetoBCUp->Fill(counter8BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter8BVetoBCDown ++;
						Events_T2bw025_lowMassesBVetoBCDown->Fill(counter8BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter8BVetoLightUp ++;
						Events_T2bw025_lowMassesBVetoLightUp->Fill(counter8BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter8BVetoLightDown ++;
						Events_T2bw025_lowMassesBVetoLightDown->Fill(counter8BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw025_highMasses(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter9BVetoBCUp ++;
						Events_T2bw025_highMassesBVetoBCUp->Fill(counter9BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter9BVetoBCDown ++;
						Events_T2bw025_highMassesBVetoBCDown->Fill(counter9BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter9BVetoLightUp ++;
						Events_T2bw025_highMassesBVetoLightUp->Fill(counter9BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter9BVetoLightDown ++;
						Events_T2bw025_highMassesBVetoLightDown->Fill(counter9BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_offShell(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter10BVetoBCUp ++;
						Events_T2bw050_offShellBVetoBCUp->Fill(counter10BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter10BVetoBCDown ++;
						Events_T2bw050_offShellBVetoBCDown->Fill(counter10BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter10BVetoLightUp ++;
						Events_T2bw050_offShellBVetoLightUp->Fill(counter10BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter10BVetoLightDown ++;
						Events_T2bw050_offShellBVetoLightDown->Fill(counter10BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw050_lowMasses(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter11BVetoBCUp ++;
						Events_T2bw050_lowMassesBVetoBCUp->Fill(counter11BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter11BVetoBCDown ++;
						Events_T2bw050_lowMassesBVetoBCDown->Fill(counter11BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter11BVetoLightUp ++;
						Events_T2bw050_lowMassesBVetoLightUp->Fill(counter11BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter11BVetoLightDown ++;
						Events_T2bw050_lowMassesBVetoLightDown->Fill(counter11BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_mediumDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter12BVetoBCUp ++;
						Events_T2bw050_mediumDeltaMBVetoBCUp->Fill(counter12BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter12BVetoBCDown ++;
						Events_T2bw050_mediumDeltaMBVetoBCDown->Fill(counter12BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter12BVetoLightUp ++;
						Events_T2bw050_mediumDeltaMBVetoLightUp->Fill(counter12BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter12BVetoLightDown ++;
						Events_T2bw050_mediumDeltaMBVetoLightDown->Fill(counter12BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter13BVetoBCUp ++;
						Events_T2bw050_highDeltaMBVetoBCUp->Fill(counter13BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter13BVetoBCDown ++;
						Events_T2bw050_highDeltaMBVetoBCDown->Fill(counter13BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter13BVetoLightUp ++;
						Events_T2bw050_highDeltaMBVetoLightUp->Fill(counter13BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter13BVetoLightDown ++;
						Events_T2bw050_highDeltaMBVetoLightDown->Fill(counter13BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw075_lowDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter14BVetoBCUp ++;
						Events_T2bw075_lowDeltaMBVetoBCUp->Fill(counter14BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter14BVetoBCDown ++;
						Events_T2bw075_lowDeltaMBVetoBCDown->Fill(counter14BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter14BVetoLightUp ++;
						Events_T2bw075_lowDeltaMBVetoLightUp->Fill(counter14BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter14BVetoLightDown ++;
						Events_T2bw075_lowDeltaMBVetoLightDown->Fill(counter14BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter15BVetoBCUp ++;
						Events_T2bw075_mediumDeltaMBVetoBCUp->Fill(counter15BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter15BVetoBCDown ++;
						Events_T2bw075_mediumDeltaMBVetoBCDown->Fill(counter15BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter15BVetoLightUp ++;
						Events_T2bw075_mediumDeltaMBVetoLightUp->Fill(counter15BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter15BVetoLightDown ++;
						Events_T2bw075_mediumDeltaMBVetoLightDown->Fill(counter15BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw075_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter16BVetoBCUp ++;
						Events_T2bw075_highDeltaMBVetoBCUp->Fill(counter16BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter16BVetoBCDown ++;
						Events_T2bw075_highDeltaMBVetoBCDown->Fill(counter16BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter16BVetoLightUp ++;
						Events_T2bw075_highDeltaMBVetoLightUp->Fill(counter16BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter16BVetoLightDown ++;
						Events_T2bw075_highDeltaMBVetoLightDown->Fill(counter16BVetoLightDown, getWeight());
					}

			  	}





                                        if (myEvent.isUsedInBDTTraining == 0) {

	//                                if ( (myEvent.event%2)==1 ) continue;

					double weight = getWeight() * 2.; 


					if (nBJetsUpBC > 0 ) {
					hist_BDT_output_t2bw025_R1BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R1, weight);
					hist_BDT_output_t2bw025_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
					hist_BDT_output_t2bw025_R4BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
					hist_BDT_output_t2bw025_R6BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


					hist_BDT_output_t2bw050_R1BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
					hist_BDT_output_t2bw050_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
					hist_BDT_output_t2bw050_R4BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
					hist_BDT_output_t2bw050_R5BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
					hist_BDT_output_t2bw050_R6BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

					hist_BDT_output_t2bw075_R1BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
					hist_BDT_output_t2bw075_R2BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
					hist_BDT_output_t2bw075_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
					hist_BDT_output_t2bw075_R5BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

					hist_BDT_output_t2tt_R1BVetoBCUp->Fill(myEvent.BDT_output_t2tt_R1, weight);		
					hist_BDT_output_t2tt_R2BVetoBCUp->Fill(myEvent.BDT_output_t2tt_R2, weight);		
					hist_BDT_output_t2tt_R5BVetoBCUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		

					}

					if (nBJetsDownBC > 0 ) {
					hist_BDT_output_t2bw025_R1BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R1, weight);
					hist_BDT_output_t2bw025_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
					hist_BDT_output_t2bw025_R4BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
					hist_BDT_output_t2bw025_R6BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R6, weight);		

					hist_BDT_output_t2bw050_R1BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
					hist_BDT_output_t2bw050_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
					hist_BDT_output_t2bw050_R4BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
					hist_BDT_output_t2bw050_R5BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
					hist_BDT_output_t2bw050_R6BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

					hist_BDT_output_t2bw075_R1BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
					hist_BDT_output_t2bw075_R2BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
					hist_BDT_output_t2bw075_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
					hist_BDT_output_t2bw075_R5BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

					hist_BDT_output_t2tt_R1BVetoBCDown->Fill(myEvent.BDT_output_t2tt_R1, weight);		
					hist_BDT_output_t2tt_R2BVetoBCDown->Fill(myEvent.BDT_output_t2tt_R2, weight);		
					hist_BDT_output_t2tt_R5BVetoBCDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		

					}

					if (nBJetsUpLight > 0 ) {
					hist_BDT_output_t2bw025_R1BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R1, weight);
					hist_BDT_output_t2bw025_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
					hist_BDT_output_t2bw025_R4BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
					hist_BDT_output_t2bw025_R6BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


					hist_BDT_output_t2bw050_R1BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
					hist_BDT_output_t2bw050_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
					hist_BDT_output_t2bw050_R4BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
					hist_BDT_output_t2bw050_R5BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
					hist_BDT_output_t2bw050_R6BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

					hist_BDT_output_t2bw075_R1BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
					hist_BDT_output_t2bw075_R2BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
					hist_BDT_output_t2bw075_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
					hist_BDT_output_t2bw075_R5BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

					hist_BDT_output_t2tt_R1BVetoLightUp->Fill(myEvent.BDT_output_t2tt_R1, weight);		
					hist_BDT_output_t2tt_R2BVetoLightUp->Fill(myEvent.BDT_output_t2tt_R2, weight);		
					hist_BDT_output_t2tt_R5BVetoLightUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		
					}

					if (nBJetsDownLight > 0 ) {
					hist_BDT_output_t2bw025_R1BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R1, weight);
					hist_BDT_output_t2bw025_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
					hist_BDT_output_t2bw025_R4BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
					hist_BDT_output_t2bw025_R6BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


					hist_BDT_output_t2bw050_R1BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
					hist_BDT_output_t2bw050_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
					hist_BDT_output_t2bw050_R4BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
					hist_BDT_output_t2bw050_R5BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
					hist_BDT_output_t2bw050_R6BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

					hist_BDT_output_t2bw075_R1BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
					hist_BDT_output_t2bw075_R2BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
					hist_BDT_output_t2bw075_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
					hist_BDT_output_t2bw075_R5BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

					hist_BDT_output_t2tt_R1BVetoLightDown->Fill(myEvent.BDT_output_t2tt_R1, weight);		
					hist_BDT_output_t2tt_R2BVetoLightDown->Fill(myEvent.BDT_output_t2tt_R2, weight);		
					hist_BDT_output_t2tt_R5BVetoLightDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		

					}

				}
			}			



			if (goesInPreselectionMTtail() == true) {
		
				    myEvent.MET = myEvent.MET_JESup;                          
				    myEvent.MT = myEvent.MT_JESup;                         
				    myEvent.deltaPhiMETJets= myEvent.deltaPhiMETJets_JESup;            
				    myEvent.hadronicChi2 = myEvent.hadronicChi2_JESup;               
				    myEvent.MT2W = myEvent.MT2W_JESup;                       
				    myEvent.HT = myEvent.HT_JESup;                         
				    myEvent.HTRatio = myEvent.HTRatio_JESup;                    
				    myEvent.leadingBPt= myEvent.leadingBPt_JESup;                 
				    myEvent.leadingJetPt= myEvent.leadingJetPt_JESup;               
				    myEvent.Mlb = myEvent.Mlb_JESup;                        
				    myEvent.Mlb_hemi = myEvent.Mlb_hemi_JESup;                   
				    myEvent.M3b = myEvent.M3b_JESup;                        
				    myEvent.deltaRLeptonLeadingB= myEvent.deltaRLeptonLeadingB_JESup;       
				    myEvent.METoverSqrtHT= myEvent.METoverSqrtHT_JESup;              
				    myEvent.HTPlusLeptonPtPlusMET = myEvent.HTPlusLeptonPtPlusMET_JESup;      
				    myEvent.nJets = myEvent.nJets_JESup;  	

				if ( cutAndCount_T2tt_offShellLoose(true) == true){ 
				counter1JESUp ++;
				Events_T2tt_offShellLooseJESUp->Fill(counter1JESUp, getWeight());
				}

				if ( cutAndCount_T2tt_offShellTight(true) == true){
				counter2JESUp ++;
				Events_T2tt_offShellTightJESUp->Fill(counter2JESUp, getWeight());
				}	
				
				if ( cutAndCount_T2tt_lowDeltaM(true) == true){
				counter3JESUp ++;
				Events_T2tt_lowDeltaMJESUp->Fill(counter3JESUp, getWeight());
				}	

				if ( cutAndCount_T2tt_mediumDeltaM(true) == true){
				counter4JESUp ++;
				Events_T2tt_mediumDeltaMJESUp->Fill(counter4JESUp, getWeight());
				}	

				if ( cutAndCount_T2tt_highDeltaM(true) == true){
				counter5JESUp ++;
				Events_T2tt_highDeltaMJESUp->Fill(counter5JESUp, getWeight());
				}	

				if ( cutAndCount_T2bw025_offShell(true) == true){
				counter7JESUp ++;
				Events_T2bw025_offShellJESUp->Fill(counter7JESUp, getWeight());
				}

				if ( cutAndCount_T2bw025_lowMasses(true) == true){
				counter8JESUp ++;
				Events_T2bw025_lowMassesJESUp->Fill(counter8JESUp, getWeight());
				}

				if ( cutAndCount_T2bw025_highMasses(true) == true){
				counter9JESUp ++;
				Events_T2bw025_highMassesJESUp->Fill(counter9JESUp, getWeight());
				}

		
				if ( cutAndCount_T2bw050_offShell(true) == true){
				counter10JESUp ++;
				Events_T2bw050_offShellJESUp->Fill(counter10JESUp, getWeight());
				}

				if ( cutAndCount_T2bw050_lowMasses(true) == true){
				counter11JESUp ++;
				Events_T2bw050_lowMassesJESUp->Fill(counter11JESUp, getWeight());
				}

				if ( cutAndCount_T2bw050_mediumDeltaM(true) == true){
				counter12JESUp ++;
				Events_T2bw050_mediumDeltaMJESUp->Fill(counter12JESUp, getWeight());
				}

				if ( cutAndCount_T2bw050_highDeltaM(true) == true){
				counter13JESUp ++;
				Events_T2bw050_highDeltaMJESUp->Fill(counter13JESUp, getWeight());
				}


				if ( cutAndCount_T2bw075_lowDeltaM(true) == true){
				counter14JESUp ++;
				Events_T2bw075_lowDeltaMJESUp->Fill(counter14JESUp, getWeight());
				}

				if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){
				counter15JESUp ++;
				Events_T2bw075_mediumDeltaMJESUp->Fill(counter15JESUp, getWeight());
				}

				if ( cutAndCount_T2bw075_highDeltaM(true) == true){
				counter16JESUp ++;
				Events_T2bw075_highDeltaMJESUp->Fill(counter16JESUp, getWeight());
				}


				    myEvent.MET = myEvent.MET_JESdown;                          
				    myEvent.MT = myEvent.MT_JESdown;                         
				    myEvent.deltaPhiMETJets= myEvent.deltaPhiMETJets_JESdown;            
				    myEvent.hadronicChi2 = myEvent.hadronicChi2_JESdown;               
				    myEvent.MT2W = myEvent.MT2W_JESdown;                       
				    myEvent.HT = myEvent.HT_JESdown;                         
				    myEvent.HTRatio = myEvent.HTRatio_JESdown;                    
				    myEvent.leadingBPt= myEvent.leadingBPt_JESdown;                 
				    myEvent.leadingJetPt= myEvent.leadingJetPt_JESdown;               
				    myEvent.Mlb = myEvent.Mlb_JESdown;                        
				    myEvent.Mlb_hemi = myEvent.Mlb_hemi_JESdown;                   
				    myEvent.M3b = myEvent.M3b_JESdown;                        
				    myEvent.deltaRLeptonLeadingB= myEvent.deltaRLeptonLeadingB_JESdown;       
				    myEvent.METoverSqrtHT= myEvent.METoverSqrtHT_JESdown;              
				    myEvent.HTPlusLeptonPtPlusMET = myEvent.HTPlusLeptonPtPlusMET_JESdown;      
				    myEvent.nJets = myEvent.nJets_JESdown;  	

				if ( cutAndCount_T2tt_offShellLoose(true) == true){ 
				counter1JESDown ++;
				Events_T2tt_offShellLooseJESDown->Fill(counter1JESDown, getWeight());
				}

				if ( cutAndCount_T2tt_offShellTight(true) == true){
				counter2JESDown ++;
				Events_T2tt_offShellTightJESDown->Fill(counter2JESDown, getWeight());
				}	
				
				if ( cutAndCount_T2tt_lowDeltaM(true) == true){
				counter3JESDown ++;
				Events_T2tt_lowDeltaMJESDown->Fill(counter3JESDown, getWeight());
				}	

				if ( cutAndCount_T2tt_mediumDeltaM(true) == true){
				counter4JESDown ++;
				Events_T2tt_mediumDeltaMJESDown->Fill(counter4JESDown, getWeight());
				}	

				if ( cutAndCount_T2tt_highDeltaM(true) == true){
				counter5JESDown ++;
				Events_T2tt_highDeltaMJESDown->Fill(counter5JESDown, getWeight());
				}	

				if ( cutAndCount_T2bw025_offShell(true) == true){
				counter7JESDown ++;
				Events_T2bw025_offShellJESDown->Fill(counter7JESDown, getWeight());
				}

				if ( cutAndCount_T2bw025_lowMasses(true) == true){
				counter8JESDown ++;
				Events_T2bw025_lowMassesJESDown->Fill(counter8JESDown, getWeight());
				}

				if ( cutAndCount_T2bw025_highMasses(true) == true){
				counter9JESDown ++;
				Events_T2bw025_highMassesJESDown->Fill(counter9JESDown, getWeight());
				}

		
				if ( cutAndCount_T2bw050_offShell(true) == true){
				counter10JESDown ++;
				Events_T2bw050_offShellJESDown->Fill(counter10JESDown, getWeight());
				}

				if ( cutAndCount_T2bw050_lowMasses(true) == true){
				counter11JESDown ++;
				Events_T2bw050_lowMassesJESDown->Fill(counter11JESDown, getWeight());
				}

				if ( cutAndCount_T2bw050_mediumDeltaM(true) == true){
				counter12JESDown ++;
				Events_T2bw050_mediumDeltaMJESDown->Fill(counter12JESDown, getWeight());
				}

				if ( cutAndCount_T2bw050_highDeltaM(true) == true){
				counter13JESDown ++;
				Events_T2bw050_highDeltaMJESDown->Fill(counter13JESDown, getWeight());
				}


				if ( cutAndCount_T2bw075_lowDeltaM(true) == true){
				counter14JESDown ++;
				Events_T2bw075_lowDeltaMJESDown->Fill(counter14JESDown, getWeight());
				}

				if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){
				counter15JESDown ++;
				Events_T2bw075_mediumDeltaMJESDown->Fill(counter15JESDown, getWeight());
				}

				if ( cutAndCount_T2bw075_highDeltaM(true) == true){
				counter16JESDown ++;
				Events_T2bw075_highDeltaMJESDown->Fill(counter16JESDown, getWeight());
				}
				
			} 



 } 

    
      fout->cd();
      fout->Write();
      fout->Close();



      return (0);

}



