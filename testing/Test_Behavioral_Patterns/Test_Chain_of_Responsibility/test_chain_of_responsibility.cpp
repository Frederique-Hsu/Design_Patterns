/*!
 *  \file       test_chain_of_responsibility.cpp
 *  \brief      
 *  
 */


#include <gtest/gtest.h>

#include "Behavioral_Patterns/Chain_of_Responsibility/cpp/MonkeyHandler.hpp"
#include "Behavioral_Patterns/Chain_of_Responsibility/cpp/SquirrelHandler.hpp"
#include "Behavioral_Patterns/Chain_of_Responsibility/cpp/DogHandler.hpp"
#include "Behavioral_Patterns/Chain_of_Responsibility/cpp/Client.hpp"

TEST(UTester4ChainOfResponsibility, CheckHowChainOfResponsibilityPatternWorks)
{
    std::shared_ptr<MonkeyHandler> monkey(new MonkeyHandler);
    std::shared_ptr<SquirrelHandler> squirrel(new SquirrelHandler);
    std::shared_ptr<DogHandler> dog(new DogHandler);

    monkey->setNext(squirrel.get())->setNext(dog.get());

    std::cout << "Chain:  Monkey --> Squirrel --> Dog" << std::endl;
    Client::execute(*monkey);
    std::cout << "\n" << std::endl;

    std::cout << "Subchain: Squirrel --> Dog" << std::endl;
    Client::execute(*squirrel);
}