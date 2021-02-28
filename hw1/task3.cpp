#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<"Введите коэффициенты уравнения ax^2+bx+c"<<endl;
  float a=0,b=0,c=0;
  cin>>a>>b>>c;
  if (a==0) {
    cout<<"Данное уравнение не квадратное";
    exit(0);
  }
  float x1=0,x2=0;
  float D=b*b-4*a*c;
  if (D>0) {
    x1=(-b+sqrt(D))/(2*a);
    x2=(-b-sqrt(D))/(2*a);
    cout<<"x1="<<x1<<endl<<"x2="<<x2<<endl;
  }
  else if (D==0) {
    x1=-b/(2*a);
    cout<<"x="<<x1<<endl;
  }
  else{
    cout<<"Решений нет";
  }
  return 0;
}
