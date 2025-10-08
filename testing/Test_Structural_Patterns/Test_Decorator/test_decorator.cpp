/*!
 *  \file       test_decorator.cpp
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include "Structural_Patterns/Decorator/cpp/ConcreteComponent.hpp"
#include "Structural_Patterns/Decorator/cpp/ConcreteDecorator.hpp"
#include "Structural_Patterns/Decorator/cpp/Client.hpp"

#include <iostream>
#include <memory>

TEST_CASE("UTester for Decorator Pattern", "[Decorator]")
{
    SECTION("Check how Decorator Pattern works")
    {
        Component *simple = new ConcreteComponent;
        std::cout << "Client: I have got a simple component: " << std::endl;

        Client::execute(simple);
        std::cout << "\n" << std::endl;
        delete simple;
    }

    SECTION("Check how decorators wrap not only simple components, but also other decorators as welll")
    {
        std::shared_ptr<Component> simple(new ConcreteComponent);
        std::shared_ptr<Component> decorator1(new ConcreteDecoratorA(simple.get()));
        std::shared_ptr<Component> decorator2(new ConcreteDecoratorB(decorator1.get()));
        
        std::cout << "Client: Now I have got a decorated component: " << std::endl;
        Client::execute(decorator2.get());
        std::cout << "\n" << std::endl;
    }
}