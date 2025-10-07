/*!
 *  \file       Equipment.cpp
 *  \brief      
 *  
 */


#include "Equipment.hpp"

#include "UnimplementedException.hpp"

Equipment::Equipment(const char *name) : m_name{name}
{
}

Equipment::~Equipment()
{
}

const char* Equipment::name()
{
    return m_name;
}

Equipment::Watt Equipment::power()
{
    NOT_IMPLEMENTED_EXCEPTION();
    return 0;
}

Equipment::Currency Equipment::netPrice()
{
    NOT_IMPLEMENTED_EXCEPTION();
    return 0;
}

Equipment::Currency Equipment::discountPrice()
{
    NOT_IMPLEMENTED_EXCEPTION();
    return 0;
}

void Equipment::add(Equipment *)
{
    NOT_IMPLEMENTED_EXCEPTION();
}

void Equipment::remove(Equipment *)
{
    NOT_IMPLEMENTED_EXCEPTION();
}

Iterator<Equipment *>* Equipment::createIterator()
{
    NOT_IMPLEMENTED_EXCEPTION();
    return nullptr;
}