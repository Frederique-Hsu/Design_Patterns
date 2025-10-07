/*!
 *  \file       Bus.cpp
 *  \brief      
 *  
 */


#include "Bus.hpp"


Bus::Bus(const char* name) : CompositeEquipment(name)
{
}

Bus::~Bus()
{
}

Equipment::Watt Bus::power()
{
    return Watt(1);
}

Equipment::Currency Bus::netPrice()
{
    return Currency(20);
}

Equipment::Currency Bus::discountPrice()
{
    return Currency(16);
}