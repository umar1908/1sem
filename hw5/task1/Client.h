#ifndef CL
#define CL
#include <iostream>
#include "Phone_number.h"
using namespace std;

class Client{
private:
  string name;
  string surname;
  int id;
  string citizenship;
  string passport;
  double balance_RUB;
  double balance_USD;
  double credit_history_score;
  Phone_number phone;
  friend ostream& operator<<(ostream&, const Client&); //перегрузка оператора <<
public:
  static double Dollar_rate; //курс доллар
  Client(string, string, int, string, string, double,double,double,Phone_number);
  Client();// конструктор по умолчанию
  // начало блока аксессоров
  string get_name() const;
  string get_surname() const;
  int get_id() const;
  string get_passport() const;
  double get_balance_RUB() const;
  double get_balance_USD() const;
  double get_credit_history_score() const;
  Phone_number get_Phone_number() const;
  void set_name(string );
  void set_surname(string );
  void set_passport(string );
  void set_credit_history_score(double);
  void set_number(Phone_number phone);
  // конец блока аксессоров
  void show_balance() const; //вывести баланс клиента
  void convert_RUB_to_USD(double); //метод для конвертации валюты
  void give_credit(double sum); //метод член выдачи кредита
  ~Client();
};

#endif
