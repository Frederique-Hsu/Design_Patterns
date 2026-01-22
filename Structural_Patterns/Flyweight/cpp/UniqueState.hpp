/*!
 *  \file       UniqueState.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>

namespace dive_into_design_patterns
{
    class UniqueState
    {
        friend std::ostream& operator<<(std::ostream &os, const UniqueState &us);
    public:
        UniqueState(const std::string &owner, const std::string &plates);

    private:
        std::string m_owner;
        std::string m_plates;
    };
}