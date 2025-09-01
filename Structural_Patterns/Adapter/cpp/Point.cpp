/*!
 *  \file       Point.cpp
 *  \brief
 *
 */


#include "Point.hpp"

#include <cmath>

const Point Point::Zero(0, 0);


Point::Point(Coord x, Coord y) : m_x(x), m_y(y)
{
}

Point::Point(const Point &rhs) : m_x(rhs.m_x), m_y(rhs.m_y)
{
}

Point& Point::operator=(const Point &rhs)
{
    if (this != &rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
    }
    return *this;
}


Coord Point::X() const
{
    return m_x;
}

Coord Point::Y() const
{
    return m_y;
}

void Point::X(Coord x)
{
    m_x = x;
}

void Point::Y(Coord y)
{
    m_y = y;
}

Point& Point::operator+=(const Point &rhs)
{
    m_x += rhs.m_x;
    m_y += rhs.m_y;
    return *this;
}

Point& Point::operator-=(const Point &rhs)
{
    m_x -= rhs.m_x;
    m_y -= rhs.m_y;
    return *this;
}

Point& Point::operator*=(const Point &rhs)
{
    m_x *= rhs.m_x;
    m_y *= rhs.m_y;
    return *this;
}

Point& Point::operator/=(const Point &rhs)
{
    m_x /= rhs.m_x;
    m_y /= rhs.m_y;
    return *this;
}

Point Point::operator-()
{
    Point ret(*this);
    ret.m_x *= -1;
    ret.m_y *= -1;
    return ret;
}

Point operator+(const Point &lhs, const Point &rhs)
{
    Point point(lhs);
    point += rhs;
    return point;
}

Point operator-(const Point &lhs, const Point &rhs)
{
    Point point(lhs);
    point -= rhs;
    return point;
}

Point operator*(const Point &lhs, const Point &rhs)
{
    Point point(lhs);
    point *= rhs;
    return point;
}

Point operator/(const Point &lhs, const Point &rhs)
{
    Point point(lhs);
    point /= rhs;
    return point;
}

bool operator==(const Point &lhs, const Point &rhs)
{
    return (std::fabs(lhs.m_x - rhs.m_x) <= 1.0e-3) and
           (std::fabs(lhs.m_y - rhs.m_y) <= 1.0e-3);
}

bool operator!=(const Point &lhs, const Point &rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
    out << "(" << point.m_x << ", " << point.m_y << ")";
    return out;
}

std::istream& operator>>(std::istream &in, Point &point)
{
    in >> point.m_x >> point.m_y;
    if (!in)
    {
        point = Point();
    }
    return in;
}
