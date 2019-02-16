#include "Sensor.h"

// Default Constructor
Sensor::Sensor()
{

}

// Parametized Constructor
Sensor::Sensor(char* type, float extracost)
{
    myStringCopy(m_type, type);
    m_extracost = extracost;
}

// Setters
void Sensor::setType(char* type)
{
    myStringCopy(m_type, type);
}

void Sensor::setExtracost(float extracost)
{
    m_extracost = extracost;
}

// Getters
char* Sensor::getType()
{
    return m_type;
}

float Sensor::getExtracost()
{
    return m_extracost;
}