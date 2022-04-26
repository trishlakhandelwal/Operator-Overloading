// Author: Trishla Khandelwal
// Date: 03/01/2022
// FileName: duelingJP.h
// Revision History: version 3 used for P4
// Platform : C++ using Visual Studio Code

#include "jumpPrime.cpp"
class duelingJP
{
public:
    int *givenList;                  // array passed in to initialize jumpPrime objects
    duelingJP(int list[], int len);  //constructor with default values
    duelingJP(const duelingJP &src); //copy constructor
    duelingJP(duelingJP &&src);      //move constructor

    ~duelingJP();                               //destructor
    duelingJP &operator=(const duelingJP &rhs); //overload assignment
    duelingJP &operator=(duelingJP &&rhs);      //move assignment

    int getCollisions(); //method to return no. of collisions
    int getInversions(); //method to return no. of inversions
    int getSize() const; //getter method ehich returns size

    //overloading methods
    duelingJP operator+(const duelingJP &rhs); //addition duelingJP+duelingJP
    duelingJP operator+(const jumpPrime &rhs); //dueling+jumpPrime
    duelingJP operator+(int val);              //addition duelingJP+int

    bool operator==(duelingJP &rhs);       //overloaded == checks if duelingJP==duelingJP
    bool operator>(duelingJP &rhs);        //overloaded > checks if duelingJP>duelingJP
    bool operator<(duelingJP &rhs);        //overloaded < checks if duelingJP<duelingJP
    bool operator!=(duelingJP &rhs);       //overloaded == checks if duelingJP!=duelingJP
    bool operator>=(duelingJP &rhs);       //overloaded >= checks if duelingJP>=duelingJP
    bool operator<=(duelingJP &rhs);       //overloaded <= checks if duelingJP<=duelingJP
    void operator+=(const duelingJP &rhs); //Addition assignment operator duelingJP += duelingJP
    void operator+=(const jumpPrime &rhs); //Addition assignment operator duelingJP += jumpPrime
    void operator+=(int val);              //Addition assignment operator duelingJP += int

private:
    bool active = true;
    int size; //size of encapsulated integer array
    int collisions = 0; //counter variable to track no. of collisions
    int inversions = 0; //counter variable to track no. of inversions
    jumpPrime **JPList; // list of jumpPrime objects

    void findCollisions();              //method to calculate collisions
    void findInversions();              //method to calculate inversions
    void deallocateHeaps();             //method used for destructor
    void initializeJP();                //method to initialize jumpPrime objects
    void copy(const duelingJP &source); //method used for copy constructor
};