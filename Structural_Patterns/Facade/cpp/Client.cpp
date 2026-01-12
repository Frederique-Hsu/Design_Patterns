/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"

#include <iostream>

#include "Facade.hpp"


namespace dive_into_design_patterns
{
    void Client::execute(Facade *facade)
    {
        std::cout << facade->operation() << std::endl;
    }
}