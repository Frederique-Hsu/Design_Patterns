#include "ExtendedAbstraction.hpp"
#include "Implementation.hpp"


ExtendedAbstraction::ExtendedAbstraction(Implementation* impl) : Abstraction(impl)
{
}

std::string ExtendedAbstraction::Operation() const
{
    return ("ExtendedAbstraction: Extended operation with: \n" + m_impl->OperationImplementation());
}
