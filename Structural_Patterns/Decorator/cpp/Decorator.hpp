/*!
 *  \file       Decorator.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Component.hpp"


/*!
 *  \class  Decorator
 *  \brief  The base Decorator class follows the same interface as other components.
 *          The primary purpose of this class is to define the wrapping interface for all concrete decorators.
 *          The default implementation of the wrapping code might include a field for storing a wrapped component
 *          and the means to initialize it.
 */
class Decorator : public Component
{
protected:
    Component *m_component;

public:
    Decorator(Component *component);

public:
    std::string operation() const override;
};