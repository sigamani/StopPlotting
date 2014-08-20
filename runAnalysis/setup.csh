#!/bin/csh 

# Check if we have the current directory in the library paths
# and add it if not.

set TEST=`echo $LD_LIBRARY_PATH | grep $PWD`
if ($TEST == "" ) then
    setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PWD}
endif
