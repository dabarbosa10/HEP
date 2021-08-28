bool Analyzer::passGenMassFilterZ(float mass_lowbound, float mass_upbound){

  if(!isZsample) return true;

   std::vector<uint> genleptonindices;
   int genpart_id = 0, genmotherpart_idx = 0, genmotherpart_id = 0;

   // std::cout << "---------------------------" << std::endl;
   // Loop over all generator level particles to look for the leptons that come from a Z:
   for(size_t idx = 0; idx < _Gen->size(); idx++) {
     // Get the particle PDG ID
     genpart_id = abs(_Gen->pdg_id[idx]);
    // Find the index of the mother particle
     genmotherpart_idx = _Gen->genPartIdxMother[idx];

     // Find the id of the mother particle using the index we just retrieved
     genmotherpart_id =abs( _Gen->pdg_id[genmotherpart_idx]);

     //std::cout<<genmotherpart_id<<"    " <<genpart_id <<std::endl;
     // std::cout << "part_idx = " << idx << ", genpart_id = " << genpart_id << ", status = " << _Gen->status[idx] << ", mother part_idx = " << genmotherpart_idx << ", mother genpart_id = " << genmotherpart_id << std::endl;

     // Only select those particles that are electrons (11), muons (13) or taus (15)
     //if(! ( ( (genpart_id == 11 || genpart_id == 13) && _Gen->status[idx] == 1) || (genpart_id == 15 && _Gen->status[idx] == 2) ) )  continue;
     // std::cout << "This is a lepton" << std::endl;
     if(! ( (genpart_id == 15 && _Gen->status[idx] == 2) ) )  continue;
     // Check that the mother particle is a Z boson (23)
     //
     if((genmotherpart_id == 23) || (genmotherpart_id == 15) ){

       genleptonindices.push_back(idx);

     }
     // std::cout << "The mother is a Z boson" << std::endl;
     // Add the 4-momentum of this particle to the vector used later for dilepton mass calculation.

   }


  // Check that this vector only contains the information from two leptons.
   if(genleptonindices.size() < 2){
     // std::cout << "Not enough or too much leptons coming from the Z, returning false" << std::endl;
     return false;
   }
   // Check that they have the same mother (same mother index)
  /*
   else if(_Gen->genPartIdxMother[genleptonindices.at(0)] != _Gen->genPartIdxMother[genleptonindices.at(1)]){
     // std::cout << "The mothers of these two leptons are different, returning false" << std::endl;
     return false;
   }
  */
   // std::cout << "We got a real Z -> ll event" << std::endl;
   // Get the dilepton mass using the indices from the leptons stored
   TLorentzVector lep1 = _Gen->p4(genleptonindices.at(0));
   TLorentzVector lep2 = _Gen->p4(genleptonindices.at(1));

   gendilepmass = (lep1 + lep2).M();

   if( gendilepmass >= mass_lowbound && gendilepmass <= mass_upbound){
     // std::cout << "Dilepton mass = " << (lep1 + lep2).M() << " between " << mass_lowbound << " and " << mass_upbound << " Passed the genMassfilter! " << std::endl;
     return true;
   }
   else{
     // std::cout << "Dilepton mass = " << (lep1 + lep2).M() << " not between " << mass_lowbound << " and " << mass_upbound << " Failed the genMassfilter! " << std::endl;
     return false;
   }

 }
