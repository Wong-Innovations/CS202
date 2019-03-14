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
    this->SetLLA( lla );
    std::cout << "Vehicle: Parametrized-ctor" << std::endl;
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle &obj)
{
    this->SetLLA( obj.getLLA() );
    std::cout << "Vehicle: Copy-ctor" << std::endl;
}

// Deconstructor
Vehicle::~Vehicle()
{
    std::cout << "Vehicle: Dtor" << std::endl;
}

// Setters
void Vehicle::SetLLA(const float *lla)
{
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}

// Getters
const float *Vehicle::getLLA() const { return this->m_lla; }

// Other Methods
std::ostream & operator<< (std::ostream & os, const Vehicle & vehicle)
{
    vehicle.serialize(os);

    return os;
}

void Vehicle::operator= (const Vehicle &other)
{
    std::cout << "Vehicle: Assignment" << std::endl;
    this->SetLLA(other.getLLA());
}

// Private methods
void Vehicle::serialize(std::ostream& os) const
{
    const float *ptr = this->getLLA();
    os << "Vehicle @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}