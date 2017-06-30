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
    double Rges  = 0;
    
    for (int i = 0; i < Anzahl ; ++i)
    {
        double curr = dR[i];
        Rges += curr;
    }
    
    return Rges;
}

//Parallelwiderstand (Anzahl, R1,R2...,Rn)
double fRinParallel(int Anzahl, double dR[])
{
    double dRges = 0, dLeit = 0;
    
    for (int i=0; i < Anzahl; i++)
    {
        double curr = 1 / dR[i];
        dLeit += curr;
    }
    
    dRges = 1 / dLeit;
    return dRges;
}

//Kondensator laden (Zeit, Spannung, Widerstand, Kapazität)
void fKondensatorladen(double dT, double dU0,double dRC, double dC,double *dUC, double *dIL)
{
    *dUC = dU0 * (1 - exp(-dT / (dRC * dC)));
    *dIL = (dU0 / dRC) * (1 - exp(-dT / (dRC * dC)));
}

//Kondensator entladen (Zeit, Spannung, Widerstand, Kapazität, Spannung Kondensator,)
void fKondensatorentladen(double dT, double dU0,double dRC, double dC,double *dUC, double *dIL)
{
    *dUC = dU0 * exp(-dT / (dRC * dC));
    *dIL = -(dU0 / dRC) * (1 - exp(-dT / (dRC * dC)));
}

//Physikalisch (Speyifischer Widerstand, Leiterlänge, Leiterquerschnitt)
double fWiderstand(double dp,double dl,double dA)
{
    double dR = (dp * dl / dA);
    return dR;
}

//Temperatur (Widerstand bei 20°C, Alpha20, Temperatur differenz)
double fRTemp(double dR20, double dA, double dV)
{
    double dRv = dR20 * (1 + dA * dV);
    return dRv;
}

//Innenwiderstand (Lastwiderstand, Spannung Unbelastet, Spannung last)
double fRinnen(double dRa, double dVl, double dVa)
{
    return (dVl - dVa) / (dVa / dRa);
}

//Leistung (Spannung, Strom, Phasenverschiebung)
void fLeistung(double dU, double dA, double dPhi, double *aSLeistung, double *aWLeistung, double *aBLeistung)
{
    *aSLeistung = dU * dA;
    *aWLeistung = dU * dA * cos(dPhi * PI / 180);
    *aBLeistung = dU * dA * sin(dPhi * PI / 180);
}

// RLC Brücke(Spannung,Frequenz,Widerstand,Induktivitaet,Kapazitaet,
            //Strom,Phasenverschiebung,Komplexer Widerstand,Komplexe Induktivitaet,Komplexe Kapazitaet,Scheinleistung,Wirkleistung,Blindleistung)
void fRLC(double dU, double df, double dR, double dL, double dC,
          double *dA, double *dPhi, double *dZ, double *dwL, double *dwC, double *aSLeistung, double *aWLeistung, double *aBLeistung)
{
    double zreal,zim;
    double omega=2 * PI * df;
    *dwL = omega * dL;
    *dwC = -1 / (omega * dC);
    zreal = dR;
    zim = *dwC + *dwL;
    *dPhi = atan(zim/ zreal)*180/PI;
    *dZ = sqrt(zreal*zreal+zim*zim);
    *dA = dU / *dZ;
    
    
    
    *aSLeistung = dU * *dA;
    *aWLeistung = dU * *dA * cos(*dPhi * PI / 180);
    *aBLeistung = dU * *dA * sin(*dPhi * PI / 180);
}
