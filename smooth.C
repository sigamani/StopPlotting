
double ReturnSmoothedLimit( double x, double y, double limit, TString decay_mode, TString EXP ){


        if (decay_mode=="T2bw025") {

            if ( x == 125 &&  y == 0 ) limit = 1.1;
            if ( x == 150 &&  y == 0 ) limit = 1.1;
		}

/*
        if (decay_mode=="T2bw075") {

            if ( x == 125 &&  y == 0 ) limit = 1.1;
		}

        if (decay_mode=="T2bw075" && EXP=="Exp") {

            if ( x == 150 &&  y == 0 ) limit = 0.9;
            if ( x == 150 &&  y == 25 ) limit = 0.9;
            if ( x == 150 &&  y == 75 ) limit = 0.9;
		}
*/
		return limit; 

}
