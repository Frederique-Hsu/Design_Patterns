/* File name    : main.cpp
 * 
 */

#include <iostream>

#include "Abstration.hpp"
#include "ConcreteImplementation.hpp"
#include "ExtendedAbstraction.hpp"

void ClientCode(const Abstraction& abstract);

int main(int argc, char* argv[])
{
    Implementation* pimpl = new ConcreteImplementation_A;
    Abstraction* pabstract = new Abstraction(pimpl);

    ClientCode(*pabstract);
    std::cout << "\n" << std::endl;

    delete pimpl;
    delete pabstract;

    pimpl = new ConcreteImplementation_B;
    pabstract = new ExtendedAbstraction(pimpl);
    ClientCode(*pabstract);
    std::cout << "\n" << std::endl;

    delete pimpl;
    delete pabstract;

    return 0;
}

void ClientCode(const Abstraction& abstract)
{
    std::cout << abstract.Operation() << std::endl;
}
