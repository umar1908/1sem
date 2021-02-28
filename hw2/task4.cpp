#include <iostream>
#include <iomanip>
#include <vector>
// #include <string>
// #include <cmath>
using namespace std;

struct subseq{
  vector<int> sub_seq1;// индексы сформированной попоследовательности последовательности 1
  vector<int> sub_seq2;// индексы сформированной подпоследовательности последовательноси 2
  int start_pos1=0;
  int start_pos2=0;
  int length=0;
};

subseq find_max_subseq(vector<int> &seq1, vector<int> &seq2, subseq mem){
  size_t i1=mem.start_pos1;
  size_t i2=mem.start_pos2;
  // cout<<i1<<" "<<i2<<endl;
  if ((mem.start_pos1==seq1.size())||(mem.start_pos2==seq2.size())) {
    return mem;
  }
  if (seq1[i1]==seq2[i2]) {
    mem.sub_seq1.push_back(i1);
    mem.sub_seq2.push_back(i2);
    mem.length++;
    mem.start_pos1++;
    mem.start_pos2++;
    // cout<<i1<<" "<<i2<<endl;
    return find_max_subseq(seq1,seq2,mem);

  }
  else{
    subseq mem1=mem;
    mem1.start_pos1++;
    subseq way1=find_max_subseq(seq1,seq2,mem1);
    subseq mem2=mem;
    mem2.start_pos2++;
    subseq way2=find_max_subseq(seq1,seq2,mem2);
    int len1=way1.length;
    int len2=way2.length;
    if (len1>=len2) {
      return way1;
    }
    else{
      return way2;
    }
  }
}
int main(){
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  int n1,n2;



  cout<<"¬ведите количество элементов последовательноси 1"<<endl;
  cin>>n1;
  vector<int> seq1(n1);
  cout<<"¬ведите элементы первой последовательноси"<<endl;
  for (size_t i = 0; i < n1; i++) {
    cin>>seq1[i];
  }
  cout<<"¬ведите количество элементов последовательности 2"<<endl;
  cin>>n2;
  vector<int> seq2(n2);
  cout<<"¬ведите элементы второй последовательноси"<<endl;
  for (size_t i = 0; i < n2; i++) {
    cin>>seq2[i];
  }



  subseq mem;

  subseq result=find_max_subseq(seq1,seq2,mem);
  cout<<"Success!"<<endl;
  for (int elem: result.sub_seq1) {
    cout<<seq1[elem]<<" ";
  }
  cout<<endl;
  for (int elem: result.sub_seq2) {
    cout<<seq2[elem]<<" ";
  }

  return 0;
}
