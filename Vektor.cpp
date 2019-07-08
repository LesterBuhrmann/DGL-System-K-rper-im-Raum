#include"Vektor.h"
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<fstream>




using namespace std;

Vektor::Vektor(double x, double y, double z) : x(x), y(y), z(z) {}
  Vektor Vektor::operator+(const Vektor &b)                        //Einführung des Operators für Vektoraddition
  {
    Vektor summe(x +b.x, y + b.y, z +b.z);
    return summe;
  }
double Vektor::operator*(const Vektor &a)                 //Einführung des Operators für Skalarprodukt von Vektoren
{
double produkt(x*a.x+y*a.y+z*a.z);
return produkt;
}
Vektor Vektor::operator*(const double &a)                 //Einführung des Operators für rechtsseitige Multiplikation mit einem Skalar
{
    Vektor pro(a*x, a*y, a*z);
    return pro;
}
double norm(Vektor a) {                          //Einführung der Betragsfunktion
    return sqrt(a * a);
}
