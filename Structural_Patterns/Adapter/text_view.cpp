/*!
 *  \file       text_view.cpp
 *  \brief      
 *  
 */


#include "text_view.hpp"

TextView::TextView() : m_x{1.0}, m_y{2.0}, m_width{3.0}, m_height{4.0}
{
}

TextView::~TextView()
{
}

void TextView::getOrigin(Coord& x, Coord& y) const
{
    x = m_x;
    y = m_y;
}

void TextView::getExtend(Coord& width, Coord& height) const
{
    width = m_width;
    height = m_height;
}

bool TextView::isEmpty() const
{
    return (m_width == 0 or m_height == 0);
}