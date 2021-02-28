#include <iostream>
#include <iomanip>
using namespace std;
// const auto N=11; //колличество элементов массива
bool bin_search(int* start,int n,int key) {
  if (n==0) {
    return false;
  }
  if (n%2==0) {
    int i1=n/2-1;
    int i2=n/2;
    if ((key<start[i2])&&(key>start[i1])) {
      return false;
    }
    else if(key>=start[i2]){
      bin_search(start+i2,n/2,key);
    }
    else if(key<=start[i1]){
      bin_search(start,n/2,key);
    }
  }
  else{
    int i=n/2;
    if (start[i]==key) {
      return true;
    }
    else{
      if (key>=start[i]) {
        bin_search(start+i+1,n/2,key);
      }
      else{
        bin_search(start,n/2,key);
      }
    }
  }
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы

  cout<<"Ведите размер массива"<<endl;
  int N;
  cin>>N;
  if (N<=0){
    cout<<"Некоректый ввод";
    exit(0);
  }
  int* data;
  data=new int [N];
  // int data[N];
  cout<<"Введите элементы отсортированного массива"<<endl;
  for (size_t i = 0; i < N; i++) {
    cin>>data[i];
  }
  cout<<"Введите элемент для поиска"<<endl;
  int key;
  cin>>key;
  cout<<boolalpha<<bin_search(data,N,key);
  delete[] data;



  return 0;
}
