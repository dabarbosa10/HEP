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














































VMLM_TeV_MG_MC_4.sh

Total for query: 123 jobs; 0 completed, 0 removed, 0 idle, 123 running, 0 held, 0 suspended 
Total for all users: 4518 jobs; 0 completed, 30 removed, 3041 idle, 1410 running, 37 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q dbarbosa


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 16:50:22
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 4623 jobs; 0 completed, 114 removed, 2719 idle, 1719 running, 71 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 16:50:22
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 5983 jobs; 0 completed, 0 removed, 3653 idle, 1238 running, 1092 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 16:50:22
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+03:06:06 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.1   dbarbosa        8/27 13:43   0+03:06:10 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_1.sh
73002957.2   dbarbosa        8/27 13:43   0+03:06:04 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+03:06:05 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+03:06:08 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+03:06:04 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+03:06:06 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+03:06:10 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.8   dbarbosa        8/27 13:43   0+03:06:06 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_8.sh
73002957.9   dbarbosa        8/27 13:43   0+03:06:08 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+03:06:08 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+03:06:10 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.13  dbarbosa        8/27 13:43   0+03:06:08 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_13.sh
73002957.14  dbarbosa        8/27 13:43   0+03:06:06 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.15  dbarbosa        8/27 13:43   0+03:06:09 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_15.sh
73002957.16  dbarbosa        8/27 13:43   0+03:06:08 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+03:05:46 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+03:05:46 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+03:05:47 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+03:05:45 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+03:05:45 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.22  dbarbosa        8/27 13:43   0+03:05:45 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_22.sh
73002957.23  dbarbosa        8/27 13:43   0+03:05:45 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_23.sh
73002957.24  dbarbosa        8/27 13:43   0+03:05:45 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+03:05:43 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+03:05:43 R  0   248.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+03:05:43 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+03:05:43 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+03:05:23 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+03:05:21 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+03:05:21 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.32  dbarbosa        8/27 13:43   0+03:05:21 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_32.sh
73002957.33  dbarbosa        8/27 13:43   0+03:05:21 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+03:05:19 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.35  dbarbosa        8/27 13:43   0+03:05:21 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_35.sh
73002957.36  dbarbosa        8/27 13:43   0+03:05:19 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+03:05:19 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+03:04:58 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+03:04:54 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.40  dbarbosa        8/27 13:43   0+03:04:58 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_40.sh
73002957.41  dbarbosa        8/27 13:43   0+03:04:55 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+03:04:54 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+03:04:51 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+03:04:57 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.45  dbarbosa        8/27 13:43   0+03:04:57 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_45.sh
73002957.46  dbarbosa        8/27 13:43   0+03:04:57 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+03:04:57 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.48  dbarbosa        8/27 13:43   0+03:04:57 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_48.sh
73002957.49  dbarbosa        8/27 13:43   0+03:04:55 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_49.sh
73002957.50  dbarbosa        8/27 13:43   0+03:04:55 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_50.sh
73002957.51  dbarbosa        8/27 13:43   0+03:04:31 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+03:04:34 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+03:04:34 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+03:04:33 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.55  dbarbosa        8/27 13:43   0+03:04:34 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_55.sh
73002957.56  dbarbosa        8/27 13:43   0+03:04:34 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+03:04:33 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.1   dbarbosa        8/27 13:43   0+03:04:33 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002958.2   dbarbosa        8/27 13:43   0+03:04:33 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+03:04:10 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+03:04:10 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+03:04:05 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+03:04:08 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+03:04:10 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+03:04:10 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.9   dbarbosa        8/27 13:43   0+03:04:10 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_9.sh
73002958.10  dbarbosa        8/27 13:43   0+03:04:08 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_10.sh
73002958.11  dbarbosa        8/27 13:43   0+03:04:08 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+03:04:08 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+03:04:07 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+03:04:06 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+03:04:06 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+03:04:06 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+03:04:06 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+03:04:04 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+03:04:04 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+03:04:04 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.21  dbarbosa        8/27 13:43   0+03:03:46 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_21.sh
73002958.22  dbarbosa        8/27 13:43   0+03:03:43 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+03:03:43 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+03:03:44 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.27  dbarbosa        8/27 13:43   0+03:03:44 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_27.sh
73002958.28  dbarbosa        8/27 13:43   0+03:03:45 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_28.sh
73002958.29  dbarbosa        8/27 13:43   0+03:03:45 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+03:03:43 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002958.31  dbarbosa        8/27 13:43   0+03:03:43 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_31.sh
73002959.0   dbarbosa        8/27 13:49   0+03:01:02 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.1   dbarbosa        8/27 13:49   0+03:01:01 R  0   248.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002959.2   dbarbosa        8/27 13:49   0+03:01:02 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002959.3   dbarbosa        8/27 13:49   0+03:01:00 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002959.4   dbarbosa        8/27 13:49   0+03:01:00 R  0   246.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002959.5   dbarbosa        8/27 13:49   0+03:01:00 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002959.7   dbarbosa        8/27 13:49   0+03:01:00 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002959.8   dbarbosa        8/27 13:49   0+03:00:58 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002961.0   dbarbosa        8/27 13:49   0+03:00:37 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002961.1   dbarbosa        8/27 13:49   0+03:00:38 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002961.2   dbarbosa        8/27 13:49   0+03:00:36 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.3   dbarbosa        8/27 13:49   0+03:00:36 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002961.4   dbarbosa        8/27 13:49   0+03:00:34 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+03:00:36 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+03:00:36 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+03:00:35 R  0   247.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+03:00:34 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+03:00:34 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.2   dbarbosa        8/27 13:49   0+03:00:34 R  0   246.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002962.3   dbarbosa        8/27 13:49   0+03:00:33 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002962.4   dbarbosa        8/27 13:49   0+03:00:31 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002962.5   dbarbosa        8/27 13:49   0+03:00:31 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002962.7   dbarbosa        8/27 13:49   0+03:00:30 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.8   dbarbosa        8/27 13:49   0+03:00:30 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002964.0   dbarbosa        8/27 13:49   0+03:00:11 R  0   248.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_0.sh
73002964.2   dbarbosa        8/27 13:49   0+03:00:13 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002964.3   dbarbosa        8/27 13:49   0+03:00:13 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002964.5   dbarbosa        8/27 13:49   0+03:00:11 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_5.sh
73002964.6   dbarbosa        8/27 13:49   0+02:59:49 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_6.sh
73002964.7   dbarbosa        8/27 13:49   0+02:59:49 R  0   248.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_7.sh
73002964.8   dbarbosa        8/27 13:49   0+02:59:48 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_8.sh
73002965.2   dbarbosa        8/27 13:49   0+02:59:23 R  0   246.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002965.3   dbarbosa        8/27 13:49   0+02:59:25 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002965.4   dbarbosa        8/27 13:49   0+02:59:25 R  0   244.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_4.sh

Total for query: 120 jobs; 0 completed, 0 removed, 0 idle, 120 running, 0 held, 0 suspended 
Total for all users: 4145 jobs; 0 completed, 31 removed, 2787 idle, 1291 running, 36 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q 


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 17:44:13
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 3860 jobs; 0 completed, 114 removed, 2039 idle, 1636 running, 71 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 17:44:13
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 5250 jobs; 0 completed, 0 removed, 3038 idle, 1119 running, 1093 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 17:44:13
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+03:59:58 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.1   dbarbosa        8/27 13:43   0+04:00:02 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_1.sh
73002957.2   dbarbosa        8/27 13:43   0+03:59:56 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+03:59:57 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+04:00:00 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+03:59:56 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+03:59:58 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+04:00:02 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.8   dbarbosa        8/27 13:43   0+03:59:58 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_8.sh
73002957.9   dbarbosa        8/27 13:43   0+04:00:00 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+04:00:00 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+04:00:02 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.13  dbarbosa        8/27 13:43   0+04:00:00 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_13.sh
73002957.14  dbarbosa        8/27 13:43   0+03:59:58 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.15  dbarbosa        8/27 13:43   0+04:00:01 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_15.sh
73002957.16  dbarbosa        8/27 13:43   0+04:00:00 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+03:59:38 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+03:59:38 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+03:59:39 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+03:59:37 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+03:59:37 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.22  dbarbosa        8/27 13:43   0+03:59:37 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_22.sh
73002957.23  dbarbosa        8/27 13:43   0+03:59:37 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_23.sh
73002957.24  dbarbosa        8/27 13:43   0+03:59:37 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+03:59:35 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+03:59:35 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+03:59:35 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+03:59:35 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+03:59:15 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+03:59:13 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+03:59:13 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.32  dbarbosa        8/27 13:43   0+03:59:13 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_32.sh
73002957.33  dbarbosa        8/27 13:43   0+03:59:13 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+03:59:11 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.35  dbarbosa        8/27 13:43   0+03:59:13 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_35.sh
73002957.36  dbarbosa        8/27 13:43   0+03:59:11 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+03:59:11 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+03:58:50 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+03:58:46 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.40  dbarbosa        8/27 13:43   0+03:58:50 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_40.sh
73002957.41  dbarbosa        8/27 13:43   0+03:58:47 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+03:58:46 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+03:58:43 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+03:58:49 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.45  dbarbosa        8/27 13:43   0+03:58:49 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_45.sh
73002957.46  dbarbosa        8/27 13:43   0+03:58:49 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+03:58:49 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.48  dbarbosa        8/27 13:43   0+03:58:49 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_48.sh
73002957.49  dbarbosa        8/27 13:43   0+03:58:47 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_49.sh
73002957.50  dbarbosa        8/27 13:43   0+03:58:47 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_50.sh
73002957.51  dbarbosa        8/27 13:43   0+03:58:23 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+03:58:26 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+03:58:26 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+03:58:25 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.55  dbarbosa        8/27 13:43   0+03:58:26 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_55.sh
73002957.56  dbarbosa        8/27 13:43   0+03:58:26 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+03:58:25 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.1   dbarbosa        8/27 13:43   0+03:58:25 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002958.2   dbarbosa        8/27 13:43   0+03:58:25 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+03:58:02 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+03:58:02 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+03:57:57 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+03:58:00 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+03:58:02 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+03:58:02 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.9   dbarbosa        8/27 13:43   0+03:58:02 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_9.sh
73002958.10  dbarbosa        8/27 13:43   0+03:58:00 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_10.sh
73002958.11  dbarbosa        8/27 13:43   0+03:58:00 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+03:58:00 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+03:57:59 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+03:57:58 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+03:57:58 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+03:57:58 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+03:57:58 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+03:57:56 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+03:57:56 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+03:57:56 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.21  dbarbosa        8/27 13:43   0+03:57:38 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_21.sh
73002958.22  dbarbosa        8/27 13:43   0+03:57:35 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+03:57:35 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+03:57:36 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.27  dbarbosa        8/27 13:43   0+03:57:36 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_27.sh
73002958.28  dbarbosa        8/27 13:43   0+03:57:37 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_28.sh
73002958.29  dbarbosa        8/27 13:43   0+03:57:37 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+03:57:35 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002958.31  dbarbosa        8/27 13:43   0+03:57:35 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_31.sh
73002959.0   dbarbosa        8/27 13:49   0+03:54:54 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.1   dbarbosa        8/27 13:49   0+03:54:53 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002959.2   dbarbosa        8/27 13:49   0+03:54:54 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002959.3   dbarbosa        8/27 13:49   0+03:54:52 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002959.4   dbarbosa        8/27 13:49   0+03:54:52 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002959.5   dbarbosa        8/27 13:49   0+03:54:52 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002959.8   dbarbosa        8/27 13:49   0+03:54:50 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002961.0   dbarbosa        8/27 13:49   0+03:54:29 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002961.1   dbarbosa        8/27 13:49   0+03:54:30 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002961.2   dbarbosa        8/27 13:49   0+03:54:28 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.4   dbarbosa        8/27 13:49   0+03:54:26 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+03:54:28 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+03:54:28 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+03:54:27 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+03:54:26 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+03:54:26 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.3   dbarbosa        8/27 13:49   0+03:54:25 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002962.4   dbarbosa        8/27 13:49   0+03:54:23 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002962.5   dbarbosa        8/27 13:49   0+03:54:23 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002962.7   dbarbosa        8/27 13:49   0+03:54:22 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.8   dbarbosa        8/27 13:49   0+03:54:22 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002964.0   dbarbosa        8/27 13:49   0+03:54:03 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_0.sh
73002964.2   dbarbosa        8/27 13:49   0+03:54:05 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002964.3   dbarbosa        8/27 13:49   0+03:54:05 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002964.5   dbarbosa        8/27 13:49   0+03:54:03 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_5.sh
73002964.6   dbarbosa        8/27 13:49   0+03:53:41 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_6.sh
73002964.7   dbarbosa        8/27 13:49   0+03:53:41 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_7.sh
73002964.8   dbarbosa        8/27 13:49   0+03:53:40 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_8.sh
73002965.2   dbarbosa        8/27 13:49   0+03:53:15 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002965.3   dbarbosa        8/27 13:49   0+03:53:17 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002965.4   dbarbosa        8/27 13:49   0+03:53:17 R  0   248.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_4.sh

Total for query: 117 jobs; 0 completed, 0 removed, 0 idle, 117 running, 0 held, 0 suspended 
Total for dbarbosa: 117 jobs; 0 completed, 0 removed, 0 idle, 117 running, 0 held, 0 suspended 
Total for all users: 3789 jobs; 0 completed, 31 removed, 2138 idle, 1584 running, 36 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q 


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 17:53:55
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 5714 jobs; 0 completed, 114 removed, 3842 idle, 1687 running, 71 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 17:53:55
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 6214 jobs; 0 completed, 0 removed, 4015 idle, 1106 running, 1093 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 17:53:55
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+04:09:39 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.1   dbarbosa        8/27 13:43   0+04:09:43 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_1.sh
73002957.2   dbarbosa        8/27 13:43   0+04:09:37 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+04:09:38 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+04:09:41 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+04:09:37 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+04:09:39 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+04:09:43 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.8   dbarbosa        8/27 13:43   0+04:09:39 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_8.sh
73002957.9   dbarbosa        8/27 13:43   0+04:09:41 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+04:09:41 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+04:09:43 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.13  dbarbosa        8/27 13:43   0+04:09:41 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_13.sh
73002957.14  dbarbosa        8/27 13:43   0+04:09:39 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.15  dbarbosa        8/27 13:43   0+04:09:42 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_15.sh
73002957.16  dbarbosa        8/27 13:43   0+04:09:41 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+04:09:19 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+04:09:19 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+04:09:20 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+04:09:18 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+04:09:18 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.22  dbarbosa        8/27 13:43   0+04:09:18 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_22.sh
73002957.23  dbarbosa        8/27 13:43   0+04:09:18 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_23.sh
73002957.24  dbarbosa        8/27 13:43   0+04:09:18 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+04:09:16 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+04:09:16 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+04:09:16 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+04:09:16 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+04:08:56 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+04:08:54 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+04:08:54 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.32  dbarbosa        8/27 13:43   0+04:08:54 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_32.sh
73002957.33  dbarbosa        8/27 13:43   0+04:08:54 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+04:08:52 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.35  dbarbosa        8/27 13:43   0+04:08:54 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_35.sh
73002957.36  dbarbosa        8/27 13:43   0+04:08:52 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+04:08:52 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+04:08:31 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+04:08:27 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.40  dbarbosa        8/27 13:43   0+04:08:31 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_40.sh
73002957.41  dbarbosa        8/27 13:43   0+04:08:28 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+04:08:27 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+04:08:24 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+04:08:30 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.45  dbarbosa        8/27 13:43   0+04:08:30 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_45.sh
73002957.46  dbarbosa        8/27 13:43   0+04:08:30 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+04:08:30 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.48  dbarbosa        8/27 13:43   0+04:08:30 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_48.sh
73002957.49  dbarbosa        8/27 13:43   0+04:08:28 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_49.sh
73002957.50  dbarbosa        8/27 13:43   0+04:08:28 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_50.sh
73002957.51  dbarbosa        8/27 13:43   0+04:08:04 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+04:08:07 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+04:08:07 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+04:08:06 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.55  dbarbosa        8/27 13:43   0+04:08:07 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_55.sh
73002957.56  dbarbosa        8/27 13:43   0+04:08:07 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+04:08:06 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.1   dbarbosa        8/27 13:43   0+04:08:06 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002958.2   dbarbosa        8/27 13:43   0+04:08:06 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+04:07:43 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+04:07:43 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+04:07:38 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+04:07:41 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+04:07:43 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+04:07:43 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.9   dbarbosa        8/27 13:43   0+04:07:43 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_9.sh
73002958.10  dbarbosa        8/27 13:43   0+04:07:41 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_10.sh
73002958.11  dbarbosa        8/27 13:43   0+04:07:41 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+04:07:41 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+04:07:40 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+04:07:39 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+04:07:39 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+04:07:39 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+04:07:39 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+04:07:37 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+04:07:37 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+04:07:37 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.21  dbarbosa        8/27 13:43   0+04:07:19 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_21.sh
73002958.22  dbarbosa        8/27 13:43   0+04:07:16 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+04:07:16 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+04:07:17 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.27  dbarbosa        8/27 13:43   0+04:07:17 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_27.sh
73002958.28  dbarbosa        8/27 13:43   0+04:07:18 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_28.sh
73002958.29  dbarbosa        8/27 13:43   0+04:07:18 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+04:07:16 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002958.31  dbarbosa        8/27 13:43   0+04:07:16 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_31.sh
73002959.0   dbarbosa        8/27 13:49   0+04:04:35 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.1   dbarbosa        8/27 13:49   0+04:04:34 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002959.2   dbarbosa        8/27 13:49   0+04:04:35 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002959.3   dbarbosa        8/27 13:49   0+04:04:33 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002959.4   dbarbosa        8/27 13:49   0+04:04:33 R  0   250.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002959.5   dbarbosa        8/27 13:49   0+04:04:33 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002959.8   dbarbosa        8/27 13:49   0+04:04:31 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002961.1   dbarbosa        8/27 13:49   0+04:04:11 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002961.2   dbarbosa        8/27 13:49   0+04:04:09 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.4   dbarbosa        8/27 13:49   0+04:04:07 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+04:04:09 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+04:04:09 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+04:04:08 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+04:04:07 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+04:04:07 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.3   dbarbosa        8/27 13:49   0+04:04:06 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002962.4   dbarbosa        8/27 13:49   0+04:04:04 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002962.5   dbarbosa        8/27 13:49   0+04:04:04 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002962.7   dbarbosa        8/27 13:49   0+04:04:03 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.8   dbarbosa        8/27 13:49   0+04:04:03 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002964.0   dbarbosa        8/27 13:49   0+04:03:44 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_0.sh
73002964.2   dbarbosa        8/27 13:49   0+04:03:46 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002964.3   dbarbosa        8/27 13:49   0+04:03:46 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002964.5   dbarbosa        8/27 13:49   0+04:03:44 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_5.sh
73002964.6   dbarbosa        8/27 13:49   0+04:03:22 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_6.sh
73002964.7   dbarbosa        8/27 13:49   0+04:03:22 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_7.sh
73002964.8   dbarbosa        8/27 13:49   0+04:03:21 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_8.sh
73002965.2   dbarbosa        8/27 13:49   0+04:02:56 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002965.4   dbarbosa        8/27 13:49   0+04:02:58 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_4.sh

Total for query: 115 jobs; 0 completed, 0 removed, 0 idle, 115 running, 0 held, 0 suspended 
Total for dbarbosa: 115 jobs; 0 completed, 0 removed, 0 idle, 115 running, 0 held, 0 suspended 
Total for all users: 5455 jobs; 0 completed, 30 removed, 3872 idle, 1516 running, 37 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 18:04:21
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 5708 jobs; 0 completed, 114 removed, 3896 idle, 1627 running, 71 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 18:04:21
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 6479 jobs; 0 completed, 0 removed, 4288 idle, 1097 running, 1094 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 18:04:21
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+04:20:24 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.1   dbarbosa        8/27 13:43   0+04:20:28 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_1.sh
73002957.2   dbarbosa        8/27 13:43   0+04:20:22 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+04:20:23 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+04:20:26 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+04:20:22 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+04:20:24 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+04:20:28 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.8   dbarbosa        8/27 13:43   0+04:20:24 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_8.sh
73002957.9   dbarbosa        8/27 13:43   0+04:20:26 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+04:20:26 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+04:20:28 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.13  dbarbosa        8/27 13:43   0+04:20:26 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_13.sh
73002957.14  dbarbosa        8/27 13:43   0+04:20:24 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.15  dbarbosa        8/27 13:43   0+04:20:27 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_15.sh
73002957.16  dbarbosa        8/27 13:43   0+04:20:26 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+04:20:04 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+04:20:04 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+04:20:05 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+04:20:03 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+04:20:03 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.22  dbarbosa        8/27 13:43   0+04:20:03 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_22.sh
73002957.23  dbarbosa        8/27 13:43   0+04:20:03 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_23.sh
73002957.24  dbarbosa        8/27 13:43   0+04:20:03 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+04:20:01 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+04:20:01 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+04:20:01 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+04:20:01 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+04:19:41 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+04:19:39 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+04:19:39 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.32  dbarbosa        8/27 13:43   0+04:19:39 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_32.sh
73002957.33  dbarbosa        8/27 13:43   0+04:19:39 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+04:19:37 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.35  dbarbosa        8/27 13:43   0+04:19:39 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_35.sh
73002957.36  dbarbosa        8/27 13:43   0+04:19:37 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+04:19:37 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+04:19:16 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+04:19:12 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.40  dbarbosa        8/27 13:43   0+04:19:16 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_40.sh
73002957.41  dbarbosa        8/27 13:43   0+04:19:13 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+04:19:12 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+04:19:09 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+04:19:15 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.45  dbarbosa        8/27 13:43   0+04:19:15 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_45.sh
73002957.46  dbarbosa        8/27 13:43   0+04:19:15 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+04:19:15 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.48  dbarbosa        8/27 13:43   0+04:19:15 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_48.sh
73002957.49  dbarbosa        8/27 13:43   0+04:19:13 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_49.sh
73002957.50  dbarbosa        8/27 13:43   0+04:19:13 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_50.sh
73002957.51  dbarbosa        8/27 13:43   0+04:18:49 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+04:18:52 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+04:18:52 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+04:18:51 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.55  dbarbosa        8/27 13:43   0+04:18:52 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_55.sh
73002957.56  dbarbosa        8/27 13:43   0+04:18:52 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+04:18:51 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.1   dbarbosa        8/27 13:43   0+04:18:51 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002958.2   dbarbosa        8/27 13:43   0+04:18:51 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+04:18:28 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+04:18:28 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+04:18:23 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+04:18:26 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+04:18:28 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+04:18:28 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.9   dbarbosa        8/27 13:43   0+04:18:28 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_9.sh
73002958.10  dbarbosa        8/27 13:43   0+04:18:26 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_10.sh
73002958.11  dbarbosa        8/27 13:43   0+04:18:26 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+04:18:26 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+04:18:25 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+04:18:24 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+04:18:24 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+04:18:24 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+04:18:24 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+04:18:22 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+04:18:22 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+04:18:22 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.21  dbarbosa        8/27 13:43   0+04:18:04 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_21.sh
73002958.22  dbarbosa        8/27 13:43   0+04:18:01 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+04:18:01 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+04:18:02 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.27  dbarbosa        8/27 13:43   0+04:18:02 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_27.sh
73002958.28  dbarbosa        8/27 13:43   0+04:18:03 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_28.sh
73002958.29  dbarbosa        8/27 13:43   0+04:18:03 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+04:18:01 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002958.31  dbarbosa        8/27 13:43   0+04:18:01 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_31.sh
73002959.0   dbarbosa        8/27 13:49   0+04:15:20 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.1   dbarbosa        8/27 13:49   0+04:15:19 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002959.3   dbarbosa        8/27 13:49   0+04:15:18 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002959.4   dbarbosa        8/27 13:49   0+04:15:18 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002959.5   dbarbosa        8/27 13:49   0+04:15:18 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002959.8   dbarbosa        8/27 13:49   0+04:15:16 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002961.2   dbarbosa        8/27 13:49   0+04:14:54 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.4   dbarbosa        8/27 13:49   0+04:14:52 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+04:14:54 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+04:14:54 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+04:14:53 R  0   251.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+04:14:52 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+04:14:52 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.4   dbarbosa        8/27 13:49   0+04:14:49 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002962.5   dbarbosa        8/27 13:49   0+04:14:49 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002962.7   dbarbosa        8/27 13:49   0+04:14:48 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.8   dbarbosa        8/27 13:49   0+04:14:48 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002964.0   dbarbosa        8/27 13:49   0+04:14:29 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_0.sh
73002964.2   dbarbosa        8/27 13:49   0+04:14:31 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002964.3   dbarbosa        8/27 13:49   0+04:14:31 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002964.5   dbarbosa        8/27 13:49   0+04:14:29 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_5.sh
73002964.6   dbarbosa        8/27 13:49   0+04:14:07 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_6.sh
73002964.7   dbarbosa        8/27 13:49   0+04:14:07 R  0   254.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_7.sh
73002964.8   dbarbosa        8/27 13:49   0+04:14:06 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_8.sh
73002965.2   dbarbosa        8/27 13:49   0+04:13:41 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002965.4   dbarbosa        8/27 13:49   0+04:13:43 R  0   249.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_4.sh

Total for query: 112 jobs; 0 completed, 0 removed, 0 idle, 112 running, 0 held, 0 suspended 
Total for dbarbosa: 112 jobs; 0 completed, 0 removed, 0 idle, 112 running, 0 held, 0 suspended 
Total for all users: 5689 jobs; 0 completed, 31 removed, 4034 idle, 1588 running, 36 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 18:27:42
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 3982 jobs; 0 completed, 114 removed, 2127 idle, 1670 running, 71 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 18:27:42
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 4767 jobs; 0 completed, 0 removed, 2556 idle, 1112 running, 1099 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 18:27:42
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+04:43:27 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.2   dbarbosa        8/27 13:43   0+04:43:25 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+04:43:26 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+04:43:29 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+04:43:25 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+04:43:27 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+04:43:31 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.8   dbarbosa        8/27 13:43   0+04:43:27 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_8.sh
73002957.9   dbarbosa        8/27 13:43   0+04:43:29 R  0   279.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+04:43:29 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+04:43:31 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.13  dbarbosa        8/27 13:43   0+04:43:29 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_13.sh
73002957.14  dbarbosa        8/27 13:43   0+04:43:27 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.15  dbarbosa        8/27 13:43   0+04:43:30 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_15.sh
73002957.16  dbarbosa        8/27 13:43   0+04:43:29 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+04:43:07 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+04:43:07 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+04:43:08 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+04:43:06 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+04:43:06 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.22  dbarbosa        8/27 13:43   0+04:43:06 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_22.sh
73002957.23  dbarbosa        8/27 13:43   0+04:43:06 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_23.sh
73002957.24  dbarbosa        8/27 13:43   0+04:43:06 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+04:43:04 R  0   263.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+04:43:04 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+04:43:04 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+04:43:04 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+04:42:44 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+04:42:42 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+04:42:42 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.32  dbarbosa        8/27 13:43   0+04:42:42 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_32.sh
73002957.33  dbarbosa        8/27 13:43   0+04:42:42 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+04:42:40 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.35  dbarbosa        8/27 13:43   0+04:42:42 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_35.sh
73002957.36  dbarbosa        8/27 13:43   0+04:42:40 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+04:42:40 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+04:42:19 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+04:42:15 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.40  dbarbosa        8/27 13:43   0+04:42:19 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_40.sh
73002957.41  dbarbosa        8/27 13:43   0+04:42:16 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+04:42:15 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+04:42:12 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+04:42:18 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.45  dbarbosa        8/27 13:43   0+04:42:18 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_45.sh
73002957.46  dbarbosa        8/27 13:43   0+04:42:18 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+04:42:18 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.48  dbarbosa        8/27 13:43   0+04:42:18 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_48.sh
73002957.49  dbarbosa        8/27 13:43   0+04:42:16 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_49.sh
73002957.50  dbarbosa        8/27 13:43   0+04:42:16 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_50.sh
73002957.51  dbarbosa        8/27 13:43   0+04:41:52 R  0   279.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+04:41:55 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+04:41:55 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+04:41:54 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.55  dbarbosa        8/27 13:43   0+04:41:55 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_55.sh
73002957.56  dbarbosa        8/27 13:43   0+04:41:55 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+04:41:54 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.1   dbarbosa        8/27 13:43   0+04:41:54 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002958.2   dbarbosa        8/27 13:43   0+04:41:54 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+04:41:31 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+04:41:31 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+04:41:26 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+04:41:29 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+04:41:31 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+04:41:31 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.9   dbarbosa        8/27 13:43   0+04:41:31 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_9.sh
73002958.10  dbarbosa        8/27 13:43   0+04:41:29 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_10.sh
73002958.11  dbarbosa        8/27 13:43   0+04:41:29 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+04:41:29 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+04:41:28 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+04:41:27 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+04:41:27 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+04:41:27 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+04:41:27 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+04:41:25 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+04:41:25 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+04:41:25 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.21  dbarbosa        8/27 13:43   0+04:41:07 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_21.sh
73002958.22  dbarbosa        8/27 13:43   0+04:41:04 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+04:41:04 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+04:41:05 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.28  dbarbosa        8/27 13:43   0+04:41:06 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_28.sh
73002958.29  dbarbosa        8/27 13:43   0+04:41:06 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+04:41:04 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002959.0   dbarbosa        8/27 13:49   0+04:38:23 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.1   dbarbosa        8/27 13:49   0+04:38:22 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002959.3   dbarbosa        8/27 13:49   0+04:38:21 R  0   258.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002959.4   dbarbosa        8/27 13:49   0+04:38:21 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002959.5   dbarbosa        8/27 13:49   0+04:38:21 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002959.8   dbarbosa        8/27 13:49   0+04:38:19 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002961.2   dbarbosa        8/27 13:49   0+04:37:57 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.4   dbarbosa        8/27 13:49   0+04:37:55 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+04:37:57 R  0   261.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+04:37:57 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+04:37:56 R  0   253.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+04:37:55 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+04:37:55 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.4   dbarbosa        8/27 13:49   0+04:37:52 R  0   257.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002962.5   dbarbosa        8/27 13:49   0+04:37:52 R  0   262.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002962.7   dbarbosa        8/27 13:49   0+04:37:51 R  0   256.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.8   dbarbosa        8/27 13:49   0+04:37:51 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002964.0   dbarbosa        8/27 13:49   0+04:37:32 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_0.sh
73002964.2   dbarbosa        8/27 13:49   0+04:37:34 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002964.3   dbarbosa        8/27 13:49   0+04:37:34 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_3.sh
73002964.5   dbarbosa        8/27 13:49   0+04:37:32 R  0   259.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_5.sh
73002964.6   dbarbosa        8/27 13:49   0+04:37:10 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_6.sh
73002964.8   dbarbosa        8/27 13:49   0+04:37:09 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_8.sh
73002965.2   dbarbosa        8/27 13:49   0+04:36:44 R  0   255.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_2.sh
73002965.4   dbarbosa        8/27 13:49   0+04:36:46 R  0   252.0 wrapper.sh run_DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeVMLM_TeV_MG_MC_4.sh

Total for query: 108 jobs; 0 completed, 0 removed, 0 idle, 108 running, 0 held, 0 suspended 
Total for dbarbosa: 108 jobs; 0 completed, 0 removed, 0 idle, 108 running, 0 held, 0 suspended 
Total for all users: 3799 jobs; 0 completed, 30 removed, 2154 idle, 1577 running, 38 held, 0 suspended

[dbarbosa@cmslpc139 ~]$ condor_q


-- Schedd: lpcschedd1.fnal.gov : <131.225.188.55:9618?... @ 08/27/21 20:11:34
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 2048 jobs; 0 completed, 114 removed, 500 idle, 1362 running, 72 held, 0 suspended



-- Schedd: lpcschedd2.fnal.gov : <131.225.188.57:9618?... @ 08/27/21 20:11:34
 ID      OWNER            SUBMITTED     RUN_TIME ST PRI SIZE CMD

Total for query: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for dbarbosa: 0 jobs; 0 completed, 0 removed, 0 idle, 0 running, 0 held, 0 suspended 
Total for all users: 3507 jobs; 0 completed, 0 removed, 942 idle, 1397 running, 1168 held, 0 suspended



-- Schedd: lpcschedd3.fnal.gov : <131.225.188.235:9618?... @ 08/27/21 20:11:34
 ID          OWNER            SUBMITTED     RUN_TIME ST PRI SIZE  CMD
73002957.0   dbarbosa        8/27 13:43   0+06:27:18 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_0.sh
73002957.2   dbarbosa        8/27 13:43   0+06:27:16 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_2.sh
73002957.3   dbarbosa        8/27 13:43   0+06:27:17 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_3.sh
73002957.4   dbarbosa        8/27 13:43   0+06:27:20 R  0   292.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_4.sh
73002957.5   dbarbosa        8/27 13:43   0+06:27:16 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_5.sh
73002957.6   dbarbosa        8/27 13:43   0+06:27:18 R  0   274.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_6.sh
73002957.7   dbarbosa        8/27 13:43   0+06:27:22 R  0   291.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_7.sh
73002957.9   dbarbosa        8/27 13:43   0+06:27:20 R  0   293.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_9.sh
73002957.10  dbarbosa        8/27 13:43   0+06:27:20 R  0   293.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_10.sh
73002957.11  dbarbosa        8/27 13:43   0+06:27:22 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_11.sh
73002957.14  dbarbosa        8/27 13:43   0+06:27:18 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_14.sh
73002957.16  dbarbosa        8/27 13:43   0+06:27:20 R  0   280.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_16.sh
73002957.17  dbarbosa        8/27 13:43   0+06:26:58 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_17.sh
73002957.18  dbarbosa        8/27 13:43   0+06:26:58 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_18.sh
73002957.19  dbarbosa        8/27 13:43   0+06:26:59 R  0   292.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_19.sh
73002957.20  dbarbosa        8/27 13:43   0+06:26:57 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_20.sh
73002957.21  dbarbosa        8/27 13:43   0+06:26:57 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_21.sh
73002957.24  dbarbosa        8/27 13:43   0+06:26:57 R  0   287.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_24.sh
73002957.25  dbarbosa        8/27 13:43   0+06:26:55 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_25.sh
73002957.26  dbarbosa        8/27 13:43   0+06:26:55 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_26.sh
73002957.27  dbarbosa        8/27 13:43   0+06:26:55 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_27.sh
73002957.28  dbarbosa        8/27 13:43   0+06:26:55 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_28.sh
73002957.29  dbarbosa        8/27 13:43   0+06:26:35 R  0   292.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_29.sh
73002957.30  dbarbosa        8/27 13:43   0+06:26:33 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_30.sh
73002957.31  dbarbosa        8/27 13:43   0+06:26:33 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_31.sh
73002957.33  dbarbosa        8/27 13:43   0+06:26:33 R  0   292.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_33.sh
73002957.34  dbarbosa        8/27 13:43   0+06:26:31 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_34.sh
73002957.36  dbarbosa        8/27 13:43   0+06:26:31 R  0   276.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_36.sh
73002957.37  dbarbosa        8/27 13:43   0+06:26:31 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_37.sh
73002957.38  dbarbosa        8/27 13:43   0+06:26:10 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_38.sh
73002957.39  dbarbosa        8/27 13:43   0+06:26:06 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_39.sh
73002957.41  dbarbosa        8/27 13:43   0+06:26:07 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_41.sh
73002957.42  dbarbosa        8/27 13:43   0+06:26:06 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_42.sh
73002957.43  dbarbosa        8/27 13:43   0+06:26:03 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_43.sh
73002957.44  dbarbosa        8/27 13:43   0+06:26:09 R  0   267.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_44.sh
73002957.46  dbarbosa        8/27 13:43   0+06:26:09 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_46.sh
73002957.47  dbarbosa        8/27 13:43   0+06:26:09 R  0   291.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_47.sh
73002957.51  dbarbosa        8/27 13:43   0+06:25:43 R  0   293.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_51.sh
73002957.52  dbarbosa        8/27 13:43   0+06:25:46 R  0   286.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_52.sh
73002957.53  dbarbosa        8/27 13:43   0+06:25:46 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_53.sh
73002957.54  dbarbosa        8/27 13:43   0+06:25:45 R  0   292.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_54.sh
73002957.56  dbarbosa        8/27 13:43   0+06:25:46 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext2_MG_MC_56.sh
73002958.0   dbarbosa        8/27 13:43   0+06:25:45 R  0   291.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002958.2   dbarbosa        8/27 13:43   0+06:25:45 R  0   291.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002958.3   dbarbosa        8/27 13:43   0+06:25:23 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002958.4   dbarbosa        8/27 13:43   0+06:25:23 R  0   291.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002958.5   dbarbosa        8/27 13:43   0+06:25:18 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002958.6   dbarbosa        8/27 13:43   0+06:25:21 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002958.7   dbarbosa        8/27 13:43   0+06:25:23 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002958.8   dbarbosa        8/27 13:43   0+06:25:23 R  0   290.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_8.sh
73002958.11  dbarbosa        8/27 13:43   0+06:25:21 R  0   275.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_11.sh
73002958.12  dbarbosa        8/27 13:43   0+06:25:21 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_12.sh
73002958.13  dbarbosa        8/27 13:43   0+06:25:20 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_13.sh
73002958.14  dbarbosa        8/27 13:43   0+06:25:19 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_14.sh
73002958.15  dbarbosa        8/27 13:43   0+06:25:19 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_15.sh
73002958.16  dbarbosa        8/27 13:43   0+06:25:19 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_16.sh
73002958.17  dbarbosa        8/27 13:43   0+06:25:19 R  0   278.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_17.sh
73002958.18  dbarbosa        8/27 13:43   0+06:25:17 R  0   273.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_18.sh
73002958.19  dbarbosa        8/27 13:43   0+06:25:17 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_19.sh
73002958.20  dbarbosa        8/27 13:43   0+06:25:17 R  0   272.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_20.sh
73002958.22  dbarbosa        8/27 13:43   0+06:24:56 R  0   268.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_22.sh
73002958.23  dbarbosa        8/27 13:43   0+06:24:56 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_23.sh
73002958.25  dbarbosa        8/27 13:43   0+06:24:57 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_25.sh
73002958.29  dbarbosa        8/27 13:43   0+06:24:58 R  0   288.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_29.sh
73002958.30  dbarbosa        8/27 13:43   0+06:24:56 R  0   289.0 wrapper.sh run_DYJetsToLL_M-50_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_30.sh
73002959.0   dbarbosa        8/27 13:49   0+06:22:15 R  0   271.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002959.3   dbarbosa        8/27 13:49   0+06:22:13 R  0   266.0 wrapper.sh run_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_3.sh
73002961.2   dbarbosa        8/27 13:49   0+06:21:49 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_2.sh
73002961.4   dbarbosa        8/27 13:49   0+06:21:47 R  0   264.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh
73002961.5   dbarbosa        8/27 13:49   0+06:21:49 R  0   269.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_5.sh
73002961.6   dbarbosa        8/27 13:49   0+06:21:49 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_6.sh
73002961.7   dbarbosa        8/27 13:49   0+06:21:48 R  0   260.0 wrapper.sh run_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_7.sh
73002962.0   dbarbosa        8/27 13:49   0+06:21:47 R  0   270.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_0.sh
73002962.1   dbarbosa        8/27 13:49   0+06:21:47 R  0   277.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_1.sh
73002962.4   dbarbosa        8/27 13:49   0+06:21:44 R  0   265.0 wrapper.sh run_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeVMLM_TeV_ext1_MG_MC_4.sh


