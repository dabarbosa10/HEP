{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);
 //source  ~/.bash_profile
  //gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);

   TFile *f0  = new TFile("Zprime_NonUniversalSSM_M1250_gl1p0_gh1p0.root");
   TFile *f1  = new TFile("Zprime_NonUniversalSSM_M1500_gl1p0_gh1p0.root");
   TFile *f2  = new TFile("Zprime_NonUniversalSSM_M1750_gl1p0_gh1p0.root");
   TFile *f3 =  new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0.root");
   //TFile *f4  = new TFile("Zprime_NonUniversalSSM_M3500_gl1p0_gh1p0.root");
  // TFile *f5 =  new TFile("Zprime_NonUniversalSSM_M4000_gl1p0_gh1p0.root");

   Double_t factor = 1.;

   TH1F*hTPt0=(TH1F*)f0->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt0->Rebin(10);
   Double_t scale0 = 1/hTPt0->Integral();
   hTPt0->Scale(scale0);
   Double_t x, q;
   q = 0.5; // 0.5 for "median"
   hTPt0->ComputeIntegral(); // just a precaution
   hTPt0->GetQuantiles(1, &x, &q);
   std::cout << "median = " << x << std::endl;
   hTPt0->SetLineWidth(3);
   hTPt0->SetLineColor(kGreen);
   
   TH1F*hTPt1=(TH1F*)f1->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt1->Rebin(10);
   Double_t scale1 = 1/hTPt1->Integral();
   hTPt1->Scale(scale1);
   Double_t x1, q1;
   q1 = 0.5; // 0.5 for "median"
   hTPt1->ComputeIntegral(); // just a precaution
   hTPt1->GetQuantiles(1, &x1, &q1);
   std::cout << "median = " << x1 << std::endl;
   hTPt1->SetLineWidth(3);
   hTPt1->SetLineColor(kRed);
   


   TH1F*hTPt2=(TH1F*)f2->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt2->Rebin(10);
   Double_t scale2 = 1/hTPt2->Integral();
   hTPt2->Scale(scale2);
   Double_t x2, q2;
   q2 = 0.5; // 0.5 for "median"
   hTPt2->ComputeIntegral(); // just a precaution
   hTPt2->GetQuantiles(1, &x2, &q2);
   std::cout << "median = " << x2 << std::endl;
   hTPt2->SetLineWidth(3);
   hTPt2->SetLineColor(kMagenta);
   

	
   TH1F*hTPt3=(TH1F*)f3->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt3->Rebin(10);
   Double_t scale3 = 1/hTPt3->Integral();
   hTPt3->Scale(scale3);
   Double_t x3, q3;
   q3 = 0.5; // 0.5 for "median"
   hTPt3->ComputeIntegral(); // just a precaution
   hTPt3->GetQuantiles(1, &x3, &q3);
   std::cout << "median = " << x3 << std::endl;
   hTPt3->SetLineWidth(3);
   hTPt3->SetLineColor(kBlue);
   
/*

   TH1F*hTPt4=(TH1F*)f4->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt4->Rebin(10);
   Double_t scale4 = 1/hTPt4->Integral();
   hTPt4->Scale(scale4);
   Double_t x4, q4;
   q4 = 0.5; // 0.5 for "median"
   hTPt4->ComputeIntegral(); // just a precaution
   hTPt4->GetQuantiles(1, &x4, &q4);
   std::cout << "median = " << x4 << std::endl;
   hTPt4->SetLineWidth(3);
   hTPt4->SetLineColor(kCyan);
  
   //Tau1Pt

   TH1F*hTPt5=(TH1F*)f5->Get("NRecoVertex/Electron1Tau1ReconstructableMassDeltaPt");
   hTPt5->Rebin(10);
   Double_t scale5 = 1/hTPt5->Integral();
   hTPt5->Scale(scale5);
   Double_t x5, q5;
   q5 = 0.5; // 0.5 for "median"
   hTPt5->ComputeIntegral(); // just a precaution
   hTPt5->GetQuantiles(1, &x5, &q5);
   std::cout << "median = " << x5 << std::endl;
   hTPt5->SetLineWidth(3);
   hTPt5->SetLineColor(kOrange);
*/
   //THStack *hs_n = new THStack("hs_n","");
    //hs_n->Add(hTPt0);
    //hs_n->Add(hTPt1);
    //hs_n->Add(hTPt2);
    //hs_n->Add(hTPt3);
    //hs_n->Add(hTPt4);
    //hs_n->Add(hTPt5); 

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
    hTPt2->Draw("HIST SAME");
    hTPt3->Draw("HIST SAME");
   // hTPt4->Draw("HIST SAME");
   // hTPt5->Draw("HIST SAME");
   //hs_n->Draw(); 
   hTPt0->SetMaximum(1);
   hTPt0->SetMinimum(10e-5);
   hTPt0->GetXaxis()->SetRangeUser(0,6000);
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
  hTPt0->SetTitle("Signal Samples (2017) ; m_{rec}(e, #tau, #Delta p_{T})  ; a.u");
          leg1=new TLegend(0.6,0.6,0.93,0.89);
          //leg1->SetHeader("CMS Preliminary","C");
	  leg1->SetBorderSize(0);
		   leg1->SetHeader("gl=gh=1","C");
          leg1->AddEntry(hTPt0,"250 GeV","l");
          leg1->AddEntry(hTPt1,"500 GeV","l");
          leg1->AddEntry(hTPt2,"750 GeV","l");
          leg1->AddEntry(hTPt3,"1000 GeV","l");
          //leg1->AddEntry(hTPt4,"3500 GeV","l");
          //leg1->AddEntry(hTPt5,"4000 GeV","l");
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

c0->SaveAs("SignalSamplesgl1_recMass17b.eps")
}