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
#include "Calculation_methods.h"




template<typename T>
class Base_subject{ //базовый предмет. Весь общий для наследникв функционал будет выполняться тут
public:
  double final_result(){ //вычисление итогового результата
    double crit1=self()->calculate_criteria1(self()->x_,self()->y_);//вычисление первой компоненты
    double crit2=self()->calculate_criteria2(self()->x_,self()->y_);//вычисление второй компоненты
    return crit1+crit2;
  }
  void set_method_for_criteria1(Calculation_method* method){ //установка метода вычисления критерия 1
    self()->method_for_criteria1=method;
  }
  void set_method_for_criteria2(Calculation_method* method){ //установка метода вычисления критерия 2
    self()->method_for_criteria2=method;
  }
private:
  T* self(){ //получение указателя на дочерний объект для доступа к специфичной
    // части конерктного наследника
    return static_cast<T*>(this);
  }
};



class SubjectA:public Base_subject<SubjectA>{
  friend class Base_subject<SubjectA>;
private:
  double x_=10;
  double y_=5;
  Calculation_method* method_for_criteria1; //хранится метод вычисления перавой компоненты
  Calculation_method* method_for_criteria2; //хранится метод вычислений второй компоненты

  double calculate_criteria1(double x,double y){ //вычисление первой компоенты
    return method_for_criteria1->execute(x,y);
  }
  double calculate_criteria2(double x,double y){ //вычисление второй компоненты
    return method_for_criteria2->execute(x,y);
  }
public:
  SubjectA(){ //конструктор по умолчанию
    Calculation_methodA default_method;
    method_for_criteria1=&default_method;
    method_for_criteria2=&default_method;
  }
};
int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;



  SubjectA a;
  Calculation_methodA method_a;
  Calculation_methodB method_b;
  Calculation_methodC method_c;

  a.set_method_for_criteria1(&method_a); //этот метод выполняется в базовом классе
  a.set_method_for_criteria2(&method_b); //этот метод выполняется в базовом классе
  cout<<a.final_result()<<endl; //этот метод выполняется в базовом классе

  a.set_method_for_criteria2(&method_c);//этот метод выполняется в базовом классе
  cout<<a.final_result()<<endl;//этот метод выполняется в базовом классе

}

/*  Как видим при применениее MixLn вся общая для наследников работы происходит
в базовом классе. Это несколько сокращает код (в случае виртуальных функций
приходится объявлять весь функционал в базовом классе а затем реализовывать
его в наследуемых). Mixln называется перевенутым т.к в классическом Mixln
дочерние классы расширяются функционалом родительских, а в данном случае у нас
функционал базового класса расширяется с помощью отличающихся методов дочерних классов*/
