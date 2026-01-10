/*!
 *  \file       BorderDecorator.hpp
 *  \brief      
 *  
 */


#pragma once


#include "Decorator.hpp"

namespace gof_design_patterns
{
    class BorderDecorator : public Decorator
    {
    public:
        BorderDecorator(VisualComponent *, int border_width);
        ~BorderDecorator();

    public:
        void draw() override;

    private:
        void drawBorder(int);

    private:
        int m_width;
    };
}