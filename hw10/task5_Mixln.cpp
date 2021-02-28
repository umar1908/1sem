#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
#include "Calculation_methods.h"




template<typename T>
class Base_subject{ //������� �������. ���� ����� ��� ���������� ���������� ����� ����������� ���
public:
  double final_result(){ //���������� ��������� ����������
    double crit1=self()->calculate_criteria1(self()->x_,self()->y_);//���������� ������ ����������
    double crit2=self()->calculate_criteria2(self()->x_,self()->y_);//���������� ������ ����������
    return crit1+crit2;
  }
  void set_method_for_criteria1(Calculation_method* method){ //��������� ������ ���������� �������� 1
    self()->method_for_criteria1=method;
  }
  void set_method_for_criteria2(Calculation_method* method){ //��������� ������ ���������� �������� 2
    self()->method_for_criteria2=method;
  }
private:
  T* self(){ //��������� ��������� �� �������� ������ ��� ������� � �����������
    // ����� ����������� ����������
    return static_cast<T*>(this);
  }
};



class SubjectA:public Base_subject<SubjectA>{
  friend class Base_subject<SubjectA>;
private:
  double x_=10;
  double y_=5;
  Calculation_method* method_for_criteria1; //�������� ����� ���������� ������� ����������
  Calculation_method* method_for_criteria2; //�������� ����� ���������� ������ ����������

  double calculate_criteria1(double x,double y){ //���������� ������ ���������
    return method_for_criteria1->execute(x,y);
  }
  double calculate_criteria2(double x,double y){ //���������� ������ ����������
    return method_for_criteria2->execute(x,y);
  }
public:
  SubjectA(){ //����������� �� ���������
    Calculation_methodA default_method;
    method_for_criteria1=&default_method;
    method_for_criteria2=&default_method;
  }
};
int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;



  SubjectA a;
  Calculation_methodA method_a;
  Calculation_methodB method_b;
  Calculation_methodC method_c;

  a.set_method_for_criteria1(&method_a); //���� ����� ����������� � ������� ������
  a.set_method_for_criteria2(&method_b); //���� ����� ����������� � ������� ������
  cout<<a.final_result()<<endl; //���� ����� ����������� � ������� ������

  a.set_method_for_criteria2(&method_c);//���� ����� ����������� � ������� ������
  cout<<a.final_result()<<endl;//���� ����� ����������� � ������� ������

}

/*  ��� ����� ��� ����������� MixLn ��� ����� ��� ����������� ������ ����������
� ������� ������. ��� ��������� ��������� ��� (� ������ ����������� �������
���������� ��������� ���� ���������� � ������� ������ � ����� �������������
��� � �����������). Mixln ���������� ����������� �.� � ������������ Mixln
�������� ������ ����������� ������������ ������������, � � ������ ������ � ���
���������� �������� ������ ����������� � ������� ������������ ������� �������� �������*/
