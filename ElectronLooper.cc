#include <fstream>
#include <iostream>

#include "CMS2.h"
#include "goodrun.h"
#include "electronSelections.h"
#include "eventSelections.h"

using namespace std;
using namespace tas;
using namespace wp2012;

int main(int argc, char** argv) {
//void ElectronLooper(TString inputList) {
// PassAllWP2012Cuts

  enum Classification { UNKNOWN=-1, GOLDEN=0, BIGBREM=1, BADTRACK=2, SHOWERING=3, GAP=4 } ;

  TString reader;
  ifstream fileReader(argv[1]);

  TFile* outputFile = TFile::Open("ntuple.root", "recreate");
  TTree* redTree = new TTree ("redTree","a small Tree");
   /*------------------------------ this is for the mass---------------------------------------------------------------------------------------------*/
   //Float_t dielectron_mass;
  //  Float_t dielectron_mass,dielectron_mass_lowfbrem,dielectron_mass_onecluster,dielectron_mass_golden;
  // RCLSA: this is a tree, not a histogram
  LorentzVector electron0_p4;
  LorentzVector electron1_p4;
  LorentzVector dielectron_p4;
  LorentzVector electronSC0_p4;
  LorentzVector electronSC1_p4;
  int           electron0_class;
  int           electron1_class;
  float         electron0_fbrem;
  float         electron1_fbrem;
  float         electron0_eSC;
  float         electron1_eSC;
  float         electron0_z0;
  float         electron1_z0;
  float         electron0_lostHits;
  float         electron1_lostHits;
  float         electron0_ecalEnergy;
  float         electron1_ecalEnergy;
  float         electron0_eSCPresh;
  float         electron1_eSCPresh;
  float         electron0_HoE;
  float         electron1_HoE;
  float         electron0_dEtaIn;
  float         electron1_dEtaIn;
  float         electron0_dEtaOut;
  float         electron1_dEtaOut;
  float         electron0_dPhiIn;
  float         electron1_dPhiIn;
  float         electron0_dPhiOut;
  float         electron1_dPhiOut;
  float         electron0_r9;
  float         electron1_r9;
  int           electron0_charge;
  int           electron1_charge;
  float         electron0_sigmaEtaEta;
  float         electron1_sigmaEtaEta;
  float         electron0_sigmaPhiPhi;
  float         electron1_sigmaPhiPhi;
  float         electron0_etaSC;
  float         electron1_etaSC;
  float         electron0_nSeed;
  float         electron1_nSeed;
  float         electron0_eOverPIn;
  float         electron1_eOverPIn;
  float         electron0_eOverPOut;
  float         electron1_eOverPOut;
  float         electron0_ip3d;
  float         electron1_ip3d;
  float         electron0_eSeed;
  float         electron1_eSeed;
  float         eletrcon0_phiSC;
  float         eletrcon1_phiSC;
  float         electron0_trkIso;
  float         electron1_trkIso;
  float         electron0_trkIso04;
  float         electron1_trkIso04;
  float         electron0_d0;
  float         electron1_d0;
  float         scs0_eta;
  float         scs1_eta;
  float         dielectron_mass;
  float         dielectron_pt;
  float         dielectronSC_mass;
  float         dielectronSC_pt;
  float         scale1fb;
  int           run;
  int           event;
  int           lumi;


 
  // redTree->Branch("scs0_eta",            &scs0);
 redTree->Branch("electron1_lostHits",            &electron1_lostHits);
 redTree->Branch("electron0_lostHits",            &electron0_lostHits);
 redTree->Branch("electron1_lostHits",            &electron1_lostHits);
 redTree->Branch("electron0_dPhiIn",              &electron0_dPhiIn);
 redTree->Branch("electron1_dPhiIn",              &electron1_dPhiIn);
 redTree->Branch("electron0_z0",                  &electron0_z0);
 redTree->Branch("electron1_z0",                  &electron1_z0);
 redTree->Branch("electron0_dEtaIn",              &electron0_dEtaIn);
 redTree->Branch("electron1_dEtaIn",              &electron1_dEtaIn);
 redTree->Branch("electron0_dEtaOut",             &electron0_dEtaOut);
 redTree->Branch("electron1_dEtaOut",             &electron1_dEtaOut);
 redTree->Branch("electron0_d0",                  &electron0_d0);
 redTree->Branch("electron1_d0",                  &electron1_d0);
 redTree->Branch("electron0_trkIso",              &electron0_trkIso);
 redTree->Branch("electron1_trkIso",              &electron1_trkIso);
 redTree->Branch("electron0_trkIso",              &electron0_trkIso04);
 redTree->Branch("electron1_trkIso",              &electron1_trkIso04);
 redTree->Branch("eletrcon0_phiSC",               &eletrcon0_phiSC);
 redTree->Branch("eletrcon1_phiSC",               &eletrcon1_phiSC);
 redTree->Branch("electron0_ip3d",                &electron0_ip3d);
 redTree->Branch("electron1_ip3d",                &electron1_ip3d);
 redTree->Branch("electron0_eSeed",               &electron0_eSeed);
 redTree->Branch("electron1_eSeed",               &electron1_eSeed);
 redTree->Branch("electron0_eOverPIn",            &electron0_eOverPIn);
 redTree->Branch("electron1_eOverPIn",            &electron1_eOverPIn);
 redTree->Branch("electron0_eOverPOut",           &electron0_eOverPOut);
 redTree->Branch("electron1_eOverPOut",           &electron1_eOverPOut);
 redTree->Branch("electron0_etaSC",               &electron0_etaSC);
 redTree->Branch("electron1_etaSC",               &electron1_etaSC);
 redTree->Branch("electron0_ecalEnergy",          &electron0_ecalEnergy);
 redTree->Branch("electron1_ecalEnergy",          &electron1_ecalEnergy);
 redTree->Branch("electron0_eSCPresh",            &electron0_eSCPresh);
 redTree->Branch("electron1_eSCPresh",            &electron1_eSCPresh);
 redTree->Branch("electron0_sigmaPhiPhi",         &electron0_sigmaPhiPhi);
 redTree->Branch("electron1_sigmaPhiPhi",         &electron1_sigmaPhiPhi);
 redTree->Branch("electron0_sigmaEtaEta",         &electron0_sigmaEtaEta);
 redTree->Branch("electron1_sigmaEtaEta",         &electron1_sigmaEtaEta);
 redTree->Branch("electron0_nSeed",               &electron0_nSeed);
 redTree->Branch("electron1_nSeed",               &electron1_nSeed);
 redTree->Branch("electron0_r9",                  &electron0_r9);
 redTree->Branch("electron1_r9",                  &electron1_r9);
 redTree->Branch("electron0_HoE",                 &electron0_HoE);
 redTree->Branch("electron1_HoE",                 &electron1_HoE);
 redTree->Branch("electron0_eSC",                 &electron0_eSC);
 redTree->Branch("electron1_eSC",                 &electron1_eSC);
 redTree->Branch("electron0_p4",                  &electron0_p4);
 redTree->Branch("electron1_p4",                  &electron1_p4);
 redTree->Branch("electronSC0_p4",                &electronSC0_p4);
 redTree->Branch("electronSC1_p4",                &electronSC1_p4);
 redTree->Branch("dielectron_p4",                 &dielectron_p4);
 redTree->Branch("electron0_class",               &electron0_class);
 redTree->Branch("electron1_class",               &electron1_class);
 redTree->Branch("electron0_fbrem",               &electron0_fbrem);
 redTree->Branch("electron1_fbrem",               &electron1_fbrem);
 redTree->Branch("dielectron_mass",               &dielectron_mass);
 redTree->Branch("dielectron_pt",                 &dielectron_pt);
 redTree->Branch("electron0_charge",              &electron0_charge);
 redTree->Branch("electron1_charge",              &electron1_charge);
 redTree->Branch("scale1fb",                      &scale1fb);
 redTree->Branch("run",                           &run);
 redTree->Branch("event",                         &event);
 redTree->Branch("lumi",                          &lumi);

  
 
 set_goodrun_file("goodruns.txt");
  
  while (!fileReader.eof()) {

    reader.ReadLine(fileReader);
    if (reader.Length() < 2) continue;
    cout << "Opening file " << reader.Data() << endl;

    TFile* fileHandle = TFile::Open(reader);
    TTree* treeHandle = static_cast<TTree*>(fileHandle->Get("Events"));
    Long64_t nentries = treeHandle->GetEntries();
    
    cms2.Init(treeHandle);
    for (Long64_t ientry = 0; ientry < nentries; ientry++) {
      CMS2::progress(ientry,nentries);
      cms2.GetEntry(ientry);
     
      // clean up data
      if (!cleaning_goodVertexApril2011()) continue;
      if( evt_isRealData() && !goodrun(evt_run(), evt_lumiBlock()) ) continue;

      electron0_p4 = LorentzVector(0,0,0,0);
      electron1_p4 = LorentzVector(0,0,0,0);
      electronSC0_p4 = LorentzVector(0,0,0,0);
      electronSC1_p4 = LorentzVector(0,0,0,0);
      
      electron0_class            = -999;
      electron1_class            = -999;
      electron0_fbrem            = -999.;
      electron1_fbrem            = -999.;
      electron0_z0               = -999.;
      electron1_z0               = -999.;
      electron0_eSC              = -999.;
      electron1_eSC              = -999.;
      electron0_ecalEnergy       = -999.;
      electron1_ecalEnergy       = -999.;
      electron0_eSCPresh         = -999.;
      electron1_eSCPresh         = -999.;
      electron0_dEtaIn           = -999.;
      electron1_dEtaIn           = -999.;
      electron0_dEtaOut          = -999.;
      electron1_dEtaOut          = -999.;
      electron0_dPhiIn           = -999.;
      electron1_dPhiIn           = -999.;
      electron0_dPhiOut          = -999.;
      electron1_dPhiOut          = -999.;
      electron0_HoE              = -999.;
      electron1_HoE              = -999.;
      electron0_r9               = -999.;
      electron1_r9               = -999.;
      electron0_charge           = -999;
      electron1_charge           = -999;
      electron0_sigmaEtaEta      = -999.;
      electron1_sigmaEtaEta      = -999.;
      electron0_sigmaPhiPhi      = -999.;
      electron1_sigmaPhiPhi      = -999.;
      electron0_nSeed            = -999.;
      electron1_nSeed            = -999.;
      electron0_etaSC            = -999.;
      electron1_etaSC            = -999.;
      electron0_eOverPIn         = -999.;
      electron1_eOverPIn         = -999.;
      electron0_eOverPOut        = -999.;
      electron1_eOverPOut        = -999.;
      electron0_eSeed            = -999.;
      electron1_eSeed            = -999.;
      electron0_trkIso           = -999.;
      electron1_trkIso           = -999.;
      electron0_d0               = -999.;
      electron1_d0               = -999.;
      electron0_lostHits         = - 999.;
      electron1_lostHits         = - 999.;
      electron0_trkIso04         = -999.;
      electron1_trkIso04         = -999.;
      eletrcon0_phiSC            = -999.;
      eletrcon1_phiSC            = -999.;
      electron0_ip3d             = -999.;
      electron1_ip3d             = -999.;
      scale1fb                   = -999.;
      run                        = -999;
      event                      = -999;
      lumi                       = -999;

 

      int electron0_idx = -1;
      int electron1_idx = -1;
      
      // Analysis selection
      for (int ielec=0; ielec<els_p4().size(); ielec++) {
	if ((electronId_WP2012_v3(ielec, TIGHT) == PassAllWP2012Cuts) && electron0_idx < 0) electron0_idx = ielec;
	else if ((electronId_WP2012_v3(ielec, TIGHT) == PassAllWP2012Cuts) && electron0_idx >= 0 && electron1_idx < 0) electron1_idx = ielec;
      }

      if (electron0_idx < 0 || electron1_idx < 0) continue;

      electron0_p4          = els_p4().at(electron0_idx);
      electron1_p4          = els_p4().at(electron1_idx);
      dielectron_p4         = electron0_p4+electron1_p4;
      dielectron_mass       = dielectron_p4.mass();
      dielectron_pt         = dielectron_p4.pt();
      electron0_class       = els_class().at(electron0_idx);
      electron1_class       = els_class().at(electron1_idx);
      electron0_fbrem       = els_fbrem().at(electron0_idx);
      electron1_fbrem       = els_fbrem().at(electron1_idx);
      electron0_fbrem       = els_fbrem().at(electron0_idx);
      electron1_fbrem       = els_fbrem().at(electron1_idx);
      electron0_eSC         = els_eSC().at(electron0_idx); 
      electron1_eSC         = els_eSC().at(electron1_idx);
      electron0_ecalEnergy  = els_ecalEnergy().at(electron0_idx);
      electron1_ecalEnergy  = els_ecalEnergy().at(electron1_idx);
      electron0_eSCPresh    = els_eSCPresh().at(electron0_idx);
      electron1_eSCPresh    = els_eSCPresh().at(electron1_idx);
      electron0_HoE         = els_hOverE().at(electron0_idx);
      electron1_HoE         = els_hOverE().at(electron1_idx);
      electron0_sigmaEtaEta = els_sigmaEtaEta().at(electron0_idx);
      electron1_sigmaEtaEta = els_sigmaEtaEta().at(electron1_idx);
      electron0_sigmaPhiPhi = els_sigmaPhiPhi().at(electron0_idx);
      electron1_sigmaPhiPhi = els_sigmaPhiPhi().at(electron1_idx);
      electron0_charge      = els_charge().at(electron0_idx);
      electron1_charge      = els_charge().at(electron1_idx);
      electron0_r9          = els_r9().at(electron0_idx);
      electron1_r9          = els_r9().at(electron1_idx);
      electron0_etaSC       = els_etaSC().at(electron0_idx);
      electron1_etaSC       = els_etaSC().at(electron1_idx);
      electron0_eOverPIn    = els_eOverPIn().at(electron0_idx);
      electron1_eOverPIn    = els_eOverPIn().at(electron1_idx);
      electron0_eOverPOut   = els_eOverPOut().at(electron0_idx);
      electron1_eOverPOut   = els_eOverPOut().at(electron1_idx);
      electron0_eSeed       = els_eSeed().at(electron0_idx);
      electron1_eSeed       = els_eSeed().at(electron1_idx);
      electron0_nSeed       = els_nSeed().at(electron0_idx);
      electron1_nSeed       = els_nSeed().at(electron1_idx);
      electron0_ip3d        = els_ip3d().at(electron0_idx);
      electron1_ip3d        = els_ip3d().at(electron1_idx);
      eletrcon0_phiSC       = els_phiSC().at(electron0_idx);
      eletrcon1_phiSC       = els_phiSC().at(electron1_idx);
      electron0_trkIso      = els_tkIso04().at(electron0_idx);
      electron1_trkIso      = els_tkIso04().at(electron1_idx);
      electron0_trkIso      = els_tkIso().at(electron0_idx);
      electron1_trkIso      = els_tkIso().at(electron1_idx);
      electron0_d0          = els_d0().at(electron0_idx);
      electron1_d0          = els_d0().at(electron1_idx);
      electron0_z0          = els_z0().at(electron0_idx);
      electron1_z0          = els_z0().at(electron1_idx);
      electron0_dEtaIn      = els_dEtaIn().at(electron0_idx);
      electron1_dEtaIn      = els_dEtaIn().at(electron1_idx);
      electron0_dEtaOut     = els_dEtaOut().at(electron0_idx);
      electron1_dEtaOut     = els_dEtaOut().at(electron1_idx);
      electron0_dPhiIn      = els_dPhiIn().at(electron0_idx);
      electron1_dPhiIn      = els_dPhiIn().at(electron1_idx);
      electron0_dPhiOut     = els_dPhiOut().at(electron0_idx);
      electron1_dPhiOut     = els_dPhiOut().at(electron1_idx);
      electron0_lostHits    = els_lostHits().at(electron0_idx);
      electron1_lostHits    = els_lostHits().at(electron1_idx);
      scale1fb              = evt_scale1fb();
      run                   = evt_run();
      event                 = evt_event();
      lumi                  = evt_lumiBlock();
      
      
      redTree->Fill();
      
    }
  }

  outputFile->cd();
  redTree->Write();
  outputFile->Close();
  
}
