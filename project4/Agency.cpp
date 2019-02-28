#include <iostream>
#include <fstream>
#include "Agency.h"
#include "Car.h"
#include "myStrings.h"

// Default Constructor
Agency::Agency()
{
    m_zipcode = 00000;
    myStringCopy(m_name, "NO-NAME");
}

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

// Paramatized Constructor
Agency::Agency(char* name, int zipcode, Car* inventory) :
    m_zipcode(zipcode)
{
    myStringCopy(m_name, name);
}

// Setters
void Agency::setName(char* name)
{
    myStringCopy(m_name, name);
}

void Agency::setZip(int zipcode)
{
    m_zipcode = zipcode;
}

void Agency::setInventory(Car* inventory)
{
    for(int i = 0; i < 5; i++, inventory++)
    {
        this->m_inventory[i].setYear(inventory->getYear());
        this->m_inventory[i].setMake(inventory->getMake());
        this->m_inventory[i].setModel(inventory->getModel());
        this->m_inventory[i].setBaseprice(inventory->getBaseprice());
        this->m_inventory[i].setAvailability(inventory->getAvailability());
    }
}

// Getters
char* Agency::getName()
{
    return m_name;
}

int Agency::getZip()
{
    return m_zipcode;
}

Car* Agency::getInventory()
{
    return m_inventory;
}


// Overload Operators
Car& Agency::operator[](const int index)
{
    return m_inventory[index];
}

// Other Methods
void Agency::printAllData()
{
    std::cout << this->getName() << ' '
    << this->getZip() << '\n';

    Car *carsRef = getInventory();

    for(int j = 0; j < 5; j++)
    {
        carsRef->print();
        carsRef++;
    }
    std::cout << '\n';
}

void Agency::readAllData(std::ifstream & infile)
{
    char temp_name[256], trash;
    int temp_zip;

    infile >> temp_name;
    infile >> temp_zip;

    this->setName(temp_name);
    this->setZip(temp_zip);

    for(int j = 0; j < 5; j++)
    {
        int temp_year;
        char temp_make[256], temp_model[256], trash;
        float temp_price;
        bool temp_available;
        char temp_type[256];
        Sensor arr[3];
        Sensor *arrRef = arr;

        infile >> temp_year;
        infile >> temp_make;
        infile >> temp_model;
        infile >> temp_price;

        while(1)
        {
            infile.get(trash);
            if (trash == '{')
            {
                char* temp_typeRef;
                temp_typeRef = temp_type;
                do{
                    infile.get(trash);
                    *temp_typeRef = trash;
                    temp_typeRef++;
                }while((trash != '}') && (trash != ' '));
                
                *temp_typeRef = '\0';

                std::cout << temp_type << std::endl;

                arrRef->setType(temp_type);
                arrRef->setExtracost();
                arrRef++;
            }
            if (trash == '}') {break;}
        }
        
        infile >> temp_available;

        (*this)[j].setYear(temp_year);
        (*this)[j].setMake(temp_make);
        (*this)[j].setModel(temp_model);
        (*this)[j].setBaseprice(temp_price);
        (*this)[j].setSensors(arr);
        (*this)[j].setAvailability(temp_available);
    }
}