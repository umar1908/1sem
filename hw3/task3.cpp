#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
using namespace std;
int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  cout<<"Ведите количество элементов массива"<<endl;
  int n;
  cin>>n;
  if (n<=0){
    cout<<"Некорректный ввод"<<endl;
    exit(0);
  }

  vector<int> data(n);
  cout<<"Введите значения элементов массива"<<endl;
  for(int& elem: data){
    cin>>elem;
  }
  cout<<"Сортировка по возрастанию"<<endl;
  sort(data.begin(),data.end());
  for(const int& elem:data){
    cout<<elem<<endl;
  }
  cout<<endl<<"Сортировка по убыванию"<<endl;
  sort(data.begin(),data.end(),[](int& x,int& y)->bool{return x>y;});
  for(const int& elem:data){
    cout<<elem<<endl;
  }



  return 0;
}
