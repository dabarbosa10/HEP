{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);
  gStyle->SetOptFit(kTRUE);
/////////////////////////////////////////////////////////////////
 // TFile *f00  = new TFile("/Users/diegobarbosa/Desktop/2017/W+Jets.root");
 // TFile *f01  = new TFile("/Users/diegobarbosa/Desktop/2017/1/W+Jets.root");
  TFile *f02  = new TFile("/Users/diegobarbosa/Desktop/2017/1/DY+JetsLS.root");
  TFile *f03  = new TFile("/Users/diegobarbosa/Desktop/2017/1/ttbarLS.root");
  TFile *f04  = new TFile("/Users/diegobarbosa/Desktop/2017/1/SingleTopLS.root");
  TFile *f06  = new TFile("/Users/diegobarbosa/Desktop/2017/1/VVLS.root");
  TFile *f900 = new TFile("/Users/diegobarbosa/Desktop/2017/1/DataLS.root");
  TFile *f901 = new TFile("/Users/diegobarbosa/Desktop/2017/1/DataLS.root");

 // TFile *f90 = new TFile("/home/jfraga/17zprime/csr/W+Jets.root");
 // TFile *f91 = new TFile("/home/jfraga/17zprime/csr/W+Jets.root");
  TFile *f92 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/DY+Jets.root");
  TFile *f93 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/ttbar.root");
  TFile *f94 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/SingleTop.root");
  TFile *f95 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/VV.root");
  TFile *f909 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/Data.root");
  TFile *f902 = new TFile("/Users/diegobarbosa/Desktop/2017/OS/Data.root");
///////////////////////////////////////////////////////////////////
 // TH1F *h_wj;
  TH1F *h_dy;
  TH1F *h_tt;
  TH1F *h_st;
  TH1F *h_vv;
  TH1F *h_data;
  TH1F *h_data9;
  TH1F *h_back;
  TH1F *h_back9;
  TH1F *h_dy9;
  TH1F *h_tt9;
  TH1F *h_st9;
  TH1F *h_vv9;

 // h_wj = (TH1F *)f01->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
  h_dy = (TH1F *)f02->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_tt = (TH1F *)f03->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_st = (TH1F *)f04->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_vv = (TH1F *)f06->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");

 // h_wj9 = (TH1F *)f91->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
  h_dy9 = (TH1F *)f92->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_tt9 = (TH1F *)f93->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_st9 = (TH1F *)f94->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_vv9 = (TH1F *)f95->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");

  h_data9 = (TH1F *)f909->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_back9 = (TH1F *)f909->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_back9->Add(h_dy9);
  h_back9->Add(h_tt9);
  h_back9->Add(h_st9);
  h_back9->Add(h_vv9);
  h_ratio = (TH1F *)f902->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_ratio->Add(h_back9,-1);

  h_data = (TH1F *)f900->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_back = (TH1F *)f900->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_back->Add(h_dy);
  h_back->Add(h_tt);
  h_back->Add(h_st);
  h_back->Add(h_vv);
  h_d = (TH1F *)f901->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_d->Add(h_back,-1);

//Double_t nbins = 12;
Double_t nbins = h_back->GetXaxis()->GetNbins();
TH1F *h_nmc=(TH1F*)h_data->Clone();
h_nmc->SetName("h_nmc");
h_nmc->Add(h_back,-1);
double edy, ett, est, evv, eback, edata, enmc;
double intdy = h_dy->IntegralAndError(1,nbins,edy);
//double intwj = h_wj->IntegralAndError(1,nbins,ewj);
double inttt = h_tt->IntegralAndError(1,nbins,ett);
double intst = h_st->IntegralAndError(1,nbins,est);
double intvv = h_vv->IntegralAndError(1,nbins,evv);
double intback = h_back->IntegralAndError(1,nbins,eback);
double intdat = h_data->IntegralAndError(1,nbins,edata);
double intnmc = h_nmc->IntegralAndError(1,nbins,enmc);
TH1F *h_nmc9=(TH1F*)h_data9->Clone();
h_nmc9->SetName("h_nmc9");
h_nmc9->Add(h_back9,-1);
double edy9, ett9, est9, evv9, eback9, edata9, enmc9;
double intdy9 = h_dy9->IntegralAndError(1,nbins,edy9);
//double intwj9 = h_wj9->IntegralAndError(1,nbins,ewj9);
double inttt9 = h_tt9->IntegralAndError(1,nbins,ett9);
double intst9 = h_st9->IntegralAndError(1,nbins,est9);
double intvv9 = h_vv9->IntegralAndError(1,nbins,evv9);
double intback9 = h_back9->IntegralAndError(1,nbins,eback9);
double intdat9 = h_data9->IntegralAndError(1,nbins,edata9);
double intnmc9 = h_nmc9->IntegralAndError(1,nbins,enmc9);

double sf = intnmc9/intnmc;
double esf = sqrt( pow((enmc9/intnmc),2)
	          +pow((intnmc9*enmc/(intnmc*intnmc)),2));



double xbins[14] = {0,150,300,400,600,1200,1400,1500,1600,1700,1800,1900,1950,2000};
  //  h_wj->Rebin(13,"hb_wj",xbins);
    h_dy->Rebin(13,"hb_dy",xbins);
    h_tt->Rebin(13,"hb_tt",xbins);
    h_st->Rebin(13,"hb_st",xbins);
    h_vv->Rebin(13,"hb_vv",xbins);
    h_data->Rebin(13,"hb_data",xbins);
    h_ratio->Rebin(13,"hb_ratio",xbins);
    h_back->Rebin(13,"hb_back",xbins);
 //   h_wj9->Rebin(13,"hb_wj9",xbins);
    h_dy9->Rebin(13,"hb_dy9",xbins);
    h_tt9->Rebin(13,"hb_tt9",xbins);
    h_st9->Rebin(13,"hb_st9",xbins);
    h_vv9->Rebin(13,"hb_vv9",xbins);
    h_data9->Rebin(13,"hb_data9",xbins);
    h_d->Rebin(13,"hb_d",xbins);
    h_back9->Rebin(13,"hb_back9",xbins);


  TCanvas *c0=new TCanvas("c0","rm_nn",500,400);
   c0->cd(1);

        gPad->SetTickx();
        gPad->SetTicky();
	gPad->SetLeftMargin(0.15);
    	gPad->SetRightMargin(0.04);
        gPad->SetBottomMargin(0.15);
        gPad->SetTopMargin(0.06);

hb_ratio->Sumw2();
hb_ratio->Scale(1.5);
hb_d->Sumw2();
hb_ratio->Divide(hb_d);

TF1 *f1 = new TF1("f1","pol0",0,1200);
hb_ratio->Fit("f1","emr");
cout<<f1->GetParameter(0)<<endl;
gStyle->SetStatX(0.9);
gStyle->SetStatY(0.9);
gStyle->SetFitFormat("4.3g");

hb_ratio->Draw();
hb_ratio->SetMaximum(5);
hb_ratio->SetMinimum(-1);
hb_ratio->SetLineWidth(1);
//hb_ratio->SetFillColor(1);
//hb_ratio->SetLineColor(1);
//hb_ratio->SetMarkerStyle(20);
hb_ratio->GetXaxis()->SetRangeUser(0,1200);
hb_ratio->SetTitle("   ; m_{rec}(e, #tau, #Delta p_{T}) [GeV] ; R_{OS / LS} ");

  hb_ratio->SetMarkerStyle(33);
  hb_ratio->GetXaxis()->SetLabelSize(0.045);
  hb_ratio->GetYaxis()->SetLabelSize(0.045);
  hb_ratio->GetXaxis()->SetTitleSize(0.06);
  hb_ratio->GetYaxis()->SetTitleSize(0.06);
  hb_ratio->GetYaxis()->SetTitleOffset(1.1);
  hb_ratio->GetXaxis()->SetTitleOffset(1.1);

    TPaveText *pt = new TPaveText(0.11,0.94,0.99,0.999,"NBNDC");
      pt->AddText("41.5 fb^{-1} (2017)");
      pt->SetTextFont(47);
      pt->SetTextAlign(32);
      pt->SetFillStyle(0);
      pt->SetBorderSize(0);
      pt->Draw();                                                                                             
  
c0->SaveAs("muTau_ratioCD_2017.pdf");
}
