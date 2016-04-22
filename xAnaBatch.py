#!/usr/bin/env python

import sys,os
import commands
import shutil
import commonBatch


from optparse import OptionParser
parser = OptionParser()
parser.add_option("-c", "--config"      , default='thereIsNoConfigFile.config', dest="configFile")
parser.add_option("-o", "--outputDir"   , default='notSpecified' , dest="outputDir")
parser.add_option("-d", "--dry_run"     , default=False  , action="store_true", dest="dry_run")
parser.add_option("-i", "--interactive" , default=False  , action="store_true", dest="interactive")

(options, args) = parser.parse_args()
######################################################################################################
datasetsData = []
datasetsMC   = []


###### define data datasets
dataRun8TeV = { 'name' : 'run8TeV', 'filelist' : 'mc.txt', 'split': 4, 'mcinfo': None }
datasetsData.append(dataRun8TeV)

print datasetsData
datasets = datasetsData

#commonBatch.fileSplitter(datasetsData[0],commonBatch.dirForFileSplit)

#if not options.hadd:
commonBatch.submitJob( datasets, options, commonBatch.dirScriptBatch ) 
#else:
#    if options.outputDir == 'notSpecified':
#        print 'Need to specify the option outputDir (-o)'
#        sys.exit(0)
#    for dataset in datasets:
#        print '*** hadd dataset %s ' % dataset['name']
#        os.system( 'hadd %s/%s.hadd.root %s/%s.*.root' % (options.outputDir,dataset['name'],
#                                                          options.outputDir,dataset['name']) )
    
