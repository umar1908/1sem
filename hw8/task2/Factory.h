#include"Warrior.h"

class Warrior_factory{
public:
  virtual Warrior* create_Warrior()=0;
  virtual ~Warrior_factory()=default;
};

class Goblin_factory{
public:
  virtual Warrior* create_Warrior(){return new Goblin;}
};


class Orc_factory{
public:
  virtual Warrior* create_Warrior(){return new Orc;}
};


class Whitcher_factory{
public:
  virtual Warrior* create_Warrior(){return new Whitcher;}
};
