// Author: Trishla Khandelwal
// FileName: jumpPrime.h
// Date: 03/01/2022
// Revision History: version 3 used for P4
// Platform : C++ using Visual Studio Code

#include <iostream>
using namespace std;
class jumpPrime
{
public:
    // methods
    jumpPrime();          //constructor
    jumpPrime(int value); //parameterized constructor
    int up();
    int down();
    bool revive();
    bool reset();
    bool isActive();
    int calculateHigherPrime();
    int calculateLowerPrime();
    int getNum() const;

    //OVERLOADING METHODS//
    jumpPrime operator+(const jumpPrime &rhs); // Addition operator jumpPrime + jumpPrime
    jumpPrime operator+(int val);              // Addition operator jumpPrime + int

    bool operator==(const jumpPrime &rhs); // equality operator jumpPrime == jumpPrime
    bool operator==(int val);              // == operator jumpPrime == int

    bool operator!=(const jumpPrime &rhs); // not-equal-to operator jumpPrime != jumpPrime
    bool operator!=(int val);              // != jumpPrime != int

    bool operator>(const jumpPrime &rhs); // greater than jumpPrime > jumpPrime
    bool operator>(int val);              // jumpPrime > int

    bool operator<=(const jumpPrime &rhs); // less than/equal to operator jumpPrime <= jumpPrime
    bool operator<=(int val);              // jumpPrime <= int

    bool operator<(const jumpPrime &rhs); // less than jumpPrime < jumpPrime
    bool operator<(int val);              // jumpPrime < int

    bool operator>=(const jumpPrime &rhs); // greater than/equal to jumpPrime >= jumpPrime
    bool operator>=(int val);              // jumpPrime >= int

    void operator++();   // Postfix increment operator
    void operator++(int); // Prefix increment operator

    void operator+=(int rhs);              // addition assignment operator jumpPrime += int
    void operator+=(const jumpPrime &rhs); // addition assignment operator jumpPrime += jumpPrime

    friend std::ostream &operator<<(std::ostream &os, const jumpPrime &jp);

private:
    // data members
    int num;          // encapsulated number
    int qCount;       // count of queries
    bool active;      // bool to track state of object(Active/Inactive)
    bool deactivated; // bool to track permanent deactivation
    int jCount;       // count of jumps
    int maxQueries;   // max number of queries before jump required
    int maxJumps;     // maximum number of jumps allowed
    int upperPrime;   // the return values for up
    int lowerPrime;   // the return values for down

    // methods
    bool isPrime(int n); //method to check whether a number is prime or not
    bool jump();         //method to jump
};