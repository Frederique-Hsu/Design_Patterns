/*!
 *  \file       ConcreteImplementor.cpp
 *  \brief      
 *  
 */


#include "ConcreteImplementor.hpp"


std::string ConcreteImplementorA::OperationImpl() const
{
    return std::string("ConcreteImplementorA: Here is the result on the platform A.\n");
}


std::string ConcreteImplementorB::OperationImpl() const
{
    return std::string("ConcreteImplementorB: Here is the result on the platform B.\n");
}