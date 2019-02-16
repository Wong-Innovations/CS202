#include "Car.h"

#ifndef AGENCY_H
#define AGENCY_H

class Agency
{
public:
    // Default Constructor
    Agency();

    // Paramatized Constructor
    Agency(char* m_name, int m_zipcode, Car* m_inventory);

    // Setters
    void setName(char* name);
    void setZip(int zipcode);
    void setInventory(Car* inventory);

    // Getters
    char* getName();
    int getZip();
    Car* getInventory();

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
};

#endif