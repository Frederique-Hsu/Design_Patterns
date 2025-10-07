/*!
 *  \file       FloppyDisk.cpp
 *  \brief      
 *  
 */


#include "FloppyDisk.hpp"


FloppyDisk::FloppyDisk(const char* name) : Equipment(name)
{
}

FloppyDisk::~FloppyDisk()
{
}

Equipment::Watt FloppyDisk::power()
{
    Watt watt(10);
    return watt;
}

Equipment::Currency FloppyDisk::netPrice()
{
    Currency currency(10);
    return currency;
}

Equipment::Currency FloppyDisk::discountPrice()
{
    Currency currency(5);
    return currency;
}