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

constexpr int check(int a, int b, int current){
  if (current%a==0 && current%b==0){
    return current;
  }
  return check(a,b,current+1);
}

constexpr int nok(int a, int b){
  if (a==0||b==0){
    return 0;
  }
  if (a>=b){
    return check (a,b,a);
  }
  return check(a,b,b);
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;

  cout<<nok(56,10);


}
