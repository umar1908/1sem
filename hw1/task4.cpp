#include <iostream>
// #include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>
using namespace std;
int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  cout<<"������� ����� x"<<endl;
  int x;
  cin>>x;
  cout<<"������� ����� y"<<endl;
  int y;
  cin>>y;
  x+=y;
  y=x-y;
  x-=y;
  cout<<"x="<<x<<" y="<<y;

  return 0;
}
