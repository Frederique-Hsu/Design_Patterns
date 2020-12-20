#include "Abstration.hpp"
#include "Implementation.hpp"

Abstraction::Abstraction(Implementation* impl) : m_impl(impl)
{
}

Abstraction::~Abstraction()
{
}

std::string Abstraction::Operation() const
{
    return ("Abstraction: Base operation with:\n" + m_impl->OperationImplementation());
}
