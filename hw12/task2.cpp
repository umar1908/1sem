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



template<int n>
struct fib{
  constexpr static int value=fib<n-1>::value+fib<n-2>::value;
};


template<>
struct fib<1>{
  constexpr static int value=0;
};

template<>
struct fib<2>{
  constexpr static int value=1;
};

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;

  cout<<fib<3>::value<<endl;
  cout<<fib<4>::value<<endl;
  cout<<fib<5>::value<<endl;
  cout<<fib<6>::value<<endl;
  cout<<fib<7>::value<<endl;
  cout<<fib<8>::value<<endl;


}
