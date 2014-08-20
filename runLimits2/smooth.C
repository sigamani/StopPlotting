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


double ReturnCleanedLimit( double x, double y, double limit, TString decay_mode, bool isBDT = true, TString EXP ){


 if ( isBDT  == true) { 
 
     if (EXP == "ExpM") {

	if (decay_mode=="T2tt") {

               if ( (x == 200) && (y == 0)) limit = 1.1;
	}


	if (decay_mode=="T2bw075") { 

		if ( (x == 475) && (y == 350)  ) limit = 1.1;
		if ( (x == 750) && (y == 200)  ) limit = 1.1;
		if ( (x == 800) && (y == 225)  ) limit = 1.1;
		if ( (x == 800) && (y == 150)  ) limit = 1.1;
		if ( (x == 800) && (y == 75)  ) limit = 1.1;
		if ( (x == 775) && (y == 175)  ) limit = 1.1;

		if ( (x == 150) && (y == 0)  ) limit = 0.9;
		if ( (x == 150) && (y == 25)  ) limit = 0.9;
		if ( (x == 200) && (y == 0)  ) limit = 0.9;
		if ( (x == 425) && (y == 225)  ) limit = 0.9;
		if ( (x == 550) && (y == 250)  ) limit = 0.9;
		if ( (x == 625) && (y == 250)  ) limit = 0.9;
		if ( (x == 650) && (y == 200)  ) limit = 0.9;
		if ( (x == 650) && (y == 225)  ) limit = 0.9;
		if ( (x == 725) && (y == 175)  ) limit = 0.9;
		if ( (x == 775) && (y == 50)  ) limit = 0.9;
	}

     }
	
     if (EXP == "Exp") {

	if (decay_mode=="T2tt") {

               if ( (x == 150) && (y == 25)) limit = 0.9;     

	}


	if (decay_mode=="T2bw025") { 

//		if ( (x == 500) && (y == 400)) limit = 1.1;
		if ( (x == 450) && (y == 350)) limit = 1.1;
		if ( (x == 500) && (y == 400) ) limit = 1.1;

	}

	if (decay_mode=="T2bw050") { 

		if ( (x == 225) && (y == 100) ) limit = 0.9;
		if ( (x == 225) && (y == 75)  ) limit = 0.9;
		if ( (x == 250) && (y == 75)  ) limit = 0.9;
		if ( (x == 275) && (y == 25)  ) limit = 0.9;
		if ( (x == 325) && (y == 100) ) limit = 0.9;
		if ( (x == 600) && (y == 200) ) limit = 0.9; 

		if ( (x == 275) && (y == 150) ) limit = 1.1;
		if ( (x == 300) && (y == 175) ) limit = 1.1;
		if ( (x == 325) && (y == 200) ) limit = 1.1;
		if ( (x == 325) && (y == 175) ) limit = 1.1;
		if ( (x == 700) && (y == 200) ) limit = 1.1;
		if ( (x == 725) && (y == 150) ) limit = 1.1;
		if ( (x == 650) && (y == 250) ) limit = 1.1;

         
	}


	if (decay_mode=="T2bw075") { 

		if ( (x == 375) && (y == 250) ) limit = 1.1.;
		if ( (x == 425) && (y == 250)  ) limit = 1.1;

		if ( (x == 525) && (y == 225)  ) limit = 0.9;
		if ( (x == 425) && (y == 225)  ) limit = 0.9;
		if ( (x == 400) && (y == 200)  ) limit = 0.9;
		if ( (x == 200) && (y == 0)  ) limit = 0.9;
		if ( (x == 675) && (y == 125)  ) limit = 0.9;
		if ( (x == 150) && (y == 0)  ) limit = 0.9;
		if ( (x == 150) && (y == 25)  ) limit = 0.9;
	}

    }


     if (EXP == "ExpP") {

        if (decay_mode=="T2tt") {

               if ( (x == 150) && (y == 25)) limit = 0.9;
               if ( (x == 225) && (y == 100)) limit = 0.9;
               if ( (x == 275) && (y == 0)) limit = 0.9;
               if ( (x == 300) && (y == 0)) limit = 0.9;
               if ( (x == 400) && (y == 75)) limit = 0.9;
               if ( (x == 400) && (y == 75)) limit = 0.9;
               if ( (x == 425) && (y == 150)) limit = 0.9;
               if ( (x == 550) && (y == 150)) limit = 0.9;

	}

	if (decay_mode=="T2bw075") { 

		if ( (x == 325) && (y == 225)  ) limit = 1.1;
		if ( (x == 350) && (y == 225)  ) limit = 1.1;

		if ( (x == 150) && (y == 0)  ) limit = 0.9;
		if ( (x == 150) && (y == 25)  ) limit = 0.9;
		if ( (x == 175) && (y == 50)  ) limit = 0.9;
		if ( (x == 200) && (y == 0)  ) limit = 0.9;
		if ( (x == 325) && (y == 175)  ) limit = 0.9;
		if ( (x == 375) && (y == 175)  ) limit = 0.9;
		if ( (x == 500) && (y == 175)  ) limit = 0.9;
		if ( (x == 550) && (y == 150)  ) limit = 0.9;
		if ( (x == 550) && (y == 175)  ) limit = 0.9;
		if ( (x == 575) && (y == 125)  ) limit = 0.9;
		if ( (x == 575) && (y == 75)  ) limit = 0.9;
		if ( (x == 600) && (y == 100)  ) limit = 0.9;
	}

	
     }

  }

  if ( isBDT  == false) {

	     if (EXP == "ExpM") {

		if (decay_mode == "T2tt") {
		if ( (x == 650) && (y == 225) ) limit = 1.1;
		if ( (x == 375) && (y == 200) ) limit = 1.1;
		if ( (x == 325) && (y == 150) ) limit = 1.1;
		}

             }

	     if (EXP == "Exp") {


		if (decay_mode == "T2tt") {
		if ( (x == 125) && (y == 0) ) limit = 0.9;
		if ( (x == 225) && (y == 100) ) limit = 0.9;
		}


		if (decay_mode == "T2bw025") {
		if ( (x == 300) && (y == 50) ) limit = 0.9;
		if ( (x == 325) && (y == 75) ) limit = 0.9;
		if ( (x == 450) && (y == 50) ) limit = 0.9;
		if ( (x == 400) && (y == 25) ) limit = 0.9;
		if ( (x == 400) && (y == 50) ) limit = 0.9;
		if ( (x == 400) && (y == 75) ) limit = 0.9;

		if ( (x == 125) && (y == 0)  ) limit = 1.1;
		if ( (x == 125) && (y == 25)  ) limit = 1.1;
		if ( (x == 150) && (y == 50)  ) limit = 1.1;
		}


		if (decay_mode == "T2bw050") {
		if ( (x == 550) && (y == 175) ) limit = 0.9;
		if ( (x == 225) && (y == 25) ) limit = 0.9;

		if ( (x == 150) && (y == 50)  ) limit = 1.1;
		if ( (x == 200) && (y == 75)  ) limit = 1.1;
		if ( (x == 275) && (y == 125)  ) limit = 1.1;
		if ( (x == 325) && (y == 150)  ) limit = 1.1;
		if ( (x == 575) && (y == 200)  ) limit = 1.1;
		}

		if (decay_mode == "T2bw075") {
		if ( (x == 575) && (y == 75) ) limit = 0.9;
		if ( (x == 625) && (y == 50) ) limit = 0.9;
		if ( (x == 525) && (y == 150) ) limit = 0.9;
		if ( (x == 550) && (y == 150) ) limit = 0.9;

		if ( (x == 350) && (y == 175)  ) limit = 1.1;
		if ( (x == 375) && (y == 200)  ) limit = 1.1;
		if ( (x == 225) && (y == 150)  ) limit = 1.1;
		if ( (x == 225) && (y == 125)  ) limit = 1.1;
		if ( (x == 125) && (y == 25)  ) limit = 1.1;
		if ( (x == 250) && (y == 125)  ) limit = 1.1;
		
  		}
	    }


	     if (EXP == "ExpP") {

		if (decay_mode == "T2tt") {
		if ( (x == 575) && (y == 50) ) limit = 1.1;
		if ( (x == 550) && (y == 75) ) limit = 0.9;

		}
             }

	}
		return limit; 

}
