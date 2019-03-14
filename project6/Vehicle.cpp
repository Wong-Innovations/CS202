#include <iostream>
#include <cstring>
#include "Vehicle.h"

// Default Constructor
Vehicle::Vehicle()
{
    std::cout << "Vehicle: Default-ctor" << std::endl;
}

// Paramatized Constructor
Vehicle::Vehicle(const float *lla)
{
    this->SetLLA(0, lla[0]);
    this->SetLLA(1, lla[1]);
    this->SetLLA(2, lla[2]);
    std::cout << "Vehicle: Parametrized-ctor" << std::endl;
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle &obj)
{
    this->SetLLA(0, obj.getLLA(0));
    this->SetLLA(1, obj.getLLA(0));
    this->SetLLA(2, obj.getLLA(0));
    std::cout << "Vehicle: Copy-ctor" << std::endl;
}

// Deconstructor
Vehicle::~Vehicle()
{
    std::cout << "Vehicle: Dtor" << std::endl;
}

// Setters
void Vehicle::SetLLA(const int index, const float val)
{
    m_lla[index] = val;
}

// Getters
const float Vehicle::getLLA(const int index) const { return this->m_lla[index]; }

// Other Methods
std::ostream & operator<< (std::ostream & os, const Vehicle & vehicle)
{
    vehicle.serialize(os);

    return os;
}

void Vehicle::operator= (const Vehicle &other)
{
    std::cout << "Vehicle: Assignment" << std::endl;
    this->SetLLA(0, other.getLLA(0));
    this->SetLLA(1, other.getLLA(1));
    this->SetLLA(2, other.getLLA(2));
}

// Private methods
void Vehicle::serialize(std::ostream& os) const
{
    os << "Vehicle @ [" << this->getLLA(0) << ", " << this->getLLA(1) << ", " << this->getLLA(2) << ']';
}