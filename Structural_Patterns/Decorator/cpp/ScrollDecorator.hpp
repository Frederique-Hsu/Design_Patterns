/*!
 *  \file       ScrollDecorator.hpp
 *  \brief      
 *  
 */


#pragma once


#include "Decorator.hpp"

namespace gof_design_patterns
{
    class ScrollDecorator : public Decorator
    {
    public:
        ScrollDecorator(VisualComponent *);
        ~ScrollDecorator();
    };
}