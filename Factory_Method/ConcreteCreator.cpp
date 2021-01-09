#include "ConcreteCreator.hpp"
#include "Product.h++"
#include "ConcreteProduct.h++"

Product* ConcreteCreator_PhonePlant::FactoryMethod() const
{
    return (new ConcreteProduct_PhoneAntenna());
}

Product* ConcreteCreator_VehiclePlant::FactoryMethod() const
{
    return (new ConcreteProduct_VehicleAntenna());
}
