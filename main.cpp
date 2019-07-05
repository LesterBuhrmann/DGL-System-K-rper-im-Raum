//============================================================================
// Name des Projekts: 3-Körper Problem
// Author      : Lester Buhrmann,Dennis Budzinski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include<iostream>
#include<vector>
#include<math.h>
#include"Vektor.h"

using namespace std;



std::ostream &operator<<(std::ostream &Str, Vektor const &v) //Ein Operator, um einzelne Vektoren schneller und kompakter über cout auszugeben
{
    Str << "["<<v.x<<","<<v.y<<","<<v.z<<"]";
   return Str;
}




int main()
{
 double me = 5.96e24;  //Masse der Erde
 double mm = 6.39e23;  //Masse des Mars
 double G = 6.67384e-11; //Gravitationskonstante
 double m = -1;       //Minus eins als für Umkehrung von Vektoren
 double mmerk = 0.055*me;

vector<Vektor> xe, xm, xmerk, ve, vm, vmerk, ae, am, amerk;     //Erstellen von vector-arrays der Ortsvektoren, Geschwindigkeits und Beschleunigungsvektoren
Vektor xe0(0, 0, 0), xm0(1e6, 1e6, 1e6), xmerk0(0, -2e6, 0), ve0(0, 0, 0), vm0(-10000, 0, -5000), vmerk0(1000,0,4000);   //Der Mars ist ungefähr anfangs 1.7 Millionen Meter von der Erde entfernt
                                                     //Die Anfangswerte werden benötigt, um in der for Schleife das Euler-Verfahren durchzuführen

xe.push_back(xe0);             //arrays werden mit Anfangswerten aufgefüllt.
xm.push_back(xm0);
xmerk.push_back(xmerk0);
ve.push_back(ve0);
vm.push_back(vm0);
vmerk.push_back(vmerk0);

vector<double> dt,t,k;   //Die Länge des Zeitschritts dt ist vom Abstand und der Geschwindigkeit abhängig, weshalb dafür ein Array angelegt wird.
                         //t ist der absolute Zeitwert und k wird benötigt um gerundete Zeitpunkte zu bilden
t.push_back(0);     //Startzeitpunkt für t
dt.push_back(0.1); //Anfangszeitschritt nicht unnötig fein gewählt

vector<int> tn; // Dies werden die Zeitschritte für die als txt Datei ausgegebenen Werte mit gleichmäßigem zeitlichen Abstand werden


int N = 200000;
 for(int i = 0;i <= N; ++i){     //Nach dem Euler-Verfahren wird hier die Bewegung der Körper schrittweise numerisch ermittelt.
Vektor Rme = xm[i] + (xe[i]*m);  //Abstandsvektor
Vektor Remerk = xe[i] + (xmerk[i]*m);
Vektor Rmmerk = xm[i] + (xmerk[i]*m);
Vektor Fem = Rme*((mm*me)/((Rme*Rme)*norm(Rme)))*G;
Vektor Fmerke = Remerk*((mmerk*me)/((Remerk*Remerk)*norm(Remerk)))*G;
Vektor Fmerkm = Rmmerk*((mmerk*mm)/((Rmmerk*Rmmerk)*norm(Rmmerk)))*G;
ae.push_back(((Fmerke*m)+Fem)*(1/me)); //Beschleunigungsvektor der Erde nach newtonscher Gravitation
am.push_back((Fmerkm+Fem)*(m/mm));     //Beschhleunigungsvektor des Mars (Erinnerung:m = -1)
amerk.push_back((Fmerke+Fmerkm)*(1/mmerk));
ve.push_back(ve[i]+(ae[i]*dt[i]));   //Geschwindigkeitsvektor der Erde über Tangentenzerlegung von ve des vorherigen Zeitpunkts
vm.push_back(vm[i]+(am[i]*dt[i]));   //Geschwindihkeitsvektor des Mars
vmerk.push_back(vmerk[i]+(amerk[i]*dt[i]));
xe.push_back(xe[i]+ve[i]*dt[i]);     //Ortsvektor der Erde über Tangentenzerlegung von xe des vorherigen Zeitpunkts
xm.push_back(xm[i]+vm[i]*dt[i]);     //Ortsvekor des Mars
xmerk.push_back(xmerk[i]+vmerk[i]*dt[i]);
t.push_back(t[i]+dt[i]);

k.push_back(round(t[i]*1/dt[0])*dt[0]);


cout << xmerk[i] << " " << norm(xe[i]) << " " << k[i] << endl;      //Ausgabe beliebiger Größen

double Dme = ((norm(Rme)*norm(Rme))/norm(vm[i]))*1e-7*dt[0];
double Demerk = ((norm(Remerk)*norm(Remerk))/norm(vmerk[i]))*1e-7*dt[0];
double Dmmerk = ((norm(Rmmerk)*norm(Rmmerk))/norm(vmerk[i]))*1e-7*dt[0];

if((dt[0] >= Dme)||(dt[0] >= Demerk)||(dt[0] >= Dmmerk))    //Kontrolle des v zu r^2 Verhältnisses
{
 if((Dme < Dmmerk)&&(Dme < Demerk)){
 dt.push_back(Dme);}                          //Funktion für veränderliches Zeitintervall.
if((Dmmerk < Dme)&&(Dmmerk < Demerk)){
 dt.push_back(Dmmerk);}
 if((Demerk < Dme)&&(Demerk < Dmmerk)){
 dt.push_back(Demerk);}
}
   else{
     dt.push_back(dt[0]);                   //ansonsten zurück zum groben Intervall
                          }

 }

 for(int i = 1; i <= N; i++){  //Hiermit wird tn so befüllt,
 if(k[i] > k[i-1]){            //dass es immer die Nummern der Einträge zeigt, die zeitlich fast genau 0.1 Einheiten entfernt sind.
 tn.push_back(i);}
                   }
 int Schrittzahl = tn.size();  //Anzahl der Schritte mit gleichen Zeitabständen
                               //Damit werden genau so viele Elemente wie möglich, aber nicht mehr in die Textdatei geschrieben


  FILE* fp;
 fp = fopen("xMars.txt","w");
 for(int j = 0;j <= Schrittzahl; j++)
 {


fprintf(fp,"%e %e %e\n", xm[tn[j]].x, xm[tn[j]].y, xm[tn[j]].z);

 }
fclose(fp);


FILE* fs;
 fs = fopen("xErde.txt","w");
 for(int j = 0;j <= Schrittzahl; j++)
 {


fprintf(fs,"%e %e %e\n", xe[tn[j]].x, xe[tn[j]].y, xe[tn[j]].z);

 }
fclose(fs);

FILE* fk;
 fk = fopen("xMerkur.txt","w");
 for(int j = 0;j <= Schrittzahl; j++)
 {


fprintf(fk,"%e %e %e\n", xmerk[tn[j]].x, xmerk[tn[j]].y, xmerk[tn[j]].z);

 }
fclose(fk);

    return 0;

}
