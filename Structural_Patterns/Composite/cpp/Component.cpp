/*!
 *  \file       Component.cpp
 *  \brief      
 *  
 */


#include "Component.hpp"


Component::~Component()
{
}

void Component::setParent(Component *parent)
{
    m_parent = parent;
}

Component* Component::getParent() const
{
    return m_parent;
}

/*!
 *  \remark     In some cases, it would be beneficial to define the child-management operations right in the base Component
 *              class. This way, you won't need to expose any concrete component classes to the Client code, even during
 *              the object tree assembly. The downsides is that these methods will be empty for the leaf-level components.
 */
void Component::add(Component *component)
{
    UNUSED(component);
}

void Component::remove(Component *component)
{
    UNUSED(component);
}

/*!
 *  \fn     isComposite
 *  \brief  You can provide a method that lets the client code figure out whether a component can bear children.
 */
bool Component::isComposite() const
{
    return false;
}