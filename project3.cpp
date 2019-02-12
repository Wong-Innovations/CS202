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
    char name[256];
    int zipcode;
    RentalCar inventory[5];
};


// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

void printAgencies(RentalAgency* agencies);

void readFile(RentalAgency* agencies, const char* source_file_name);

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
                std::cout << '\n';
                readFile(agencies, source_file_name);
                break;
            case 2:
                printAgencies(agencies);
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
    std::cout
    << "1. Read car data.\n"
    << "2. Print car data.\n"
    << "3. Save car data.\n"
    << "4. Sort cars (by price).\n"
    << "5. Compare rental prices.\n"
    << "6. Exit the program.\n"
    << "Enter your selection: ";

    return;
}

void printAgencies(RentalAgency* agencies)
{
    for(int i = 0; i < 3; i++)
    {
        std::cout << agencies[i].name
        << ' ' << agencies[i].zipcode << '\n';

        for(int j = 0; j < 5; j++)
        {
            std::cout << agencies[i].inventory[j].getYear() << ' '
            << agencies[i].inventory[j].getMake() << ' '
            << agencies[i].inventory[j].getModel() << " , $"
            << agencies[i].inventory[j].getPrice()
            << " per day , Available: " << std::boolalpha
            << agencies[i].inventory[j].getAvailability() << "\n";
        }
    }
    std::cout << '\n';

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
                int temp_year;
                char temp_make[10], temp_model[10];
                float temp_price;
                bool temp_available;

                source_file >> temp_year;
                source_file >> temp_make;
                source_file >> temp_model;
                source_file >> temp_price;
                source_file >> temp_available;

                agencies[i].inventory[j] = RentalCar(temp_year, temp_make, temp_model, temp_price, temp_available);

                agencies[i].inventory[j].RentalCar::setYear(temp_year);
                agencies[i].inventory[j].RentalCar::setMake(temp_make);
                agencies[i].inventory[j].RentalCar::setModel(temp_model);
                agencies[i].inventory[j].RentalCar::setPrice(temp_price);
                agencies[i].inventory[j].RentalCar::setAvailability(temp_available);
            }
        }
    }
    
    return;
}