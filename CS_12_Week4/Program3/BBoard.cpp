#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

#include "BBoard.h"

//string Global_username;

BBoard::BBoard(){
    title = "Welcome to CS12 Bulletin Board";
    vector<User> userList;
    User currentUser;
    vector<Message> messageList;
}

BBoard::BBoard(const string & tit){
    title = "Welcome to CS12 Bulletin Board";
    vector<User> userList;
    User currentUser;
    vector<Message> messageList;
}

bool BBoard::loadUsers(const string & file_name){
    
    // Create input stream and open input dat file.
    ifstream inFS;
    string input_username;
    string input_password;
    inFS.open(file_name);
    
       // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if (!inFS.is_open()) {
//      cout << "Error loading users from file " << file_name << endl;
        return false;
    }
       
   // Read in integers from input file to vector.
    while (inFS >> input_username){
        if (input_username != "end"){
            inFS >> input_password;
            User input_user(input_username, input_password);
            userList.push_back(input_user);
        } else {
            break;
        }
    }
   // Close input stream.
    inFS.close();
    return true;   
}

void BBoard::display_vector(){
    for (unsigned int i = 0; i < userList.size(); ++i){
        cout << i << userList.at(i).getUsername() << "   " << userList.at(i).Get_password();
    }
    return;
}    

bool BBoard::login(){
//    User uu;
    string UserN;
    string UserP;
    string uname;
    string pass;
    User Tempo;
//    Bboard USER_NAME;
    bool Check_if_true = false;
    
    cout << title << endl;
    while ((UserN != "q") && (UserN != "Q")){
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> UserN;
        cout << endl;
        if ((UserN == "q") || (UserN == "Q")){
            cout << "Bye!" << endl; 
            break;
        }
        
//        cout << endl;
        
        cout << "Enter your password: ";
        cin >> UserP;
        cout << endl;
        for (unsigned int i = 0; i < userList.size(); ++i){
            currentUser = userList.at(i);
            if ((currentUser.getUsername() == UserN) && currentUser.Get_password() == UserP){
                cout << "Welcome back " << currentUser.getUsername() << "!" << endl;
                cout << endl;
                currentUser = userList.at(i);
                pass = UserP;
                Check_if_true = true;
               
                return true;
            }
        }
        
        if (Check_if_true !=true){          
            cout << "Invalid Username or Password!" << endl;
        }
        cout << endl;
    }
    if ((UserN != "q") && (UserN != "Q")){
        User(uname,pass);
        run();
    }
    return false;
}

void BBoard::run(){
    User uu;
    Message mm;
    char EnterKey = 'i';
    string athr = currentUser.getUsername();
    string sbjct;
    string body;
        while((EnterKey != 'q') && (EnterKey != 'Q')){
            cout << "Menu" << endl;
            cout <<  "- Display Messages ('D' or 'd')" << endl;
            cout <<  "- Add New Message ('N' or 'n')" << endl;
            cout <<  "- Quit ('Q' or 'q')" << endl;
            cout <<  "Choose an action: " ;
            cin >> EnterKey;
            cout << endl;

            if (EnterKey == 'D' || EnterKey == 'd'){
                if (messageList.size() != 0){
                    for (unsigned i = 0; i < messageList.size(); ++i){
                        cout << "---------------------------------------------------------"<< endl;
                        cout << "Message #" << i+1 << ": "<< messageList.at(i).Get_subject() << endl;
                        cout << "from " << athr << ": " << messageList.at(i).Get_body() << endl;
                    }
                cout << "---------------------------------------------------------"<< endl;
                cout << endl;
                }
                else {
//                cout << endl;    
                cout << "Nothing to Display." << endl;
                cout << endl;
                }
            }
            
            else if (EnterKey == 'N' || EnterKey == 'n'){
                cout << "Enter Subject: ";
                cin.ignore();
                getline(cin, sbjct);
                cout << endl;
                cout << "Enter Body: ";
                getline(cin, body);
                cout << endl;
                Message MesInput(athr, sbjct, body);
                messageList.push_back(MesInput);

                cout << "Message Recorded!" << endl;
                cout << endl;
            } 
            else if ((EnterKey == 'q') || (EnterKey == 'Q')){
                cout << "Bye!" << endl; 
                break;
            }
        }
      
    return;
}

string BBoard::Get_title() const{
    return title;
}

User BBoard::Get_currentUser() const{
    return currentUser;
}

