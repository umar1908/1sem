#include <iostream>
#include <iomanip>
// #include <functional>
// #include <algorithm>
// #include <vector>
#include <string>
#include <cstdlib>
// #include <cmath>
using namespace std;
const auto Dollar_rate=78.15;

// Я пытался объявить структуры в начале, а определить их в конце программы,
// но компилятор на это ругался и не давал создавать экземпляр структуры
// внутри main
struct Phone_number{
  Phone_number(short int, short int,int);
  Phone_number();
  short int country_code;
  short int op_code;
  int number;
  void print_number(){
    cout<<"+"<<country_code<<"("<<op_code<<")"<<number<<endl<<"**************"<<endl;
    return;
  }
};

struct Client{
  Client(string, string, int, string, string, double,double,double,Phone_number);
  Client();
  ~Client(){
    cout<<"Данные клиента с id="<<id<<" удалены"<<endl;
  }
  string name;
  string surname;
  int id;
  string citizenship;
  string passport;
  double balance_RUB;
  double balance_USD;
  double credit_history_score;
  Phone_number phone;
  void show_balance(){
    cout<<"Баланс клиента:"<<endl;
    cout<<"RUB: "<<balance_RUB<<"руб."<<endl;
    cout<<"USD: "<<balance_USD<<"$"<<endl;
    cout<<"********************"<<endl;
    return;
  }
  void convert_RUB_to_USD(double); //функция-член для конвертации валюты
  void give_credit(double sum); // функция член выдачи кредита
  void contacts(){ // функция-член вывода контактной информации о клинете
    cout<<"Контактные данные:"<<endl<<"Имя: "<<name<<endl<<"Фамилия: "<<surname<<endl<<"Номер телефона:"<<endl;
    phone.print_number();
  }

};



int main(){
  system("chcp 1251"); //для корректного отображения кирилицы

  cout<<endl;
  // Создадим нового клиента
  Client client_auto("Umar","Makhsudov", rand(),"UZB","AB75*****",10000,100,0.3,
                    Phone_number(7,985,3635441));
  // выведем баланс клиента
  client_auto.show_balance();
  //выведем контактные данные клиента
  client_auto.contacts();
  // Произведем конвертацию валют. В случае если на балансе будет недостаточно
  // для конвертации денег, то система сообщит об этом
  client_auto.convert_RUB_to_USD(1000);

  // Запрос на выдачу кредита. Максимальная сумма кредита определяется из формулы
  // max_sum=10000000*credit_history_score. Если запрошенная сумма превышает
  // max_sum , то дается отказ.
  client_auto.give_credit(300000);


  // Создадим нового клиента в реиме диалога с пользователем
  Client new_client;
  // выведем баланс клиента
  new_client.show_balance();
  //выведем контактные данные клиента
  new_client.contacts();
  // Произведем конвертацию валют. В случае если на балансе будет недостаточно
  // для конвертации денег, то система сообщит об этом
  new_client.convert_RUB_to_USD(1000);

  // Запрос на выдачу кредита. Максимальная сумма кредита определяется из формулы
  // max_sum=10000000*credit_history_score. Если запрошенная сумма превышает
  // max_sum , то дается отказ.
  new_client.give_credit(300000);
  return 0;
}

// Конструктор для внутрисистемного создания объекта без диалога с пользователем
Phone_number::Phone_number(short int _country_code, short int _op_code, int _number):
              country_code(_country_code),op_code(_op_code),number(_number){
}

//
Phone_number::Phone_number(){
  cout<<"Регистрация номера телефона"<<endl;
  cout<<"Введите код страны"<<endl;
  cin>>country_code;
  cout<<"Введите код оператора"<<endl;
  cin>>op_code;
  cout<<"Введите оставшиеся цифры номера телефона без пробелов"<<endl;
  cin>>number;
  cout<<"Номер зафиксирован"<<endl;
}

// Конструктор для внутрисистемного создания объекта без диалога с пользователем
Client::Client(string _name, string _surname, int _id, string _citizenship,
              string _passport, double _balance_RUB, double _balance_USD,
              double _credit_history_score, Phone_number _phone):
              name(_name),surname(_surname), id(_id), citizenship(_citizenship),
              passport(_passport),balance_RUB(_balance_RUB),
              balance_USD(_balance_USD),credit_history_score(_credit_history_score),
              phone(_phone){
  cout<<"Данные клиента зафиксированы\n*********************"<<endl<<endl;


}

//Конструктор для создания объекта с параметрами,вводимыми пользователем c консоли
Client::Client():phone(Phone_number(0,0,0)){
  id=rand();
  cout<<"Регистрация нового клиента.\nId="<<id<<endl;
  cout<<"Введите имя"<<endl;
  cin>>name;
  cout<<"Ведите фамилию"<<endl;
  cin>>surname;
  cout<<"Ведите гражданство"<<endl;
  cin>>citizenship;
  cout<<"Введите серию и номер паспорта"<<endl;
  cin>>passport;
  cout<<"Введите начальный баланс в рублях"<<endl;
  cin>>balance_RUB;
  cout<<"Введите баланс в долларах"<<endl;
  cin>>balance_USD;
  cout<<"Введите рейтинг кредитной истории в диапазоне от 0 до 1"<<endl;
  cin>>credit_history_score;
  phone=Phone_number();
  cout<<"Данные клиента зафиксированы\n*********************"<<endl<<endl;
}

void Client::convert_RUB_to_USD(double sum){
  if (sum>balance_RUB){
    cout<<"Недостаточно средств для конвертации валюты"<<endl;
    cout<<"*********************"<<endl;
    return;
  }
  balance_USD+=sum/Dollar_rate;
  balance_RUB-=sum;
  cout<<"Конвертация валюты прошла успешно"<<endl;
  show_balance();
  return;
}

void Client:: give_credit(double sum){
  double max_sum=credit_history_score*1000000;
  if (sum>max_sum){
    cout<<"Мы не можем выдать вам кредит на зарошенную сумму"<<endl<<endl;
    return;
  }
  balance_RUB+=sum;
  cout<<"Кредит выдан!"<<endl;
  show_balance();
  return;
}
