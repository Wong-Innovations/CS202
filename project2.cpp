/*********************************************************
 * Name: proj2.c                                         *
 * Purpose: Calculate best valued rental car.            *
 * Author: Dylan Wong                                    *
 * Class: CS 202.1001                                    *
 *********************************************************/
#include <iostream>
#include <fstream>

struct RentalCar {
    int year = 0000;
    char make[10] = "NO CAR";
    char model[10] = "SELECTED";
    float price = 0.00;
    bool available = 0;
};

// Function name: displayMenu
// Pre-condition: None
// Post-condition: Prints the menu to the console
void displayMenu();

// Function name: logCarData
// Pre-condition: carsArray is an array of RendalCar objetcts, positionArray is an array of integers coresponding to carsArray objects' original indexes, destination_file_name is a string.
// Post-condition: Saves carsArray to a file with name "destination_file_name"
void logCarData(RentalCar* carsArray, const int* positionArray, const char* destination_file_name);

// Function name: myStringCat
// Pre-condition: destination and source are c-string pointers, destination has enough additional space to store source
// Post-condition: Returns a pointer to the destination array, destination array contains source appended to the end
char *myStringCat(char* destination, const char* source);

// Function name: myStringCompare
// Pre-condition: str1 and str2 are c-string pointers
// Post-condition: Returns 0 when the C-strings match,
//  i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
//  returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
//  returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char* str1, const char* str2);

// Function name: myStringCopy
// Pre-condition: destination and source are c-string pointers, destination has enough space to store
// Post-condition: Returns a pointer to the destination array, destination array contains source string
char *myStringCopy(char* destination, const char* source);

// Function name: myStringLength
// Pre-condition: str is a c-string pointer
// Post-condition: Returns the required number of bytes to hold str
size_t myStringLength(const char*str);

//
void printCarData(RentalCar* carsArray, const int* positionArray, const float* rates, const int num_of_days);

// 
void readFile(RentalCar* carsArray, const char* source_file_name);

// 
void sortByPrice(RentalCar* carsArray, int* positionArray);

//
void swapCars(RentalCar* a, RentalCar* b);

int main(void)
{
    RentalCar carsArray[5];
    char source_file_name[255], destination_file_name[255];
    int selection, positionArray[5] = {0,1,2,3,4};

    do
    {
        displayMenu();
        std::cin >> selection;

        float rates[5];
        int num_of_days;
        switch (selection)
        {
            case 1:
                std::cout << "Source filename: ";
                std::cin >> source_file_name;
                readFile(carsArray, source_file_name);
                break;
            case 2:
                printCarData(carsArray, positionArray, 0, 0);
                break;
            case 3:
                std::cout << "Destination filename: ";
                std::cin >> destination_file_name;
                logCarData(carsArray, positionArray, destination_file_name);
                break;
            case 4:
                sortByPrice(carsArray, positionArray);
                break;
            case 5:
                std::cout << "Number of days you wish to rent a car: ";
                std::cin >> num_of_days;

                sortByPrice(carsArray, positionArray);

                rates[0] = carsArray[0].price * num_of_days;
                rates[1] = carsArray[1].price * num_of_days;
                rates[2] = carsArray[2].price * num_of_days;
                rates[3] = carsArray[3].price * num_of_days;
                rates[4] = carsArray[4].price * num_of_days;

                printCarData(carsArray, positionArray, rates, num_of_days);
                break;
            case 6:
            
                break;
            case 7: selection = 0;
        }
    } while(selection);

    return 0;
}

void displayMenu()
{
    std::cout << '\n'
    << "1. Read car data.\n"
    << "2. Print car data.\n"
    << "3. Save car data.\n"
    << "4. Sort cars (by price).\n"
    << "5. Compare rental prices.\n"
    << "6. Calculate a car's rental price.\n"
    << "7. Exit the program.\n"
    << "Enter your selection: ";

    return;
}

void logCarData(RentalCar* carsArray, const int* positionArray, const char* destination_file_name)
{
    std::ofstream destination_file;
    destination_file.open(destination_file_name);

    for(int i = 0; i < 5; i++)
    {
        destination_file
        << '[' << positionArray[i] << "] "
        << carsArray[i].year << ' '
        << carsArray[i].make << ' '
        << carsArray[i].model << " , $"
        << carsArray[i].price << " per day , Available: "
        << std::boolalpha
        << carsArray[i].available << "\n";
    }
}

int myStringCompare(const char* str1, const char* str2)
{
	for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		int val1 = str1[i], val2 = str2[i];
		(val1 >= 97)? val1 -= 32 : val1 -= 0;
		(val2 >= 97)? val2 -= 32 : val1 -= 0;
		if (val1 > val2){
			return 1;
		}else if (val1 < val2){
			return -1;
		}
	}
    return 0;
}

char* myStringCopy(char* destination, const char* source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

size_t myStringLength(const char* str)
{
    int len = 0;
    for (; str[len] != '\0'; len++) continue;

    return len * sizeof(char);
}

void printCarData(RentalCar* carsArray, const int* positionArray, const float* rates, const int num_of_days)
{
    for(int i = 0; i < 5; i++)
    {
        if (rates || num_of_days)
        {
            if (carsArray[i].available)
            {
                std::cout 
                << '[' << i << "] "
                << carsArray[i].year << ' '
                << carsArray[i].make << ' '
                << carsArray[i].model << " , Total Cost: $"
                << rates[i] << "\n";
            }
        } else
        {
            std::cout 
            << '[' << positionArray[i] << "] "
            << carsArray[i].year << ' '
            << carsArray[i].make << ' '
            << carsArray[i].model << " , $"
            << carsArray[i].price << " per day , Available: "
            << std::boolalpha
            << carsArray[i].available << "\n";
        }
    }
}

void readFile(RentalCar* carsArray, const char* source_file_name)
{
    std::ifstream source_file;
    source_file.open(source_file_name);
    if(!source_file)
    {
        std::cout << "File cannot be read.\n";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            source_file >> carsArray[i].year;
            source_file >> carsArray[i].make;
            source_file >> carsArray[i].model;
            source_file >> carsArray[i].price;
            source_file >> carsArray[i].available;
        }
    }
    
    return;
}

void sortByPrice(RentalCar* carsArray, int* positionArray)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (carsArray[j+1].price < carsArray[j].price)
            {
                int tempInt = positionArray[j+1];
                positionArray[j+1] = positionArray[j];
                positionArray[j] = tempInt;

                swapCars(&carsArray[j+1], &carsArray[j]);
            }
        }
    }
    return;
}

void swapCars(RentalCar* a, RentalCar* b)
{
    RentalCar tempObj = *a;
    *a = *b;
    *b = tempObj;
    return;
}