/*!
 *  \file       object_adapter.hpp
 *  \brief
 *
 */


#pragma once

#include <string>

namespace object_adapter
{
/*!
 *  \class      Target
 *  \brief      This Target defines the domain-specific interface used by the client code
 */
class Target
{
public:
    virtual ~Target() = default;
    
public:
    virtual std::string request() const;
};


/*!
 *  \class      Adaptee
 *  \brief      The \a Adaptee contains some useful behaviour, but its interface is incompatible with the
 *              existing client code. The Adaptee needs some adaptation before the client code can use it.
 */
class Adaptee
{
public:
    std::string specificRequest() const;
};


/*!
 *  \class      Adapter
 *  \brief      The Adapter makes the Adaptee's interface compatible with the Target's interface.
 */
class Adapter : public Target
{
public:
    explicit Adapter(Adaptee *adaptee);
    
private:
    Adaptee *m_adaptee;
    
public:
    std::string request() const override;
};


class Client
{
public:
    static void execute(const Target *target);
};
}
