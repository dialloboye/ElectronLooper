import FWCore.ParameterSet.Config as cms

process = cms.Process("PickEvent")

process.source = cms.Source ("PoolSource",
        fileNames = cms.untracked.vstring(),
        duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)

