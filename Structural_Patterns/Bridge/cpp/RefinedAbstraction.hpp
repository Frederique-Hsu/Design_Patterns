/*!
 *  \file       RefinedAbstraction.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Abstraction.hpp"

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *implementor);
    ~RefinedAbstraction() = default;

public:
    std::string Operation() const override;
};