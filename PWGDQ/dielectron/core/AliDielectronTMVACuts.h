#ifndef ALIDIELECTRONTMVACUTS_H
#define ALIDIELECTRONTMVACUTS_H

/* Copyright(c) 1998-2009, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//#############################################################
//#                                                           # 
//#         Class AliDielectronTMVACuts                       #
//#                                                           #
//#  Authors:                                                 #
//#   Aaron     Capon,    SMI / aaron.capon@cern.ch           #
//#   Sebastian Lehner,   SMI / Sebastian.Lehner@cern.ch      #
//#   Michael   Weber,    SMI / m.weber@cern.ch               #
//#                                                           #
//#############################################################

#include "TMVA/Reader.h"

#include <AliAnalysisCuts.h>
#include <AliDielectronVarManager.h>

class AliDielectronTMVACuts : public AliAnalysisCuts {
public:
  
  AliDielectronTMVACuts();
  AliDielectronTMVACuts(const char*name, const char* title);

  virtual ~AliDielectronTMVACuts();

  void AddTMVAInput(TString featureName, AliDielectronVarManager::ValueTypes dielectronVar);
  void AddTMVASpectator(TString featureName, AliDielectronVarManager::ValueTypes dielectronVar);
  void SetTMVAWeights(TString TMVAName, TString weightName);
  void SetTMVACutValue(Float_t userTMVACutValue) {mvaCutValue = userTMVACutValue;}
    

  //
  //Analysis cuts interface
  //
  virtual Bool_t IsSelected(TObject* track);
  virtual Bool_t IsSelected(TList*   /* list */ ) {return kFALSE;}
  

 private:

  AliDielectronTMVACuts(const AliDielectronTMVACuts &c);
  AliDielectronTMVACuts &operator=(const AliDielectronTMVACuts &c);

  static const Int_t nInputFeatureMax = 20;                      // maximum number of input features
  
  TMVA::Reader* TMVAReader;                                      // TMVA reader
  TString TMVAReaderName;                                        // TMVA Reader Name
  
  Int_t nInputFeatureActive;                                     // number of active input features
  TBits* fUsedVars;                                              // used variables in AliDielectronVarManager::ValueTypes
  Float_t inputFeature[nInputFeatureMax];                        // input feature array, to be filled track-by-track from AliDielectronVarManager
  AliDielectronVarManager::ValueTypes inputFeatureNumber[nInputFeatureMax];    // input feature number array (corresponding to AliDielectronVarManager::ValueTypes)
  
  Float_t mvaCutValue;                                           // cut value to be used for TMVA output value
  
  ClassDef(AliDielectronTMVACuts,1)                              // Dielectron TMVACuts
};



#endif
