#include <iostream>
#include "Agency.h"
#include "Car.h"
#include "myStrings.h"

// Default Constructor
Agency::Agency()
{

}

// Paramatized Constructor
Agency::Agency(char* name, int zipcode, Car* inventory)
{

}

// Setters
void Agency::setName(char* name)
{
    char* m_nameRef = this->m_name;
    for(; *name != '\0'; m_nameRef++, name++)
    {
        *m_nameRef = *name;
    }
}
void Agency::setZip(int zipcode)
{
    this->m_zipcode = zipcode;
}

void Agency::setInventory(Car* inventory)
{

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
void Agency::operator[](const int index)
{

}