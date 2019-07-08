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
#include<string>
#include<algorithm>
#include<fstream>
#include"Vektor.h"

using namespace std;



std::ostream &operator<<(std::ostream &Str, Vektor const &v) //Ein Operator, um einzelne Vektoren schneller und kompakter über cout auszugeben
{
    Str << "["<<v.x<<","<<v.y<<","<<v.z<<"]";
   return Str;
}




int main()
{ string Koerper1, Koerper2, Koerper3,Antwort1,Antwort2,Ausgabe,Nein1,Nein2,Nein3;
 Nein1 = "nein";
 Nein2 = "Nein";
 Nein3 = "no";

 Koerper1 = "Erde";
 Koerper2 = "Mars";
 Koerper3 = "Merkur";

 Vektor xe0(0,0,0), xm0(1e6,1e6,1e6), xmerk0(0, -2e6, 0), ve0(0, 0, 0), vm0(-10000, 0, -5000), vmerk0(1000,0,4000);
 double me = 5.96e24;  //Masse der Erde
 double mm = 6.39e23; //Masse des Mars
 double mmerk = 0.055*me; //Masse des Merkur
 double dt0 = 0.1;
 cout<<"Wollen sie vorgefertigte Massen und Anfangsbedingungen verwenden?"<<endl;
 cin>>Antwort1;
 if((Antwort1 == Nein1)||(Antwort1 == Nein2)||(Antwort1 == Nein3))
{
 cout<<"Name des ersten Koerpers?"<<endl;
 cin >> Koerper1; //Masse des ersten Körpers
 cout<<"Name des zweiten Koerpers?"<<endl;
 cin >> Koerper2;  //Masse zweiten Körpers
 cout<<"Name des dritten Koerpers?"<<endl;
 cin >> Koerper3;  //Masse des dritten Körpers

 cout<<"Masse "<<Koerper1<<"?"<<endl;
 cin >> me; //Masse des ersten Körpers
 cout<<"Masse "<<Koerper2<<"?"<<endl;
 cin >> mm;  //Masse zweiten Körpers
 cout<<"Masse "<<Koerper3<<"?"<<endl;
 cin >> mmerk;  //Masse des dritten Körpers



 cout<<"Ortsvektor "<<Koerper1<<" x wert?"<<endl; //Ortsvektor des ersten Körpers eingeben
 cin >> xe0.x;
 cout<<"Ortsvektor "<<Koerper1<<" y wert?"<<endl;
 cin >> xe0.y;
 cout<<"Ortsvektor "<<Koerper1<<" z wert?"<<endl;
 cin >> xe0.z;

 cout<<"Geschwindigkeitsvektor "<<Koerper1<<" x wert?"<<endl; //Geschwindigkeitsvektor des ersten Körpers eingeben
 cin >> ve0.x;
 cout<<"Geschwindigkeitssvektor "<<Koerper1<<" y wert?"<<endl;
 cin >> ve0.y;
 cout<<"Geschwindigkeitsvektor "<<Koerper1<<" z wert?"<<endl;
 cin >> ve0.z;

 cout<<"Ortsvektor "<<Koerper2<<" x wert?"<<endl; //Ortsvektor des zweiten Körpers eingeben
 cin >> xm0.x;
 cout<<"Ortsvektor "<<Koerper2<<" y wert?"<<endl;
 cin >> xm0.y;
 cout<<"Ortsvektor "<<Koerper2<<" z wert?"<<endl;
 cin >> xm0.z;

 cout<<"Geschwindigkeitsvektor "<<Koerper2<<" x wert?"<<endl; //Geschwindigkeitsvektor des zweiten Körpers eingeben
 cin >> vm0.x;
 cout<<"Geschwindigkeitsvektor "<<Koerper2<<" y wert?"<<endl;
 cin >> vm0.y;
 cout<<"Geschwindigkeitsvektor "<<Koerper2<<" z wert?"<<endl;
 cin >> vm0.z;

 cout<<"Ortsvektor "<<Koerper3<<" x wert?"<<endl; //Ortsvektor des dritten Körpers eingeben
 cin >> xmerk0.x;
 cout<<"Ortsvektor "<<Koerper3<<" y wert?"<<endl;
 cin >> xmerk0.y;
 cout<<"Ortsvektor "<<Koerper3<<" z wert?"<<endl;
 cin >> xmerk0.z;

 cout<<"Geschwindigkeitsvektor "<<Koerper3<<" x wert?"<<endl; //Geschwindigkeitsvektor des dritten Körpers eingeben
 cin >> vmerk0.x;
 cout<<"Geschwindigkeitsvektor "<<Koerper3<<" y wert?"<<endl;
 cin >> vmerk0.y;
 cout<<"Geschwindigkeitsvektor "<<Koerper3<<" z wert?"<<endl;
 cin >> vmerk0.z;

 cout<<"Zeitintervall dt0"<<endl;
 cin>> dt0;
 }

 else{cout<<"beliebige Taste fuer Erde Mars und Merkur, (1) fuer Erde, Mond, Sonne"<<endl;
 cin>>Antwort2;
 if(Antwort2 == "1")
 {Koerper1 = "Erde";
  Koerper2 = "Mond";
  Koerper3 = "Sonne";
 xe0.x=0;xe0.y=0;xe0.z=0;xm0.x=0;xm0.y=3.27171e8;xm0.z=1.42258e8;xmerk0.x=0;xmerk0.y=1.471e11;xmerk0.z=0;ve0.x=-29.78e3;ve0.y=0;ve0.z=0;vm0.x=1.067e3-29.78e3;vm0.y=0;vm0.z=0;
 vmerk0.x=0;vmerk0.y=0;vmerk0.z=0;
 me = 5.96e24;  //Masse der Erde
 mm = 7.349e22; //Masse des Mondes
 mmerk = 1.989e30; //Masse der Sonne
 dt0 = 0.1e3;
       }
 }

vector<Vektor> xe, xm, xmerk, ve, vm, vmerk, ae, am, amerk;     //Erstellen von vector-arrays der Ortsvektoren, Geschwindigkeits und Beschleunigungsvektoren

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
dt.push_back(dt0); //Anfangszeitschritt nicht unnötig fein gewählt

vector<int> tn; // Dies werden die Zeitschritte für die als txt Datei ausgegebenen Werte mit gleichmäßigem zeitlichen Abstand werden

int N;
cout<<"Wähle die Anzahl der Berechnungsschritte(Empfehlung: 20000)"<< endl;
cin>>N;

 double G = 6.67384e-11; //Gravitationskonstante
 double m = -1;       //Minus eins als für Umkehrung von Vektoren

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


cout<<Koerper1<<":"<< xm[i] << " Zeit in s: " << t[i] << endl;      //Ausgabe beliebiger Größen

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
 vector<double> xex,xey,xez,xmx,xmy,xmz,xmerkx,xmerky,xmerkz; //Um anschließend das Maximum und Minimum der Komponenten für das Plot Intervall festzulegen, wird zu jeder Komponente ein Vector angelegt.
 for(int i = 1; i <= N; i++){  //Hiermit wird tn so befüllt,
 if(k[i] > k[i-1]){            //dass es immer die Nummern der Einträge zeigt, die zeitlich fast genau 0.1 Einheiten entfernt sind.
 tn.push_back(i);}
 xex.push_back(xe[i].x);    //Die einzelnen Komponenten der Vektoren müssen seperat in einen vector geladen werden
 xey.push_back(xe[i].y);
 xez.push_back(xe[i].z);
 xmx.push_back(xm[i].x);
 xmy.push_back(xm[i].y);
 xmz.push_back(xm[i].z);
 xmerkx.push_back(xmerk[i].x);
 xmerky.push_back(xmerk[i].y);
 xmerkz.push_back(xmerk[i].z);
                             }
 int Schrittzahl = tn.size();  //Anzahl der Schritte mit gleichen Zeitabständen
                               //Damit werden genau so viele Elemente wie möglich, aber nicht mehr in die Textdatei geschrieben

double maxxex = *max_element(xex.begin(), xex.end());   //Nun wird das maximale Element zu den einzelnen Komponenten der einzelnen Vektoren
double maxxey = *max_element(xey.begin(), xey.end());   //ermittelt
double maxxez = *max_element(xez.begin(), xez.end());
double maxxmx = *max_element(xmx.begin(), xmx.end());
double maxxmy = *max_element(xmy.begin(), xmy.end());
double maxxmz = *max_element(xmz.begin(), xmz.end());
double maxxmerkx = *max_element(xmerkx.begin(), xmerkx.end());
double maxxmerky = *max_element(xmerky.begin(), xmerky.end());
double maxxmerkz = *max_element(xmerkz.begin(), xmerkz.end());

vector<double> xx;
vector<double> xy;
vector<double> xz;
xx.push_back(maxxex); xx.push_back(maxxmx); xx.push_back(maxxmerkx); //Ein kleiner Vektor wird mit den maximalen x-Werten überschrieben
xy.push_back(maxxey); xy.push_back(maxxmy); xy.push_back(maxxmerky); //Ein kleiner Vektor wird mit den maximalen y-Werten überschrieben
xz.push_back(maxxez);xz.push_back(maxxmz);xz.push_back(maxxmerkz);   //Ein kleiner Vektor wird mit den maximalen z-Werten überschrieben
double maxx = *max_element(xx.begin(), xx.end());  //Das Maximum der Maxima aller x Komponenten wird hiermit ermittelt
double maxy = *max_element(xy.begin(), xy.end());  //Das Maximum der Maxima aller y Komponenten wird hiermit ermittelt
double maxz = *max_element(xz.begin(), xz.end());  //Das Maximum der Maxima aller z Komponenten wird hiermit ermittelt


//Die gleiche Prozedur wird für die unteren Grenzen des Intervalls analog wiederholt
double minxex = *min_element(xex.begin(), xex.end());
double minxey = *min_element(xey.begin(), xey.end());
double minxez = *min_element(xez.begin(), xez.end());
double minxmx = *min_element(xmx.begin(), xmx.end());
double minxmy = *min_element(xmy.begin(), xmy.end());
double minxmz = *min_element(xmz.begin(), xmz.end());
double minxmerkx = *min_element(xmerkx.begin(), xmerkx.end());
double minxmerky = *min_element(xmerky.begin(), xmerky.end());
double minxmerkz = *min_element(xmerkz.begin(), xmerkz.end());

xx.push_back(minxex);
xx.push_back(minxmx);
xx.push_back(minxmerkx);
xy.push_back(minxey);
xy.push_back(minxmy);
xy.push_back(minxmerky);
xz.push_back(minxez);
xz.push_back(minxmz);
xz.push_back(minxmerkz);

double minx = *min_element(xx.begin(), xx.end());
double miny = *min_element(xy.begin(), xy.end());
double minz = *min_element(xz.begin(), xz.end());
cout<<"Das maximale x Intervall sollte groesser gleich : ["<<maxx<<","<<minx<<"] sein"<<endl
<<"Das maximale y Intervall sollte groesser gleich : ["<<maxy<<","<<miny<<"] sein"<<endl
<<"Das maximale z Intervall sollte groesser gleich : ["<<maxz<<","<<minz<<"] sein"<<endl;


Koerper1 += ".txt";
Koerper2 += ".txt";
Koerper3 += ".txt";
fstream f,ds,cs;
    f.open(Koerper2.c_str(), ios::out);
    ds.open(Koerper2.c_str(), ios::out);
    cs.open(Koerper3.c_str(), ios::out);
    for(int j = 0;j <= Schrittzahl; j++)     //Bis zur Schrittzahl, die der Größe von tn entspricht wird in die txt Datei eingeschrieben
    {int l = tn[j];                        //Man wählt nur die Elemente mit Positionen im Array, die in tn eingeschrieben sind
        f << xe[l].x<<" "<<xe[l].y<<" "<<xe[l].z<< endl;
        ds <<xm[l].x<<" "<<xm[l].y<<" "<<xm[l].z<< endl;
        cs <<xmerk[l].x<<" "<<xmerk[l].y<<" "<<xmerk[l].z<< endl;
        }
    f.close();
    ds.close();
    cs.close();

return 0;
}

