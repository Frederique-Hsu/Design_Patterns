/*!
 *  \file       Composite.cpp
 *  \brief      
 *  
 */


#include "Composite.hpp"


/*!
 *  \note   A composite object can add or remove other components (both simple or complex) to or from its child list.
 */
void Composite::add(Component *component)
{
    m_children.push_back(component);
    component->setParent(this);
}

void Composite::remove(Component *component)
{
    m_children.remove(component);
    component->setParent(nullptr);
}

bool Composite::isComposite() const
{
    return true;
}

/*!
 *  \attention  The Composite executes its primary logic in a particular way.
 *              It traverses recursively through all its children, collecting and summarizing their results.
 *              Since the composite's children pass these calls to their children, and so forth,
 *              the whole object tree is traversed as a result.
 */
std::string Composite::operation() const
{
    std::string result;

    for (const Component *comp : m_children)
    {
        /*!
         *  \note   This loop will traverse to access each comp,
         *          if comp is Composite* object, it will call Composite::operation() recursively,
         *          because Composite* object has the m_children of list<Component *> container
         * 
         *          if comp is Leaf* object, it will then call Leaf::operation(), but not recursively,
         *          because Leaf* object has no any children, it is at the bottom.
         */
        if (comp == m_children.back())
        {
            result += comp->operation();
        }
        else
        {
            result += comp->operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}
