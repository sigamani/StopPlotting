#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']


dataset_name 		= ['T2bw-025' , 'T2bw-050' , 'T2bw-075' , 'T2tt'] 
executable         	= "runAnalysis" 


for z in range(len(dataset_name)):


    inputfile = "root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-05-REDUCED/"+dataset_name[z]+".root"
    outputdir = pwd+"/batch_output_8_MT100/"+dataset_name[z] 
   	     
    os.system("rm -r "+outputdir)
    os.system("mkdir -p "+outputdir)
    os.system("mkdir -p "+outputdir+"/log/")
    os.system("mkdir -p "+outputdir+"/input/")
    os.system("mkdir -p "+outputdir+"/output/")
    os.system("mkdir -p "+outputdir+"/src/")


    for stopmass in range(100, 825, 25):

        for lspmass in range(0, 425, 25):

            if (stopmass - lspmass > 75):

                output = dataset_name[z]+"_"+str(stopmass)+"_"+str(lspmass)
                outputname = outputdir+"/src/"+output+".src"
                outputfile = open(outputname,'w')
                outputfile.write('#!/bin/bash\n')
                outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
                outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
                outputfile.write('cd /tmp/sigamani; \n')
                outputfile.write('cp /afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_14_STOPS/src/Stops-AN-14-067/runAnalysis/'+executable+' .; \n')
                outputfile.write("./"+executable+" "+inputfile+ " "+output+".root " +str(stopmass)+" "+str(lspmass)+";")
                outputfile.write("cp "+output+".root "+outputdir+"/output/ ; rm "+output+".root; ")
                outputfile.close
		if (dataset_name[z] == 'T2tt'):
                    os.system("echo bsub -q 2nd -o "+outputdir+"/log/"+output+".log source "+outputname)
                    os.system("bsub -q 2nd -o "+outputdir+"/log/"+output+".log source "+outputname)
    		    time.sleep(1)
		else:
                    os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
                    os.system("bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
    		time.sleep(1)
