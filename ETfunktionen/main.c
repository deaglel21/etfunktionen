//
//  main.c
//  ETfunktionen
//
//  Created by Arthur Lerke on 13.05.17.
//  Copyright © 2017 Arthur Lerke. All rights reserved.
//
#include <stdio.h>
#include<stdlib.h>
#include"fET.h"


int main()
{
    double dAusgabe;
    int iAuswahl,iAnzahl,ineu=1;
    
    puts("Elektrotechnik Berechnungsprogramm");
    puts("Berechnung von:\n"
         "1. Physikalischen Widerstand berechnen\n"
         "2. Widerstand bei Erhitzung\n"
         "3. Widerstand in Reihe\n"
         "4. Parallelwiderstand\n"
         "5. Innenwiderstand\n"
         "6. Kondensator beim Laden\n"
         "7. Kondensator beim Entladen\n"
         "8. Leistung(Schein,Blind,Wirk\n"
         "9. RLC Reihe");
    
    while(ineu){
        printf("\nBerechnung Nr: "); scanf("%i",&iAuswahl);

        switch (iAuswahl) {
            case 1:{            //Physikalischer Widerstand
                double dp,dl,dA;
            
                printf("Spezifischer Widerstand in (Ohm*mm^2)/m: ");    scanf("%lf",&dp);   getchar();
                printf("Laenge in m:                             ");    scanf("%lf",&dl);   getchar();
                printf("Leiterquerschnitt in mm^2:               ");    scanf("%lf",&dA);   getchar();
            
                dAusgabe=fWiderstand(dp, dl, dA);
            
                printf("\nDer Widerstand betraegt %8.2lf Ohm",dAusgabe);
                break;
            }
            case 2:{            //Widerstand bei Erhitzung
                double dR20,da,dv;
            
                printf("Widerstand bei 20°C in Ohm: "); scanf("%lf",&dR20); getchar();
                printf("Temperaturkoeffizient:      "); scanf("%lf",&da);   getchar();
                printf("Temperatur differenz:       "); scanf("%lf",&dv);   getchar();
            
                dAusgabe=fWiderstand(dR20, da, dv);
            
                printf("\nDer Widerstand bei %5.2lf°C betraegt %8.2lf Ohm",dv+20,dAusgabe);
                break;
            }
            case 3:{            //Widerstand in Reihe
                double *dRr;

                printf("Anzahl der Widerstaende: ");    scanf("%i",&iAnzahl);   getchar();
                dRr=(double*)malloc(iAnzahl*sizeof(int));
                
                for(int i=0; i<iAnzahl;i++)
                {
                    printf("R%i in Ohm: ",i+1); scanf("%lf",&dRr[i]); getchar();
                }
                dAusgabe=fRinReihe(iAnzahl,dRr);
                free(dRr);
                
                printf("\nDer Gesamtwiderstand ist: %8.2lf Ohm",dAusgabe);
                break;
            }
            case 4:{            //Widerstand bei Parallelschaltung
                double *dRp;

                printf("Anzahl der Widerstaende: ");    scanf("%i",&iAnzahl);   getchar();
                dRp=(double*)malloc(iAnzahl*sizeof(int));
                
                for(int i=0; i<iAnzahl;i++)
                {
                    printf("R%i in Ohm: ",i+1);  scanf("%lf",&dRp[i]);   getchar();
                }
            
                dAusgabe=fRinParallel(iAnzahl,dRp);
                free(dRp);
                
                printf("\nDer Gesamtwiderstand ist: %8.2lf Ohm",dAusgabe);
                break;
            }
            case 5:{            //Innenwiderstand
                double dRa,dVl,dVa;
            
                printf("Spannung ohne Last in V: ");    scanf("%lf",&dVl);  getchar();
                printf("Spannung mit Last in V:  ");    scanf("%lf",&dVa);  getchar();
                printf("Lastwiderstand in Ohm:   ");    scanf("%lf",&dRa);  getchar();
            
                dAusgabe=fRinnen(dRa, dVl, dVa);
            
                printf("\nDer Innenwiderstand betraegt: %8.2lf Ohm",dAusgabe);
                break;
            }
            case 6:{            //Kondensator laden
                double dU0,dT,dRc,dC,dUC,dIL;
                
                printf("Spannung U0 in V:     ");   scanf("%lf",&dU0);  getchar();
                printf("Zeit in ms:           ");   scanf("%lf",&dT);   getchar();
                printf("Widerstand Rc in Ohm: ");   scanf("%lf",&dRc);  getchar();
                printf("Kapazitaet in nF:     ");   scanf("%lf",&dC);   getchar();
                
                fKondensatorladen(dT*1e-3, dU0, dRc, dC*1e-9,&dUC,&dIL);
                
                printf("\nDie Kondensatorspannung beim Laden ist: %8.2lf V",dUC);
                printf("\nDer Ladestrom ist:                      %8.2lf A",dIL);
                break;
            }
            case 7:{            //Kondensator entladen
                double dU0,dT,dRc,dC,dUC,dIL;
                
                printf("Spannung U0 in V:     ");   scanf("%lf",&dU0);  getchar();
                printf("Zeit in ms:           ");   scanf("%lf",&dT);   getchar();
                printf("Widerstand Rc in Ohm: ");   scanf("%lf",&dRc);  getchar();
                printf("Kapazitaet in nF:     ");   scanf("%lf",&dC);   getchar();
                
                fKondensatorentladen(dT*1e-3, dU0, dRc, dC*1e-9,&dUC,&dIL);
                
                printf("\nDie Kondensatorspannung beim Entladen ist: %8.2lf V",dUC);
                printf("\nDer Entladestrom ist:                      %8.2lf A",dIL);
                break;
            }
            case 8:{            //Scheinleistung
                double dU,dA,dPhi,dSLeistung,dWLeistung,dBLeistung;
                
                printf("Spannung in V:           ");    scanf("%lf",&dU);       getchar();
                printf("Strom in A:              ");    scanf("%lf",&dA);       getchar();
                printf("Phasenverschiebung in °: ");    scanf("%lf",&dPhi);     getchar();
                
                fLeistung(dU, dA, dPhi,&dSLeistung,&dWLeistung,&dBLeistung);
                
                printf("\nDie Scheineistung ist: %8.2lf W",dSLeistung);
                printf("\nDie Wirkleistung ist:  %8.2lf W",dWLeistung);
                printf("\nDie Blindleistung ist: %8.2lf W",dBLeistung);
                break;
            }
            case 9:{            //Komplexerwiderstand
                double dU,df,dA,dPhi,dR,dL,dC,dZ,dwL,dwC,dSLeistung,dWLeistung,dBLeistung;
                
                printf("Spannung in V:           ");    scanf("%lf",&dU);       getchar();
                printf("Frequenz in Hz:          ");    scanf("%lf",&df);       getchar();
                printf("Widerstand in Ohm:       ");    scanf("%lf",&dR);       getchar();
                printf("Induktivitaet in mH:     ");    scanf("%lf",&dL);       getchar();
                printf("Kapazitaet in uF:        ");    scanf("%lf",&dC);       getchar();
                
                fRLC(dU,df,dR,dL*1e-3,dC*1e-6,&dA,&dPhi,&dZ,&dwL,&dwC,&dSLeistung,&dWLeistung,&dBLeistung);
                
                printf("\nKomplexer Widerstand: %8.2lf Ohm %.0lf Grad",dZ,dPhi);
                printf("\nWiderstand Spule: %8.2lf Ohm 90 Grad",dwL);
                printf("\nWiderstand Kondensator: %8.2lf Ohm -90 Grad",-dwC);
                printf("\nStrom:  %8.2lf A %.0lf Grad",dA,-dPhi);
                printf("\nDie Scheineistung ist: %8.2lf W",dSLeistung);
                printf("\nDie Wirkleistung ist:  %8.2lf W",dWLeistung);
                printf("\nDie Blindleistung ist: %8.2lf W",dBLeistung);
                break;
            }
        }
        
        puts("\n\nNoch eine Berechnug? (1/0)");   scanf("%i",&ineu);
    }
    
    getchar();
    return 0;
}
