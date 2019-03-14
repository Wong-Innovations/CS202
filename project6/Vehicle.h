#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>

class Vehicle
{
public:
    // Default Constructor
    Vehicle();
    
    // Paramatized Constructor
    Vehicle(const float *lla);

    // Copy Constructor
    Vehicle(const Vehicle &obj);

    // Deconstructor
    virtual ~Vehicle();

    // Setters
    void SetLLA(const float *lla);

    // Getters
    const float *getLLA() const;

    // Other Methods
    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);
    void operator=(const Vehicle &other);
    virtual void Move(const float *lla) = 0;

protected:
    // Member Variables
    float m_lla[3];

private:
    // Private Methods
    virtual void serialize(std::ostream& os) const;
};

#endif