#ifndef PH
#define PH
#include <iostream>
using namespace std;

class Phone_number{
private:
  short int country_code;
  short int op_code;
  int number;
  friend ostream& operator<<(ostream&, const Phone_number&); //���������� ��������� <<
public:
  Phone_number(short int ,short int,int);
  Phone_number(); //����������� �� ���������
  void print_number(); // ������ ������
  // ������ ����� ����������
  short int get_country_code() const;
  short int get_op_code() const;
  int get_number() const;
  void set_country_code(short int);
  void set_op_code(short int);
  void set_number(int);
  // ����� ����� ����������
};

#endif
