#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']

#dataset_name 		= ['SingleElec', 'SingleMuon', 'DoubleElec', 'DoubleMuon', 'MuEl', 'W+jets', 'rare', 'singleTop_st', 'ttbar_powheg', 'ttbar_madgraph_1l', 'ttbar_madgraph_2l', 'T2bw-025', 'T2bw-050', 'T2bw-075', 'T2tt', 'ttbar_madgraph_mass166-5', 'ttbar_madgraph_mass178-5', 'ttbar_madgraph_matchingdown', 'ttbar_madgraph_matchingup', 'ttbar_madgraph_scaledown', 'ttbar_madgraph_scaleup'] 
#dataset_name 		= ['T2bw-025', 'T2bw-050', 'T2bw-075', 'T2tt', 'W+jets', 'rare', 'ttbar_madgraph_1l'] 
dataset_name 		= ['Wjets'] 
outputEOSdir		= "/eos/cms/store/caf/user/sigamani/StopBabies/V00-06/"


for z in range(len(dataset_name)):

    outputdir = pwd+"/batch_output2/"+dataset_name[z] 

    os.system("rm -r "+outputdir)
    os.system("mkdir -p "+outputdir)
    os.system("mkdir -p "+outputdir+"/log/")
    os.system("mkdir -p "+outputdir+"/src/")

    outputname = outputdir+"/src/"+dataset_name[z]+".src"
    outputfile = open(outputname,'w')
    outputfile.write('#!/bin/bash\n')
    outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
    outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
    outputfile.write("./runExtender /afs/cern.ch/user/a/aaubin/work/public/stopBabies_1030/"+dataset_name[z]+".root /tmp/sigamani/"+dataset_name[z]+".root met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB met,lepton_pT,njets,mlb_hemi,m3b,mT2W,dR_LepB,dPhi_JetMet,b1_pt met,lepton_pT,njets,jet1_pT,HT,mlb_hemi,m3b,mT2W,dPhi_JetMet met,lepton_pT,mlb_hemi,HTfrac,njets,dPhi_JetMet,b1_pt met,mT2W,HTfrac,njets,dPhi_JetMet,lepton_pT,dR_LepB,Chi2SNT,jet1_pT; \n")
    outputfile.write('/afs/cern.ch/project/eos/installation/0.3.15/bin/eos.select rm '+outputEOSdir+'/'+dataset_name[z]+'.root; \n')
    outputfile.write('/usr/bin/xrdcp /tmp/sigamani/'+dataset_name[z]+'.root root://eoscms/'+outputEOSdir+'/'+dataset_name[z]+'.root; \n')
    outputfile.write('rm /tmp/sigamani/'+dataset_name[z]+'.root \n')
    outputfile.close
    os.system("echo bsub -q 1nw -o "+outputdir+"/log/"+dataset_name[z]+".log source "+outputname)
    os.system("bsub -q 1nw -o "+outputdir+"/log/"+dataset_name[z]+".log source "+outputname)
