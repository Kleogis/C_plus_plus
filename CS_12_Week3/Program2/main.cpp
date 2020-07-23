#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date(){
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){
    monthName = name(m);
    day = d;
    month = m;
    year = y;
    if (m == 0 && d == 0){
        month = 1;
        day = 1;
        cout << "Invalid date values: Date corrected to 1/1/" << y << "." << endl;      
    }
    else if (m > 12 && d == 0){
        month = 12;
        day = 1;
        cout << "Invalid date values: Date corrected to 12/1/" << y << "." << endl;      
    }
    else if (d == 0){
        month = m;
        day = 1;
        cout << "Invalid date values: Date corrected to " << month << "/1/" << y << "." << endl;      
    }
    else if ((m == 1) && (d <= daysPerMonth(m,y))){
        month = m;
        day = d;
    }
    else if ((m == 1) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 1/31/" << y << "." << endl;
    }
    else if ((m == 2) && (isLeap(y) == true) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 2) && (isLeap(y) == true) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 2/29/" << y << "." << endl;
    }
    else if ((m == 2) && (isLeap(y) == false) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 2/28/" << y << "." << endl;
    }
    else if ((m == 3) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 3) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 3/31/" << y << "." << endl;
    } 
    else if ((m == 4) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 4) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 4/30/" << y << "." << endl;
    } 
    else if ((m == 5) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 5) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 5/31/" << y << "." << endl;
    } 
    else if ((m == 6) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 6) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 6/30/" << y << "." << endl;
    } 
    else if ((m == 7) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 7) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 7/31/" << y << "." << endl;
    }
    else if ((m == 8) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 8) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 8/31/" << y << "." << endl;
    }
    else if ((m == 9) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 9) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 9/30/" << y << "." << endl;
    }
    else if ((m == 10) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 10) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 10/31/" << y << "." << endl;
    }
    else if ((m == 11) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 11) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 11/30/" << y << "." << endl;
    }
    else if ((m == 12) && (d <= daysPerMonth(m,y))){
        day = d;
        month = m;
    }
    else if ((m == 12) && (d > daysPerMonth(m,y))){
        day = daysPerMonth(m,y);
        month = m;
        cout << "Invalid date values: Date corrected to 12/31/" << y << "." << endl;
    }
    else if ((m > 12) && (d <= daysPerMonth(12,y))){
        day = d;
        month = 12;
        cout << "Invalid date values: Date corrected to 12/" << d << "/" << y << "." << endl;
    }
    else if ((m > 12) && (d > daysPerMonth(12,y))){
        day = daysPerMonth(12,y);
        month = 12;
        cout << "Invalid date values: Date corrected to 12/31/" << y << "." << endl; 
    }
    else if ((m > 12) && (d == 0)){
        day = 1;
        month = 12;
        cout << "Invalid date values: Date corrected to 12/1/" << y << "." << endl; 
    }
    else if ((m == 0) && (d <= daysPerMonth(1,y))){
        day = d;
        month = 1;
        cout << "Invalid date values: Date corrected to 1/" << d << "/" << y << "." << endl; 
    }
    else if ((m == 0) && (d > daysPerMonth(1,y))){
        day = daysPerMonth(1,y);
        month = 1;
        cout << "Invalid date values: Date corrected to 1/" << daysPerMonth(1,y) << "/" << y << "." << endl; 
    }
}

Date::Date(const string &mn, unsigned d, unsigned y){
    month = number(mn);
    year = y;
//    if (d == 0){
//        day = 1;
//        cout << "Invalid date values: Date corrected to " << number(mn) << "/1/" << y << "." << endl;      
//    }
    if ((mn == "January" || mn == "january") && (d == 0)){
        day = 1;
        monthName = "January";
        cout << "Invalid date values: Date corrected to 1/1/" << y << "." << endl;
    }
    else if ((mn == "January" || mn == "january") && (d <= daysPerMonth(month,y))){
        monthName = "January";
        day = d;
    }
    else if ((mn == "January" || mn == "january") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "January";
        cout << "Invalid date values: Date corrected to 1/31/" << y << "." << endl;
    }
    else if ((mn == "February" || mn == "february") && (isLeap(y) == true) && (d == 0)){
        day = 1;
        monthName = "February";
        cout << "Invalid date values: Date corrected to 2/1/" << y << "." << endl;
    }
    else if ((mn == "February" || mn == "february") && (isLeap(y) == true) && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "February";
    }
    else if ((mn == "February" || mn == "february") && (isLeap(y) == true) && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "February";
        cout << "Invalid date values: Date corrected to 2/29/" << y << "." << endl;
    }
    else if ((mn == "February" || mn == "february") && (isLeap(y) == false) && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "February";
        cout << "Invalid date values: Date corrected to 2/28/" << y << "." << endl;
    }
    else if ((mn == "March" || mn == "march") && (d == 0)){
        day = 1;
        monthName = "March";
        cout << "Invalid date values: Date corrected to 3/1/" << y << "." << endl;
    }
    else if ((mn == "March" || mn == "march") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "March";
    }
    else if ((mn == "March" || mn == "march") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "March";
        cout << "Invalid date values: Date corrected to 3/31/" << y << "." << endl;
    } 
    else if ((mn == "April" || mn == "april") && (d ==0)){
        day = 1;
        monthName = "April";
        cout << "Invalid date values: Date corrected to 4/1/" << y << "." << endl;
    }
    else if ((mn == "April" || mn == "april") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "April";
    }
    else if ((mn == "April" || mn == "april") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "April";
        cout << "Invalid date values: Date corrected to 4/30/" << y << "." << endl;
    } 
    else if ((mn == "May" || mn == "may") && (d == 0)){
        day = 1;
        monthName = "May";
        cout << "Invalid date values: Date corrected to 5/1/" << y << "." << endl;
    }
    else if ((mn == "May" || mn == "may") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "May";
    }
    else if ((mn == "May" || mn == "may") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "May";
        cout << "Invalid date values: Date corrected to 5/31/" << y << "." << endl;
    }
    else if ((mn == "June" || mn == "june") && (d == 0)){
        day = 1;
        monthName = "June";
        cout << "Invalid date values: Date corrected to 6/1/" << y << "." << endl;
    } 
    else if ((mn == "June" || mn == "june") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "June";
    }
    else if ((mn == "June" || mn == "june") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "June";
        cout << "Invalid date values: Date corrected to 6/30/" << y << "." << endl;
    }
    else if ((mn == "July" || mn == "july") && (d == 0)){
        day = 1;
        monthName = "July";
        cout << "Invalid date values: Date corrected to 7/1/" << y << "." << endl;
    }
    else if ((mn == "July" || mn == "july") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "July";
    }
    else if ((mn == "July" || mn == "july") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "July";
        cout << "Invalid date values: Date corrected to 7/31/" << y << "." << endl;
    }
    else if ((mn == "August" || mn == "august") && (d == 0)){
        day = 1;
        monthName = "August";
        cout << "Invalid date values: Date corrected to 8/1/" << y << "." << endl;
    }
    else if ((mn == "August" || mn == "august") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "August";
    }
    else if ((mn == "August" || mn == "august") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "August";
        cout << "Invalid date values: Date corrected to 8/31/" << y << "." << endl;
    }
    else if ((mn == "September" || mn == "september") && (d == 0)){
        day = 1;
        monthName = "September";
        cout << "Invalid date values: Date corrected to 9/1/" << y << "." << endl;
    }
    else if ((mn == "September" || mn == "september") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "September";
    }
    else if ((mn == "September" || mn == "september") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "September";
        cout << "Invalid date values: Date corrected to 9/30/" << y << "." << endl;
    }
    else if ((mn == "October" || mn == "october") && (d == 0)){
        day = 1;
        monthName = "October";
        cout << "Invalid date values: Date corrected to 10/1/" << y << "." << endl;
    }
    else if ((mn == "October" || mn == "october") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "October";
    }
    else if ((mn == "October" || mn == "october") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "October";
        cout << "Invalid date values: Date corrected to 10/31/" << y << "." << endl;
    }
    else if ((mn == "November" || mn == "november") && (d == 0)){
        day = 1;
        monthName = "November";
        cout << "Invalid date values: Date corrected to 11/1/" << y << "." << endl;
    }
    else if ((mn == "November" || mn == "november") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "November";
    }
    else if ((mn == "November" || mn == "november") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "November";
        cout << "Invalid date values: Date corrected to 11/30/" << y << "." << endl;
    }
    else if ((mn == "December" || mn == "december") && (d == 0)){
        day = 1;
        monthName = "December";
        cout << "Invalid date values: Date corrected to 12/1/" << y << "." << endl;
    }
    else if ((mn == "December" || mn == "december") && (d <= daysPerMonth(month,y))){
        day = d;
        monthName = "December";
    }
    else if ((mn == "December" || mn == "december") && (d > daysPerMonth(month,y))){
        day = daysPerMonth(month,y);
        monthName = "December";
        cout << "Invalid date values: Date corrected to 12/31/" << y << "." << endl;
    }
    else{
        day = 1;
        monthName = "January";
        year = 2000;
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl; 
    }
}

void Date::printNumeric() const{
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const{
    cout << monthName << " " << day << ", " << year; 
}

bool Date::isLeap(unsigned y) const{
    if(y % 100 != 0 && y % 4 == 0){
        return true;
    }
    else if(y % 100 == 0 && y % 400 == 0){
        return true;
    }
    else{
        return false;
    }       
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    if (m == 1 || m == 0){
        return 31;
    }
    else if (m == 2 && isLeap(y) == true){
        return 29;
    }
    else if (m == 2 && isLeap(y) == false){
        return 28;
    }
    else if (m == 3){
        return 31;
    }
    else if (m == 4){
        return 30;
    }
    else if (m == 5){
        return 31;
    }
    else if (m == 6){
        return 30;
    }
    else if (m == 7){
        return 31;
    }
    else if (m == 8){
        return 31;
    }
    else if (m == 9){
        return 30;
    }
    else if (m == 10){
        return 31;
    }
    else if (m == 11){
        return 30;
    }
    else if (m == 12 || m > 12){
        return 31;
    }
    return 1;
}

string Date::name(unsigned m) const{
    if (m == 1){
        return "January";
    }
    else if (m == 2){
        return "February";
    }
    else if (m == 3){
        return "March";
    }
    else if (m == 4){
        return "April";
    }
    else if (m == 5){
        return "May";
    }
    else if (m == 6){
        return "June";
    }
    else if (m == 7){
        return "July";
    }
    else if (m == 8){
        return "August";
    }
    else if (m == 9){
        return "September";
    }
    else if (m == 10){
        return "October";
    }
    else if (m == 11){
        return "November";
    }
    else if (m == 12){
        return "December";
    }
    else if (m == 0){
        return "January";
    }
    else if (m > 12){
        return "December";
    }
    return "Unknown";
}

unsigned Date::number(const string &mn) const{
    if (mn == "January" || mn =="january"){
        return 1;
    }
    else if (mn == "February" || mn == "february"){
        return 2;
    }
    else if (mn == "March" || mn == "march"){
        return 3;
    }
    else if (mn == "April" || mn == "april"){
        return 4;
    }
    else if (mn == "May" || mn == "may"){
        return 5;
    }
    else if (mn == "June" || mn == "june"){
        return 6;
    }
    else if (mn == "July" || mn == "july"){
        return 7;
    }
    else if (mn == "August" || mn == "august"){
        return 8;
    }
    else if (mn == "September" || mn == "september"){
        return 9;
    }
    else if (mn == "October" || mn == "october"){
        return 10;
    }
    else if (mn == "November" || mn == "november"){
        return 11;
    }
    else if (mn == "December" || mn == "december"){
        return 12;
    }
    else{
        return 1;
    }
//    return 100;
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
