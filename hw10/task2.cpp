#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>


class Something{
  int param1_;
  double param2_;
public:
  Something(int param1,double param2 ):param1_(param1),param2_(param2){};
  void get_info(){
    cout<<"param1="<<param1_<<" param2="<<param2_<<endl;
  }
  Something():param1_(0),param2_(0){};
};

template<typename T, typename...Types>
unique_ptr<T> create_object(Types...params){
  return unique_ptr<T>(new T(params...));
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;

  auto ptr=create_object<Something>(10,3.2);
  ptr->get_info();

  create_object<Something>()->get_info();
}
