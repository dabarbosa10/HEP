

  bool sameParticle = (&lep1 == &lep2);
  TLorentzVector part1, part2, llep;

  for(auto i1 : *active_part->at(ePos1)) {




    part1 = lep1.p4(i1);
    // New: Get the rest mass in GeV according to the lepton type, Jun 26, 2020
    float mass1 = leptonmasses.at(lep1.type);

    for(auto i2 : *active_part->at(ePos2)) {
      if(sameParticle && i2 <= i1) continue;
      part2 = lep2.p4(i2);
      // New: Get the rest mass in GeV according to the lepton type, Jun 26, 2020
      float mass2 = leptonmasses.at(lep2.type);

      bool passCuts = true;

      if(!isData){
  if(distats["Run"].bfind("DiscrByGenDileptonMass")){
       if(passGenMassFilterZ(distats["Run"].pmap.at("GenDilepMassRange").first, distats["Run"].pmap.at("GenDilepMassRange").second) == false){
   //  clear_values();
   //     //    return;
          passCuts=false;
          }
       }
      }


      for(auto cut : stats.bset) {

        if(!passCuts) break;
        else if (cut == "DiscrByDeltaR") passCuts = passCuts && (part1.DeltaR(part2) >= stats.dmap.at("DeltaRCut"));
        else if(cut == "DiscrByCosDphi") passCuts = passCuts && passCutRange(cos(absnormPhi(part1.Phi() - part2.Phi())), stats.pmap.at("CosDphiCut"));
        else if(cut == "DiscrByDeltaPt") passCuts = passCuts && passCutRange(part1.Pt() - part2.Pt(), stats.pmap.at("DeltaPtCutValue"));
        else if(cut == "DiscrByCDFzeta2D") {
          double CDFzeta = stats.dmap.at("PZetaCutCoefficient") * getPZeta(part1, part2).first
            + stats.dmap.at("PZetaVisCutCoefficient") * getPZeta(part1, part2).second;
          passCuts = passCuts && passCutRange(CDFzeta, stats.pmap.at("CDFzeta2DCutValue"));
