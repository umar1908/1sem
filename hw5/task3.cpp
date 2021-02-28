#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>


class A;

//������ ����� ��� ������� � ����� ������ �;
// ������������ ���� ������ ��������� � ��������� �����, ������ ������� ����������
// ������ ������ ������ ������������� ������ �������

class key_x{
private:
  // ���� ����� �������� ������� ������, ������� ����� ��������� ������ � ���� �
  friend void f1(A);
  key_x(){};
};
class key_y{
private:
  // ���� ����� �������� ������� ������, ������� ����� ��������� ������ � ���� y
  friend void f2(A);
  key_y(){};
};
class key_z{
private:
  // ���� ����� �������� ������� ������, ������� ����� ��������� ������ � ���� z
  friend void f3(A);
  key_z(){};
};

class A{
private:
  int x;
  int y;
  int z;
public:
  A(int _x,int _y,int _z):x(_x),y(_y),z(_z){}//�����������
  // ���� ����������, ��� ������ � �������� ���������� ����� ��������� ���������������� ������ (�����)
  int get_x(key_x) const{
    return x;
  }
  int get_y(key_y) const{
    return y;
  }
  int get_z(key_z) const{
    return z;
  }
  void set_x(key_x,int x){
    this->x=x;
  }
  void set_y(key_y,int y){
    this->y=y;
  }
  void set_z(key_z,int z){
    this->z=z;
  }
};

void f1(A a){
  cout<<"f1 start"<<endl;
  cout<<"x="<<a.get_x(key_x())<<endl;
  // cout<<a.get_y(key_y()); //������� ������ �.� f1 �� ������ ������ ��������� ������ key_x
  // cout<<a.get_z(key_z()); //������� ������
  a.set_x(key_x(),2);
  cout<<"x="<<a.get_x(key_x())<<endl<<"f1 finish"<<endl;
}


void f2(A a){
  cout<<"f2 start"<<endl;
  cout<<"y="<<a.get_y(key_y())<<endl;
  // cout<<a.get_x(key_x()); //������� ������ �.� f2 �� ������ ������ ��������� ������ key_x
  // cout<<a.get_z(key_z()); //������� ������
  a.set_y(key_y(),6);
  cout<<"y="<<a.get_y(key_y())<<endl<<"f2 finish"<<endl;
}

void f3(A a){
  cout<<"f3 start"<<endl;
  cout<<"z="<<a.get_z(key_z())<<endl;
  // cout<<a.get_x(key_x()); //������� ������ �.� f3 �� ������ ������ ��������� ������ key_x
  // cout<<a.get_y(key_y()); //������� ������
  a.set_z(key_z(),0);
  cout<<"z="<<a.get_z(key_z())<<endl<<"f3 finish"<<endl;
}

int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  A a(1,2,3);
  f1(a);
  f2(a);
  f3(a);
  return 0;
}
