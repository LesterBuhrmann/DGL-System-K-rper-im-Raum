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
  vector<Vector> xe, xm, ve, vm, ae, am;
Vector xe0(0, 0, 0), xm0(1e6, 1e6, 1e6), ve0(0, 0, 0), vm0(0, 0, 0);

xe.push_back(xe0);
xm.push_back(xm0);
ve.push_back(ve0);
vm.push_back(vm0);

vector<double> dt;
dt.push_back(0.01)    

 for(int i = 0;i <= 10000; ++i){
Vector r = xm[i] + (xe[i]*m);
ae.push_back(r*(mm/((r*r)*norm(r)))*G);
am.push_back((ae[i]*m)*(me/mm));
ve.push_back(ve[i]+(ae[i]*dt[i]));
vm.push_back(vm[i]+(am[i]*dt[i]));
xe.push_back(xe[i]+ve[i]*dt[i]);
xm.push_back(xm[i]+vm[i]*dt[i]);
dt.push_back(dt[i]);

cout << norm(vm[i]) << " " << norm(r) << endl;



 } 
    return 0;
}





}

