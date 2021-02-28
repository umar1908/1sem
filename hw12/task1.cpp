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


template<int n, int k>
struct binomial{
  constexpr static int value=binomial<n-1,k-1>::value+binomial<n-1,k>::value;
};

template<>
struct binomial<1,1>{
  constexpr static int value=1;
};

template<>
struct binomial<0,0>{
  constexpr static int value=1;
};

template<>
struct binomial<1,0>{
  constexpr static int value=1;
};

template<>
struct binomial<0,1>{
  constexpr static int value=0;
};

template<int k>
struct binomial<0,k>{
  constexpr static int value=0;
};



int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<binomial<14,3>::value<<endl;
  cout<<binomial<10,5>::value<<endl;
  cout<<binomial<6,6>::value<<endl;
  cout<<binomial<2,1>::value<<endl;


}
