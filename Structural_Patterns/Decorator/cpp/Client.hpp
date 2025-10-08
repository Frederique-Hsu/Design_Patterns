/*!
 *  \file       Client.hpp
 *  \brief      
 *  
 */


#pragma once

class Component;


/*!
 *  \class  Client
 *  \brief  The client code works with all objects using the Component interface.
 *          This way it can stay independent of the concrete classes of components it works with.
 */
class Client
{
public:
    static void execute(Component *component);
};