#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <iomanip>

template<typename T>
struct add_const{
using type=const T;
};

template<typename T>
struct add_const<const T>{
using type=T;
};

template<typename T>
struct remove_const{
using type=T;
};

template <typename T>
struct remove_const<const T>{
using type=T;
};

int main()
{

 std::cout<<"const int == int? "<<std::boolalpha<< std::is_same< const int,int >::value<<std::endl;
 std::cout<< "const int == add_const<int>? "<< std::is_same< const int,add_const<int>::type >::value<<std::endl;

 std::cout<<"int == const int? "<<std::boolalpha<< std::is_same< int, const int >::value<<std::endl;
 std::cout<<"int == remove_const<const int>? "<< std::is_same< int,remove_const<const int>::type >::value;

}
