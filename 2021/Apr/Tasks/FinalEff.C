{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);
  //gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);

   TFile *f0  = new TFile("Zprime_NonUniversalSSM_M1000_gl1p0_gh1p0.root");
   TFile *f1  = new TFile("Zprime_NonUniversalSSM_M1250_gl1p0_gh1p0.root");
   TFile *f2  = new TFile("Zprime_NonUniversalSSM_M1750_gl1p0_gh1p0.root");
   TFile *f3 =  new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0.root");
   TFile *f4  = new TFile("Zprime_NonUniversalSSM_M2250_gl1p0_gh1p0.root");

   //TFile *f6= new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0.root");

   TH1F*hTPt0=(TH1F*)f0->Get("NDiJetCombinations/Events");
   TH1F*hTPt1=(TH1F*)f1->Get("NDiJetCombinations/Events");
   TH1F*hTPt2=(TH1F*)f2->Get("NDiJetCombinations/Events");
   TH1F*hTPt3=(TH1F*)f3->Get("NDiJetCombinations/Events");
   TH1F*hTPt4=(TH1F*)f4->Get("NDiJetCombinations/Events");
 
   double_t af0, be0,ra0, af1, be1,ra1,af2, be2,ra2, af3, be3,ra3, af4, be4,ra4 ;

   be0=hTPt0->GetBinContent(1);
   af0=hTPt0->GetBinContent(2);
   ra0=af0/be0;
   er0= TMath::Sqrt( (1.0/be0) + (1.0/af0) );
   er0=(er0*(ra0))*100;

   be1=hTPt1->GetBinContent(1);
   af1=hTPt1->GetBinContent(2);
   ra1=af1/be1;
   er1= TMath::Sqrt( (1.0/be1) + (1.0/af1) );
   er1=(er1*(ra1))*100;

   be2=hTPt2->GetBinContent(1);
   af2=hTPt2->GetBinContent(2);
   ra2=af2/be2;
   er2= TMath::Sqrt( (1.0/be2) + (1.0/af2) );
   er2=(er2*(ra2))*100;

   be3=hTPt3->GetBinContent(1);
   af3=hTPt3->GetBinContent(2);
   ra3=af3/be3;
   er3= TMath::Sqrt( (1.0/be3) + (1.0/af3) );
   er3=(er3*(ra3))*100;

   be4=hTPt4->GetBinContent(1);
   af4=hTPt4->GetBinContent(2);
   ra4=af4/be4;
   er4= TMath::Sqrt( (1.0/be4) + (1.0/af4) );
   er4=(er4*(ra4))*100;
   
   cout<<"\\hline\\hline"<<endl;
   cout<<"Mass(GeV)   & Efficiency  \\%   & Events Before Cuts & Events After  Cuts     \\\\"<<endl;
   //cout<<"Process   & Events          & \\%   \\\\ "<<endl; 
   cout<<"1000 & " <<ra0*100<<"$ \\pm $"<<er0<<" & " << be0 <<" & " << af0 <<" \\\\"<<endl;
   cout<<"1250 & "<<ra1*100<<"$ \\pm$ "<<er1<<" & " << be1 <<" & " << af1 <<" \\\\"<<endl;
   cout<<"1750 & "<<ra2*100<<"$ \\pm$ "<<er2<<" & " << be2 <<" & " << af2 <<" \\\\"<<endl;
   cout<<"2000 & "<<ra3*100<<"$ \\pm$ "<<er3<<" & " << be3 <<" & " << af3 <<" \\\\"<<endl;
   cout<<"2500 & "<<ra4*100<<"$ \\pm $"<<er4<<" & " << be4 <<" & " << af4 << " \\\\"<<endl;


}