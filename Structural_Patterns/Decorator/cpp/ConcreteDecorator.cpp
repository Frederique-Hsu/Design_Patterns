/*!
 *  \file       ConcreteDecorator.cpp
 *  \brief      
 *  
 */


#include "ConcreteDecorator.hpp"

namespace dive_into_design_patterns
{
ConcreteDecoratorA::ConcreteDecoratorA(Component *component) : Decorator{component}
{
}

std::string ConcreteDecoratorA::operation() const
{
    return "ConcreteDecoratorA(" + Decorator::operation() + ")";
}


ConcreteDecoratorB::ConcreteDecoratorB(Component *component) : Decorator{component}
{
}

std::string ConcreteDecoratorB::operation() const
{
    return "ConcreteDecoratorB(" + Decorator::operation() + ")";
}
}
