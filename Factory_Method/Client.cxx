/* File name    : Client.cxx
 *
 */

#include <iostream>
#include <memory>

#include "Creator.hh"
#include "ConcreteCreator.hpp"

void ClientCode(const Creator& creator);

int main(int, char**)
{
    std::cout << "App: Launched with the ConcreteCreator: Phone Plant" << std::endl;
    Creator* phonecreator = new ConcreteCreator_PhonePlant();
    ClientCode(*phonecreator);
    std::cout << "\n" << std::endl;

    std::cout << "App: Launched with the ConcreteCreator: Vehicle Plant" << std::endl;
    std::shared_ptr<Creator> vehiclecreator(new ConcreteCreator_VehiclePlant());
    ClientCode(*vehiclecreator);

    delete  phonecreator;
    return 0;
}

void ClientCode(const Creator& creator)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
}
