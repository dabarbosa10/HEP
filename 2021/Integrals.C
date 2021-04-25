{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
/////////////////////////////////////////////////////////////////
  TFile *f0  = new TFile("W+Jets.root");
  TFile *f1  = new TFile("W+Jets.root");
  TFile *f2  = new TFile("DY+Jets.root");
  TFile *f3  = new TFile("ttbar.root");
  TFile *f4  = new TFile("SingleTop.root");
  TFile *f5  = new TFile("VV.root");
  TFile *f6 = new TFile("Data.root");
  TFile *f61 = new TFile("Data.root");

  TH1F*h_wj=(TH1F*)f0->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_wj->SetLineColor(1);
  h_wj->SetFillColor(kAzure+6);
  TH1F*h_wj1=(TH1F*)f1->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  TH1F*h_dy=(TH1F*)f2->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_dy->SetLineColor(1);
  h_dy->SetFillColor(kOrange-4);
  TH1F*h_tt=(TH1F*)f3->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_tt->SetLineColor(1);
  h_tt->SetFillColor(kBlue-8);
  TH1F*h_st=(TH1F*)f4->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_st->SetLineColor(1);
  h_st->SetFillColor(8);
  TH1F*h_vv=(TH1F*)f5->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_vv->SetLineColor(1);
  h_vv->SetFillColor(46);
  TH1F*h_data=(TH1F*)f6->Get("NDiJetCombinations/Electron1Tau1ReconstructableMassDeltaPt");
  h_data->SetLineColor(1);
  h_data->SetLineStyle(1);
  h_data->SetMarkerStyle(20);
  h_data->SetLineWidth(1);




Double_t nbins = h_dy->GetXaxis()->GetNbins();
double edy, ewj,ett,est,evv;
double intdy = h_dy->IntegralAndError(1,nbins,edy);
double intwj = h_wj->IntegralAndError(1,nbins,ewj);
double inttt = h_tt->IntegralAndError(1,nbins,ett);
double intst = h_st->IntegralAndError(1,nbins,est);
double intvv = h_vv->IntegralAndError(1,nbins,evv);



cout<<"DY = "<<h_dy->Integral()<< " "<<intdy <<" "<<edy<< endl;
cout<<"tt = "<<h_tt->Integral()<< " "<<inttt <<" "<<ett<<endl;
cout<<"vv = "<<h_vv->Integral()<< " "<<intvv <<" "<<evv<<endl;
cout<<"wj = "<<h_wj->Integral()<< " "<<intwj <<" "<<ewj<<endl;
cout<<"st = "<<h_st->Integral()<< " "<<intst <<" "<<est<<endl;
cout<<"data = "<<h_data->Integral()<<endl;
cout<<nbins<<" "<< edy<< " " <<intdy<<endl;

for(int i = 0; i < h_dy->GetXaxis()->GetNbins(); i++) {
    h_dy->SetBinContent(i+1, h_dy->GetBinContent(i+1)/h_dy->GetBinWidth(i+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }

for(int j = 0; j < h_wj->GetXaxis()->GetNbins(); j++) {
    h_wj->SetBinContent(j+1, h_wj->GetBinContent(j+1)/h_wj->GetBinWidth(j+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }

for(int k = 0; k < h_tt->GetXaxis()->GetNbins(); k++) {
    h_tt->SetBinContent(k+1, h_tt->GetBinContent(k+1)/h_tt->GetBinWidth(k+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }

for(int l = 0; l < h_st->GetXaxis()->GetNbins(); l++) {
    h_st->SetBinContent(l+1, h_st->GetBinContent(l+1)/h_st->GetBinWidth(l+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }

for(int m = 0; m < h_vv->GetXaxis()->GetNbins(); m++) {
    h_vv->SetBinContent(m+1, h_vv->GetBinContent(m+1)/h_vv->GetBinWidth(m+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }

for(int n = 0; n < h_data->GetXaxis()->GetNbins(); n++) {
    h_data->SetBinContent(n+1, h_data->GetBinContent(n+1)/h_data->GetBinWidth(n+1));
    //d_s->SetBinError(i+1, data->GetBinError(i+1)/data->GetBinWidth(i+1));
  }



   h_wj->Rebin(1);
    h_dy->Rebin(1);
    h_tt->Rebin(1);
    h_st->Rebin(1);
    h_vv->Rebin(1);
    h_data->Rebin(1);
    //h_back->Rebin(1);
    //h_ratio->Rebin(1);

  THStack *hs_n = new THStack("hs_n","");
    hs_n->Add(h_st);
    hs_n->Add(h_vv);
    hs_n->Add(h_tt);
    hs_n->Add(h_wj);
    hs_n->Add(h_dy);

TCanvas *c0=new TCanvas("c0","rm_nn",500,500);
  //c0->Divide(2,1);

    c0->cd(1);
TPad *pad1 = new TPad("pad1", "pad1", 0, 0, 1, 1);
  pad1->SetBottomMargin(0.3); // Upper and lower plot are joined
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
        //gPad->SetLogy();
        gPad->SetTickx();
        gPad->SetTicky();
    	gPad->SetLeftMargin(0.15);
    	gPad->SetRightMargin(0.05);
    	//gPad->SetBottomMargin(0.15);
    	gPad->SetTopMargin(0.06);
  hs_n->Draw(); 
   hs_n->SetMaximum(300);
   //hs_n->SetMinimum(0.0);
   hs_n->GetXaxis()->SetRangeUser(70,110);
   hs_n->Draw("HIST");
   h_data->Draw("same");
   //h_back->Draw("E2same");
   //h_back->SetLineWidth(1);
   //h_back->SetFillColor(1);
   //h_back->SetFillStyle(3002);
   hs_n->SetTitle(" ;  ; Events/GeV");
   hs_n->GetYaxis()->SetTitleSize(0.04);
   //hs_n->SetTitle("CMS Preliminary                 35.9 fb^{-1} (13 TeV, 2016) ;  ; Events");
          leg1=new TLegend(0.67,0.63,0.93,0.91);
          //leg1->SetHeader("CMS Preliminary","C");
	  leg1->SetBorderSize(0);
          leg1->AddEntry(h_data,"Data","lp");
          leg1->AddEntry(h_dy,"Drell-Yan","fp");
          leg1->AddEntry(h_wj,"W+jets","fp");
          leg1->AddEntry(h_tt,"t#bar{t}","fp");
          leg1->AddEntry(h_vv,"Diboson","fp");
          //leg1->AddEntry(h_qc,"data-driven QCD","fp");
          leg1->AddEntry(h_st,"Single Top","fp");
          //leg1->AddEntry(h_back,"Stat. Uncert.","fp");
          leg1->Draw();


    TPaveText *pt = new TPaveText(0.11,0.94,0.99,0.99,"NBNDC");
      pt->AddText("Drell-Yan CR                 35.9 fb^{-1} (13 TeV, 2016)");
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

   c0->cd(1);


}
