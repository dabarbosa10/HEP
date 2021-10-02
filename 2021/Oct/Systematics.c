void Systematics::shiftJet(Particle& jet, TLorentzVector recoJet, std::string& syst_name, int syst){
  jet.addP4Syst(recoJet, syst);
  return;
}
void Systematics::shiftParticle(Particle& jet, TLorentzVector recoJet,
 double const& corrJetPt, double& corrJetMass, std::string& syst_name, int syst){
  TLorentzVector shiftedRecoJet;
  shiftedRecoJet.SetPtEtaPhiM(corrJetPt, recoJet.Eta(), recoJet.Phi(), corrJetMass);
  jet.addP4Syst(shiftedRecoJet, syst);
  return;
}
void Systematics::shiftLepton(Lepton& lepton, TLorentzVector recoLep, 
TLorentzVector genLep, double& dPx, double& dPy, int syst){
  if (genLep == TLorentzVector(0,0,0,0)) {
    lepton.addP4Syst(recoLep, syst);
    return;
  }
  double ratio = ((genLep.Pt()*scale) + (recoLep.Pt() - genLep.Pt())*resolution)/recoLep.Pt();
   dPx+=recoLep.Px()*(ratio-1);
   dPy+=recoLep.Py()*(ratio-1);
   recoLep*=ratio;
   lepton.addP4Syst(recoLep, syst);
   return;
}
void Systematics::loadScaleRes(const PartStats& smear, const PartStats& syst, std::string syst_name) {
  scale = 1;
  resolution = 1;
  if(smear.bfind("SmearTheParticle")) {
    scale = smear.dmap.at("PtScaleOffset");
    resolution = smear.dmap.at("PtResolutionOffset");
  }
  if(syst_name.find("_Res_")) {
    resolution = syst_name.find("_Up") ? 1 + syst.dmap.at("res") : 1 - syst.dmap.at("res");
    scale=1;
  } else if(syst_name.find("_Scale_")) {
    scale = syst_name.find("_Up") ? 1+syst.dmap.at("scale") : 1- syst.dmap.at("scale");
    resolution=1;
  }
}





