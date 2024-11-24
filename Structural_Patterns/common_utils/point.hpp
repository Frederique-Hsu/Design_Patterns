/*!
 *  \file       point.hpp
 *  \brief      
 *  
 */


#pragma once

#include "coord.hpp"

class Point
{
public:
    Point(Coord x = 0.0, Coord y = 0.0);
private:
    Coord m_x;
    Coord m_y;
};