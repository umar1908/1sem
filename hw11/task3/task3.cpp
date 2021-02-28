#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
#include <cmath>
// #include <cstdlib>
// #include<utility>
#include <exception>
// #include <bitset>
#include<string>
#include"Warrior.h"
#include "Factory.h"







int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  Goblin_factory goblin_factory;
  Orc_factory orc_factory;
  Whitcher_factory whitcher_factory;
  vector<Warrior*> creatures;
  std::string name{"test name"};
  double param{100};
  goblin_factory.create_Warrior();
  goblin_factory.create_Warrior(name);
  goblin_factory.create_Warrior(name,param,20);


  orc_factory.create_Warrior("Name 2",0.5);
  orc_factory.create_Warrior(name);
  orc_factory.create_Warrior();

  whitcher_factory.create_Warrior();
  whitcher_factory.create_Warrior("Name 3");
  whitcher_factory.create_Warrior(param);






}
