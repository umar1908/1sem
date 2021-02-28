#include "Phone_number.h"
#include "Client.h"
#include <stdlib.h>

double Client::Dollar_rate=78.15; //��������� static ����� ������
Client::Client(string _name, string _surname, int _id, string _citizenship,
              string _passport, double _balance_RUB, double _balance_USD,
              double _credit_history_score, Phone_number _phone):
              name(_name),surname(_surname), id(_id), citizenship(_citizenship),
              passport(_passport),balance_RUB(_balance_RUB),
              balance_USD(_balance_USD),credit_history_score(_credit_history_score),
              phone(_phone){
  cout<<"*******************************\n������ ������� �������������\n*******************************"<<endl<<endl;
}

ostream& operator<<(ostream& os, const Client& client){
  os<<"���������� � �������(id="<<client.id<<")\n���:"<<client.name<<endl<<"�������:"<<
  client.surname<<endl<<"�����������:"<<client.citizenship<<endl<<"�������:"<<
  client.passport<<"\n��������� �������:"<<client.credit_history_score<<endl;
  client.show_balance();
  return os;
}

void Client::convert_RUB_to_USD(double sum){
  if (sum>balance_RUB){
    cout<<"������������ ������� ��� ����������� ������"<<endl;
    cout<<"*********************"<<endl;
    return;
  }
  balance_USD+=sum/Dollar_rate;
  balance_RUB-=sum;
  cout<<"����������� ������ ������ �������"<<endl;
  show_balance();
  return;
}

void Client:: give_credit(double sum){
  double max_sum=credit_history_score*1000000;
  if (sum>max_sum){
    cout<<"�� �� ����� ������ ��� ������ �� ���������� �����"<<endl<<endl;
    return;
  }
  balance_RUB+=sum;
  cout<<"������ �����!"<<endl;
  show_balance();
  return;
}


Client::Client():name("No name"),surname("No surname"),id(0),citizenship("None"),
        passport("None"),balance_RUB(0),balance_USD(0),credit_history_score(0),
        phone(Phone_number()){}// ����������� �� ���������

string  Client::get_name() const{
  return name;
}
string Client::get_surname() const{
  return surname;
}
int Client::get_id() const{
  return id;
}
string Client::get_passport() const{
  return passport;
}
double Client::get_balance_RUB() const{
  return balance_RUB;
}
double Client::get_balance_USD() const{
  return balance_USD;
}
double Client::get_credit_history_score() const{
  return credit_history_score;
}
Phone_number Client::get_Phone_number() const {
  return phone;
}
void Client::set_name(string name){
  this->name=name;
}
void Client::set_surname(string surname){
  this->surname=surname;
}
void Client::set_passport(string passport){
  this->passport;
}
void Client::set_credit_history_score(double credit_history_score){
  if (credit_history_score>=0 && credit_history_score<=1){
    this->credit_history_score=credit_history_score;
  }
  else{
     cout<<"������������ ��������� �������!";
     exit(0);
   }
}
void Client::set_number(Phone_number phone){
  this->phone=phone;
}
void Client::show_balance() const{
  cout<<"������ �������:"<<endl;
  cout<<"RUB: "<<balance_RUB<<"���."<<endl;
  cout<<"USD: "<<balance_USD<<"$"<<endl;
  cout<<"********************"<<endl;
  return;
}
Client::~Client(){// ����������
  cout<<"������ ������� � id="<<id<<" �������"<<endl;
}
