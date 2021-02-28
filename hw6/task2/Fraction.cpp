#include "Fraction.h"
#include <iostream>
#include <cmath>
using namespace std;


void approx(double& _num,double& _denum,const double& d); //преобразование double в пару числитель/знаменатель
bool approx_equal(const double& lhs,const double& rhs); //приблизительное сравнение двух double


int Fraction::get_num(){
  return num;
}

int Fraction::get_denum(){
  return denum;
}

void Fraction::simplify(){
  int min;
  for (int i = denum; i > 1; i--) {
    if (num%i==0 && denum%i==0){
      num/=i;
      denum/=i;
      return;
    }
  }
}

void Fraction::set_num(const int& _num){
  num=_num;
}

void Fraction::set_denum(const int& _denum){
  if (_denum<0){
    num*=-1;
  }
  denum=abs(_denum);
}

Fraction::Fraction():num{0},denum{1}{}

Fraction::Fraction(const int& _num, const int& _denum){
  set_num(_num);
  set_denum(_denum);
  simplify();
}

Fraction::Fraction(const double& d){
  bool minus=(d<0);
  double _d=abs(d);
  int int_part=static_cast<int>(_d);
  double rest=_d-int_part;
  if (rest==0){
    num=int_part;
    denum=1;
    return;
  }
  double _num{1};
  double _denum{1};
  cout<<"\nDEBUG: _num="<<_num<<" _denum="<<_denum<<" rest="<<rest<<endl;
  approx(_num,_denum,rest);
  num=_num+=int_part*_denum;
  denum=_denum;
  if (minus){
    num*=-1;
  }
  // simplify();
}

ostream& operator<<(ostream& out, const Fraction& frac){
  out<<frac.num<<"/"<<frac.denum;
  return out;
}

istream& operator>>(istream& in, Fraction& frac){
  int num,denum;
  cin>>num>>denum;
  frac.set_num(num);
  frac.set_denum(denum);
  frac.simplify();
  return in;
}

Fraction operator+ (const Fraction& lhs ,const Fraction& rhs) {
  return Fraction(lhs.num*rhs.denum+rhs.num*lhs.denum,rhs.denum*lhs.denum);
}

Fraction operator- (const Fraction& lhs,const Fraction& rhs ) {
  return Fraction(lhs.num*rhs.denum-rhs.num*lhs.denum,rhs.denum*lhs.denum);
}

Fraction operator* (const Fraction& lhs,const Fraction& rhs) {
  return Fraction(rhs.num*lhs.num,rhs.denum*lhs.denum);
}

Fraction operator/ (const Fraction& lhs,const Fraction& rhs) {
  return Fraction(lhs.num*rhs.denum,lhs.denum*rhs.num);
}



bool operator==(const Fraction& lhs,const Fraction& rhs) {
 if (rhs.num==lhs.num && rhs.denum==lhs.denum){
   return true;
 }
 return false;
}

bool operator!=(const Fraction& lhs,const Fraction& rhs) {
 return !(rhs==lhs);
}

bool operator< (const Fraction& lhs,const Fraction& rhs) {
 return (lhs.num*rhs.denum<rhs.num*lhs.denum);
}

bool operator> (const Fraction& lhs,const Fraction& rhs) {
 return (lhs.num*rhs.denum>rhs.num*lhs.denum);
}

bool operator<=(const Fraction& lhs,const Fraction& rhs) {
 return !(lhs>rhs);
}

bool operator>=(const Fraction& lhs ,const Fraction& rhs) {
 return !(lhs<rhs);
}


Fraction& Fraction::operator= (const Fraction& other){
 num=other.num;
 denum=other.denum;
 return *this;
}

Fraction& Fraction::operator+=(const Fraction& other){
 num=num*other.denum+other.num*denum;
 denum=other.denum*denum;
 simplify();
 return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
 num=num*other.denum-other.num*denum;
 denum=other.denum*denum;
 simplify();
 return *this;
}

Fraction& Fraction::operator*=(const Fraction& other){
 num*=other.num;
 denum*=other.denum;
 simplify();
 return *this;
}

Fraction& Fraction::operator/=(const Fraction& other){
 num*=other.denum;
 denum*=other.num;
 simplify();
 return *this;
}

Fraction& Fraction::operator++(){ //префиксный
 num+=denum;
 simplify();
 return *this;
}

Fraction& Fraction::operator--(){
 num-=denum;
 simplify();
 return *this;
}

Fraction Fraction::operator++(int){
Fraction temp(*this);
num+=denum;
simplify();
return temp;
}

Fraction Fraction::operator--(int){
 Fraction temp(*this);
 num-=denum;
 simplify();
 return temp;
}

Fraction Fraction::operator-() const{
 return Fraction(-num,denum);
}

Fraction Fraction::operator+() const{
 return Fraction(num,denum);
}

Fraction Fraction::operator!() const{
 Fraction tmp;
 if (num<0){
   tmp.num=-denum;
   tmp.denum=-num;
 }
 else{
   tmp.num=denum;
   tmp.denum=num;
 }
 return tmp;
}

Fraction::operator double (){
 return static_cast<double>(num)/denum;
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

bool approx_equal(const double& lhs,const double& rhs){
 if (abs(lhs-rhs)<1e-8)
 return abs(lhs-rhs)<1e-8;
}
