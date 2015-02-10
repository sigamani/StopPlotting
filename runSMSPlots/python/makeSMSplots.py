import sys
from inputFile import *
from smsPlotXSEC import *
from smsPlotCONT import *
from smsPlotBrazil import *

if __name__ == '__main__':
    # read input arguments
    filename = sys.argv[1]
    modelname = sys.argv[1].split("/")[-1].split("_")[0]
    analysisLabel = sys.argv[1].split("/")[-1].split("_")[1]
    outputname = sys.argv[2]


    print "********"
    print filename
    print modelname
    print analysisLabel
    print outputname
   
    print "********"

    # read the config file
    fileIN = inputFile(filename)
    
    # classic temperature histogra
    xsecPlot = smsPlotXSEC(modelname, fileIN.HISTOGRAM, fileIN.OBSERVED, fileIN.EXPECTED, fileIN.ENERGY, fileIN.LUMI, fileIN.PRELIMINARY, "")
    xsecPlot.Draw()
    if (modelname == "T2bw075"): 
        xsecPlot.DrawKinematicLimitLinesT2bw075()
    if (modelname == "T2bw050"): 
        xsecPlot.DrawKinematicLimitLinesT2bw050()
    if (modelname == "T2bw025"): 
        xsecPlot.DrawKinematicLimitLinesT2bw025()
    if (modelname == "T2tt"): 
        xsecPlot.DrawKinematicLimitLinesT2tt()
    xsecPlot.Save("%sXSEC_BDT" %outputname)

    # only lines
    #contPlot = smsPlotCONT(modelname, fileIN.HISTOGRAM, fileIN.OBSERVED, fileIN.EXPECTED, fileIN.ENERGY, fileIN.LUMI, fileIN.PRELIMINARY, "")
    #contPlot.Draw()
    #contPlot.Save("%sCONT" %outputname)

    # brazilian flag (show only 1 sigma)
    #brazilPlot = smsPlotBrazil(modelname, fileIN.HISTOGRAM, fileIN.OBSERVED, fileIN.EXPECTED, fileIN.ENERGY, fileIN.LUMI, fileIN.PRELIMINARY, "")
    #brazilPlot.Draw()
    #brazilPlot.Save("%sBAND" %outputname)
