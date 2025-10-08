/*!
 *  \file       AbstractHandler.cpp
 *  \brief      
 *  
 */


#include "AbstractHandler.hpp"

AbstractHandler::AbstractHandler() : m_next_handler{nullptr}
{
}

Handler* AbstractHandler::setNext(Handler *handler)
{
    m_next_handler = handler;
    return handler;
}

std::string AbstractHandler::handle(std::string request)
{
    if (m_next_handler != nullptr)
    {
        return m_next_handler->handle(request);
    }
    return std::string{};
}