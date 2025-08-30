/*!
 *  \file       RefinedAbstraction.cpp
 *  \brief      
 *  
 */


#include "RefinedAbstraction.hpp"

#include "Implementor.hpp"


RefinedAbstraction::RefinedAbstraction(Implementor *implementor) : Abstraction(implementor)
{
}

std::string RefinedAbstraction::Operation() const
{
    return std::string("RefinedAbstraction: operation with: \n") + m_implementor->OperationImpl();
}