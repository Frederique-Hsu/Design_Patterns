/*!
 *  \file       Cabinet.cpp
 *  \brief      
 *  
 */


#include "Cabinet.hpp"

Cabinet::Cabinet(const char* name) : CompositeEquipment(name)
{
}

Cabinet::~Cabinet()
{
}

Equipment::Watt Cabinet::power()
{
    Watt w(2);
    return w;
}

Equipment::Currency Cabinet::netPrice()
{
    return Currency(30);
}

Equipment::Currency Cabinet::discountPrice()
{
    return Currency(26);
}