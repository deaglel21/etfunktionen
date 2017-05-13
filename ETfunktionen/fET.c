//
//  fET.c
//  ETfunktionen
//
//  Created by Arthur Lerke on 13.05.17.
//  Copyright © 2017 Arthur Lerke. All rights reserved.
//
#include<math.h>
#include <stdarg.h>

double fRinReihe(int Anzahl,double dR[])
{
    double Rges  = 0.0;
    for (int i = 0; i < Anzahl ; ++i) {
        double curr=dR[i];
        Rges += curr;
    }
    return Rges;
}
double fRinParallel(int Anzahl, double dR[])
{
    double dRges=0.0,dLeit = 0.0;
    for (int i=0; i< Anzahl; i++){
        double curr=1/dR[i];
        dLeit += curr;
    }
    dRges=1/dLeit;
    return dRges;
}

double fKondensatorladen(double dT, double dU0,double dRC, double dC)
{
    double dUC;
    
    dUC=dU0*(1-exp(-dT/(dRC*dC)));
    return dUC;
}

double fWiderstand(double dp,double dl,double dA)
{
    double dR = (dp*dl/dA);
    return dR;
}
double fRTemp(double dR20, double da, double dv)
{
    double dRv= dR20*(1+da*dv);
    return dRv;
}
