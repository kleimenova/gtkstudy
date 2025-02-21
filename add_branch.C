void add_branch(){
  TFile *f = new TFile("Run009001_gtk_tp4b_2604.root","update"); 
  TTree *T = (TTree*)f->Get("GTKStudyTtree"); 
  
  Double_t pt; 

  TBranch *bpt = T->Branch("pt",&pt,"pt/D");

  Long64_t nentries = T->GetEntries(); 
  for (Long64_t i=0;i<nentries;i++) { 
    T->GetEntry(i); 
    pt = -100500; 
    bpt->Fill(); 
  } 

  T->Print(); 
  T->Write("", TObject::kOverwrite); 
  delete f;
}
