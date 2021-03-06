#ifndef TAU_RESPONSE_H
#define TAU_RESPONSE_H

#include <iostream>
#include <exception>

#include "TH1.h"
#include "TString.h"

#include "HistReader.h"


// Tau-reponse templates and related information

class TauResponse {
public:
  // Definition of the pt bins for which separate
  // response templates are determined
  static unsigned int nBins() { return 4; }
  static unsigned int ptBin(double pt);

  // The acceptance inside which the response
  // distributions are valid. Corresponds to the
  // muon acceptance in the analysis.
  static double ptMin() { return ptMin(0); }
  static double etaMax() { return 2.1; }

  // Pt bin edges
  static double ptMin(unsigned int ptBin);
  static double ptMax(unsigned int ptBin);

  // Name of the response-template histogram
  // for the given pt bin
  static TString name(unsigned int ptBin);


  // Constructor. Takes name of file with response histograms
  // as input
  TauResponse(const char *fileName);

  // Get random number sampled from response distribution
  // The response distribution is chosen according to
  // the specified pt
  double getRandom(double pt) const { return resp_.at(ptBin(pt))->GetRandom(); }

  TH1* Resp(double pt){ return resp_.at(ptBin(pt));}

  static void Histfill(TH1* h1, TH1* h2);
  static void Histfill1D(TH1* h1, TH1* h2);
  static void Histfill2D(TH2* h1, TH2* h2);
  static void Histfill1Dto2D(TH1* h1, TH2* h2);
  static void HistfillCorr(TH1* h1, TH2* h2);
private:
  static void checkPtBin(unsigned int ptBin);

  std::vector<TH1*> resp_;	//  the response distribtuons
};


TauResponse::TauResponse(const char *fileName) {
  for(unsigned int i = 0; i < nBins(); ++i) {
    resp_.push_back(HistReader::get(fileName,TauResponse::name(i)));
  }
}

unsigned int TauResponse::ptBin(double pt) {
  /*if( pt < ptMin() ) {
    std::cerr << "\n\nERROR in TauResponse::ptBin" << std::endl;
    std::cerr << "  No response available for pt = " << pt << " < " << ptMin() << std::endl;
    throw std::exception();
    }*/

  unsigned int bin = 0;
  if( pt > 30. )  bin = 1;
  if( pt > 50. )  bin = 2;
  if( pt > 100. )  bin = 3;
  return bin;
}


/*double TauResponse::ptMin(unsigned int ptBin) {
  checkPtBin(ptBin);
  double pt = 20.;
  if(      ptBin == 1 ) pt = 30.;
  else if( ptBin == 2 ) pt = 40.;
  else if( ptBin == 3 ) pt = 50.;
  else if( ptBin == 4 ) pt = 70.;
  else if( ptBin == 5 ) pt = 100.;
  else if( ptBin == 6 ) pt = 150.;

  return pt;
  }*/

double TauResponse::ptMin(unsigned int ptBin) {
  checkPtBin(ptBin);
  double pt = 20.;
  if(      ptBin == 1 ) pt = 30.;
  else if( ptBin == 2 ) pt = 50.;
  else if( ptBin == 3 ) pt = 100.;

  return pt;
}

/*double TauResponse::ptMax(unsigned int ptBin) {
  checkPtBin(ptBin);
  double pt = 30.;
  if(      ptBin == 1 ) pt = 40.;
  else if( ptBin == 2 ) pt = 50.;
  else if( ptBin == 3 ) pt = 70.;
  else if( ptBin == 4 ) pt = 100.;
  else if( ptBin == 5 ) pt = 150.;
  else if( ptBin == 6 ) pt = 10000.;

  return pt;
  }*/

double TauResponse::ptMax(unsigned int ptBin) {
  checkPtBin(ptBin);
  double pt = 30.;
  if(      ptBin == 1 ) pt = 50.;
  else if( ptBin == 2 ) pt = 100.;
  else if( ptBin == 3 ) pt = 10000.;

  return pt;
}

TString TauResponse::name(unsigned int ptBin) {
  checkPtBin(ptBin);
  TString name = "hTauResp_";
  name += ptBin;

  return name;
}


void TauResponse::checkPtBin(unsigned int ptBin) {
  if( ptBin > 3 ) {
    std::cerr << "\n\nERROR in TauResponse: pt bin " << ptBin << " out of binning" << std::endl;
    throw std::exception();
  }
}

void TauResponse::Histfill(TH1* h1, TH1* h2){
  
  for (int ibin=1;ibin<=h1->GetNbinsX();ibin++){
    double bin = h1->GetBinCenter(ibin);
    double content = h1->GetBinContent(ibin);
    
    if (content!=0.){
      h2->Fill(bin,content);
    }
  }
  h1->Reset();
}
void TauResponse::Histfill1D(TH1* h1, TH1* h2){

  for (int ibin=1;ibin<=h1->GetNbinsX();ibin++){
    double bin = h1->GetBinCenter(ibin);
    double content = h1->GetBinContent(ibin);

    if (content!=0.){
      h2->Fill(bin,content);
    }
  }
    double lastbin = h1->GetXaxis()->GetBinLowEdge(h1->GetNbinsX()+1);
    double lastcontent = h1->GetBinContent(h1->GetNbinsX()+1);
    if (lastcontent>0.){
    h2->Fill(lastbin, lastcontent);
  }
  h1->Reset();
}
void TauResponse::Histfill2D(TH2* h1, TH2* h2){

  for (int ibin=1;ibin<=h1->GetNbinsX();ibin++){
    double binx = h1->GetXaxis()->GetBinCenter(ibin);
    for (int jbin=1;jbin<=h1->GetNbinsY();jbin++){
      double biny = h1->GetYaxis()->GetBinCenter(jbin);
      double content = h1->GetBinContent(ibin, jbin);
      if (content>0.)h2->Fill(binx, biny, content);
    }
  }
}
void TauResponse::Histfill1Dto2D(TH1* h1, TH2* h2){

  for (int ibin=1;ibin<=h1->GetNbinsX();ibin++){
    double bin = h1->GetBinCenter(ibin);
    double content = h1->GetBinContent(ibin);

    if (content!=0.){
      h2->Fill(bin,content);
    }
  }
  h1->Reset();
}

void TauResponse::HistfillCorr(TH1* h1, TH2* h2){
  for (int ibin=0;ibin<h1->GetNbinsX()+2;ibin++){
    double binX     = h1->GetBinCenter(ibin);
    double contentX = h1->GetBinContent(ibin);
    if (contentX != 0.){
      h2->Fill(binX,binX,contentX); // diagonal entries
    }
    for (int jbin=0;jbin<ibin;jbin++){
      double binY     = h1->GetBinCenter(jbin);
      double contentY = h1->GetBinContent(jbin);  
      double content = TMath::Min(contentX,contentY); // how this line works in MC events with negative weights
      // is not clear yet. Needs to be revisited.
      //if (content != 0.){
      //h2->Fill(binX,binY,content); // off-diagonal entries
      if (contentX != 0. && contentY != 0.){
	h2->Fill(binX,binY,contentY); // diagonal entries
	h2->Fill(binY,binX,contentX); // diagonal entries
      }
    }
  }
  h1->Reset();
}

#endif
