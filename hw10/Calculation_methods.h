#pragma once
#include <cmath>

class Calculation_method{ //базовый метод способа вычислений критериев
public:
  virtual double execute(double,double)const=0;
};
class Calculation_methodA:public Calculation_method{// перавй вариант вычисления критериев
public:
  virtual double execute(double x,double y)const override{
    return x*y;
  }
};
class Calculation_methodB:public Calculation_method{ //второй вариант вычислений критериев
public:
  virtual double execute(double x,double y)const override{
    return x+y;
  }
};
class Calculation_methodC:public Calculation_method{// третий вариант вычсления критериев
public:
  virtual double execute(double x,double y)const override{
    return pow(x,y);
  }
};
