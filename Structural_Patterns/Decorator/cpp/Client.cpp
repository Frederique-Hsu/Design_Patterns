/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"
#include "Component.hpp"

#include <iostream>

void Client::execute(Component *component)
{
    std::cout << "RESULT: " << component->operation() << std::endl;
}