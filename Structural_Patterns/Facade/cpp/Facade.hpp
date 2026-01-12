/*!
 *  \file       Facade.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>

namespace dive_into_design_patterns
{
    class Subsystem1;
    class Subsystem2;

    /*!
     *  \class  Facade
     *  \brief  The Facade class provides a simple interface to the complex logic of one or several subsystems.
     *          The Facade delegates the client's requests to the appropriate objects within the subsystem.
     *          The Facade is also responsible for managing their lifecycle. All of this shields the client
     *          from undesired complexity of the subsystem.
     */
    class Facade
    {
    protected:
        Subsystem1 *m_subsystem1;
        Subsystem2 *m_subsystem2;

    public:
        Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr);
        ~Facade();

    public:
        std::string operation();
    };
}