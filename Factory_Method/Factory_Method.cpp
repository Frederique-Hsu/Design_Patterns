/*!
 *  \file   Factory_Method.cpp
 *  \brief  Demonstrate how the Factory Method pattern work.
 *  \author Frederique Hsu
 *  \date   Tue.    07 Dec. 2021
 * 
 */

#include "Factory_Method.hpp"

#include <iostream>

Product::~Product()
{
}

std::string ConcreteProduct_PhoneAntenna::Operation() const
{
    return "{Result of the ConcreteProduct_PhoneAntenna}";
}

std::string ConcreteProduct_VehicleAntenna::Operation() const
{
    return "{Result of the ConcreteProduct_VehicleAntenna}";
}

Creator::~Creator()
{
}

std::string Creator::SomeOperation() const
{
    Product* product = this->FactoryMethod();
    std::string result = "Creator: the same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
}

Product* ConcreteCreator_PhoneFactory::FactoryMethod() const
{
    return (new ConcreteProduct_PhoneAntenna());
}

Product* ConcreteCreator_VehicleFactory::FactoryMethod() const
{
    return (new ConcreteProduct_VehicleAntenna);
}

void ClientCode(const Creator& creator)
{
    std::cout << "Client: I am not aware of the creator's class, but it still works\n"
              << creator.SomeOperation()
              << std::endl;
}