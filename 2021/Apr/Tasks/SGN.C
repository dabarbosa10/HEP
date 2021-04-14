{
   auto c1 = new TCanvas("c1","c1",600,500);
   gStyle->SetOptStat(0);
   TFile *f  = new TFile("Zprime_NonUniversalSSM_M1000_gl1p0_gh1p0.root");
   TFile *f1=  new TFile("Zprime_NonUniversalSSM_M4000_gl1p0_gh1p0.root");
   TFile *f2  = new TFile("Zprime_NonUniversalSSM_M1250_gl1p0_gh1p0.root");
   TFile *f3  = new TFile("Zprime_NonUniversalSSM_M1750_gl1p0_gh1p0.root");
   TFile *f4=  new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0.root");
   TFile *f5  = new TFile("Zprime_NonUniversalSSM_M2250_gl1p0_gh1p0.root");

   

   TH1F*hTPt=(TH1F*)f->Get("NRecoVertex/Tau1Pt");
   TH1F*hTPt1=(TH1F*)f1->Get("NRecoVertex/Tau1Pt");
   TH1F*hTPt2=(TH1F*)f2->Get("NRecoVertex/Tau1Pt");
   TH1F*hTPt3=(TH1F*)f3->Get("NRecoVertex/Tau1Pt");
   TH1F*hTPt4=(TH1F*)f4->Get("NRecoVertex/Tau1Pt");
   TH1F*hTPt5=(TH1F*)f5->Get("NRecoVertex/Tau1Pt");
	
   Double_t factor = 1.;

   	

   Double_t scale1 = 1/hTPt1->Integral();
   hTPt1->Scale(scale1);
   hTPt1->SetLineWidth(1);
   hTPt1->SetLineColor(kGreen);
   hTPt1->Draw();

   Double_t scale2 = 1/hTPt->Integral();
   hTPt->Scale(scale2);
   hTPt->SetFillColor(kRed);
   hTPt->SetLineColor(kRed);	
   hTPt->Draw("SAME");


   Double_t scale3 = 1/hTPt2->Integral();
   hTPt2->Scale(scale3);
   hTPt2->SetFillColor(kMagenta);
   hTPt2->SetLineColor(kMagenta);	
   hTPt2->Draw("SAME");


   Double_t scale4 = 1/hTPt3->Integral();
   hTPt3->Scale(scale4);
   hTPt3->SetFillColor(kBlue);
   hTPt3->SetLineColor(kBlue);
   hTPt3->Draw("SAME");


   Double_t scale = 1/hTPt4->Integral();
   hTPt4->Scale(scale);
   hTPt4->SetFillColor(kViolet);
   hTPt4->SetLineColor(kViolet);	
   hTPt4->Draw("SAME");

	
   Double_t scale5 = 1/hTPt5->Integral();
   hTPt5->Scale(scale5); 
   hTPt5->SetFillColor(kOrange);
   hTPt5->SetLineColor(kOrange);	
   hTPt5->Draw("SAME");

   hTPt1->SetTitle(" ;  P_{T}(#tau); a.u");
 
   // gPad-­>SetLogy(1);
   auto legend = new TLegend(0.2,0.7,0.48,0.9);
   legend->SetHeader("gl=gh=1","C"); // option "C" allows to center the header
   legend->AddEntry(hTPt,"1000GeV","l");
   legend->AddEntry(hTPt1,"4000GeV","l");
   legend->AddEntry(hTPt2,"1250GeV","l");
   legend->AddEntry(hTPt3,"1750GeV","l");
   legend->AddEntry(hTPt4,"2000GeV","l");
   legend->AddEntry(hTPt5,"2250GeV","l");

   //legend->AddEntry("gr","Graph with error bars","lep");
   legend->Draw();






}