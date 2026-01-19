/*!
 *  \file       Client.hpp
 *  \brief
 *
 */


#pragma once

#include <string>

namespace dive_into_design_patterns
{
    class FlyweightFactory;

    class Client
    {
    public:
        static void addCarToPoliceDatabase(FlyweightFactory &ff,
                                           const std::string &plates,
                                           const std::string &owner,
                                           const std::string &brand,
                                           const std::string &model,
                                           const std::string &color);
    };
}
