/*!
 *  \file       FlyweightFactory.cpp
 *  \brief      
 *  
 */


#include "FlyweightFactory.hpp"

#include <iostream>


namespace dive_into_design_patterns
{
    FlyweightFactory::FlyweightFactory(std::initializer_list<SharedState> shared_states)
    {
        for (const SharedState &ss : shared_states)
        {
            m_flyweights.insert(std::make_pair(getKey(ss), Flyweight(&ss)));
        }
    }

    std::string FlyweightFactory::getKey(const SharedState &ss) const
    {
        return ss.getBrand() + "_" + ss.getModel() + "_" + ss.getColor();
    }

    Flyweight FlyweightFactory::getFlyweight(const SharedState &shared_state)
    {
        std::string key = getKey(shared_state);
        if (m_flyweights.find(key) == m_flyweights.end())
        {
            std::cout << "FlyweightFactory: cannot find a flyweight, creating a new one." << std::endl;
            m_flyweights.insert(std::make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            std::cout << "FlyweightFactory: Reusing existing flyweight." << std::endl;
        }
        
        return m_flyweights.at(key);
    }

    void FlyweightFactory::listFlyweights() const
    {
        size_t count = m_flyweights.size();
        std::cout << "FlyweightFactory: I have " << count << " flyweights:" << std::endl;
        for (const auto& [key, flyweight] : m_flyweights)
        {
            std::cout << key << std::endl;
        }
    }
}
