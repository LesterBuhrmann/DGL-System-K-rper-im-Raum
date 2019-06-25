#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;


class Vektor          //Einführung einer Klasse für 3D Vektoren
{
public:
  double x;
  double y;
  double z;

  Vektor(double x, double y, double z) : x(x), y(y), z(z) {}
  Vektor operator+(const Vektor &b)                        //Einführung des Operators für Vektoraddition
  {
    Vektor summe(x +b.x, y + b.y, z +b.z);
    return summe;
  }
double operator*(const Vektor &a)                 //Einführung des Operators für Skalarprodukt von Vektoren
{
double produkt(x*a.x+y*a.y+z*a.z);
return produkt;
}
Vektor operator*(const double &a)                 //Einführung des Operators für rechtsseitige Multiplikation mit einem Skalar
{
    Vektor pro(a*x, a*y, a*z);
    return pro;
}
};
double norm(Vektor a) {                          //Einführung der Betragsfunktion
    return sqrt(a * a);
}
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


vector<Vektor> xe, xm, ve, vm, ae, am;     //Erstellen von vector-arrays der Ortsvektoren, Geschwindigkeits und Beschleunigungsvektoren
Vektor xe0(0, 0, 0), xm0(1e6, 1e6, 1e6), ve0(0, 0, 0), vm0(-10000, 0, -5000);   //Der Mars ist ungefähr anfangs 1.7 Millionen Meter von der Erde entfernt
                                                     //Die Anfangswerte werden benötigt, um in der for Schleife das Euler-Verfahren durchzuführen

xe.push_back(xe0);             //arrays werden mit Anfangswerten aufgefüllt.
xm.push_back(xm0);
ve.push_back(ve0);
vm.push_back(vm0);

vector<double> dt;            //Die Länge des Zeitschritts dt ist vom Abstand und der Geschwindigkeit abhängig, weshalb dafür ein Array angelegt wird.
dt.push_back(0.1);
int N = 20000;
 for(int i = 0;i <= N; ++i){     //Nach dem Euler-Verfahren wird hier die Bewegung der Körper schrittweise numerisch ermittelt.
Vektor r = xm[i] + (xe[i]*m);        //Abstandsvektor
ae.push_back(r*(mm/((r*r)*norm(r)))*G); //Beschleunigungsvektor der Erde nach newtonscher Gravitation
am.push_back((ae[i]*m)*(me/mm));     //Beschhleunigungsvektor des Mars
ve.push_back(ve[i]+(ae[i]*dt[i]));   //Geschwindigkeitsvektor der Erde über Tangentenzerlegung von ve
vm.push_back(vm[i]+(am[i]*dt[i]));   //Geschwindihkeitsvektor des Mars
xe.push_back(xe[i]+ve[i]*dt[i]);     //Ortsvektor der Erde über Tangentenzerlegung von xe
xm.push_back(xm[i]+vm[i]*dt[i]);     //Ortsvekor des Mars


cout << xm[i] << " " << xe[i] << " " << norm(r) << endl;      //Ausgabe beliebiger Größen

if(norm(vm[i])/(norm(r)*norm(r)) >= 1e-8)    //Kontrolle des v zu r^2 Verhältnisses
{
 dt.push_back(((norm(r)*norm(r))/norm(vm[i]))*1e-8); //Funktion für veränderliches Zeitintervall.

}
   else{
     dt.push_back(0.1);                   //ansonsten zurück zum groben Intervall
                          }

 }

 FILE* fp;
 fp = fopen("xMars.txt","w");
 for(int j = 0;j <= N; j++)
 {


fprintf(fp,"%e %e %e\n", xm[j].x, xm[j].y, xm[j].z);

 }
fclose(fp);


FILE* fs;
 fs = fopen("xErde.txt","w");
 for(int j = 0;j <= N; j++)
 {


fprintf(fs,"%e %e %e\n", xe[j].x, xe[j].y, xe[j].z);

 }
fclose(fs);

    return 0;

}

