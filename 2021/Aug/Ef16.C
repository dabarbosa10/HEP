{  
	gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);
  //gStyle->SetOptStat(0);
  //gStyle->SetOptFit(0);

   TFile *f0  = new TFile("Zprime_M250_gl1p0_gh1p0.root");
   TFile *f1  = new TFile("Zprime_M500_gl1p0_gh1p0.root");
   TFile *f2  = new TFile("Zprime_M750_gl1p0_gh1p0.root");
   TFile *f3  = new TFile("Zprime_M1000_gl1p0_gh1p0.root");
   TFile *f4  = new TFile("Zprime_M1250_gl1p0_gh1p0.root");
   TFile *f5  = new TFile("Zprime_M1500_gl1p0_gh1p0.root");
   TFile *f6  = new TFile("Zprime_M1750_gl1p0_gh1p0.root");
   TFile *f7  = new TFile("Zprime_M2000_gl1p0_gh1p0.root");
   TFile *f8  = new TFile("Zprime_M2250_gl1p0_gh1p0.root");
   TFile *f9  = new TFile("Zprime_M2500_gl1p0_gh1p0.root");
   TFile *f10=  new TFile("Zprime_M2750_gl1p0_gh1p0.root");
   TFile *f11 = new TFile("Zprime_M3000_gl1p0_gh1p0.root");
   TFile *f12 = new TFile("Zprime_M4000_gl1p0_gh1p0.root");

   //TFile *f6= new TFile("Zprime_NonUniversalSSM_M2000_gl1p0_gh1p0.root");

   TH1F*hTPt0=(TH1F*)f0->Get("NDiJetCombinations/Events");
   TH1F*hTPt1=(TH1F*)f1->Get("NDiJetCombinations/Events");
   TH1F*hTPt2=(TH1F*)f2->Get("NDiJetCombinations/Events");
   TH1F*hTPt3=(TH1F*)f3->Get("NDiJetCombinations/Events");
   TH1F*hTPt4=(TH1F*)f4->Get("NDiJetCombinations/Events");
   TH1F*hTPt5=(TH1F*)f5->Get("NDiJetCombinations/Events");
   TH1F*hTPt6=(TH1F*)f6->Get("NDiJetCombinations/Events");
   TH1F*hTPt7=(TH1F*)f7->Get("NDiJetCombinations/Events");
   TH1F*hTPt8=(TH1F*)f8->Get("NDiJetCombinations/Events");
   TH1F*hTPt9=(TH1F*)f9->Get("NDiJetCombinations/Events");
   TH1F*hTPt10=(TH1F*)f10->Get("NDiJetCombinations/Events");
   TH1F*hTPt11=(TH1F*)f11->Get("NDiJetCombinations/Events");
   TH1F*hTPt12=(TH1F*)f12->Get("NDiJetCombinations/Events");

   double_t af0, be0, ra0, af1, be1, ra1, af2, be2, ra2, af3, be3, ra3, af4, be4, ra4;
   double_t af5, be5, ra5, af6, be6, ra6, af7, be7, ra7, af8, be8, ra8, af9, be9, ra9;
   double_t af10, be10, ra10, af11, be11, ra11,af12, be12, ra12;

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

   be5=hTPt5->GetBinContent(1);
   af5=hTPt5->GetBinContent(2);
   ra5=af5/be5;
   er5= TMath::Sqrt( (1.0/be5) + (1.0/af5) );
   er5=(er5*(ra5))*100;

   be6=hTPt6->GetBinContent(1);
   af6=hTPt6->GetBinContent(2);
   ra6=af6/be6;
   er6= TMath::Sqrt( (1.0/be6) + (1.0/af6) );
   er6=(er6*(ra6))*100;

   be7=hTPt7->GetBinContent(1);
   af7=hTPt7->GetBinContent(2);
   ra7=af7/be7;
   er7= TMath::Sqrt( (1.0/be7) + (1.0/af7) );
   er7=(er7*(ra7))*100;

   be8=hTPt8->GetBinContent(1);
   af8=hTPt8->GetBinContent(2);
   ra8=af8/be8;
   er8= TMath::Sqrt( (1.0/be8) + (1.0/af8) );
   er8=(er8*(ra8))*100;

   be9=hTPt9->GetBinContent(1);
   af9=hTPt9->GetBinContent(2);
   ra9=af9/be9;
   er9= TMath::Sqrt( (1.0/be9) + (1.0/af9) );
   er9=(er9*(ra9))*100;

   be10=hTPt10->GetBinContent(1);
   af10=hTPt10->GetBinContent(2);
   ra10=af10/be10;
   er10=TMath::Sqrt( (1.0/be10) + (1.0/af10) );
   er10=(er10*(ra10))*100;

   be11=hTPt11->GetBinContent(1);
   af11=hTPt11->GetBinContent(2);
   ra11=af11/be11;
   er11= TMath::Sqrt( (1.0/be11) + (1.0/af11) );
   er11=(er11*(ra11))*100;

   be12=hTPt12->GetBinContent(1);
   af12=hTPt12->GetBinContent(2);
   ra12=af12/be12;
   er12= TMath::Sqrt( (1.0/be12) + (1.0/af12) );
   er12=(er12*(ra12))*100;

   double xs250, xs500, xs750, xs1000, xs1250, xs1500, xs1750, xs2000, xs2250 ,xs2500, xs2750 ,xs3000, xs3500, xs4000;

   xs250=1846;
   xs500= 172.5;
   xs750=37.93;
   xs1000=11.93;
   xs1250=4.557;
   xs1500=1.971;
   xs1750= 0.9264;
   xs2000=0.4633;
   xs2250=0.2425;
   xs2500=0.1313;
   xs2750=0.07287;
   xs3000=0.04129;
   //xs3500= 0.0005883*1000.0;
   xs4000= 0.004812;

   double lumi=35.9; 

   cout<<"\\hline\\hline"<<endl;
   cout<<"Mass(GeV)   & Efficiency  \\%   & Events Before Cuts & Events After  Cuts & Cross Section (fb)  & N=L.xs.e    \\\\"<<endl;
   //cout<<"Process   & Events          & \\%   \\\\ "<<endl; 
   cout<<"250 & "<<ra0*100<<"$ \\pm $"<<er0<<" & " << be0 <<" & " << af0 << " & "<< xs250 <<" & "<< (ra0)*lumi*xs250 <<" \\\\"<<endl;
   cout<<"500 & "<<ra1*100<<"$ \\pm$ "<<er1<<" & " << be1 <<" & " << af1 << " & " << xs500 <<" & "<<(ra1)*lumi*xs500 <<" \\\\"<<endl;
   cout<<"750 & "<<ra2*100<<"$ \\pm$ "<<er2<<" & " << be2 <<" & " << af2 << " & " << xs750 <<" & "<<(ra2)*lumi*xs750 <<" \\\\"<<endl;
   cout<<"1000 & "<<ra3*100<<"$ \\pm$ "<<er3<<" & " << be3 <<" & " << af3 << " & " << xs1000 <<" & "<<(ra3)*lumi*xs1000 <<" \\\\"<<endl;
   cout<<"1250 & "<<ra4*100<<"$ \\pm $"<<er4<<" & " << be4 <<" & " << af4 << " & " << xs1250 <<" & "<<(ra4)*lumi*xs1250 <<" \\\\"<<endl;
   cout<<"1500 & "<<ra5*100<<"$ \\pm $"<<er5<<" & " << be5 <<" & " << af5 << " & " << xs1500 <<" & "<<(ra5)*lumi*xs1500 <<" \\\\"<<endl;
   cout<<"1750 & "<<ra6*100<<"$ \\pm$ "<<er6<<" & " << be6 <<" & " << af6 << " & " << xs1750 <<" & "<<(ra6)*lumi*xs1750 <<" \\\\"<<endl;
   cout<<"2000 & "<<ra7*100<<"$ \\pm$ "<<er7<<" & " << be7 <<" & " << af7 << " & " << xs2000 <<" & "<<(ra7)*lumi*xs2000 <<" \\\\"<<endl;
   cout<<"2250 & "<<ra8*100<<"$ \\pm$ "<<er8<<" & " << be8 <<" & " << af8 << " & " << xs2250 <<" & "<<(ra8)*lumi*xs2250 <<" \\\\"<<endl;
   cout<<"2500 & "<<ra9*100<<"$ \\pm$ "<<er9<<" & " << be9 <<" & " << af9 << " & " << xs2500 <<" & "<<(ra9)*lumi*xs2500 <<" \\\\"<<endl;
   cout<<"2750 & "<<ra10*100<<"$ \\pm$ "<<er10<<" & " << be10 <<" & " << af10 << " & " << xs2750 <<" & "<<(ra10)*lumi*xs2750 <<" \\\\"<<endl;
   cout<<"3000 & "<<ra11*100<<"$ \\pm $"<<er11<<" & " << be11 <<" & " << af11 << " & " << xs3000 <<" & "<<(ra11)*lumi*xs3000 <<" \\\\"<<endl;
   cout<<"4000 & "<<ra12*100<<"$ \\pm $"<<er12<<" & " << be12 <<" & " << af12 << " & " << xs4000 <<" & "<<(ra12)*lumi*xs4000 <<" \\\\"<<endl;




}