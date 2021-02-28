#include <iostream>
#include <iomanip>
#include <string>
// #include <cmath>
using namespace std;
const auto Column = 2997924580;
const float Force=1e5;
const float Energy=1e7;
const float Viscosity=10;


int main() {
system("chcp 1251"); //для корректного отображения кирилицы
cout<<endl;

cout<<"Выберите единицу измерения для перевода из СИ в СГС"<<endl<<"1:[Заряд]=Кл"<<endl<<"2:[Сила]=Н"<<endl
<<"3:[Энергия]=Дж"<<endl<<"4:[Вязкость]=Па*с"<<endl;
float user_input,result=0;
int choise;
cout<<"Выберите номер"<<endl;
cin>>choise;
cout<<"Введите значение величины для перевода в СГС"<<endl;
cin>>user_input;

// cout<<choise;
switch (choise){
  case 1:
    result=user_input*Column;
    cout<<result<<" ед. СГСЭ"<<endl;
    break;
  case 2:
    result=user_input*Force;
    cout<<result<<" Дин(ы)"<<endl;
    break;
  case 3:
    result=user_input*Energy;
    cout<<result<<" Эрг"<<endl;
    break;
  case 4:
    result=user_input*Viscosity;
    cout<<result<<" Пуаз(а)"<<endl;
    break;
  default:
    cout<<"Некорректный ввод";
    break;
}


return (0);
}
