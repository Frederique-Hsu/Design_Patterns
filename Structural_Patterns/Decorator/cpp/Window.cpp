/*!
 *  \file       Window.cpp
 *  \brief      
 *  
 */


#include "Window.hpp"

#include "Component.hpp"

namespace gof_design_patterns
{
    void Window::setContents(VisualComponent *contents)
    {
        m_contents = contents;
    }
}