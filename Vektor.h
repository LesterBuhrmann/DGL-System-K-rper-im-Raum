#ifndef VEKTOR_H_INCLUDED
#define VEKTOR_H_INCLUDED
class Vektor          //Einf�hrung einer Klasse f�r 3D Vektoren
{
public:
  double x;
  double y;
  double z;

  Vektor(double x, double y, double z);
  Vektor operator+(const Vektor &b);                        //Einf�hrung des Operators f�r Vektoraddition

double operator*(const Vektor &a);                 //Einf�hrung des Operators f�r Skalarprodukt von Vektoren

Vektor operator*(const double &a);                 //Einf�hrung des Operators f�r rechtsseitige Multiplikation mit einem Skalar

};
double norm(Vektor a);


#endif // VEKTOR_H_INCLUDED
