#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#include "Distance.h"


//constractors
Distance::Distance(){
    feet = 0;
    inches = 0.0;      
}

Distance::Distance(unsigned ft, double in){
    feet = ft;
    if (in < 0){
        inches = -in;
    }
    else{
    inches = in;
    }
    init();
}

Distance::Distance(double in){
    feet = 0;
    if (in < 0){
        inches = -in;
    }
    else{
    inches = in;
    }
    init();
    
}

void Distance::init(){
    if (inches < 0){
        inches = -inches;
    }
    if (inches >= 12){
        feet = fabs(feet) + (static_cast<int>(inches) / 12);
        inches = inches - (static_cast<int>(inches) / 12) * 12; 
    }
    else{
        feet = fabs(feet);
        inches = fabs(inches);
    }
    return;
}

unsigned Distance::getFeet() const{  
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    double InchTotal;
    InchTotal = feet * 12 + inches;
    return InchTotal;
}

double Distance::distanceInFeet() const{
    double FeetTotal;
    FeetTotal = feet + 0.0833333 * inches;
    return FeetTotal;
}

double Distance::distanceInMeters() const{
    double MeterTotal;
    MeterTotal = distanceInInches() * 0.0254;
    return MeterTotal;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance TotalDist;
//    rhs.feet = fabs(rhs.feet);
//    rhs.inches = fabs(rhs.inches);
    TotalDist.feet = feet + rhs.feet;
    TotalDist.inches = inches + rhs.inches;
    if (TotalDist.inches >= 12){
        TotalDist.feet = TotalDist.feet + (static_cast<int>(TotalDist.inches) / 12);
        TotalDist.inches = TotalDist.inches - (static_cast<int>(TotalDist.inches) / 12) * 12; 
    }
    return TotalDist;
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance TotalDist;
    Distance RHS;
    TotalDist.inches = inches;
    TotalDist.feet = feet;
    RHS.inches = rhs.inches;
    unsigned count = 0;
    unsigned count2 = 0;
//    rhs.feet = fabs(rhs.feet);
//    rhs.inches = fabs(rhs.inches);
    if (TotalDist.inches < rhs.inches && TotalDist.feet > rhs.feet){
        while (!(TotalDist.inches > rhs.inches)){
            TotalDist.inches = TotalDist.inches + 12;
            count++;
        }
        TotalDist.feet = TotalDist.feet - count - rhs.feet;
        TotalDist.inches = TotalDist.inches - rhs.inches;
    }
    else if (TotalDist.inches <= rhs.inches && TotalDist.feet <= rhs.feet){
        TotalDist.feet   = rhs.feet - feet;
        TotalDist.inches = rhs.inches - inches;
    }
    else if (TotalDist.inches > rhs.inches && TotalDist.feet < rhs.feet){
         while (!(TotalDist.inches < RHS.inches)){
            RHS.inches = RHS.inches + 12;
            count2++;
        }
        TotalDist.feet = rhs.feet - TotalDist.feet - count2;
        TotalDist.inches = RHS.inches - TotalDist.inches;
    }
    else {
        TotalDist.feet   = feet - rhs.feet;
        TotalDist.inches = inches - rhs.inches;
    }
    return TotalDist;
}

std::ostream & operator<<(ostream & out, const Distance & rhs) {
      out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
      return out;
}

