#include <iostream>
#include <iomanip>
#include <string>
// #include <cmath>
using namespace std;
const auto Column = 2997924580;
const float Force=1e5;
const float Energy=1e7;
const float Viscosity=10;


int main() {
system("chcp 1251"); //��� ����������� ����������� ��������
cout<<endl;

cout<<"�������� ������� ��������� ��� �������� �� �� � ���"<<endl<<"1:[�����]=��"<<endl<<"2:[����]=�"<<endl
<<"3:[�������]=��"<<endl<<"4:[��������]=��*�"<<endl;
float user_input,result=0;
int choise;
cout<<"�������� �����"<<endl;
cin>>choise;
cout<<"������� �������� �������� ��� �������� � ���"<<endl;
cin>>user_input;

// cout<<choise;
switch (choise){
  case 1:
    result=user_input*Column;
    cout<<result<<" ��. ����"<<endl;
    break;
  case 2:
    result=user_input*Force;
    cout<<result<<" ���(�)"<<endl;
    break;
  case 3:
    result=user_input*Energy;
    cout<<result<<" ���"<<endl;
    break;
  case 4:
    result=user_input*Viscosity;
    cout<<result<<" ����(�)"<<endl;
    break;
  default:
    cout<<"������������ ����";
    break;
}


return (0);
}
