#include <iostream>
#include <iomanip>
#include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
using namespace std;
double calculate(double, double, function<double(double,double)>);
int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  double x,y;
  cout<<"������� � � �"<<endl;
  cin>>x>>y;
  vector<function<double(double,double)>> lambda_vector(4);
  lambda_vector={[](double x,double y){return x+y;},[](double x,double y){return x-y;},[](double x,double y){return x*y;},[](double x,double y){return x/y;}};
  for (auto elem: lambda_vector){
    cout<<calculate(x,y,elem)<<endl;
  }


  return 0;
}

double calculate(double x, double y, function<double(double,double)> lambda){
  return lambda(x,y);
}
