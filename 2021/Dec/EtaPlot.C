{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);

   TFile *f0  = new TFile("/Users/diegobarbosa/Documents/signalseta2_1/Zprime_M2000_gl1p0_gh1p0.root");
   TFile *f1  = new TFile("/Users/diegobarbosa/Documents/signalseta2_4/Zprime_M2000_gl1p0_gh1p0.root");

   Double_t factor = 1.;

   TH1F*hTPt0=(TH1F*)f0->Get("NDiJetCombinations/Tau1Eta");
   //hTPt0->Rebin(0.2);
   Double_t scale0 = 1/hTPt0->Integral();
   hTPt0->Scale(scale0);
   hTPt0->SetLineWidth(3);
   hTPt0->SetLineColor(kBlue);
   
   TH1F*hTPt1=(TH1F*)f1->Get("NDiJetCombinations/Tau1Eta");
   //hTPt1->Rebin(0.2);
   Double_t scale1 = 1/hTPt1->Integral();
   hTPt1->Scale(scale1);
   hTPt1->SetLineWidth(3);
   hTPt1->SetLineColor(kRed);

   TCanvas *c0=new TCanvas("c0","rm_nn",500,500);
  //c0->Divide(2,1);

   c0->cd();
        gPad->SetLogy();
        gPad->SetTickx();
        gPad->SetTicky();
    	gPad->SetLeftMargin(0.13);
    	gPad->SetRightMargin(0.05);
    	gPad->SetBottomMargin(0.12);
    	gPad->SetTopMargin(0.08);
    hTPt0->Draw("HIST");
    hTPt1->Draw("HIST SAME ");

// hTPt0->SetMaximum(1);
 // hTPt0->SetMinimum(10e-5);
  // hTPt0->GetXaxis()->SetRangeUser(50,150);
   //hs_n->Draw("HIST");
   //hb_back->Draw("E2same");
   //hb_back->SetLineWidth(1);
   //hb_back->SetFillColor(1);
   //hb_back->SetFillStyle(3002);
  hTPt0->GetXaxis()->SetLabelSize(0.035);
  hTPt0->GetYaxis()->SetLabelSize(0.04);
  hTPt0->GetXaxis()->SetTitleSize(0.05);
  hTPt0->GetYaxis()->SetTitleSize(0.05);
  hTPt0->GetYaxis()->SetTitleOffset(1.3);
  hTPt0->GetXaxis()->SetTitleOffset(1.1);
  hTPt0->SetTitle("(2016) ; #eta(#tau)  ; Events");
          leg1=new TLegend(0.6,0.6,0.93,0.89);
          //leg1->SetHeader("CMS Preliminary","C");
	  leg1->SetBorderSize(0);
		   leg1->SetHeader("gl=gh=1, 2000 GeV","C");
          leg1->AddEntry(hTPt0,"#eta(#tau)=2.1","l");
          leg1->AddEntry(hTPt1,"#eta(#tau)=2.4","l");
          //leg1->AddEntry(hTPt2,"2750 GeV","l");
          //leg1->AddEntry(hTPt3,"2000 GeV","l");
          //leg1->AddEntry(hTPt4,"3000 GeV","l");
        //  leg1->AddEntry(hTPt5,"4000 GeV","l");
          //leg1->AddEntry(hb_back,"Stat. Uncert.","fp");
          leg1->Draw();

    TPaveText *pt = new TPaveText(0.11,0.92,0.99,0.99,"NBNDC");
      pt->AddText("                       35.9 fb^{-1} (13 TeV, 2016)");
      pt->SetTextFont(38);
      pt->SetTextAlign(32);
      pt->SetFillStyle(0);
      pt->SetBorderSize(0);
      pt->Draw();                                                                                             
    TPaveText *pt2 = new TPaveText(0.39,0.83,0.51,0.9,"NBNDC");
      pt2->AddText("CMS ");
      pt2->SetTextAlign(12);
      pt2->SetFillStyle(0);
      pt2->SetBorderSize(0);
      pt2->Draw();
    TPaveText *pt3 = new TPaveText(0.38,0.8,0.51,0.86,"NBNDC");
      pt3->AddText("Preliminary");
      pt3->SetTextAlign(12);
      pt3->SetTextFont(52);
      pt3->SetFillStyle(0);
      pt3->SetBorderSize(0);
      pt3->Draw();

c0->SaveAs("EtaTau.eps")




}