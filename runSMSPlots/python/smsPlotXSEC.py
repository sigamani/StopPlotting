import ROOT as rt
from array import *
from sms import *
from smsPlotABS import *

# class producing the 2D plot with xsec colors
class smsPlotXSEC(smsPlotABS):

    def __init__(self, modelname, histo, obsLimits, expLimits, energy, lumi, preliminary, label):
        self.standardDef(modelname, histo, obsLimits, expLimits, energy, lumi, preliminary)
        self.LABEL = label
        # canvas for the plot
        self.c = rt.TCanvas("cCONT_%s" %label,"cCONT_%s" %label,600,600)
        self.histo = histo['histogram']
        # canvas style
        self.setStyle()
        self.setStyleCOLZ()

    # define the plot canvas
    def setStyleCOLZ(self):        
        # set z axis
        self.histo.GetZaxis().SetLabelFont(42)
        self.histo.GetZaxis().SetTitleFont(42)
        self.histo.GetZaxis().SetLabelSize(0.035)
        self.histo.GetZaxis().SetTitleSize(0.035)
        self.histo.GetZaxis().SetRangeUser(10e-4,10)

        # define the palette for z axis
        NRGBs = 5
        NCont = 255
        stops = array("d",[0.00, 0.34, 0.61, 0.84, 1.00])
        red= array("d",[0.50, 0.50, 1.00, 1.00, 1.00])
        green = array("d",[ 0.50, 1.00, 1.00, 0.60, 0.50])
        blue = array("d",[1.00, 1.00, 0.50, 0.40, 0.50])
        rt.TColor.CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont)
        rt.gStyle.SetNumberContours(NCont)
        
        self.c.cd()
        self.histo.Draw("colz")
        
        rt.gPad.Update()
        palette = self.histo.GetListOfFunctions().FindObject("palette")
        palette.SetX1NDC(1.-0.18)
        palette.SetY1NDC(0.14)
        palette.SetX2NDC(1.-0.13)
        palette.SetY2NDC(1.-0.08)
        palette.SetLabelFont(42)
        palette.SetLabelSize(0.035)


    def DrawPaletteLabel(self):
        textCOLZ = rt.TLatex(0.98,0.15,"95% C.L. upper limit on cross section (pb)")
        textCOLZ.SetNDC()
        #textCOLZ.SetTextAlign(13)
        textCOLZ.SetTextFont(42)
        textCOLZ.SetTextSize(0.045)
        textCOLZ.SetTextAngle(90)
        textCOLZ.Draw()
        self.c.textCOLZ = textCOLZ


    def DrawKinematicLimitLinesT2bw075(self):
        lm = rt.TLine( 80/0.75, 0. , 416. , 416. - 80./0.75)
        lm.SetLineColor(1) 
        lm.SetLineWidth(2)
        lm.SetLineStyle(2)
        lm2 = rt.TLine( 87.5, 12.5 , 384 , 384 - 87.5 + 12.5) 
        lm2.SetLineColor(1) 
        lm2.SetLineWidth(2)
        lm2.SetLineStyle(2)
        lm.Draw("SAME")       
        lm2.Draw("SAME")  
        tex = rt.TLatex(0.238255,0.2377622,"m_{#tilde{#chi}^{#pm}_{1}} - m_{#tilde{#chi}^{0}_{1}} = m_{W}");
        tex.SetNDC()
        tex.SetTextAlign(12)
        tex.SetTextFont(42)
        tex.SetTextSize(0.03)
        tex.SetTextAngle(62.35402) 

        tex.SetLineWidth(2)
        tex.Draw("SAME")
        tex2 = rt.TLatex(0.2516779,0.4685315,"m_{#tilde{t}} = m_{b} + m_{W} + m_{#tilde{#chi}^{0}_{1}}");
        tex2.SetNDC()
        tex2.SetTextAlign(12)
        tex2.SetTextFont(42)
        tex2.SetTextSize(0.03)
        tex2.SetTextAngle(62.35402)
        tex2.SetLineWidth(2)
        tex2.Draw("SAME")
   
        tex3 = rt.TLatex(0.14,0.065,"m_{#tilde{#chi}^{0}_{1}} = 0.75 m_{#tilde{t}} + 0.25 m_{#tilde{#chi}^{0}_{1}}");
        tex3.SetNDC()
        tex3.SetTextAlign(13)
        tex3.SetTextFont(42)
        tex3.SetTextSize(0.04)
        tex3.SetLineWidth(2)
        tex3.Draw()

        self.c.lm = lm
        self.c.lm2 = lm2
        self.c.tex = tex
        self.c.tex2 = tex2
        self.c.tex3 = tex3


    def DrawKinematicLimitLinesT2bw050(self):
        lm = rt.TLine( 80/0.50, 0. , 469. , 469. - 80./0.50)
        lm.SetLineColor(1) 
        lm.SetLineWidth(2)
        lm.SetLineStyle(2)
        lm2 = rt.TLine( 87.5, 12.5 , 384 , 384 - 87.5 + 12.5)
        lm2.SetLineColor(1) 
        lm2.SetLineWidth(2)
        lm2.SetLineStyle(2)
        lm.Draw("SAME")       
        lm2.Draw("SAME")       
        tex = rt.TLatex(0.4211409,0.5192308,"m_{#tilde{#chi}^{#pm}_{1}} - m_{#tilde{#chi}^{0}_{1}} = m_{W}");
        tex.SetNDC()
        tex.SetTextAlign(12)
        tex.SetTextFont(42)
        tex.SetTextSize(0.03)
        tex.SetTextAngle(62.35402) 

        tex.SetLineWidth(2)
        tex.Draw("SAME")
        tex2 = rt.TLatex(0.2516779,0.4685315,"m_{#tilde{t}} = m_{b} + m_{W} + m_{#tilde{#chi}^{0}_{1}}");
        tex2.SetNDC()
        tex2.SetTextAlign(12)
        tex2.SetTextFont(42)
        tex2.SetTextSize(0.03)
        tex2.SetTextAngle(62.35402)
        tex2.SetLineWidth(2)
        tex2.Draw("SAME")

        tex3 = rt.TLatex(0.14,0.065,"m_{#tilde{#chi}^{0}_{1}} = 0.50 m_{#tilde{t}} + 0.50 m_{#tilde{#chi}^{0}_{1}}");
        tex3.SetNDC()
        tex3.SetTextAlign(13)
        tex3.SetTextFont(42)
        tex3.SetTextSize(0.04)
        tex3.SetLineWidth(2)
        tex3.Draw()

        self.c.lm = lm
        self.c.lm2 = lm2
        self.c.tex = tex
        self.c.tex2 = tex2
        self.c.tex3 = tex3
            
    def DrawKinematicLimitLinesT2bw025(self):
        lm = rt.TLine( 80/0.25, 0. , 629. , 629. - 80./0.25)
        lm.SetLineColor(1) 
        lm.SetLineWidth(2)
        lm.SetLineStyle(2)
        lm2 = rt.TLine( 87.5, 12.5 , 384 , 384 - 87.5 + 12.5)
        lm2.SetLineColor(1) 
        lm2.SetLineWidth(2)
        lm2.SetLineStyle(2)
        lm.Draw("SAME")       
        lm2.Draw("SAME")       
        tex = rt.TLatex(0.4161074,0.2202797,"m_{#tilde{#chi}^{#pm}_{1}} - m_{#tilde{#chi}^{0}_{1}} = m_{W}");
        tex.SetNDC()
        tex.SetTextAlign(12)
        tex.SetTextFont(42)
        tex.SetTextSize(0.03)
        tex.SetTextAngle(62.35402) 

        tex.SetLineWidth(2)
        tex.Draw("SAME")
        tex2 = rt.TLatex(0.2466443,0.4615385,"m_{#tilde{t}} = m_{b} + m_{W} + m_{#tilde{#chi}^{0}_{1}}");
        tex2.SetNDC()
        tex2.SetTextAlign(12)
        tex2.SetTextFont(42)
        tex2.SetTextSize(0.03)
        tex2.SetTextAngle(62.35402)
        tex2.SetLineWidth(2)
        tex2.Draw("SAME")
        tex3 = rt.TLatex(0.14,0.065,"m_{#tilde{#chi}^{0}_{1}} = 0.25 m_{#tilde{t}} + 0.75 m_{#tilde{#chi}^{0}_{1}}");
        tex3.SetNDC()
        tex3.SetTextAlign(13)
        tex3.SetTextFont(42)
        tex3.SetTextSize(0.04)
        tex3.SetLineWidth(2)
        tex3.Draw()

        self.c.lm = lm
        self.c.lm2 = lm2
        self.c.tex = tex
        self.c.tex2 = tex2
        self.c.tex3 = tex3


    def DrawKinematicLimitLinesT2tt(self):
        tex = rt.TLatex(0.3842282,0.534965,"m_{#tilde{t}} - m_{#tilde{#chi}^{0}_{1}} = m_{t}");
        tex.SetNDC()
        tex.SetTextAlign(12)
        tex.SetTextFont(42)
        tex.SetTextSize(0.03)
        tex.SetTextAngle(62.35402) 
        tex.SetLineWidth(2)
        tex.Draw("SAME")
        #tex2 = rt.TLatex(0.2734899,0.5192308,"m_{#tilde{#chi}^{#pm}_{1}} - m_{#tilde{#chi}^{0}_{1}} = m_{W}");
        tex2 = rt.TLatex(0.2734899,0.5192308,"m_{#tilde{t}} = m_{b} + m_{W} + m_{#tilde{#chi}^{0}_{1}}"); 
        tex2.SetNDC()
        tex2.SetTextAlign(12)
        tex2.SetTextFont(42)
        tex2.SetTextSize(0.03)
        tex2.SetTextAngle(61.34288)
        tex2.SetLineWidth(2)
        tex2.Draw("SAME")


        lm = rt.TLine( 173, 0. , 482. , 482. - 173)
        lm.SetLineColor(1) 
        lm.SetLineWidth(2)
        lm.SetLineStyle(2)
        lm2 = rt.TLine( 87.5, 12.5 , 384 , 384 - 87.5 + 12.5) # 309
        lm2.SetLineColor(1) 
        lm2.SetLineWidth(2)
        lm2.SetLineStyle(2)
        lm.Draw("SAME")       
        lm2.Draw("SAME")       
        self.c.lm = lm
        self.c.lm2 = lm2
        self.c.tex = tex
        self.c.tex2 = tex2

    def Draw(self):
        self.emptyHisto.GetXaxis().SetRangeUser(self.model.Xmin, self.model.Xmax)
        self.emptyHisto.GetYaxis().SetRangeUser(self.model.Ymin, self.model.Ymax)
        self.emptyHisto.Draw()
        self.histo.Draw("COLZSAME")
        #self.DrawKinematicLimitLines()
        self.DrawDiagonal()
        self.DrawLines()
        self.DrawText()
        self.DrawLegend()
        self.DrawPaletteLabel()
	  
