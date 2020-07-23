#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "Elf.h"
#include "Character.h"

//default constructor

Elf::Elf(const string &n, double h, double aS, string f_n) : Character(ELF, n, h, aS), family_name(f_n){}

// string Elf::getFamily_Name(){
//     return family_name;
// }

void Elf::attack(Character & opponent){
    double d = ((health) / MAX_HEALTH) * attackStrength;;
 
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.family_name == family_name){
            cout << "Elf " << getName() << " does not attack Elf " << opp.name << "." << endl;
            cout << "They are both members of the " << family_name << " family." << endl;
            return;
        }
    }
       
    //The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
            
            cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage."<< endl;
            opponent.damage(d);
}