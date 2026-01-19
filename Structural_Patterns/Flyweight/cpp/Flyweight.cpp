/*!
 *  \file       Flyweight.cpp
 *  \brief      
 *  
 */


#include "Flyweight.hpp"

#include "SharedState.hpp"
#include "UniqueState.hpp"

namespace dive_into_design_patterns
{
    Flyweight::Flyweight(const SharedState *shared_state) : m_shared_state{new SharedState(*shared_state)}
    {
    }

    Flyweight::Flyweight(const Flyweight &other) : m_shared_state{new SharedState(*other.m_shared_state)}
    {
    }

    Flyweight::~Flyweight()
    {
        if (m_shared_state)
        {
            delete m_shared_state;
            m_shared_state = nullptr;
        }
    }

    SharedState* Flyweight::getSharedState() const
    {
        return m_shared_state;
    }

    void Flyweight::operation(const UniqueState &unique_state) const
    {
        std::cout << "Flyweight: Displaying shared (" << *m_shared_state 
                  << ") and unique (" << unique_state << ") state."
                  << std::endl;
    }
}