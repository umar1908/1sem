#include <iostream>
#include <iomanip>
// #include "Something.h"
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
 #include <cstdlib>
#include <utility>
#include "Something.h"






int main(){
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  std::vector<int> v{1,2,3,4,5};
  {
    Something thing1(v);//тут происходит кража данных вектора v (так реализован конструктор)
    thing1.print();
    cout<<"*************************\nѕроверка конструктора копировани€ (глубокое копирование)"<<endl;
    {
      Something thing2(thing1); //задействован конструктор копировани€
      cout<<"thing2:"<<endl;
      thing2.print();
      cout<<endl;
    }//тут объект thing2 выходит из зоны видимости и удал€етс€ (его выделенна€ пам€ть тоже очищаетс€).
     // Ќо данные объекта thing1 не затрагиваютс€.Ёто заслуга конструктора копировани€
    cout<<"thing1:"<<endl;
    thing1.print();
    cout<<"****************************\nѕроверка конструктора перемещени€"<<endl;
    Something thing3 (move(thing1)); //передаем thing1 через rvalue, чтобы принудительно
    // задействовать конструктор перемещени€
    cout<<"thing3:"<<endl;
    thing3.print();
    cout<<"\nthing1:"<<endl;
    thing1.print();
  }
  cout<<"\nѕроверка операторов присваивани€ копированием"<<endl;
  std::vector<int> v2{1,1,1,1,1};
  Something thing4(v2);
  cout<<"thing4:"<<endl;
  thing4.print();
  {
  Something thing5;//создадим объект с конструктором по умолчанию
  cout<<"thing5:"<<endl;
  thing5.print();
  thing5=thing4; //оператор присваивани€ копированием
  }//thing5 выходит из зоны видимости и удал€етс€ с освобожднием пам€ти
  cout<<"thing4:"<<endl;// объект thing4 все также существует т.к имело место глубокое копирование
  thing4.print();
  cout<<"\nѕроверка оператора присваивани€ перемещением"<<endl;
  Something thing6;
  thing6=move(thing4);//передача thing4 по rvalue дл€ вызова оператора присваивани€ перемещением
  cout<<"thing6:"<<endl;
  thing6.print();
  cout<<"thing4:"<<endl;
  thing4.print();//этот объект теперь пустой т.к все данные из него переместили в thing6

  return 0;
}
