#include <string>
#include <iostream>
using namespace std;

#include "User.h"

//User uu;

User::User(){
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::getUsername() const{
    return username;
}

bool User::check(const string &uname, const string &pass) const{
    if ((uname == getUsername()) && (pass == Get_password())){
        return true;
    }
    if (uname == ""){
        return false;
    }
    else {
        return false;
    }
    return false;
}
        
bool User::setPassword(const string &oldpass, const string &newpass){
    if ((Get_password() == oldpass) && (oldpass != "")){
        password = newpass;
        return true;
    }
//    if (Get_password() == newpass){
//        return true;
//    }
    else{
        return false;
    }
    return false;
}

string User::Get_password() const{
    return password;
}


// int main(){
//     string uname = "ali87";
//     string pass = "8422";
//     string oldpass = pass;
//     string newpass = "1111";
//     bool checking;
//     bool setpassing;
//     User uu = User(uname, pass);
//     checking = uu.check(uname, pass);
//     cout << "Check function: " <<  checking << endl;
//     setpassing = uu.setPassword(oldpass, newpass);
//     cout << "setPassword function: " << setpassing << endl;
//     cout << uu.Get_password() << endl;
//     cout << uu.getUsername() << endl;
//     return 0;
// }
