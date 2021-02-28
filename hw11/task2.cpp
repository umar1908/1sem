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



/* Решение основано на том, что const нельзя навесить только на ссылки и функции.
Поэтому в начале я пытаюсь добавить const к типу с помощью ранее написанной add_const
и если при этом тип не изменлся (проверяю с помощью is_same) то переданнный тип
или функция или сслыка. Чтобы если подействовать на тип remove_reference, то ссылка изменит свой тип,
а функция -нет. С помощью is_same проверяю это и если на тип не навешивается const
и он не изменяется в резульате действия remove_reference , то это функция*/
template<typename T>
struct is_function{
static constexpr bool value=(std::is_same< T, typename add_const<T>::type >::value && //проверка на то, позможно ли нацепить на тип const
  std::is_same< T, typename std::remove_reference<T>::type >::value); // проверка на то, является ли тип ссылкой
  // using type=
};

void f();


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  std::cout<<std::endl;

  std::cout<< is_function<decltype(f)>::value<<std::endl;
  std::cout<< is_function<int>::value;



}
