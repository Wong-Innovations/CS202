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
    int zipcode[5];
    RentalCar inventory[5];
};

// Function name: myAtoi
// Pre-condition: a is the ascii representation of a single diget integer
// Post-condition: returns the true int value
int myAtoi(char a);

// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

// Function name: findMostExpensive
// Pre-condition: agencies is an array of RentalAgency objects
// Post-condition: Prints the most expensive car to the console
void findMostExpensive(RentalAgency* agencies);

// Function name: giveQuote
// Pre-condition: agencies is an array of RentalAgency objects
// Post-condition: quotes the user for the price of renting a given car for x days.
void giveQuote(RentalAgency* agencies);

// Function name: printAgenciesWithPointers
// Pre-condition: agencies is an array of RentalAgency objects
// Post-condition: Prints the agencies names, zipcodes, and inventory to the terminal
void printAgenciesWithPointers(RentalAgency* agencies);

// Function name: readFileWithPointers
// Pre-condition: agencies is an array of RentalAgency objects
// Post-condition: Reads in agency data from a user inputed file
void readFileWithPointers(RentalAgency* agencies);

// Function name: saveAvailableCars
// Pre-condition: agencies is an array of RentalAgency objects
// Post-condition: Saves the available cars to a user-named output file
void saveAvailableCars(RentalAgency* agencies);

int main(void)
{
    RentalAgency agencies[3];
    int selection;

    do {
        displayMenu();
        std::cin >> selection;



        switch (selection)
        {
            case 1:
                readFileWithPointers(agencies);
                break;
            case 2:
                printAgenciesWithPointers(agencies);
                break;
            case 3:
                giveQuote(agencies);
                break;
            case 4:
                findMostExpensive(agencies);
                break;
            case 5:
                saveAvailableCars(agencies);
                break;
        }
    } while(selection != 6);

    return 0;
}

int myAtoi(char a) 
{
    return a - '0';
} 

void displayMenu()
{
    std::cout
    << "1. Read car data.\n"
    << "2. Print rental agency data.\n"
    << "3. Estimate rental cost.\n"
    << "4. Find the most expensive car.\n"
    << "5. Compare rental prices.\n"
    << "6. Exit the program.\n"
    << "Enter your selection: ";

    return;
}

void findMostExpensive(RentalAgency* agencies)
{
    int mostExpensiveAgency = 0, mostExpensiveCar = 0;
    float mostExpensivePrice = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            float next = agencies[i].inventory[j].getPrice();
            if (next > mostExpensivePrice)
            {
                mostExpensivePrice = next;
                mostExpensiveAgency = i;
                mostExpensiveCar = j;
            }
        }
    }
    std::cout << "The most expensive car is the: "
    << agencies[mostExpensiveAgency].inventory[mostExpensiveCar].getYear() << ' '
    << agencies[mostExpensiveAgency].inventory[mostExpensiveCar].getMake() << ' '
    << agencies[mostExpensiveAgency].inventory[mostExpensiveCar].getModel() << ' '
    << "at the " << agencies[mostExpensiveAgency].name << " rental agency.\n\n";

    return;
}

void giveQuote(RentalAgency* agencies)
{
    int agencySelection, carSelection, num_of_days;

    std::cout << "Select an agency to rent from (0-2): ";
    std::cin >> agencySelection;

    std::cout << "Which car would you like to rent (0-4): ";
    std::cin >> carSelection;

    std::cout << "How many days would you like to rent that car for: ";
    std::cin >> num_of_days;

    std::cout << "The "
    << agencies[agencySelection].inventory[carSelection].getYear() << ' '
    << agencies[agencySelection].inventory[carSelection].getMake() << ' '
    << agencies[agencySelection].inventory[carSelection].getModel() << ' '
    << "will cost: $"
    << agencies[agencySelection].inventory[carSelection].estimateCost(num_of_days)
    << " for " << num_of_days << " days.\n\n";
}

void printAgenciesWithPointers(RentalAgency* agencies)
{
    RentalAgency *agenciesRef = agencies;

    for(int i = 0; i < 3; i++)
    {
        std::cout << agenciesRef->name << ' ';
        int *zipRef = agenciesRef->zipcode;

        for(int j = 0; j < 5; j++)
        {
            std::cout << *zipRef;
            zipRef++;
        }
        
        std::cout << '\n';

        RentalCar *carsRef = agenciesRef->inventory;

        for(int j = 0; j < 5; j++)
        {
            carsRef->printCar();
            carsRef++;
        }
        agenciesRef++;
    }
    std::cout << '\n';

    return;
}

void readFileWithPointers(RentalAgency* agencies)
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
        RentalAgency *agenciesRef = agencies;

        for(int i = 0; i < 3; i++)
        {   
            char temp_zip[6];

            source_file >> agenciesRef->name;
            source_file >> temp_zip;

            int *zipRef = agenciesRef->zipcode;

            for(char *temp_zipRef = temp_zip; *temp_zipRef != '\0'; temp_zipRef++)
            {
                *zipRef = myAtoi(*temp_zipRef);
                zipRef++;
            }

            RentalCar *carsRef = agenciesRef->inventory;

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

            agenciesRef++;
        }

    }
    

    return;
}

void saveAvailableCars(RentalAgency* agencies)
{
    char destination_file_name[256];

    std::cout << "Enter destination file name: ";
    std::cin >> destination_file_name;

    std::ofstream destination_file;
    destination_file.open(destination_file_name);

    RentalAgency* agenciesRef = agencies;

    for(int i = 0; i < 3; i++)
    {
        RentalCar* carsRef = agenciesRef->inventory;
        for(int j = 0; j < 5; j++)
        {
            if (carsRef->getAvailability())
            {
                destination_file << carsRef->getYear() << ' '
                << carsRef->getMake() << ' '
                << carsRef->getModel() << " , $"
                << carsRef->getPrice() << " per day , Available: "
                << std::boolalpha << carsRef->getAvailability()
                << '\n';
            }
            carsRef++;
        }
        agenciesRef++;
    }
}