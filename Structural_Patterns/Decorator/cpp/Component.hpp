/*!
 *  \file       Component.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>


namespace dive_into_design_patterns
{
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
}


namespace gof_design_patterns
{
    class VisualComponent
    {
    public:
        VisualComponent();
        virtual ~VisualComponent();

    public:
        virtual void draw();
        virtual void resize();
    };
}
