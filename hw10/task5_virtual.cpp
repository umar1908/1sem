#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
#include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
#include "Calculation_methods.h"


class Base_subject{ //������� �������
private:
  virtual double calculate_criteria1(double,double)const=0; //���������� ������ ���������� �������� ��������
  virtual double calculate_criteria2(double,double)const=0; //���������� ������ ���������� �������� ��������
public:
  virtual void set_method_for_criteria1(Calculation_method*)=0; //��������� ������� ������� ������ ����������
  virtual void set_method_for_criteria2(Calculation_method*)=0; //��������� ������� ������� ������ ����������
  Base_subject()=default;

  virtual double final_result()const=0; //������ ��������� ��������
  virtual ~Base_subject()=default;
};
/* � ������� ������ ��������� ������ ������� ���������. ���� ���������� � ���
�������� ���������� � ������� �����������*/

class SubjectA:public Base_subject{
private:
  double x_=10;//��������� ����������� ��������
  double y_=5;
  Calculation_method* method_for_criteria1; //��� ������� ����� ���������� ������ ����������
  Calculation_method* method_for_criteria2; //��� �������� ����� ���������� ������ ����������
  virtual double calculate_criteria1(double x,double y)const override{
    return method_for_criteria1->execute(x,y);
  }
  virtual double calculate_criteria2(double x,double y)const override{
    return method_for_criteria2->execute(x,y);
  }
public:
  SubjectA(){
    Calculation_methodA default_method;
    method_for_criteria1=&default_method;
    method_for_criteria2=&default_method;
  }
  virtual double final_result()const override{
    return calculate_criteria1(x_,y_)+calculate_criteria2(x_,y_);
  }
  virtual void set_method_for_criteria1(Calculation_method* new_method)override{
    method_for_criteria1=new_method;
  }
  virtual void set_method_for_criteria2(Calculation_method* new_method)override{
    method_for_criteria2=new_method;
  }
};

int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  SubjectA a;
  Calculation_methodA method_a;
  Calculation_methodB method_b;
  Calculation_methodC method_c;

  a.set_method_for_criteria1(&method_a);
  a.set_method_for_criteria2(&method_b);
  cout<<a.final_result()<<endl;

  a.set_method_for_criteria2(&method_c);
  cout<<a.final_result()<<endl;



}
