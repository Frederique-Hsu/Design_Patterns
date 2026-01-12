/*!
 *  \file       Subsystem.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>

namespace dive_into_design_patterns
{
    /*!
     *  \class  Subsystem
     *  \brief  The Subsystem can accept requests either from facade or client directly.
     *          In any case, to the Subsystem, the facade is yet another client, and it 
     *          is not a part of subsystem.
     */
    class Subsystem1
    {
    public:
        std::string operation1() const;
        //...
        std::string operationN() const;
    };


    class Subsystem2
    {
    public:
        std::string operation1() const;
        //...
        std::string operationZ() const;
    };
}