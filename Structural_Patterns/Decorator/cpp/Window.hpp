/*!
 *  \file       Window.hpp
 *  \brief      
 *  
 */


#pragma once


namespace gof_design_patterns
{
    class VisualComponent;

    class Window
    {
    public:
        void setContents(VisualComponent *contents);

    private:
        VisualComponent *m_contents;
    };
}