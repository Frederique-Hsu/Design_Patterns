/*!
 *  \file       test_flyweight.cpp
 *  \brief      
 *  
 */

#include <catch2/catch_test_macros.hpp>

#include "Structural_Patterns/Flyweight/cpp/FlyweightFactory.hpp"
#include "Structural_Patterns/Flyweight/cpp/SharedState.hpp"
#include "Structural_Patterns/Flyweight/cpp/Client.hpp"

#include "testing/Test_Structural_Patterns/finalize.hpp"
#include "testing/Test_Structural_Patterns/finalize.cpp"


TEST_CASE("UTester for Flyweight Pattern", "[Flyweight]")
{
    SECTION("Check how Flyweight Pattern works")
    {
        using namespace dive_into_design_patterns;
        
        FlyweightFactory *factory = new FlyweightFactory({SharedState("Chevrolet", "Camaro2018", "pink"),
                                                          SharedState("Mercedes Benz", "C300", "black"),
                                                          {"BMW", "M5", "red"},
                                                          SharedState("BMW", "X6", "white")});
        auto deleter = finalize([&factory]() {
            if (factory)
            {
                delete factory;
                factory = nullptr;
            }
        });
        factory->listFlyweights();
        std::cout << "\n" << std::endl;
        
        Client::addCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
        std::cout << std::endl;
        Client::addCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "X1", "blue");
        
        std::cout << "\n" << std::endl;
        factory->listFlyweights();
    }
}
