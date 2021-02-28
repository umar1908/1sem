#include <string>
#pragma once
using namespace std;
class Spell{
private:
public:
  virtual double get_damage()const=0;
  virtual double get_cost()const=0;
  virtual string get_name()const=0;
  virtual ~Spell()=default;
};
//
class Fireball:public Spell{
public:
  virtual double get_damage()const override{
    return 150;
  }
  virtual double get_cost()const override{
    return 20;
  }
  virtual string get_name()const override{
    return "Fireball";
  }
  virtual ~Fireball()=default;

};
//
//
class Lighting:public Spell{
public:
  virtual double get_damage()const override{
    return 300;
  }
  virtual double get_cost()const override{
    return 50;
  }
  virtual string get_name()const override{
    return "Lighting";
  }
  virtual ~Lighting()=default;
};
//
//
class Freeze:public Spell{
public:
  virtual double get_damage()const override{
    return 70;
  }
  virtual double get_cost()const override{
    return 10;
  }
  virtual string get_name()const override{
    return "Freeze";
  }
  virtual ~Freeze()=default;

};
//
//
class Earthquake:public Spell{
public:
  virtual double get_damage()const override{
    return 500;
  }
  virtual double get_cost()const override{
    return 100;
  }
  virtual string get_name()const override{
    return "Earthquake";
  }
  virtual ~Earthquake()=default;
};

class Default_spell:public Spell{
public:
  virtual double get_damage()const override{
    return 0;
  }
  virtual double get_cost()const override{
    return 0;
  }
  virtual string get_name()const override{
    return "(Не выбрано)";
  }
  virtual ~Default_spell()=default;
};
