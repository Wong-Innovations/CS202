#include <iostream>
#include <fstream>
#define LENGTH 10

void alphabetize(char arr[][255], int pos[]);
void lenSort(char arr[][255], int pos[]);
void logNames(std::ofstream& outFile, char arr[][255], int pos[]);
int myStringCompare(const char str1 [], const char str2 []);
void myStringCopy(char destination [], const char source []);
int myStringLength(const char str []);
void printNames(char arr[][255], int pos[]);

int main(void)
{
    char source_file_name[255], destination_file_name[255];
    char name_list[LENGTH][255];
    int pos[LENGTH] = {0,1,2,3,4,5,6,7,8,9};

    // User input
    std::cout << "Enter source file name: ";
    std::cin >> source_file_name;
    std::cout << "Enter destination file name: ";
    std::cin >> destination_file_name;

    // open a file in read mode.
    std::ifstream source_file;
    source_file.open(source_file_name);

    // open a file in write mode
    std::ofstream destination_file;
    destination_file.open(destination_file_name);
   
    for (int i = 0; !source_file.eof(); i++)
    {
    	source_file >> name_list[i];
    }

    std::cout << "Unsorted Data (Original Input Order and Name)" << std::endl;
    std::cout << "=============================" << std::endl;
    printNames(name_list, pos);

    lenSort(name_list, pos);

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

void alphabetize(char arr[][255], int pos[])
{
	for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - 1; j++)
        {
            if (myStringCompare(arr[j], arr[j+1]) == 1)
            {
                char temp[255];
				int storage = pos[j+1];
                myStringCopy(temp, arr[j+1]);
                myStringCopy(arr[j+1], arr[j]);
                myStringCopy(arr[j], temp);
				pos[j+1] = pos[j];
				pos[j] = storage;
            }
        }
    }
}

void lenSort(char arr[][255], int pos[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - i - 1; j++)
        {
            if (myStringLength(arr[j]) > myStringLength(arr[j+1]))
            {
                char temp[255];
				int storage = pos[j+1];
                myStringCopy(temp, arr[j+1]);
                myStringCopy(arr[j+1], arr[j]);
                myStringCopy(arr[j], temp);
				pos[j+1] = pos[j];
				pos[j] = storage;
            }
        }
    }
}

void logNames(std::ofstream& outFile, char name_list[][255], int pos[])
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

void printNames(char name_list[][255], int pos[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << pos[i] << ' ' << name_list[i] << std::endl;
    }
}
