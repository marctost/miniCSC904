
// 5 for top, 6 for bottom
void FitClusterC(TString filename, Int_t layer=5)
{
  // number of deviations for fitting range
  Float_t nDevForRange = 1.6;

  gROOT->SetBatch(kTRUE);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPalette(1, 0);
  gStyle->SetOptStat(1);
  gStyle->SetOptFit(1111);
  TCanvas * cankres1 = new TCanvas("cankres1", "Canvas with fit1", 1200, 800);

  // get the hist.
  TFile * fin = new TFile(filename, "READ");
  if (!fin->IsOpen()) return;
  TString nameHist = Form("DQMData/CSC_013_04/h1_CSC_013_04_CFEB_Clusters_Charge_Ly_%d", layer);
  TH1D * hClusterC = (TH1D*)gFile->Get(nameHist);
  Int_t entrHist = hClusterC->GetEntries();

  // use histogram statistics for the first fitting
  Float_t meanHist = hClusterC->GetMean();
  Float_t stdevHist = hClusterC->GetStdDev();
  double lowerFitBound = meanHist - stdevHist;
  double upperFitBound = meanHist + stdevHist;

  // use gaussian fit for now
  TF1 * funcGaus = new TF1("funcGaus","gaus");  
  funcGaus->SetParameter(0, hClusterC->GetMaximum() );
  funcGaus->SetParameter(1, meanHist);
  funcGaus->SetParameter(2, stdevHist);
  TFitResultPtr FitRes = hClusterC->Fit(funcGaus, "SRQ", "", lowerFitBound, upperFitBound);

  // use previous fitting results for new fittings
  Float_t meanFit, meanErrFit, stdevFit, stdevErrFit;
  for (Int_t i=0; i<3; i++) {    
    meanFit = FitRes->Parameter(1);
    meanErrFit = FitRes->ParError(1);
    stdevFit = FitRes->Parameter(2);
    stdevErrFit = FitRes->ParError(2);
    lowerFitBound = meanFit - nDevForRange * stdevFit;
    upperFitBound = meanFit + nDevForRange * stdevFit;

    funcGaus->SetParameter(0, FitRes->Parameter(0) );
    funcGaus->SetParameter(1, meanFit);
    funcGaus->SetParameter(2, stdevFit);
    FitRes = hClusterC->Fit(funcGaus, "SRQ", "", lowerFitBound, upperFitBound);
  }

  // save plots and output text file
  TString canSaveName = gFile->GetName();
  canSaveName.Remove((canSaveName.Length() - 5), 5);
  canSaveName += ".png";
  cankres1->SaveAs(canSaveName);

  FILE * fFitResults = fopen("results_fit.txt", "a");
  fprintf(fFitResults, "%.0f\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", 
    meanHist, entrHist, stdevHist, meanFit, meanErrFit, stdevFit, stdevErrFit);
  fclose(fFitResults);
}
