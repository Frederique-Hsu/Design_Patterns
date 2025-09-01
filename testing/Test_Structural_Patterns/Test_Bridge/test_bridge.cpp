/*!
 *  \file       test_bridge.cpp
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include "Structural_Patterns/Bridge/cpp/Implementor.hpp"
#include "Structural_Patterns/Bridge/cpp/ConcreteImplementor.hpp"
#include "Structural_Patterns/Bridge/cpp/Abstraction.hpp"
#include "Structural_Patterns/Bridge/cpp/Client.hpp"
#include "Structural_Patterns/Bridge/cpp/RefinedAbstraction.hpp"

#include "testing/Test_Structural_Patterns/finalize.hpp"
#include "testing/Test_Structural_Patterns/finalize.cpp"

#include <iostream>

TEST_CASE("UTester for Bridge Pattern", "[Bridge]")
{
    SECTION("Check how Bridge pattern works")
    {
        Implementor *implementor = new ConcreteImplementorA;
        Abstraction *abstraction = new Abstraction(implementor);
        Client::execute(*abstraction);
        delete implementor;
        delete abstraction;

        implementor = new ConcreteImplementorB;
        abstraction = new RefinedAbstraction(implementor);
        auto deleter = finalize([&implementor, &abstraction]() {
            delete implementor;
            delete abstraction;
        });
        Client::execute(*abstraction);
        try
        {
            abstraction->check(5);
        }
        catch (const std::exception& e)
        {
            std::cout << "Encounter exception: " << e.what() << std::endl;
        }
    }
}