#include"Warrior.h"
#include <utility>



class Goblin_factory{
public:
  template<typename...Types>
   Warrior* create_Warrior(Types&&...params){return new Goblin(forward<Types>(params)...);}
};


class Orc_factory{
public:
  template <typename...Types>
   Warrior* create_Warrior(Types...params){return new Orc(forward<Types>(params)...);}
};


class Whitcher_factory{
public:
  template<typename...Types>
   Warrior* create_Warrior(Types...params){return new Whitcher(forward<Types>(params)...);}
};
