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

// 
void displayMenu();

// 
void readFile(RentalCar* carsArray, const char* source_file_name);

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
int myStringCompare(const char* str1, const char* str2);

// Function name: myStringCopy
// Pre-condition: destination and source are c-string pointers, destination has enough space to store
// Post-condition: Returns a pointer to the destination array, destination array contains source string
char *myStringCopy(char* destination, const char* source);

// Function name: myStringCat
// Pre-condition: destination and source are c-string pointers, destination has enough additional space to store source
// Post-condition: Returns a pointer to the destination array, destination array contains source appended to the end
char *myStringCat(char* destination, const char* source);

//
void printCarData(RentalCar* carsArray);

int main(void)
{
    RentalCar carsArray[5];
    char source_file_name[255], destination_file_name[255];
    int selection;

    std::cout << "Enter source file name: ";
    std::cin >> source_file_name;
    std::cout << "Enter destination file name: ";
    std::cin >> destination_file_name;

    std::ofstream destination_file;
    destination_file.open(destination_file_name);

    do
    {
        displayMenu();
        std::cin >> selection;

        switch (selection)
        {
            case 1:
                std::cout << "Source filename: ";
                std::cin >> source_file_name;
                readFile(carsArray, source_file_name);
                break;
            case 2:
                printCarData(carsArray);
                break;
            case 3:
            
                break;
            case 4:
            
                break;
            case 5:
            
                break;
            case 6:
            
                break;
            case 7: selection = 0;
        }
    } while(selection);

    return 0;
}

void displayMenu()
{
    std::cout << "1. Read car data.\n";
    std::cout << "2. Print car data.\n";
    std::cout << "3. Save car data.\n";
    std::cout << "4. Sort cars (by price).\n";
    std::cout << "5. Compare rental prices.\n";
    std::cout << "6. Calculate a car's rental price.\n";
    std::cout << "7. Exit the program.\n";
    std::cout << "Enter your selection: ";

    return;
}

void readFile(RentalCar* carsArray, const char* source_file_name)
{
    std::ifstream source_file;
    source_file.open(source_file_name);
    if(!source_file)
    {
        std::cout << "File cannot be read.\n";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            source_file >> carsArray[i].year;
            source_file >> carsArray[i].make;
            source_file >> carsArray[i].model;
            source_file >> carsArray[i].price;
            source_file >> carsArray[i].available;
        }
    }
    
    return;
}

void printCarData(RentalCar* carsArray)
{

}