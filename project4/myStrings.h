#include <iostream>

#ifndef MYSTRINGS_H
#define MYSTRINGS_H

// Function name: myStringCat
// Pre-condition: destination and source are c-string pointers, destination has enough additional space to store source
// Post-condition: Returns a pointer to the destination array, destination array contains source appended to the end


// Function name: myStringCompare
// Pre-condition: str1 and str2 are c-string pointers
// Post-condition: Returns 0 when the C-strings match,
//  i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
//  returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
//  returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char* str1, const char* str2);

// Function name: myStringCopy
// Pre-condition: destination and source are c-string pointers, destination has enough space to store
// Post-condition: Returns a pointer to the destination array, destination array contains source string
char* myStringCopy(char* destination, const char* source);

// Function name: myStringLength
// Pre-condition: str is a c-string pointer
// Post-condition: Returns the required number of bytes to hold str
size_t myStringLength(const char* str);

// Function name: myAtoi
// Pre-condition: a is the ascii representation of a single diget integer
// Post-condition: returns the true int value
int myAtoi(char* str);

#endif