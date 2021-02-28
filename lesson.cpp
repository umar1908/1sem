#include <iostream>
#include <typeinfo>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

class A{
private:
  double a;
  friend A operator+(const A&,const A&);
public:
  A(const double& _a):a(_a){};

  void print(){
    cout<<a<<endl;
  }
};

A operator+(const A& lhs,const A& rhs){
  return A(lhs.a+rhs.a);
}

bool approx_equal(const double& lhs,const double& rhs){
  if (abs(lhs-rhs)<1e-8)
  return abs(lhs-rhs)<1e-8;
}

void approx(double& _num,double& _denum,const double& d){
  while ((_num/_denum)>d) {

    _denum++;
    if (approx_equal(_num/_denum,d)) {
      return;
    }
  }
  while (_num/_denum<d) {
    _num++;
    if (approx_equal(_num/_denum,d)) {
      return;
    }
  }

  double accuracy=abs(_num/_denum-d);
  if (accuracy<1e-5){
    return;
  }
  approx(_num,_denum,d);


}

void test(double d){
  int int_part=static_cast<int>(d);
  double rest=d-int_part;

  double _num{1};
  double _denum{1};
  approx(_num,_denum,rest);
  cout<<_num<<"/"<<_denum<<endl;



}

int main(){
  // test(2.0);
  // double d=1.0/3.0;
  // cout<<(1.0/3.0>d);
 unsigned int a=2;
 int b=-1;
 cout<<a*b;



}
