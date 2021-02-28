#include <iostream>
#include <iomanip>
using namespace std;
// const auto N=3; //����� ���������;

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

void check(double* line,size_t N){ //�������� ������� ������� �����
  for (size_t i = 0; i < N; i++) {
    if (line[i]!=0){
      return;
    }
  }
  if (line[N]==0){
    cout<<"���������� ����� �������";
  }
  else{
    cout<<"������� ���";
  }
  exit(0);
}

// ������ ����������� ��� �������� ���������� ������� � ������� ���������� � ���������.
// �� ����� ��� ��� ��������, �������� �������� �� ���� �������.
// ��� ����� �������� ��� ���. ����������� ������ ��� ���� ����� �� ������������ ��� ������� ��������������
// ����������
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
  system("chcp 1251"); //��� ����������� ����������� ��������

  cout<<"������� ���������� ���������"<<endl;
  int N;
  cin>>N;
  if (N<=0){
    cout<<"���������� ����";
    exit(0);
  }


  double** data;
  data=new double* [N];
  for (size_t i = 0; i < N; i++) {
    data[i]=new double[N+1];
  }

  // double data[N][N+1];
  cout<<"������� ��������� ����������� ������� �������"<<N<<"x"<<N+1<<endl;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N+1; j++) {
      cin>>data[i][j];
    }
  }
// ���������� � ������������ ����
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

  // �������� ������� ������� �����
  for (size_t i = 0; i < N; i++) {
    check(data[i],N);
  }
  // "������������"
  for (size_t i = 0; i < N; i++) {
    norm(data[i],i,N);
  }


// �������� �������:
  for (size_t j =1; j < N; j++) {
    for (int i = j-1; i >=0 ; i--) {
      subtract(data[i],data[j],j,N);
    }
    print(data,N);
    // �������� ������� ������� �����
    for (size_t i = 0; i < N; i++) {
      check(data[i],N);
    }


  }

  print(data,N);
// ����� ������
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
