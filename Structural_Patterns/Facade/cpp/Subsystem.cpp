/*!
 *  \file       Subsystem.cpp
 *  \brief      
 *  
 */


#include "Subsystem.hpp"


namespace dive_into_design_patterns
{
    std::string Subsystem1::operation1() const
    {
        return "Subsystem1: Ready!\n";
    }

    std::string Subsystem1::operationN() const
    {
        return "SubsystemN: Go!\n";
    }

    std::string Subsystem2::operation1() const
    {
        return "Subsystem2: Get ready!\n";
    }

    std::string Subsystem2::operationZ() const
    {
        return "Subsystem2: Fire!\n";
    }
}