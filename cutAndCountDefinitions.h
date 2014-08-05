#ifndef _cutAndCountDefinitions_h
#define _cutAndCountDefinitions_h

// LM 150 to cross check with number from Alex. G

bool crossCheck_LM150(bool applyMTCut)
{
    // Apply MET and MT cuts
    if (myEvent.MET < 150) return false;
    if ((applyMTCut) && (myEvent.MT < 120)) return false;

    // Chi2 and deltaPhi cuts
    if (myEvent.deltaPhiMETJets < 0.8) return false;
    if (myEvent.hadronicChi2 > 5) return false;

    return true;
}

// Preselection signal region (ie : basically no cut compared to other "standard" SR's)
bool preselection(bool applyMTCut)
{
    if ((applyMTCut) && (myEvent.MT < 100)) return false;

    return true;
}


// ISR jet definition

float leadingNonBPt()
{
    float leadingPt = -1;
    for (unsigned int j = 0 ; j < myEvent.jets.size()  ; j++)
    {
        // Ignore b-tagged jets
        float CSV;
        if (sampleType == "data") CSV = (myEvent.jets_CSV_raw)[j];
        else                      CSV = (myEvent.jets_CSV_reshaped)[j];

        if (CSV > 0.679) continue;

        // Keep Pt max
        if (leadingPt < (myEvent.jets)[j].Pt())
            leadingPt = (myEvent.jets)[j].Pt();
    }
    return leadingPt;
}

bool findISRJet()
{
    if (myEvent.nJets < 5) return false;
    if (leadingNonBPt() < 200) return false;
    return true;
}


// ###########################
// #  _____ ____  _   _      #
// #  |_   _|___ \| |_| |_   #
// #    | |   __) | __| __|  #
// #    | |  / __/| |_| |_   #
// #    |_| |_____|\__|\__|  #
// #                         #
// ###########################

bool cutAndCount_T2tt(float cutMET, float cutMEToverSqrtHT, float cutMT, float cutMT2W, float cutDeltaPhi, float cutHadronicChi2, bool enableISRJetRequirement, float enableHighPtNonBJetRequirement = -1)
{
    if (myEvent.METoverSqrtHT   < cutMEToverSqrtHT) return false;
    if (myEvent.MT              < cutMT)            return false;
    if (myEvent.MT2W            < cutMT2W)          return false;
    if ((cutMT2W > 0) && (myEvent.MT2W > 99990))    return false;
    if (myEvent.MET             < cutMET)           return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)      return false;
    if (myEvent.hadronicChi2    > cutHadronicChi2)  return false;
 
    if (enableISRJetRequirement)
    {
        #ifdef ISR_JET_ALREADY_COMPUTED
            if (!myEvent.ISRJet)   return false;
        #else
            if (!findISRJet())     return false;
        #endif
    }
    if (enableHighPtNonBJetRequirement != -1)
    {
        #ifdef LEADING_NON_B_PT_ALREADY_COMPUTED
            if (myEvent.leadingNonBPt < enableHighPtNonBJetRequirement)   return false;
        #else
            if (leadingNonBPt()       < enableHighPtNonBJetRequirement)   return false;
        #endif
    }

    return true;
}

                                                                            // MET METsig   MT             MT2W dPhi Chi2    ISRjet
bool cutAndCount_T2tt_offShellLoose(bool applyMTCut) { return cutAndCount_T2tt( -1,  8,  125 * applyMTCut, -1,   -1, 999999, true ); }
bool cutAndCount_T2tt_offShellTight(bool applyMTCut) { return cutAndCount_T2tt( 300, -1, 130 * applyMTCut, -1,   -1, 999999, true ); }
bool cutAndCount_T2tt_lowDeltaM    (bool applyMTCut) { return cutAndCount_T2tt( -1,  8,  140 * applyMTCut, -1,  0.8, 5,      false); }
bool cutAndCount_T2tt_mediumDeltaM (bool applyMTCut) { return cutAndCount_T2tt( 200, -1, 140 * applyMTCut, 180, 0.8, 3,      false); }
bool cutAndCount_T2tt_highDeltaM   (bool applyMTCut) { return cutAndCount_T2tt( 350, -1, 130 * applyMTCut, 190,  -1, 999999, false); }

// #################################
// #  _____ ____  _                #
// #  |_   _|___ \| |____      __  #
// #    | |   __) | '_ \ \ /\ / /  #
// #    | |  / __/| |_) \ V  V /   #
// #    |_| |_____|_.__/ \_/\_/    #
// #                               #
// #################################

bool cutAndCount_T2bw(float cutMET, float cutMETsig, float cutMT, float cutMT2W, float cutBPt, float cutDeltaPhi, bool enableISRJetRequirement, float enableHighPtNonBJetRequirement = -1)
{
    if (myEvent.MET             < cutMET)               return false;
    if (myEvent.METoverSqrtHT   < cutMETsig)            return false;
    if (myEvent.MT              < cutMT)                return false;
    if (myEvent.MT2W            < cutMT2W)              return false;
    if ((cutMT2W > 0)  && (myEvent.MT2W>99990))         return false;
    if (myEvent.leadingBPt      < cutBPt)               return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)          return false;
    if (enableISRJetRequirement)
    {
        #ifdef ISR_JET_ALREADY_COMPUTED
            if (!myEvent.ISRJet)   return false;
        #else
            if (!findISRJet())     return false;
        #endif
    }
    if (enableHighPtNonBJetRequirement != -1)
    {
        #ifdef LEADING_NON_B_PT_ALREADY_COMPUTED
            if (myEvent.leadingNonBPt < enableHighPtNonBJetRequirement)   return false;
        #else
            if (leadingNonBPt()       < enableHighPtNonBJetRequirement)   return false;
        #endif
    }

    return true;
}

                                                                              // MET METsig   MT                MT2W BPt dPhi ISRjet
bool cutAndCount_T2bw025_offShell    (bool applyMTCut) { return cutAndCount_T2bw(-1,   9,    120 * applyMTCut, -1,   -1, 0.2, true ); }
bool cutAndCount_T2bw025_lowMasses   (bool applyMTCut) { return cutAndCount_T2bw(-1,   6,    120 * applyMTCut, 200, 180, 0.8, false); }
bool cutAndCount_T2bw025_highMasses  (bool applyMTCut) { return cutAndCount_T2bw(300, -1,    120 * applyMTCut, 200, 180, 0.8, false); }

bool cutAndCount_T2bw050_offShell    (bool applyMTCut) { return cutAndCount_T2bw(-1,   9,    120 * applyMTCut, -1,   -1, 0.2, true ); }
bool cutAndCount_T2bw050_lowMasses   (bool applyMTCut) { return cutAndCount_T2bw(-1,   6,    135 * applyMTCut, 180,  -1, 0.8, false); }
bool cutAndCount_T2bw050_mediumDeltaM(bool applyMTCut) { return cutAndCount_T2bw(-1,   7,    140 * applyMTCut, 190, 100, 0.8, false); }
bool cutAndCount_T2bw050_highDeltaM  (bool applyMTCut) { return cutAndCount_T2bw(300, -1,    120 * applyMTCut, 200, 100, 0.8, false); }

bool cutAndCount_T2bw075_lowDeltaM   (bool applyMTCut) { return cutAndCount_T2bw(-1,  12,    120 * applyMTCut, -1,   -1, 0.8, true);  }
bool cutAndCount_T2bw075_mediumDeltaM(bool applyMTCut) { return cutAndCount_T2bw(-1,  10,    130 * applyMTCut, 180,  -1, 0.8, false); }
bool cutAndCount_T2bw075_highDeltaM  (bool applyMTCut) { return cutAndCount_T2bw(300, -1,    140 * applyMTCut, 200,  -1, 0.8, false); }

// #################################
// #  CnC signal region container  #
// #################################

typedef struct 
{
    string  labelRoot;
    string  labelLatex;

    bool (*selector)(bool);

} CnCSignalRegion;

#include <map>
map<string, CnCSignalRegion> CnCSignalRegionMap;

void loadCnCSignalRegion(string tag, string labelRoot, string labelLatex, bool (*selector)(bool))
{
    CnCSignalRegionMap[tag].labelRoot  = labelRoot;
    CnCSignalRegionMap[tag].labelLatex = labelLatex;
    CnCSignalRegionMap[tag].selector   = selector;
}

bool doesCnCSignalRegionExists(string CnCSignalRegionTag)
{
    // Check if entry exist in map
    if (CnCSignalRegionMap.find(CnCSignalRegionTag) == CnCSignalRegionMap.end())
    {
        cerr << "WARNING (" << __FILE__ << ", l." << __LINE__ << ")"
             << "Trying to access unknown CnC signal region tag '" << CnCSignalRegionTag << "'" << endl;
        return false;
    }
    else return true;
}

string CnClabel(string CnCSignalRegionTag, string mode) 
{
    // If tag starts with "CnC_", remove the 4 first characters
    // (so that "CnC_T2tt_offShellLoose" and "T2tt_offShellLoose" returns the same thing)
    if (CnCSignalRegionTag.find("CnC_") == 0)
        CnCSignalRegionTag = CnCSignalRegionTag.substr(4,CnCSignalRegionTag.size());

    // If tag starts with "cutAndCount_", remove the 12 first characters
    // (so that "cutAndCount_T2tt_offShellLoose" and "T2tt_offShellLoose" returns the same thing)
    if (CnCSignalRegionTag.find("cutAndCount_") == 0)
        CnCSignalRegionTag = CnCSignalRegionTag.substr(12,CnCSignalRegionTag.size());

    if (doesCnCSignalRegionExists(CnCSignalRegionTag) == false) return "";

         if (mode == "root")  return CnCSignalRegionMap[CnCSignalRegionTag].labelRoot;
    else if (mode == "latex") return CnCSignalRegionMap[CnCSignalRegionTag].labelLatex;
    else                      return "";
}

void loadCnCSignalRegions()
{
    loadCnCSignalRegion("preselection",         "Preselection",                  "Preselection",                    &preselection                    ); 
    loadCnCSignalRegion("T2tt_offShellLoose",   "T2tt, Off-shell loose",         "T2tt, Off-shell loose",           &cutAndCount_T2tt_offShellLoose  );
    loadCnCSignalRegion("T2tt_offShellTight",   "T2tt, Off-shell tight",         "T2tt, Off-shell tight",           &cutAndCount_T2tt_offShellTight  );
    loadCnCSignalRegion("T2tt_lowDeltaM",       "T2tt, Low #Delta m",            "T2tt, Low $\\Delta m$",           &cutAndCount_T2tt_lowDeltaM      );
    loadCnCSignalRegion("T2tt_mediumDeltaM",    "T2tt, Medium #Delta m",         "T2tt, Medium $\\Delta m$",        &cutAndCount_T2tt_mediumDeltaM   );
    loadCnCSignalRegion("T2tt_highDeltaM",      "T2tt, High #Delta m",           "T2tt, High $\\Delta m$",          &cutAndCount_T2tt_highDeltaM     );
    loadCnCSignalRegion("T2bw025_offShell",     "T2bw x=0.25, Off-shell",        "T2bw x=0.25, Off-shell",          &cutAndCount_T2bw025_offShell    );
    loadCnCSignalRegion("T2bw025_lowMasses",    "T2bw x=0.25, Low masses",       "T2bw x=0.25, Low masses",         &cutAndCount_T2bw025_lowMasses   );
    loadCnCSignalRegion("T2bw025_highMasses",   "T2bw x=0.25, High masses",      "T2bw x=0.25, High masses",        &cutAndCount_T2bw025_highMasses  );
    loadCnCSignalRegion("T2bw050_offShell",     "T2bw x=0.50, Off-shell",        "T2bw x=0.50, Off-shell",          &cutAndCount_T2bw050_offShell    );
    loadCnCSignalRegion("T2bw050_lowMasses",    "T2bw x=0.50, Low masses",       "T2bw x=0.50, Low masses",         &cutAndCount_T2bw050_lowMasses   );
    loadCnCSignalRegion("T2bw050_mediumDeltaM", "T2bw x=0.50, Medium #Delta m",  "T2bw x=0.50, Medium $\\Delta m$", &cutAndCount_T2bw050_mediumDeltaM);
    loadCnCSignalRegion("T2bw050_highDeltaM",   "T2bw x=0.50, High #Delta m",    "T2bw x=0.50, High $\\Delta m$",   &cutAndCount_T2bw050_highDeltaM  );
    loadCnCSignalRegion("T2bw075_lowDeltaM",    "T2bw x=0.75, Low #Delta m",     "T2bw x=0.75, Low $\\Delta m$",    &cutAndCount_T2bw075_lowDeltaM   );
    loadCnCSignalRegion("T2bw075_mediumDeltaM", "T2bw x=0.75, Medium #Delta m",  "T2bw x=0.75, Medium $\\Delta m$", &cutAndCount_T2bw075_mediumDeltaM);
    loadCnCSignalRegion("T2bw075_highDeltaM",   "T2bw x=0.75, High #Delta m",    "T2bw x=0.75, High $\\Delta m$",   &cutAndCount_T2bw075_highDeltaM  );
}


#endif
