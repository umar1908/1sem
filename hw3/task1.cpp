#include <iostream>
#include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>
using namespace std;

void f1(double);
void f1(float);
void f2(double);
void f2(double&);
// void f3(int);
void f3(int, int=5);
void f3(int);



int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  cout<<"Первый вариант. Проблема приведения типов"<<endl;
  f1(1.0); //нет неоднозначности
  f1(1.0f); // нет неонозначности
  // f1(1) // ошибка компиляции
  cout<<endl<<"Второй вариант. Передача по ссылке и по значению"<<endl;
  double x=2.0;
  // f2(x); // ошибка компиляции
  cout<<endl<<"Третий вариант. Значение по умолчанию"<<endl;
  f3(1,2); //нет неоднозначности
  // f3(1); // ошибка компиляции


  return 0;
}



void f1(double x){
  cout<<"double "<<x<<endl;
  return;
}

void f1 (float x){
  cout<<"float "<<x<<endl;
  return;
}
void f2(double x){
  cout<<"По значению: "<<x;
  return;
}
void f2(double& x){
  cout<<"По ссылке: "<<x;
  return;
}
void f3(int x,int y){ // в объявлении функции для y дано значене по умолчанию
  cout<<"x="<<x<<" y="<<y<<endl;
  return;
}

void f3(int x){
  cout<<"x="<<x<<endl;
  return;
}
