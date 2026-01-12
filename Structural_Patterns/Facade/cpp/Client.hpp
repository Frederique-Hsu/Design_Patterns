/*!
 *  \file       Client.hpp
 *  \brief      
 *  
 */


#pragma once


namespace dive_into_design_patterns
{
    class Facade;
    
    class Client
    {
    public:
        static void execute(Facade *facade);
    };
}