#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void copyTree(TString FileName="Run012037_gtk_tp4b_1804.root",
// "Run011100_gtk_tp4b_1804.root",
// "/home/akleimen/Documents/Run009001_gtk_tp4b_3103.root", 
              TString TreeName = "GTKStudyTtree"){
  TFile oldfile(FileName);
  TTreeReader reader(TreeName, &oldfile);

  Int_t runid(0), burstid(0), evid(0), ktag_ns(0);
  UInt_t evts(0);
  Double_t iiev(0), k3pivtx_x(0), k3pivtx_y(0), k3pivtx_z(0), k3pivtx_t(0), ktag_t(0), k3pivtx_px(0), k3pivtx_py(0),k3pivtx_pz(0);
  Double_t k3pivtxgtk3_x(0), k3pivtxgtk3_y(0), k3pivtxgtk3_z(0), k3pivtxgtk3_px(0), k3pivtxgtk3_py(0), k3pivtxgtk3_pz(0);
  std::vector<Float_t> gtk3_x, gtk3_y, gtkt_t, gtkt_px, gtkt_py, gtkt_pz, gtkt_chi2;

  TFile newfile("small_tree_test.root", "recreate");
  TTree *newTree = new TTree("GTKStudyTtree","GTKStudyTtree");

  newTree->Branch("RunID", &runid);
  newTree->Branch("BurstID", &burstid);
  newTree->Branch("EventID", &evid);
  newTree->Branch("EventTS", &evts);
  newTree->Branch("InstantaneousIntensity", &iiev);
  newTree->Branch("K3piVertex_x", &k3pivtx_x);
  newTree->Branch("K3piVertex_y", &k3pivtx_y);
  newTree->Branch("K3piVertex_z", &k3pivtx_z);
  newTree->Branch("K3piVertex_t", &k3pivtx_t);
  newTree->Branch("K3piKTAG_t", &ktag_t);
  newTree->Branch("K3piKTAG_nsectors", &ktag_ns);
  newTree->Branch("K3piTotalMom_Px", &k3pivtx_px);
  newTree->Branch("K3piTotalMom_Py", &k3pivtx_py);
  newTree->Branch("K3piTotalMom_Pz", &k3pivtx_pz);
  newTree->Branch("K3piVertexGTK3_x", &k3pivtxgtk3_x);
  newTree->Branch("K3piVertexGTK3_y", &k3pivtxgtk3_y);
  newTree->Branch("K3piVertexGTK3_z", &k3pivtxgtk3_z);
  newTree->Branch("K3piTotalMomGTK3_Px", &k3pivtxgtk3_px);
  newTree->Branch("K3piTotalMomGTK3_Py", &k3pivtxgtk3_py);
  newTree->Branch("K3piTotalMomGTK3_Pz", &k3pivtxgtk3_pz);
  newTree->Branch("GTKTrackGTK3_x", &gtk3_x);
  newTree->Branch("GTKTrackGTK3_y", &gtk3_y);
  newTree->Branch("GTKTrack_t", &gtkt_t);
  newTree->Branch("GTKTrack_Px", &gtkt_px);
  newTree->Branch("GTKTrack_Py", &gtkt_py);
  newTree->Branch("GTKTrack_Pz", &gtkt_pz);
  newTree->Branch("GTKTrack_chi2", &gtkt_chi2);

  TTreeReaderValue<Int_t> rrunid(reader, "RunID");
  TTreeReaderValue<Int_t> rburstid(reader, "BurstID");
  TTreeReaderValue<Int_t> revid(reader, "EventID");
  TTreeReaderValue<UInt_t> revts(reader, "EventTS");
  TTreeReaderValue<Float_t> riiev(reader, "InstantaneousIntensity");
  TTreeReaderValue<Float_t> rk3pivtx_x(reader, "K3piVertex_x");
  TTreeReaderValue<Float_t> rk3pivtx_y(reader, "K3piVertex_y");
  TTreeReaderValue<Float_t> rk3pivtx_z(reader, "K3piVertex_z");
  TTreeReaderValue<Float_t> rk3pivtx_t(reader, "K3piVertex_t");
  TTreeReaderValue<Float_t> rktag_t(reader, "K3piKTAG_t");
  TTreeReaderValue<Int_t> rktag_ns(reader, "K3piKTAG_nsectors");
  TTreeReaderValue<Float_t> rk3pivtx_px(reader, "K3piTotalMom_Px");
  TTreeReaderValue<Float_t> rk3pivtx_py(reader, "K3piTotalMom_Py");
  TTreeReaderValue<Float_t> rk3pivtx_pz(reader, "K3piTotalMom_Pz");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_x(reader, "K3piVertexGTK3_x");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_y(reader, "K3piVertexGTK3_y");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_z(reader, "K3piVertexGTK3_z");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_px(reader, "K3piTotalMomGTK3_Px");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_py(reader, "K3piTotalMomGTK3_Py");
  TTreeReaderValue<Float_t> rk3pivtxgtk3_pz(reader, "K3piTotalMomGTK3_Pz");
  TTreeReaderValue<std::vector<Float_t>> rgtk3_x(reader, "GTKTrackGTK3_x");
  TTreeReaderValue<std::vector<Float_t>> rgtk3_y(reader, "GTKTrackGTK3_y");
  TTreeReaderValue<std::vector<Float_t>> rgtkt_t(reader, "GTKTrack_t");
  TTreeReaderValue<std::vector<Float_t>> rgtkt_px(reader, "GTKTrack_Px");
  TTreeReaderValue<std::vector<Float_t>> rgtkt_py(reader, "GTKTrack_Py");
  TTreeReaderValue<std::vector<Float_t>> rgtkt_pz(reader, "GTKTrack_Pz");
  TTreeReaderValue<std::vector<Float_t>> rgtkt_chi2(reader, "GTKTrack_chi2");

  int mysweetcout = 0;
  while (reader.Next()){
    // if (mysweetcout>10)
    //   break;
    runid = (*rrunid);
    burstid = (*rburstid);
    evid = (*revid);
    evts = (*revts);
    iiev = (*riiev);
    k3pivtx_x = (*rk3pivtx_x);
    k3pivtx_y = (*rk3pivtx_y);
    k3pivtx_z = (*rk3pivtx_z);
    k3pivtx_t = (*rk3pivtx_t);
    ktag_t = (*rktag_t);
    ktag_ns = (*rktag_ns);
    k3pivtx_px = (*rk3pivtx_px);
    k3pivtx_py = (*rk3pivtx_py);
    k3pivtx_pz = (*rk3pivtx_pz);
    k3pivtxgtk3_x = (*rk3pivtxgtk3_x);
    k3pivtxgtk3_y = (*rk3pivtxgtk3_y);
    k3pivtxgtk3_z = (*rk3pivtxgtk3_z);
    k3pivtxgtk3_px = (*rk3pivtxgtk3_px);
    k3pivtxgtk3_py = (*rk3pivtxgtk3_py);
    k3pivtxgtk3_pz = (*rk3pivtxgtk3_pz);
    gtk3_x = (*rgtk3_x);
    gtk3_y = (*rgtk3_y);
    gtkt_t = (*rgtkt_t);
    gtkt_px = (*rgtkt_px);
    gtkt_py = (*rgtkt_py);
    gtkt_pz = (*rgtkt_pz);
    gtkt_chi2 = (*rgtkt_chi2);

    newTree->Fill();
    // std::cout << (*rgtk3_x).size() << " " << (*rrunid) << std::endl;
    // mysweetcout++;
  }

  newTree->Write("", TObject::kOverwrite);
  // newfile.Purge();
  // newfile.Write();
  newfile.Close();
}