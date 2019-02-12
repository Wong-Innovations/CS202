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

void findMostExpensive(RentalAgency* agencies);

void giveQuote(RentalAgency* agencies);

void printAgencies(RentalAgency* agencies);

void readFile(RentalAgency* agencies);

int main(void)
{
    RentalAgency agencies[3];
    char destination_file_name[255];
    int selection;

    do {
        displayMenu();
        std::cin >> selection;



        switch (selection)
        {
            case 1:
                readFile(agencies);
                break;
            case 2:
                printAgencies(agencies);
                break;
            case 3:
                giveQuote(agencies);
                break;
            case 4:
                findMostExpensive(agencies);
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

void readFile(RentalAgency* agencies)
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
            }
        }
    }
    
    return;
}