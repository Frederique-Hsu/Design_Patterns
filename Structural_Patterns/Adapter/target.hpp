/*!
 *  \file       target.hpp
 *  \brief      
 *  
 */


#pragma once


/*!
 *  \brief  Define the class for target
 */
class Controller
{
public:
    Controller();
    virtual ~Controller();
public:
    virtual void pathPlanning() = 0;
};