#include <iostream>
#include <iomanip>
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>

using namespace std;

class Energy_unit{
private:
  static  const double erg;
  static  const double eV;
  double dj;

public:
  Energy_unit(); //конструктор по умолчанию
  // начало блока аксессоров
  double get_dj() const;
  double get_erg() const;
  double get_eV() const;
  void set_dj(double);
  void set_erg(double);
  void set_eV(double);
  friend ostream& operator<<(ostream&, const Energy_unit&);
  // конец блока аксессоров
  ~Energy_unit();//Деструктор
};
const double Energy_unit::erg=1e-7;
const double Energy_unit::eV=1.6e-19;


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  Energy_unit energy_val;
  cout<<"Выберите единицу измерения:\n1:Джоуль\n2:Эрг\n3:эВ\n";
  int n;
  cin>>n;
  cout<<"Введите величину энергии:\n";
  double unit;
  cin>>unit;
  switch(n){
    case 1:
      energy_val.set_dj(unit);
      break;
    case 2:
      energy_val.set_erg(unit);
      break;
    case 3:
      energy_val.set_eV(unit);
      break;
    default:
      cout<<"Некорректный выбор единицы измерения";
      exit(0);
      break;
  }

  cout<<energy_val;

  return 0;
}

Energy_unit::Energy_unit():dj(0){}
double Energy_unit::get_dj()const {return dj;}
double Energy_unit::get_erg()const {return dj/erg;}
double Energy_unit::get_eV()const {return dj/eV;}
void Energy_unit::set_dj(double dj){this->dj=dj;}
void Energy_unit::set_erg(double erg){this->dj=erg*Energy_unit::erg;}
void Energy_unit::set_eV(double eV){this->dj=eV*Energy_unit::eV;}
ostream& operator<<(ostream& os, const Energy_unit& energy_val){
  os<<energy_val.dj<<" Дж"<<endl<<energy_val.get_erg()<<" эрг"<<endl<<energy_val.get_eV()<<" эВ"<<endl;
  return os;
}
Energy_unit::~Energy_unit(){cout<<"Объект уничтожен"<<endl;}
