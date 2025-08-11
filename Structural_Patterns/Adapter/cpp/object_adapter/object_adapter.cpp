/*!
 *  \file       object_adapter.cpp
 *  \brief
 *
 */



#include "object_adapter.hpp"

#include <iostream>

namespace object_adapter
{
std::string Target::request() const
{
    return std::string("Target: The default target's behaviour.");
}


std::string Adaptee::specificRequest() const
{
    return std::string(".eetpadA eht fo ruoivaheb cificepS");
}


Adapter::Adapter(Adaptee *adaptee) : m_adaptee(adaptee)
{
}


std::string Adapter::request() const
{
    std::string to_reverse = m_adaptee->specificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    
    return std::string("Adapter: (TRANSLATED) " + to_reverse);
}


/*!
 *  \fn     execute
 *  \brief  The client code supports all classes that follow the Target's interface.
 */
void Client::execute(const Target *target)
{
    std::cout << target->request() << std::endl;
}
}
