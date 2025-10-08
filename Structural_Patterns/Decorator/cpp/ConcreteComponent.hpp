/*!
 *  \file       ConcreteComponent.hpp
 *  \brief      
 *  
 */


#pragma once


#include "Component.hpp"


/*!
 *  \class  ConcreteComponent
 *  \brief  Concrete Components provide default implementations of the operation().
 *          There might be several variations of these classes.
 */
class ConcreteComponent : public Component
{
public:
    std::string operation() const override;
};