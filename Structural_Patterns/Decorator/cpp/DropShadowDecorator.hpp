/*!
 *  \file       DropShadowDecorator.cpp
 *  \brief      
 *  
 */


#pragma once


#include "Decorator.hpp"

namespace gof_design_patterns
{
    class DropShadowDecorator : public Decorator
    {
    public:
        DropShadowDecorator(VisualComponent *);
        ~DropShadowDecorator();
    };
}