/*!
 *  \file       test_facade.cpp
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include <memory>

#include "Structural_Patterns/Facade/cpp/Subsystem.hpp"
#include "Structural_Patterns/Facade/cpp/Facade.hpp"
#include "Structural_Patterns/Facade/cpp/Client.hpp"


TEST_CASE("UTester for Facade Pattern", "[Facade]")
{
    SECTION("Check how Facade Pattern works")
    {
        using namespace dive_into_design_patterns;

        Subsystem1 *subsystem1 = new Subsystem1();
        Subsystem2 *subsystem2 = new Subsystem2();

        std::unique_ptr<Facade> facade = std::make_unique<Facade>(subsystem1, subsystem2);
        Client::execute(facade.get());
    }
}