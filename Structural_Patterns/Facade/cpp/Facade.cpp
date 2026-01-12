/*!
 *  \file       Facade.cpp
 *  \brief      
 *  
 */


#include "Facade.hpp"

#include "Subsystem.hpp"

namespace dive_into_design_patterns
{
    Facade::Facade(Subsystem1 *subsystem1, Subsystem2 *subsystem2)
    {
        m_subsystem1 = subsystem1 ? : new Subsystem1();
        m_subsystem2 = subsystem2 ? : new Subsystem2();
    }

    Facade::~Facade()
    {
        if (m_subsystem1)
        {
            delete m_subsystem1;
            m_subsystem1 = nullptr;
        }
        if (m_subsystem2)
        {
            delete m_subsystem2;
            m_subsystem2 = nullptr;
        }
    }
}


/*!
 *  \fn     operation
 *  \brief  The Facade's methods are convenient shortcuts to the sophisticated functionality of the subsystems.
 *          However clients get only to a fraction of a subsystem's capabilities.
 */
std::string dive_into_design_patterns::Facade::operation()
{
    std::string result = "Facade initializes subsystems: \n";
    result += m_subsystem1->operation1();
    result += m_subsystem2->operation1();

    result += "Facade orders subsystem to perform the action: \n";
    result += m_subsystem1->operationN();
    result += m_subsystem2->operationZ();

    return result;
}