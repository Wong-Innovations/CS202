#include "RentalCar.h"

void myStringCopy(char* des, char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}

// Default Constructor
RentalCar::RentalCar()
{
    RentalCar::setYear(0000);
    RentalCar::setMake("NO CAR");
    RentalCar::setModel("SELECTED");
    RentalCar::setPrice(0.00);
    RentalCar::setAvailability(0);
}

// Paramatized Constructor
RentalCar::RentalCar(int year, char *make, char *model, float price, bool available)
{
    RentalCar::setYear(year);
    RentalCar::setMake(make);
    RentalCar::setModel(model);
    RentalCar::setPrice(price);
    RentalCar::setAvailability(available);
}

// Setters
void RentalCar::setYear(int year)
{
    m_year = year;
}

void RentalCar::setMake(char *make)
{
    myStringCopy(m_make, make);
}

void RentalCar::setModel(char *model)
{
    myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price)
{
    m_price = price;
}

void RentalCar::setAvailability(bool available)
{
    m_available = available;
}

// Getters
int RentalCar::getYear()
{
    return m_year;
}

char* RentalCar::getMake()
{
    return m_make;
}

char* RentalCar::getModel()
{
    return m_model;
}

float RentalCar::getPrice()
{
    return m_price;
}

bool RentalCar::getAvailability()
{
    return m_available;
}