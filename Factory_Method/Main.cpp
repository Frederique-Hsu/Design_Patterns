/*!
 *  \file   Main.cpp
 *  \brief  This file implements the main() entry function.
 *  \author Frederique Hsu
 *  \date   Tue.    07 Dec. 2021
 */

#include "Factory_Method.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "App: Launched with the ConcreteCreator_PhoneFactory." << std::endl;
    Creator* phoneCreator = new ConcreteCreator_PhoneFactory();
    ClientCode(*phoneCreator);
    std::cout << "\n" << std::endl;

    std::cout << "App: Launched with ConcreteCreator_VehicleFactory." << std::endl;
    Creator* vehicleCreator = new ConcreteCreator_VehicleFactory();
    ClientCode(*vehicleCreator);
    std::cout << "\n" << std::endl;

    delete phoneCreator;
    delete vehicleCreator;

    return 0;
}