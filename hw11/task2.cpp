#include <iostream>
#include <iomanip>
// using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
#include<utility>
// #include <exception>
// #include <bitset>
#include <typeinfo>
#include <type_traits>


template<typename T>
struct add_const{
using type=const T;
};

template<typename T>
struct add_const<const T>{
using type=T;
};



/* ������� �������� �� ���, ��� const ������ �������� ������ �� ������ � �������.
������� � ������ � ������� �������� const � ���� � ������� ����� ���������� add_const
� ���� ��� ���� ��� �� �������� (�������� � ������� is_same) �� ����������� ���
��� ������� ��� ������. ����� ���� ������������� �� ��� remove_reference, �� ������ ������� ���� ���,
� ������� -���. � ������� is_same �������� ��� � ���� �� ��� �� ������������ const
� �� �� ���������� � ��������� �������� remove_reference , �� ��� �������*/
template<typename T>
struct is_function{
static constexpr bool value=(std::is_same< T, typename add_const<T>::type >::value && //�������� �� ��, �������� �� �������� �� ��� const
  std::is_same< T, typename std::remove_reference<T>::type >::value); // �������� �� ��, �������� �� ��� �������
  // using type=
};

void f();


int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  std::cout<<std::endl;

  std::cout<< is_function<decltype(f)>::value<<std::endl;
  std::cout<< is_function<int>::value;



}
