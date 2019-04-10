#include <iostream>
#include "DataType.h"
#include "SmartPtr.h"

SmartPtr::SmartPtr( )
{
    try
    {
        m_ptr = new DataType;
        m_refcount = new size_t;
        *m_refcount = 0;
        if (m_ptr != NULL) m_refcount++;
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "SmartPtr Default Constructor for new allocation, RefCount="
            << *m_refcount << std::endl;
}

SmartPtr::SmartPtr( DataType * data )
{
    m_ptr = data;
    try
    {
        m_refcount = new size_t;
        *m_refcount = 0;
        if (m_ptr != NULL) m_refcount++; // Checks data wasn't NULL
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "SmartPtr Parametrized Constructor from data pointer, RefCount="
        << *m_refcount << std::endl;   
}

SmartPtr::SmartPtr( const SmartPtr & other )
{
    m_ptr = other.m_ptr;
    m_refcount = other.m_refcount;
    m_refcount++;
    
    std::cout << "SmartPtr Copy Constructor, RefCount=" << *m_refcount << std::endl;
}


SmartPtr::~SmartPtr( )
{
    --(*m_refcount);
    if (!(*m_refcount)) {
        delete m_ptr;
        m_ptr = NULL;
    }

    std::cout << "SmartPtr Destrcutor, RefCount=" << *m_refcount << std::endl;
}


SmartPtr & SmartPtr::operator=( const SmartPtr & rhs )
{
    --(*m_refcount); // Decrease this->count
    ++(*rhs.m_refcount); // Increase new->count

    if (!(*m_refcount)) {
        delete m_ptr;
        m_ptr = NULL;
    }

    m_ptr = rhs.m_ptr;
    m_refcount = rhs.m_refcount;

    return (*this);
}


DataType & SmartPtr::operator*( ) { return (*this->m_ptr); }
DataType * SmartPtr::operator->( ) { return this->m_ptr; }