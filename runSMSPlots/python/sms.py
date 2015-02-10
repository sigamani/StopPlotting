from array import *

class sms():

    def __init__(self, modelname):
        if modelname.find("T1tttt") != -1: self.T1tttt()
        if modelname.find("T2tt") != -1: self.T2tt()
        if modelname.find("T2bw") != -1: self.T2bw()
        if modelname.find("T1bbbb") != -1: self.T1bbbb()



    def T2bw(self):
        # model name
        self.modelname = "T2bw"
        # decay chain
        # scan range to plot
        self.label= "pp #rightarrow #tilde{t} #tilde{t*}, #tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1}";
        self.Xmin = 87.5
        self.Xmax = 812.5
        self.Ymin = -12.5
        self.Ymax = 412.5
        # produce sparticle
        self.sParticle = "m_{#tilde{t}} (GeV)"
        # LSP
        self.LSP = "m_{#tilde{#chi}^{0}_{1}} (GeV)"        
        # diagonal position: mLSP = mgluino - 2mtop 
        mW = 2000000 
        self.diagX = array('d',[0,20000])
        self.diagY = array('d',[-mW, 20000-mW])        


    def T2tt(self):
        # model name
        self.modelname = "T2tt"
        # decay chain
        self.label= "pp #rightarrow #tilde{t} #tilde{t*}, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}";
        # scan range to plot
        self.Xmin = 87.5 # 162.5
        self.Xmax = 812.5
        self.Ymin = -12.5 #12.5
        self.Ymax = 412.5
        # produce sparticle
        self.sParticle = "m_{#tilde{t}} (GeV)"
        # LSP
        self.LSP = "m_{#tilde{#chi}^{0}_{1}} (GeV)"        
        # diagonal position: mLSP = mgluino - 2mtop 
        mW = 200000 
        self.diagX = array('d',[0,20000])
        self.diagY = array('d',[-mW, 20000-mW])        


    def T1tttt(self):
        # model name
        self.modelname = "T1tttt"
        # decay chain
        self.label= "bla bla pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow t #bar{t} #tilde{#chi}^{0}_{1}";
        # scan range to plot
        self.Xmin = 600
        self.Xmax = 1400
        self.Ymin = 0
        self.Ymax = 800
        # produce sparticle
        self.sParticle = "m_{gluino} (GeV)"
        # LSP
        self.LSP = "m_{LSP} (GeV)"        
        # diagonal position: mLSP = mgluino - 2mtop 
        mW = 80
        self.diagX = array('d',[0,20000])
        self.diagY = array('d',[-mW, 20000-mW])        
        
    def T1bbbb(self):
        # model name
        self.modelname = "T1bbbb"
        # decay chain
        self.label= "pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow b #bar{b} #tilde{#chi}^{0}_{1}";
        # plot boundary. The top 1/4 of the y axis is taken by the legend
        self.Xmin = 400
        self.Xmax = 1600
        self.Ymin = 0
        self.Ymax = 1200
        # produce sparticle
        self.sParticle = "m_{gluino} (GeV)"
        # LSP
        self.LSP = "m_{LSP} (GeV)"
        # diagonal position: mLSP = mgluino - 2mtop
        self.diagX = array('d',[0,20000])
        self.diagY = array('d',[0, 20000])
