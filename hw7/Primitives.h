#pragma once
#include <iostream>
using namespace std;class Point{
private:
  friend ostream& operator<<(ostream&, const Point&);

public:
  Point(double,double);
  double get_x()const;
  double get_y()const;
  double distance(const Point&) const;
protected:
  double x;
  double y;
};



class Vector:public Point{
public:
  Vector(double,double);
  Vector(const Point&, const Point&);
  double v_abs() const;
  double angle(const Vector& other)const;
};
