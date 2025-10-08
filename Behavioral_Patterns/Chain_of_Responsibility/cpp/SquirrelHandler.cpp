/*!
 *  \file       SquirrelHandler.cpp
 *  \brief      
 *  
 */


#include "SquirrelHandler.hpp"


std::string SquirrelHandler::handle(std::string request)
{
    if (request == "Nut")
    {
        return std::string("Squirrel: I will eat the ") + request + ".\n";
    }
    else
    {
        return AbstractHandler::handle(request);
    }
}