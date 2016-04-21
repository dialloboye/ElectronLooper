from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'ElectronLooper_test'
config.General.workArea = './'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'pset.py'
config.JobType.scriptExe = 'crabWrapper.sh'
config.JobType.inputFiles = ['FrameworkJobReport.xml','ElectronLooper.exe', 'goodruns.txt', 'mc_small.txt', 'mc.txt', 'data.txt']
config.JobType.outputFiles = ['ntuple.root']

config.Data.userInputFiles = open('mc_small.txt').readlines()
config.Data.outputPrimaryDataset = 'ElectronLooper_test'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.publication = False
config.Data.outputDatasetTag = 'ElectronLooper_test'

config.Site.storageSite = '/afs/cern.ch/work/d/diboye/essai/CMSSW_7_6_3/src/ElectronLooper/t2/store/data/boyedata'
config.Site.whitelist = ['T2_US_*']
