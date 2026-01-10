/*!
 *  \file       ScrollDecorator.cpp
 *  \brief      
 *  
 */


#include "ScrollDecorator.hpp"


namespace gof_design_patterns
{
    ScrollDecorator::ScrollDecorator(VisualComponent *component) : Decorator(component)
    {
    }

    ScrollDecorator::~ScrollDecorator()
    {        
    }
}