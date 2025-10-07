/*!
 *  \file       Card.cpp
 *  \brief      
 *  
 */


#include "Card.hpp"

Card::Card(const char* name) : Equipment(name)
{
}

Card::~Card()
{
}

Equipment::Watt Card::power()
{
    return Watt(3);
}

Equipment::Currency Card::netPrice()
{
    return Currency(11);
}

Equipment::Currency Card::discountPrice()
{
    return Currency(6);
}