// // Author: Trishla Khandelwal
// // FileName: p4.cpp
// // Date: 03/01/2022
// // Revision History: version 1 used for P4
// // Platform : C++ using Visual Studio Code

// #include <stdlib.h>
// #include <iostream>
// #include <ostream>
// #include <memory>
// #include <limits>
// #include "duelingJP.cpp"
// using namespace std;

// // Function prototype
// void generateArray(int *list, int size);  //method to generate an array of random numbers
// void initializeJumpPrimeArray(jumpPrime ar[]); //method to add values in jumpPrime array
// void printMyJumpPrimeArray(jumpPrime ar[]); //method to print jumpPrime array
// void printMyDuelingJPArray(duelingJP &obj); //method to print duelingJP array

// //methods to test + on jumpPrime
// void testJumpPrimeAdditionOperators(jumpPrime ar[]);
// void addJumpPrimeTest(jumpPrime ar[]); 
// void addIntTest(jumpPrime ar[]);

// //methods to test == on jumpPrime
// void testJumpPrimeEqualEqual(jumpPrime ar[]);
// void EqualJumpPrimeTest(jumpPrime ar[]);
// void EqualIntTest(jumpPrime ar[]);

// //methods to test != on jumpPrime
// void testJumpPrimeNotEqual(jumpPrime ar[]);
// void NotEqualJumpPrimeTest(jumpPrime ar[]);
// void NotEqualIntTest(jumpPrime ar[]);

// //methods to test > on jumpPrime
// void testJumpPrimeGreaterThan(jumpPrime ar[]);
// void GreaterThanJumpPrimeTest(jumpPrime ar[]);
// void GreaterThanIntTest(jumpPrime ar[]);

// //methods to test < on jumpPrime
// void testJumpPrimeLessThan(jumpPrime ar[]);
// void LessThanJumpPrimeTest(jumpPrime ar[]);
// void LessThanIntTest(jumpPrime ar[]);

// //methods to test <= on jumpPrime
// void testJumpPrimeLessThanOrEqual(jumpPrime ar[]);
// void LessThanOrEqualJumpPrimeTest(jumpPrime ar[]);
// void LessThanOrEqualIntTest(jumpPrime ar[]);

// //methods to test >= on jumpPrime
// void testJumpPrimeGreaterThanOrEqual(jumpPrime ar[]);
// void GreaterThanOrEqualJumpPrimeTest(jumpPrime ar[]);
// void GreaterThanOrEqualIntTest(jumpPrime ar[]);

// //methods to test ++ on jumpPrime
// void testIncrement(jumpPrime ar[]);

// //methods to test += on jumpPrime
// void testJumpPrimeAdditionAssignment(jumpPrime ar[], jumpPrime ar2[]);

// //method to test + on duelingJP
// void testDuelingJPAddition(duelingJP &obj, duelingJP &obj2, jumpPrime &ar);

// //method to test == on duelingJP
// void equalDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test > on duelingJP
// void greaterThanDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test < on duelingJP
// void lessThanDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test != on duelingJP
// void notEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test >= on duelingJP
// void greaterThanOrEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test <= on duelingJP
// void lessThanOrEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2);

// //method to test += on duelingJP
// void testDuelingJPAdditionAssignment(duelingJP &obj, duelingJP &obj2, jumpPrime &ar);

// int const jumpPrimeTestSize = 10;
// int const duelingJPTestSize = 10;
// int const lowerBound = 99;
// int const upperBoundDiff = 1500;
// int const jumpPrimeLowerBound = 100;

// //declare variable
// const int MIN_SIZE = 2;
// const int MAX_SIZE = 10;
// const int MIN_INPUT = 200;
// const int max_input = 2000;

// int main()
// {
//     cout << "Creating an jumpPrime array of size: " << jumpPrimeTestSize << endl;
//     jumpPrime testJP1[jumpPrimeTestSize];
//     initializeJumpPrimeArray(testJP1);
//     printMyJumpPrimeArray(testJP1);
//     cout << endl
//          << "Testing different operators on jumpPrime" << endl
//          << endl;
//     testJumpPrimeAdditionOperators(testJP1);
//     testJumpPrimeEqualEqual(testJP1);
//     testJumpPrimeNotEqual(testJP1);
//     testJumpPrimeGreaterThan(testJP1);
//     testJumpPrimeLessThan(testJP1);
//     testJumpPrimeLessThanOrEqual(testJP1);
//     testJumpPrimeGreaterThanOrEqual(testJP1);
//     testJumpPrimeGreaterThanOrEqual(testJP1);
//     testIncrement(testJP1);

//     cout << "Creating another jumpPrime array of size: " << jumpPrimeTestSize << endl;
//     jumpPrime testJP3[jumpPrimeTestSize];
//     initializeJumpPrimeArray(testJP3);
//     printMyJumpPrimeArray(testJP3);
//     testJumpPrimeAdditionAssignment(testJP1, testJP3);

//     jumpPrime testJP2; //creating a jumpPrime object with only one default value(1009)
//     cout << "***** Creating duelingJP objects *****" << endl;
//     int *newArr = new int[duelingJPTestSize];
//     int *newArr2 = new int[duelingJPTestSize];

//     cout << "DuelingJP Array 1: ";
//     generateArray(newArr, duelingJPTestSize);
//     cout << endl;
//     cout << "DuelingJP Array 2: ";
//     generateArray(newArr2, duelingJPTestSize);
//     cout << endl
//          << endl;

//     duelingJP test = duelingJP(newArr, duelingJPTestSize);   // first array
//     duelingJP test2 = duelingJP(newArr2, duelingJPTestSize); // second array

//     cout<<"Testing different operators on duelingJP";
//     //testing overloading on duelingJP
//     testDuelingJPAddition(test, test2, testJP2);
//     equalDuelingJPTest(test, test2);
//     greaterThanDuelingJPTest(test, test2);
//     lessThanDuelingJPTest(test, test2);
//     notEqualDuelingJPTest(test, test2);
//     testDuelingJPAdditionAssignment(test, test2, testJP2);
//     return 0;
// }

// //method to add values in jumpPrime array
// void initializeJumpPrimeArray(jumpPrime ar[])
// {
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         ar[i] = rand() % upperBoundDiff + lowerBound;
//     }
// }

// //method to print jumpPrime array
// void printMyJumpPrimeArray(jumpPrime ar[])
// {
//     cout << "[ ";
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         cout << ar[i] << " ";
//     }
//     cout << "]" << endl;
// }

// //method to generate an array of random numbers
// void generateArray(int *list, int duelingJPTestSize)
// {
//     cout << "[";
//     for (int i = 0; i < duelingJPTestSize; i++)
//     {
//         list[i] = rand() % 200 + 2000; // using rand() for checking more collisions/inversions in a closer range
//         cout << " " << list[i] << " ";
//     }
//     cout << "]";
// }

// //method to display encapsulated integer list(givenList) of duelingJP objects
// void printMyDuelingJPArray(duelingJP &obj)
// {
//     cout << "[ ";
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         cout << obj.givenList[i] << " ";
//     }
//     cout << "]" << endl;
// }

// //test method for addition on jumpPrime
// void testJumpPrimeAdditionOperators(jumpPrime ar[])
// {
//     addJumpPrimeTest(ar);
//     addIntTest(ar);
//     cout << endl;
// }

// void addJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime+jumpPrime" << endl;
//     jumpPrime result[jumpPrimeTestSize];
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);

//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result[i] = ar[i] + test[i];
//         if (result[i] > test[i] && result[i] > ar[i])
//         {
//             count++;
//         }
//     }

//     cout << "(jumpPrime+jumpPrime) ";
//     printMyJumpPrimeArray(result);
//     cout << "Addition (jumpPrime+jumpPrime) passed " << count << "/" << jumpPrimeTestSize << " tests." << endl;
// }

// void addIntTest(jumpPrime ar[])
// {
//     cout << endl
//          << "Testing jumpPrime+int" << endl;
//     jumpPrime result1[jumpPrimeTestSize];

//     int addThisX = rand() % 100 + 1; // 1 - 100

//     int count1 = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result1[i] = ar[i] + addThisX;

//         if (result1[i] == ar[i] + addThisX)
//         {
//             count1++;
//         }
//     }

//     cout << "Random Integer : " << addThisX << endl;
//     cout << "jumpPrime+int ";
//     printMyJumpPrimeArray(result1);
//     cout << "Addition (jumpPrime+int) passed " << count1 << "/" << jumpPrimeTestSize << " tests." << endl;
// }

// //test method for equality check on jumpPrime
// void testJumpPrimeEqualEqual(jumpPrime ar[])
// {
//     EqualJumpPrimeTest(ar);
//     EqualIntTest(ar);
//     cout << endl;
// }
// void EqualJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime==jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] == test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << count << " values are equal in both jumpPrimes" << endl
//          << endl;
// }

// void EqualIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime==int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] == someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << "Random Integer equal to " << count << " values in array";
//     else
//         cout << "Random Integer not equal to any value in array";

//     cout << endl
//          << endl;
// }

// //test method for not equal operator testing on jumpPrime
// void testJumpPrimeNotEqual(jumpPrime ar[])
// {
//     NotEqualJumpPrimeTest(ar);
//     NotEqualIntTest(ar);
//     cout << endl;
// }
// void NotEqualJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime!=jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] != test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << count << " values are not equal in both jumpPrimes" << endl
//          << endl;
// }

// void NotEqualIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime!=int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] != someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << "Random Integer not equal to any value in array";
//     else
//         cout << "Random Integer equal to " << count << " values in array";

//     cout << endl
//          << endl;
// }

// void testJumpPrimeGreaterThan(jumpPrime ar[])
// {
//     GreaterThanJumpPrimeTest(ar);
//     GreaterThanIntTest(ar);
//     cout << endl;
// }
// void GreaterThanJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime>jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] > test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "First array has " << count << " values greater than second array" << endl
//          << endl;
// }

// void GreaterThanIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime>int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] > someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << count << " Values in array are greater than Random Integer";
//     else
//         cout << "No Value in array is greater than Random Integer";

//     cout << endl
//          << endl;
// }

// void testJumpPrimeLessThan(jumpPrime ar[])
// {
//     LessThanJumpPrimeTest(ar);
//     LessThanIntTest(ar);
//     cout << endl;
// }
// void LessThanJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime<jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] < test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "First array has " << count << " values less than second array" << endl
//          << endl;
// }

// void LessThanIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime<int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] < someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << count << " Values in array are less than Random Integer";
//     else
//         cout << "No Value in array is less than Random Integer";

//     cout << endl
//          << endl;
// }

// void testJumpPrimeLessThanOrEqual(jumpPrime ar[])
// {
//     LessThanOrEqualJumpPrimeTest(ar);
//     LessThanOrEqualIntTest(ar);
//     cout << endl;
// }
// void LessThanOrEqualJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime<=jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] <= test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "First array has " << count << " values less than or equal to second array" << endl
//          << endl;
// }

// void LessThanOrEqualIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime<=int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] <= someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << count << " Values in array are less than or equal to Random Integer";
//     else
//         cout << "No Value in array is less than or equal to Random Integer";

//     cout << endl
//          << endl;
// }

// void testJumpPrimeGreaterThanOrEqual(jumpPrime ar[])
// {
//     GreaterThanOrEqualJumpPrimeTest(ar);
//     GreaterThanOrEqualIntTest(ar);
//     cout << endl;
// }
// void GreaterThanOrEqualJumpPrimeTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime>=jumpPrime" << endl;
//     bool result;
//     jumpPrime test[jumpPrimeTestSize];
//     initializeJumpPrimeArray(test);
//     cout << "Second jumpPrime array ";
//     printMyJumpPrimeArray(test);
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] >= test[i];
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "First array has " << count << " values greater than or equal to second array" << endl
//          << endl;
// }

// void GreaterThanOrEqualIntTest(jumpPrime ar[])
// {
//     cout << "Testing jumpPrime>=int" << endl;
//     bool result;
//     int someNum = rand() % 100 + 1; // 1 - 100
//     int count = 0;

//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         result = ar[i] >= someNum;
//         if (result == true)
//         {
//             count++;
//         }
//     }
//     cout << "Random Integer : " << someNum << endl;
//     if (count > 0)
//         cout << count << " Values in array are greater than or equal to Random Integer";
//     else
//         cout << "No Value in array is greater than or equal to Random Integer";

//     cout << endl
//          << endl;
// }

// void testIncrement(jumpPrime ar[])
// {
//     cout << "Testing Prefix and Postfix increment on jumpPrime" << endl;
//     cout << "Original array";
//     printMyJumpPrimeArray(ar);
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         ++ar[i];
//     }
//     cout << " postfix ";
//     printMyJumpPrimeArray(ar);
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         ar[i]++;
//     }
//     cout << " prefix ";
//     printMyJumpPrimeArray(ar);
//     cout << endl
//          << endl;
// }

// //test method for addition assignment on jumpPrime
// void testJumpPrimeAdditionAssignment(jumpPrime ar[], jumpPrime ar2[])
// {
//     cout << "Testing jumpPrime+=jumpPrime" << endl;
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         ar[i] += ar2[i];
//     }
    
//     cout << "jumpPrime+=jumpPrime ";
//     printMyJumpPrimeArray(ar);
//     cout << endl;

//     cout << "Testing jumpPrime+=int" << endl;
//     int someNumber = rand() % 100 + 1; // 1 - 100;
//     for (int i = 0; i < jumpPrimeTestSize; i++)
//     {
//         ar[i] += someNumber;
//     }
//     cout << "Random Integer : " << someNumber << endl;
//     cout << "jumpPrime +=int ";
//     printMyJumpPrimeArray(ar);
//     cout << endl;
// }

// void testDuelingJPAddition(duelingJP &obj, duelingJP &obj2, jumpPrime &ar)
// {
//     cout << "Testing duelingJP+duelingJP" << endl;
//     duelingJP test3 = obj + obj2;
//     cout << "duelingJP+duelingJP ";
//     printMyDuelingJPArray(test3);
//     cout << endl;

//     cout << "Testing duelingJP+int" << endl;
//     int someNumber = rand() % 100 + 1; // 1 - 100;
//     duelingJP test4 = obj + someNumber;
//     cout << "Random Integer : " << someNumber << endl;
//     cout << "duelingJP array1 +int ";
//     printMyDuelingJPArray(test4);
//     cout << endl;

//     cout << "Testing duelingJP+jumpPrime" << endl;
//     duelingJP test5 = obj + ar;
//     cout << "JumpPrime encapsulated number is " << ar.getNum() << endl;
//     cout << " DuelingJP array1 ";
//     printMyDuelingJPArray(obj);
//     cout << "duelingJP+jumpPrime ";
//     printMyDuelingJPArray(test5);
//     cout << endl
//          << endl;
// }

// void equalDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP==duelingJP" << endl;
//     bool result;
//     result = obj == obj2;
//     if (result == true)
//         cout << " values are equal in both duelingJP arrays" << endl
//              << endl;
//     else
//         cout << " values are not equal in both duelingJP arrays" << endl
//              << endl;
//     cout << endl;
// }

// void greaterThanDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP>duelingJP" << endl;
//     bool result;
//     result = obj > obj2;
//     if (result == true)
//         cout << " duelingJP array 1 has more inversions and collisions than duelingJP array 2 " << endl
//              << endl;
//     else
//         cout << "duelingJP array 1 does not have more inversions and collisions than duelingJP array 2" << endl
//              << endl;
//     cout << endl;
// }

// void lessThanDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP<duelingJP" << endl;
//     bool result;
//     result = obj2 < obj;
//     if (result == true)
//         cout << " duelingJP array 2 has less inversions and collisions than duelingJP array 1 " << endl
//              << endl;
//     else
//         cout << "duelingJP array 2 does not have has less inversions and collisions than duelingJP array 1" << endl
//              << endl;
//     cout << endl;
// }

// void notEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP!=duelingJP" << endl;
//     bool result;
//     result = obj != obj2;
//     if (result == true)
//         cout << " values are not equal in both duelingJP arrays" << endl
//              << endl;
//     else
//         cout << " values are equal in both duelingJP arrays" << endl
//              << endl;
//     cout << endl;
// }

// void greaterThanOrEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP>=duelingJP" << endl;
//     bool result;
//     result = obj >= obj2;
//     if (result == true)
//         cout << " duelingJP array 1 has more oe equal inversions and collisions than duelingJP array 2 " << endl
//              << endl;
//     else
//         cout << "duelingJP array 1 does not have more or equal inversions and collisions than duelingJP array 2" << endl
//              << endl;
//     cout << endl;
// }

// void lessThanOrEqualDuelingJPTest(duelingJP &obj, duelingJP &obj2)
// {
//     cout << "Testing duelingJP<=duelingJP" << endl;
//     bool result;
//     result = obj2 <= obj;
//     if (result == true)
//         cout << " duelingJP array 2 has less or equal inversions and collisions than duelingJP array 1 " << endl
//              << endl;
//     else
//         cout << "duelingJP array 2 does not have has less or equal inversions and collisions than duelingJP array 1" << endl
//              << endl;
//     cout << endl;
// }

// void testDuelingJPAdditionAssignment(duelingJP &obj, duelingJP &obj2, jumpPrime &ar)
// {
//     cout << "Testing duelingJP+=duelingJP" << endl;
//     obj += obj2;
//     cout << "duelingJP+=duelingJP ";
//     printMyDuelingJPArray(obj);
//     cout << endl;

//     cout << "Testing duelingJP+=jumpPrime" << endl
//          << endl;
//     cout << " DuelingJP array1 ";
//     printMyDuelingJPArray(obj);
//     obj += ar;
//     cout << "JumpPrime encapsulated number is " << ar.getNum() << endl;
//     cout << "duelingJP+=jumpPrime ";
//     printMyDuelingJPArray(obj);
//     cout << endl;

//     cout << "Testing duelingJP+=int" << endl;
//     int someNumber = rand() % 100 + 1; // 1 - 100;
//     obj2 += someNumber;
//     cout << "Random Integer : " << someNumber << endl;
//     cout << "duelingJP array2 +=int ";
//     printMyDuelingJPArray(obj2);
//     cout << endl;
// }
