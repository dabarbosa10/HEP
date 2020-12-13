{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);
  gStyle->SetOptFit(kTRUE);


TFile *f00=new TFile("Zprime_NonUniversalSSM_M250_gl1p0_gh1p0_mg.root");
TFile *f01=new TFile("Zprime_NonUniversalSSM_M1000_gl1p0_gh1p0_mg.root");
TFile *f02=new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0_mg.root");
h_250=(TH1F *)f00->Get("NRecoTau1/Tau1Pt");
h_1000=(TH1F *)f01->Get("NRecoTau1/Tau1Pt");
h_2000=(TH1F *)f02->Get("NRecoTau1/Tau1Pt");
h_250->SetLineColor(2);
h_1000->SetLineColor(1);
h_250->GetXaxis()->SetTitle("P_{T}(#tau)[GeV] ");
h_250->GetYaxis()->SetTitle("a.u.");

h_250->DrawNormalized();
h_1000->DrawNormalized("Same");
h_2000->DrawNormalized("Same");
auto legend = new TLegend(0.7,0.7,0.98,0.9);
legend->AddEntry(h_250,"250GeV");
legend->AddEntry(h_1000,"1000GeV");
legend->AddEntry(h_2000,"2000GeV");
legend->Draw();
}