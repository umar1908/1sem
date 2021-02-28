#include <iostream>
#include <iomanip>
using namespace std;
// const auto N=3; //Число уравнений;

void subtract(double* line1,double* line2,size_t column,size_t N){
  if (line2[column]==0) {
    return;
  }
  double k=line1[column]/line2[column];
  for (size_t i = 0; i < N+1; i++) {
    // cout<<"*";
    line1[i]-=line2[i]*k;
  }
  return;
}

void norm(double* line,size_t column,size_t N){
  double k=line[column];
  if (k==0) {
    return;
  }
  for (size_t i = 0; i < N+1; i++) {
    line[i]/=k;
  }
  return;
}

void check(double* line,size_t N){ //Проверка наличия нулевых строк
  for (size_t i = 0; i < N; i++) {
    if (line[i]!=0){
      return;
    }
  }
  if (line[N]==0){
    cout<<"Бесконечно много решений";
  }
  else{
    cout<<"Решений нет";
  }
  exit(0);
}

// Данную конструкцию для передачи двумерного массива в функцию подсмотрел в интернете.
// Не понял как она устроена, планирую спросить на след занятии.
// Тут можно обойтись без нее. Использовал только для того чтобы не загромождать код выводом промежуточного
// результата
void print(double** data, size_t N){
  for (size_t i = 0; i < N; i++) {
    cout<<endl;
    for (size_t j = 0; j < N+1; j++) {
      cout<<setfill(' ')<<setw(3)<<data[i][j]<<" ";
      if (j==N-1) {
        cout<<"|";
      }
    }
  }
  cout<<endl;

}


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы

  cout<<"Введите количество уравнений"<<endl;
  int N;
  cin>>N;
  if (N<=0){
    cout<<"Некоректый ввод";
    exit(0);
  }


  double** data;
  data=new double* [N];
  for (size_t i = 0; i < N; i++) {
    data[i]=new double[N+1];
  }

  // double data[N][N+1];
  cout<<"Введите построчно расширенную матрицу размера"<<N<<"x"<<N+1<<endl;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N+1; j++) {
      cin>>data[i][j];
    }
  }
// Приведение к треугольному виду
  for (size_t j = 0; j < N; j++) {
    print(data,N);
    size_t i=j;
    while (data[i][j]==0) {
      i++;
      if (i==N) {
        break;
      }
    }
    if (i==N) {
      continue;
    }
    if (i!=j){
      cout<<"flag2";
      swap(data[i],data[j]);
    }
    for (size_t k = j+1; k < N; k++) {
      subtract(data[k],data[j],j,N);
    }
  }

  // Проверка наличия нулевых строк
  for (size_t i = 0; i < N; i++) {
    check(data[i],N);
  }
  // "нормализация"
  for (size_t i = 0; i < N; i++) {
    norm(data[i],i,N);
  }


// обратный процесс:
  for (size_t j =1; j < N; j++) {
    for (int i = j-1; i >=0 ; i--) {
      subtract(data[i],data[j],j,N);
    }
    print(data,N);
    // Проверка наличия нулевых строк
    for (size_t i = 0; i < N; i++) {
      check(data[i],N);
    }


  }

  print(data,N);
// вывод ответа
cout<<endl;
for (size_t i = 0; i < N; i++) {
  cout<<"x"<<i<<"="<<data[i][N]<<endl;
}

for (size_t i = 0; i < N; i++) {
  delete [] data[i];
}
delete[] data;

  return 0;
}
