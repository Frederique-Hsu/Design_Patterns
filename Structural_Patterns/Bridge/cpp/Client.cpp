/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"

#include "Abstraction.hpp"

#include <iostream>

void Client::execute(const Abstraction& abstraction)
{
    std::cout << abstraction.Operation() << std::endl;
}