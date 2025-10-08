/*!
 *  \file       AbstractHandler.hpp
 *  \brief      
 *  
 */


#pragma once


#include "Handler.hpp"

class AbstractHandler : public Handler
{
private:
    Handler *m_next_handler;

public:
    AbstractHandler();

public:
    Handler* setNext(Handler *handler) override;
    std::string handle(std::string request) override;
};