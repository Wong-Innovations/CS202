#include "Sensor.h"

#ifndef CAR_H
#define CAR_H

class Car
{
public:
    // Default Constructor
    Car();

    // Paramatized Constructor
    Car(int year, char *make, char *model, float price, bool available);

    // Copy Constructor
    Car(const Car &carAddr);

    // Setters
    void setYear(int year);
    void setMake(char *make);
    void setModel(char *model);
    void setBaseprice(float baseprice);
    void setAvailability(bool available);
    void setOwner(char* owner);

    // Getters
    int     getYear(int year);
    char*   getMake(char *make);
    char*   getModel(char *model);
    Sensor* getSensors(Sensor* sensors);
    float   getBaseprice(float baseprice);
    float   getFinalprice(float finalprice);
    bool    getAvailability(bool available);
    char*   getOwner(char* owner);

    // Other methods
    void addLessee();
    void addSensor();
    float estimateCost(const int num_of_days);
    void print();
    void updatePrice(float price); // updates final price

private:
    // Member Variables
    int    m_year;
    char   m_make[256];
    char   m_model[256];
    Sensor m_sensors[3];
    float  m_baseprice;
    float  m_finalprice;
    bool   m_available;
    char   m_owner[256];
};

#endif