/*!
 *  \file       point.cpp
 *  \brief      
 *  
 */


#include "point.hpp"


Point::Point(Coord x, Coord y) : m_x{x}, m_y{y}
{
}

Coord Point::X() const
{
    return m_x;
}

Coord Point::Y() const
{
    return m_y;
}

void Point::setX(Coord x)
{
    m_x = x;
}

void Point::setY(Coord y)
{
    m_y = y;
}