#include <iostream>
#include <iomanip>
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
  enum class Months{
    Jan=1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
  };
using namespace std;
void show_days_count(Months);


int main(){
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  int month_num;
  cout<<"1-январь\n2-‘евраль\n3-ћарт\n4-јпрель\n5-ћай\n6-»юнь\n7-»юль\n";
  cout<<"8-јвгуст\n9-—ент€брь\n10-ќкт€брь\n11-Ќо€брь\n12-ƒекабрь\n"<<endl;
  cout<<"¬ведите мес€ц"<<endl;
  cin>>month_num;
  Months month=static_cast<Months>(month_num);
  cout<<"ƒней в мес€це:"<<endl;
  show_days_count(month);





  return 0;
}
void show_days_count(Months month){
  switch (month){
    case Months::Jan:
      cout<<31<<endl;
      break;
    case Months::Feb:
      cout<<28<<endl;
      break;
    case Months::Mar:
      cout<<31<<endl;
      break;
    case Months::Apr:
      cout<<30<<endl;
      break;
    case Months::May:
      cout<<31<<endl;
      break;
    case Months::Jun:
      cout<<30<<endl;
      break;
    case Months::Jul:
      cout<<31<<endl;
      break;
    case Months::Aug:
      cout<<31<<endl;
      break;
    case Months::Sep:
      cout<<30<<endl;
      break;
    case Months::Oct:
      cout<<31<<endl;
      break;
    case Months::Nov:
      cout<<30<<endl;
      break;
    case Months::Dec:
      cout<<31<<endl;
      break;
  }

}
