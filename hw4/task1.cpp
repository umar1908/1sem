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

// � ������� �������� ��������� � ������, � ���������� �� � ����� ���������,
// �� ���������� �� ��� ������� � �� ����� ��������� ��������� ���������
// ������ main
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
    cout<<"������ ������� � id="<<id<<" �������"<<endl;
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
    cout<<"������ �������:"<<endl;
    cout<<"RUB: "<<balance_RUB<<"���."<<endl;
    cout<<"USD: "<<balance_USD<<"$"<<endl;
    cout<<"********************"<<endl;
    return;
  }
  void convert_RUB_to_USD(double); //�������-���� ��� ����������� ������
  void give_credit(double sum); // ������� ���� ������ �������
  void contacts(){ // �������-���� ������ ���������� ���������� � �������
    cout<<"���������� ������:"<<endl<<"���: "<<name<<endl<<"�������: "<<surname<<endl<<"����� ��������:"<<endl;
    phone.print_number();
  }

};



int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������

  cout<<endl;
  // �������� ������ �������
  Client client_auto("Umar","Makhsudov", rand(),"UZB","AB75*****",10000,100,0.3,
                    Phone_number(7,985,3635441));
  // ������� ������ �������
  client_auto.show_balance();
  //������� ���������� ������ �������
  client_auto.contacts();
  // ���������� ����������� �����. � ������ ���� �� ������� ����� ������������
  // ��� ����������� �����, �� ������� ������� �� ����
  client_auto.convert_RUB_to_USD(1000);

  // ������ �� ������ �������. ������������ ����� ������� ������������ �� �������
  // max_sum=10000000*credit_history_score. ���� ����������� ����� ���������
  // max_sum , �� ������ �����.
  client_auto.give_credit(300000);


  // �������� ������ ������� � ����� ������� � �������������
  Client new_client;
  // ������� ������ �������
  new_client.show_balance();
  //������� ���������� ������ �������
  new_client.contacts();
  // ���������� ����������� �����. � ������ ���� �� ������� ����� ������������
  // ��� ����������� �����, �� ������� ������� �� ����
  new_client.convert_RUB_to_USD(1000);

  // ������ �� ������ �������. ������������ ����� ������� ������������ �� �������
  // max_sum=10000000*credit_history_score. ���� ����������� ����� ���������
  // max_sum , �� ������ �����.
  new_client.give_credit(300000);
  return 0;
}

// ����������� ��� ���������������� �������� ������� ��� ������� � �������������
Phone_number::Phone_number(short int _country_code, short int _op_code, int _number):
              country_code(_country_code),op_code(_op_code),number(_number){
}

//
Phone_number::Phone_number(){
  cout<<"����������� ������ ��������"<<endl;
  cout<<"������� ��� ������"<<endl;
  cin>>country_code;
  cout<<"������� ��� ���������"<<endl;
  cin>>op_code;
  cout<<"������� ���������� ����� ������ �������� ��� ��������"<<endl;
  cin>>number;
  cout<<"����� ������������"<<endl;
}

// ����������� ��� ���������������� �������� ������� ��� ������� � �������������
Client::Client(string _name, string _surname, int _id, string _citizenship,
              string _passport, double _balance_RUB, double _balance_USD,
              double _credit_history_score, Phone_number _phone):
              name(_name),surname(_surname), id(_id), citizenship(_citizenship),
              passport(_passport),balance_RUB(_balance_RUB),
              balance_USD(_balance_USD),credit_history_score(_credit_history_score),
              phone(_phone){
  cout<<"������ ������� �������������\n*********************"<<endl<<endl;


}

//����������� ��� �������� ������� � �����������,��������� ������������� c �������
Client::Client():phone(Phone_number(0,0,0)){
  id=rand();
  cout<<"����������� ������ �������.\nId="<<id<<endl;
  cout<<"������� ���"<<endl;
  cin>>name;
  cout<<"������ �������"<<endl;
  cin>>surname;
  cout<<"������ �����������"<<endl;
  cin>>citizenship;
  cout<<"������� ����� � ����� ��������"<<endl;
  cin>>passport;
  cout<<"������� ��������� ������ � ������"<<endl;
  cin>>balance_RUB;
  cout<<"������� ������ � ��������"<<endl;
  cin>>balance_USD;
  cout<<"������� ������� ��������� ������� � ��������� �� 0 �� 1"<<endl;
  cin>>credit_history_score;
  phone=Phone_number();
  cout<<"������ ������� �������������\n*********************"<<endl<<endl;
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
