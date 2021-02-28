#include <iostream>
#include <iomanip>
// #include "Something.h"
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
 #include <cstdlib>
#include <utility>
#include "Something.h"






int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  std::vector<int> v{1,2,3,4,5};
  {
    Something thing1(v);//��� ���������� ����� ������ ������� v (��� ���������� �����������)
    thing1.print();
    cout<<"*************************\n�������� ������������ ����������� (�������� �����������)"<<endl;
    {
      Something thing2(thing1); //������������ ����������� �����������
      cout<<"thing2:"<<endl;
      thing2.print();
      cout<<endl;
    }//��� ������ thing2 ������� �� ���� ��������� � ��������� (��� ���������� ������ ���� ���������).
     // �� ������ ������� thing1 �� �������������.��� ������� ������������ �����������
    cout<<"thing1:"<<endl;
    thing1.print();
    cout<<"****************************\n�������� ������������ �����������"<<endl;
    Something thing3 (move(thing1)); //�������� thing1 ����� rvalue, ����� �������������
    // ������������� ����������� �����������
    cout<<"thing3:"<<endl;
    thing3.print();
    cout<<"\nthing1:"<<endl;
    thing1.print();
  }
  cout<<"\n�������� ���������� ������������ ������������"<<endl;
  std::vector<int> v2{1,1,1,1,1};
  Something thing4(v2);
  cout<<"thing4:"<<endl;
  thing4.print();
  {
  Something thing5;//�������� ������ � ������������� �� ���������
  cout<<"thing5:"<<endl;
  thing5.print();
  thing5=thing4; //�������� ������������ ������������
  }//thing5 ������� �� ���� ��������� � ��������� � ������������ ������
  cout<<"thing4:"<<endl;// ������ thing4 ��� ����� ���������� �.� ����� ����� �������� �����������
  thing4.print();
  cout<<"\n�������� ��������� ������������ ������������"<<endl;
  Something thing6;
  thing6=move(thing4);//�������� thing4 �� rvalue ��� ������ ��������� ������������ ������������
  cout<<"thing6:"<<endl;
  thing6.print();
  cout<<"thing4:"<<endl;
  thing4.print();//���� ������ ������ ������ �.� ��� ������ �� ���� ����������� � thing6

  return 0;
}
