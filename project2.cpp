/*********************************************************
 * Name: proj2.c                                         *
 * Purpose: Calculate best valued rental car.            *
 * Author: Dylan Wong                                    *
 * Class: CS 202.1001                                    *
 *********************************************************/
#include <iostream>
#include <fstream>

struct RentalCar {
    int year;
    char make[10];
    char model[10];
    float price;
    bool available;
};

// Function name: myStringLength
// Pre-condition: str is a c-string pointer
// Post-condition: Returns the required number of bytes to hold str
size_t myStringLength(const char*str);

// Function name: myStringCompare
// Pre-condition: str1 and str2 are c-string pointers
// Post-condition: 
int myStringCompare(const char*str1, const char*str2);
char *myStringCopy(char*destination, const char* source);
char *myStringCat(char*destination, const char* source);