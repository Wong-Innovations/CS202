#include <iostream>
#include <fstream>
#include "Agency.h"
#include "Car.h"
#include "myStrings.h"

// Default Constructor
Agency::Agency()
{
    m_zipcode = 00000;
    myStringCopy(m_name, "NO-NAME");
}

// Paramatized Constructor
Agency::Agency(char* name, int zipcode, Car* inventory) :
    m_zipcode(zipcode)
{
    myStringCopy(m_name, name);
}

// Setters
void Agency::setName(char* name)
{
    myStringCopy(m_name, name);
    std::cout << "Setting name:" << name << std::endl;
}

void Agency::setZip(int zipcode)
{
    m_zipcode = zipcode;
    std::cout << "Setting zip:" << zipcode << std::endl;
}

void Agency::setInventory(Car* inventory)
{
    for(int i = 0; i < 5; i++, inventory++)
    {
        this->m_inventory[i].setYear(inventory->getYear());
        this->m_inventory[i].setMake(inventory->getMake());
        this->m_inventory[i].setModel(inventory->getModel());
        this->m_inventory[i].setBaseprice(inventory->getBaseprice());
        this->m_inventory[i].setAvailability(inventory->getAvailability());
    }
}

// Getters
char* Agency::getName()
{
    return m_name;
}

int Agency::getZip()
{
    return m_zipcode;
}

Car* Agency::getInventory()
{
    return m_inventory;
}


// Overload Operators
Car& Agency::operator[](const int index)
{
    return m_inventory[index];
}

// Other Methods
void Agency::printAllData()
{
    std::cout << this->getName() << ' '
    << this->getZip() << '\n';

    Car *carsRef = getInventory();

    for(int j = 0; j < 5; j++)
    {
        carsRef->print();
        carsRef++;
    }
    std::cout << '\n';
}

void Agency::readAllData(std::ifstream & infile)
{
    char temp_name[256];
    int temp_zip;

    infile >> temp_name;
    infile >> temp_zip;

    this->setName(temp_name);
    this->setZip(temp_zip);

    for(int j = 0; j < 5; j++)
    {
        int temp_year;
        char temp_make[256], temp_model[256];
        float temp_price;
        bool temp_available;

        infile >> temp_year;
        infile >> temp_make;
        infile >> temp_model;
        infile >> temp_price;
        infile >> temp_available;

        m_inventory[j].setYear(temp_year);
        m_inventory[j].setMake(temp_make);
        m_inventory[j].setModel(temp_model);
        m_inventory[j].setBaseprice(temp_price);
        m_inventory[j].setAvailability(temp_available);

    }
}