#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

#include "Warrior.h"

//default constructor

Warrior::Warrior(const string &n, double h, double aS, string a) : Character(WARRIOR, n, h, aS), allegiance(a){}

// string Warrior::getAllegiance{
//     return allegiance;
// }

void Warrior::attack(Character & opponent){
//     double d;
//     if(opponent.getType() == WARRIOR){
//         Warrior &opp = dynamic_cast<Warrior &>(opponent);
//         if(opp.allegiance == allegiance){
//             cout << "Warrior " << getName() << " does not attack Warrior " << opp.name << "." << endl;
//             cout << "They share an allegiance with " << allegiance;
//         }
//         else{
//             //The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
//             d = ((health) / MAX_HEALTH) * attackStrength;
//             opponent.damage(d);
//             cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
//             cout << opponent.getName() << " takes " << d << " damage.";
//         }
//      if(opponent.getType() == WARRIOR || opponent.getType() == WIZARD){
//             d = ((health) / MAX_HEALTH) * attackStrength;
//             opponent.damage(d);
//             cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
//             cout << opponent.getName() << " takes " << d << " damage.";
//     }
//     }

//         return;
// }
    cout << "Warrior " << name << " ";
    double d = attackStrength * (health / MAX_HEALTH);
    if (opponent.getType() == WARRIOR)
    {
        Warrior& opp = dynamic_cast<Warrior&>(opponent);
        if (opp.allegiance == allegiance)
        {
            cout << "does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    cout << "attacks " << opponent.getName() << " --- SLASH!!" << endl;
    cout << opponent.getName() << " takes " << d << " damage." << endl;
    opponent.damage(d);
}
