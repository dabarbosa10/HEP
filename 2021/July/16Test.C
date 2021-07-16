{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  	TFile *f00  = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/Data.root");
	TH1F *B_data = (TH1F*)f00->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	B_data->SetLineWidth(1);
	B_data->SetMarkerStyle(20);
	B_data->SetLineColor(1);

  	TFile *C0 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/Data.root");
	TH1F *C_data = (TH1F*)C0->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	C_data->SetLineWidth(1);
	C_data->SetMarkerStyle(20);
	C_data->SetLineColor(1);

   TFile *D0 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/Data.root");
   TH1F *D_data = (TH1F*)D0->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	D_data->SetLineWidth(1);
	D_data->SetMarkerStyle(20);
	D_data->SetLineColor(1);

   TFile *B1 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/DY+Jets.root");
	TH1F *B_dy = (TH1F*)B1->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	

	TFile *C1 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/DY+Jets.root");
	TH1F *C_dy = (TH1F*)C1->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");


	TFile *D1 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/DY+Jets.root");
	TH1F *D_dy = (TH1F*)D1->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

   TFile *B2 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/SingleTop.root");
	TH1F *B_st = (TH1F*)B2->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	
	TFile *C2 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/SingleTop.root");
	TH1F *C_st = (TH1F*)C2->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

	TFile *D2 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/SingleTop.root");
	TH1F *D_st = (TH1F*)D2->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");




	TFile *B3 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/tbar{t}.root");
	TH1F *B_tt = (TH1F*)B3->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	
	TFile *C3 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/tbar{t}.root");
	TH1F *C_tt = (TH1F*)C3->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

	TFile *D3 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/tbar{t}.root");
	TH1F *D_tt = (TH1F*)D3->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");




	TFile *B4 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/VV.root");
	TH1F *B_vv = (TH1F*)B4->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

	TFile *C4 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/VV.root");
	TH1F *C_vv = (TH1F*)C4->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

	TFile *D4 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/VV.root");
	TH1F *D_vv = (TH1F*)D4->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

  	TFile *B5 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/B/W+Jets.root");
	TH1F *B_wj = (TH1F*)B5->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");
	
	TFile *C5 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/C/W+Jets.root");
	TH1F *C_wj = (TH1F*)C5->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

	TFile *D5 = new TFile("/Users/diegobarbosa/Desktop/DYStudies/QCDNICOLAS/2016/D/W+Jets.root");
	TH1F *D_wj = (TH1F*)D5->Get("NDiJetCombinations/DiTauReconstructableMassDeltaPt");

   TH1F *B_qcd = (TH1F*)B_data->Clone("B_qcd");
		B_qcd->Add(B_dy,-1);
		B_qcd->Add(B_st,-1);
		B_qcd->Add(B_tt,-1);
		B_qcd->Add(B_vv,-1);
		B_qcd->Add(B_wj,-1);
		B_qcd->Sumw2();
   

	TH1F *C_qcd = (TH1F*)C_data->Clone("C_qcd");
		C_qcd->Add(C_dy,-1);
		C_qcd->Add(C_st,-1);
		C_qcd->Add(C_tt,-1);
		C_qcd->Add(C_vv,-1);
		C_qcd->Add(C_wj,-1);
		C_qcd->Sumw2();


	TH1F *D_qcd = (TH1F*)D_data->Clone("D_qcd");
		D_qcd->Add(D_dy,-1);
		D_qcd->Add(D_st,-1);
		D_qcd->Add(D_tt,-1);
		D_qcd->Add(D_vv,-1);
		D_qcd->Add(D_wj,-1);
		D_qcd->Sumw2();
 
  std::cout<< "B: "<<B_qcd-> Integral() << " C: " << C_qcd-> Integral() << "D: " << D_qcd->Integral() << std::endl ;

  Double_t xbins[8] = {0,100, 300, 500, 700, 900, 1500, 4000};
	
	Int_t n = 7;
   TH1F *b_qcd = (TH1F*)B_qcd->Rebin (7, "b_qcd", xbins);
		b_qcd->Sumw2();

   TH1F *c_qcd = (TH1F*)C_qcd->Rebin (7, "c_qcd", xbins);
		c_qcd->Sumw2();

   TH1F *d_qcd = (TH1F*)D_qcd->Rebin (7, "d_qcd", xbins);
		d_qcd->Sumw2();

   c_qcd->Scale(b_qcd->Integral()/d_qcd->Integral());
	
	TH1F *qcd = (TH1F*)c_qcd->Clone("ReconstructedMass");

   std::cout<<"Final "<<c_qcd->Integral()<<std::endl;
    
   qcd->SaveAs("QCD_2016.root");

}