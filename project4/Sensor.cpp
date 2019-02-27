#include "Sensor.h"
#include "myStrings.h"

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

void Sensor::setExtracost()
{
    if (m_type)
    {
        /* code */
    }
    
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

// Overload Operators
bool Sensor::operator== (Sensor *sensorRef)
{
    bool result = 1;
    char *sensor_one_type = this->getType();
    char *sensor_two_type = sensorRef->getType();

    while((*sensor_one_type != '\0') && (*sensor_two_type != '\0'))
    {
        if (*sensor_one_type != *sensor_two_type)
        {
            result = 0;
            break;
        }

        sensor_one_type++, sensor_two_type++;
    }
    
    return result;
}
