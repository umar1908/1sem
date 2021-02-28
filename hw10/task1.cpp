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


template<typename...Types>
size_t size_of_args(Types...params){
  return (sizeof(params)+...);
}

size_t size_of_args(){
  return 0;
}


size_t size_of_args_2(){
  return 0;
}

template<typename...Types, typename T>
size_t size_of_args_2(T first,Types...params){
  return sizeof(first)+size_of_args_2(params...);
}




int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  cout<<size_of_args(1,2,3,4,5)<<endl;
  cout<<size_of_args(1,1.2,1.2f)<<endl;
  long long int b,c,d;
  cout<<size_of_args(b,c,d)<<endl;
  cout<<size_of_args()<<endl;

  cout<<size_of_args_2(1,2,3,4,5)<<endl;
  cout<<size_of_args_2(1,1.2,1.2f)<<endl;
  cout<<size_of_args_2(b,c,d)<<endl;
  cout<<size_of_args_2()<<endl;



}
