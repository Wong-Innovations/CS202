#include "Car.h"

#ifndef AGENCY_H
#define AGENCY_H

class Agency
{
public:
    // Default Constructor
    Agency();

    // Paramatized Constructor
    Agency(char* name, int zipcode, Car* inventory);

    // Setters
    void setName(char* name);
    void setZip(int zipcode);
    void setInventory(Car* inventory);

    // Getters
    char* getName();
    int getZip();
    Car* getInventory();

    // Overload Operators
    void operator[] (const int);

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
};

#endif