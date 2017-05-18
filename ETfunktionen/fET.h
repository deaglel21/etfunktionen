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
double fKondensatorladen(double dT, double dU0,double dRC, double dC);
double fWiderstand(double dp,double dl,double dA);
double fRTemp(double dR20, double da, double dv);
double fRinnen(double dRa, double dVl, double dVa);



#endif /* fET_h */
