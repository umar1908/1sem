#include <iostream>
#include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>
using namespace std;

void f1(double);
void f1(float);
void f2(double);
void f2(double&);
// void f3(int);
void f3(int, int=5);
void f3(int);



int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  cout<<"������ �������. �������� ���������� �����"<<endl;
  f1(1.0); //��� ���������������
  f1(1.0f); // ��� ��������������
  // f1(1) // ������ ����������
  cout<<endl<<"������ �������. �������� �� ������ � �� ��������"<<endl;
  double x=2.0;
  // f2(x); // ������ ����������
  cout<<endl<<"������ �������. �������� �� ���������"<<endl;
  f3(1,2); //��� ���������������
  // f3(1); // ������ ����������


  return 0;
}



void f1(double x){
  cout<<"double "<<x<<endl;
  return;
}

void f1 (float x){
  cout<<"float "<<x<<endl;
  return;
}
void f2(double x){
  cout<<"�� ��������: "<<x;
  return;
}
void f2(double& x){
  cout<<"�� ������: "<<x;
  return;
}
void f3(int x,int y){ // � ���������� ������� ��� y ���� ������� �� ���������
  cout<<"x="<<x<<" y="<<y<<endl;
  return;
}

void f3(int x){
  cout<<"x="<<x<<endl;
  return;
}
