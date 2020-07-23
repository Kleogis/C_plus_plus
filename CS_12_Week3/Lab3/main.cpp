#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void displayResult(const string & , const Rational & , const Rational & , const Rational & ) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

//Default constractor:a constructor with no parameters (0/1)
Rational::Rational(){
    numerator = 0;
    denominator = 1;
}
//Constractor with one parameter (denominator set to 1)
Rational::Rational(int numer){
    numerator = numer;
    denominator = 1;
}
//Constractor with two parameters (numerator and denominator)
Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}

//Accessor function ADD
const Rational Rational::add(const Rational & B) const {
    //   (a/b) + (c/d) = (ad + bc) / (b*d)
    Rational R;
    R.numerator = (numerator * B.denominator + denominator * B.numerator);
    R.denominator = (denominator * B.denominator);
    return R;
}

//Accessor function SUBTRACT
const Rational Rational::subtract(const Rational & B) const {
    //  (a/b) - (c/d) = (ad - bc) / (b*d)
    Rational R;
    R.numerator = (numerator * B.denominator - denominator * B.numerator);
    R.denominator = (denominator * B.denominator);
    return R;
}
//Accessor function MULTIPLY
const Rational Rational::multiply(const Rational & B) const {
    // (a/b) * (c/d) = (ac) / (bd)
    Rational R;
    R.numerator = (numerator * B.numerator);
    R.denominator = (denominator * B.denominator);
    return R;
}
//Accessor function DIVIDE
const Rational Rational::divide(const Rational & B) const {
    //   (a/b) / (c/d) = (ad) / (cb)
    Rational R;
    R.numerator = (numerator * B.denominator);
    R.denominator = (B.numerator * denominator);
    return R;
}

//Display
void Rational::display() const{
    cout << numerator << " / " << denominator; 
}

// GCD algorithm
int Rational::gcd(int a, int b) const{
    int t;
    while (b != 0){
       t = b; 
       b = a % b; 
       a = t;
    }
    return a;
}

void Rational::simplify(){
    int common_div;
    common_div = gcd(numerator, denominator);
    numerator = numerator / common_div;
    denominator = denominator / common_div;
    return;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
 
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();

   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {

      result = A.add(B);

      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   }
     else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

