
import ROOT
from ROOT import TFile, TLatex ,TTree, TCanvas, TGraph, TMultiGraph, TGraphErrors, TLegend
#import CMS_lumi, tdrstyle
import subprocess # to execute shell command
ROOT.gROOT.SetBatch(ROOT.kTRUE)
import sys


coupling = sys.argv[1]

fac = float(coupling)*float(coupling)

print(fac)
points = [250, 500,   750,   1000,  1250,  1500,  1750,   2000,   2500,   3000,    4000]
xsec = [1846., 172.5, 37.93, 11.93, 4.557, 1.971, 0.9264, 0.4633, 0.1313, 0.04129, 0.004812]
#points = [250, 500,   750,   1000,  1250,  1500,  1750,   2000,   2500]
#xsec = [1846., 172.5, 37.93, 11.93, 4.557, 1.971, 0.9264, 0.4633, 0.1313]
def executeCards(points):
    mass = len(points)
    for j in range(mass):
        file_name = "combined_zprime_etau_2016_signal_"+str(points[j])+".txt"
        combine_command = "combine -M AsymptoticLimits -m %s %s" % (points[j], file_name)
        print(">>> " + combine_command)
        p = subprocess.Popen(combine_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        for line in p.stdout.readlines():
            print line.rstrip("\n")
            print(">>>   higgsCombine_M"+str(points[j])+"_AsymptoticLimits.root created")
            retval = p.wait()

#get limits from root file


def getLimits(file_name):
        file = TFile(file_name)
        tree = file.Get("limit")

        limits = [ ]
        for quantile in tree:
            limits.append(tree.limit)
            print ">>>   %.2f" % limits[-1]

        return limits[:6]

#plot limits

def plotUpperLimits(file_name):
    # see CMS plot guidelines: https://ghm.web.cern.ch/ghm/plots/

    N = len(points)
    yellow = TGraph(2*N)    # yellow band
    green = TGraph(2*N)     # green band
    median = TGraph(N)      # median line
    theo_line = TGraph(N)      # median line 
    theo_p1sig = TGraph(N)
    theo_m1sig = TGraph(N)
theo_line_10p = TGraph(N)
    theo_line_1p = TGraph(N)

    up2s = [ ]
    for i in range(N):
        file_name = "higgsCombineTest.AsymptoticLimits.mH"+str(points[i])+".root"
        limit = getLimits(file_name)
        up2s.append(limit[4])
        yellow.SetPoint(    i,    points[i], limit[4]*0.1 ) # + 2 sigma
        green.SetPoint(     i,    points[i], limit[3]*0.1 ) # + 1 sigma
        median.SetPoint(    i,    points[i], limit[2]*0.1 ) # median
        green.SetPoint(  2*N-1-i, points[i], limit[1]*0.1 ) # - 1 sigma
        yellow.SetPoint( 2*N-1-i, points[i], limit[0]*0.1 ) # - 2 sigma
        #yellow.SetPoint(    i,    points[i], limit[4]*xsec[i]*1.3/0.1 ) # + 2 sigma
        #green.SetPoint(     i,    points[i], limit[3]*xsec[i]*1.3/0.1 ) # + 1 sigma
        #median.SetPoint(    i,    points[i], limit[2]*xsec[i]*1.3/0.1 ) # median
        #green.SetPoint(  2*N-1-i, points[i], limit[1]*xsec[i]*1.3/0.1 ) # - 1 sigma
        #yellow.SetPoint( 2*N-1-i, points[i], limit[0]*xsec[i]*1.3/0.1 ) # - 2 sigma
        theo_line.SetPoint( i,    points[i], fac*xsec[i]*1.3)
        theo_p1sig.SetPoint( i,    points[i],fac*xsec[i]*1.3+0.021*fac*xsec[i]*1.3)
        theo_m1sig.SetPoint( i,    points[i],fac*xsec[i]*1.3-0.021*fac*xsec[i]*1.3)
        theo_line_10p.SetPoint( i,    points[i], fac*xsec[i]*1.3*0.1)
        theo_line_1p.SetPoint( i,    points[i], fac*xsec[i]*1.3*0.01)
        print(xsec[i])
        print(xsec[i]+0.021*xsec[i])
    W = 800
    H  = 600
    T = 0.08*H
    B = 0.12*H
    L = 0.12*W
    R = 0.04*W
    c = TCanvas("c","c",100,100,W,H)
    c.SetFillColor(0)
    c.SetBorderMode(0)
    c.SetFrameFillStyle(0)
    c.SetFrameBorderMode(0)
    c.SetLeftMargin( L/W )
    c.SetRightMargin( R/W )
    c.SetTopMargin( T/H )
    c.SetBottomMargin( B/H )
    c.SetTickx(0)
    c.SetTicky(0)
    c.SetLogy()
#    c.SetGrid()

c.cd()
    frame = c.DrawFrame(2000.4,0.001, 2400.1, 10)

#    frame.GetYaxis().CenterTitle()
    frame.GetYaxis().SetTitleSize(0.05)
    frame.GetXaxis().SetTitleSize(0.05)
    frame.GetXaxis().SetLabelSize(0.04)
    frame.GetYaxis().SetLabelSize(0.04)
    frame.GetYaxis().SetTitleOffset(0.9)
    frame.GetXaxis().SetNdivisions(508)
#    frame.GetYaxis().CenterTitle(True)
    frame.GetYaxis().SetTitle("#sigma #times B [pb]")
#    frame.GetYaxis().SetTitle("95% upper limit on #sigma #times BR / (#sigma #times BR)_{SM}")
    frame.GetXaxis().SetTitle("M_{Z'} [GeV]")
    frame.SetMinimum(0.001)
#    frame.SetMaximum(max(up2s)*1.05)
    frame.SetMaximum(max(up2s)*6.05)
    frame.GetXaxis().SetLimits(min(points),max(points))
    yellow.SetFillColor(ROOT.kOrange)
    yellow.SetLineColor(ROOT.kOrange)
    yellow.SetFillStyle(1001)
    yellow.Draw('F')

    green.SetFillColor(ROOT.kGreen+1)
    green.SetLineColor(ROOT.kGreen+1)
    green.SetFillStyle(1001)
    green.Draw('Fsame')

    median.SetLineColor(1)
    median.SetLineWidth(2)
    median.SetLineStyle(2)
    median.Draw('Lsame')

    theo_line.SetLineColor(2)
    theo_line.SetLineWidth(2)
    theo_line.SetLineStyle(2)
    theo_line.Draw('Lsame')

    theo_p1sig.SetLineColor(2)
    theo_p1sig.SetLineWidth(2)
    theo_p1sig.SetLineStyle(2)
    theo_p1sig.Draw('Lsame')

    theo_m1sig.SetLineColor(2)
    theo_m1sig.SetLineWidth(2)
    theo_m1sig.SetLineStyle(2)
    theo_m1sig.Draw('Lsame')

theo_line_10p.SetLineColor(4)
    theo_line_10p.SetLineWidth(2)
    theo_line_10p.SetLineStyle(2)
    theo_line_10p.Draw('Lsame')

    theo_line_1p.SetLineColor(6)
    theo_line_1p.SetLineWidth(2)
    theo_line_1p.SetLineStyle(2)
    theo_line_1p.Draw('Lsame')

    #CMS_lumi.CMS_lumi(c,14,11)
    ROOT.gPad.SetTicks(1,1)
    frame.Draw('sameaxis')

    x1 = 0.67
    x2 = x1 + 0.25
    y2 = 0.86
    y1 = 0.66
    legend = TLegend(x1,y1,x2,y2)
    legend.SetFillStyle(0)
    legend.SetBorderSize(0)
    legend.SetTextSize(0.041)
    legend.SetTextFont(42)
    legend.SetHeader("95% CL limits")
    legend.AddEntry(median, "Expected",'L')
    legend.AddEntry(green, "#pm 1 std. deviation",'f')
#    legend.AddEntry(green, "Asymptotic CL_{s} #pm 1 std. deviation",'f')
    legend.AddEntry(yellow,"#pm 2 std. deviation",'f')
    legend.AddEntry(theo_line, "Z' #rightarrow #tau#tau #rightarrow e#tau (BF = 1)",'LEP')
    legend.AddEntry(theo_line_10p, "Z' #rightarrow #tau#tau #rightarrow e#tau (BF = 0.1)",'LEP')
    legend.AddEntry(theo_line_1p, "Z' #rightarrow #tau#tau #rightarrow e#tau (BF = 0.01)",'LEP')
#    legend.AddEntry(green, "Asymptotic CL_{s} #pm 2 std. deviation",'f')
    legend.Draw()

    tex0 = TLatex(352.0408,17185.27,"CMS Preliminary");
    tex0.SetTextFont(42);
    tex0.SetLineWidth(2);
    tex0.Draw();
    tex = TLatex(2696.071,17185.27,"35.9 fb^{-1} , 13 TeV");
    tex.SetTextFont(42);
    tex.SetLineWidth(2);
    tex.Draw();

    print " "
    c.SaveAs("eTau_2016_gl1_UpperLimit.png")
    c.SaveAs("eTau_2016_gl1_UpperLimit.root")
    c.Close()

def main():
        executeCards(points)
        plotUpperLimits(points)

if __name__ == '__main__':
    main()
