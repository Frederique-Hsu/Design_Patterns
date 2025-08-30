/*!
 *  \file       ConcreteImplementor.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Implementor.hpp"


/*!
 *  \details    Each concrete implementor corresponds to a specific platform and 
 *              implements the Implementor interface using that platform's API.
 */
class ConcreteImplementorA : public Implementor
{
public:
    std::string OperationImpl() const override;
};


class ConcreteImplementorB : public Implementor
{
public:
    std::string OperationImpl() const override;
};