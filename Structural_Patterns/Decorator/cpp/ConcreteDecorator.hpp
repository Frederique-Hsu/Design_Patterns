/*!
 *  \file       ConcreteDecorator.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Decorator.hpp"


namespace dive_into_design_patterns
{
/*!
 *  \class  ConcreteDecoratorA
 *  \brief  Concrete Decorators call the wrapped object and alter its result in some way.
 */
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *component);

public:
    std::string operation() const override;
};


class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *component);

public:
    std::string operation() const override;
};
}
