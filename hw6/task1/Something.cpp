#include "Something.h"
#include <vector>
#include <iostream>
using namespace std;


Something::Something():n(0),ptr(nullptr),v(vector<int>()){}



Something::Something(const Something& other){
  n=other.n;
  v=other.v;
  if (n==0){
    ptr=nullptr;
  }
    else{
    ptr=new int[n];
    for (size_t i = 0; i < n; i++) {
      ptr[i]=other.ptr[i];
    }
  }

}



Something::Something(Something&& other){
  n=other.n;
  ptr=other.ptr;
  other.ptr=nullptr;
  v=move(other.v);

}



Something::~Something(){
  v.clear();
  delete[] ptr;
  cout<<"Объект удален"<<endl;
}



Something& Something::operator=(const Something& other){
  if (this==&other){
    return *this;
  }
  v=other.v;
  if (n==0){
    ptr=nullptr;
    return *this;
  }
  n=other.n;
  v=other.v;
  delete[] ptr;
  ptr=new int[n];
  for (size_t i = 0; i < n; i++) {
    ptr[i]=other.ptr[i];
  }
  return *this;
}



Something& Something::operator=(Something&& other){
  if (this==&other){
    return *this;
  }
  n=other.n;
  v=move(other.v);
  delete[] ptr;
  ptr=other.ptr;
  other.ptr=nullptr;
  return *this;
}

Something::Something(vector<int>& _v){
  n=_v.size();
  ptr=new int [n];
  for (size_t i = 0; i < n; i++) {
    ptr[i]=_v.at(i);
  }
  v=move(_v);
}

void Something::print(){
  if (ptr==nullptr){
    cout<<"У меня ничего нет :(\n";
    return;
  }
  cout<<"n="<<n<<endl;
  cout<<"Стандартный динамический массив:";
  cout<<"(";
  for (size_t i = 0; i < n; i++) {
    cout<<ptr[i]<<" ";
  }
  cout<<")"<<endl;
  cout<<"Вектор:";
  cout<<"(";
  for(auto elem:v){
    cout<<elem<<" ";
  }
  cout<<")"<<endl;

}
