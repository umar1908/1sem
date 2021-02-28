#include <iostream>
#include <iomanip>
using namespace std;
#include <functional>
// #include <algorithm>
#include <array>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
#include <exception>
#include<stdexcept>
// #include <bitset>





template<typename T>
unique_ptr<T> my_sort(T* begin,int size,function<bool(T,T)>comp){
  if (size==1){
    unique_ptr<T> sorted(new T);
    *sorted=begin[0];
    return sorted;
  }



  auto sub_array1_begin=begin; //деление массива на плдмассивы
  auto sub_array1_end=begin+(size/2-1);
  if (sub_array1_begin==sub_array1_end){
  }
  auto size1=sub_array1_end-sub_array1_begin+1;
  // cout<<size1<<endl;
  auto sub_array2_begin=begin+(size/2);
  auto sub_array2_end=begin+(size-1);
  auto size2=sub_array2_end-sub_array2_begin+1;
  auto sorted_sub_array1=my_sort(sub_array1_begin,size1,comp);
  auto sorted_sub_array2=my_sort(sub_array2_begin,size2,comp);



  unique_ptr<T> merge_array(new T[size]);
  int i=0;
  T* iterator1=sorted_sub_array1.get();
  // cout<<"!^"<<*iterator1;
  T* stop1=sorted_sub_array1.get()+size1;
  T* iterator2=sorted_sub_array2.get();
  T* stop2=sorted_sub_array2.get()+size2;
  while(true){ //слияние двух отсортированных подмассивов
    // cout<<"Try";
    if (comp(*iterator1,*iterator2)) {
      merge_array.get()[i]=*iterator1;
      // cout<<"\nДобавлен i= "<<i<<" "<<merge_array[i]<<endl;
      ++iterator1;
      i++;
    }
    else{

      // cout<<"set"<<*iterator2<<"\n";
      merge_array.get()[i]=*iterator2;
      // cout<<"\nДобавлен i="<<i<<" "<<merge_array[i]<<endl;
      ++iterator2;
      i++;
    }
    if(iterator1==stop1){ // добавление хвоста когда один из подмассивов закончился
      while (iterator2!=stop2){
        merge_array.get()[i]=(*iterator2);
        ++iterator2;
        i++;
      }
      break;
    }
    if(iterator2==stop2){ // добавление хвоста когда один из подмассивов закончился
      while(iterator1!=stop1){
        merge_array.get()[i]=(*iterator1);
        ++iterator1;
        i++;
      }
      break;
    }
  }
  for (size_t i = 0; i < size; i++) {
    begin[i]=merge_array.get()[i];
  }
  return merge_array;

}

template<typename T,size_t N>
unique_ptr<T> my_sort(T (&array)[N],function<bool(T,T)> comp){
  T* ptr=new T[N];
  for (size_t i = 0; i < N; i++) {
    ptr[i]=array[i];
  }
  unique_ptr<T> sorted=move(my_sort(ptr,N,comp));
  for (size_t i = 0; i < N; i++) {
    array[i]=sorted.get()[i];
  }
  return sorted;
}





int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  int* b=new int[6];
  b[0]=2;
  b[1]=4;
  b[2]=3;
  b[3]=5;
  b[4]=7;
  b[5]=-3;
  function<bool(int,int)> comp1=[](const int& x1,const int& x2)->bool{return x1>=x2;};
  function<bool(double,double)> comp2=[](const double& x1,const double& x2)->bool{return x1<=x2;};
  my_sort(b,6,comp1);
  for (int i = 0; i < 6; i++) {
    cout<<b[i]<<endl;
  }
  cout<<endl;
  double c[]{-9.2,21.2,100,10,23.55,11,2,-7,122,3.7,5.8};

  my_sort(c,comp2);

  for (size_t i = 0; i < 11; i++) {
    cout<<c[i]<<endl;
  }

}
