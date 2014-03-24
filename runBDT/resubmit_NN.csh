#!/usr/bin/env tcsh


set BASEDIR=$PWD

touch runNN.sh
echo "Re-submitting failed jobs......wait"

#/bin/ls -l Reg1_T2bw025/setup/setup_102 | awk '{print $9}' | sed 's#work_LM/setup/setup_##' | sed 's#.cfg##' > ! num.txt

#set low = `sort -n num.txt | head -1`
#set high = `sort -n num.txt | tail -1`



foreach i ( `seq 102 103` )


	foreach j ( LM IM1 IM2 HM )


	set datafile=Reg3_T2bw050/OUTPUT/setup_$i/NN/weights/BDT_BDT.weights.xml

	if ( -f $datafile ) then

	else
		 #echo "DID NOT FIND: $datafile"
		 set cmd = 'cd work_'$j'; sleep 2; ../JM.py "setup/setup_'$i'.cfg" ../JM_NN.py --create; python ../JM.py --submit --mode bsub --queue 8nh; cd '$BASEDIR'' 
		 echo $cmd >> runNN.sh 
	endif
	end

end

source runNN.sh
rm runNN.sh
rm num.txt
echo "Done"
