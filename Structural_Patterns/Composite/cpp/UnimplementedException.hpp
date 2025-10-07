/*!
 *  \file       UnimplementedException.hpp
 *  \brief      
 *  
 */


#pragma once


#include <stdexcept>
#include <string>


class UnimplementedException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;    // 直接继承基类的构造函数
};

/*============================================================================*/

#define UNIMPLEMENTED_EXCEPTION(class_name)                     \
    throw UnimplementedException(                               \
        "Function \"" + std::string(#class_name) + "::" +       \
        __FUNCTION__ + "\" in " + __FILE__ + ":" +              \
        std::to_string(__LINE__) + "\n---> has not yet been implemented.")

/*============================================================================*/

#define NOT_IMPLEMENTED_EXCEPTION()                                     \
    throw UnimplementedException(                                       \
        "Function \"" + std::string(__PRETTY_FUNCTION__) +              \
        "\" in file " + __FILE__ +  ":" + std::to_string(__LINE__) +    \
        "\n---> has not yet been implemented.")

/*============================================================================*/