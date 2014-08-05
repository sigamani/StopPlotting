#ifndef _SignalRegionDefinitions_h
#define _SignalRegionDefinitions_h


string signalregionName(TString decaymode, int stopmass, int lspmass)
{

    string SR = "nan";
    if (decaymode == "T2bw075") 
    {
        if (lspmass > stopmass - 200)
            SR = "T2bw075_1";
        if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            SR = "T2bw075_2";
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            SR = "T2bw075_3";
        if (lspmass <= stopmass - 475)
            SR = "T2bw075_5_lowDM";
        if (lspmass <= stopmass - 575)
            SR = "T2bw075_5_highDM";
    }

    if (decaymode == "T2bw050") 
    {
        if (lspmass > stopmass - 250) 
        {
            SR = "T2bw050_1_highDM" ; 
            if (lspmass < 150) SR = "T2bw050_1_lowDM";
        }

        if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            SR = "T2bw050_3";
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            SR = "T2bw050_4";
        if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
            SR = "T2bw050_5";
        if (lspmass <= stopmass - 625)
            SR = "T2bw050_6";
    }    

    if (decaymode == "T2bw025") 
    {

        if (lspmass > stopmass - 225)
            SR = "T2bw025_1";
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            SR = "T2bw025_3_lowDM";
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 425)
            SR = "T2bw025_3_highDM";
        if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
            SR = "T2bw025_4";
        if (lspmass <= stopmass - 600)
            SR = "T2bw025_6";
    }

    if (decaymode == "T2tt") 
    {

        if (lspmass > stopmass - 225)
            SR = "T2tt_1";
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            SR = "T2tt_2_lowDM";
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 325)
            SR = "T2tt_2_highDM";
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            SR = "T2tt_5_lowDM";
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 500)
            SR = "T2tt_5_mediumDM";
        if (lspmass <= stopmass - 500)
            SR = "T2tt_5_highDM";

    }

    return SR;
}






double signalcut(TString decaymode, int stopmass, int lspmass)
{
    double cutvalue = 0.;

    if (decaymode == "T2bw075") 
    {
        if (lspmass > stopmass - 200)
            cutvalue = 0.225;
        if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            cutvalue = 0.275;
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            cutvalue = 0.350;
        if (lspmass <= stopmass - 475)
            cutvalue = 0.25;
        if (lspmass <= stopmass - 575)
            cutvalue = 0.3;
    }

    if (decaymode == "T2bw050") 
    {
        if (lspmass > stopmass - 250) 
        {
            cutvalue = 0.25 ; 
            if (lspmass < 150) cutvalue = 0.175;
        }

        if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            cutvalue = 0.3;
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            cutvalue = 0.250;
        if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
            cutvalue = 0.225;
        if (lspmass <= stopmass - 625)
            cutvalue = 0.2;
    }    

    if (decaymode == "T2bw025") 
    {

          if (lspmass > stopmass - 225)
            cutvalue = 0.15;
          if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            cutvalue = 0.15;
          if (lspmass <= stopmass - 275 && lspmass > stopmass - 425)
            cutvalue = 0.3;
          if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
            cutvalue = 0.15;
          if (lspmass <= stopmass - 600)
            cutvalue = 0.175;

   }
    if (decaymode == "T2tt") 
    { 

        if (lspmass > stopmass - 225)
            cutvalue = 0.275;
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            cutvalue = 0.350;
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 325)
            cutvalue = 0.4;
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            cutvalue = 0.35;
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 500)
            cutvalue = 0.325;
        if (lspmass <= stopmass - 500)
            cutvalue = 0.375;

    }


    return cutvalue;
}

int returnIntBDTOffsetValue(TString decaymode, int stopmass, int lspmass)
{
    int intoffset = -999;

    if (decaymode == "T2bw075") 
    {
        if (lspmass > stopmass - 200)
            intoffset = 4;
        if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            intoffset = 4;
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            intoffset = 4;
        if (lspmass <= stopmass - 475)
            intoffset = 4;
        if (lspmass <= stopmass - 575)
            intoffset = 4;
    }


    if (decaymode == "T2bw050"){ 
  

        if (lspmass > stopmass - 250)
        {   
            intoffset = 5 ;
            if (lspmass <= 50) intoffset = 2;
          //  if (lspmass > 50) && intoffset = 5;
        }

        if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            intoffset = 4;
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            intoffset = 4;
        if (lspmass <= stopmass - 450 && lspmass > stopmass - 550)
            intoffset = 4;
        if (lspmass <= stopmass - 550 )
            intoffset = 5;
    }    


  if (decaymode == "T2bw025") {

          if (lspmass > stopmass - 225)
            intoffset = 4;
          if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            intoffset = 4;

          if ((lspmass <= stopmass - 275 && lspmass > stopmass - 425) && (lspmass <= 50))
            intoffset = 1;
          if ((lspmass <= stopmass - 275 && lspmass > stopmass - 425) && (lspmass > 50))
            intoffset = 4;

          if (lspmass <= stopmass - 425 && lspmass > stopmass - 550)
            intoffset = 4;
          if (lspmass <= stopmass - 550)
            intoffset = 3;

  }



    if (decaymode == "T2tt")
    {

        if ((lspmass > stopmass - 225 ) && (lspmass <= 100)) intoffset = 4;
        if ((lspmass > stopmass - 225 ) && (lspmass > 100)) intoffset = 7; // peak of the off shell top part

        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            intoffset = 4;
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 325)
            intoffset = 4;
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            intoffset = 4;
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 500)
            intoffset = 4;
        if (lspmass <= stopmass - 500)
            intoffset = 4;

    }


    return intoffset;
}

// #################################
// #  BDT signal region container  #
// #################################

typedef struct 
{
    string  labelRoot;
    string  labelLatex;

    double* BDTOutputPointer;
    float   BDTOutputCut;

} BDTSignalRegion;

#include <map>
map<string, BDTSignalRegion> BDTSignalRegionMap;

void loadBDTSignalRegion(string tag, string labelRoot, string labelLatex, double* BDTOutputPointer, float BDTOutputCut)
{
    BDTSignalRegionMap[tag].labelRoot        = labelRoot;
    BDTSignalRegionMap[tag].labelLatex       = labelLatex;
    BDTSignalRegionMap[tag].BDTOutputPointer = BDTOutputPointer;
    BDTSignalRegionMap[tag].BDTOutputCut     = BDTOutputCut;
}

void loadBDTSignalRegions()
{
    loadBDTSignalRegion("T2tt_1_lowLSP",     "T2tt-1, low m(LSP)",       "T2tt-1, low $m$(LSP)",        &myEvent.BDT_output_t2tt_R1,    0.275);
    loadBDTSignalRegion("T2tt_1_highLSP",    "T2tt-1, high m(LSP)",      "T2tt-1, high $m$(LSP)",       &myEvent.BDT_output_t2tt_R1,    0.425);
    loadBDTSignalRegion("T2tt_2_lowDM",      "T2tt-2, low m(LSP)",       "T2tt-2, low $m$(LSP)",        &myEvent.BDT_output_t2tt_R2,    0.35 );
    loadBDTSignalRegion("T2tt_2_highDM",     "T2tt-2, high m(LSP)",      "T2tt-2, high $m$(LSP)",       &myEvent.BDT_output_t2tt_R2,    0.4  );
    loadBDTSignalRegion("T2tt_5_lowDM",      "T2tt-5, low #Delta m",     "T2tt-5, low $\\Delta m$",     &myEvent.BDT_output_t2tt_R5,    0.35 );
    loadBDTSignalRegion("T2tt_5_mediumDM",   "T2tt-5, medium #Delta m",  "T2tt-5, medium $\\Delta m$",  &myEvent.BDT_output_t2tt_R5,    0.325);
    loadBDTSignalRegion("T2tt_5_highDM",     "T2tt-5, high #Delta m",    "T2tt-5, high $\\Delta m$",    &myEvent.BDT_output_t2tt_R5,    0.375);
    
    loadBDTSignalRegion("T2bw075_1",         "T2bw075-1",                "T2bw075-1",                   &myEvent.BDT_output_t2bw075_R1, 0.225);
    loadBDTSignalRegion("T2bw075_2",         "T2bw075-2",                "T2bw075-2",                   &myEvent.BDT_output_t2bw075_R2, 0.275);
    loadBDTSignalRegion("T2bw075_3",         "T2bw075-3",                "T2bw075-3",                   &myEvent.BDT_output_t2bw075_R3, 0.350);
    loadBDTSignalRegion("T2bw075_5_lowDM",   "T2bw075-5, low #Delta m",  "T2bw075-5, low $\\Delta m$",  &myEvent.BDT_output_t2bw075_R5, 0.25 );
    loadBDTSignalRegion("T2bw075_5_highDM",  "T2bw075-5, high #Delta m", "T2bw075-5, high $\\Delta m$", &myEvent.BDT_output_t2bw075_R5, 0.3  );
    
    loadBDTSignalRegion("T2bw050_1_lowLSP",  "T2bw050-1, low m(LSP)",    "T2bw050-1, low $m$(LSP)",     &myEvent.BDT_output_t2bw050_R1, 0.075);
    loadBDTSignalRegion("T2bw050_1_highLSP", "T2bw050-1, high m(LSP)",   "T2bw050-1, high $m$(LSP)",    &myEvent.BDT_output_t2bw050_R1, 0.225);
    loadBDTSignalRegion("T2bw050_3",         "T2bw050-3",                "T2bw050-3",                   &myEvent.BDT_output_t2bw050_R3, 0.3  );
    loadBDTSignalRegion("T2bw050_4",         "T2bw050-4",                "T2bw050-4",                   &myEvent.BDT_output_t2bw050_R4, 0.250);
    loadBDTSignalRegion("T2bw050_5",         "T2bw050-5",                "T2bw050-5",                   &myEvent.BDT_output_t2bw050_R5, 0.225);
    loadBDTSignalRegion("T2bw050_6",         "T2bw050-6",                "T2bw050-6",                   &myEvent.BDT_output_t2bw050_R6, 0.2  );
    
    loadBDTSignalRegion("T2bw025_1",         "T2bw025-1",                "T2bw025-1",                   &myEvent.BDT_output_t2bw025_R1, 0.15 );
    loadBDTSignalRegion("T2bw025_3_lowDM",   "T2bw025-3, low #Delta m",  "T2bw025-3, low $\\Delta m$",  &myEvent.BDT_output_t2bw025_R3, 0.15 );
    loadBDTSignalRegion("T2bw025_3_highDM",  "T2bw025-3, high #Delta m", "T2bw025-3, high $\\Delta m$", &myEvent.BDT_output_t2bw025_R3, 0.3  );
    loadBDTSignalRegion("T2bw025_4",         "T2bw025-4",                "T2bw025-4",                   &myEvent.BDT_output_t2bw025_R4, 0.15 );
    loadBDTSignalRegion("T2bw025_6",         "T2bw025-6",                "T2bw025-6",                   &myEvent.BDT_output_t2bw025_R6, 0.125);
}

// #############################################
// #  Accessors to the BDT signal regions map  #  
// #############################################

bool doesBDTSignalRegionExists(string BDTSignalRegionTag)
{
    // Check if entry exist in map
    if (BDTSignalRegionMap.find(BDTSignalRegionTag) == BDTSignalRegionMap.end())
    {
        cerr << "WARNING (" << __FILE__ << ", l." << __LINE__ << ")"
             << "Trying to access unknown BDT signal region tag '" << BDTSignalRegionTag << "'" << endl;
        return false;
    }
    else return true;
}

float BDToutput(string BDTSignalRegionTag)
{
    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return -10.0;
    else return *(BDTSignalRegionMap[BDTSignalRegionTag].BDTOutputPointer);
}

float BDTcut(string BDTSignalRegionTag) 
{
    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return -1.0;
    else return BDTSignalRegionMap[BDTSignalRegionTag].BDTOutputCut;
}

string BDTlabel(string BDTSignalRegionTag, string mode) 
{
    // If tag starts with "BDT_", remove the 4 first characters
    // (so that "BDT_T2tt_1" and "T2tt_1" returns the same thing)
    if (BDTSignalRegionTag.find("BDT_") == 0)
        BDTSignalRegionTag = BDTSignalRegionTag.substr(4,BDTSignalRegionTag.size());

    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return "";

         if (mode == "root")  return BDTSignalRegionMap[BDTSignalRegionTag].labelRoot;
    else if (mode == "latex") return BDTSignalRegionMap[BDTSignalRegionTag].labelLatex;
    else                      return "";
}


bool goesInBDTRegion(string BDTregion) { return (BDToutput(BDTregion) > BDTcut(BDTregion)); }

// FIXME : these hardcoded functions shouldn't be needed because it introduces tight coupling w.r.t. the signal region definitions.

bool BDT_T2tt_1_lowLSP           (bool applyMTCut) { return goesInBDTRegion("T2tt_1_lowLSP"    ); }
bool BDT_T2tt_1_highLSP          (bool applyMTCut) { return goesInBDTRegion("T2tt_1_highLSP"   ); }
bool BDT_T2tt_2_lowDM            (bool applyMTCut) { return goesInBDTRegion("T2tt_2_lowDM"     ); }
bool BDT_T2tt_2_highDM           (bool applyMTCut) { return goesInBDTRegion("T2tt_2_highDM"    ); }
bool BDT_T2tt_5_lowDM            (bool applyMTCut) { return goesInBDTRegion("T2tt_5_lowDM"     ); }
bool BDT_T2tt_5_mediumDM         (bool applyMTCut) { return goesInBDTRegion("T2tt_5_mediumDM"  ); }
bool BDT_T2tt_5_highDM           (bool applyMTCut) { return goesInBDTRegion("T2tt_5_highDM"    ); }
bool BDT_T2bw075_1               (bool applyMTCut) { return goesInBDTRegion("T2bw075_1"        ); }
bool BDT_T2bw075_2               (bool applyMTCut) { return goesInBDTRegion("T2bw075_2"        ); }
bool BDT_T2bw075_3               (bool applyMTCut) { return goesInBDTRegion("T2bw075_3"        ); }
bool BDT_T2bw075_5_lowDM         (bool applyMTCut) { return goesInBDTRegion("T2bw075_5_lowDM"  ); }
bool BDT_T2bw075_5_highDM        (bool applyMTCut) { return goesInBDTRegion("T2bw075_5_highDM" ); }
bool BDT_T2bw050_1_lowLSP        (bool applyMTCut) { return goesInBDTRegion("T2bw050_1_lowLSP" ); }
bool BDT_T2bw050_1_highLSP       (bool applyMTCut) { return goesInBDTRegion("T2bw050_1_highLSP"); }
bool BDT_T2bw050_3               (bool applyMTCut) { return goesInBDTRegion("T2bw050_3"        ); }
bool BDT_T2bw050_4               (bool applyMTCut) { return goesInBDTRegion("T2bw050_4"        ); }
bool BDT_T2bw050_5               (bool applyMTCut) { return goesInBDTRegion("T2bw050_5"        ); }
bool BDT_T2bw050_6               (bool applyMTCut) { return goesInBDTRegion("T2bw050_6"        ); }
bool BDT_T2bw025_1               (bool applyMTCut) { return goesInBDTRegion("T2bw025_1"        ); }
bool BDT_T2bw025_3_lowDM         (bool applyMTCut) { return goesInBDTRegion("T2bw025_3_lowDM"  ); }
bool BDT_T2bw025_3_highDM        (bool applyMTCut) { return goesInBDTRegion("T2bw025_3_highDM" ); }
bool BDT_T2bw025_4               (bool applyMTCut) { return goesInBDTRegion("T2bw025_4"        ); }
bool BDT_T2bw025_6               (bool applyMTCut) { return goesInBDTRegion("T2bw025_6"        ); }

// Aliases to loosest BDT signal regions in case of different cuts that apply to same BDT output
bool BDT_T2tt_1                  (bool applyMTCut) { return BDT_T2tt_1_lowLSP   (applyMTCut); }
bool BDT_T2tt_2                  (bool applyMTCut) { return BDT_T2tt_2_lowDM    (applyMTCut); }
bool BDT_T2tt_5                  (bool applyMTCut) { return BDT_T2tt_5_mediumDM (applyMTCut); }
bool BDT_T2bw075_5               (bool applyMTCut) { return BDT_T2bw075_5_lowDM (applyMTCut); }
bool BDT_T2bw050_1               (bool applyMTCut) { return BDT_T2bw050_1_lowLSP(applyMTCut); }
bool BDT_T2bw025_3               (bool applyMTCut) { return BDT_T2bw025_3_lowDM (applyMTCut); }

#endif
