/*!
 *  \file       Client.hpp
 *  \brief      
 *  
 */


#pragma once

class Component;

class Client
{
public:
    static void execute(Component *component);
    static void execute(Component *component1, Component *component2);
};