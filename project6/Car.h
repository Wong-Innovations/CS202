#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Vehicle.h"

class Car : Vehicle
{
public:
    // Default Constructor
    Car();
    
    // Paramatized Constructor
    Car(const float* lla);

    // Copy Constructor
    Car(const Car &obj);

    // Deconstructor
    virtual ~Car() override;

    // Setters
    void setThrottle(const int throttle);

    // Getters
    const int getThrottle() const;

    // Other Methods
    virtual void Move(const float *lla) override;
    void drive(const int throttle);
    void operator=(const Car &other);

private:
    // Member Variables
    int m_throttle;
    // Private Methods
    virtual void serialize(std::ostream& os) const override;
};

#endif