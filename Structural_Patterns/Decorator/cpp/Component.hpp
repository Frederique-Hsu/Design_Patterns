/*!
 *  \file       Component.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>


/*!
 *  \class  Component
 *  \brief  This base Component interface defines operations that can be altered by decorators.
 */
class Component
{
public:
    virtual ~Component() = default;

public:
    virtual std::string operation() const = 0;
};