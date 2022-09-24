/*!
 *  \file   Return_Objects.cpp
 *  \brief  This file studies how to return objects from functions.
 *  
 */

#include "Return_Objects.hpp"

#include <iostream>

Foo::Foo(int n)
{
}

Foo::Foo(const Foo&)
{
    std::cout << "COPY Constructor!!!\n" << std::endl;
}

Foo make_foo(int n)
{
    return Foo{n};
}

std::unique_ptr<Foo> Make_Foo(int n)
{
    return std::make_unique<Foo>(n);
}