#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<"Введите количество элементов"<<endl;
  int n;
  cin>>n;
  if (n<=0){
    cout<<"Некорректный ввод";
    exit(0);
  }
  vector<int> data(n);
  cout<<"Введите значения элементов"<<endl;

  for (size_t i = 0; i < n; i++) {
    cin>>data[i];
  }

  for (size_t i=0;i<n;i++){
    for (size_t j = n-1; j >0 ; j--) {
      if (j>i+i){
        swap(data[j],data[j-1]);
      }
      else{
        if (data[j]<data[j-1]){
          swap(data[j],data[j-1]);
        }

      }
    }
  }
  cout<<"Отсортированные данные:"<<endl;
  for (size_t i = 0; i < n ; i++) {
    cout<<data[i]<<endl;
  }





  return 0;
}
