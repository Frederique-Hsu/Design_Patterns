/*!
 *  \file       class_adapter.hpp
 *  \brief
 *
 */


#pragma once


#include <string>

namespace class_adapter
{
class Target
{
public:
    virtual ~Target() = default;
    
public:
    virtual std::string request() const;
};


class Adaptee
{
public:
    std::string specificRequest() const;
};


class Adapter : public Target, public Adaptee
{
public:
    Adapter();
    
public:
    std::string request() const override;
};


class Client
{
public:
    void execute(const Target* target);
};
}
