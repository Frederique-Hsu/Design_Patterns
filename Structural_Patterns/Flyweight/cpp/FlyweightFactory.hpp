/*!
 *  \file       FlyeightFactory.hpp
 *  \brief      
 *  
 */


#pragma once

#include <initializer_list>
#include <unordered_map>

#include "SharedState.hpp"
#include "Flyweight.hpp"

namespace dive_into_design_patterns
{
    /*!
     *  \class  FlyweightFactory
     *  \brief  The Flyweight Factory creates and manages the Flyweight objects.
     *          It ensures that flyweights are shared correctly, when the client request a flyweight,
     *          the factory either returns an existing instance or create a new one, if it doesn't exist yet.
     */
    class FlyweightFactory
    {
    public:
        FlyweightFactory(std::initializer_list<SharedState> shared_states);

    private:
        std::unordered_map<std::string, Flyweight> m_flyweights;

    public:
        Flyweight getFlyweight(const SharedState &shared_state);
        void listFlyweights() const;

    private:
        std::string getKey(const SharedState &ss) const;
    };
}
