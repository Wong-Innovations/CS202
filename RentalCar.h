#ifndef RENTALCAR_H
#define RENTALCAR_H

class RentalCar
{
public:
    // Default Constructor
    RentalCar();

    // Paramatized Constructor


private:
    // Member Variables
    int   m_year;
    char  m_make[10];
    char  m_model[10];
    float m_price;
    bool  m_available;
};

#endif