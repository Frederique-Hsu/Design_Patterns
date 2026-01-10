/*!
 *  \file       test_decorator.cpp
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <memory>

#include "Structural_Patterns/Decorator/cpp/ConcreteComponent.hpp"
#include "Structural_Patterns/Decorator/cpp/ConcreteDecorator.hpp"
#include "Structural_Patterns/Decorator/cpp/Client.hpp"
#include "Structural_Patterns/Decorator/cpp/Window.hpp"
#include "Structural_Patterns/Decorator/cpp/TextView.hpp"
#include "Structural_Patterns/Decorator/cpp/BorderDecorator.hpp"
#include "Structural_Patterns/Decorator/cpp/ScrollDecorator.hpp"


TEST_CASE("UTester for Decorator Pattern", "[Decorator]")
{
    SECTION("Check how Decorator Pattern works")
    {
        using namespace dive_into_design_patterns;

        Component *simple = new ConcreteComponent;
        std::cout << "Client: I have got a simple component: " << std::endl;

        Client::execute(simple);
        std::cout << "\n" << std::endl;
        delete simple;
    }

    SECTION("Check how decorators wrap not only simple components, but also other decorators as welll")
    {
        using namespace dive_into_design_patterns;

        std::shared_ptr<Component> simple(new ConcreteComponent);
        std::shared_ptr<Component> decorator1(new ConcreteDecoratorA(simple.get()));
        std::shared_ptr<Component> decorator2(new ConcreteDecoratorB(decorator1.get()));
        
        std::cout << "Client: Now I have got a decorated component: " << std::endl;
        Client::execute(decorator2.get());
        std::cout << "\n" << std::endl;
    }

    SECTION("Validate how decorator pattern works, when user want to build a text view")
    {
        using namespace gof_design_patterns;

        std::unique_ptr<Window> window(new Window);
        std::unique_ptr<TextView> text_view = std::make_unique<TextView>();

        window->setContents(new BorderDecorator(new ScrollDecorator(text_view.get()), 1));
    }
}
