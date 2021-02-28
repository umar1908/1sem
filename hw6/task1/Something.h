#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Something{
private:
  size_t n;
  int* ptr;
  vector<int> v;
public:
  Something();//����������� �� ���������
  Something(const Something&);//����������� �����������
  Something(Something&&);//����������� �����������
  ~Something();//����������
  Something& operator=(const Something&);//�������� ������������ ������������
  Something& operator=(Something&&);//�������� ������������ ������������
  Something(vector<int>&); //����������� ��� �������� �������� �� ���������� �� ����������� �������
  void print();//����� ������. ������� �� ������� �� ��, ��� �� ���������� �������� <<
  // ������� ����� �� ������ ���� ��������

};
