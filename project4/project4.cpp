/*********************************************************
 * Name: proj4.c                                         *
 * Purpose: Calculate best valued rental car.            *
 * Author: Dylan Wong                                    *
 * Class: CS 202.1001                                    *
 *********************************************************/
#include <iostream>
#include <fstream>
#include "Agency.h"

// Function name: myAtoi
// Pre-condition: a is the ascii representation of a single diget integer
// Post-condition: returns the true int value
int myAtoi(char* str);

// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

// Function name: readFileWithPointers
// Pre-condition: agencies is an array of Agency objects
// Post-condition: Reads in agency data from a user inputed file
void readFileWithPointers(Agency* agency);

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
                readFileWithPointers(&agency);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                std::cout << "Invalid Option!\n";
        }
    } while(selection != 6);

    return 0;
}

int myAtoi(char* str) 
{
    int val = 0;

    for (char* strRef = str; *str != '\0'; strRef++)
    {
        val = val*10 + *str - '0';
    }

    return val;
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

void readFileWithPointers(Agency* agency)
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
        char temp_name[256];
        int temp_zip;
        Car temp_inventory[5];

        source_file >> temp_name;
        source_file >> temp_zip;

        Car* carsRef = temp_inventory;
        for(int j = 0; j < 5; j++)
        {
            int temp_year;
            char temp_make[256], temp_model[256];
            float temp_price;
            bool temp_available;

            source_file >> temp_year;
            source_file >> temp_make;
            source_file >> temp_model;
            source_file >> temp_price;
            source_file >> temp_available;

            carsRef->setYear(temp_year);
            carsRef->setMake(temp_make);
            carsRef->setModel(temp_model);
            carsRef->setPrice(temp_price);
            carsRef->setAvailability(temp_available);

            carsRef++;
        }
        
        Agency *agencyRef = agency;
        agencyRef->setName(temp_name);
        agencyRef->setZip(temp_zip);
        agencyRef->setInventory(temp_inventory);
    }

    return;
}