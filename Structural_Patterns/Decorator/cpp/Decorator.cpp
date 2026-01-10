/*!
 *  \file       Decorator.cpp
 *  \brief      
 *  
 */


#include "Decorator.hpp"

namespace dive_into_design_patterns
{
    Decorator::Decorator(Component *component) : m_component{component}
    {
    }

    std::string Decorator::operation() const
    {
        return m_component->operation();
    }
}


namespace gof_design_patterns
{
    Decorator::Decorator(VisualComponent *component) : m_component{component}
    {
    }

    Decorator::~Decorator()
    {
    }

    void Decorator::draw()
    {
        m_component->draw();
    }

    void Decorator::resize()
    {
        m_component->resize();
    }
}
