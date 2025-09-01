/*!
 *  \file       Abstraction.cpp
 *  \brief      
 *  
 */


#include "Abstraction.hpp"
#include "Implementor.hpp"

#include "UnimplementedException.hpp"

Abstraction::Abstraction(Implementor *implementor) : m_implementor{implementor}
{
}

Abstraction::~Abstraction()
{
}

std::string Abstraction::Operation() const
{
    return std::string("Abstraction: Base operation with: \n") + m_implementor->OperationImpl();
}

void Abstraction::check(int num) const volatile
{
    (void)num;
    NOT_IMPLEMENTED_EXCEPTION();
    // UNIMPLEMENTED_EXCEPTION("Abstraction");
}