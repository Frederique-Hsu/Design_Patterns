/*!
 *  \file       Cabinet.hpp
 *  \brief      
 *  
 */


#pragma once

#include "CompositeEquipment.hpp"

class Cabinet : public CompositeEquipment
{
public:
    Cabinet(const char*);
    virtual ~Cabinet();

    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;
};