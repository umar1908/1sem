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
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  double x,y;
  cout<<"¬ведите х и у"<<endl;
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
