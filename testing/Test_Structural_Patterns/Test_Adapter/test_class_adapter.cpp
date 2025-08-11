/*!
 *  \file       test_class_adapter.cpp
 *  \brief
 *
 */


#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "Structural_Patterns/Adapter/cpp/class_adapter/class_adapter.hpp"

#include "testing/Test_Structural_Patterns/finalize.hpp"
#include "testing/Test_Structural_Patterns/finalize.cpp"


TEST_CASE("UTester for Adapter Pattern", "[class-adapter]")
{
    SECTION("Check how class-adapter pattern works")
    {
        using namespace class_adapter;
        
        std::cout << "Client: I can work just fine with the Target objects: " << std::endl;

        Target* target = new Target;

        Client clinet;
        clinet.execute(target);
        std::cout << std::endl;

        Adaptee *adaptee = new Adaptee;
        std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:" << std::endl;
        std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;
        std::cout << "\n" << std::endl;

        std::cout << "Client: But I can work with it via a Adapter: " << std::endl;
        Adapter* adapter = new Adapter;

        auto deleter = finalize([&target, &adaptee, &adapter]() {
            delete target;
            delete adaptee;
            delete adapter;
        });

        clinet.execute(adapter);
        std::cout << std::string(100, '=') << "\n" << std::endl;
    }
}
