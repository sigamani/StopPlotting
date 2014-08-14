#!/bin/csh 

# Check if we have the current directory in the library paths
# and add it if not.

set TEST=`echo $LD_LIBRARY_PATH | grep $PWD`
if ($TEST == "" ) then
    setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PWD}
endif

setenv PATH $PWD/LHAPDF/bin:$PATH
setenv LD_LIBRARY_PATH $PWD/LHAPDF/lib:$LD_LIBRARY_PATH
setenv PYTHONPATH $PWD/LHAPDF/lib64/python2.6/site-packages:$PYTHONPATH
