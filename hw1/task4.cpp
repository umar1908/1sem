#include <iostream>
// #include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>
using namespace std;
int main(){
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  cout<<"¬ведите число x"<<endl;
  int x;
  cin>>x;
  cout<<"¬ведите число y"<<endl;
  int y;
  cin>>y;
  x+=y;
  y=x-y;
  x-=y;
  cout<<"x="<<x<<" y="<<y;

  return 0;
}
