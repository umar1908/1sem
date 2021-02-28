#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
#include <exception>
// #include <bitset>
#include "Array.h"





int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  Array<int> array1;
  cout<<"Is empty:"<<boolalpha<<array1.is_empty()<<"\nsize:"<<array1.size();
  cout<<"\n\n******************************\n\n";
  double* b=new double[5];
  b[0]=1.0;
  b[1]=2.2;
  b[2]=3.3;
  b[3]=4.4;
  b[4]=5.5;
  try{
  cout<<endl<<"Проверка исключений";
  cout<<endl;
   Array<double> array3(b,-1);// вызовет исключение logic_error
 }
 catch(logic_error e){
   cerr<<e.what();
   cout<<endl;
   cout<<endl;
 }
  Array<double> array2(b,5);
  cout<<"is_empty:"<<array2.is_empty()<<"\nsize="<<array2.size()<<endl;
  for (size_t i = 0; i < array2.size(); i++) {
    cout<<array2[i]<<" ";
  }
  try{

    cout<<endl<<"Проверка исключений";
    cout<<endl;
  array2[-1];//
  }
  catch(out_of_range e){
    cerr<<e.what();
    cout<<endl;
  }
  cout<<"\n\n******************************\n\n";
    Array<int> array4(10,0);
    cout<<"size="<<array4.size()<<endl;
    for (size_t i = 0; i < array4.size(); i++) {
      cout<<array4[i]<<" ";
    }
    cout<<"\n\n******************************\n\n";
  Array<int> array5 (5);
  cout<<"size="<<array5.size()<<endl;
  for (size_t i = 0; i < array5.size(); i++) {
    cout<<array5[i]<<" ";
  }
  cout<<"\n\n******************************\n\n";

  Array<int> array6(array4);
  cout<<"size="<<array6.size()<<endl;
  for (size_t i = 0; i < array6.size(); i++) {
    cout<<array6[i]<<" ";
  }
  cout<<"\n\n******************************\n\n";

  Array<double> array7 (move(array2));
  cout<<"size="<<array7.size()<<endl;
  for (size_t i = 0; i < array7.size(); i++) {
    cout<<array7[i]<<" ";
  }
  cout<<"Донор пуст:"<<array2.is_empty();
  cout<<"\n\n******************************\n\n";

  array2=array7;
  cout<<"size="<<array7.size()<<endl;
  for (size_t i = 0; i < array7.size(); i++) {
    cout<<array7[i]<<" ";
  }
  cout<<"\nДонор\n";
  cout<<"size="<<array2.size()<<endl;
  for (size_t i = 0; i < array2.size(); i++) {
    cout<<array2[i]<<" ";
  }

  cout<<"\n\n******************************\n\n";
  array2=move(array2);
  cout<<"size="<<array7.size()<<endl;
  for (size_t i = 0; i < array7.size(); i++) {
    cout<<array7[i]<<" ";
  }
  cout<<"\nДонор\n";
  cout<<"size="<<array2.size()<<endl;
  for (size_t i = 0; i < array2.size(); i++) {
    cout<<array2[i]<<" ";
  }
  cout<<"\n\n******************************\n\n";
  cout<<"Resize 10->15:\n";
  array4.resize(15);
  cout<<"size="<<array4.size()<<endl;
  for (size_t i = 0; i < array4.size(); i++) {
    cout<<array4[i]<<" ";
  }

  cout<<"\n\nResize 15->2:\n";
  array4.resize(2);
  cout<<"size="<<array4.size()<<endl;
  for (size_t i = 0; i < array4.size(); i++) {
    cout<<array4[i]<<" ";
  }
  cout<<"\n\n******************************\n\n";
  cout<<"size="<<array7.size()<<endl;
  for (size_t i = 0; i < array7.size(); i++) {
    cout<<array7[i]<<" ";
  }
    cout<<"\nswap:0 <->4\n";
    swapp(array7[0],array7[4]);
    cout<<"size="<<array7.size()<<endl;
    for (size_t i = 0; i < array7.size(); i++) {
      cout<<array7[i]<<" ";
  }
  cout<<"\n\n******************************\n\n";

}
