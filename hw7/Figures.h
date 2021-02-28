#pragma once
#include "Primitives.h"

class Figure{
private:
  string _name;
  vector<Point> _points;
  friend ostream& operator<<(ostream&, const Figure&); //перегрузка оператора вывода
  virtual ostream& print(ostream&)const=0;
public:
  Figure(string&, vector<Point>&&); //будем использовать семантику перемещени€
  const string& get_name() const;
  const vector<Point>& get_points() const;
  virtual ~Figure(){}
  virtual double area()const=0;
  virtual double perimeter()const=0;
protected:
  set_points () const;

};


class Elipse: public Figure{
private:
  double _a;
  double _b;
  virtual ostream& print(ostream&)const override;
public:
  Elipse(const Point&,const Point&,double,double,string="Elipse");
  virtual ~Elipse(){}
  virtual double area() const override;
  virtual double perimeter() const override;
};




class Circle:public Elipse{
private:
  double _radius;
  virtual ostream& print(ostream&) const override;
public:
  Circle(const Point&, const Point&,string="Circle");
  virtual ~Circle(){}
//на самом деле т.к круг €вл€етс€ частным случаем эллипса, то
// фукции вычислени€ площади и периметра можно было бы и не переписывать. ѕереписываю дл€ тренировки
virtual double area() const override;
virtual double perimeter()const  override;
};


class Polygon:public Figure{
private:
  int _n;
  ostream& print(ostream&)const=0;
public:
  Polygon(vector<Point>&,string);
  virtual ~Polygon(){}
  virtual double area()const=0;
  virtual double perimeter() const=0;
  virtual int get_n()const final{return _n;}
};

class Quadrancle:public Polygon{
private:
  ostream& print(ostream&)const=0;
public:
  Quadrancle(vector<Point>&,string);
  virtual ~Quadrancle(){}
  virtual double area()const=0;
  virtual double perimeter() const=0;

};



class Parallelogram:public Quadrancle{
private:
  ostream& print(ostream&) const override;
public:
  Parallelogram(vector<Point>&&,string="Parallelogram");
  virtual ~Parallelogram(){}
  virtual double area() const override;
  virtual double perimeter() const override;
protected:
  double _angle;
  double _a;
  double _b;
};

class Rectangle:virtual public Parallelogram{
private:
ostream& print(ostream&) const override;
public:
  Rectangle(vector<Point>&&,string="Rectangle");
  virtual ~Rectangle(){}
  virtual double area() const override;
  virtual double perimeter() const override;

};

class Rhombus:virtual public Parallelogram{
private:
  ostream& print(ostream&) const override;
public:
  Rhombus(vector<Point>&&,string="Rhombus");
  virtual ~Rhombus(){}
  //площадь переписывать сложно. ѕридетс€ высчитывать диаганали.
  // ≈сли необходимо, то переопределю
  virtual double perimeter() const override;
};



class Triangle:public Polygon{
private:
  double _a;
  double _b;
  double _c;
  ostream& print(ostream&) const override;
public:
  Triangle(vector<Point>&&,string="Triangle");
  virtual ~Triangle(){}
  virtual double area() const override;
  virtual double perimeter() const override;
};


class Square:public Rectangle, public Rhombus{
private:
  ostream& print(ostream&) const override;
public:
  Square(vector<Point>&&,string="Square");
  virtual ~Square(){}
  virtual double area() const override;
  virtual double perimeter() const override;

};
