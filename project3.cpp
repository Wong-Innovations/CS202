/*********************************************************
 * Name: proj3.c                                         *
 * Purpose: Calculate best valued rental car.            *
 * Author: Dylan Wong                                    *
 * Class: CS 202.1001                                    *
 *********************************************************/
#include <iostream>
#include <fstream>
#include "RentalCar.h"

struct RentalAgency
{
    char name[];
    int zipcode;
    RentalCar inventory[5];
};


// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

int main(void)
{
    RentalAgency agencies[3];
    char source_file_name[255], destination_file_name[255];
    int selection;

    do {
        displayMenu();
        std::cin >> selection;



        switch (selection)
        {
            case 1:
                std::cout << "Source filename: ";
                std::cin >> source_file_name;
                readFile(agencies, source_file_name);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    } while(selection != 6);

    return 0;
}

void displayMenu()
{
    std::cout << '\n'
    << "1. Read car data.\n"
    << "2. Print car data.\n"
    << "3. Save car data.\n"
    << "4. Sort cars (by price).\n"
    << "5. Compare rental prices.\n"
    << "6. Exit the program.\n"
    << "Enter your selection: ";

    return;
}

void readFile(RentalAgency* agencies, const char* source_file_name)
{
    std::ifstream source_file;
    source_file.open(source_file_name);
    if(!source_file)
    {
        std::cout << "File cannot be read.\n";
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            source_file >> agencies[i].name;
            source_file >> agencies[i].zipcode;
            for (int j = 0; j < 5; j++)
            {
                source_file >> agencies[i].inventory[j].year;
                source_file >> agencies[i].inventory[j].make;
                source_file >> agencies[i].inventory[j].model;
                source_file >> agencies[i].inventory[j].price;
                source_file >> agencies[i].inventory[j].available;
            }
        }
    }
    
    return;
}