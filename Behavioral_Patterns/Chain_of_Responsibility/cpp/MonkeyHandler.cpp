/*!
 *  \file       MonkeyHandler.cpp
 *  \brief      
 *  
 */


#include "MonkeyHandler.hpp"


std::string MonkeyHandler::handle(std::string request)
{
    if (request == "Banana")
    {
        return std::string("Monkey: I will eat the ") + request + ".\n";
    }
    else
    {
        return AbstractHandler::handle(request);
    }
}