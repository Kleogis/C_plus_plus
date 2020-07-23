#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Message.h"
#include "Reply.h"
#include "Topic.h"
using namespace std;

Message::Message(){
}

Message::Message(const string &athr,  const string &sbjct, const string &bd, unsigned id){
    author = athr;
    subject = sbjct;
    body = bd;
    this-> id = id;
}
Message::~Message(){
}
void Message::display() const {
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
    cout << "---------------------------------------------------------" << endl;
}

unsigned Message::getID() const{
    return this->id;
}

void Message::addChild(Message *child){
    childList.push_back(child);
}

 const string & Message::getSubject() const{
     return subject;
 }



string Message::toFormattedString() const{
   ostringstream IDString;
   ostringstream intString;
	string reply;
    IDString << id;
    reply = ":id: " + IDString.str()  + '\n';
    reply = reply + ":subject: " + subject +'\n';
    reply = reply + ":from: " + author + '\n';
    if (childList.size() != 0){
        reply = reply + ":children: ";
        for (unsigned i = 0; i<childList.size();i++){
            intString.str(string() );
            intString << childList.at(i)->getID();

            reply += intString.str();
            if (i < childList.size()-1){
             reply +=" ";
            }
            else {
                reply += '\n';
            }


            }
        }


    reply = reply +":body: " + body + '\n' + "<end>\n";
    return reply;
}


void Message::print(unsigned indentation) const{
        spacing(indentation);

        cout << "Message #" << id << ": " << subject << endl;
        spacing(indentation);
        cout << "from " << author << ":";
        cout <<' ';
        for (unsigned j = 0; j < body.size(); j++) {

            cout << body.at(j);

            if ( j == body.size() - 1){
            }

            else if (body.at(j) == '\n'){
                spacing(indentation);
            }
        }

        for (unsigned i = 0; i < childList.size(); i++) {
            cout << '\n' << '\n';
            childList.at(i)->print(indentation + 1);
        }

}


void Message::spacing(unsigned totalSpc) const{
    for (unsigned i = 0; i< totalSpc; i++){
        cout <<"  ";
    }
}