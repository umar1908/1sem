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

  Fraction();//����������� �� ���������

  Fraction(const double&);//����������� ��� �������� frac �� ����� � ��������� ������

  Fraction(const int& _num, const int& _denum); //����������� ��� �������� frac ��������� ��������� � �����������

// ���������� ����������
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
  Fraction operator!() const;//�������� �����

  explicit operator double();// ���������� frac � double
  // explicit ������������ ��� ���� ����� ������������� ��������������� ����������
  // �������������� ���������� (double + Fraction). ����� ��� Fraction �������� � double
  // ��� � double �������� � Fraction

  void simplify(); //��������� �����

};
