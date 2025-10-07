/*!
 *  \file       Chassis.cpp
 *  \brief      
 *  
 */


#include "Chassis.hpp"


Chassis::Chassis(const char* name) : CompositeEquipment(name)
{
}

Chassis::~Chassis()
{
}

Equipment::Watt Chassis::power()
{
    Watt w(4);
    return w;
}

Equipment::Currency Chassis::netPrice()
{
    Currency c(40);
    return c;
}

Equipment::Currency Chassis::discountPrice()
{
    Currency c(36);
    return c;
}