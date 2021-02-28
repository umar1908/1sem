#pragma once
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
#include <exception>
// #include <bitset>


template<typename T>
class Array{
private:
  T* _ptr;
  int _size;
public:
  Array();
  Array(T* ptr, int size);
  Array(const int& ,const T&);
  Array(const int&, T&& );
  Array(const int&);
  Array(const Array&);
  Array(Array&&);
  ~Array(){if (_ptr!=nullptr)delete[] _ptr;}
  T& operator[](const int&);
  const T& operator[](const int&)const;
  Array& operator=(const Array&);
  Array& operator=(Array&&);
  void resize(int);
  int size()const{return _size;}
  bool is_empty(){return _ptr==nullptr;}
  void clear(){delete[] _ptr;}

};

template <typename T>
Array<T>::Array():_size(0),_ptr(nullptr){
  cout<<"\n\nСоздан пустой массив\n";
}


template <typename T>
Array<T>::Array(T* ptr,int size):_ptr(ptr),_size(size){
  if (size<0){
    throw(logic_error("Размер не может быть отрицательным"));
  }
  cout<<"\n\nСоздан массив из динамического массива\n";
}



template <typename T>
Array<T>::Array(const int& N, T&& filler){
  cout<<"Создание заполненного массива\n";
  if (N<0){
    throw(logic_error("Размер не может быть отрицательным"));
  }
  _size=N;
  _ptr=new T[N];
  for (int i = 0; i < N; i++) {
    _ptr[i]=filler;
  }
}


template<typename T>
Array<T>::Array(const int& N,const T& filler){
  cout<<"Создание заполненного массива\n";
  if (N<0){
    throw(logic_error("Размер не может быть отрицательным"));
  }
  _size=N;
  _ptr=new T[N];
  for (int i = 0; i < N; i++) {
    _ptr[i]=filler;
  }
}

template<typename T>
Array<T>::Array(const int& N){
  cout<<"Создание пустого массива\n";
  if (N<0){
    throw(logic_error("Размер не может быть отрицательным"));
  }
  _size=N;
  _ptr=new T[N];
}


template<typename T>
Array<T>::Array(const Array& obj){
  cout<<"Создание массива копированием\n";
  _ptr=new T[obj._size];
  _size=obj._size;
  for (size_t i = 0; i < _size; i++) {
    _ptr[i]=obj[i];
  }
}
template<typename T>
Array<T>::Array(Array&& obj){
  cout<<"Создание массива перемещением\n";
  _ptr=obj._ptr;
  obj._ptr=nullptr;
  _size=obj._size;
  obj._size=0;
}



template<typename T>
T& Array<T>::operator[](const int& i){
  if (i<0||i>=_size){
    throw(out_of_range("index ["+to_string(i)+"] not possible"));
  }
  return _ptr[i];
}

template<typename T>
const T& Array<T>::operator[](const int& i)const{
  if (i<0||i>=_size){
    throw(out_of_range("index ["+to_string(i)+"] not possible"));
  }
  return _ptr[i];
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& obj){
  cout<<"Оператор присваивания\n";
  _size=obj._size;
  delete[] _ptr;
  _ptr=new T[_size];
  for (size_t i = 0; i < _size; i++) {
    _ptr[i]=obj[i];
  }
  return *this;
}


template<typename T>
Array<T>& Array<T>::operator=(Array&& obj){
  _size=obj._size;
  delete[] _ptr;
  _ptr=obj._ptr;
  obj._ptr=nullptr;
  obj._size=0;
  return *this;
}



template<typename T>
void Array<T>::resize(int N){
  if (N<0){
    throw(out_of_range("Размер не может быть отрицательным\n"));
  }

  T* tmp_ptr=new T[N];
  for (size_t i = 0; i < min(N,this->_size); i++) {
    tmp_ptr[i]=(*this)[i];
  }
  delete[] _ptr;
  _ptr=tmp_ptr;
  _size=N;

}



template<typename T>
void swapp(T& left,T& right){
  T tmp=left;
  left=right;
  right=tmp;
}
