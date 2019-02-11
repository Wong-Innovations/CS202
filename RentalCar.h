#ifndef RENTALCAR_H
#define RENTALCAR_H

void myStringCopy(char* des, char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}

class RentalCar
{
public:
    // Default Constructor
    RentalCar()
    {
        RentalCar::setYear(0000);
        RentalCar::setMake("NO CAR");
        RentalCar::setModel("SELECTED");
        RentalCar::setPrice(0.00);
        RentalCar::setAvailability(0);
    }

    // Paramatized Constructor
    RentalCar(int year, char *make, char *model, float price, bool available)
    {
        RentalCar::setYear(year);
        RentalCar::setMake(make);
        RentalCar::setModel(model);
        RentalCar::setPrice(price);
        RentalCar::setAvailability(available);
    }

    // Setters
    void setYear(int year){m_year = year;}
    void setMake(char *make){myStringCopy(m_make, make);}
    void setModel(char *model){myStringCopy(m_model, model);}
    void setPrice(float price){m_price = price;}
    void setAvailability(bool available){m_available = available;}

    // Getters
    int   getYear(){return m_year;}
    char* getMake(){return m_make;}
    char* getModel(){return m_model;}
    float getPrice(){return m_price;}
    bool  getAvailability(){return m_available;}

private:
    // Member Variables
    int   m_year;
    char  m_make[10];
    char  m_model[10];
    float m_price;
    bool  m_available;
};

#endif