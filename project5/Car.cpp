#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

// Default Constructor
Car::Car():
    m_throttle(0)
{
    std::cout << "Car #" << this->getVin() << ": Default-ctor" << std::endl;
}

// Paramatized Constructor
Car::Car(const char* plates, const int throttle):
    m_throttle(throttle)
{
    this->setPlates(plates);
    std::cout << "Car #" << this->getVin() << ": Parametized-ctor" << std::endl;
}

// Copy Constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{

    std::cout << "Car #" << this->getVin() << ": Copy-ctor" << std::endl;
}

// Deconstructor
Car::~Car()
{
    std::cout << "Car #" << this->getVin() << ": Dtor" << std::endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}

void Car::setPlates(const char *plates)
{
    stpcpy(m_plates, plates);
}

// Getters
const int Car::getThrottle() const { return m_throttle; }
const char *Car::getPlates() const { return m_plates; }

// Other Methods
void Car::move(const float *lla)
{
    std::cout << "Car #" << this->getVin()
    << ": DRIVE to destination, with throttle @ 75 "
    << std::endl;

    this->drive( 75 );
    this->setLLA( lla );
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}
