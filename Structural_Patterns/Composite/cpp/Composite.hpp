/*!
 *  \file       Composite.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Component.hpp"

#include <list>


/*!
 *  \class  Composite
 *  \brief  The Composite class represents the complex components that may have children.
 *          usuablly, the Composite objects delegates the actual work to their children and then "sum-up" the result.
 */
class Composite : public Component
{
protected:
    std::list<Component *> m_children;

public:
    void add(Component *component) override;
    void remove(Component *component) override;
    bool isComposite() const override;

    std::string operation() const override;
};