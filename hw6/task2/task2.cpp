#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
#include <cmath>
#include <cstdlib>
// #include<utility>
#include "Fraction.h"



int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  // �������� ������������
  Fraction f1(-1,9);
  Fraction f2(2,10);
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
// �������� �������������� �������1
  cout<<"f1+f2="<<f1+f2<<endl<<endl;
  cout<<"f1-f2="<<f1-f2<<endl<<endl;
  cout<<"f1*f2="<<f1*f2<<endl<<endl;
  cout<<"f1/f2="<<f1/f2<<endl<<endl;
// �������� ���������� int � double � frac
  cout<<"f1+2.3="<<f1+2.3<<endl<<endl;
  cout<<"f1+2="<<f1+2<<endl<<endl;
  cout<<"f1*2.3="<<f1*2.3<<endl<<endl;
  cout<<"f1/2.3="<<f1/2.3<<endl<<endl;
// ������� ������ ����������� double � frac
  f1=73.0/127.0;
  cout<<"73/127(double)="<<f1<<"(frac)"<<endl<<endl;
  f2=f1;
  cout<<"f2=f1; f2="<<f2<<endl<<endl;


// �������� ���������� += -= *= /=
  f1=Fraction(1.25);
  f2=Fraction(9,4);
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
  f1+=f2;
  cout<<"f1+=f2->f1="<<f1<<endl<<endl;
  f1-=f2;
  cout<<"f1-=f2->f1="<<f1<<endl<<endl;
  f1*=f2;
  cout<<"f1*=f2->f1="<<f1<<endl<<endl;
  f1/=f2;
  cout<<"f1/=f2->f1="<<f1<<endl<<endl;

//�������� ����������� � ������������ ���������� � ����������
Fraction f3;
  f3=f1++;
  cout<<"f3=f1++ ->f1="<<f1<<" f3="<<f3<<endl<<endl;
  f3=++f1;
  cout<<"f3=++f1->f1="<<f1<<" f3="<<f3<<endl<<endl;

  f3=f1--;
  cout<<"f3=f1-- ->f1="<<f1<<" f3="<<f3<<endl<<endl;
  f3=--f1;
  cout<<"f3=--f1->f1="<<f1<<" f3="<<f3<<endl<<endl;
// �������� ������� �������� - + !(�������� �����)
  cout<<"f3="<<f3<<" -f3="<<-f3<<endl<<endl;
  cout<<"f3="<<f3<<" +f3="<<+f3<<endl<<endl;
  cout<<"f3="<<f3<<" (f3)^-1="<<!f3<<endl<<endl;
// �������� ���������� ����� frac � double
  double x= static_cast<double>(f3);
  cout<<"double x=f3 ,x="<<x<<endl<<endl;
// �������� ��������� �����
  Fraction f4;
  cout<<"������� ��������� � �����������\n";
  cin>>f4;
  cout<<"f4="<<f4<<endl<<endl;

// �������� ���������� ���������
  f1=Fraction(-1,2);
  f2=Fraction(f1);
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
  cout<<boolalpha<<"f1==f2 "<<(f1==f2)<<endl<<endl;
  cout<<boolalpha<<"f1!=f2 "<<(f1!=f2)<<endl<<endl;
  f1++;
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
  cout<<boolalpha<<"f1==f2 "<<(f1==f2)<<endl<<endl;
  cout<<boolalpha<<"f1!=f2 "<<(f1!=f2)<<endl<<endl;
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
  cout<<boolalpha<<"f1<f2 "<<(f1<f2)<<endl<<endl;
  cout<<boolalpha<<"f1>f2 "<<(f1>f2)<<endl<<endl;
  f1=Fraction(f2);
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
  cout<<boolalpha<<"f1<=f2 "<<(f1<=f2)<<endl<<endl;
  cout<<boolalpha<<"f1>=f2 "<<(f1>=f2)<<endl<<endl;


  return 0;
}
