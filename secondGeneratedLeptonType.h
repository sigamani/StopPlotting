#ifndef _secondGeneratedLeptonType_h
#define _secondGeneratedLeptonType_h

enum SecondGeneratedLeptonType
{ 
    UNKNOWN,                    // Unkown case (shouldn't be happening if every case is correctly covered)
    NO_SECOND_LEPTON,           // No second lepton
    NOT_IN_ACCEPTANCE,          // There is a second lepton but not in acceptance
    ELEC_OR_MUON,               // If second lepton is a e/mu
    TAU_TO_ELEC_OR_MUON,        // If second lepton is a tau -> e/mu
    TAU_TO_ONE_PRONG,           // If second lepton is a tau -> one charged hadron with pT > 10 GeV
    TAU_TO_MORE_THAN_ONE_PRONG  // If second lepton is a tau -> multiple hadrons 
                                    // (or one charged hadron < 10 GeV but visible energy > 20 GeV)
};

SecondGeneratedLeptonType secondGeneratedLeptonType()
{
     // ######################################
     // #  Get indexes of generated leptons  #
     // ######################################
     
	 vector<int> genLeptons; 
	 for(unsigned int ip=0 ; ip < myEvent.genParticles.size() ; ip++)
     {
        int genParticlePDGId = abs(myEvent.genParticlesPDGId[ip]);

		if (genParticlePDGId == 11
         || genParticlePDGId == 13
         || genParticlePDGId == 15)
        {
            int genParticleMotherPDGId = abs(myEvent.genParticlesPDGId[myEvent.genParticlesMother[ip]]);
			if (genParticleMotherPDGId == 23
             || genParticleMotherPDGId == 24)
            {
				genLeptons.push_back(ip);
			}
		}
	 }

	 // Sort the vector in Pt
	 vector<TLorentzVector> genParticles = myEvent.genParticles; 
     sort(genLeptons.begin(),genLeptons.end(),
          [&genParticles](int index1, int index2)
          { 
             return genParticles[index1].Pt() > genParticles[index2].Pt(); 
          });

     // ##################################################
     // #  Check event has at least 2 generated leptons  #
     // ##################################################

     if (genLeptons.size() < 2) return NO_SECOND_LEPTON;

     // #####################################
     // #  Retrieve info of the 2nd lepton  #
     // #####################################
     
     int secondGenLeptonIndex = genLeptons[1];
     int secondGenLeptonPDGId = myEvent.genParticlesPDGId[secondGenLeptonIndex];
     TLorentzVector secondGenLepton = myEvent.genParticles[secondGenLeptonIndex];

     // #################################################
     // #  Make checks about the nature and acceptance  #
     // #################################################

     // Check second lepton is in eta < 2.5
	 if (abs(secondGenLepton.Eta()) > 2.5) return NOT_IN_ACCEPTANCE;

        // ###############
        // #  e/mu case  #
        // ###############

     if (abs(secondGenLeptonPDGId) < 14)       // Second lepton is an electron or muon
     {
         if (secondGenLepton.Pt() > 5) return ELEC_OR_MUON;
         else                          return NOT_IN_ACCEPTANCE;
     }
     
        // ##############
        // #  tau case  #
        // ##############
     
     //check if daughter lepton or single track has pT>10GeV
     if (abs(secondGenLeptonPDGId) == 15) 
     {

         // ## Access info of tau decay
         
         vector<int> tauDecay;
         bool tauHad = false;
         TLorentzVector taudvis;
         for (unsigned int td = secondGenLeptonIndex+1 ; td < myEvent.genParticles.size() ; td++)
         {
             if (myEvent.genParticlesMother[td] == secondGenLeptonIndex)
             {
                 if (abs(myEvent.genParticlesPDGId[td]) >  16) tauHad = true;

                 if (abs(myEvent.genParticlesPDGId[td]) != 16 
                 && abs(myEvent.genParticlesPDGId[td])  != 14 
                 && abs(myEvent.genParticlesPDGId[td])  != 12) 
                     taudvis+=myEvent.genParticles[td];

                 tauDecay.push_back(td);
             }
         }

         // ## Tau to hadronic decays
         
         if (tauHad)
         {
             int ntracks = 0;
             float trackPt = 0;
             for (unsigned int vtd=0 ; vtd < tauDecay.size() ; vtd++)
             {
                 int aid = abs(myEvent.genParticlesPDGId[tauDecay[vtd]]);
                 if (aid == 211 || aid == 321) 
                 {
                     trackPt = myEvent.genParticles[tauDecay[vtd]].Pt();
                     ntracks++;
                 }
             }

             // ## One-prong tau
             if ((ntracks == 1) && (trackPt > 10)) return TAU_TO_ONE_PRONG;
             else if (taudvis.Pt() > 20)           return TAU_TO_MORE_THAN_ONE_PRONG;
             else                                  return NOT_IN_ACCEPTANCE;
         }

         // ## Tau to leptonic decays

         else
         {
             for (unsigned int vtd=0;vtd<tauDecay.size();vtd++)
             {
                 int pdgId = abs(myEvent.genParticlesPDGId[tauDecay[vtd]]);
                 float pT = myEvent.genParticles[tauDecay[vtd]].Pt();

                 if (pdgId == 11 || pdgId == 13)
                 {
                     if (pT > 5) return TAU_TO_ELEC_OR_MUON;
                     else        return NOT_IN_ACCEPTANCE;
                 }
             }
         }

     }
	 
     return UNKNOWN;
}

#endif
