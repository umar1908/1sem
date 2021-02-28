#include "Primitives.h"
#include <cmath>
Point::Point(double x_,double y_):x(x_),y(y_){}
double Point::get_x()const{return x;}
double Point::get_y()const{return y;}

double Point::distance(const Point& other) const{
  return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
}

ostream& operator<<(ostream& out, const Point& point){
  cout<<"x="<<point.x<<" y="<<point.y;
  return out;
}

Vector::Vector(double x_,double y_):Point(x_,y_){}
Vector::Vector(const Point& begin, const Point& end):Point(end.get_x()-begin.get_x(),end.get_y()-begin.get_y()){}

double Vector::v_abs() const{
  return sqrt(get_x()*get_x()+get_y()*get_y());
}
double Vector::angle(const Vector& other)const{
  double scalar_product=this->x*other.x+this->y*other.y;
  return acos(scalar_product/(this->v_abs()*other.v_abs()));
}
