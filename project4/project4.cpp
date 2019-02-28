/*********************************************************
 * Name: proj4.c                                         *
 * Purpose: Store data about car rental agencies.        *
 * Author: Dylan Wong                                    *
 * Class: CS 202.1001                                    *
 *********************************************************/
#include <iostream>
#include <fstream>
#include "Agency.h"

// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

// Function name: readFileWithPointers
// Pre-condition: agencies is an array of Agency objects
// Post-condition: Reads in agency data from a user inputed file
void readFileWithPointers(Agency agency);

int main(void)
{
    Agency agency;
    int selection;

    do {
        displayMenu();
        std::cin >> selection;



        switch (selection)
        {
            case 1:
                readFileWithPointers(agency);
                break;
            case 2:
                agency.printAllData();
                break;
            case 3:
                
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid Option!\n";
        }
    } while(selection != 5);

    return 0;
}

void displayMenu()
{
    std::cout
    << "1. Read rental agency data.\n"
    << "2. Print rental agency data.\n"
    << "3. Calculate number of sensors.\n"
    << "4. Find the most expensive car.\n"
    << "5. Exit the program.\n"
    << "Enter your selection: ";

    return;
}

void readFileWithPointers(Agency agency)
{
    char source_file_name[255];
    std::cout << "Source filename: ";
    std::cin >> source_file_name;
    std::cout << '\n';
    std::ifstream source_file;
    source_file.open(source_file_name);
    if(!source_file)
    {
        std::cout << "File cannot be read.\n";
    }
    else
    {
        agency.readAllData(source_file);
    }

    return;
}
