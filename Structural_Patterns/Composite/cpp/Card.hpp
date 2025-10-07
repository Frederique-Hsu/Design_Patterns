/*!
 *  \file       Card.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Equipment.hpp"

class Card : public Equipment
{
public:
    Card(const char*);
    virtual ~Card();

public:
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;
};