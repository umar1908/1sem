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
  creatures.push_back(goblin_factory.create_Warrior());
  creatures.push_back(orc_factory.create_Warrior());
  creatures.push_back(whitcher_factory.create_Warrior());
  cout<<"Вывод из вектора:\n";
  for (const auto& creature:creatures ){
    cout<<*creature<<endl;
  }

  Goblin g;
  Orc o;
  Whitcher w;
  cout<<endl;
  o.strike(g);
  g.strike(o);
  o.strike(w);
  Fireball s1;
  Freeze s2;
  Lighting s3;
  Earthquake s4;
  w.set_spell(&s1);
    w.strike(o);
  w.set_spell(&s2);
    w.strike(o);
  w.set_spell(&s3);
    w.strike(o);
  w.set_spell(&s4);
  w.strike(o);
  cout<<"\nСостояние персонажей\n";
  cout<<o<<g<<w;
  w.recharge();
  w.recharge();
  w.recharge();
  w.strike(o);

}
