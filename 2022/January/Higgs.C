using std::cout;
using std::endl;

using namespace RooFit;

TH1F* GetHistoFromTree(TTree* eventTree, string var, string limits, string cut){
	
	string title=var+limits+cut;
	
	string variable=var+">>sg1"+limits;
	eventTree->Draw(variable.c_str(),cut.c_str());
	HistoSg1 = (TH1F*)gDirectory->Get("sg1");
	
	return HistoSg1;
}


int PlotHggVariables(){
	
	string filename[4];
	filename[0] = "Experiment_gluonfusionH120to2photons_all.root";
	filename[1] = "Experiment_born_all.root";
	filename[2] = "Experiment_born_all.root";
	filename[3] = "Experiment_gammajet_all.root";
	
	double weight[4];
	weight[0] = 5000*19.0*0.00223/100000.;
	weight[1] = 5000*2.0*22.37/100000.;
	weight[2] = 5000*2.0*12.37/100000.;
	weight[3] = 5000*1.3*19220./20000000.;
	
	TFile* file[4];
	TTree* Tree[4];
	
	file[0] = new TFile(filename[0].c_str());
	file[1] = new TFile(filename[1].c_str());
	file[2] = new TFile(filename[2].c_str());
	file[3] = new TFile(filename[3].c_str());

	Tree[0] = (TTree*) file[0]->Get("Tree");
	Tree[1] = (TTree*) file[1]->Get("Tree");
	Tree[2] = (TTree*) file[2]->Get("Tree");
	Tree[3] = (TTree*) file[3]->Get("Tree");

	string var = "dipho_mgg";
	string limits = "(50,100,200)";
	string cut = "pholead_pt>40 && pholead_pt>30";
	
	TH1F* Histo[4];
	Histo[0] = GetHistoFromTree(Tree[0], var, limits, cut);
	Histo[1] = GetHistoFromTree(Tree[1], var, limits, cut);
	Histo[2] = GetHistoFromTree(Tree[2], var, limits, cut);
	Histo[3] = GetHistoFromTree(Tree[3], var, limits, cut);

	TH1F* HistoStack[4];
	HistoStack[0] = new TH1F("HistoStack0","HistoStack0",50,100,200);
	HistoStack[0]->Add(Histo[0],10*weight[0]);
	HistoStack[0]->Add(Histo[1],weight[1]);
	HistoStack[0]->Add(Histo[2],weight[2]);
	HistoStack[0]->Add(Histo[3],weight[3]);
	
	HistoStack[1] = new TH1F("HistoStack1","HistoStack1",50,100,200);
	HistoStack[1]->Add(Histo[1],weight[1]);
	HistoStack[1]->Add(Histo[2],weight[2]);	
	HistoStack[1]->Add(Histo[3],weight[3]);	
	
	HistoStack[2] = new TH1F("HistoStack2","HistoStack2",50,100,200);
	HistoStack[2]->Add(Histo[2],weight[2]);	
	HistoStack[2]->Add(Histo[3],weight[3]);	

	HistoStack[3] = new TH1F("HistoStack3","HistoStack3",50,100,200);
	HistoStack[3]->Add(Histo[3],weight[3]);	
	
	TCanvas* CanvasMgg = new TCanvas("CanvasMgg","CanvasMgg");
	
	HistoStack[0]->SetXTitle("M_{#gamma#gamma} (GeV)");
	HistoStack[0]->SetFillColor(kMagenta);
	HistoStack[0]->Draw();
	
	HistoStack[1]->SetFillColor(kBlue);
	HistoStack[1]->Draw("same");
	
	HistoStack[2]->SetFillColor(8);
	HistoStack[2]->Draw("same");
	
	HistoStack[3]->SetFillColor(kOrange);
	HistoStack[3]->Draw("same");
	
	legend = new TLegend(0.3, 0.7, 0.95, 0.95, "5 fb^{-1}, p_{T}>40,30 GeV");
	legend->SetFillColor(kWhite);
	legend->AddEntry(HistoStack[0]->GetName(), "H#rightarrow#gamma#gamma #times10", "f");
	legend->AddEntry(HistoStack[1]->GetName(), "Born", "f");
	legend->AddEntry(HistoStack[2]->GetName(), "Box", "f");
	legend->AddEntry(HistoStack[3]->GetName(), "#gamma+jets", "f");
	legend->Draw();
	
	CanvasMgg->Update();
	CanvasMgg->Draw();
	
	return;
}