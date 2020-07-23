#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Character.h"

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength)
{}
  
HeroType Character::getType() const {
    return type;
}

const string& Character::getName() const {
    return name;
}

int Character::getHealth() const{
    return (static_cast<int>(health));
}

void Character::setHealth(double h){
    health = h;
}

void Character::damage(double d){
    health = health - d;
    return;
}

bool Character::isAlive() const{
    if (health > 0){
        return true;
    }
    else{
        return false;
    }
}

