#ifndef VEKTOR_H_INCLUDED
#define VEKTOR_H_INCLUDED
class Vektor          //Einführung einer Klasse für 3D Vektoren
{
public:
  double x;
  double y;
  double z;

  Vektor(double x, double y, double z);
  Vektor operator+(const Vektor &b);                        //Einführung des Operators für Vektoraddition

double operator*(const Vektor &a);                 //Einführung des Operators für Skalarprodukt von Vektoren

Vektor operator*(const double &a);                 //Einführung des Operators für rechtsseitige Multiplikation mit einem Skalar

};
double norm(Vektor a);


#endif // VEKTOR_H_INCLUDED
