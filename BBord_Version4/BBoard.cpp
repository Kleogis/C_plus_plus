#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

#include "BBoard.h"
#include "Message.h"
#include "Topic.h"
#include "User.h"
#include "Reply.h"

//string Global_username;

BBoard::BBoard(){
    title = "Welcome to CS12 Bulletin Board"; //FIXME: Maybe it should be title = "";
    vector<User> userList;
    currentUser = nullptr;
    vector<Message *> messageList;
}

BBoard::BBoard(const string & ttl){
    title = ttl;
    //title = "Welcome to CS12 Bulletin Board";
    vector<User> userList;
    currentUser = nullptr;
    vector<Message *> messageList;
}

BBoard::~BBoard(){
    for (unsigned i =0; i < messageList.size(); ++i){
        delete messageList.at(i);
    }
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

void BBoard::login(){
    string userEnter;
    cout << "Welcome to " << title;


    while ((userEnter !="q")||(userEnter !="Q")){
        cout << endl << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userEnter;
        if ((userEnter == "q") || (userEnter == "Q")){
            cout << "Bye!" << endl;
            currentUser = 0;
            exit(1);
            return;
        }

        string Pass;
        cout << "Enter your password: ";
        cin >> Pass;


        for (unsigned i= 0 ; i<userList.size(); i++) {
            if ((userList.at(i).check (userEnter , Pass))&&(userEnter != "" || Pass !="")){
                currentUser = &userList.at(i);
                cout << endl;
                cout << "Welcome back " << userEnter<<'!' << endl;
                cout << endl;
                return;
            }
        }
        cout << "Invalid Username or Password!"  << endl;
    }

}

void BBoard::run(){
    char EnterKey = 'i';
    string athr = currentUser->getUsername();
    if (currentUser == 0){
        return;
    }
    string sbjct;
    string body;
        while((EnterKey != 'q') && (EnterKey != 'Q')){
            cout << "Menu" << endl;
            cout <<  "- Display Messages ('D' or 'd')" << endl;
            cout <<  "- Add New Topic ('N' or 'n')" << endl;
            cout <<  "- Add Reply to a Topic ('R' or 'r')" << endl;
            //cout <<  "- Add New Message ('N' or 'n')" << endl;
            cout <<  "- Quit ('Q' or 'q')" << endl;
            cout <<  "Choose an action: " ;
            cin >> EnterKey;
           // cout << endl; 
            if (EnterKey == 'D' || EnterKey == 'd'){
                if (messageList.size() != 0){
                    cout << endl;
                    display();
                }
                else{
                    cout << endl;    
                    cout << "Nothing to Display." << endl;
                    cout << endl;
                }
            }
            else if (EnterKey == 'N' || EnterKey == 'n'){
                addTopic();
            }
            else if (EnterKey == 'R' || EnterKey == 'r'){
                addReply();
            }
            else if (EnterKey == 'q' || EnterKey == 'Q'){
                cout << "Bye!" << endl; 
                currentUser =0;
                break;
            }
        }
      
    return;
}

// string BBoard::Get_title() const{
//     return title;
// }

// User BBoard::Get_currentUser() const{
//     return currentUser;
// }

bool BBoard::loadMessages(const string & datafile){
    ifstream IFIn;
    stringstream ss;

    unsigned messageNum = 0;

    string tempStr;
    string checkType;
    vector<unsigned> childIndex;
    int counter = 0;
    int toInt = 0;

    string Author;
    string Subject;
    string Body;
    string Child;
    unsigned ID;

    IFIn.open(datafile.c_str());
    if (!IFIn.is_open()){
        return false;
    }

    IFIn >> messageNum;
    if(messageNum != 0){
        for(unsigned i = 0; i < messageNum; ++i){
            IFIn >> tempStr;
            checkType = tempStr;
            Author = "";
            Subject = "";
            Body = "";
            Child = "";
            ID = 0;
            while(tempStr != "<end>"){
                if(tempStr != ":body:" && tempStr != ":children"){
                    IFIn >> tempStr;
                }
                if(tempStr == ":id:"){
                    IFIn.ignore(); //whitespace
                    IFIn >> ID;
                }
                else if(tempStr == ":subject:"){
                    IFIn.ignore();
                    getline(IFIn, Subject);
                }
                else if(tempStr == ":from:"){
                    IFIn.ignore();
                    IFIn >> Author;
                }
                else if(tempStr == ":children:"){
                    IFIn.ignore();
                    while(tempStr != ":body:"){
                        IFIn >> tempStr;
                        ss.clear();
                        ss.str(tempStr);
                        ss >> toInt;
                        childIndex.push_back(toInt);
                    }
                }
                else if(tempStr == ":body:"){
                    IFIn.ignore();
                    getline(IFIn, tempStr);
                    Body += tempStr;
                    while(tempStr != "<end>"){
                        getline(IFIn, tempStr);
                        if(tempStr != "<end>"){
                        Body += "\n" + tempStr;
                        }
                    }
                }
            }
        if(checkType == "<begin_topic>"){
            Topic * tempTop = new Topic(Author, Subject, Body, ID);
            messageList.push_back(tempTop);
        }
        else if(checkType == "<begin_reply>"){
            Reply * tempRep = new Reply(Author, Subject, Body, ID);
            messageList.push_back(tempRep);
        }
        childIndex.push_back(0);
        }
        for(unsigned j = 0; j < childIndex.size() - 1; ++j){
            if(childIndex.at(j) != 0){
                (messageList.at(counter))->addChild(messageList.at(childIndex.at(j) - 1));
            }
            else if(childIndex.at(j) == 0 && childIndex.at(j + 1) != 0){
                counter++;
            }
        }
    }
    return true;
}
   
bool BBoard::saveMessages(const string & datafile){
    ofstream FOut;

    FOut.open(datafile.c_str());

    FOut << messageList.size() << endl;
    for (unsigned i = 0; i < messageList.size(); ++i){
        FOut << messageList.at(i)->toFormattedString();
    }
    FOut.close();
    return true;
}
    
void BBoard::addTopic(){
    string athr = currentUser->getUsername();
    string sbjt;
    int sz_list;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, sbjt);
    string body;
    string InputBody;
    cout << "Enter Body: ";
    getline(cin,InputBody);
    //The body ends when the user enters an empty line
    while (InputBody != ""){
        body = body + InputBody + '\n';
        getline(cin,InputBody);
    }
    body = body.substr(0, body.size() - 1);
    cout << endl;
    sz_list = messageList.size() + 1;
    
    Topic * NewTopic = new Topic(athr, sbjt, body, sz_list);
    messageList.push_back(NewTopic);
}

void BBoard::addReply(){
    int InputID;
    int sizeID = messageList.size()+1;
    string sbjt;
    string body;
    string tempStr;   

    cout << "Enter Message ID: ";
    cin >> InputID;
    if (InputID < 0){
        return;
    }
    int id = messageList.size();
    while ((InputID > id)||(InputID == 0)){
        cout << "Invalid Message ID" << endl;
        cout << "Enter Message ID(Negative number for menu):";
        cin >> InputID;
    }
  // cout << "Message vector size: " << messageList.size() << endl;
    
    InputID = InputID - 1; // subtract 1 since the numeration of messages in vector starts with 0.
    
        sbjt = "Re: " + messageList.at(InputID)->getSubject();
        cin.ignore();
        cout << "Enter Body: ";
        getline(cin, tempStr);
        while(tempStr !=  ""){
            body += tempStr + '\n';
            getline(cin, tempStr);
        }
    
        body = body.substr(0, body.size() - 1);
        cout << endl;
    
        Reply* NewReply = new Reply(currentUser->getUsername(), sbjt, body, sizeID);
        messageList.push_back(NewReply);
        messageList.at(InputID)->addChild(NewReply);  
}

void BBoard::display() const{
    if (messageList.size() == 0){
        cout << "Nothing to Display." << endl;
        cout << endl;
    }
    else {
        for (unsigned i = 0; i < messageList.size(); ++i){
            if(messageList.at(i)->isReply() == false){
                cout << "---------------------------------------------------------" << endl;
                (messageList.at(i))->print(0);
            }
        }
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
    }
}

 
