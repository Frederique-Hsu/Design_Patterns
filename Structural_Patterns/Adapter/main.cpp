/***************************************************************************************************
 * Project name     : Adapter
 * Description      : Study the Adapter pattern, make a good research how to implement this pattern,
 *                  : and how it works.
 * =================================================================================================
 * File name        : main.cpp
 * Description      : This file implements the main() entry function for current project.
 * Creator          : Frederique Hsu
 * Creation date    : Sun.  13 Dec. 2020
 * Copyright(C)     2020    All rights reserved.
 ***************************************************************************************************/

#include <iostream>

#include "Target.hpp"
#include "Adaptee.hpp"
#include "Adapter.hpp"
#include "Multi_Inheritance_Adapter.hpp"

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target* target)
{
    std::cout << target->Request();
}

int main(int argc, char* argv[])
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target* target = new Target;
    ClientCode(target);
    std::cout << "\n" << std::endl;

    Adaptee* adaptee = new Adaptee;
    std::cout << "Client: The Adaptee has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n" << std::endl;

    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n" << std::endl;

    std::cout<<  "Client: I can also work with it via the Multiple Inheritance Adapter:\n";
    MIAdapter* miadapter = new MIAdapter;
    ClientCode(miadapter);
    std::cout << "\n" << std::endl;

    delete target;
    delete adapter;
    delete adaptee;

    return 0;
}
