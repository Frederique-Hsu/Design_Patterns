/*!
 *  \file       TextView.cpp
 *  \brief
 *
 */


#include "TextView.hpp"

#include <cmath>

TextView::TextView() : m_x{1.0}, m_y{2.0}, m_width{3.0}, m_height{4.0}
{
}

void TextView::getOrigin(Coord &x, Coord &y) const
{
    x = m_x;
    y = m_y;
}

void TextView::getExtend(Coord &width, Coord &height) const
{
    width = m_width;
    height = m_height;
}

bool TextView::isEmpty() const
{
    return (std::fabs(m_width) <= 1.0e-3) or (std::fabs(m_height) <= 1.0e-3);
}
