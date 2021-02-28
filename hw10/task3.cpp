#include <iostream>
#include <iomanip>
using namespace std;
#include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>


template<typename T1,typename... Types>
  void execute_func(T1 func,Types...params){
    func(params...);
}

template<typename T>
void print_sorted(vector<T> &v){
  sort(v.begin(),v.end());
  for(auto elem:v)
  cout<<elem<<endl;
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;


  execute_func([](int a, int b){cout<< a+b;},1,2); //первый пример использования
  cout<<endl;

  vector<int> v{-6,13,56,2,1,10};
  execute_func(print_sorted<int>,v); //второй пример использования



}
