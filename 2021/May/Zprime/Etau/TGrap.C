{
 TFile *f0  = new TFile("QCD_B_eTauF.root");
 TFile *f1  = new TFile("QCD_D_eTauF.root");

  h_qcdB = (TH1F *)f0->Get("Electron1Tau1ReconstructableMassDeltaPt");
  h_qcdD = (TH1F *)f1->Get("Electron1Tau1ReconstructableMassDeltaPt");
  
  TCanvas* c1 = new TCanvas("c1", "c1");
  TGraphAsymmErrors* gr1 = new TGraphAsymmErrors( h_qcdB, h_qcdD, "b(1,1)" );
  gr1->Draw();

//b(1,1) mode

}