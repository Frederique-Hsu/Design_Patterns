/*!
 *  \file       class_adapter.cpp
 *  \brief
 *
 */


#include "class_adapter.hpp"

#include <iostream>
#include <algorithm>

namespace class_adapter
{
std::string Target::request() const
{
    return std::string("Target: The default target's behaviour.");
}


std::string Adaptee::specificRequest() const
{
    return std::string("eetpadA fo ruoivaheb cificepS");
}


Adapter::Adapter() : Target(), Adaptee()
{
}


std::string Adapter::request() const
{
    std::string to_reverse = specificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    
    return std::string("Adapter: (TRANSLATED) " + to_reverse);
}


void Client::execute(const Target *target)
{
    std::cout << target->request() << std::endl;
}
}
