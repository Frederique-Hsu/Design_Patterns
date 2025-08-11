/*!
 *  \file       Point.hpp
 *  \brief
 *
 */


#pragma once


#include "Coord.hpp"

#include <iostream>

class Point
{
public:
    static const Point Zero;

    friend Point operator+(const Point&, const Point&);
    friend Point operator-(const Point&, const Point&);
    friend Point operator*(const Point&, const Point&);
    friend Point operator/(const Point&, const Point&);

    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);

    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend std::istream& operator>>(std::istream&,       Point&);

public:
    Point(Coord x = 0.0, Coord y = 0.0);
    Point(const Point &rhs);
    Point& operator=(const Point &rhs);

private:
    Coord m_x;
    Coord m_y;

public:
    Coord X() const;
    Coord Y() const;
    void X(Coord x);
    void Y(Coord y);

    Point& operator+=(const Point&);
    Point& operator-=(const Point&);
    Point& operator*=(const Point&);
    Point& operator/=(const Point&);

    Point operator-();

};
