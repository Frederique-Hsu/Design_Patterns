/*!
 *  \file       Implementor.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>


/*!
 *  \class      Implementor
 *  \details    This Implementor defines the interface for all implementor sub-classes.
 *              It doesn't have to match with the Abstraction's interface. In fact, the two interfaces can be 
 *              entirely different. Typically the Implementor interface provides only primitive operations, 
 *              while the Abstraction defines higher-level operation based on those primitives.
 */
class Implementor
{
public:
    virtual ~Implementor() {}

public:
    virtual std::string OperationImpl() const = 0;
};