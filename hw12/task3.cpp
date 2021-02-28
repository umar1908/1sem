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




//факториал
// template<int n>
// struct fact{
//   constexpr static int value=n*fact<n-1>::value;
// };
//
// template<>
// struct fact<0>{
//   constexpr static int value=1;
// };
//
// template<>
// struct fact<1>{
//   constexpr static int value=1;
// };
//



// template<int n>
// struct exp{
//   constexpr static double value=exp<n-1>::value+1.0/fact<n>::value;
// };
//
// template<>
// struct exp<1>{
//   constexpr static double value=1;
// };


constexpr int fact(int n){
  if (n==0 || n==1){
    return 1;
  }
  return n*fact(n-1);
}

constexpr double exp(double n){
  if (n==1.0){
    return 1.0;
  }
  return exp(n-1)+1.0/fact(n);
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  //параметр шаблона- количество членов в многочлене тейлора
  cout<<setprecision(10);
   cout<<exp(1)<<endl;
   cout<<exp(2)<<endl;
   cout<<exp(3)<<endl;
   cout<<exp(4)<<endl;
   cout<<exp(5)<<endl;
   cout<<exp(6)<<endl;
   cout<<exp(7)<<endl;
   cout<<exp(8)<<endl;
   cout<<exp(9)<<endl;
   cout<<exp(10)<<endl;
   cout<<exp(11)<<endl;
   cout<<exp(12)<<endl;
   // cout<<exp<13>::value<<endl;



}
