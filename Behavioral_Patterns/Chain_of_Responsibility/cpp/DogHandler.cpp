/*!
 *  \file       DogHandler.cpp
 *  \brief      
 *  
 */


#include "DogHandler.hpp"


std::string DogHandler::handle(std::string request)
{
    if (request == "MeatBall")
    {
        return std::string("Dog: I will eat the ") + request + ".\n";
    }
    else
    {
        return AbstractHandler::handle(request);
    }
}