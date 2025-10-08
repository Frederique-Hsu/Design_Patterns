/*!
 *  \file       DogHandler.hpp
 *  \brief      
 *  
 */


#pragma once

#include "AbstractHandler.hpp"

class DogHandler : public AbstractHandler
{
public:
    std::string handle(std::string request) override;
};