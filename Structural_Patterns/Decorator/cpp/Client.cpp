/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"
#include "Component.hpp"

#include <iostream>

namespace dive_into_design_patterns
{
void Client::execute(Component *component)
{
    std::cout << "RESULT: " << component->operation() << std::endl;
}
}
