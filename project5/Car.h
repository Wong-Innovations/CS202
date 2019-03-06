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
    Car(const char* plates, const int throttle);

    // Copy Constructor
    Car(const Car &obj);

    // Deconstructor
    ~Car();

    // Setters
    void setThrottle(const int throttle);
    void setPlates(const char *plates);

    // Getters
    const int getThrottle() const;
    const char *getPlates() const;

    // Other Methods
    void move(const float *lla);
    void drive(const int throttle);

private:
    // Member Variables
    char m_plates[256];
    int m_throttle;
};

#endif