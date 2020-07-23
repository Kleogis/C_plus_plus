#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character{
    private:
        int rank;
    
    public:
        void attack(Character & opponent);
        Wizard(const string &n, double h, double aS, int r);
        int getRank() const;
    
};

#endif
