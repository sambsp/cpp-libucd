/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */

#ifndef nsBig5Prober_h__
#define nsBig5Prober_h__

#include "nsCharSetProber.h"
#include "nsCodingStateMachine.h"
#include "CharDistribution.h"

class nsBig5Prober: public nsCharSetProber {
public:
  nsBig5Prober(void){mCodingSM = new nsCodingStateMachine(&Big5SMModel);
                      Reset();};
  virtual ~nsBig5Prober(void){delete mCodingSM;};
  nsProbingState HandleData(const char* aBuf, PRUint32 aLen);
  const char* GetCharSetName() {return "Big5";};
  nsProbingState GetState(void) {return mState;};
  void      Reset(void);
  float     GetConfidence(void);
  void      SetOpion() {};

protected:
  void      GetDistribution(PRUint32 aCharLen, const char* aStr);
  
  nsCodingStateMachine* mCodingSM;
  nsProbingState mState;

  //Big5ContextAnalysis mContextAnalyser;
  Big5DistributionAnalysis mDistributionAnalyser;
  char mLastChar[2];

};


#endif /* nsBig5Prober_h__ */
