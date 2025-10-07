/*!
 *  \file       Chassis.hpp
 *  \brief      
 *  
 */


#pragma once

#include "CompositeEquipment.hpp"

class Chassis : public CompositeEquipment
{
public:
    Chassis(const char*);
    virtual ~Chassis();

public:
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;
};