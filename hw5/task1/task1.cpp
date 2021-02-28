#include <iostream>
#include <iomanip>
#include "Phone_number.h"
#include "Client.h"

// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
 #include <cstdlib>
using namespace std;

Client creat_new_client(); //функция для ручного создания нового клиента

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  // Создадим нового клиента
  Client client_auto("Umar","Makhsudov", rand(),"UZB","AB75*****",10000,100,0.3,
                    Phone_number(7,985,3635441));
  // выведем полную информацию о клменте
  cout<<client_auto;
  // Произведем конвертацию валют. В случае если на балансе будет недостаточно
  // для конвертации денег, то система сообщит об этом
  client_auto.convert_RUB_to_USD(1000);
  // Запрос на выдачу кредита. Максимальная сумма кредита определяется из формулы
  // max_sum=10000000*credit_history_score. Если запрошенная сумма превышает
  // max_sum , то дается отказ.
  client_auto.give_credit(300000);

  // создадим клиента вручную
  Client new_client=creat_new_client();
  cout<<new_client;
  // Произведем конвертацию валют. В случае если на балансе будет недостаточно
  // для конвертации денег, то система сообщит об этом
  new_client.convert_RUB_to_USD(1000);

  // Запрос на выдачу кредита. Максимальная сумма кредита определяется из формулы
  // max_sum=10000000*credit_history_score. Если запрошенная сумма превышает
  // max_sum , то дается отказ.
  new_client.give_credit(300000);
  return 0;

}


Client creat_new_client(){
  string name,surname,passport,citizenship;
  int id=rand();
  short int country_code,op_code;
  int number;
  double credit_history_score,balance_RUB,balance_USD;
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

  cout<<"Регистрация номера телефона"<<endl;
  cout<<"Введите код страны"<<endl;
  cin>>country_code;
  cout<<"Введите код оператора"<<endl;
  cin>>op_code;
  cout<<"Введите оставшиеся цифры номера телефона без пробелов"<<endl;
  cin>>number;
  cout<<"Номер зафиксирован"<<endl;
  return Client(name,surname,id,citizenship,passport,balance_RUB,balance_USD,
                credit_history_score,
                Phone_number(country_code,op_code,number));
}
