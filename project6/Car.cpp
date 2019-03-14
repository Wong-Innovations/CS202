#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

// Default Constructor
Car::Car():
    m_throttle(0)
{
    std::cout << "Car: Default-ctor" << std::endl;
}

// Paramatized Constructor
Car::Car(const float* lla):
    Vehicle(lla)
{
    std::cout << "Car: Parametized-ctor" << std::endl;
}

// Copy Constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{
    std::cout << "Car: Copy-ctor" << std::endl;
}

// Deconstructor
Car::~Car()
{
    std::cout << "Car: Dtor" << std::endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}

// Getters
const int Car::getThrottle() const { return m_throttle; }

// Other Methods
void Car::Move(const float *lla)
{
    std::cout << "Car: DRIVE to destination, with throttle @ 75 " << std::endl;

    this->drive( 75 );
    this->SetLLA(0, lla[0]);
    this->SetLLA(1, lla[1]);
    this->SetLLA(2, lla[2]);
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}

void Car::operator=(const Car &other)
{
    std::cout << "Car: Assignment" << std::endl;
    this->SetLLA(0, other.getLLA(0));
    this->SetLLA(1, other.getLLA(1));
    this->SetLLA(2, other.getLLA(2));
    this->setThrottle(other.getThrottle());
}

void Car::serialize(std::ostream& os) const
{
    std::cout << "Car: Throttle: " << this->getThrottle()
    << " @ ["
    << this->getLLA(0) << ", "
    << this->getLLA(1) << ", "
    << this->getLLA(2) << ']';
}