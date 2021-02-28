#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
  int num;
  int denum;
public:
  int get_num();

  int get_denum();

  void set_num(const int& num);

  void set_denum(const int& denum);

  Fraction();//конструктор по умолчанию

  Fraction(const double&);//конструктор для создания frac из чисел с плавающей точкой

  Fraction(const int& _num, const int& _denum); //констркутор для создания frac заданичем числителя и знаменателя

// перегрузка операторов
  friend ostream& operator<<(ostream&, const Fraction&);
  friend istream& operator>>(istream&,  Fraction&);

  friend Fraction operator+ (const Fraction&,const Fraction&);
  friend Fraction operator- (const Fraction&,const Fraction&);
  friend Fraction operator* (const Fraction&,const Fraction&);
  friend Fraction operator/ (const Fraction&,const Fraction&);


  friend bool operator==(const Fraction&,const Fraction&);
  friend bool operator!=(const Fraction&,const Fraction&);
  friend bool operator< (const Fraction&,const Fraction&);
  friend bool operator> (const Fraction&,const Fraction&);
  friend bool operator<=(const Fraction&,const Fraction&);
  friend bool operator>=(const Fraction&,const Fraction&);



  Fraction& operator= (const Fraction&);
  Fraction& operator+=(const Fraction&);
  Fraction& operator-=(const Fraction&);
  Fraction& operator*=(const Fraction&);
  Fraction& operator/=(const Fraction&);

  Fraction& operator++();
  Fraction& operator--();
  Fraction operator++(int);
  Fraction operator--(int);

  Fraction operator-() const;
  Fraction operator+() const;
  Fraction operator!() const;//обратная дробь

  explicit operator double();// приведение frac к double
  // explicit используется для того чтобы предотвратить неоднозначность перегрузки
  // арифметических операторов (double + Fraction). Можно как Fraction привести к double
  // так и double привести к Fraction

  void simplify(); //упрощение дроби

};
