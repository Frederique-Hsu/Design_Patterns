/*!
 *  \file       user_exception.hpp
 *  \brief      
 *  
 */


#pragma once

#include <stdexcept>

class UnimplementedException : public std::runtime_error
{
public:
    UnimplementedException(const std::string& what_arg);
    UnimplementedException(const char* what_arg);
    UnimplementedException(const UnimplementedException& rhs) noexcept = default;
    UnimplementedException& operator=(const UnimplementedException& rhs) noexcept = default;
    ~UnimplementedException() noexcept = default;
public:
    virtual const char* what() const noexcept override;
};