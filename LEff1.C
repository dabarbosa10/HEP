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
   //TFile *f5 =  new TFile("Zprime_NonUniversalSSM_M4000_gl1p0_gh1p0.root");

   TH1F*hTPt0=(TH1F*)f0->Get("NRecoVertex/Events");
   TH1F*hTPt00=(TH1F*)f0->Get("NDiJetCombinations/Events");
   
   TH1F*hTPt1=(TH1F*)f1->Get("NRecoVertex/Events");
   TH1F*hTPt01=(TH1F*)f1->Get("NDiJetCombinations/Events");

   TH1F*hTPt2=(TH1F*)f2->Get("NRecoVertex/Events");
   TH1F*hTPt02=(TH1F*)f2->Get("NDiJetCombinations/Events");

   TH1F*hTPt3=(TH1F*)f3->Get("NRecoVertex/Events");
   TH1F*hTPt03=(TH1F*)f3->Get("NDiJetCombinations/Events");

   TH1F*hTPt4=(TH1F*)f4->Get("NRecoVertex/Events");
   TH1F*hTPt04=(TH1F*)f4->Get("NDiJetCombinations/Events");

   //TH1F*hTPt5=(TH1F*)f5->Get("NRecoVertex/Events");
   //TH1F*hTPt05=(TH1F*)f5->Get("NDiJetCombinations/Events");
 
   double_t Ef0, Ef1, Ef2, Ef3, Ef4, Ef5,er0,err0,er1,er2,er3,er4,er5;
   
   AC0=hTPt0->Integral();
   DC0=hTPt00->Integral();
   Ef0=(DC0/AC0);
   er0=TMath::Sqrt( DC0*(1-Ef0) );
   er0=(er0/AC0)*100;	

   AC1=hTPt1->Integral();
   DC1=hTPt01->Integral();
   Ef1=DC1/AC1;
   er1=TMath::Sqrt( DC1*(1-Ef1) );
   er1=(er1/AC1)*100;	
   
   AC2=hTPt2->Integral();
   DC2=hTPt02->Integral();
   Ef2=DC2/AC2;
   er2=TMath::Sqrt( DC2*(1-Ef2) );
   er2=(er2/AC2)*100;	

   AC3=hTPt3->Integral();
   DC3=hTPt03->Integral();
   Ef3=DC3/AC3;
   er3=TMath::Sqrt( DC3*(1-Ef3) );
   er3=(er3/AC3)*100;	

   AC4=hTPt4->Integral();
   DC4=hTPt04->Integral();
   Ef4=DC4/AC4;
   er4=TMath::Sqrt( DC4*(1-Ef4) );
   er4=(er4/AC4)*100;	

   //AC5=hTPt5->Integral();
   //DC5=hTPt05->Integral();
   //Ef5=DC5/AC5;
   //er5=TMath::Sqrt( DC5*(1-Ef5) );
   //er5=(er5/AC5)*100;	
   
   
   cout<<"-----------------------------"<<endl;
   cout<<"Mzprime 1000 GeV, gl=gh=1"<<endl;
   cout<<"Antes Cortes= "<<AC0<<endl;
   cout<<"Despues Cortes= "<<DC0<<endl;
   cout<<"Eficiencia= "<<(Ef0*100)<<" pm "<< er0 <<endl;
   cout<<"-----------------------------"<<endl;


   cout<<"-----------------------------"<<endl;
   cout<<"Mzprime 1250 GeV, gl=gh=1"<<endl;
   cout<<"Antes Cortes= "<<AC1<<endl;
   cout<<"Despues Cortes= "<<DC1<<endl;
   cout<<"Eficiencia= "<<Ef1*100<<" pm "<< er1 <<endl;;
   cout<<"-----------------------------"<<endl;

   cout<<"-----------------------------"<<endl;
   cout<<"Mzprime 1750 GeV, gl=gh=1"<<endl;
   cout<<"Antes Cortes= "<<AC2<<endl;
   cout<<"Despues Cortes= "<<DC2<<endl;
   cout<<"Eficiencia= "<<Ef2*100<<" pm "<< er2 <<endl;
   cout<<"-----------------------------"<<endl;
 
   cout<<"-----------------------------"<<endl;
   cout<<"Mzprime 2000 GeV, gl=gh=1"<<endl;
   cout<<"Antes Cortes= "<<AC3<<endl;
   cout<<"Despues Cortes= "<<DC3<<endl;
   cout<<"Eficiencia= "<<Ef3*100<<" pm "<< er3 <<endl;
   cout<<"-----------------------------"<<endl;


   cout<<"-----------------------------"<<endl;
   cout<<"Mzprime 2250 GeV, gl=gh=1"<<endl;
   cout<<"Antes Cortes= "<<AC4<<endl;
   cout<<"Despues Cortes= "<<DC4<<endl;
   cout<<"Eficiencia= "<<Ef4*100<<" pm "<< er4 <<endl;
   cout<<"-----------------------------"<<endl;

  // cout<<"-----------------------------"<<endl;
  //cout<<"Mzprime 4000 GeV, gl=gh=1"<<endl;
   //cout<<"Antes Cortes= "<<AC5<<endl;
   //cout<<"Despues Cortes= "<<DC5<<endl;
   //cout<<"Eficiencia= "<<Ef5*100<<" pm "<< er5 <<endl;
   //cout<<"-----------------------------"<<endl;

}