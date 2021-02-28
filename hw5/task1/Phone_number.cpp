#include "Phone_number.h"

short int Phone_number::get_country_code() const{
  return country_code;
}
short int Phone_number::get_op_code() const{
  return op_code;
}
int Phone_number::get_number() const{
  return number;
}
void Phone_number::set_country_code(short int number){
  this->number=number;
}
void Phone_number::set_op_code(short int op_code){
  this->op_code=op_code;
}
void Phone_number::set_number(int number){
  this->number=number;
}

Phone_number::Phone_number():country_code(0),op_code(0),number(0){};





void Phone_number::print_number(){
cout<<"+"<<country_code<<"("<<op_code<<")"<<number<<endl<<"***************"<<endl;
return;
}

Phone_number::Phone_number(short int _country_code, short int _op_code, int _number):
            country_code(_country_code),op_code(_op_code),number(_number){}

ostream& operator<< (ostream& os, const Phone_number& phone){
os<<"+"<<phone.country_code<<"("<<phone.op_code<<")"<<phone.number;
return os;
}
