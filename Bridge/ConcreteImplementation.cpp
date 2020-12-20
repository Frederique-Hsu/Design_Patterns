#include "ConcreteImplementation.hpp"

std::string ConcreteImplementation_A::OperationImplementation() const
{
    return std::string("ConcreteImplementation_A: Here is the result on the platform A.\n");
}

std::string ConcreteImplementation_B::OperationImplementation() const
{
    return std::string("ConcreteImplementation_B: Here is the result on platform B.\n");
}