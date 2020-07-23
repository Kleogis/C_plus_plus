#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character
{
    private:
        string family_name;
    
    public:
        void attack(Character &opponent);
        Elf(const string &n, double h, double aS, string f_n);
//        string getFamily_Name();
    
};

#endif
