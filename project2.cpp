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
// Post-condition: Returns 0 when the C-strings match,
//  i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
//  returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
//  returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char*str1, const char*str2);

// Function name: myStringCopy
// Pre-condition: destination and source are c-string pointers, destination has enough space to store
// Post-condition: Returns a pointer to the destination array, destination array contains source string
char *myStringCopy(char*destination, const char* source);

// Function name: myStringCat
// Pre-condition: destination and source are c-string pointers, destination has enough additional space to store source
// Post-condition: Returns a pointer to the destination array, destination array contains source appended to the end
char *myStringCat(char*destination, const char* source);

int main(void)
{
    char source_file_name[255], destination_file_name[255];

    std::cout << "Enter source file name: ";
    std::cin >> source_file_name;
    std::cout << "Enter destination file name: ";
    std::cin >> destination_file_name;

    std::ifstream source_file;
    source_file.open(source_file_name);

    std::ofstream destination_file;
    destination_file.open(destination_file_name);

    



    return 0;
}
