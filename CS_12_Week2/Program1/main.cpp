#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

void readData(const string & FileName, vector<double> & FlightPathAngles, vector<double> & LiftCoef){
    
// Create input stream and open input dat file.
    ifstream inFS;
    double Nums;
    inFS.open(FileName);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if (!inFS.is_open()) {
        cout << "Error opening " << FileName << endl;
        exit(1);
   }
       
   // Read in integers from input file to vector.
    vector<double> Inputs;
    while (inFS >> Nums){
        Inputs.push_back(Nums);
        inFS.ignore();
    }
    for(unsigned int i =0; i < Inputs.size(); ++i){
        if(i % 2 == 0){
            FlightPathAngles.push_back(Inputs.at(i));
        }
        else{
            LiftCoef.push_back(Inputs.at(i));
        }
    }

   
   // Close input stream.
    inFS.close();
    return;
}


double interpolation(double FlightPathAngle_value, const vector<double>& FlightPathAngles, const vector<double>& LiftCoef){
    double LiftCoef_int = 0;
    for (unsigned int i =0; i < FlightPathAngles.size(); ++i){
        if (FlightPathAngles.at(i) == FlightPathAngle_value){          
            return (LiftCoef.at(i));
        }
        else if (FlightPathAngle_value > FlightPathAngles.at(i) && FlightPathAngle_value < FlightPathAngles.at(i + 1)){
            LiftCoef_int = LiftCoef.at(i) + (FlightPathAngle_value - FlightPathAngles.at(i)) / (FlightPathAngles.at(i + 1) - FlightPathAngles.at(i)) * (LiftCoef.at(i + 1) - LiftCoef.at(i));
        }
    }
    return LiftCoef_int;
}

bool isOrdered(const vector<double>& FlightPathAngles){

    if (FlightPathAngles.size() == 0 || FlightPathAngles.size() == 1){
        return (true);
    }
    if (FlightPathAngles.size() >= 2){
        for (unsigned int i =0; i < FlightPathAngles.size()-1; ++i){
            for (unsigned int j = i +1; j < FlightPathAngles.size(); ++j){
                if (FlightPathAngles.at(i) == FlightPathAngles.at(j)){
                    return (true);
                }
                else if (FlightPathAngles.at(i) > FlightPathAngles.at(j)){
                    return (false);
                }
            }
        }
    }

    return (true);
}

void reorder(vector<double>& FlightPathAngles, vector<double> & LiftCoef){
    if (isOrdered(FlightPathAngles) == false){
        for (unsigned int i = 0; i < FlightPathAngles.size() - 1; ++i){
            for (unsigned int j = 0; j < FlightPathAngles.size() - 1 - i; ++j){
                if (FlightPathAngles.at(j) > FlightPathAngles.at(j + 1)){
                    swap(FlightPathAngles.at(j), FlightPathAngles.at(j + 1));
                    swap(LiftCoef.at(j), LiftCoef.at(j + 1));
                }
            }
        }
    }
    return;
}

int main(int argc, char* argv[]){
    string FileName;
    string Answer;
    FileName = argv[1];
    
//    ifstream inFS;
//    inFS.open(FileName);
   
    
    vector<double> FlightPathAngles;
    vector<double> LiftCoef;
    double FlightPathAngle_val;
    
    readData(FileName, FlightPathAngles, LiftCoef);
    
    cout << "Enter flight path angle value: " << endl;
    cin >> FlightPathAngle_val;
    
    
    if (isOrdered(FlightPathAngles) == true){
        cout << "Lift coefficient is " << interpolation(FlightPathAngle_val, FlightPathAngles, LiftCoef) << endl;
    }
    else{
        reorder(FlightPathAngles, LiftCoef);

        cout << "Lift coefficient is " << interpolation(FlightPathAngle_val, FlightPathAngles, LiftCoef) << endl;
    }
    
    while (Answer != "no" && Answer != "No"){
        cout << "Do you want to calculate an another flight-path angle ?" << endl;
        cin >> Answer;
        if (Answer == "yes" || Answer == "Yes"){
            cout << "Enter flight path angle value: " << endl;
            cin >> FlightPathAngle_val;
            if (isOrdered(FlightPathAngles) == true){
                cout << "Lift coefficient is " << interpolation(FlightPathAngle_val, FlightPathAngles, LiftCoef) << endl;
            }
            else {
                reorder(FlightPathAngles, LiftCoef);
                cout << "Lift coefficient is " << interpolation(FlightPathAngle_val, FlightPathAngles, LiftCoef) << endl;
            }
        }
    }
    return 0;
}