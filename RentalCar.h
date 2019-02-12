#ifndef RENTALCAR_H
#define RENTALCAR_H

class RentalCar
{
public:
    // Default Constructor
    RentalCar();

    // Paramatized Constructor
    RentalCar(int year, char *make, char *model, float price, bool available);

    // Setters
    void setYear(int year);
    void setMake(char *make);
    void setModel(char *model);
    void setPrice(float price);
    void setAvailability(bool available);

    // Getters
    int   getYear();
    char* getMake();
    char* getModel();
    float getPrice();
    bool  getAvailability();

private:
    // Member Variables
    int   m_year;
    char  m_make[10];
    char  m_model[10];
    float m_price;
    bool  m_available;
};

#endif