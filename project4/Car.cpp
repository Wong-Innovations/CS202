#include <iostream>
#include "Car.h"
#include "Sensor.h"
#include "myStrings.h"

// Default Constructor
Car::Car()
{
    setYear(0000);
    setMake("NO CAR");
    setModel("SELECTED");
    setBaseprice(0.00);
    setAvailability(0);
}

// Paramatized Constructor
Car::Car(int year, char *make, char *model, float price, bool available)
{
    setYear(year);
    setMake(make);
    setModel(model);
    setBaseprice(price);
    setAvailability(available);
}

// Copy Constructor
Car::Car(const Car & other) :
    m_year(other.m_year) ,
    m_baseprice(other.m_baseprice) ,
    m_available(other.m_available)
{
    setMake(other.m_make);
    setModel(other.m_model);
}

// Setters
void Car::setYear(const int year)
{
    m_year = year;
}

void Car::setMake(const char *make)
{
    myStringCopy(m_make, make);
}

void Car::setModel(const char *model)
{
    myStringCopy(m_model, model);
}

void Car::setBaseprice(float baseprice)
{
    m_baseprice = baseprice;
}

void Car::setAvailability(bool available)
{
    m_available = available;
}

void Car::setOwner(char* owner)
{
    myStringCopy(m_owner, owner);
}


// Getters
int     Car::getYear()
{
    return m_year;
}

char*   Car::getMake()
{
    return m_make;
}

char*   Car::getModel()
{
    return m_model;
}

Sensor* Car::getSensors()
{
    return m_sensors;
}

float   Car::getBaseprice()
{
    return m_baseprice;
}

float   Car::getFinalprice()
{
    return m_finalprice;
}

bool    Car::getAvailability()
{
    return m_available;
}

char*   Car::getOwner()
{
    return m_owner;
}


// Other methods
void Car::addLessee()
{

}

void Car::operator+ (char *type)
{
    m_sensors->setType(type);
}

float Car::estimateCost(const int num_of_days)
{

}

void Car::print()
{
    std::cout << getYear() << ' '
            << getMake() << ' '
            << getModel() << " , $"
            << getBaseprice()
            << " per day , Available: " << std::boolalpha
            << getAvailability() << "\n";
}

void Car::updatePrice(float price)
{

}
