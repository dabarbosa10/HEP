{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  	TFile *f00  = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/Data.root");
	TH1F *B_data = (TH1F*)f00->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	B_data->SetLineWidth(1);
	B_data->SetMarkerStyle(20);
	B_data->SetLineColor(1);

  	TFile *C0 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/Data.root");
	TH1F *C_data = (TH1F*)C0->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	C_data->SetLineWidth(1);
	C_data->SetMarkerStyle(20);
	C_data->SetLineColor(1);

   TFile *D0 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/Data.root");
   TH1F *D_data = (TH1F*)D0->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	D_data->SetLineWidth(1);
	D_data->SetMarkerStyle(20);
	D_data->SetLineColor(1);

   TFile *B1 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/DY+Jets.root");
	TH1F *B_dy = (TH1F*)B1->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	

	TFile *C1 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/DY+Jets.root");
	TH1F *C_dy = (TH1F*)C1->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");


	TFile *D1 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/DY+Jets.root");
	TH1F *D_dy = (TH1F*)D1->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

   TFile *B2 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/SingleTop.root");
	TH1F *B_st = (TH1F*)B2->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	
	TFile *C2 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/SingleTop.root");
	TH1F *C_st = (TH1F*)C2->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

	TFile *D2 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/SingleTop.root");
	TH1F *D_st = (TH1F*)D2->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");




	TFile *B3 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/ttbar.root");
	TH1F *B_tt = (TH1F*)B3->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	
	TFile *C3 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/ttbar.root");
	TH1F *C_tt = (TH1F*)C3->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

	TFile *D3 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/ttbar.root");
	TH1F *D_tt = (TH1F*)D3->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");




	TFile *B4 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/VV.root");
	TH1F *B_vv = (TH1F*)B4->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

	TFile *C4 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/VV.root");
	TH1F *C_vv = (TH1F*)C4->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

	TFile *D4 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/VV.root");
	TH1F *D_vv = (TH1F*)D4->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

  	TFile *B5 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/2016QCD_CRB/W+Jets.root");
	TH1F *B_wj = (TH1F*)B5->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
	
	TFile *C5 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRC/W+Jets.root");
	TH1F *C_wj = (TH1F*)C5->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

	TFile *D5 = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/QCD2016_CRD/W+Jets.root");
	TH1F *D_wj = (TH1F*)D5->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");

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


///////////// Signal Region ////////////////////////////

	TFile *SR1 = new TFile("DY+Jets.root");
		TH1F *DY = (TH1F*)SR1->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
			DY->SetLineColor(1);
			DY->SetFillColor(kOrange-4);	
	


	TFile *SR2 = new TFile("SingleTop.root");
		TH1F *ST = (TH1F*)SR2->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
			ST->SetLineColor(1);
			ST->SetFillColor(8);	



	TFile *SR3 = new TFile("ttbar.root");
		TH1F *TT = (TH1F*)SR3->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
			TT->SetLineColor(1);
			TT->SetFillColor(kBlue-8);



	TFile *SR4 = new TFile("VV.root");
		TH1F *VV = (TH1F*)SR4->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
			VV->SetLineColor(1);
			VV->SetFillColor(46);


	TFile *SR5 = new TFile("W+Jets.root");
		TH1F *WJ = (TH1F*)SR5->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
        WJ->SetBins(600);
			WJ->SetLineColor(1);
			WJ->SetFillColor(kAzure+6);

    WJ->SaveAs("W+Jets_2016_1.root");
    std::cout<<"W+Jets: "<<WJ->GetNbinsX() <<" DY: " <<DY->GetNbinsX()<< std::endl; 

}

