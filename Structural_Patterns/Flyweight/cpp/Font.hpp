/*!
 *  \file       Font.hpp
 *  \brief      
 *  
 */


#pragma once

namespace gof_design_patterns
{
    class Font
    {
    public:
        Font(char *);
        
    private:
        [[maybe_unused]] char *m_name;
    };
}
