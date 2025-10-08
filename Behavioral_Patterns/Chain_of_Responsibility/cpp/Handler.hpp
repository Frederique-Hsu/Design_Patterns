/*!
 *  \file       Handler.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>


class Handler
{
public:
    virtual ~Handler() = default;
    
public:
    virtual Handler* setNext(Handler *handler) = 0;
    virtual std::string handle(std::string request) = 0;
};