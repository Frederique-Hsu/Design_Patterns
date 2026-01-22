/*!
 *  \file       Flyweight.hpp
 *  \brief      
 *  
 */


#pragma once


namespace dive_into_design_patterns
{
    class SharedState;
    class UniqueState;

    class Flyweight
    {
    public:
        Flyweight(const SharedState *shared_state);
        Flyweight(const Flyweight &other);
        ~Flyweight();

    private:
        SharedState *m_shared_state;

    public:
        SharedState* getSharedState() const;
        void operation(const UniqueState &unique_state) const;
    };
}