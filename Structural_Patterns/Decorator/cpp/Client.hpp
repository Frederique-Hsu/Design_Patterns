/*!
 *  \file       Client.hpp
 *  \brief      
 *  
 */


#pragma once

namespace dive_into_design_patterns
{
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
}
