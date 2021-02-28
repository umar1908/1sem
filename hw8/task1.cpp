#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
#include <exception>
#include <bitset>

void throw_range_error();
void throw_bad_alloc_error();
void throw_overflow();
void throw_length_error();
class Triangle{
  double _a,_b,_c;
public:
  Triangle(double a,double b,double c){
    if (a+b<c || a+c<b || b+c<a){
      throw logic_error("Impossible triangle");
    }
  }
};

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  try{
    cout<<"OUT OF RANGE TEST:\n";
    throw_range_error();
  }
  catch(const out_of_range& e){
    cerr<<"Out of range error with message:"<<e.what();
  }


  try{
    cout<<"\n\nBAD ALLOC TEST(Please,wait...):\n";
  throw_bad_alloc_error();
  }
  catch(const bad_alloc& e){
    cerr<<"Bad_alloc error with message:"<<e.what()<<endl;
  }

  try{
    cout<<"\nOVERFLOW ERROR TEST\n\n";
    throw_overflow();
  }
  catch(const overflow_error& e){
    cerr<<"Overflow error with message:"<<e.what()<<endl;
  }

try{
  cout<<"\nLENGTH ERROR TEST:\n\n";
   throw_length_error();
}
catch(const length_error& e){
  cerr<<"length_error with message:"<<e.what();
}

try{
  cout<<"\n\nLOGIC ERROR TEST:\n\n";
Triangle(1,1,10);
}
catch(const logic_error& e){
  cerr<<"logic error with message:"<<e.what();
}
  cout<<"\n\nFinished successfully";
  return 0;
}


void throw_range_error(){
  vector<int> v{0,1,2,3,4};
  cout<<"\ncout<<v.at(2):\n";
  cout<<v.at(2);
  cout<<"\ncout<<v[10]:\n";
  cout<<v[10];
  cout<<"\ncout<<v.at(10):\n";
  cout<<v.at(10);
}

void throw_bad_alloc_error(){
  std::vector<int> v;
  while(true){
    v.push_back(1);
  }
}

void throw_overflow(){
  bitset<33> bitset;
  bitset[0]=1;
  bitset[32]=1;
  unsigned long a=bitset.to_ulong();
}


void throw_length_error(){
  int a{-1};
  vector<int> v(a);
}
