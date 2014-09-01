#ifndef _SignalRegionDefinitions_h
#define _SignalRegionDefinitions_h


// This function maps the SRs to the signal plane in the BDT analysis

TString signalregionName(TString decaymode, int stopmass, int lspmass)  
{

    TString SR = "nan";

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
        if (lspmass > stopmass - 150){
            SR = "T2bw050_1_lowDM_lowLSP";
				if (lspmass >= 125) SR = "T2bw050_1_lowDM_highLSP";
           }
        if (lspmass <= stopmass - 150 && lspmass > stopmass - 250) {
			SR = "T2bw050_1_highDM";
		}
        if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            SR = "T2bw050_3";
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 550)
            SR = "T2bw050_4";
        if (lspmass <= stopmass - 550 && lspmass > stopmass - 625)
            SR = "T2bw050_5"; 
        if (lspmass <= stopmass - 625)
            SR = "T2bw050_6";
    }    



    if (decaymode == "T2bw025") 
    {
          if (lspmass > stopmass - 225)
            SR = "T2bw025_1"; 
          if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            SR = "T2bw025_3";
          if (lspmass <= stopmass - 275 && lspmass > stopmass - 375)
            SR = "T2bw025_3";
          if (lspmass <= stopmass - 375 && lspmass > stopmass - 600){
            SR = "T2bw025_4_highLSP";
                if (lspmass <= 100) SR = "T2bw025_4_lowLSP";
            }
          if (lspmass <= stopmass - 600)
            SR = "T2bw025_6";


    }



    if (decaymode == "T2tt") 
    {
        if (lspmass > stopmass - 225 ) {
             SR = "T2tt_1_highLSP";
             if (lspmass <= 100 && lspmass > 50)
             SR = "T2tt_1_mediumLSP";
             if (lspmass <= 50)
             SR = "T2tt_1_lowLSP";
        }
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 325)
            SR = "T2tt_2";
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            SR = "T2tt_5_lowDM";
        if (lspmass <= stopmass - 400 ) 
            SR = "T2tt_5_highDM"; 

    }

    return SR;
}




double BDToutput(TString BDTregion)
{
    	 if (BDTregion == "T2tt_1_lowLSP" ) return myEvent.BDT_output_t2tt_R1;
    else if (BDTregion == "T2tt_1_highLSP")	return myEvent.BDT_output_t2tt_R1;
    else if (BDTregion == "T2tt_2_lowDM" ) return myEvent.BDT_output_t2tt_R2;
    else if (BDTregion == "T2tt_2" ) return myEvent.BDT_output_t2tt_R2;
    else if (BDTregion == "T2tt_5_lowDM" ) return myEvent.BDT_output_t2tt_R5;
    else if (BDTregion == "T2tt_5_mediumDM" ) return myEvent.BDT_output_t2tt_R5;
    else if (BDTregion == "T2tt_5_highDM" ) return myEvent.BDT_output_t2tt_R5;

    else if (BDTregion == "T2bw075_1" ) return myEvent.BDT_output_t2bw075_R1;
    else if (BDTregion == "T2bw075_2" ) return myEvent.BDT_output_t2bw075_R2;
    else if (BDTregion == "T2bw075_3" ) return myEvent.BDT_output_t2bw075_R3;
    else if (BDTregion == "T2bw075_5_lowDM" ) return myEvent.BDT_output_t2bw075_R5;
    else if (BDTregion == "T2bw075_5_highDM") return myEvent.BDT_output_t2bw075_R5;

    else if (BDTregion == "T2bw050_1_lowDM" ) return myEvent.BDT_output_t2bw050_R1;
    else if (BDTregion == "T2bw050_1_highDM") return myEvent.BDT_output_t2bw050_R1;
    else if (BDTregion == "T2bw050_3" ) return myEvent.BDT_output_t2bw050_R3;
    else if (BDTregion == "T2bw050_4" ) return myEvent.BDT_output_t2bw050_R4;
    else if (BDTregion == "T2bw050_5" ) return myEvent.BDT_output_t2bw050_R5;
    else if (BDTregion == "T2bw050_6" ) return myEvent.BDT_output_t2bw050_R6;

    else if (BDTregion == "T2bw025_1" ) return myEvent.BDT_output_t2bw025_R1;
    else if (BDTregion == "T2bw025_3" ) return myEvent.BDT_output_t2bw025_R3;
    else if (BDTregion == "T2bw025_3_highDM") return myEvent.BDT_output_t2bw025_R3;
    else if (BDTregion == "T2bw025_4" ) return myEvent.BDT_output_t2bw025_R4;
    else if (BDTregion == "T2bw025_6" ) return myEvent.BDT_output_t2bw025_R6;

    else
    {
        cerr << "WARNING (" << __FILE__ << ", l." << __LINE__ << ")"
            << "Trying to read cut for unknown BDT region '" << BDTregion << "'" << endl;
        return -10.0;
    }
}


double BDTcut(TString BDTregion)
{
    	 if (BDTregion == "T2tt_1_lowLSP" ) 	return 0.175;
    else if (BDTregion == "T2tt_1_mediumLSP")	return 0.325;
    else if (BDTregion == "T2tt_1_highLSP" )	return 0.375;
    else if (BDTregion == "T2tt_2" )		return 0.35 ;
    else if (BDTregion == "T2tt_5_lowDM" )		return 0.30 ;
    else if (BDTregion == "T2tt_5_highDM" )		return 0.325;

    else if (BDTregion == "T2bw075_1" )			return 0.225;
    else if (BDTregion == "T2bw075_2" )			return 0.275;
    else if (BDTregion == "T2bw075_3" )			return 0.3;
    else if (BDTregion == "T2bw075_5_lowDM" )	return 0.25 ;
    else if (BDTregion == "T2bw075_5_highDM")	return 0.3 ;

    else if (BDTregion == "T2bw050_1_lowDM_lowLSP")	return 0.275;
    else if (BDTregion == "T2bw050_1_highDM")	return 0.175;
    else if (BDTregion == "T2bw050_1_lowDM_highLSP")	return 0.375;
    else if (BDTregion == "T2bw050_3" )			return 0.3 ;
    else if (BDTregion == "T2bw050_4" )			return 0.250;
    else if (BDTregion == "T2bw050_5" ) 	return 0.275;
    else if (BDTregion == "T2bw050_6" ) 		return 0.2 ; 

    else if (BDTregion == "T2bw025_1" ) 		return 0.2 ;
    else if (BDTregion == "T2bw025_3" ) 	return 0.2 ;
    else if (BDTregion == "T2bw025_4_highLSP") return 0.2 ;
    else if (BDTregion == "T2bw025_4_lowLSP" ) 	return 0.15 ;
    else if (BDTregion == "T2bw025_6" ) 		return 0.175; 

    else
    {
        cerr << "WARNING (" << __FILE__ << ", l." << __LINE__ << ")"
            << "Trying to read cut for unknown BDT region '" << BDTregion << "'" << endl;
        return -1.0;
    }
}


#endif
