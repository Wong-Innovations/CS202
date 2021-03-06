#include <iostream>

#include "MyString.h"

// Default C-tor
MyString::MyString() { buffer_allocate(0); }

// Paramatized C-tor
MyString::MyString(const char* buffer)
{
    size_t size;
    // Calculate size_t of buffer
    for (int i=0; buffer[i] != 0; i++) size = i;
    size++;

    // Attempt to allocate memory
    try
    {
        buffer_allocate(size);
        // If successful, copy buffer -> m_buffer
        for(size_t i = 0; i < size; i++)
            (*this)[i] = buffer[i];
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
        buffer_deallocate();
    }
}

// Copy C-tor
MyString::MyString(const MyString & other_myStr)
{
    // Attempt to allocate memory
    try
    {
        buffer_allocate(other_myStr.size());
        // If successful, copy other_myStr.buffer -> m_buffer
        for(size_t i = 0; i < other_myStr.size(); i++)
            (*this)[i] = other_myStr[i];
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
        buffer_deallocate();
    }
}

// D-tor
MyString::~MyString() { this->buffer_deallocate(); }

// Other Methods
size_t MyString::size() const { return m_size; }
size_t MyString::length() const { return m_size-1; }
const char * MyString::c_str() const { return m_buffer; }

// Overload Operators
bool MyString::operator== (const MyString & other_myStr) const
{   
    // Strcmp Implementation
    int i = 0;
    for(;other_myStr[i] &&
        (other_myStr[i] == (*this)[i]); i++);
    
    // Boolean Conversion
    if(other_myStr[i] - (*this)[i]) return false;
    return true;
}

MyString & MyString::operator= (const MyString & other_myStr)
{
    // Deallocate current this->m_buffer
    this->buffer_deallocate();

    try
    {
        this->buffer_allocate(other_myStr.size());
        for(size_t i = 0; i < other_myStr.size(); i++)
            (*this)[i] = other_myStr[i];
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
        this->buffer_deallocate();
    }
    
    return *this;
}

MyString MyString::operator+ (const MyString & other_myStr) const
{
    // Calculate size required to store concatinated string
    size_t new_size = other_myStr.size() + size();

    // Temp storage
    char *concat_buffer;

    try
    {
        // Allocate temp storage
        concat_buffer = new char[new_size];

        // Copy m_buffer(s) -> concat_buffer
        size_t i = 0;
        for (; i < size(); i++)
            concat_buffer[i] = (*this)[i];
        for (; i < new_size; i++)
            concat_buffer[i] = other_myStr[i-size()];
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
    }

    return MyString(concat_buffer);
}

char & MyString::operator[] (size_t index) { return m_buffer[index]; }
const char & MyString::operator[] (size_t index) const { return m_buffer[index]; }

std::ostream & operator<<(std::ostream & os, const MyString & myStr)
{
    os << myStr.m_buffer;
    return os;
}

// Private Methods
void MyString::buffer_deallocate()
{
    delete[] m_buffer;
    m_buffer = NULL;
    m_size = 0;
}

void MyString::buffer_allocate(size_t size)
{
    try
    {
        m_size = size;
        m_buffer = new char[size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        this->buffer_deallocate();
    }
}