#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
using namespace std;
int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  cout<<"������ ���������� ��������� �������"<<endl;
  int n;
  cin>>n;
  if (n<=0){
    cout<<"������������ ����"<<endl;
    exit(0);
  }

  vector<int> data(n);
  cout<<"������� �������� ��������� �������"<<endl;
  for(int& elem: data){
    cin>>elem;
  }
  cout<<"���������� �� �����������"<<endl;
  sort(data.begin(),data.end());
  for(const int& elem:data){
    cout<<elem<<endl;
  }
  cout<<endl<<"���������� �� ��������"<<endl;
  sort(data.begin(),data.end(),[](int& x,int& y)->bool{return x>y;});
  for(const int& elem:data){
    cout<<elem<<endl;
  }



  return 0;
}
