/*!
 *  \file       Decorator.cpp
 *  \brief      
 *  
 */


#include "Decorator.hpp"


Decorator::Decorator(Component *component) : m_component{component}
{
}

std::string Decorator::operation() const
{
    return m_component->operation();
}