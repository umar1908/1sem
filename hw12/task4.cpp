#include <iostream>
#include <iomanip>
// using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
// #include <type_traits>


template<typename T>
struct can_compare{

  // template<typename ...>
private:
  static int detect(...);
  template<typename B>
  static decltype( std::declval<B>()==std::declval<B>() ) detect(const B&);
public:
  constexpr static bool value=std::is_same< decltype( detect(std::declval<T>()) ), bool >::value;
};


template<typename T>
typename std::enable_if<can_compare<T>::value , bool>::type compare(const T& rhs, const T& lhs){
  std::cout<<"Can compare!"<<std::endl;
  return rhs==lhs;
}


template<typename T>
typename std::enable_if<!can_compare<T>::value , bool>::type compare(const T& rhs, const T& lhs){
  std::cout<<"Can`t compare=("<<std::endl;
  return false;
}




class My{};
class My2{
  int _a;
public:
  My2(int a):_a(a){};
  bool operator== (const My2& rhs) const{
    return this->_a==rhs._a;
  }
};

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  std::cout<<std::boolalpha;
  std::cout<<"1==1 "<<compare(1,1)<<std::endl;
  std::cout<<"1==2 "<<compare(1,2)<<std::endl;
  std::cout<<"My()==My() "<<compare(My(),My())<<std::endl;
  std::cout<<"My2(1)==My2(1) "<<compare(My2(1),My2(1))<<std::endl;
  std::cout<<"My2(1)==My2(5) "<<compare(My2(1),My2(5))<<std::endl;




}
