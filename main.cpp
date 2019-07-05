#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include"Vektor.h"
using namespace std;
std::ostream &operator<<(std::ostream &Str, Vektor const &v) //Ein Operator, um einzelne Vektoren schneller und kompakter über cout auszugeben
{
    Str << "["<<v.x<<","<<v.y<<","<<v.z<<"]";
   return Str;
}

int main()
{ string Koerper1, Koerper2, Koerper3;
 cout<<"Name des ersten Körpers?"<<endl;
 cin >> Koerper1; //Masse des ersten Körpers
 cout<<"Name des zweiten Körpers?"<<endl;
 cin >> Koerper2;  //Masse zweiten Körpers
 cout<<"Name des dritten Körpers?"<<endl;
 cin >> Koerper3;  //Masse des dritten Körpers

 double me,mm,mmerk; //Masse 1,2 und 3
 cout<<"Masse "<<Koerper1<<"?"<<endl;
 cin >> me; //Masse des ersten Körpers
 cout<<"Masse "<<Koerper2<<"?"<<endl;
 cin >> mm;  //Masse zweiten Körpers
 cout<<"Masse "<<Koerper3<<"?"<<endl;
 cin >> mmerk;  //Masse des dritten Körpers
 Vektor xe0(0,0,0), xm0(0,0,0), xmerk0(0,0,0), ve0(0,0,0), vm0(0,0,0), vmerk0(0,0,0);
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

 double G = 6.67384e-11; //Gravitationskonstante
 double m = -1;       //Minus eins als für Umkehrung von Vektoren

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
dt.push_back(0.1e3); //Anfangszeitschritt nicht unnötig fein gewählt
vector<int> tn; // Dies werden die Zeitschritte für die als txt Datei ausgegebenen Werte mit gleichmäßigem zeitlichen Abstand werden

int N = 20000;
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

cout << xm[i] << " " << norm(xe[i]) << " " << k[i] << endl;      //Ausgabe beliebiger Größen
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
string txt, xKoerper1,xKoerper2,xKoerper3;          //Es werden hier strings deklariert, um Dateinamen zu erstellen, die der Eingabe der Namen der Körper entsprechen
txt = ".txt";
xKoerper1 = Koerper1 + txt;
xKoerper2 = Koerper2 + txt;
xKoerper3 = Koerper3 + txt;
 FILE* fp;
 fp = fopen(xKoerper1.c_str(),"w");
 for(int j = 0;j <= Schrittzahl; j++)
 {

fprintf(fp,"%e %e %e\n", xe[tn[j]].x, xe[tn[j]].y, xe[tn[j]].z); //Ausgabe der txt Datei zum ersten Körper
 }
fclose(fp);

FILE* fs;
 fs = fopen(xKoerper2.c_str(),"w");
 for(int j = 0;j <= Schrittzahl; j++)
 {

fprintf(fs,"%e %e %e\n", xm[tn[j]].x, xm[tn[j]].y, xm[tn[j]].z);
 }
fclose(fs);
FILE* fk;
 fk = fopen(xKoerper3.c_str(),"w");
 for(int j = 0;j <= Schrittzahl; j++)
 {

fprintf(fk,"%e %e %e\n", xmerk[tn[j]].x, xmerk[tn[j]].y, xmerk[tn[j]].z);
 }
fclose(fk);
    return 0;
}
