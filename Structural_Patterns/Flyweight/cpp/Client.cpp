/*!
 *  \file       Client.cpp
 *  \brief
 *
 */


#include "Client.hpp"

#include "FlyweightFactory.hpp"
#include "UniqueState.hpp"

namespace dive_into_design_patterns
{
    void Client::addCarToPoliceDatabase(FlyweightFactory &ff,
                                        const std::string &plates,
                                        const std::string &owner,
                                        const std::string &brand,
                                        const std::string &model,
                                        const std::string &color)
    {
        std::cout << "Client: Adding a car to database:" << std::endl;
        const Flyweight &flyweight = ff.getFlyweight(SharedState(brand, model, color));
        flyweight.operation({owner, plates});
    }
}
