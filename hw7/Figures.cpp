#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
#include <algorithm>
#include <vector>
// #include <string>
#include <cmath>
// #include <cstdlib>
// #include<utility>
#include "Primitives.h"
#include "Figures.h"

#ifndef M_PI
       #define M_PI 3.14159265358979323846 //почему-то не во всех компиляторах при
       // подключении cmath определяется константа M_PI
#endif

const auto pi=M_PI;

const string& Figure::get_name() const{return _name;}
const vector<Point>& Figure::get_points() const{return _points;}

Figure::Figure(string& name,  vector<Point>&& points):
      _name(move(name)),_points(points){
  cout<<"Создан объект Figure\n";
}

ostream& operator<<(ostream& out, const Figure& fig){
  return fig.print(out);
}



Elipse::Elipse(const Point& focus1,const Point& focus2,double a,
              double b,string name):
  Figure(name,vector<Point>{focus1,focus2}),_a(a),_b(b){
  cout<<"Создан объект Elipse\n";
};


ostream& Elipse::print(ostream& out) const{
  out<<"Имя фигуры:"<<get_name()<<endl<<"Большая полуось:a="
  <<_a<<"\nМеньшая полуось:b="<<_b<<endl<<"Координаты точек:"<<endl;
  out<<"Фокус 1 "<<get_points().front()<<endl;
  out<<"Фокус 2 "<<get_points().back()<<endl;
  out<<setprecision(2)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(2)<<"Площадь: S="<<area();
  return out;
}

double Elipse::area() const {
  return pi*_a*_b;
}
double Elipse::perimeter ()const {
  return 4*(pi*_a*_b+(_a-_b))/(_a+_b);
}


Circle::Circle(const Point& center, const Point& point,string name):
              Elipse(center,center,point.distance(center),point.distance(center),name),
              _radius(point.distance(center)){
  cout<<"Создан объекта Circle"<<endl;
}

ostream& Circle::print(ostream& out) const{
  out<<setprecision(2)<<"Имя фигуры:"<<get_name()<<endl<<"Радиус:R="<<_radius<<endl<<"Координаты точек:"<<endl;
  out<<"Центр "<<get_points().front()<<endl;
  out<<setprecision(2)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(2)<<"Площадь: S="<<area();
  return out;
}

double Circle::area() const {
  return _radius*_radius*pi;
}
double Circle::perimeter() const {
  return 2*pi*_radius;
}


Polygon::Polygon(vector<Point>& points,string name="Polygon"):
        Figure(name,move(points)),_n(points.size()){
  cout<<"Создан объект Polygon"<<endl;
}

Quadrancle::Quadrancle(vector<Point>& points,string name="Quadrancle"):Polygon(points,name){
  if (get_n()!=4){
    cerr<<"Неверный ввод четырехугольника";
    exit(0);
  }
  cout<<"Создан объект Quadrancle"<<endl;
}

Parallelogram::Parallelogram(vector<Point>&& points,string name):Quadrancle(points,name){

  vector<Vector> vectors;
  for (const auto& elem:get_points()){
    vectors.push_back(Vector(get_points().front(),elem));
  }
  sort(vectors.begin(),vectors.end(),[](Vector x, Vector y)->bool{return x.v_abs()<y.v_abs();});
  _angle=vectors.at(1).angle(vectors.at(2));
  cout<<"Создан объект Parellelepiped"<<endl;
  _a=vectors.at(1).v_abs();
  _b=vectors.at(2).v_abs();
}

ostream& Parallelogram::print(ostream& out) const{
  out<<"Имя фигуры:"<<get_name()<<endl<<"Координаты точек:"<<endl;
  for (const auto& elem:get_points()){
    out<<showpos<<elem<<endl;
  }
  out<<noshowpos<<"a="<<_a<<endl<<"b="<<_b<<endl;
  out<<setprecision(3)<<"Угол между сторонами:angle="<<_angle/pi<<"pi"<<endl;
  out<<setprecision(2)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(2)<<"Площадь: S="<<area();
  return out;
}

double Parallelogram::area() const {
  return _a*_b*sin(_angle);
}
double Parallelogram::perimeter() const {
  return 2*(_a+_b);
}


Rectangle::Rectangle(vector<Point>&& points, string name):
                    Parallelogram(move(points),name){
  if (_angle!=0.5*pi){
    cerr<<"Неверно задан Rectangle"<<endl;
    exit(0);
  }
  cout<<"Создан объект Rectangle"<<endl;
}

ostream& Rectangle::print(ostream& out) const{
  out<<"Имя фигуры:"<<get_name()<<endl<<"Координаты точек:"<<endl;
  for (const auto& elem:get_points()){
    out<<showpos<<elem<<endl;
  }
  out<<noshowpos<<"a="<<_a<<endl<<"b="<<_b<<endl;
  out<<setprecision(2)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(2)<<"Площадь: S="<<area();
  return out;
}


double Rectangle::area() const{
  return _a*_b;
}
double Rectangle::perimeter() const{
  return (_a+_b)*2;
}


Rhombus::Rhombus(vector<Point>&& points,string name):
                Parallelogram(move(points),name){
  if (_a!=_b){
    cerr<<"Неверный ввод Rectangle";
    exit(0);
  }
  cout<<"Создан объект Rhombus"<<endl;
}

ostream& Rhombus::print(ostream& out) const{
  out<<"Имя фигуры:"<<get_name()<<endl<<"Координаты точек:"<<endl;
  for (const auto& elem:get_points()){
    out<<showpos<<elem<<endl;
  }
  out<<noshowpos<<"a="<<_a<<endl;
  out<<setprecision(2)<<"Угол angle="<<_angle/pi<<"pi"<<endl;
  out<<setprecision(4)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(4)<<"Площадь: S="<<area();
  return out;
}

double Rhombus::perimeter() const{
  return 4*_a;
}


ostream& Triangle::print(ostream& out)const {
  out<<"Имя фигуры:"<<get_name()<<endl<<"a="<<_a<<"\nb="<<_b<<"\nc="<<_c<<"\nКоординаты точек:"<<endl;
  for (const auto& elem:get_points()){
    out<<showpos<<elem<<endl;
  }
  out<<setprecision(4)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(4)<<"Площадь: S="<<area()<<endl;
  return out;
}


Triangle::Triangle(vector<Point>&& points,string name):Polygon(points,name){
  if (get_n()!=3){
    cerr<<"Неверно введен Triangle"<<endl;
    exit(0);
  }
  Vector ab(get_points()[0],get_points()[1]);
  Vector ac(get_points()[0],get_points()[2]);
  Vector bc(get_points()[1],get_points()[2]);
  _c=ab.v_abs();
  _b=ac.v_abs();
  _a=bc.v_abs();


  cout<<"Создан объект Triangle"<<endl;
}

double Triangle::area()const{
  Vector ab(get_points()[0],get_points()[1]);
  Vector ac(get_points()[0],get_points()[2]);
  return 0.5*ab.v_abs()*ac.v_abs()*sin(ab.angle(ac));
}

double Triangle::perimeter()const{
  return _a+_b+_c;
}

Square::Square(vector<Point>&& points,string name):Parallelogram(move(points),name),Rectangle(move(points),name),Rhombus(move(points),name){
  cout<<"создан объект Square"<<endl;
}

ostream& Square::print(ostream& out)const{
  out<<"Имя фигуры:"<<get_name()<<endl<<"a="<<_a<<"\nКоординаты точек:"<<endl;
  for (const auto& elem:get_points()){
    out<<showpos<<elem<<endl;
  }
  out<<setprecision(4)<<"Периметр:P="<<perimeter()<<endl;
  out<<setprecision(4)<<"Площадь: S="<<area()<<endl;
  return out;
}


double Square::area()const {
  return _a*_a;
}
double Square::perimeter()const{
  return 4*_a;
}
