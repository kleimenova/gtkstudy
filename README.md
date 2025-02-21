# Study of GTK performance

We start our project with the notebook [TP4b_project_study.ipynb](TP4b_project_study.ipynb)

### Literature:
- [NA62 detector paper](https://iopscience.iop.org/article/10.1088/1748-0221/12/05/P05025)
- [K->pinn theoretical overview](https://arxiv.org/abs/1503.02693)
- [GTK paper](https://arxiv.org/abs/1904.12837)
- [HSF training](https://hsf-training.github.io/analysis-essentials/python/README.html)
- `ROOT` [documentation](https://root.cern/)
- `uproot` [documentation](https://uproot.readthedocs.io/en/latest/)
- `zfit` [documentation](https://zfit.readthedocs.io/en/0.3.6/getting_started.html)
- [TDCPix design manual](https://espace.cern.ch/tdc-pix/Shared%20Documents/20130506TDCpix_design_manual.pdf)

### Description of `TTree` variables:
- `RunID` - number of data taking run
- `BurstID` - number of SPS spill recorded inside one run
- `EventID` - number of event witten inside a burst
- `EventTS` - UTC time associated with the event 
- `InstantaneousIntensity` - instantaneous particle rate computed for each event
- `K3piVertex_x` - X position of reconstructed $K^+ \rightarrow \pi^+ \pi^+ \pi^-$ ($K3\pi$) decay vertex [mm]
- `K3piVertex_y` - Y position of reconstructed $K3\pi$ decay vertex [mm]
- `K3piVertex_z` - Z position of reconstructed $K3\pi$ decay vertex [mm]
- `K3piVertex_t` - weighted average time of three $\pi$ tracks (from CHOD and NewCHOD detectors) [ns]
- `K3piKTAG_t` - time measured by KTAG and matched with vertex time in $\pm$ 1 ns [ns]
- `K3piKTAG_nsectors` - number of fired sectors in KTAG
- `K3piTotalMom_Px` - X coordinate of the reconstructed kaon momentum $P_{K^+} = P_{\pi^+} + P_{\pi^+} + P_{\pi^-}$  [MeV]
- `K3piTotalMom_Py` - Y coordinate of the reconstructed kaon momentum $P_{K^+}$  [MeV]
- `K3piTotalMom_Pz` - Z coordinate of the reconstructed kaon momentum $P_{K^+}$  [MeV]
- `K3piVertexGTK3_x` - X position of reconstructed $K3\pi$ decay vertex propagated back to GTK3 posiiton [mm]
- `K3piVertexGTK3_y` - Y position of reconstructed $K3\pi$ decay vertex propagated back to GTK3 posiiton [mm]
- `K3piVertexGTK3_z` - Z position of reconstructed $K3\pi$ decay vertex propagated back to GTK3 posiiton [mm]
- `K3piTotalMomGTK3_Px`- X coordinate of the reconstructed kaon momentum $P_{K^+}$ propagated back to GTK3 posiiton [MeV] (what is the difference?)
- `K3piTotalMomGTK3_Py`- Y coordinate of the reconstructed kaon momentum $P_{K^+}$ propagated back to GTK3 posiiton [MeV] (what is the difference?)
- `K3piTotalMomGTK3_Pz`- Z coordinate of the reconstructed kaon momentum $P_{K^+}$ propagated back to GTK3 posiiton [MeV] (what is the difference?)
- `GTKTrackGTK3_x` - X coordinate of the reconstructed by GTK beam track at GTK3 [mm] 
- `GTKTrackGTK3_y` - Y coordinate of the reconstructed by GTK beam track at GTK3 [mm] 
- `GTKTrack_t` - time of the beam track reconstructed by GTK as weighted average of times of all stations [ns]
- `GTKTrack_Px` - X coordinate of the reconstructed by GTK beam track momentum [MeV]
- `GTKTrack_Py` - Y coordinate of the reconstructed by GTK beam track momentum [MeV]
- `GTKTrack_Pz` - Z coordinate of the reconstructed by GTK beam track momentum [MeV]
- `GTKTrack_chi2` - $\chi^2$ of GTK track fit
- `GTKTrack_nhits` - number of hits in the rescostrcuted gtk track
- `GTKHit_x` - X coordinate of the reconstrcuted GTK hit (1 hit = 1pixel)
- `GTKHit_y` - Y coordinate of the reconstrcuted GTK hit (1 hit = 1pixel)
- `GTKHit_t` - time of the reconstrcuted GTK hit [ns]
- `GTKHit_traw` - uncorrected time of the reconstrcuted GTK hit [ns]
- `GTKHit_uid` - pixel ID (unique for all pixels in all stations)
- `GTKHit_isintrack` - bool variable, if True the hit was present in some reconstructed GTK track
