/*!
 *  \file       Leaf.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Component.hpp"

class Leaf : public Component
{
public:
    std::string operation() const override;
};
