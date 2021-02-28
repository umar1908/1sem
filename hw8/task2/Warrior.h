#pragma once
#include<iostream>
#include"Spell.h"


class Warrior{
private:
  static int last_id;
  double _hp;
  double _damage;
  bool _alive;
  int _id;
  virtual ostream& print(ostream&)const=0;
  friend  ostream& operator<<(ostream&,const Warrior&);
public:
  Warrior (double hp,double damage);
  virtual ~Warrior()=default;
  virtual void strike(Warrior&)=0;
  double get_hp()const{return _hp;}
  double get_damage()const{return _damage;}
  bool is_alive()const{return _alive;}
  void get_hurt(double damage);
  int get_id()const{return _id;}
protected:
  void set_damage(double damage);
};



class Goblin:public Warrior{
private:
  virtual ostream& print(ostream&)const override;
public:
  Goblin();
  virtual void strike(Warrior&)override;
  virtual ~Goblin()=default;
};

class Orc:public Warrior{
private:
  double _stamina; //выносливость,которая будет влиять на силу удара
  virtual ostream& print(ostream&)const override;
public:
  void relax();//восстановление выносливости
  Orc();
  virtual ~Orc()=default;
  virtual void strike(Warrior&)override;

};



class Whitcher:public Warrior{
private:
  Spell* current_spell;
  double _mana;//уровень маны
  virtual ostream& print(ostream&)const override;
public:
  double get_mana(){return _mana;}
  Whitcher();
  virtual ~Whitcher()=default;
  void recharge();//восстановление маны
  virtual void strike(Warrior&)override;
  void set_spell(Spell* spell){current_spell=spell;}

};
