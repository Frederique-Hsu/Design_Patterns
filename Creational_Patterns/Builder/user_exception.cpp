/*!
 *  \file       user_exception.cpp
 *  \brief      
 *  
 */


#include "user_exception.hpp"

UnimplementedException::UnimplementedException(const std::string& what_arg) : std::runtime_error(what_arg)
{
}

UnimplementedException::UnimplementedException(const char* what_arg) : std::runtime_error(what_arg)
{
}

const char* UnimplementedException::what() const noexcept
{
    std::string error_mesg(std::runtime_error::what());
    
    error_mesg += " has not yet been implemented.";
    return error_mesg.c_str();
}