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

Client creat_new_client(); //������� ��� ������� �������� ������ �������

int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  // �������� ������ �������
  Client client_auto("Umar","Makhsudov", rand(),"UZB","AB75*****",10000,100,0.3,
                    Phone_number(7,985,3635441));
  // ������� ������ ���������� � �������
  cout<<client_auto;
  // ���������� ����������� �����. � ������ ���� �� ������� ����� ������������
  // ��� ����������� �����, �� ������� ������� �� ����
  client_auto.convert_RUB_to_USD(1000);
  // ������ �� ������ �������. ������������ ����� ������� ������������ �� �������
  // max_sum=10000000*credit_history_score. ���� ����������� ����� ���������
  // max_sum , �� ������ �����.
  client_auto.give_credit(300000);

  // �������� ������� �������
  Client new_client=creat_new_client();
  cout<<new_client;
  // ���������� ����������� �����. � ������ ���� �� ������� ����� ������������
  // ��� ����������� �����, �� ������� ������� �� ����
  new_client.convert_RUB_to_USD(1000);

  // ������ �� ������ �������. ������������ ����� ������� ������������ �� �������
  // max_sum=10000000*credit_history_score. ���� ����������� ����� ���������
  // max_sum , �� ������ �����.
  new_client.give_credit(300000);
  return 0;

}


Client creat_new_client(){
  string name,surname,passport,citizenship;
  int id=rand();
  short int country_code,op_code;
  int number;
  double credit_history_score,balance_RUB,balance_USD;
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

  cout<<"����������� ������ ��������"<<endl;
  cout<<"������� ��� ������"<<endl;
  cin>>country_code;
  cout<<"������� ��� ���������"<<endl;
  cin>>op_code;
  cout<<"������� ���������� ����� ������ �������� ��� ��������"<<endl;
  cin>>number;
  cout<<"����� ������������"<<endl;
  return Client(name,surname,id,citizenship,passport,balance_RUB,balance_USD,
                credit_history_score,
                Phone_number(country_code,op_code,number));
}
