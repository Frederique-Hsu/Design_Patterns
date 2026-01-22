/*!
 *  \file       UniqueState.cpp
 *  \brief      
 *  
 */


#include "UniqueState.hpp"

#include <iostream>

namespace dive_into_design_patterns
{
    UniqueState::UniqueState(const std::string &owner, const std::string &plates)
        : m_owner{owner}, m_plates{plates}
    {
    }

    std::ostream& operator<<(std::ostream &os, const UniqueState &us)
    {
        os << "[" << us.m_owner << ", " << us.m_plates << "]";
        return os;
    }
}
