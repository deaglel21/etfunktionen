//
//  fET.c
//  ETfunktionen
//
//  Created by Arthur Lerke on 13.05.17.
//  Copyright © 2017 Arthur Lerke. All rights reserved.
//
#include<math.h>
#include <stdarg.h>

#define PI 3.14159265

//Reihenwiderstand (Anzahl, R1,R2...,Rn)
double fRinReihe(int Anzahl,double dR[])
{
    double Rges  = 0.0;
    for (int i = 0; i < Anzahl ; ++i) {
        double curr=dR[i];
        Rges += curr;
    }
    return Rges;
}

//Parallelwiderstand (Anzahl, R1,R2...,Rn)
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

//Kondensator aufladen (Zeit, Spannung, Widerstand, Kapazität)
double fKondensatorladen(double dT, double dU0,double dRC, double dC)
{
    double dUC;
    
    dUC=dU0*(1-exp(-dT/(dRC*dC)));
    return dUC;
}

//Physikalisch (Speyifischer Widerstand, Leiterlänge, Leiterquerschnitt)
double fWiderstand(double dp,double dl,double dA)
{
    double dR = (dp*dl/dA);
    return dR;
}

//Temperatur (Widerstand bei 20°C, Alpha20, Temperatur differenz)
double fRTemp(double dR20, double dA, double dV)
{
    double dRv= dR20*(1+dA*dV);
    return dRv;
}

//Innenwiderstand (Lastwiderstand, Spannung Unbelastet, Spannung belastet)
double fRinnen(double dRa, double dVl, double dVa)
{
    double dRi;
    dRi=(dVl-dVa)/(dVa/dRa);
    return dRi;
}

//Leistung (Spannung, Strom, Phasenverschiebung)
double * fleistung(double dU, double dA, double dGrad)
{
    static double dleistung[3];
    dleistung[0]= dU*dA;
    dleistung[1]=dU*dA*cos(dGrad*(PI/180));
    dleistung[2]=dU*dA*sin(dGrad*(PI/180));
    return dleistung;
    
}
