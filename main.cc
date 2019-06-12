#include<iostream>
#include<vector>
#include<math.h>


using namespace std

class Vector
{ 
public:
  double x;
  double y;
  double z;

  Vector(double x, double y, double z) : x(x), y(y), z(z) {}
  Vector operator+(const Vector &b)
  {
    Vector summe(x +b.x, y + b.y, z +b.z);
    return summe;  
  }
double operator*(const Vector &a) 
{
double produkt(x*a.x+y*a.y+z*a.z);
return produkt;
}
Vector operator*(const double &a)
{
    Vector pro(a*x, a*y, a*z);
    return pro
};
double norm(Vector a) {
    return sqrt(a * a);
}
std::ostream &operator<<(std::ostream &Str, Vector const &v)
{
    Str << "["<<v.x<<","<<v.y<<","v.z"]";
   return Str;
}

int main()
{
    return 0;
}





}

