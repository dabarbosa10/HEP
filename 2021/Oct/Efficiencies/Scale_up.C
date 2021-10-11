{
  gROOT->Reset();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);

  // TFile *f0  = new TFile("DY+Jets_Nic_ST_2016.root");
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
	TFile *f10  = new TFile("Zprime_M2750_gl1p0_gh1p0.root");
   TFile *f11  = new TFile("Zprime_M3000_gl1p0_gh1p0.root");
   //TFile *f12  = new TFile("Zprime_M3500_gl1p0_gh1p0.root");
   TFile *f13  = new TFile("Zprime_M4000_gl1p0_gh1p0.root");


//==================================================================
   TH1F*hTPt0=(TH1F*)f0->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt00=(TH1F*)f0->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt1=(TH1F*)f1->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt11=(TH1F*)f1->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt2=(TH1F*)f2->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt22=(TH1F*)f2->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt3=(TH1F*)f3->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt33=(TH1F*)f3->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt4=(TH1F*)f4->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt44=(TH1F*)f4->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt5=(TH1F*)f5->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt55=(TH1F*)f5->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt6=(TH1F*)f6->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt66=(TH1F*)f6->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt7=(TH1F*)f7->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt77=(TH1F*)f7->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt8=(TH1F*)f8->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt88=(TH1F*)f8->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt9=(TH1F*)f9->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt99=(TH1F*)f9->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt10=(TH1F*)f10->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt100=(TH1F*)f10->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt111=(TH1F*)f11->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt1111=(TH1F*)f11->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   //TH1F*hTPt12=(TH1F*)f12->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
  // TH1F*hTPt120=(TH1F*)f12->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   TH1F*hTPt13=(TH1F*)f13->Get("NElectron1Tau1Combinations/Electron1Tau1ReconstructableMassDeltaPt");
   TH1F*hTPt130=(TH1F*)f13->Get("Electron_Res_Up/Electron1Tau1ReconstructableMassDeltaPt");

   rel0=abs( ((hTPt0->Integral()- hTPt00->Integral())/(hTPt00->Integral()))*100  );
   rel1=abs( ((hTPt1->Integral()- hTPt11->Integral())/(hTPt11->Integral()))*100  );
	rel2=abs( ((hTPt2->Integral()- hTPt22->Integral())/(hTPt22->Integral()))*100  );
   rel3=abs( ((hTPt3->Integral()- hTPt33->Integral())/(hTPt33->Integral()))*100  );
   rel4=abs( ((hTPt4->Integral()- hTPt44->Integral())/(hTPt44->Integral()))*100  );
   rel5=abs( ((hTPt5->Integral()- hTPt55->Integral())/(hTPt55->Integral()))*100  );
	rel6=abs( ((hTPt6->Integral()- hTPt66->Integral())/(hTPt66->Integral()))*100  );
   rel7=abs( ((hTPt7->Integral()- hTPt77->Integral())/(hTPt77->Integral()))*100  );
   rel8=abs( ((hTPt8->Integral()- hTPt88->Integral())/(hTPt88->Integral()))*100  );
   rel9=abs( ((hTPt9->Integral()- hTPt99->Integral())/(hTPt99->Integral()))*100  );
   rel10=abs( ((hTPt10->Integral()- hTPt100->Integral())/(hTPt100->Integral()))*100  );
   rel11=abs( ((hTPt111->Integral()- hTPt1111->Integral())/(hTPt1111->Integral()))*100  );
	//rel12=abs( ((hTPt12->Integral()- hTPt120->Integral())/(hTPt120->Integral()))*100  );
   rel13=abs( ((hTPt13->Integral()- hTPt130->Integral())/(hTPt130->Integral()))*100  );


   std::cout<<"\\\\begin{tabular}{  |c| c | c | c |   }"<<std::endl;
   std::cout<<"\\hline "<<std::endl;
	std::cout<<" Mass & Without Res up & With Res Up & Difference \\% \\\\"<<std::endl;
	std::cout<< " \\hline " <<std::endl;
   std::cout<<"250 Gev &" <<hTPt0->Integral()<<" & " <<hTPt00->Integral()<<" & "<<rel0   <<" \\\\" << std::endl;
   std::cout<<"500 Gev &" <<hTPt1->Integral()<<" & " <<hTPt11->Integral()<<" & "<<rel1   << " \\\\" << std::endl;
   std::cout<<"750 Gev &" <<hTPt2->Integral()<<" & " <<hTPt22->Integral()<<" & "<<rel2   << " \\\\" << std::endl;
   std::cout<<"1000 Gev &" <<hTPt3->Integral()<<" & " <<hTPt33->Integral()<<" & "<<rel3   <<" \\\\" <<  std::endl;
   std::cout<<"1250 Gev &" <<hTPt4->Integral()<<" & " <<hTPt44->Integral()<<" & "<<rel4   << " \\\\" <<  std::endl;
   std::cout<<"1500 Gev &" <<hTPt5->Integral()<<" & " <<hTPt55->Integral()<<" & "<<rel5   << " \\\\" <<  std::endl;
   std::cout<<"1750 Gev &" <<hTPt6->Integral()<<" & " <<hTPt66->Integral()<<" & "<<rel6   << " \\\\" << std::endl;
   std::cout<<"2000 Gev &" <<hTPt7->Integral()<<" & " <<hTPt77->Integral()<<" & "<<rel7   << " \\\\" << std::endl;
   std::cout<<"2250 Gev &" <<hTPt8->Integral()<<" & " <<hTPt88->Integral()<<" & "<<rel8   << " \\\\" << std::endl;
   std::cout<<"2500 Gev &" <<hTPt9->Integral()<<" & " <<hTPt99->Integral()<<" & "<<rel9   << " \\\\" << std::endl;
   std::cout<<"2750 Gev &" <<hTPt10->Integral()<<" & " <<hTPt100->Integral()<<" & "<<rel10   << " \\\\" <<  std::endl;
   std::cout<<"3000 Gev &" <<hTPt111->Integral()<<" & " <<hTPt1111->Integral()<<" & "<<rel11   << " \\\\" << std::endl;
  // std::cout<<"3500 Gev &" <<hTPt12->Integral()<<" & " <<hTPt120->Integral()<<" & "<<rel12   << " \\\\" <<  std::endl;
   std::cout<<"4000 Gev &" <<hTPt13->Integral()<<" & " <<hTPt130->Integral()<<" & "<<rel13   <<" \\\\" <<  std::endl;







}