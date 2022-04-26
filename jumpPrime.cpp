// Author: Trishla Khandelwal
// FileName: jumpPrime.cpp
// Date: 03/01/2022
// Revision History: version 3 used for P4
// Platform : C++ using Visual Studio Code

#include "jumpPrime.h"
using namespace std;

// This class encapsulates a positive integer, which must be at least 3-digits long
// Clients can request the prime numbers above(up) or below(down) to the encapsulated positive integer
// encapsulated number will ‘jump’ after a limited number of queries,
// that will be the number determined by the distance between the two closest prime numbers

// Class Invariant: the encapsulated a positive integer must be at least 4-digits long,
// otherwise a default value of 1000 will be used

// Interface Invariant:
// up()
//returns closest prime number that is higher than the encapsulated number and -1 if inactive
//
// down()
//returns closest prime number that is lower than the encapsulated number and -1 if inactive
//
// revive()
// Revives a jumpPrime object. An attempt to revive an active jumpPrime object causes that object to be permanently deactivated.
// Returns true on a successful revive attempt
//
// reset()
// Resets an ACTIVE jumpPrime object, resetting it's queries count and number of jumps made.
// Returns true when successfully resetted
//
// isActive()
// returns true if object is active

//getNum() getter method which returns num

// operator+(const jumpPrime& rhs)      //adds encapsulated no.s of two jumpPrimes
// operator+(int val)                   //adds a random integer and encapsulated no. of a jumpPrime
// operator++()                         //increments encapsulated no. of jumpPrime by 1 (prefix)
// operator++(int)                      //increments encapsulated no. of jumpPrime by 1 (postfix)
// operator >= (const jumpPrime& rhs)   //checks how many no.s in jumpPrime array 1 are greater than or equal to no.s in jumpPrime array 2
// operator >= (int val)                //checks how many no.s in jumpPrime array 1 are greater than or equal to the random integer
// operator < (const jumpPrime& rhs)    //checks how many no.s in jumpPrime array 1 are less than no.s in jumpPrime array 2
// operator < (int val)                 //checks how many no.s in jumpPrime array 1 are less than the random integer
// operator == (const jumpPrime& rhs)   //checks how many no.s in jumpPrime array 1 are equal to no.s in jumpPrime array 2
// operator == (int val)                //checks how many no.s in jumpPrime array 1 are equal to random integer
// operator != (const jumpPrime& rhs)   //checks how many no.s in jumpPrime array 1 are not equal to no.s in jumpPrime array 2
// operator != (int val)                //checks how many no.s in jumpPrime array 1 are not equal to  random integer
// operator > (const jumpPrime& rhs)    //checks how many no.s in jumpPrime array 1 are greater than no.s in jumpPrime array 2
// operator > (int val)                 //checks how many no.s in jumpPrime array 1 are greater than random integer
// operator <= (const jumpPrime& rhs)   //checks how many no.s in jumpPrime array 1 are less than or equal to no.s in jumpPrime array 2
// operator <= (int val)                //checks how many no.s in jumpPrime array 1 are less than or equal to random integer
// operator += (int rhs)                //addition assignment operator performs jumpPrime += int
// operator += (const jumpPrime& rhs)   //addition assignment operator jumpPrime += jumpPrime
// std::ostream& operator<<(std::ostream& os, const jumpPrime& jp) //overloaded stream operator

// States: Active- a call to up or down will return a valid prime number
// Inactive- a call to up or down will return -1
// The jumpPrime object may automatically become inactive after the no. of jumps exceeds MAX_JUMPS
// Dead- The object can no longer be revived
// The client may revive a jumpPrime object, if it is inactive
// The client may reset a jumpPrime object that is active, which will reset the count of queries to 0
// An attempt to revive an active jumpPrime object causes that object to be permanently dead

// Default Constructor
// Initializating num with 1009 which is already a prime number
// Maximum number of jumps allowed is 5
// Max number of queries before jump required is the difference between the upperPrime and lowerPrime number
jumpPrime::jumpPrime()
{

    num = 1009;
    qCount = 0;
    active = true;
    jCount = 0;
    deactivated = false;
    maxJumps = 5;
    lowerPrime = calculateLowerPrime();
    upperPrime = calculateHigherPrime();
    maxQueries = upperPrime - lowerPrime;
}

// Parameterized constructor
// Maximum number of jumps allowed is 5
// max number of queries before jump required is the difference between the upperPrime and lowerPrime number
jumpPrime::jumpPrime(int value)
{
    if (value > 99)
        num = value;
    else
    {
        num = 1000;
    }
    qCount = 0;
    active = true;
    jCount = 0;
    deactivated = false;
    maxJumps = 5;
    lowerPrime = calculateLowerPrime();
    upperPrime = calculateHigherPrime();
    maxQueries = upperPrime - lowerPrime;
}

// If object is active, return next prime number higher than value
// If object is not active, return -1
// postCondition: if qCount reaches maxQueries, value is jumped to a value higher than the next higher prime number
int jumpPrime::up()
{
    if (active)
    {
        qCount++;
        if (qCount > maxQueries)
        {
            jump();
        }
        return upperPrime;
    }
    else
    {
        return -1;
    }
}

// If object is active, return next prime number lower than value
// If object is not active, return -1
// postCondition: if qCount reaches maxQueries, value is jumped to a value lower than the next lower prime number
int jumpPrime::down()
{
    if (active)
    {
        qCount++;
        if (qCount > maxQueries)
        {
            jump();
        }
        return lowerPrime;
    }
    else
    {
        return -1;
    }
}

//Postconditions: object can be permanently deactivated if you revive an active jumpPrime object
// Returns true on a successful revive attempt
bool jumpPrime::revive()
{
    if (!active && !deactivated)
        active = true;

    else
    {
        deactivated = true;
        active = false;
    }

    return active;
}

//Postconditions: Resets an ACTIVE jumpPrime object
// Returns true when successfully resetted
bool jumpPrime::reset()
{
    if (!active || deactivated)
    {
        return false;
    }

    qCount = 0;
    jCount = 0;

    return true;
}

// Returns true if object is active, otherwise false
bool jumpPrime::isActive()
{
    return active;
}

bool jumpPrime::isPrime(int n)
{
    // This is checked so that we can skip middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 ||
            n % (i + 2) == 0)
            return false;

    return true;
}
// Calculates the next higher Prime number
int jumpPrime::calculateHigherPrime()
{
    int prime = num;
    bool found = false;

    while (!found)
    {
        prime++;

        if (isPrime(prime))
            found = true;
    }

    upperPrime = prime;
    return upperPrime;
}
// Calculates the next lower Prime number
int jumpPrime::calculateLowerPrime()
{
    int prime = num;
    bool found = false;

    while (!found)
    {
        prime--;

        if (isPrime(prime))
            found = true;
    }

    lowerPrime = prime;
    return lowerPrime;
}

// The number will ‘jump’ after a limited number of queries i.e the difference between the two closest upper and lower prime numbers
bool jumpPrime::jump()
{
    if (jCount == maxJumps)
    {
        jCount = 0;
        active = false;
        return false;
    }

    qCount = 0;
    calculateLowerPrime();
    calculateHigherPrime();
    maxQueries = (upperPrime - lowerPrime);
    jCount++;

    return true;
}

//getter method to return value of encapsulated number
int jumpPrime::getNum() const
{
    return this->num;
}

//OVERLOADING METHODS//

//description: used for addition of jumpPrime+jumpPrime
jumpPrime jumpPrime::operator+(const jumpPrime &rhs)
{
    return jumpPrime(this->num + rhs.num);
}

//description: used for addition of jumpPrime+int
jumpPrime jumpPrime::operator+(int val)
{
    return jumpPrime(this->num + val);
}

//description: used for postfix increment on jumpPrime
void jumpPrime::operator++()
{
    this->num = this->num++;
}

//description: used for prefix increment on jumpPrime
void jumpPrime::operator++(int)
{
    this->num = ++this->num;
}

//description: >= operator overloaded
bool jumpPrime::operator>=(const jumpPrime &rhs)
{
    return num >= rhs.num;
}
//description: >= operator overloaded
bool jumpPrime::operator>=(int val)
{
    return num >= val;
}
//description: < operator overloaded
bool jumpPrime::operator<(const jumpPrime &rhs)
{
    return num < rhs.num;
}
//description: < operator overloaded
bool jumpPrime::operator<(int val)
{
    return num < val;
}
//description: == operator overloaded
bool jumpPrime::operator==(const jumpPrime &rhs)
{
    return num == rhs.num;
}
//description: == operator overloaded
bool jumpPrime::operator==(int val)
{
    return num == val;
}
//description: != operator overloaded
bool jumpPrime::operator!=(const jumpPrime &rhs)
{
    return !(num == rhs.num);
}
//description: != operator overloaded
bool jumpPrime::operator!=(int val)
{
    return !(num == val);
}
//description: > operator overloaded
bool jumpPrime::operator>(const jumpPrime &rhs)
{
    return num > rhs.num;
}
//description: > operator overloaded
bool jumpPrime::operator>(int val)
{
    return num > val;
}
//description: <= operator overloaded
bool jumpPrime::operator<=(const jumpPrime &rhs)
{
    return num <= rhs.num;
}
//description: <= operator overloaded
bool jumpPrime::operator<=(int val)
{
    return num <= val;
}
//description: += operator overloaded
void jumpPrime::operator+=(int rhs)
{
    this->num = this->num + rhs;
}
//description: += operator overloaded
void jumpPrime::operator+=(const jumpPrime &rhs)
{
    this->num = this->num + rhs.num;
}

//overloaded stream operator
std::ostream &operator<<(std::ostream &os, const jumpPrime &jp)
{
    os << jp.num;
    return os;
}

// Implementation Invariant:
// When jumpPrime 'jumps' the new number is direction is determined by the closest prime number, upPrime or downPrime
// The number encapsulated is generated randomly between the range of 1000-9999
// Permanently deactivated objects will act forever inactive.
// USER CAN MANIPULATE JUMPPRIME OBJECTS USING VARIOUS OPERATOR OVERLOADING METHODS