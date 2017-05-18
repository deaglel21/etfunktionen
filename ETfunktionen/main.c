//
//  main.c
//  ETfunktionen
//
//  Created by Arthur Lerke on 13.05.17.
//  Copyright © 2017 Arthur Lerke. All rights reserved.
//
#include <stdio.h>
#include"fET.h"


int main()
{
    double dAusgabe;
    int iAuswahl,iAnzahl;
    puts("Elektrotechnik Berechnungsprogramm");
    puts("Berechnung von:\n1. Physikalischen Widerstand berechnen\n2. Widerstand bei Temperatur berechnen\n3. Widerstand in Reihe\n4. Parallelwiderstand\n5. Innenwiderstand\n6. Spannung am Kondensator");
    printf("Berechnung Nr: "); scanf("%i",&iAuswahl); getchar();
    switch (iAuswahl) {
        case 1:{
            double dp,dl,dA;
            printf("Spezifischer Widerstand in (Ohm*mm^2)/m: ");scanf("%lf",&dp); getchar();
            printf("Laenge in m: "); scanf("%lf",&dl); getchar();
            printf("Leiterquerschnitt in mm^2: ");scanf("%lf",&dA); getchar();
            dAusgabe=fWiderstand(dp, dl, dA);
            printf("Der Widerstand betraegt %8.2lf Ohm",dAusgabe);
            break;
        }
        case 2:{
            double dR20,da,dv;
            printf("Widerstand bei 20°C in Ohm: ");scanf("%lf",&dR20); getchar();
            printf("Temperaturkoeffizient: "); scanf("%lf",&da); getchar();
            printf("Temperatur differenz: ");scanf("%lf",&dv); getchar();
            dAusgabe=fWiderstand(dR20, da, dv);
            printf("Der Widerstand bei %5.2lf°C betraegt %8.2lf Ohm",dv+20,dAusgabe);
            break;
        }
        case 3:{ printf("Anzahl der Widerstaende: "); scanf("%i",&iAnzahl); getchar();
    double dRr[iAnzahl];
    for(int i=0; i<iAnzahl;i++){
        printf("R%i in Ohm:",i+1); scanf("%lf",&dRr[i]); getchar();
    }
    dAusgabe=fRinReihe(iAnzahl,dRr);
    printf("Der Gesamtwiderstand ist: %8.2lf Ohm",dAusgabe);
            break;
        }
        case 4:{printf("Anzahl der Widerstaende: "); scanf("%i",&iAnzahl); getchar();
            double dRp[iAnzahl];
            for(int i=0; i<iAnzahl;i++){
                printf("R%i in Ohm:",i+1); scanf("%lf",&dRp[i]); getchar();
            }
            dAusgabe=fRinParallel(iAnzahl,dRp);
            printf("Der Gesamtwiderstand ist: %8.2lf Ohm",dAusgabe);
            break;
        }
        case 5:{
            double dRa,dVl,dVa;
            printf("Spannung ohne Last in V: ");scanf("%lf",&dVl); getchar();
            printf("Spannung mit Last in V: "); scanf("%lf",&dVa); getchar();
            printf("Lastwiderstand in Ohm: ");scanf("%lf",&dRa); getchar();
            dAusgabe=fRinnen(dRa, dVl, dVa);
            printf("Der Innenwiderstand betraegt: %8.2lf Ohm",dAusgabe);
            break;
        }
        case 6:{
            double dU0,dT,dRc,dC;
            printf("Spannung U0 in V: ");scanf("%lf",&dU0); getchar();
            printf("Zeit in ms: ");scanf("%lf",&dT); getchar();
            printf("Widerstand Rc in Ohm: ");scanf("%lf",&dRc); getchar();
            printf("Kapazitaet in nF: ");scanf("%lf",&dC); getchar();
            dAusgabe=fKondensatorladen(dT*1e-3, dU0, dRc, dC*1e-9);
            printf("Die Spannung am Kondensator ist: %8.2lf V",dAusgabe);
            break;
        }
    }
    getchar();
    return 0;
}
