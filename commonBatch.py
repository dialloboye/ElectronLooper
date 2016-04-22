#!/usr/bin/env python

import os
import shutil
import subprocess


dirAFS = os.getcwd()
dirScriptBatch  = '%s/tmpBatchOut_PythonSub/' % dirAFS
dirForFileSplit = 'tmp/fileSplittingDir/';


bsuboptions    = "-q 8nh"


def prepareGridCert():
    if not os.path.exists(dirScriptBatch):
        print " mkdir ",dirScriptBatch
        os.mkdir( dirScriptBatch )
    
#    u = commands.getoutput('voms-proxy-init')
    userid = os.environ['KRB5CCNAME'].split('_')[1]
    pathToGridCert='/tmp/x509up_u%s' % userid
    gridCert = os.path.basename(pathToGridCert)
    shutil.copy(pathToGridCert,dirScriptBatch)
    pathToGridCert = '%s/%s' % (dirScriptBatch,gridCert)
    return pathToGridCert

pathToGridCert = prepareGridCert()


def fileSplitter(dataset,outDir):
    input = open( dataset['filelist'], 'r')
    splitLen = dataset['split']
    count = 0
    at = 0
    dest = None
    if not os.path.exists(outDir):
        os.mkdir(outDir)
    inFileList = []
    for line in input:
        if count % splitLen == 0:
            if dest: dest.close()
            outfile = outDir + dataset['name'] + '.' + str(at) + '.txt'
            inFileList.append(outfile)
            dest = open( outfile, 'w')
            at += 1
        dest.write(line)
        count += 1
            
    return inFileList


def config(scriptName, configFile, filelist, mcinfo, outputDir):
    rootfilename = os.path.basename(filelist)
    cmdExe = './ElectronLooper.exe %s %s %s' % (filelist,outputDir,rootfilename)
    script = open(scriptName,'w')
    script.write('#!/bin/bash\n')
    script.write('cd %s\n'% dirAFS) 
#    script.write('source etc/scripts/setup_xAna.sh\n')
    script.write('export X509_USER_PROXY=%s\n'%pathToGridCert)
    script.write('%s\n'%cmdExe)
    script.close()
    st=os.stat(scriptName)
    os.chmod(scriptName, st.st_mode | 0o111)
 #   print os.stat(scriptName)


def bsubJob( dirScriptBatch, script, filenameJobList ):
    fileJobList = open( filenameJobList, 'a' )
    os.chdir(dirScriptBatch)
    proc = subprocess.Popen( 'bsub %s %s' % ( bsuboptions,script) , shell = True, stdout=subprocess.PIPE)
    tmp = proc.stdout.read().split(' ')
    jobid = tmp[1].split('<')[1].split('>')[0]
    fileJobList.write( '%s  %s\n' % (jobid,script) )
    fileJobList.close()
    os.chdir( dirAFS )



def submitJob(datasets, options, mainDirForScript):
    anaType = 'WmassNtupler'
    dirScriptBatch = '%s/%s_%s/' % (mainDirForScript,anaType,os.getpid())
    if not os.path.exists(dirScriptBatch): 
        os.mkdir( dirScriptBatch )

    joblistName = '%s/joblist.txt' % (dirScriptBatch)

    for dataset in datasets:
        listOfFilelist = fileSplitter(dataset,dirForFileSplit)
        for filelist in listOfFilelist:
            script = '%s/%s_%s_%s.sh'%(dirScriptBatch,os.path.basename(filelist),anaType,os.getpid())
            config( script, options.configFile, filelist,dataset['mcinfo'], options.outputDir )

            if options.dry_run:
                print script            
            else:
                if options.interactive:
                    os.system(script)
                else:
                    print "submitting script %s for filelist %s" % (script,filelist )
                    bsubJob( dirScriptBatch, script, joblistName )
               ### change directory to get output in batch dir






