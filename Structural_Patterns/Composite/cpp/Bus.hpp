/*!
 *  \file       Bus.hpp
 *  \brief      
 *  
 */


#pragma once

#include "CompositeEquipment.hpp"


class Bus : public CompositeEquipment
{
public:
    Bus(const char*);
    virtual ~Bus();

public:
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;
};