#include "Warrior.h"
#include "Spell.h"

int Warrior::last_id=0;
Warrior::Warrior (double hp,double damage):_hp(hp),_damage(damage),_alive(true),_id(last_id){last_id++;}


ostream& operator<<(ostream& out,const Warrior& obj){
  out<<"\n*********************\n";
  out<<"id="<<obj._id<<endl;
  obj.print(out);
  out<<"\n*********************\n";
  return out;

}


void Warrior::set_damage(double damage){
  if (damage<0){
    throw logic_error("Invalide damage");
  }
  _damage=damage;
}

  void Warrior::get_hurt(double damage){
    _hp-=damage;
    if (_hp<=0){
      cout<<"����� c id="<<_id<<" �����\n";
      _alive=false;
    }
  }
  ostream& Goblin::print(ostream& out)const{
    out<<"���:������\n";
    if (is_alive()){
      out<<"������:���\n"<<"��������:"<<get_hp()<<endl<<"������� ����:"<<get_damage()
      <<"\n������� ����:"<<get_damage()*get_hp()<<endl;
      return out;
    }
    cout<<"������:�����\n";
    return out;
  }
  Goblin::Goblin():Warrior(20,5){
      cout<<"������ ������ � �����������:\n"<<*this;
  }

  void Goblin::strike(Warrior& target){
    if (is_alive()){
      cout<<"(id="<<get_id()<<") ������� (id="<<target.get_id()<<") c ������ "<<get_damage()*get_hp()<<endl;
    target.get_hurt(get_damage()*get_hp());
    }
    else{
      cout<<"������� �� ��c�����\n";
    }
  }

  Orc::Orc():Warrior(1000,100),_stamina(1.0){
    cout<<"������ ��� � �����������:\n"<<*this;
  }

  void Orc::strike(Warrior& target){
    cout<<"(id="<<get_id()<<") ������� (id="<<target.get_id()<<") c ������ "<<get_damage()*_stamina<<endl;
    if (_stamina>0){

      target.get_hurt(get_damage()*_stamina);
      _stamina-=0.1;
      if (abs(_stamina)<0.01){
        _stamina=0;
      }
  }
    else{
      cout<<"��� ���!"<<endl;
    }
  }
  ostream& Orc::print(ostream& out)const{
    out<<"���:���\n";
    if (is_alive()){
      out<<"������:���\n"<<"��������:"<<get_hp()<<endl<<"������� ����:"<<get_damage()
      <<"\n������� ����:"<<get_damage()*_stamina<<endl<<"������������:"<<_stamina<<endl;
      return out;
    }
    cout<<"������:�����\n";
    return out;
  }
  void Orc::relax(){
    if (_stamina<1){
      _stamina+=0.1;
      cout<<"�(id="<<this->get_id()<<") ������������� 0.1 ������������";
    }
  }

  Whitcher::Whitcher():Warrior(200,0),_mana(150),current_spell(new Default_spell){
    cout<<"������� ������ � �����������:"<<*this;
  }
  void Whitcher::recharge(){
    if (_mana<150){
      _mana+=10;
      cout<<"(id="<<get_id()<<") ����������� 10�� ����\n";
    }
  }

  void Whitcher::strike(Warrior& target){
    if (current_spell==nullptr){
      cout<<"�� ������� ����������\n";
      return;
    }
    cout<<"(id="<<get_id()<<") ������� (id="<<target.get_id()<<") c ������� "
    <<current_spell->get_name()<<endl;
    if (_mana>=current_spell->get_cost()){
      target.get_hurt(current_spell->get_damage());
      _mana-=current_spell->get_cost();
    }
    else{
      cout<<"������������ ���� ��� ���������� ����������� �����\n";
  }
}

ostream& Whitcher::print(ostream& out)const{
  out<<"���:������\n";
  if (is_alive()){
    out<<"������:���\n"<<"��������:"<<get_hp()<<endl<<"��������� ����������:"<<current_spell->get_name()
    <<"\n������� ����:"<<current_spell->get_damage()<<endl<<"����:"<<_mana<<endl;
    return out;
  }
  cout<<"������:�����\n";
  return out;
}
