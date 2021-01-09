#include "Creator.hh"
#include "Product.h++"

Creator::~Creator()
{
}

std::string Creator::SomeOperation() const
{
    Product* product = FactoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
}