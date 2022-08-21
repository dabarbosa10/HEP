{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  
///////////// Signal Region ////////////////////////////

   	TFile *SR0 = new TFile("QCD_2017.root");
		TH1F *qcd = (TH1F*)SR0->Get("ReconstructedMass");
			qcd->SetLineColor(1);
			qcd->SetFillColor(kMagenta-10);

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
  std::cout<<"D_qcd: "<<qcd->GetNbinsX() <<" C_qcd: " <<qcd->GetNbinsX()<< std::endl; 
  std::cout<<"W+Jets: "<<WJ->GetBinWidth(1) <<" DY: " <<DY->GetBinWidth(1)<< std::endl; 
  std::cout<<"D_qcd: "<<qcd->GetBinWidth(1) <<" C_qcd: " <<qcd->GetBinWidth(1)<< std::endl; 


//////////////////////////7/// REBINING //////////////////////////////


Double_t xbins[8] = {0,100, 300, 500, 700, 900, 1500, 4000};
//Double_t xbins[8] = {0,100, 300, 500, 700, 900, 1500, 4000};
	
	Int_t n = 7;

  /*TFile *S_0  = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/gl1_gh1_ZPrime_M500_2016.root");
  TFile *S_1  = new TFile("/Users/diegobarbosa/Desktop/Limits/FinalSRegions/2016/gl1_gh1_ZPrime_M2500_2016.root");
  TH1F *sig1 = (TH1F*)S_0->Get("ReconstructedMass");
  TH1F *sig2 = (TH1F*)S_1->Get("ReconstructedMass");

   TH1F *SIG1 =(TH1F*)sig1->Rebin (n, "ReconstructedMass", xbins);
  TH1F *SIG2 =(TH1F*)sig2->Rebin (n, "ReconstructedMass", xbins);*/

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






//////////////// Rescalamientos (calcular QCD tomando la forma de CR-C y el Ratio Iso/Anti Iso) (aplicar el factor de escala de tt, dy & wj) ///////////////////////////////////////////////

 // sc=0.0139*172.5*1.3;
 //  SIG1->Scale(sc);
 //  SIG2->Scale(0.0022);
 //	c_qcd->Scale((b_qcd->Integral()/d_qcd->Integral())*0.98);
	
 /*	TH1F *qcd = (TH1F*)c_qcd->Clone("ReconstructedMass");
		qcd->SetLineColor(1);
		qcd->SetFillColor(kMagenta-10);



	tt->Scale(0.90); // (2016 - 1.05) (2017 - 0.84)(2018 - 0.85)
	dy->Scale(1.02); // (2016 - 1.02) (2017 - 0.91)(2018 - 0.81) 2017 y 2018 usamos resultados de Jorge.
	wj->Scale(1.02); // (2016 - 1.02) (2017 - 1.05)(2018 - 0.92) */
	


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
    //  SIG1->Draw("HIST SAME");
    //  SIG2->Draw("HIST SAME");


	
	TLegend *leg1 = new TLegend(0.6,0.6,0.93,0.89);
		leg1->SetBorderSize(0);
		leg1->AddEntry(dy, "DY+Jets","f");
		leg1->AddEntry(wj, "W+Jets","f");
		leg1->AddEntry(tt, "ttbar","f");
		leg1->AddEntry(vv, "Diboson","f");
		leg1->AddEntry(qcd, "QCD","f");
		leg1->AddEntry(st, "Single Top","f");
		leg1->AddEntry(back,"Stat. Uncert","fp");
    //  leg1->AddEntry(SIG1,"M_{Z'}=500 GeV","lp");
    //  leg1->AddEntry(SIG2,"M_{Z'}=2500 GeV","lp");
		leg1->Draw();



	TPaveText *pt = new TPaveText(0.11,0.94,0.99,0.99,"NBNDC");
		pt->AddText("Signal Region                                 41.5fb^{-1} (13 TeV, 2017)"); // 35.9 (2016), 41.5 (2017) and /59.7 (2018)
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


	
	c1->SaveAs("SR17.pdf"); 

  /* TFile f1("QCD_16.root", "RECREATE");
   f1.mkdir("NDiJetCombinations");
   //f1.mkdir("mysubdir2");
   //f1.cd("/");
   //wj->Write();
   f1.cd("/NDiJetCombinations");
   qcd->Write();
   //f1.cd("/mysubdir2");
   //dy->Write();
	f1.Close(); */
   

   wj->SaveAs("W+Jets_2017.root");
   dy->SaveAs("DY+Jets_2017.root");
   st->SaveAs("SingleTop_2017.root");
   tt->SaveAs("ttbar_2017.root");
   vv->SaveAs("VV_2017.root");
   //qcd->SaveAs("QCD_2016.root");
   
	std::cout<<"Hola Die"<< std::endl;

}
