#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "Wizard.h"
#include "Character.h"

//default constructor

Wizard::Wizard(const string &n, double h, double aS, int r) : Character(WIZARD, n, h, aS), rank(r){}

int Wizard::getRank() const{
    return rank;
}

void Wizard::attack(Character & opponent){
//     double d;
//     d = attackStrength;
//     if(opponent.getType() == WIZARD){
        
//         Wizard &opp = dynamic_cast<Wizard &>(opponent);
//          //The damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
//             d = attackStrength * (static_cast<double>(rank) / static_cast<double>(opp.getRank()));
//             opponent.damage(d);
//             cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
//             cout << opponent.getName() << " takes " << d << " damage.";
//     }
//      if(opponent.getType() == ELF || opponent.getType() == WARRIOR){
//          //The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
//             d = attackStrength;
//             opponent.damage(d);
//             cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
//             cout << opponent.getName() << " takes " << d << " damage.";
//     }
//         return;
// }

    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    double d = attackStrength;
    if (opponent.getType() == WIZARD)
    {
        Wizard& opp = dynamic_cast<Wizard&>(opponent);
        d = attackStrength * (static_cast<double>(rank) / static_cast<double>(opp.getRank()));
    }
    cout << opponent.getName() << " takes " << d << " damage." << endl;
    opponent.damage(d);
}