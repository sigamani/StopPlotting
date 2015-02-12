#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "TCanvas.h"
#include "TLegend.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TPad.h"
#include "TCut.h"
#include "TProfile.h"
#include "THStack.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TLine.h"
#include "TMath.h"

using namespace std;


double ReturnSmoothedLimitCombination( double x, double y, double limit, TString decay_mode, TString EXP ){




     if (EXP == "ObsM") {
		
		if (decay_mode=="T2tt") { 

		}

		if (decay_mode=="T2bw025") { 
			

		}

		if (decay_mode=="T2bw050") { 


		}

		if (decay_mode=="T2bw075") { 

		}


	 } 


     if (EXP == "Obs") {
		
		if (decay_mode=="T2tt") { 

		}

		if (decay_mode=="T2bw025") { 

            if ( x == 575 &&  y == 125 ) limit = 0.9;
            if ( x == 525 &&  y == 150 ) limit = 0.9;
            if ( x == 550 &&  y == 150 ) limit = 0.9;
            if ( x == 575 &&  y == 150 ) limit = 0.9;
			
		}

		if (decay_mode=="T2bw050") { 

		}

		if (decay_mode=="T2bw075") { 

		}

	 } 



     if (EXP == "ObsP") {
		
		if (decay_mode=="T2tt") { 

		}

		if (decay_mode=="T2bw025") { 
			
		}

		if (decay_mode=="T2bw050") { 

		}

		if (decay_mode=="T2bw075") { 

		}


	 } 




     if (EXP == "ExpM") {

		if (decay_mode=="T2tt") {

		}

		if (decay_mode=="T2bw025") { 

		}

		if (decay_mode=="T2bw050") { 

    	}	

		if (decay_mode=="T2bw075") { 


		}

     }
	
     if (EXP == "Exp") {

		if (decay_mode=="T2tt") {

		}


		if (decay_mode=="T2bw025") { 

            if ( x == 125 &&  y == 0 ) limit = 1.1;
            if ( x == 175 &&  y == 50 ) limit = 1.1;
            if ( x == 525 &&  y == 150 ) limit = 0.9;
            if ( x == 525 &&  y == 175 ) limit = 0.9;
            if ( x == 575 &&  y == 150 ) limit = 0.9;

		}

		if (decay_mode=="T2bw050") { 

		}


		if (decay_mode=="T2bw075") { 


		}

     }


     if (EXP == "ExpP") {

        if (decay_mode=="T2tt") {

		}

		if (decay_mode=="T2bw025") { 

		}

		if (decay_mode=="T2bw050") { 

		}

		if (decay_mode=="T2bw075") { 

		}
	
     }

		return limit; 

}
