{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
/////////////////////////////////////////////////////////////////
  TFile *f00  = new TFile("W+Jets.root");
  TFile *f01  = new TFile("W+Jets.root");
  TFile *f02  = new TFile("DY+Jets.root");
  TFile *f03  = new TFile("ttbar.root");
  TFile *f04  = new TFile("SingleTop.root");
  TFile *f06  = new TFile("VV.root");
  TFile *f900 = new TFile("Data.root");
  TFile *f901 = new TFile("Data.root");
///////////////////////////////////////////////////////////////////
  TH1F *h_wj;
  TH1F *h_dy;
  TH1F *h_tt;
  TH1F *h_st;
  TH1F *h_vv;
  TH1F *h_data;
  TH1F *h_ratio;
  TH1F *h_back;

  h_wj = (TH1F *)f01->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    h_wj->SetLineColor(1);
    h_wj->SetFillColor(kAzure+6);
    h_wj->Scale(1);
  h_dy = (TH1F *)f02->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    h_dy->SetLineColor(1);
    h_dy->SetFillColor(kOrange-4);
    h_dy->Scale(1);
  h_tt = (TH1F *)f03->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    h_tt->SetLineColor(1);
    h_tt->SetFillColor(kBlue-8);
    h_tt->Scale(1);
  h_st = (TH1F *)f04->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    h_st->SetLineColor(1);
    h_st->SetFillColor(8);
  h_vv = (TH1F *)f06->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    h_vv->SetLineColor(1);
    h_vv->SetFillColor(46);
  h_ratio = (TH1F *)f901->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
  h_data = (TH1F *)f900->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
    //h_data->Scale(8.9);
    h_data->SetLineColor(1);
    h_data->SetLineStyle(1);
    h_data->SetMarkerStyle(20);
    h_data->SetLineWidth(1);
  h_back = (TH1F *)f00->Get("NDiJetCombinations/Muon1Tau1ReconstructableMassDeltaPt");
  h_back->Add(h_dy);
  h_back->Add(h_tt);
  h_back->Add(h_st);
  h_back->Add(h_vv);

//Double_t nbins = 10;
Double_t nbins = h_back->GetXaxis()->GetNbins();
TH1F *h_nmc=(TH1F*)h_data->Clone();
h_nmc->SetName("h_nmc");
h_nmc->Add(h_back,-1);
h_nmc->Add(h_tt,1);
double edy, ewj, ett, est, evv, eback, edata, enmc;
double intdy = h_dy->IntegralAndError(1,nbins,edy);
double intwj = h_wj->IntegralAndError(1,nbins,ewj);
double inttt = h_tt->IntegralAndError(1,nbins,ett);
double intst = h_st->IntegralAndError(1,nbins,est);
double intvv = h_vv->IntegralAndError(1,nbins,evv);
double intback = h_back->IntegralAndError(1,nbins,eback);
double intdat = h_data->IntegralAndError(1,nbins,edata);
double intnmc = h_nmc->IntegralAndError(1,nbins,enmc);
double sf = intnmc/inttt;
double esf = sqrt( pow((enmc/inttt),2)
	          +pow((intnmc*ett/(inttt*inttt)),2));

cout<<" "<<Form("%.2f",intnmc)<<" "<<endl;
cout<<"-----------  beamer table ------------------"<<endl;
cout<<"\\begin{tabular}{lcr}"<<endl;
cout<<"\\hline\\hline"<<endl;
cout<<"Process   & Events          & \\%   \\\\ "<<endl; 
cout<<"\\hline"<<endl;
cout<<"W+jets    & "<<Form("%.1f",intwj)<<"$\\pm$"<<Form("%.2f",ewj)<<" & "<<Form("%.1f",100*intwj/intdat)<<"\\% \\\\ "<<endl;
cout<<"Drell-Yan & "<<Form("%.1f",intdy)<<"$\\pm$"<<Form("%.2f",edy)<<" & "<<Form("%.1f",100*intdy/intdat)<<"\\% \\\\ "<<endl;
cout<<"ttbar     & "<<Form("%.1f",inttt)<<"$\\pm$"<<Form("%.2f",ett)<<" & "<<Form("%.1f",100*inttt/intdat)<<"\\% \\\\ "<<endl;
cout<<"SingleTop & "<<Form("%.1f",intst)<<"$\\pm$"<<Form("%.2f",est)<<" & "<<Form("%.1f",100*intst/intdat)<<"\\% \\\\ "<<endl;
cout<<"Diboson   & "<<Form("%.1f",intvv)<<"$\\pm$"<<Form("%.2f",evv)<<" & "<<Form("%.1f",100*intvv/intdat)<<"\\% \\\\ "<<endl;    
cout<<"\\hline"<<endl;
cout<<"TotalBack.& "<<Form("%.1f",intback)<<"$\\pm$"<<eback<<" & "<<Form("%.1f",100*intback/intdat)<<"\\% \\\\ "<<endl;
cout<<"Data      & "<<intdat<<"             &        \\\\ "<<endl;
cout<<"\\hline"<<endl;
cout<<"ScaleFactor & "<<Form("%.2f",sf)<<" $\\pm$"<<Form("%.3f",esf)<<"  &        \\\\ "<<endl; 
cout<<"\\hline\\hline"<<endl;
cout<<"\\end{tabular}"<<endl;
cout<<"--------------------------------------------"<<endl;

double xbins[14] = {0,100,200,300,400,500,600,700,1200,1300,1400,2000,3000,4000};
    h_wj->Rebin(13,"hb_wj",xbins);
    h_dy->Rebin(13,"hb_dy",xbins);
    h_tt->Rebin(13,"hb_tt",xbins);
    h_st->Rebin(13,"hb_st",xbins);
    h_vv->Rebin(13,"hb_vv",xbins);
    //h_qc->Rebin(11,"hb_qc",xbins);
    h_data->Rebin(13,"hb_data",xbins);
    h_ratio->Rebin(13,"hb_ratio",xbins);
    h_back->Rebin(13,"hb_back",xbins);

/*
    h_wj->Rebin(10);
    h_dy->Rebin(10);
    h_tt->Rebin(10);
    h_st->Rebin(10);
    h_vv->Rebin(10);
    h_data->Rebin(10);
    h_back->Rebin(10);
    h_ratio->Rebin(10);
*/
  THStack *hs_n = new THStack("hs_n","");
    hs_n->Add(hb_wj);
    hs_n->Add(hb_vv);
    hs_n->Add(hb_dy);
    hs_n->Add(hb_st);
    hs_n->Add(hb_tt);

  TCanvas *c0=new TCanvas("c0","rm_nn",500,600);
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
   hs_n->SetMaximum(80);
   //hs_n->SetMinimum(0.0);
   hs_n->GetXaxis()->SetRangeUser(100,1200);
   hs_n->Draw("HIST");
   hb_data->Draw("same");
   hb_back->Draw("E2same");
   hb_back->SetLineWidth(1);
   hb_back->SetFillColor(1);
   hb_back->SetFillStyle(3002);
   hs_n->SetTitle(" ;  ; Events");
   //hs_n->SetTitle("CMS Preliminary                 59.7 fb^{-1} (13 TeV, 2016) ;  ; Events");
          leg1=new TLegend(0.65,0.65,0.91,0.91);
          //leg1->SetHeader("CMS Preliminary","C");
	  leg1->SetBorderSize(0);
          leg1->AddEntry(h_data,"Data","lp");
          leg1->AddEntry(h_dy,"Drell-Yan","fp");
          leg1->AddEntry(h_wj,"W+jets","fp");
          leg1->AddEntry(h_tt,"t#bar{t}","fp");
          leg1->AddEntry(h_vv,"Diboson","fp");
          //leg1->AddEntry(hb_qc,"data-driven QCD","fp");
          leg1->AddEntry(h_st,"Single Top","fp");
          leg1->AddEntry(hb_back,"Stat. Uncert.","fp");
          leg1->Draw();

    TPaveText *pt = new TPaveText(0.11,0.94,0.99,0.99,"NBNDC");
      pt->AddText("                 41.5 fb^{-1} (2017)");
      pt->SetTextFont(42);
      pt->SetTextAlign(32);
      pt->SetFillStyle(0);
      pt->SetBorderSize(0);
      pt->Draw();                                                                                             
    TPaveText *pt2 = new TPaveText(0.39,0.86,0.51,0.93,"NBNDC");
      pt2->AddText("CMS ");
      pt2->SetTextAlign(12);
      pt2->SetFillStyle(0);
      pt2->SetBorderSize(0);
      pt2->Draw();
    TPaveText *pt3 = new TPaveText(0.38,0.83,0.51,0.89,"NBNDC");
      pt3->AddText("Preliminary");
      pt3->SetTextAlign(12);
      pt3->SetTextFont(52);
      pt3->SetFillStyle(0);
      pt3->SetBorderSize(0);
      pt3->Draw();

   c0->cd(1);
TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.25);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.35);
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
        gPad->SetTickx();
        gPad->SetTicky();
	gPad->SetLeftMargin(0.15);
    	gPad->SetRightMargin(0.05);
TLine *line = new TLine(0,1,1200,1);
line->SetLineColor(2);

hb_ratio->Divide(hb_back);

int Nbins =  hb_ratio->GetXaxis()->GetNbins();               
cout<<Nbins<<endl;

Double_t* mcX = new Double_t[Nbins];                      
Double_t* mcY = new Double_t[Nbins];                      
Double_t* mcErrorX = new Double_t[Nbins];                 
Double_t* mcErrorY = new Double_t[Nbins];                                                                          

for(int bin=0; bin < Nbins; bin++) {       
	mcY[bin] = 1.0 ;                                              
	mcErrorY[bin] =  hb_ratio->GetBinError(bin+1);       
	mcX[bin] = hb_ratio->GetBinCenter(bin+1);                    
	mcErrorX[bin] = hb_ratio->GetBinWidth(bin+1) * 0.5;   
}

TGraphErrors *mcError = new TGraphErrors(Nbins,mcX,mcY,mcErrorX,mcErrorY);   
mcError->SetLineWidth(1);                                 
mcError->SetFillColor(1);                                 
mcError->SetFillStyle(3002);

hb_ratio->Draw();
mcError->Draw("E2same");
line->Draw("same");
hb_ratio->SetMaximum(2.2);
hb_ratio->SetMinimum(-0.1);
hb_ratio->SetLineWidth(1);
hb_ratio->SetFillColor(1);
hb_ratio->SetLineColor(1);
hb_ratio->SetMarkerStyle(20);
hb_ratio->GetXaxis()->SetRangeUser(100,1200);
hb_ratio->SetTitle("   ; m_{rec}(#mu, #tau, #Delta p_{T}) [GeV] ; #frac{Data}{Background} ");
  hb_ratio->SetMarkerStyle(33);
  hb_ratio->GetXaxis()->SetLabelSize(0.12);
  hb_ratio->GetYaxis()->SetLabelSize(0.11);
  hb_ratio->GetXaxis()->SetTitleSize(0.14);
  hb_ratio->GetYaxis()->SetTitleSize(0.12);
  hb_ratio->GetYaxis()->SetTitleOffset(0.5);
  hb_ratio->GetXaxis()->SetTitleOffset(1.1);

c0->SaveAs("pdf_tt16.pdf");
}
w