{ 
TFile *f_qcd1  = new TFile ("FakeTau2018_OS.root");
TFile *f_qcd2  = new TFile ("FakeTau2018_LS.root");
f_qcd1->cd("NElectron1Tau1Combinations");
TH1D* h_qcd1 =  Tau1Pt;
f_qcd2->cd("NElectron1Tau1Combinations");
TH1D* h_qcd2 =  Tau1Pt;
double xbins[5] = {0,25,50,75,200};
//double xbins[4]={0,50,100,200};
TH1D *h_qcd1n=(TH1D*)h_qcd1->Rebin(5,"h_qcd1",xbins); 
//double xbins[6] = {50,100,150,200,500,1400};
//h_qcd1->Rebin(5,"h_qcd1",xbins);                                         
//h_qcd1n->Draw();
//h_qcd1->SetAxisRange(0.,100.,"X");                
//h_qcd1->Scale(1/h_qcd1->Integral());
TH1D *h_qcd2n=(TH1D*)h_qcd2->Rebin(5,"h_qcd2",xbins); 

//h_qcd2->Add(h_qcd1,1);
//h_qcd2->Draw();
//h_qcd2->Rebin(5,"h_qcd2",xbins); 
//h_qcd2->Draw();
//h_qcd2->SetAxisRange(0.,100.,"X");                
//h_qcd2->Scale(1/h_qcd2->Integral());

TGraphAsymmErrors* gr = new TGraphAsymmErrors();
gr->Divide( h_qcd1n, h_qcd2n,"pois");
gr->Draw();
c1->SetGrid();
gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);
gr->GetXaxis()->SetTitle("P_{T}(#tau)[GeV] ");
gr->GetYaxis()->SetTitle("OS/LS ");
}

