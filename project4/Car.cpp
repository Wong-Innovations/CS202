#include <iostream>
#include "Car.h"
#include "Sensor.h"

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
Car::Car()
{
    Car::setYear(0000);
    Car::setMake("NO CAR");
    Car::setModel("SELECTED");
    Car::setPrice(0.00);
    Car::setAvailability(0);
}

// Paramatized Constructor
Car::Car(int year, char *make, char *model, float price, bool available)
{
    Car::setYear(year);
    Car::setMake(make);
    Car::setModel(model);
    Car::setPrice(price);
    Car::setAvailability(available);
}

// Copy Constructor
Car::Car(const Car &carAddr)
{
    Car::setYear(carAddr.getYear());
    Car::setMake(carAddr.getMake());
    Car::setModel(carAddr.getModel());
    Car::setPrice(carAddr.getBaseprice());
    Car::setAvailability(carAddr.getAvailability());
}