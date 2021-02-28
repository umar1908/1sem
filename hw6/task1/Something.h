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
  Something();//конструктор по умолчанию
  Something(const Something&);//конструктор копирования
  Something(Something&&);//конструктор перемещения
  ~Something();//деструктор
  Something& operator=(const Something&);//оператор присваивания копированием
  Something& operator=(Something&&);//оператоа присваивания перемещением
  Something(vector<int>&); //конструктор для создания объеккта со значениями из переданного вектора
  void print();//метод печати. Надеюсь не побьете за то, что не перегрузил оператор <<
  // задание вроде на другую тему нацелено

};
