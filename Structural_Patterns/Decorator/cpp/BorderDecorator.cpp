/*!
 *  \file       BorderDecorator.cpp
 *  \brief      
 *  
 */


#include "BorderDecorator.hpp"

#include <iostream>


namespace gof_design_patterns
{
    BorderDecorator::BorderDecorator(VisualComponent *component, int border_width)
        : Decorator(component), m_width{border_width}
    {
    }

    BorderDecorator::~BorderDecorator()
    {
    }

    void BorderDecorator::draw()
    {
        Decorator::draw();
        drawBorder(m_width);
    }

    void BorderDecorator::drawBorder(int width)
    {
        std::cout << "BorderDecorator::drawBorder(" << width << ")" << std::endl;
    }
}