/*!
 *  \file       adaptee.hpp
 *  \brief      
 *  
 */


#pragma once

/*!
 *  \brief  Define the class for adaptee
 */
class DxfParser
{
public:
    DxfParser();
public:
    void parseFile();
};


class PathPlanner
{
public:
    PathPlanner();
public:
    void calculate();
};