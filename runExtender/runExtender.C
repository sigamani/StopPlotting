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


// Define format of input file
#include "../Reader.h" 

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

//  TFile *file = TFile::Open("root://eoscms//eos/cms/store/caf/user/oglez/test/test.root");


  babyEvent myEvent;
  intermediatePointers pointers;
  InitializeBranchesForReading(theInputTree,&myEvent,&pointers);

  TTree* theOutputTree = new TTree("babyTuple","");
  InitializeBranchesForWriting(theOutputTree,&myEvent);


   Float_t met_phi;
   Float_t met_signif;
   Float_t phi_lepton_met;
   Float_t lepton_pT;
   Float_t lepton_phi;
   Float_t nbjets;
   Float_t mlpjpa;
   Float_t dphiljpa;
   Float_t dphiljb;
   Float_t dphimetl;
   Float_t missmass;
   Float_t mjetlepmax;
   Float_t m3;
   Float_t m3_pt;
   Float_t mi34;
   Float_t mi34b;
   Float_t mi34b_m2;
   Float_t m3topW ;
   Float_t jet1_pT ;
   Float_t jet2_pT ;
   Float_t jet3_pT ;
   Float_t jet4_pT ;
   Float_t jet1_phi ;
   Float_t jet2_phi ;
   Float_t jet3_phi ;
   Float_t jet4_phi ;

   Float_t b2_pt;
   Float_t b1_eta;
   Float_t b1plusb2_pt;
   Float_t dR_b1b2;
   Float_t dPhi_b1b2;

   Float_t b1_pt_2;
   Float_t b2_pt_2;
   Float_t b1_eta_2;
   Float_t b1plusb2_pt_2;
   Float_t dR_b1b2_2;
   Float_t dPhi_b1b2_2;
   Float_t mlb1_2;

   Float_t HT;
   Float_t HT_av;
   Float_t HT_MET_lep_pt;


   Float_t mlb_hemi;
   Float_t HTfrac;
   Float_t HTfrac_FNAL;
   Float_t chargino_mixing;
   Float_t mT2;
   Float_t mT2bl;
   Float_t mT2W;
   Float_t dR_LepB;
   Float_t dR_LepJet;
   Float_t dPhi_JetMet;
   Float_t METoverSqrtHT;
   Float_t Chi2SNT;

   Float_t met;
   Float_t mT;
   Float_t b1_pt;
   Float_t m3b;
   Float_t njets;
   Float_t stop_mass;
   Float_t lsp_mass;



   double BDT_output_t2bw025_R1;
   double BDT_output_t2bw025_R3;
   double BDT_output_t2bw025_R4;
   double BDT_output_t2bw025_R6;

   double BDT_output_t2bw050_R1;
   double BDT_output_t2bw050_R3;
   double BDT_output_t2bw050_R4;
   double BDT_output_t2bw050_R5;
   double BDT_output_t2bw050_R6;

   double BDT_output_t2bw075_R1;
   double BDT_output_t2bw075_R2;
   double BDT_output_t2bw075_R3;
   double BDT_output_t2bw075_R5;

   double BDT_output_t2tt_R1;
   double BDT_output_t2tt_R2;
   double BDT_output_t2tt_R5;


   Reader* reader;
   reader = new Reader("V");

   Reader* reader_t2bw050;
   reader_t2bw050 = new Reader("V");

   Reader* reader_t2bw075;
   reader_t2bw075 = new Reader("V");

   Reader* reader_t2ttOffShell;
   reader_t2ttOffShell = new Reader("V");
   Reader* reader_t2ttOnShell;
   reader_t2ttOnShell = new Reader("V");

    string NN_vars = string(argv[3]);
    TString str_NNvariables = TString(NN_vars);
    TPMERegexp _variables(",");

    string NN_vars_t2bw050 = string(argv[4]);
    TString str_NNvariables_t2bw050 = TString(NN_vars_t2bw050);
    TPMERegexp _variables_t2bw050(",");

    string NN_vars_t2bw075 = string(argv[5]);
    TString str_NNvariables_t2bw075 = TString(NN_vars_t2bw075);
    TPMERegexp _variables_t2bw075(",");


    string NN_vars_t2ttOffShell = string(argv[6]);
    TString str_NNvariables_t2ttOffShell = TString(NN_vars_t2ttOffShell);
    TPMERegexp _variables_t2ttOffShell(",");
    string NN_vars_t2ttOnShell = string(argv[7]);
    TString str_NNvariables_t2ttOnShell = TString(NN_vars_t2ttOnShell);
    TPMERegexp _variables_t2ttOnShell(",");


    set<string> NNvariables;
    int nvariables = 0;
    nvariables = _variables.Split(str_NNvariables);
    for(int i=0; i<nvariables; i++){
    NNvariables.insert(_variables[i].Data());
    }

    set<string> NNvariables_t2bw050;
    int nvariables_t2bw050 = 0;
    nvariables_t2bw050 = _variables_t2bw050.Split(str_NNvariables_t2bw050);
    for(int j=0; j<nvariables_t2bw050; j++){
    NNvariables_t2bw050.insert(_variables_t2bw050[j].Data());
    }


    set<string> NNvariables_t2bw075;
    int nvariables_t2bw075 = 0;
    nvariables_t2bw075 = _variables_t2bw075.Split(str_NNvariables_t2bw075);
    for(int j=0; j<nvariables_t2bw075; j++){
    NNvariables_t2bw075.insert(_variables_t2bw075[j].Data());
    }


    set<string> NNvariables_t2ttOffShell;
    int nvariables_t2ttOffShell = 0;
    nvariables_t2ttOffShell = _variables_t2ttOffShell.Split(str_NNvariables_t2ttOffShell);
    for(int j=0; j<nvariables_t2ttOffShell; j++){
    NNvariables_t2ttOffShell.insert(_variables_t2ttOffShell[j].Data());
    }
    set<string> NNvariables_t2ttOnShell;
    int nvariables_t2ttOnShell = 0;
    nvariables_t2ttOnShell = _variables_t2ttOnShell.Split(str_NNvariables_t2ttOnShell);
    for(int j=0; j<nvariables_t2ttOnShell; j++){
    NNvariables_t2ttOnShell.insert(_variables_t2ttOnShell[j].Data());
    }

  if(NNvariables.find("met")!=NNvariables.end())
    reader->AddVariable("met",&met);
  if(NNvariables.find("met_phi")!=NNvariables.end())
    reader->AddVariable("met_phi",&met_phi);
  if(NNvariables.find("met_signif")!=NNvariables.end())
    reader->AddVariable("met_signif",&met_signif);
  if(NNvariables.find("mT")!=NNvariables.end())
    reader->AddVariable("mT",&mT);
  if(NNvariables.find("lepton_pT")!=NNvariables.end())
    reader->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables.find("lepton_phi")!=NNvariables.end())
    reader->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables.find("njets")!=NNvariables.end())
    reader->AddVariable("njets",&njets);
  if(NNvariables.find("nbjets")!=NNvariables.end())
    reader->AddVariable("nbjets",&nbjets);
  if(NNvariables.find("m3")!=NNvariables.end())
    reader->AddVariable("m3",&m3);
  if(NNvariables.find("m3_pt")!=NNvariables.end())
    reader->AddVariable("m3_pt",&m3_pt);
  if(NNvariables.find("m3b")!=NNvariables.end())
    reader->AddVariable("m3b",&m3b);
  if(NNvariables.find("mi34")!=NNvariables.end())
    reader->AddVariable("mi34",&mi34);
  if(NNvariables.find("mi34b")!=NNvariables.end())
    reader->AddVariable("mi34b",&mi34b);
  if(NNvariables.find("mi34b_m2")!=NNvariables.end())
    reader->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables.find("mjetlepmax")!=NNvariables.end())
    reader->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables.find("phi_lepton_met")!=NNvariables.end())
    reader->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables.find("jet1_pT")!=NNvariables.end())
    reader->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables.find("jet2_pT")!=NNvariables.end())
    reader->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables.find("jet3_pT")!=NNvariables.end())
    reader->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables.find("jet4_pT")!=NNvariables.end())
    reader->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables.find("jet1_phi")!=NNvariables.end())
    reader->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables.find("jet2_phi")!=NNvariables.end())
    reader->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables.find("jet3_phi")!=NNvariables.end())
    reader->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables.find("jet4_phi")!=NNvariables.end())
    reader->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables.find("missmass")!=NNvariables.end())
    reader->AddVariable("missmass",&missmass);
  if(NNvariables.find("mlpjpa")!=NNvariables.end())
    reader->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables.find("dphiljpa")!=NNvariables.end())
    reader->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables.find("dphimetl")!=NNvariables.end())
    reader->AddVariable("dphimetl",&dphimetl);
  if(NNvariables.find("dphiljb")!=NNvariables.end())
    reader->AddVariable("dphiljb",&dphiljb);
  if(NNvariables.find("m3topW")!=NNvariables.end())
    reader->AddVariable("m3topW",&m3topW);
  if(NNvariables.find("b1_pt")!=NNvariables.end())
    reader->AddVariable("b1_pt",&b1_pt);
  if(NNvariables.find("b1_pt_2")!=NNvariables.end())
    reader->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables.find("b2_pt")!=NNvariables.end())
    reader->AddVariable("b2_pt",&b2_pt);
  if(NNvariables.find("b2_pt_2")!=NNvariables.end())
    reader->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables.find("b1plusb2_pt")!=NNvariables.end())
    reader->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables.find("b1plusb2_pt_2")!=NNvariables.end())
    reader->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables.find("b1_eta")!=NNvariables.end())
    reader->AddVariable("b1_eta",&b1_eta);
  if(NNvariables.find("b1_eta_2")!=NNvariables.end())
    reader->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables.find("dR_b1b2")!=NNvariables.end())
    reader->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables.find("dR_b1b2_2")!=NNvariables.end())
    reader->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables.find("dPhi_b1b2")!=NNvariables.end())
    reader->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables.find("dPhi_b1b2_2")!=NNvariables.end())
    reader->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables.find("mlb1_2")!=NNvariables.end())
    reader->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables.find("HT_av")!=NNvariables.end())
    reader->AddVariable("HT_av",&HT_av);
  if(NNvariables.find("HT_MET_lep_pt")!=NNvariables.end())
    reader->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables.find("mlb_hemi")!=NNvariables.end())
    reader->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables.find("HTfrac")!=NNvariables.end())
    reader->AddVariable("HTfrac",&HTfrac);
  if(NNvariables.find("HTfrac_FNAL")!=NNvariables.end())
    reader->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables.find("mT2W")!=NNvariables.end())
    reader->AddVariable("mT2W",&mT2W);
  if(NNvariables.find("dR_LepB")!=NNvariables.end())
    reader->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables.find("dR_LepJet")!=NNvariables.end())
    reader->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables.find("dPhi_JetMet")!=NNvariables.end())
    reader->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables.find("METoverSqrtHT")!=NNvariables.end())
    reader->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables.find("Chi2SNT")!=NNvariables.end())
    reader->AddVariable("Chi2SNT",&Chi2SNT);
   if(NNvariables.find("HT")!=NNvariables.end())
    reader->AddVariable("HT",&HT);



  if(NNvariables_t2bw050.find("met")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("met",&met);
  if(NNvariables_t2bw050.find("met_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("met_phi",&met_phi);
  if(NNvariables_t2bw050.find("met_signif")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("met_signif",&met_signif);
  if(NNvariables_t2bw050.find("mT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mT",&mT);
  if(NNvariables_t2bw050.find("lepton_pT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables_t2bw050.find("lepton_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables_t2bw050.find("njets")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("njets",&njets);
  if(NNvariables_t2bw050.find("nbjets")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("nbjets",&nbjets);
  if(NNvariables_t2bw050.find("m3")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("m3",&m3);
  if(NNvariables_t2bw050.find("m3_pt")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("m3_pt",&m3_pt);
  if(NNvariables_t2bw050.find("m3b")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("m3b",&m3b);
  if(NNvariables_t2bw050.find("mi34")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mi34",&mi34);
  if(NNvariables_t2bw050.find("mi34b")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mi34b",&mi34b);
  if(NNvariables_t2bw050.find("mi34b_m2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables_t2bw050.find("mjetlepmax")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables_t2bw050.find("phi_lepton_met")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables_t2bw050.find("jet1_pT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables_t2bw050.find("jet2_pT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables_t2bw050.find("jet3_pT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables_t2bw050.find("jet4_pT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables_t2bw050.find("jet1_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables_t2bw050.find("jet2_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables_t2bw050.find("jet3_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables_t2bw050.find("jet4_phi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables_t2bw050.find("missmass")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("missmass",&missmass);
  if(NNvariables_t2bw050.find("mlpjpa")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables_t2bw050.find("dphiljpa")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables_t2bw050.find("dphimetl")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dphimetl",&dphimetl);
  if(NNvariables_t2bw050.find("dphiljb")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dphiljb",&dphiljb);
  if(NNvariables_t2bw050.find("m3topW")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("m3topW",&m3topW);
  if(NNvariables_t2bw050.find("b1_pt")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1_pt",&b1_pt);
  if(NNvariables_t2bw050.find("b1_pt_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables_t2bw050.find("b2_pt")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b2_pt",&b2_pt);
  if(NNvariables_t2bw050.find("b2_pt_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables_t2bw050.find("b1plusb2_pt")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables_t2bw050.find("b1plusb2_pt_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables_t2bw050.find("b1_eta")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1_eta",&b1_eta);
  if(NNvariables_t2bw050.find("b1_eta_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables_t2bw050.find("dR_b1b2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables_t2bw050.find("dR_b1b2_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables_t2bw050.find("dPhi_b1b2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables_t2bw050.find("dPhi_b1b2_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables_t2bw050.find("mlb1_2")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables_t2bw050.find("HT_av")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("HT_av",&HT_av);
  if(NNvariables_t2bw050.find("HT_MET_lep_pt")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables_t2bw050.find("mlb_hemi")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables_t2bw050.find("HTfrac")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("HTfrac",&HTfrac);
  if(NNvariables_t2bw050.find("HTfrac_FNAL")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables_t2bw050.find("mT2W")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("mT2W",&mT2W);
  if(NNvariables_t2bw050.find("dR_LepB")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables_t2bw050.find("dR_LepJet")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables_t2bw050.find("dPhi_JetMet")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables_t2bw050.find("METoverSqrtHT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables_t2bw050.find("Chi2SNT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("Chi2SNT",&Chi2SNT);
   if(NNvariables_t2bw050.find("HT")!=NNvariables_t2bw050.end())
    reader_t2bw050->AddVariable("HT",&HT);



  if(NNvariables_t2bw075.find("met")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("met",&met);
  if(NNvariables_t2bw075.find("met_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("met_phi",&met_phi);
  if(NNvariables_t2bw075.find("met_signif")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("met_signif",&met_signif);
  if(NNvariables_t2bw075.find("mT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mT",&mT);
  if(NNvariables_t2bw075.find("lepton_pT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables_t2bw075.find("lepton_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables_t2bw075.find("njets")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("njets",&njets);
  if(NNvariables_t2bw075.find("nbjets")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("nbjets",&nbjets);
  if(NNvariables_t2bw075.find("m3")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("m3",&m3);
  if(NNvariables_t2bw075.find("m3_pt")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("m3_pt",&m3_pt);
  if(NNvariables_t2bw075.find("m3b")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("m3b",&m3b);
  if(NNvariables_t2bw075.find("mi34")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mi34",&mi34);
  if(NNvariables_t2bw075.find("mi34b")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mi34b",&mi34b);
  if(NNvariables_t2bw075.find("mi34b_m2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables_t2bw075.find("mjetlepmax")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables_t2bw075.find("phi_lepton_met")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables_t2bw075.find("jet1_pT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables_t2bw075.find("jet2_pT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables_t2bw075.find("jet3_pT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables_t2bw075.find("jet4_pT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables_t2bw075.find("jet1_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables_t2bw075.find("jet2_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables_t2bw075.find("jet3_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables_t2bw075.find("jet4_phi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables_t2bw075.find("missmass")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("missmass",&missmass);
  if(NNvariables_t2bw075.find("mlpjpa")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables_t2bw075.find("dphiljpa")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables_t2bw075.find("dphimetl")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dphimetl",&dphimetl);
  if(NNvariables_t2bw075.find("dphiljb")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dphiljb",&dphiljb);
  if(NNvariables_t2bw075.find("m3topW")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("m3topW",&m3topW);
  if(NNvariables_t2bw075.find("b1_pt")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1_pt",&b1_pt);
  if(NNvariables_t2bw075.find("b1_pt_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables_t2bw075.find("b2_pt")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b2_pt",&b2_pt);
  if(NNvariables_t2bw075.find("b2_pt_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables_t2bw075.find("b1plusb2_pt")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables_t2bw075.find("b1plusb2_pt_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables_t2bw075.find("b1_eta")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1_eta",&b1_eta);
  if(NNvariables_t2bw075.find("b1_eta_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables_t2bw075.find("dR_b1b2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables_t2bw075.find("dR_b1b2_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables_t2bw075.find("dPhi_b1b2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables_t2bw075.find("dPhi_b1b2_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables_t2bw075.find("mlb1_2")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables_t2bw075.find("HT_av")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("HT_av",&HT_av);
  if(NNvariables_t2bw075.find("HT_MET_lep_pt")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables_t2bw075.find("HT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("HT",&HT);
  if(NNvariables_t2bw075.find("mlb_hemi")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables_t2bw075.find("HTfrac")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("HTfrac",&HTfrac);
  if(NNvariables_t2bw075.find("HTfrac_FNAL")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables_t2bw075.find("mT2W")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("mT2W",&mT2W);
  if(NNvariables_t2bw075.find("dR_LepB")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables_t2bw075.find("dR_LepJet")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables_t2bw075.find("dPhi_JetMet")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables_t2bw075.find("METoverSqrtHT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables_t2bw075.find("Chi2SNT")!=NNvariables_t2bw075.end())
    reader_t2bw075->AddVariable("Chi2SNT",&Chi2SNT);


  if(NNvariables_t2ttOffShell.find("met")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("met",&met);
  if(NNvariables_t2ttOffShell.find("met_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("met_phi",&met_phi);
  if(NNvariables_t2ttOffShell.find("met_signif")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("met_signif",&met_signif);
  if(NNvariables_t2ttOffShell.find("mT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mT",&mT);
  if(NNvariables_t2ttOffShell.find("lepton_pT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables_t2ttOffShell.find("lepton_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables_t2ttOffShell.find("njets")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("njets",&njets);
  if(NNvariables_t2ttOffShell.find("nbjets")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("nbjets",&nbjets);
  if(NNvariables_t2ttOffShell.find("m3")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("m3",&m3);
  if(NNvariables_t2ttOffShell.find("m3_pt")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("m3_pt",&m3_pt);
  if(NNvariables_t2ttOffShell.find("m3b")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("m3b",&m3b);
  if(NNvariables_t2ttOffShell.find("mi34")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mi34",&mi34);
  if(NNvariables_t2ttOffShell.find("mi34b")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mi34b",&mi34b);
  if(NNvariables_t2ttOffShell.find("mi34b_m2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables_t2ttOffShell.find("mjetlepmax")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables_t2ttOffShell.find("phi_lepton_met")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables_t2ttOffShell.find("jet1_pT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables_t2ttOffShell.find("jet2_pT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables_t2ttOffShell.find("jet3_pT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables_t2ttOffShell.find("jet4_pT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables_t2ttOffShell.find("jet1_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables_t2ttOffShell.find("jet2_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables_t2ttOffShell.find("jet3_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables_t2ttOffShell.find("jet4_phi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables_t2ttOffShell.find("missmass")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("missmass",&missmass);
  if(NNvariables_t2ttOffShell.find("mlpjpa")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables_t2ttOffShell.find("dphiljpa")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables_t2ttOffShell.find("dphimetl")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dphimetl",&dphimetl);
  if(NNvariables_t2ttOffShell.find("dphiljb")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dphiljb",&dphiljb);
  if(NNvariables_t2ttOffShell.find("m3topW")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("m3topW",&m3topW);
  if(NNvariables_t2ttOffShell.find("b1_pt")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1_pt",&b1_pt);
  if(NNvariables_t2ttOffShell.find("b1_pt_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables_t2ttOffShell.find("b2_pt")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b2_pt",&b2_pt);
  if(NNvariables_t2ttOffShell.find("b2_pt_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables_t2ttOffShell.find("b1plusb2_pt")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables_t2ttOffShell.find("b1plusb2_pt_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables_t2ttOffShell.find("b1_eta")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1_eta",&b1_eta);
  if(NNvariables_t2ttOffShell.find("b1_eta_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables_t2ttOffShell.find("dR_b1b2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables_t2ttOffShell.find("dR_b1b2_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables_t2ttOffShell.find("dPhi_b1b2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables_t2ttOffShell.find("dPhi_b1b2_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables_t2ttOffShell.find("mlb1_2")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables_t2ttOffShell.find("HT_av")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("HT_av",&HT_av);
  if(NNvariables_t2ttOffShell.find("HT_MET_lep_pt")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables_t2ttOffShell.find("HT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("HT",&HT);
  if(NNvariables_t2ttOffShell.find("mlb_hemi")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables_t2ttOffShell.find("HTfrac")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("HTfrac",&HTfrac);
  if(NNvariables_t2ttOffShell.find("HTfrac_FNAL")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables_t2ttOffShell.find("mT2W")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("mT2W",&mT2W);
  if(NNvariables_t2ttOffShell.find("dR_LepB")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables_t2ttOffShell.find("dR_LepJet")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables_t2ttOffShell.find("dPhi_JetMet")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables_t2ttOffShell.find("METoverSqrtHT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables_t2ttOffShell.find("Chi2SNT")!=NNvariables_t2ttOffShell.end())
    reader_t2ttOffShell->AddVariable("Chi2SNT",&Chi2SNT);

  if(NNvariables_t2ttOnShell.find("met")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("met",&met);
  if(NNvariables_t2ttOnShell.find("met_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("met_phi",&met_phi);
  if(NNvariables_t2ttOnShell.find("met_signif")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("met_signif",&met_signif);
  if(NNvariables_t2ttOnShell.find("mT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mT",&mT);
  if(NNvariables_t2ttOnShell.find("lepton_pT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables_t2ttOnShell.find("lepton_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables_t2ttOnShell.find("njets")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("njets",&njets);
  if(NNvariables_t2ttOnShell.find("nbjets")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("nbjets",&nbjets);
  if(NNvariables_t2ttOnShell.find("m3")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("m3",&m3);
  if(NNvariables_t2ttOnShell.find("m3_pt")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("m3_pt",&m3_pt);
  if(NNvariables_t2ttOnShell.find("m3b")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("m3b",&m3b);
  if(NNvariables_t2ttOnShell.find("mi34")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mi34",&mi34);
  if(NNvariables_t2ttOnShell.find("mi34b")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mi34b",&mi34b);
  if(NNvariables_t2ttOnShell.find("mi34b_m2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables_t2ttOnShell.find("mjetlepmax")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables_t2ttOnShell.find("phi_lepton_met")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables_t2ttOnShell.find("jet1_pT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables_t2ttOnShell.find("jet2_pT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables_t2ttOnShell.find("jet3_pT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables_t2ttOnShell.find("jet4_pT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables_t2ttOnShell.find("jet1_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables_t2ttOnShell.find("jet2_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables_t2ttOnShell.find("jet3_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables_t2ttOnShell.find("jet4_phi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables_t2ttOnShell.find("missmass")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("missmass",&missmass);
  if(NNvariables_t2ttOnShell.find("mlpjpa")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables_t2ttOnShell.find("dphiljpa")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables_t2ttOnShell.find("dphimetl")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dphimetl",&dphimetl);
  if(NNvariables_t2ttOnShell.find("dphiljb")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dphiljb",&dphiljb);
  if(NNvariables_t2ttOnShell.find("m3topW")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("m3topW",&m3topW);
  if(NNvariables_t2ttOnShell.find("b1_pt")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1_pt",&b1_pt);
  if(NNvariables_t2ttOnShell.find("b1_pt_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables_t2ttOnShell.find("b2_pt")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b2_pt",&b2_pt);
  if(NNvariables_t2ttOnShell.find("b2_pt_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables_t2ttOnShell.find("b1plusb2_pt")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables_t2ttOnShell.find("b1plusb2_pt_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables_t2ttOnShell.find("b1_eta")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1_eta",&b1_eta);
  if(NNvariables_t2ttOnShell.find("b1_eta_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables_t2ttOnShell.find("dR_b1b2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables_t2ttOnShell.find("dR_b1b2_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables_t2ttOnShell.find("dPhi_b1b2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables_t2ttOnShell.find("dPhi_b1b2_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables_t2ttOnShell.find("mlb1_2")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables_t2ttOnShell.find("HT_av")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("HT_av",&HT_av);
  if(NNvariables_t2ttOnShell.find("HT_MET_lep_pt")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables_t2ttOnShell.find("HT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("HT",&HT);
  if(NNvariables_t2ttOnShell.find("mlb_hemi")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables_t2ttOnShell.find("HTfrac")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("HTfrac",&HTfrac);
  if(NNvariables_t2ttOnShell.find("HTfrac_FNAL")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables_t2ttOnShell.find("mT2W")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("mT2W",&mT2W);
  if(NNvariables_t2ttOnShell.find("dR_LepB")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables_t2ttOnShell.find("dR_LepJet")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables_t2ttOnShell.find("dPhi_JetMet")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables_t2ttOnShell.find("METoverSqrtHT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables_t2ttOnShell.find("Chi2SNT")!=NNvariables_t2ttOnShell.end())
    reader_t2ttOnShell->AddVariable("Chi2SNT",&Chi2SNT);




   TString BDT_dir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_11/src/readerSTOPS/weights_BDT_May5";
   TString BDT_dir_t2tt = "/afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_11/src/readerSTOPS/weights_BDT_May5_t2tt";


   reader->BookMVA("BDT_output_t2bw025_R1",  BDT_dir + "/BDT_t2bw025_Reg1.weights.xml");
   reader->BookMVA("BDT_output_t2bw025_R3",  BDT_dir + "/BDT_t2bw025_Reg3.weights.xml");
   reader->BookMVA("BDT_output_t2bw025_R4",  BDT_dir + "/BDT_t2bw025_Reg4.weights.xml");
   reader->BookMVA("BDT_output_t2bw025_R6",  BDT_dir + "/BDT_t2bw025_Reg6.weights.xml");

   reader_t2bw050->BookMVA("BDT_output_t2bw050_R1",  BDT_dir + "/BDT_t2bw050_Reg1.weights.xml");
   reader_t2bw050->BookMVA("BDT_output_t2bw050_R3",  BDT_dir + "/BDT_t2bw050_Reg3.weights.xml");
   reader_t2bw050->BookMVA("BDT_output_t2bw050_R4",  BDT_dir + "/BDT_t2bw050_Reg4.weights.xml");
   reader_t2bw050->BookMVA("BDT_output_t2bw050_R5",  BDT_dir + "/BDT_t2bw050_Reg5.weights.xml");
   reader_t2bw050->BookMVA("BDT_output_t2bw050_R6",  BDT_dir + "/BDT_t2bw050_Reg6.weights.xml");

   reader_t2bw075->BookMVA("BDT_output_t2bw075_R1",  BDT_dir + "/BDT_t2bw075_Reg1.weights.xml");
   reader_t2bw075->BookMVA("BDT_output_t2bw075_R2",  BDT_dir + "/BDT_t2bw075_Reg2.weights.xml");
   reader_t2bw075->BookMVA("BDT_output_t2bw075_R3",  BDT_dir + "/BDT_t2bw075_Reg3.weights.xml");
   reader_t2bw075->BookMVA("BDT_output_t2bw075_R5",  BDT_dir + "/BDT_t2bw075_Reg5.weights.xml");

   reader_t2ttOffShell->BookMVA("BDT_output_t2tt_R1",  BDT_dir_t2tt + "/BDT_t2tt_Reg1.weights.xml");
   reader_t2ttOnShell->BookMVA("BDT_output_t2tt_R2",  BDT_dir_t2tt + "/BDT_t2tt_Reg2.weights.xml");
   reader_t2ttOnShell->BookMVA("BDT_output_t2tt_R5",  BDT_dir_t2tt + "/BDT_t2tt_Reg5.weights.xml");

   vector<Float_t> BDToutputs_t2bw025, BDToutputs_t2bw050, BDToutputs_t2bw075, BDToutputs_t2tt;
   Int_t isUsedInBDT;


   theOutputTree->Branch("isUsedInBDT",     	    	    &(isUsedInBDT));
   theOutputTree->Branch("BDT_output_t2bw025_R1",     	    &(BDT_output_t2bw025_R1));
   theOutputTree->Branch("BDT_output_t2bw025_R3",     	    &(BDT_output_t2bw025_R3));
   theOutputTree->Branch("BDT_output_t2bw025_R4",     	    &(BDT_output_t2bw025_R4));
   theOutputTree->Branch("BDT_output_t2bw025_R6",     	    &(BDT_output_t2bw025_R6));
   theOutputTree->Branch("BDT_output_t2bw050_R1",     	    &(BDT_output_t2bw050_R1));
   theOutputTree->Branch("BDT_output_t2bw050_R3",     	    &(BDT_output_t2bw050_R3));
   theOutputTree->Branch("BDT_output_t2bw050_R4",     	    &(BDT_output_t2bw050_R4));
   theOutputTree->Branch("BDT_output_t2bw050_R5",     	    &(BDT_output_t2bw050_R5));
   theOutputTree->Branch("BDT_output_t2bw050_R6",     	    &(BDT_output_t2bw050_R6));
   theOutputTree->Branch("BDT_output_t2bw075_R1",     	    &(BDT_output_t2bw075_R1));
   theOutputTree->Branch("BDT_output_t2bw075_R2",     	    &(BDT_output_t2bw075_R2));
   theOutputTree->Branch("BDT_output_t2bw075_R3",     	    &(BDT_output_t2bw075_R3));
   theOutputTree->Branch("BDT_output_t2bw075_R5",     	    &(BDT_output_t2bw075_R5));
   theOutputTree->Branch("BDT_output_t2tt_R1",     	    &(BDT_output_t2tt_R1));
   theOutputTree->Branch("BDT_output_t2tt_R2",     	    &(BDT_output_t2tt_R2));
   theOutputTree->Branch("BDT_output_t2tt_R5",     	    &(BDT_output_t2tt_R5));


  // ########################################
  // ##        Run over the events         ##
  // ########################################


  for (int i = 0 ; i < theInputTree->GetEntries() ; i++)
  {
      
      if (i % (theInputTree->GetEntries() / 50) == 0) 
              printProgressBar(i,theInputTree->GetEntries());

      // Read entry from input tree 
      
      ReadEvent(theInputTree,i,&pointers,&myEvent);



        bool isSignal = false;
        bool isTTbar  = false;

        if (myEvent.mStop == -1) { isSignal = false;}
                else isSignal = true;

        if (string(argv[1]).find("ttbar") != std::string::npos) isTTbar = true;



        if ( isSignal && ((myEvent.event%2)==1)) isUsedInBDT = 1;
//        else if ( isTTbar && ((myEvent.event%2)==1))  isUsedInBDT = 1;
 
		else isUsedInBDT = 0;

      
        met = myEvent.MET;
        mT = myEvent.MT;
        mT2W = myEvent.MT2W;
        HT = myEvent.HT;
        HTfrac = myEvent.HTRatio;
        b1_pt = myEvent.leadingBPt;
        lepton_pT = myEvent.leadingLeptonPt;
        dPhi_JetMet = myEvent.deltaPhiMETJets;
        dR_LepB = myEvent.deltaRLeptonLeadingB;
        m3b = myEvent.M3b;
        mlb_hemi = myEvent.Mlb_hemi;
        jet1_pT = myEvent.leadingJetPt;
        njets = myEvent.nJets;
        METoverSqrtHT = myEvent.METoverSqrtHT;
        //dR_LepJet 
        HT_MET_lep_pt = myEvent.HTPlusLeptonPtPlusMET;
        Chi2SNT = myEvent.hadronicChi2;

        stop_mass = myEvent.mStop;
        lsp_mass = myEvent.mNeutralino;


        BDT_output_t2bw025_R1 = reader->EvaluateMVA( "BDT_output_t2bw025_R1" );
        BDT_output_t2bw025_R3 = reader->EvaluateMVA( "BDT_output_t2bw025_R3" );
        BDT_output_t2bw025_R4 = reader->EvaluateMVA( "BDT_output_t2bw025_R4" );
        BDT_output_t2bw025_R6 = reader->EvaluateMVA( "BDT_output_t2bw025_R6" );


        BDT_output_t2bw050_R1 = reader_t2bw050->EvaluateMVA( "BDT_output_t2bw050_R1" );
        BDT_output_t2bw050_R3 = reader_t2bw050->EvaluateMVA( "BDT_output_t2bw050_R3" );
        BDT_output_t2bw050_R4 = reader_t2bw050->EvaluateMVA( "BDT_output_t2bw050_R4" );
        BDT_output_t2bw050_R5 = reader_t2bw050->EvaluateMVA( "BDT_output_t2bw050_R5" );
        BDT_output_t2bw050_R6 = reader_t2bw050->EvaluateMVA( "BDT_output_t2bw050_R6" );


        BDT_output_t2bw075_R1 = reader_t2bw075->EvaluateMVA( "BDT_output_t2bw075_R1" );
        BDT_output_t2bw075_R2 = reader_t2bw075->EvaluateMVA( "BDT_output_t2bw075_R2" );
        BDT_output_t2bw075_R3 = reader_t2bw075->EvaluateMVA( "BDT_output_t2bw075_R3" );
        BDT_output_t2bw075_R5 = reader_t2bw075->EvaluateMVA( "BDT_output_t2bw075_R5" );

        BDT_output_t2tt_R1  = reader_t2ttOffShell->EvaluateMVA( "BDT_output_t2tt_R1" );
        BDT_output_t2tt_R2  = reader_t2ttOnShell->EvaluateMVA( "BDT_output_t2tt_R2" );
        BDT_output_t2tt_R5  = reader_t2ttOnShell->EvaluateMVA( "BDT_output_t2tt_R5" );

        theOutputTree->Fill();


  }           


  printProgressBar(theInputTree->GetEntries(),theInputTree->GetEntries());
  cout << endl;

  theOutputTree->Write(0, TObject::kOverwrite); 

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


