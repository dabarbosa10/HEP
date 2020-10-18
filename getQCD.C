void getQCD(){
   TFile *f_data = new TFile ("Data.root");
   TFile *f_dy   = new TFile ("DY+Jets.root");
   TFile *f_wj   = new TFile ("W+Jets.root");
   TFile *f_tt   = new TFile ("tbar{t}.root");
   TFile *f_vv   = new TFile ("VV.root");
   TFile *f_st   = new TFile ("SingleTop.root");
   TFile *f_qcd  = new TFile ("QCD_mass.root", "UPDATE");

  f_data->cd("NDiJetCombinations");
  TH1F* h_data = DiTauDiJetReconstructableMass;
  f_vv->cd("NDiJetCombinations");
  TH1F* h_vv = DiTauDiJetReconstructableMass;
  f_dy->cd("NDiJetCombinations");
  TH1F* h_dy = DiTauDiJetReconstructableMass;
  f_wj->cd("NDiJetCombinations");
  TH1F* h_wj = DiTauDiJetReconstructableMass;
  f_tt->cd("NDiJetCombinations");
  TH1F* h_tt = DiTauDiJetReconstructableMass;
  f_st->cd("NDiJetCombinations");
  TH1F* h_st = DiTauDiJetReconstructableMass;
  f_qcd->cd("NDiJetCombinations");
  TH1F* h_qcd = DiTauDiJetReconstructableMass;


  h_dy->Scale(0.9*0.9*1.01);
  h_tt->Scale(0.9*0.9*0.93);
  h_vv->Scale(0.9*0.9);
  h_wj->Scale(0.9);
  h_st->Scale(0.9);

  cout<<"DY = "<<h_dy->Integral()<<endl;
  cout<<"tt = "<<h_tt->Integral()<<endl;
  cout<<"vv = "<<h_vv->Integral()<<endl;
  cout<<"wj = "<<h_wj->Integral()<<endl;
  cout<<"st = "<<h_st->Integral()<<endl;
  cout<<"data = "<<h_data->Integral()<<endl;

  h_qcd->Add(h_dy, -1);
  h_qcd->Add(h_tt, -1);
  h_qcd->Add(h_vv, -1);
  h_qcd->Add(h_wj, -1);
  h_qcd->Add(h_st, -1);
  //h_qcd->Scale(0.34);
  cout<<"QCD = "<<h_qcd->Integral()<<endl;
  h_qcd->Write(h_qcd->GetName(),TObject::kOverwrite);

}
