#include <iostream>
#include <iomanip>
// #include <functional>
#include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
#include <cstdlib>
using namespace std;

struct Student;
struct Lesson{
  Lesson(int,unsigned int,unsigned int,unsigned int,unsigned int);
  int less_id;
  // Date_Time date;
  unsigned int date;
  unsigned int start_hour;
  unsigned int start_minute;
  unsigned int duration;
  vector<Student*> Students;
  void print();
};

struct Student{
  Student(vector<Lesson>&);
  string name;
  string surname;
  int stud_id;
  vector<Lesson*> Lessons;
  bool was_on_lesson(int); //�������� ����������� �������� �� ������
  void print(); //������� ���������� � �������� ������� ���������� �� ������
  void contacts(); // ������� ���� � ��� ���������� ������� �� �����
};


int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������
  cout<<endl;
  int n;
  //�������� ������ � ���������
  cout<<"������� ���������� ������"<<endl;
  cin>>n;
  // cout<<"��������� ������ �� ������ ������";
  vector<Lesson> lessons_vector;
  for (auto i=0;i<n;++i){
    lessons_vector.push_back(Lesson(i,rand(),12,30,rand()));
  }
  // �������� ������ �� ����������
  cout<<"������� ���������� ���������"<<endl;
  n=0;
  cin>>n;
  vector<Student> students_vector;
  for (size_t i = 0; i < n; i++) {
    // auto student=new Student(lessons_vector);
    // students_vector.push_back(student);
    students_vector.push_back(Student(lessons_vector));

  }
  // ������� ��� ������� � ����������� ����������� � ���������������� ���������
  for(auto& less: lessons_vector){
    less.print();
  }
  // ������� ���� ��������� � ����������� � ���������� �������
  for(auto student: students_vector){
    student.print();
  }
  // ������� ��� ������� �������� ������ ��������� � �������� �� ����������� �� ����� ����
  for(auto& student: students_vector){
    student.contacts();
    cout<<"*******************"<<endl;
  }

  // for(auto elem: students_vector){
  //   delete elem;
  // }
  return 0;
}

Lesson::Lesson(int _less_id,unsigned int _date,unsigned int _start_hour,
              unsigned int _start_minute,unsigned int _duration):
              less_id(_less_id),date(_date),start_hour(_start_hour),
              start_minute(_start_minute),duration(_duration){
  cout<<"������� �������"<<endl;
  print();

}

Student::Student(vector<Lesson>& lessons){
  int n;
  cout<<"������� id ��������"<<endl;
  cin>>this->stud_id;
  cout<<"������ ��� ��������"<<endl;
  cin>>this->name;
  cout<<"������� ������� ��������"<<endl;
  cin>>this->surname;
  cout<<"������� ���������� ������� ������� ������� �������"<<endl;
  cin>>n;
  cout<<"������� less_id ������, ������� ������� �������"<<endl;
  for (auto i=0;i<n;++i){
    int less_id;
    cin>>less_id;
    for (Lesson& lesson:lessons){
      if (lesson.less_id==less_id){
        Lessons.push_back(&lesson); //���������� � ������ �������� ������ �� ������
        lesson.Students.push_back(this); //���������� � ������ ������ �� ������ �������
      }
    }
    if (Lessons.empty()){
      cout<<"����� ������ �� ������� � ����!"<<endl;
      exit(0);
    }
    if (Lessons.back()->less_id!=less_id){
      cout<<"����� ������ �� ������� � ����!"<<endl;
      exit(0);
    }
  }
  cout<<"������� ������ � ���� ������"<<endl;
  // print();

}


bool Student::was_on_lesson(int less_id){
  auto res=count_if(begin(Lessons),end(Lessons),[&less_id](const Lesson* lesson)->bool{return lesson->less_id==less_id;});
  // int res=0;
  if (res==0){
    return false;
  }
  return true;
}

void Student::print(){
  cout<<"������ �� ��������"<<endl;
  cout<<name<<" "<<surname<<"(id="<<stud_id<<")"<<endl;
  cout<<"���������� ������:"<<endl;
  for (auto less: Lessons){
    cout<<"less_id="<<less->less_id<<endl;
    // less->print();
  }
  cout<<"*******************"<<endl;

}

void Lesson::print(){
  cout<<"������ �� �������:\nless_id="<<less_id<<"\n����:"<<date<<"\n����� ������: "<<
  start_hour<<":"<<start_minute<<
  "\n������������: "<<duration<<"\n���������������� ��������:"<<endl;
  for (Student* stud: Students){
    cout<<stud->name<<" "<<stud->surname<<" id="<<stud->stud_id<<endl;
  }
  cout<<"*******************************"<<endl<<endl;
}

void Student::contacts(){
  cout<<"���� � �������� ������������� "<<name<<" "<<surname<<endl;
  vector<int> contacts_ids;
  // int stud_id=this->stud_id;
  for(auto lesson:Lessons){
    for(auto student: lesson->Students){
      if ((student->stud_id!=stud_id)&&
        (count(begin(contacts_ids),end(contacts_ids),student->stud_id)==0)) {
        contacts_ids.push_back(student->stud_id);
        cout<<student->name<<" "<<student->surname<<endl;
    }

  }
}
}
