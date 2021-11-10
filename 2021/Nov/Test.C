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
			WJ->SetLineColor(1);
			WJ->SetFillColor(kAzure+6);	


  std::cout<<"W+Jets: "<<WJ->GetNbinsX() <<" DY: " <<DY->GetNbinsX()<< std::endl; 
  std::cout<<"D_qcd: "<<D_qcd->GetNbinsX() <<" C_qcd: " <<C_qcd->GetNbinsX()<< std::endl; 
  std::cout<<"W+Jets: "<<WJ->GetBinWidth(1) <<" DY: " <<DY->GetBinWidth(1)<< std::endl; 
  std::cout<<"D_qcd: "<<D_qcd->GetBinWidth(1) <<" C_qcd: " <<C_qcd->GetBinWidth(1)<< std::endl; 


//////////////////////////7/// REBINING //////////////////////////////
/*Double_t xbins1[501];
Int_t m=500;
int p1=0;
for(int l=0;l<=5000;l+=10)
{
xbins1[p1]=l;
//cout<<"l= "<<l<< " array:" << p1 << endl;
p1+=1;
}

for(int k1=0;k1<=500; k1+=1){
cout<<xbins1[k1]<<endl;
}


//cout<<xbins[4]<< " " << xbins1[4]<< endl;	
	Int_t n = 7;

	TH1F *wj = (TH1F*)WJ->Rebin (m, "wj", xbins1);
		wj->Sumw2();

	TH1F *dy = (TH1F*)DY->Rebin (m, "dy", xbins1);
		dy->Sumw2();

	TH1F *tt = (TH1F*)TT->Rebin (m, "tt", xbins1);
		tt->Sumw2();

	TH1F *st = (TH1F*)ST->Rebin (m, "st", xbins1);
		st->Sumw2();

	TH1F *vv = (TH1F*)VV->Rebin (m, "st", xbins1);
		vv->Sumw2();


	TH1F *b_data = (TH1F*)B_data->Rebin (500, "b_data", xbins1);
		b_data->Sumw2();

	TH1F *b_qcd = (TH1F*)B_qcd->Rebin (500, "b_qcd", xbins1);
		b_qcd->Sumw2();

	TH1F *b_dy = (TH1F*)B_dy->Rebin (500, "b_dy", xbins1);
		b_dy->Sumw2();

	TH1F *b_st = (TH1F*)B_st->Rebin (500, "b_st", xbins1);
		b_st->Sumw2();

	TH1F *b_tt = (TH1F*)B_tt->Rebin (500, "b_tt", xbins1);
		b_tt->Sumw2();

	TH1F *b_vv = (TH1F*)B_vv->Rebin (500, "b_vv", xbins1);
		b_vv->Sumw2();

	TH1F *b_wj = (TH1F*)B_wj->Rebin (500, "b_wj", xbins1);
		b_wj->Sumw2();





	TH1F *c_data = (TH1F*)C_data->Rebin (500, "c_data", xbins1);
		c_data->Sumw2();

	TH1F *c_qcd = (TH1F*)C_qcd->Rebin (500, "c_qcd", xbins1);
		c_qcd->Sumw2();

	TH1F *c_dy = (TH1F*)C_dy->Rebin (500, "c_dy", xbins1);
		c_dy->Sumw2();

	TH1F *c_st = (TH1F*)C_st->Rebin (500, "c_st", xbins1);
		c_st->Sumw2();

	TH1F *c_tt = (TH1F*)C_tt->Rebin (500, "c_tt", xbins1);
		c_tt->Sumw2();

	TH1F *c_vv = (TH1F*)C_vv->Rebin (500, "c_vv", xbins1);
		c_vv->Sumw2();

	TH1F *c_wj = (TH1F*)C_wj->Rebin (500, "c_wj", xbins1);
		c_wj->Sumw2();




	TH1F *d_data = (TH1F*)D_data->Rebin (500, "d_data", xbins1);
		d_data->Sumw2();

	TH1F *d_qcd = (TH1F*)D_qcd->Rebin (500, "d_qcd", xbins1);
		d_qcd->Sumw2();

	TH1F *d_dy = (TH1F*)D_dy->Rebin (500, "d_dy", xbins1);
		d_dy->Sumw2();

	TH1F *d_st = (TH1F*)D_st->Rebin (500, "d_st", xbins1);
		d_st->Sumw2();

	TH1F *d_tt = (TH1F*)D_tt->Rebin (500, "d_tt", xbins1);
		d_tt->Sumw2();

	TH1F *d_vv = (TH1F*)D_vv->Rebin (500, "d_vv", xbins1);
		d_vv->Sumw2();

	TH1F *d_wj = (TH1F*)D_wj->Rebin (500, "d_wj", xbins1);
		d_wj->Sumw2();*/

Double_t xbins[8] = {0,100, 300, 500, 700, 900, 1500, 4000};

//cout<<xbins[4]<< " " << xbins1[4]<< endl;	
	Int_t n = 7;

	TH1F *wj = (TH1F*)WJ->Rebin (n, "ReconstructedMass", xbins);
		wj->Sumw2();

	TH1F *dy = (TH1F*)DY->Rebin (n, "ReconstructedMass", xbins);
		dy->Sumw2();

	TH1F *tt = (TH1F*)TT->Rebin (n, "ReconstructedMass", xbins);
		tt->Sumw2();

	TH1F *st = (TH1F*)ST->Rebin (n, "ReconstructedMass", xbins);
		st->Sumw2();

	TH1F *vv = (TH1F*)VV->Rebin (n, "ReconstructedMass", xbins);
		vv->Sumw2();


	TH1F *b_data = (TH1F*)B_data->Rebin (n, "b_data", xbins);
		b_data->Sumw2();

	TH1F *b_qcd = (TH1F*)B_qcd->Rebin (n, "b_qcd", xbins);
		b_qcd->Sumw2();

	TH1F *b_dy = (TH1F*)B_dy->Rebin (n, "b_dy", xbins);
		b_dy->Sumw2();

	TH1F *b_st = (TH1F*)B_st->Rebin (n, "b_st", xbins);
		b_st->Sumw2();

	TH1F *b_tt = (TH1F*)B_tt->Rebin (n, "b_tt", xbins);
		b_tt->Sumw2();

	TH1F *b_vv = (TH1F*)B_vv->Rebin (n, "b_vv", xbins);
		b_vv->Sumw2();

	TH1F *b_wj = (TH1F*)B_wj->Rebin (n, "b_wj", xbins);
		b_wj->Sumw2();





	TH1F *c_data = (TH1F*)C_data->Rebin (n, "c_data", xbins);
		c_data->Sumw2();

	TH1F *c_qcd = (TH1F*)C_qcd->Rebin (n, "c_qcd", xbins);
		c_qcd->Sumw2();

	TH1F *c_dy = (TH1F*)C_dy->Rebin (n, "c_dy", xbins);
		c_dy->Sumw2();

	TH1F *c_st = (TH1F*)C_st->Rebin (n, "c_st", xbins);
		c_st->Sumw2();

	TH1F *c_tt = (TH1F*)C_tt->Rebin (n, "c_tt", xbins);
		c_tt->Sumw2();

	TH1F *c_vv = (TH1F*)C_vv->Rebin (n, "c_vv", xbins);
		c_vv->Sumw2();

	TH1F *c_wj = (TH1F*)C_wj->Rebin (n, "c_wj", xbins);
		c_wj->Sumw2();




	TH1F *d_data = (TH1F*)D_data->Rebin (n, "d_data", xbins);
		d_data->Sumw2();

	TH1F *d_qcd = (TH1F*)D_qcd->Rebin (n, "d_qcd", xbins);
		d_qcd->Sumw2();

	TH1F *d_dy = (TH1F*)D_dy->Rebin (n, "d_dy", xbins);
		d_dy->Sumw2();

	TH1F *d_st = (TH1F*)D_st->Rebin (n, "d_st", xbins);
		d_st->Sumw2();

	TH1F *d_tt = (TH1F*)D_tt->Rebin (n, "d_tt", xbins);
		d_tt->Sumw2();

	TH1F *d_vv = (TH1F*)D_vv->Rebin (n, "d_vv", xbins);
		d_vv->Sumw2();

	TH1F *d_wj = (TH1F*)D_wj->Rebin (n, "d_wj", xbins);
		d_wj->Sumw2();





//////////////// Rescalamientos (calcular QCD tomando la forma de CR-C y el Ratio Iso/Anti Iso) (aplicar el factor de escala de tt, dy & wj) ///////////////////////////////////////////////

  // sc=0.0139*172.5*1.3;
  // SIG1->Scale(sc);
   //SIG2->Scale(0.0022);
   //SIG1->Scale(172.5);
   //SIG2->Scale(0.1313);
	c_qcd->Scale((b_qcd->Integral()/d_qcd->Integral())*0.98);
	
	TH1F *qcd = (TH1F*)c_qcd->Clone("Electron1Tau1ReconstructableMassDeltaPt");
		qcd->SetLineColor(1);
		qcd->SetFillColor(kMagenta-10);



	tt->Scale(1.05); // (2016 - 1.05) (2017 - 0.84)(2018 - 0.85)
	dy->Scale(1.02); // (2016 - 1.02) (2017 - 0.91)(2018 - 0.81) 2017 y 2018 usamos resultados de Jorge.
	wj->Scale(1.02); // (2016 - 1.02) (2017 - 1.05)(2018 - 0.92)
	


//////////////////// Agrupar los histogramas////////////////////////////////////////

	


	THStack *h= new THStack("h_D", "");
		h->Add(st);
		h->Add(vv);		
		h->Add(tt);
		h->Add(qcd);
		h->Add(wj);
		h->Add(dy);




	TH1F *back = (TH1F*)dy->Clone("back");
		back->Add(st,1);	
		back->Add(tt,1);	
		back->Add(vv,1);	
		back->Add(wj,1);	
		back->Add(qcd,1);	
		back->Sumw2();
		back->SetFillStyle(3002);
		back->SetLineWidth(1);
		back->SetFillColor(1);




////// obtener la tabla de datos /////////////////////////////


	fstream file;

		file.open("data.txt", ios::out);

		file << "\\begin{table}[h]" << endl;
		file <<  "\\centering" << endl;
		file <<  "\\scalebox{0.6}{" << endl;
		file <<    "\\begin{tabular}{|c|c|c|c|c|c|c|c|}" << endl;
		file <<    "\\hline\\hline" << endl;
		file <<    "Bines [GeV] & DY + Jets & SingleTop & VV & W + Jets & t$\\bar{t}$ & QCD & \\textbf{Total} \\\\" << endl;
		file <<    "\\hline" << endl;

		Double_t f_dy, f_st, f_vv, f_wj, f_tt, f_qcd;

		for(int i=1; i<= qcd->GetNbinsX(); i++){

			Double_t down = qcd->GetBinLowEdge(i);
			Double_t up = qcd->GetBinLowEdge(i+1);
			Double_t a_dy = dy->GetBinContent(i);
			Double_t a_st = st->GetBinContent(i);
			Double_t a_vv = vv->GetBinContent(i);
			Double_t a_wj = wj->GetBinContent(i);
			Double_t a_tt = tt->GetBinContent(i);
			Double_t a_qcd = qcd->GetBinContent(i);

		file << down << "-" << up << "&" << a_dy << "&" << a_st << "&" << a_vv << "&" << a_wj << "&" << a_tt << "&" << a_qcd << "&" << a_dy + a_st + a_vv + a_wj + a_tt + a_qcd << "\\\\" << endl;	
		file << "\\hline" << endl;
		
		f_dy = f_dy + a_dy;
		f_st = f_st + a_st;
		f_vv = f_vv + a_vv;
		f_wj = f_wj + a_wj;
		f_tt = f_tt + a_tt;
		f_qcd = f_qcd + a_qcd;


		}

		f_back = f_dy + f_st + f_vv + f_wj + f_tt + f_qcd;
		
		file << "\\hline" << endl;

		file << "\\textbf{Total}" << "&" << f_dy << "&" << f_st << "&" << f_vv << "&" << f_wj << "&" << f_tt << "&" << f_qcd << "&" << f_back <<"\\\\" << endl;
		file << "\\hline" << endl;
		file <<    "\\end{tabular}}" << endl;
		file << "\\end{table}"  << endl;


		file << endl;
		file << endl;
		file << endl;
		file << endl;
		file << endl;
		file << endl;
	
		file << "\\begin{table}[h]" << endl;
		file <<  "\\centering" << endl;
		file <<  "\\scalebox{0.6}{" << endl;
		file <<    "\\begin{tabular}{|c|c|c|c|c|c|c|c|}" << endl;
		file <<    "\\hline\\hline" << endl;
		file <<     "& DY + Jets & SingleTop & VV & W + Jets & t$\\bar{t}$ & QCD & \\textbf{Total} \\\\" << endl;
		file <<    "\\hline" << endl;
		file << "\\textbf{log.txt} &" << dy->Integral() << "&" <<  st->Integral()  << "&" << vv->Integral()  << "&" << wj->Integral()  << "&" << tt->Integral()  << "&" << qcd->Integral()  << "&" << dy->Integral()+st->Integral()+vv->Integral()+wj->Integral()+tt->Integral()+qcd->Integral() << "\\\\" << endl;
		file << "\\hline" << endl;
		file <<    "\\end{tabular}}" << endl;
		file << "\\end{table}"  << endl;

	file.close();


Double_t nbins = qcd->GetXaxis()->GetNbins();
double edy, ewj, ett, est, evv, eback, edata, enmc, eqc;
double intdy = dy->IntegralAndError(1,nbins,edy);
double intwj = wj->IntegralAndError(1,nbins,ewj);
double inttt = tt->IntegralAndError(1,nbins,ett);
double intst = st->IntegralAndError(1,nbins,est);
double intvv = vv->IntegralAndError(1,nbins,evv);
double intqc = qcd->IntegralAndError(1,nbins,eqc);
double intback = back->IntegralAndError(1,nbins,eback);

cout<<"-----------  beamer table ------------------"<<endl;
cout<<"\\begin{tabular}{lcr}"<<endl;
cout<<"\\hline\\hline"<<endl;
cout<<"Process   & Events          & \\%   \\\\ "<<endl; 
cout<<"\\hline"<<endl;
cout<<"W+jets    & "<<Form("%.1f",intwj)<<"$\\pm$"<<Form("%.1f",ewj)<<" & "<<Form("%.0f",100*intwj/intback)<<"\\% \\\\ "<<endl;
cout<<"Drell-Yan & "<<Form("%.1f",intdy)<<"$\\pm$"<<Form("%.1f",edy)<<" & "<<Form("%.0f",100*intdy/intback)<<"\\% \\\\ "<<endl;
cout<<"ttbar     & "<<Form("%.1f",inttt)<<"$\\pm$"<<Form("%.1f",ett)<<" & "<<Form("%.0f",100*inttt/intback)<<"\\% \\\\ "<<endl;
cout<<"SingleTop & "<<Form("%.1f",intst)<<"$\\pm$"<<Form("%.1f",est)<<" & "<<Form("%.0f",100*intst/intback)<<"\\% \\\\ "<<endl;
cout<<"Diboson   & "<<Form("%.1f",intvv)<<"$\\pm$"<<Form("%.1f",evv)<<" & "<<Form("%.0f",100*intvv/intback)<<"\\% \\\\ "<<endl;    
cout<<"QCD       & "<<Form("%.1f",intqc)<<"$\\pm$"<<Form("%.1f",eqc)<<" & "<<Form("%.0f",100*intqc/intback)<<"\\% \\\\ "<<endl;
cout<<"\\hline"<<endl;
cout<<"TotalBack.& "<<Form("%.1f",intback)<<"$\\pm$"<<Form("%.1f",eback)<<" & "<<Form("%.0f",100*intback/intback)<<"\\% \\\\ "<<endl;
cout<<"\\hline\\hline"<<endl;
cout<<"\\end{tabular}"<<endl;
cout<<"--------------------------------------------"<<endl;

////////////////// Grafica //////////////////////////////7



TCanvas *c0 = new TCanvas("c1","rm_nn",550,500);



  c0->cd();
        gPad->SetLogy();
        gPad->SetTickx();
        gPad->SetTicky();
    	gPad->SetLeftMargin(0.13);
    	gPad->SetRightMargin(0.05);
    	gPad->SetBottomMargin(0.12);
    	gPad->SetTopMargin(0.08);


	h->Draw();
		h->SetTitle(";m_{rec} (e, #tau, #Delta p_{T}) [GeV] ; Events");
	 h->GetXaxis()->SetLabelSize(0.035);
  h->GetYaxis()->SetLabelSize(0.04);
  h->GetXaxis()->SetTitleSize(0.05);
  h->GetYaxis()->SetTitleSize(0.05);
  h->GetYaxis()->SetTitleOffset(1.3);
  h->GetXaxis()->SetTitleOffset(1.1);		
		//h->GetXaxis()->SetLabelSize(0.03);
      h->SetMaximum(10e6);
      h->SetMinimum(0.025);
		h->GetXaxis()->SetRangeUser(100,4000);
		h->Draw("HIST");
		back->Draw("E2 SAME");
     // SIG1->Draw("HIST SAME");
     // SIG2->Draw("HIST SAME");


	
	TLegend *leg1 = new TLegend(0.6,0.6,0.93,0.89);
		leg1->SetBorderSize(0);
		leg1->AddEntry(dy, "DY+Jets","f");
		leg1->AddEntry(wj, "W+Jets","f");
		leg1->AddEntry(tt, "t#bar{t}","f");
		leg1->AddEntry(vv, "Diboson","f");
		leg1->AddEntry(qcd, "QCD","f");
		leg1->AddEntry(st, "Single Top","f");
		leg1->AddEntry(back,"Stat. Uncert","fp");
   //   leg1->AddEntry(SIG1,"M_{Z'}=500 GeV","lp");
   //   leg1->AddEntry(SIG2,"M_{Z'}=2500 GeV","lp");
		leg1->Draw();



	TPaveText *pt = new TPaveText(0.11,0.94,0.99,0.99,"NBNDC");
		pt->AddText("Signal Region                                 35.9fb^{-1} (13 TeV, 2016)"); // 35.9 (2016), 41.5 (2017) and /59.7 (2018)
		pt->SetTextFont(42);
		pt->SetTextAlign(32);
		pt->SetFillStyle(0);
		pt->SetBorderSize(0);
		pt->Draw(); 



    TPaveText *pt2 = new TPaveText(0.19,0.85,0.31,0.92,"NBNDC");
      pt2->AddText("CMS ");
      pt2->SetTextAlign(12);
      pt2->SetFillStyle(0);
      pt2->SetBorderSize(0);
      pt2->Draw();
    TPaveText *pt3 = new TPaveText(0.18,0.82,0.31,0.88,"NBNDC");
      pt3->AddText("Preliminary");
      pt3->SetTextAlign(12);
      pt3->SetTextFont(52);
      pt3->SetFillStyle(0);
      pt3->SetBorderSize(0);
      pt3->Draw();


	
	c1->SaveAs("SR16.eps"); 

   TFile f1("QCD_16.root", "RECREATE");
   f1.mkdir("NDiJetCombinations");
   //f1.mkdir("mysubdir2");
   //f1.cd("/");
   //wj->Write();
   f1.cd("/NDiJetCombinations");
   qcd->Write();
   //f1.cd("/mysubdir2");
   //dy->Write();
	f1.Close();
   

   wj->SaveAs("W+Jets_2016.root");
   dy->SaveAs("DY+Jets_2016.root");
   st->SaveAs("SingleTop_2016.root");
   tt->SaveAs("ttbar_2016.root");
   vv->SaveAs("VV_2016.root");
   qcd->SaveAs("QCD_2016.root");
   
	std::cout<<"Hola Die"<< std::endl;

}
