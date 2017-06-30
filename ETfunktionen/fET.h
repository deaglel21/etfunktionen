//
//  fET.h
//  ETfunktionen
//
//  Created by Arthur Lerke on 13.05.17.
//  Copyright © 2017 Arthur Lerke. All rights reserved.
//

#ifndef fET_h
#define fET_h

double fRinReihe(int Anzahl,double dR[]);
double fRinParallel(int Anzahl, double dR[]);
void   fKondensatorladen(double dT, double dU0,double dRC, double dC,double *dUC, double *dIL);
void   fKondensatorentladen(double dT, double dU0,double dRC, double dC,double *dUC, double *dIL);
double fWiderstand(double dp,double dl,double dA);
double fRTemp(double dR20, double dA, double dV);
double fRinnen(double dRa, double dVl, double dVa);
void   fLeistung(double dU, double dA, double dGrad, double *aSLeistung, double *aWLeistung, double *aBLeistung);
void fRLC(double dU,  double df,  double dR, double dL,  double dC,
          double *dA,double *dPhi,double *dZ,double *dwL,double *dwC, double *aSLeistung, double *aWLeistung, double *aBLeistung);


#endif /* fET_h */
