#include "ConcreteProduct.h++"

#include <iostream>

std::string ConcreteProduct_PhoneAntenna::Operation() const
{
    return "{Result of the concrete product: Phone Antenna}";
}

std::string ConcreteProduct_VehicleAntenna::Operation() const
{
    return "{Result of the concrete product: Vehicle Antenna}";
}