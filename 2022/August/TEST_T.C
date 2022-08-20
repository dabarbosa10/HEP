{
   gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

	TFile *SR16Dy = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/DY+Jets_Histogram.root");
	TH1F *DY16 = (TH1F*)SR16Dy->Get("ReconstructedMass");

   TFile *SR16St = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/SingleTop_Histogram.root");
	TH1F *ST16 = (TH1F*)SR16St->Get("ReconstructedMass");

   TFile *SR16Qc = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/QCD_Histogram.root");
	TH1F *QCD16 = (TH1F*)SR16Qc->Get("ReconstructedMass");

   TFile *SR16Vv = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/VV_Histogram.root");
	TH1F *VV16 = (TH1F*)SR16Vv->Get("ReconstructedMass");

   TFile *SR16Wj = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/W+Jets_Histogram.root");
	TH1F *WJ16 = (TH1F*)SR16Wj->Get("ReconstructedMass");

   TFile *SR16Tt = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/tbar{t}_Histogram.root");
	TH1F *TT16 = (TH1F*)SR16Tt->Get("ReconstructedMass");
   


   TFile *SR17Dy = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/DY+Jets_Histogram.root");
	TH1F *DY17 = (TH1F*)SR17Dy->Get("ReconstructedMass");

   TFile *SR17St = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/SingleTop_Histogram.root");
	TH1F *ST17 = (TH1F*)SR17St->Get("ReconstructedMass");

   TFile *SR17Qc = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/QCD_2017.root");
	TH1F *QCD17 = (TH1F*)SR17Qc->Get("ReconstructedMass");

   TFile *SR17Vv = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/VV_Histogram.root");
	TH1F *VV17 = (TH1F*)SR17Vv->Get("ReconstructedMass");

   TFile *SR17Wj = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/W+Jets_Histogram.root");
	TH1F *WJ17 = (TH1F*)SR17Wj->Get("ReconstructedMass");

   TFile *SR17Tt = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/tbar{t}_Histogram.root");
	TH1F *TT17 = (TH1F*)SR17Tt->Get("ReconstructedMass");
   //==============================================================================================================================
   TFile *SR18Dy = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/DY+Jets_Histogram.root");
	TH1F *DY18 = (TH1F*)SR18Dy->Get("ReconstructedMass");

   TFile *SR18St = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/SingleTop_Histogram.root");
	TH1F *ST18 = (TH1F*)SR18St->Get("ReconstructedMass");

   TFile *SR18Qc = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/QCD_2018.root");
	TH1F *QCD18 = (TH1F*)SR18Qc->Get("ReconstructedMass");

   TFile *SR18Vv = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/VV_Histogram.root");
	TH1F *VV18 = (TH1F*)SR18Vv->Get("ReconstructedMass");

   TFile *SR18Wj = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/W+Jets_Histogram.root");
	TH1F *WJ18 = (TH1F*)SR18Wj->Get("ReconstructedMass");

   TFile *SR18Tt = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/tbar{t}_Histogram.root");
	TH1F *TT18 = (TH1F*)SR18Tt->Get("ReconstructedMass");

  TFile *S_16_500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/Zp500_glh1p0_Histogram.root");
  TFile *S_16_2500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2016/Zp2500_glh1p0_Histogram.root");
  TH1F *sig16_1 = (TH1F*)S_16_500->Get("ReconstructedMass");
  TH1F *sig16_2 = (TH1F*)S_16_2500->Get("ReconstructedMass");

  TFile *S_17_500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/Zp500_glh1p0_Histogram.root");
  TFile *S_17_2500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2017/Zp2500_glh1p0_Histogram.root");
  TH1F *sig17_1 = (TH1F*)S_17_500->Get("ReconstructedMass");
  TH1F *sig17_2 = (TH1F*)S_17_2500->Get("ReconstructedMass");

  TFile *S_18_500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/Zp500_glh1p0_Histogram.root");
  TFile *S_18_2500  = new TFile("/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/tautau/2018/Zp2500_glh1p0_Histogram.root");
  TH1F *sig18_1 = (TH1F*)S_18_500->Get("ReconstructedMass");
  TH1F *sig18_2 = (TH1F*)S_18_2500->Get("ReconstructedMass");
  
  TH1F *sig116= (TH1F*)sig16_1->Clone("sig116");
  sig116->Add(sig17_1);
  sig116->Add(sig18_1);
  sig116->Scale(0.0327);
   std::cout<<sig16_1->Integral()<<std::endl;
   std::cout<<sig17_1->Integral()<<std::endl;
   std::cout<<sig18_1->Integral()<<std::endl;
   std::cout<<"Sig:"<<sig116->Integral()<<std::endl;
  
  TH1F *sig216= (TH1F*)sig16_2->Clone("sig216");
  sig216->Add(sig17_2);
  sig216->Add(sig18_2);
  sig216->Scale(0.0428697);



   TH1F *h_dy= (TH1F*)DY16->Clone("h_dy");
   h_dy->Add(DY17);
   h_dy->Add(DY18);
   h_dy->SetLineColor(1);
   h_dy->SetFillColor(kBlue-8);

   TH1F *h_st= (TH1F*)ST16->Clone("h_st");
   h_st->Add(ST17);
   h_st->Add(ST18);
   h_st->SetLineColor(1);
   h_st->SetFillColor(kCyan-4);

   TH1F *h_qcd= (TH1F*)QCD16->Clone("h_qcd");
   h_qcd->Add(QCD17);
   h_qcd->Add(QCD18);
     h_qcd->SetLineColor(1);
   h_qcd->SetFillColor(kGray+1);
  

   TH1F *h_vv= (TH1F*)VV16->Clone("h_vv");
   h_vv->Add(VV17);
   h_vv->Add(VV18);
   h_vv->SetLineColor(1);
   h_vv->SetFillColor(kCyan+1);

   TH1F *h_wj= (TH1F*)WJ16->Clone("h_wj");
   h_wj->Add(WJ17);
   h_wj->Add(WJ18);
   h_wj->SetLineColor(1);
   h_wj->SetFillColor(kAzure+6);

   TH1F *h_tt= (TH1F*)TT16->Clone("h_tt");
   h_tt->Add(TT17);
   h_tt->Add(TT18);
   h_tt->SetLineColor(1);
   h_tt->SetFillColor(kCyan+2);

   //===========================================================================================
 
   std::cout<<DY16->Integral()<<std::endl;
   std::cout<<DY17->Integral()<<std::endl;
   std::cout<<DY18->Integral()<<std::endl;
   std::cout<<"DY:"<<h_dy->Integral()<<std::endl;

   std::cout<<ST16->Integral()<<std::endl;
   std::cout<<ST17->Integral()<<std::endl;
   std::cout<<ST18->Integral()<<std::endl;
   std::cout<<"ST:"<<h_st->Integral()<<std::endl;

   std::cout<<QCD16->Integral()<<std::endl;
   std::cout<<QCD17->Integral()<<std::endl;
   std::cout<<QCD18->Integral()<<std::endl;
   std::cout<<"QCD:"<<h_qcd->Integral()<<std::endl;

   std::cout<<VV16->Integral()<<std::endl;
   std::cout<<VV17->Integral()<<std::endl;
   std::cout<<VV18->Integral()<<std::endl;
   std::cout<<"VV:"<<h_vv->Integral()<<std::endl;

   std::cout<<WJ16->Integral()<<std::endl;
   std::cout<<WJ17->Integral()<<std::endl;
   std::cout<<WJ18->Integral()<<std::endl;
   std::cout<<"WJ:"<<h_wj->Integral()<<std::endl;

   std::cout<<TT16->Integral()<<std::endl;
   std::cout<<TT17->Integral()<<std::endl;
   std::cout<<TT18->Integral()<<std::endl;
   std::cout<<"TT:"<<h_tt->Integral()<<std::endl;


    THStack *hs_n = new THStack("hs_n","");
    hs_n->Add(h_st);
    hs_n->Add(h_vv);
    hs_n->Add(h_tt);
    hs_n->Add(h_wj);
    hs_n->Add(h_dy);
    hs_n->Add(h_qcd);
    
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
   hs_n->Draw(); 
   hs_n->SetMaximum(10e5);
   hs_n->SetMinimum(0.25);
   //hs_n->GetXaxis()->SetRangeUser(0,2000);
   hs_n->Draw("HIST");
   sig116->Draw("HIST SAME");
   sig216->Draw("HIST SAME");
   //hb_back->Draw("E2same");
   //hb_back->SetLineWidth(1);
   //hb_back->SetFillColor(1);
   //hb_back->SetFillStyle(3002);
  hs_n->GetXaxis()->SetLabelSize(0.035);
  hs_n->GetYaxis()->SetLabelSize(0.04);
  hs_n->GetXaxis()->SetTitleSize(0.05);
  hs_n->GetYaxis()->SetTitleSize(0.05);
  hs_n->GetYaxis()->SetTitleOffset(1.3);
  hs_n->GetXaxis()->SetTitleOffset(1.1);
  hs_n->SetTitle(" ; m_{rec}(#tau, #tau, #Delta p_{T}) [GeV]  ; Events");
          leg1=new TLegend(0.6,0.6,0.93,0.89);
          //leg1->SetHeader("CMS Preliminary","C");
	  leg1->SetBorderSize(0);
          leg1->AddEntry(h_dy,"Drell-Yan","f");
          leg1->AddEntry(h_wj,"W+jets","f");
          leg1->AddEntry(h_tt,"t#bar{t}","f");
          leg1->AddEntry(h_vv,"Diboson","f");
          leg1->AddEntry(h_st,"Single Top","f");
          leg1->AddEntry(h_qcd,"QCD","f");
          leg1->AddEntry(sig116,"M_{Z'(SSM)}=500 GeV","lp");
          leg1->AddEntry(sig216,"M_{Z'(SSM)}=2500 GeV","lp");
          //leg1->AddEntry(hb_back,"Stat. Uncert.","fp");
          leg1->Draw();

    TPaveText *pt = new TPaveText(0.11,0.92,0.99,0.99,"NBNDC");
      pt->AddText("CMS Preliminary                 137.1 fb^{-1} (13 TeV)");
      pt->SetTextFont(42);
      pt->SetTextAlign(32);
      pt->SetFillStyle(0);
      pt->SetBorderSize(0);
      pt->Draw();                                                                                             
   /* TPaveText *pt2 = new TPaveText(0.39,0.83,0.51,0.9,"NBNDC");
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
      pt3->Draw(); */




}
