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
// #include <exception>
// #include <bitset>


template<typename T>
class Parent{
public:
  void print(){
    static_cast<T*>(this)->print();
  }
};



class Child_A:public Parent<Child_A>{
  friend class Parent<Child_A>;
  void print(){
    cout<<"I am Child A\n";
  }
};

class Child_B:public Parent<Child_B>{
  friend class Parent<Child_B>;
  void print(){
    cout<<"I am Child B\n";
  }
};


class Virtual_Parent{
public:
  virtual void print()const=0;
  ~Virtual_Parent()=default;
};
class Virtual_Child_A:public Virtual_Parent{
public:
  virtual ~Virtual_Child_A()=default;
  virtual void print()const override{
    cout<<"I am Child A\n";
  }
};

class Virtual_Child_B:public Virtual_Parent{
public:
  virtual ~Virtual_Child_B()=default;
  virtual void print()const override{
    cout<<"I am Child B\n";
  }
};

void virtual_test( Virtual_Parent* obj){
  obj->print();
}


template<typename T>
void test( Parent<T>* obj){
  obj->print();
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  Child_A a;
  Child_B b;
  test(&a);
  test(&b);

  Virtual_Parent* virt_a=new Virtual_Child_A;
  Virtual_Parent* virt_b=new Virtual_Child_B;
  virtual_test(virt_a);
  virtual_test(virt_b);




}
