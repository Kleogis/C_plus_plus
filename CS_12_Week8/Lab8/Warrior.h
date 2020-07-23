#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character{
    private:
        string allegiance;
    
    public:
        void attack(Character & opponent);
        Warrior(const string &n, double h, double aS, string a);
//         string getAllegiance;   
};

#endif