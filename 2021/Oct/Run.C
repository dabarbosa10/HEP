####################################

CalculatePUSystematics true
DataHistos PileUpReweighting2018.root       # 2016: PileUpReweighting2016.root, 2017: PileUpReweighting2017.root, 2018: PileUpReweighting2018.root
MCHistos mc2018_pileup_Dec2018reReco.root   # 2016: mc2016_pileup_Dec2018reReco.root, 2017: mc2017_pileup_Dec2018reReco.root, 2018: 2016: mc2018_pileup_Dec2018reReco.root
DataPUHistName pileup
MCPUHistName pileup

# SpecialMCPUCalculation false
# SpecialMCPUHistos new_mc2017_pileupReweighting_NanoAODv6.root
# SpecialMCPUHistos new_mc2017_pileupReweighting_NanoAODv6_wanddylo_incl.root

ApplyTauIDSF true
TauIdSFsByDM false # Tau ID scale factors that are decay mode (DM) - dependent. If using di-tau triggers and tau-pt > 40 GeV, this are the recommended SFs.
TauSFforEmbeddedSamples false

ApplyTauAntiEleSF true
ApplyTauAntiMuSF true

UsePileUpWeight true
ApplyNPVWeight false

ApplyISRZBoostSF false # Z-boost weight corrections derived for ISR+stau analysis (SUS-19-002)
ApplySUSYZBoostSF false # Official Z-boost weight corrections derived by the SUSY PAG.
ApplyVBFSusyZBoostSF false # Weights derived by the VBF SUSY team - Run II

isData false
ApplyGenWeight true

ApplyL1PrefiringWeight true

/// ------ Data-specific cuts ------///
FilterDataByGoldenJSON true
ApplyHEMVeto2018 true

/// ------ MC Gen-level cuts ------///
/// --- HT filter --- ///
DiscrByGenHT true
LowerGenHtCut 0.0
UpperGenHtCut 100.0

/// --- dilepton mass filter --- ///
DiscrByGenDileptonMass false
GenDilepMassRange 0.0 500.0
