// Author: Trishla Khandelwal
// FileName: duelingJP.cpp
// Date: 03/01/2022
// Revision History: version 3 used for P4
// Platform : C++ using Visual Studio Code

//This class encapsulates some number of distinct jumpPrime objects;
// the cardinality of jumpPrime subobjects varies across duelingJP objects.
// Client can initialize the array size and startNum to create an object.
// Client can also call queries a number of ‘collisions’ and ‘inversions’.

//Class Invariant: duelingJP object encapsulates some number of distinct jumpPrime objects
//at least 2 objects in the jumpPrimeArray, otherwise set default array size as 5
//This class should support deep copying and move semantic
// Comparison operators will compare the inversions and collisions statistics as that is the main functionality of duelingJP
// Since it compares the inversions and collisions statistics, equality operators can only be supported of comparison of duelingJP

// Interface invariant:

// getCollisions()
// returns numbers of collisions from the jumpPrime objects

// getInversions()
// returns numbers of inversions from the jumpPrime objects

//operator+(const duelingJP &rhs)            //adds encapsulated integer array elements of two duelingJP objects
//operator+(const jumpPrime& rhs)  //encapsulated integer array elements of a duelingJP object with the encapsulated num of jumpPrime object
//operator+(int val)               //adds random integer to every element of encapsulated integer array of a duelingJP object
//operator == (duelingJP& rhs)               //checks if no. of inversions and collisions of duelingJP array1 is equal to that of duelingJP array 2
//operator > (duelingJP& rhs)                //checks if no. of inversions and collisions of duelingJP array1 is greater than that of duelingJP array 2
//operator < (duelingJP& rhs)                //checks if no. of inversions and collisions of duelingJP array1 is less than that of duelingJP array 2
//operator != (duelingJP& rhs)               //checks if no. of inversions and collisions of duelingJP array1 is not equal to that of duelingJP array 2
//operator >= (duelingJP& rhs)                //checks if no. of inversions and collisions of duelingJP array1 is greater than or equal to that of duelingJP array 2
//operator <= (duelingJP& rhs)                //checks if no. of inversions and collisions of duelingJP array1 is less than or equal to that of duelingJP array 2
//operator+= (const duelingJP &rhs);     //Addition assignment operator duelingJP += duelingJP
//operator+= (const jumpPrime &rhs);      //Addition assignment operator duelingJP += jumpPrime
//operator+= (in val);                    //Addition assignment operator duelingJP += int

#include "duelingJP.h"
using namespace std;

//constructor
duelingJP::duelingJP(int list[], int len)
{
    if (list == NULL || len == 0)
    {
        active = false;
        inversions = -1;
        collisions = -1;
        JPList = nullptr;
    }
    else
    {
        if (len < 2)
            size = 5;
        else
            size = len;
        givenList = new int[len];
        givenList = list;
        this->JPList = new jumpPrime *[size];
        initializeJP();
        findCollisions();
        findInversions();
    }
}

// copy constructor/deep copy
duelingJP::duelingJP(const duelingJP &src)
{
    copy(src);
}

//used for copy constructor
void duelingJP::copy(const duelingJP &src)
{
    size = src.size;
    JPList = new jumpPrime *[size];
    for (int i = 0; i < size; i++)
    {
        JPList[i] = src.JPList[i];
    }
}

// move constructor
duelingJP::duelingJP(duelingJP &&src)
{
    JPList = src.JPList;
    src.JPList = nullptr;

    size = src.size;
    src.size = 0;
}

// destructor
duelingJP::~duelingJP()
{
    deallocateHeaps();
}

//assignment overload
duelingJP &duelingJP::operator=(const duelingJP &rhs)
{
    if (this == &rhs)
        return *this;
    copy(rhs);
    deallocateHeaps();
    return *this;
}

// description: used for Move assignment as it transfers ownership of rhs heaps
duelingJP &duelingJP::operator=(duelingJP &&rhs)
{
    if (&rhs == this)
        return *this;

    JPList = rhs.JPList;
    rhs.JPList = nullptr;
    deallocateHeaps();
    return *this;
}

//description: method to find collisions
//postConditions: Updates the collisions counter when collision is found
void duelingJP::findCollisions()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (JPList[i]->up() == JPList[j]->up())
            {
                collisions++;
            }
        }
    }
}

//description: method to find inversions
//postConditions: Updates the inversions counter when collision is found
void duelingJP::findInversions()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (JPList[i]->up() == JPList[j]->down())
            {
                inversions++;
            }
        }
    }
}

//description: returns the final value of the collisions counter i.e. no. of collisions
int duelingJP::getCollisions()
{
    return collisions;
}

//description: returns the final value of the inversions counter i.e. no. of inversions
int duelingJP::getInversions()
{
    return inversions;
}

//description: method to deallocate heap memory
void duelingJP::deallocateHeaps()
{
    delete[] JPList;
    delete[] givenList;
}

//method to store values into JPList
void duelingJP::initializeJP()
{
    for (int i = 0; i < size; i++)
    {
        JPList[i] = new jumpPrime(givenList[i]);
    }
}

//getter method to return size of encapsulated array
int duelingJP::getSize() const
{
    return this->size;
}

// overloading operators methods for duelingJP

//description: used for addition of duelingJP+duelingJP
duelingJP duelingJP::operator+(const duelingJP &rhs)
{
    int newSize = (this->size > rhs.size) ? this->size : rhs.size;
    int *newArray = new int[newSize];
    duelingJP newDuelingJP(newArray, newSize);
    for (int i = 0; i < rhs.size; i++)
    {
        newDuelingJP.givenList[i] = this->givenList[i] + rhs.givenList[i];
    }
    return newDuelingJP;
}

//description: used for addition of duelingJP+int
duelingJP duelingJP::operator+(int val)
{
    int newSize = this->size;
    int *newArray = new int[newSize];
    duelingJP newDuelingJP(newArray, newSize);
    for (int i = 0; i < newSize; i++)
    {
        newDuelingJP.givenList[i] = this->givenList[i] + val;
    }
    return newDuelingJP;
}

//description: used for addition of duelingJP+jumpPrime
duelingJP duelingJP::operator+(const jumpPrime &rhs)
{
    int newSize = this->size;
    int *newArray = new int[newSize];
    duelingJP newDuelingJP(newArray, newSize);
    for (int i = 0; i < newSize; i++)
    {
        newDuelingJP.givenList[i] = this->givenList[i] + rhs.getNum();
    }
    return newDuelingJP;
}

//description: used to check if duelingJP==duelingJP
bool duelingJP::operator==(duelingJP &rhs)
{
    return this->getInversions() == rhs.getInversions() && this->getCollisions() == rhs.getCollisions();
}
//description: used to check if duelingJP>duelingJP
bool duelingJP::operator>(duelingJP &rhs)
{
    return this->getInversions() > rhs.getInversions() && this->getCollisions() > rhs.getCollisions();
}
//description: used to check if duelingJP<duelingJP
bool duelingJP::operator<(duelingJP &rhs)
{
    return this->getInversions() < rhs.getInversions() && this->getCollisions() < rhs.getCollisions();
}
//description: used to check if duelingJP!=duelingJP
bool duelingJP::operator!=(duelingJP &rhs)
{
    return this->getInversions() != rhs.getInversions() && this->getCollisions() != rhs.getCollisions();
}
//description: used to check if duelingJP>=duelingJP
bool duelingJP::operator>=(duelingJP &rhs)
{
    return this->getInversions() >= rhs.getInversions() && this->getCollisions() >= rhs.getCollisions();
}
//description: used to check if duelingJP<=duelingJP
bool duelingJP::operator<=(duelingJP &rhs)
{
    return this->getInversions() <= rhs.getInversions() && this->getCollisions() <= rhs.getCollisions();
}

//description: used for addition of duelingJP+=duelingJP
void duelingJP::operator+=(const duelingJP &rhs)
{
    for (int i = 0; i < rhs.size; i++)
    {
        this->givenList[i] = this->givenList[i] + rhs.givenList[i];
    }
}

//description: used for addition of duelingJP+= jumpPrime
void duelingJP::operator+=(const jumpPrime &rhs)
{
    for (int i = 0; i < this->size; i++)
    {
        this->givenList[i] = this->givenList[i] + rhs.getNum();
    }
}

//description: used for addition of duelingJP+=int
void duelingJP::operator+=(int val)
{
    for (int i = 0; i < this->size; i++)
    {
        this->givenList[i] = this->givenList[i] + val;
    }
}

// Implementation Invariant
// duelingJP is an object that encapsulates a number of jumpPrime objects.
// it takes in an array of integers and size of that array to initialize the jumpPrime objects
// can also take in an array of jumpPrime objects and the size of that array
// Users can request the number of "collisions" and "inversions" the jumpPrime objects have created
// USER CAN MANIPULATE DUELINGJP OBJECTS USING VARIOUS OPERATOR OVERLOADING METHODS