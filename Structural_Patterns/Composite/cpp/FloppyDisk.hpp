/*!
 *  \file       FloppyDisk.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Equipment.hpp"

class FloppyDisk : public Equipment
{
public:
    FloppyDisk(const char*);
    virtual ~FloppyDisk();

public:
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;
};