/*!
 *  \file       SquirrelHandler.hpp
 *  \brief      
 *  
 */


#pragma once


#include "AbstractHandler.hpp"


class SquirrelHandler : public AbstractHandler
{
public:
    std::string handle(std::string request) override;
};