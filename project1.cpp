#include <iostream>
#include <fstream>
#define LENGTH 10
#define MAXSIZE 9

void alphabetize(char name_list[][MAXSIZE], int pos[]);
void lengthSort(char name_list[][MAXSIZE], int pos[]);
void logNames(std::ofstream& outFile, char name_list[][MAXSIZE], int pos[]);
int myStringCompare(const char str1 [], const char str2 []);
void myStringCopy(char destination [], const char source []);
int myStringLength(const char str []);
void printNames(char name_list[][MAXSIZE], int pos[]);
void swapNames(char name_list[][MAXSIZE], int pos[], const int a, const int b);

int main(void)
{
    char source_file_name[MAXSIZE], destination_file_name[MAXSIZE];
    char name_list[LENGTH][MAXSIZE];
    int pos[LENGTH] = {0,1,2,3,4,5,6,7,8,9};

    std::cout << "Enter source file name: ";
    std::cin >> source_file_name;
    std::cout << "Enter destination file name: ";
    std::cin >> destination_file_name;

    std::ifstream source_file;
    source_file.open(source_file_name);

    std::ofstream destination_file;
    destination_file.open(destination_file_name);
   
    for (int i = 0; !source_file.eof(); i++)
    {
    	source_file >> name_list[i];
    }

    std::cout << "Unsorted Data (Original Input Order and Name)" << std::endl;
    std::cout << "=============================" << std::endl;
    printNames(name_list, pos);

    lengthSort(name_list, pos);

    std::cout << "\nSorted-by-Length Data (Original Input Order and Name)" << std::endl;
    std::cout << "=============================" << std::endl;
    destination_file << "Sorted-by-Length Data (Original Input Order and Name)\n";
    destination_file << "=============================\n";
    printNames(name_list, pos);
    logNames(destination_file, name_list, pos);

    alphabetize(name_list, pos);

    std::cout << "\nAlphabetcially Sorted Data (Original Input Order and Name)" << std::endl;
    std::cout << "=============================" << std::endl;
    destination_file << "\nAlphabetcially Sorted Data (Original Input Order and Name)\n";
    destination_file << "=============================\n";
    printNames(name_list, pos);
    logNames(destination_file, name_list, pos);

    destination_file.close();
    return 0;
}

void alphabetize(char name_list[][MAXSIZE], int pos[])
{
	for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - 1; j++)
        {
            if (myStringCompare(name_list[j], name_list[j+1]) == 1)
            {
                swapNames(name_list, pos, j, j+1);
            }
        }
    }
}

void lengthSort(char name_list[][MAXSIZE], int pos[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - i - 1; j++)
        {
            if (myStringLength(name_list[j]) > myStringLength(name_list[j+1]))
            {
                swapNames(name_list, pos, j, j+1);
            }
        }
    }
}

void logNames(std::ofstream& outFile, char name_list[][MAXSIZE], int pos[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        outFile << pos[i] << ' ' << name_list[i] << '\n';
    }
}

int myStringCompare(const char str1 [], const char str2 [])
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

void myStringCopy(char destination [], const char source [])
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int myStringLength(const char str [])
{
    int len = 0;
    for (; str[len] != '\0'; len++) continue;

    return len;
}

void printNames(char name_list[][MAXSIZE], int pos[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << pos[i] << ' ' << name_list[i] << std::endl;
    }
}

void swapNames(char name_list[][MAXSIZE], int pos[], const int a, const int b)
{
    char temp[MAXSIZE];
	int storage = pos[b];
    myStringCopy(temp, name_list[b]);
    myStringCopy(name_list[b], name_list[a]);
    myStringCopy(name_list[a], temp);
	pos[b] = pos[a];
	pos[a] = storage;
}
