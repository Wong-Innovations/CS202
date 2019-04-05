#include <iostream>

#include "DataType.h"
#include "SmartPtr.h"

SmartPtr::SmartPtr( )
{
    try
    {
        m_ptr = new DataType;
        m_refcount = new size_t;
        *m_refcount = 1;
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
        m_refcount = 0;
        if (m_ptr) m_refcount++;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

SmartPtr::SmartPtr( const SmartPtr & other )
{
    
}


SmartPtr::~SmartPtr( )
{
    
}


SmartPtr & SmartPtr::operator=( const SmartPtr & rhs )
{
    
}


DataType & SmartPtr::operator*( )
{
    
}

DataType * SmartPtr::operator->( )
{
    
}
