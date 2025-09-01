/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"

#include "Component.hpp"

#include <iostream>

/*!
 *  \brief  The client works with all of the components via the base interface
 */
void Client::execute(Component *component)
{
    std::cout << "RESULT: " << component->operation() << std::endl;
}


/*!
 *  \details    Thanks to the fact that the child-management operations are declared in the base Component class,
 *              the client can work with any component, simple or complex, without depending on their concrete classes.
 */
void Client::execute(Component *component1, Component *component2)
{
    if (component1->isComposite())
    {
        component1->add(component2);
    }
    std::cout << "RESULT: " << component1->operation() << std::endl;
}