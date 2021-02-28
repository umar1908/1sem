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
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  // проверка конструктора
  Fraction f1(-1,9);
  Fraction f2(2,10);
  cout<<"f1="<<f1<<" f2="<<f2<<endl<<endl;
// проверка арифметических операци1
  cout<<"f1+f2="<<f1+f2<<endl<<endl;
  cout<<"f1-f2="<<f1-f2<<endl<<endl;
  cout<<"f1*f2="<<f1*f2<<endl<<endl;
  cout<<"f1/f2="<<f1/f2<<endl<<endl;
// проверка приведения int и double к frac
  cout<<"f1+2.3="<<f1+2.3<<endl<<endl;
  cout<<"f1+2="<<f1+2<<endl<<endl;
  cout<<"f1*2.3="<<f1*2.3<<endl<<endl;
  cout<<"f1/2.3="<<f1/2.3<<endl<<endl;
// сложный пример конвертации double в frac
  f1=73.0/127.0;
  cout<<"73/127(double)="<<f1<<"(frac)"<<endl<<endl;
  f2=f1;
  cout<<"f2=f1; f2="<<f2<<endl<<endl;


// проверка операторов += -= *= /=
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

//проверка префиксного и постфиксного инкремента и декремента
Fraction f3;
  f3=f1++;
  cout<<"f3=f1++ ->f1="<<f1<<" f3="<<f3<<endl<<endl;
  f3=++f1;
  cout<<"f3=++f1->f1="<<f1<<" f3="<<f3<<endl<<endl;

  f3=f1--;
  cout<<"f3=f1-- ->f1="<<f1<<" f3="<<f3<<endl<<endl;
  f3=--f1;
  cout<<"f3=--f1->f1="<<f1<<" f3="<<f3<<endl<<endl;
// проверка унарных операций - + !(обратная дробь)
  cout<<"f3="<<f3<<" -f3="<<-f3<<endl<<endl;
  cout<<"f3="<<f3<<" +f3="<<+f3<<endl<<endl;
  cout<<"f3="<<f3<<" (f3)^-1="<<!f3<<endl<<endl;
// проверка приведения типов frac к double
  double x= static_cast<double>(f3);
  cout<<"double x=f3 ,x="<<x<<endl<<endl;
// проверка оператора ввода
  Fraction f4;
  cout<<"Введите числитель и знаменатель\n";
  cin>>f4;
  cout<<"f4="<<f4<<endl<<endl;

// Проверка операторов сравнения
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
