#include <iostream>
#include <iomanip>
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
using namespace std;

struct Date_Time{
  unsigned short Day: 5;
  unsigned short Month:4;
  unsigned short Year:11;
  unsigned short Hour:5;
  unsigned short Minute:6;
  unsigned short Second:6;
  unsigned short Mili_Second:10;
  void print(){
    cout<<setfill('0')<<setw(2)<<Day;
    cout<<"."<<setw(2)<<Month<<"."<<setw(2)<<Year<<" "<<setw(2)<<Hour<<":"<<
    setw(2)<<Minute<<":"<<setw(2)<<Second<<"."<<Mili_Second;
    return;
  }
};

int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  Date_Time date1;
  unsigned short int buffer;
  cout<<"������� ����"<<endl;
  cin>>buffer;
  date1.Day=buffer;
  cout<<"������� �����"<<endl;
  cin>>buffer;
  date1.Month=buffer;
  cout<<"������� ���"<<endl;
  cin>>buffer;
  date1.Year=buffer;
  cout<<"������� ���"<<endl;
  cin>>buffer;
  date1.Hour=buffer;
  cout<<"������� ������"<<endl;
  cin>>buffer;
  date1.Minute=buffer;
  cout<<"������� �������"<<endl;
  cin>>buffer;
  date1.Second=buffer;
  cout<<"������� �����������"<<endl;
  cin>>buffer;
  date1.Mili_Second=buffer;

  date1.print();



  return 0;
}
