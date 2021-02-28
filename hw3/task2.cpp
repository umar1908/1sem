#include <iostream>
#include <iomanip>
#include <vector>
// #include <string>
// #include <cmath>

using namespace std;
vector<int> merge_sort(vector<int>::iterator,vector<int>::iterator);
vector<int> merge_sort(vector<int>);

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
  cout<<endl;
  auto result=merge_sort(data.begin(),data.end());
  for(int elem:result){
    cout<<elem<<endl;
  }

  return 0;
}


vector<int> merge_sort(vector<int>::iterator begin,vector<int>::iterator end){
  auto size=end-begin;
  if (size==1) {
    vector<int> merge_vector{*begin};
    return merge_vector;
  }
  auto sub_vector1_begin=begin; //������� ������� �� ����������
  auto sub_vector1_end=begin+(size/2-1)+1;
  auto sub_vector2_begin=begin+(size/2);
  auto sub_vector2_end=end;
  auto sorted_sub_vector1=merge_sort(sub_vector1_begin,sub_vector1_end); //����������� ���������� ���������� �� ����������

  auto sorted_sub_vector2=merge_sort(sub_vector2_begin,sub_vector2_end);


  vector<int> merge_vector;
  auto iterator1=sorted_sub_vector1.begin();
  auto stop1=sorted_sub_vector1.end();
  auto iterator2=sorted_sub_vector2.begin();
  auto stop2=sorted_sub_vector2.end();
  while(true){ //������� ���� ��������������� �����������
    if (*iterator1<=*iterator2) {
      merge_vector.emplace_back(*iterator1);
      ++iterator1;
    }
    else{
      merge_vector.emplace_back(*iterator2);
      ++iterator2;
    }
    if(iterator1==stop1){ // ���������� ������ ����� ���� �� ����������� ����������
      while (iterator2!=stop2){
        merge_vector.emplace_back(*iterator2);
        ++iterator2;
      }
      break;
    }
    if(iterator2==stop2){ // ���������� ������ ����� ���� �� ����������� ����������
      while(iterator1!=stop1){
        merge_vector.emplace_back(*iterator1);
        ++iterator1;
      }
      break;
    }
  }
  return merge_vector;




}
