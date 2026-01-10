/*!
 *  \file       DropShadowDecorator.cpp
 *  \brief      
 *  
 */


#include "DropShadowDecorator.hpp"


namespace gof_design_patterns
{
    DropShadowDecorator::DropShadowDecorator(VisualComponent *component) : Decorator(component)
    {
    }

    DropShadowDecorator::~DropShadowDecorator()
    {
    }
}