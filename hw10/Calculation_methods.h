#pragma once
#include <cmath>

class Calculation_method{ //������� ����� ������� ���������� ���������
public:
  virtual double execute(double,double)const=0;
};
class Calculation_methodA:public Calculation_method{// ������ ������� ���������� ���������
public:
  virtual double execute(double x,double y)const override{
    return x*y;
  }
};
class Calculation_methodB:public Calculation_method{ //������ ������� ���������� ���������
public:
  virtual double execute(double x,double y)const override{
    return x+y;
  }
};
class Calculation_methodC:public Calculation_method{// ������ ������� ��������� ���������
public:
  virtual double execute(double x,double y)const override{
    return pow(x,y);
  }
};
