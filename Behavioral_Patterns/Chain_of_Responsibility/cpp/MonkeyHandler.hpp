/*!
 *  \file       MonkeyHandler.hpp
 *  \brief      
 *  
 */


#pragma once


#include "AbstractHandler.hpp"

class MonkeyHandler : public AbstractHandler
{
public:
    std::string handle(std::string request) override;
};