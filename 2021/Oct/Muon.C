***NRecoVertex                  1   -1   ///at least one good vertex
***NRecoTriggers1               1   -1   ///events must fire the HLT_IsoMu24 trigger
***NRecoElectron1               0    0
***NRecoMuon1                   1    1
***NRecoTau1                    1    1
***NRecoBJet                    0    0
***NMuon1Tau1Combinations       1    1
***NDiJetCombinations           0    0

//----RECO CUTS----//

EtaCut 2.1
PtCut 35.0 9999.9

DoDiscrByTightID 1
DoDiscrBySoftID 0

DoDiscrByIsolation 1
IsoSumPtCutValue 0.0 0.15

//----MET TOPOLOGY CUTS----//

DiscrIfIsZdecay 0

DiscrByMetDphi 0
MetDphiCut 1.0 3.15

DiscrByMetMt 0
MetMtCut 0. 100.




DiscrByDeltaR    1
DeltaRCut        0.3
DiscrByOSLSType  OS
DiscrByCosDphi   1      # dPhi is calculated between Muon1 and Tau1 
CosDphiCut      -1.00   -0.98

DiscrByCosDphi_DeltaPtAndMet   false
CosDphi_DeltaPtMetCut          0.8  1.0
DiscrByMassReco            0
HowCalculateMassReco       none     ###VectorSumOfVisProductsAndMet   or    CollinearApprox 
MassCut                    0.0   200.0
DiscrByCDFzeta2D           0
PZetaCutCoefficient        1.0
PZetaVisCutCoefficient    -3.1
CDFzeta2DCutValue         -50.0    1000
DiscrByDeltaPtDivSumPt     0
DeltaPtDivSumPtCutValue    0.1  1.0
DiscrByDeltaPt             0
DeltaPtCutValue            30.0   1000.0
DiscrByCosDphiPtAndMet     0     # dPhi between Muon1 and MET
CosDphiPtAndMetCut        -1.00 -0.90

# dPhi between leading lepton in the combination and MET
DiscrByCosDphiLeadPtAndMet      1
CosDphiLeadPtAndMetCut         -1.00 -0.95
DiscrByAbsCosDphiLeadPtandMet   0
AbsCosDphiLeadPtAndMetCut       0.90  1.00
DiscrByMtLeadPtAndMet           1
MtLeadPtAndMetCut               0.0  150.0
DiscrByDiLepMassDeltaPt         0
DiLeadMassDeltaPtCut            0.0   9999.0


