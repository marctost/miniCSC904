# I plot 2D dark current for both Irr. and Ref. layers
# Example command to run me: python plot_DC_2D.py chamber5
# I use pyROOT, so I need ROOT installed
# I count how many runs there are in the CSV file to decide the X-axis
# I assume Irr. current is from line 4 to line 11
# I assume Ref. current is from line 4 to line 7

from ROOT import *
import csv
import os
import sys

def main():
   # setup directory and canvas
   if not len(sys.argv)==2:
      print "I take only one argument (which chamber, like \"chamber5\")"
      return
   chamber = sys.argv[1]
   directory = chamber+"/Plots"
   if not os.path.exists(directory):
      os.makedirs(directory)

   cOutput = TCanvas('cOutput', '', 500, 500)
   cOutput.SetFillStyle(4000);
   cOutput.SetGrid()
   gStyle.SetOptStat(0);
   gStyle.SetPalette(kTemperatureMap)

   # read data from CSV into lists
   with open(chamber+"/analysis_page_darkCurrent.csv") as f:
      reader = csv.reader(f)
      data = [r for r in reader]

   irrVoltage = [2, 3, 3.3, 3.5, 3.6, 3.7, 3.8, 4]
   listIrrCurrent = []
   refVoltage = [2, 3, 3.6, 4]
   listRefCurrent = []

   # there are some missing data in the CSV. I set it to 0 for now
   for i in range(len(data[0])):
      if data[0][i]:
         listIrrCurrent.append([float(data[j][i+1]) if data[j][i+1] else 0 for j in range(3, 10+1) ])
         listRefCurrent.append([float(data[j][i+3]) if data[j][i+3] else 0 for j in range(3, 6+1) ])

   # create and fill histograms
   nRunIrr = len(listIrrCurrent)
   nVoltageIrr = len(irrVoltage)
   nRunRef = len(listRefCurrent)
   nVoltageRef = len(refVoltage)

   histIrr = TH2D("histIrr", ";run;V [kV]", nRunIrr, 0, nRunIrr, nVoltageIrr, 0, nVoltageIrr)
   histRef = TH2D("histRef", ";run;V [kV]", nRunRef, 0, nRunRef, nVoltageRef, 0, nVoltageRef)

   for i in xrange(0, nRunIrr):
      histIrr.GetXaxis().SetBinLabel(i+1, str(i) )
      for j in xrange(0,nVoltageIrr):
         if not i:
            histIrr.GetYaxis().SetBinLabel(j+1, str(irrVoltage[j]) )
         histIrr.SetBinContent(i+1, j+1, listIrrCurrent[i][j])

   for i in xrange(0, nRunRef):
      histRef.GetXaxis().SetBinLabel(i+1, str(i) )
      for j in xrange(0,nVoltageRef):
         if not i:
            histRef.GetYaxis().SetBinLabel(j+1, str(refVoltage[j]) )
         histRef.SetBinContent(i+1, j+1, listRefCurrent[i][j])

   # draw and save histograms
   histIrr.SetContour(200);
   histIrr.GetXaxis().SetLabelSize()
   histIrr.GetYaxis().SetLabelSize()
   histRef.SetContour(200);
   histRef.GetXaxis().SetLabelSize()
   histRef.GetYaxis().SetLabelSize()

   histIrr.Draw("ColZ")
   gPad.SetRightMargin(0.13);
   cOutput.SaveAs(directory+"/DC2D_Irr.pdf")
   histRef.Draw("ColZ")
   gPad.SetRightMargin(0.12);
   cOutput.SaveAs(directory+"/DC2D_Ref.pdf")

if __name__ == "__main__":
   main()
