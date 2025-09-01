/*!
 *  \file       test_object_adapter.cpp
 *  \brief
 *
 */


#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "Structural_Patterns/Adapter/cpp/object_adapter/object_adapter.hpp"

TEST_CASE("UTester for Adapter Pattern", "[object-adapter]")
{
    SECTION("Check how object-adapter pattern works")
    {
        using namespace object_adapter;
        
        std::cout << "Client: I can work just fine with the Target objects:" << std::endl;

        Target *target = new Target;
        Client::execute(target);

        Adaptee *adaptee = new Adaptee;
        std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:" << std::endl;
        std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;

        std::cout << "Client: But I can work with it via the Adapter: " << std::endl;
        Adapter *adapter = new Adapter(adaptee);
        Client::execute(adapter);
        std::cout << std::string(100, '=') << "\n" << std::endl;

        delete target;
        delete adaptee;
        delete adapter;
    }
}
