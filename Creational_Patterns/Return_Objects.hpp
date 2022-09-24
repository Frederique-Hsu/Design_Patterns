/*!
 *  \file   Return_Objects.hpp
 *  \brief  This file studies how to return objects from functions.
 *  
 */

#pragma once

#include <memory>

class Foo
{
public:
    Foo(int n);
    Foo(const Foo&);
};

Foo make_foo(int n);

std::unique_ptr<Foo> Make_Foo(int n);