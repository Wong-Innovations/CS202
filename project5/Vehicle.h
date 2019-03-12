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
    Vehicle(const int vin, const float *lla);

    // Copy Constructor
    Vehicle(const Vehicle &obj);

    // Deconstructor
    ~Vehicle();

    // Setters
    void setLLA(const float *lla);
    void addVin(const int vin);

    // Getters
    const int getVin() const;
    const float *getLLA() const;
    static const int getIdgen();

    // Other Methods
    static int availibleVin(const int vin);
    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);
    void operator=(const Vehicle &other);
    void move(const float *lla);

private:
    // Member Variables
    float m_lla[3];
    const int m_vin;
    static int s_idgen;
    static int s_deleted_vins[256];
};

#endif