/*!
 *  \file       WindowImpl.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Coord.hpp"

class Point;


class WindowImpl
{
public:
    virtual ~WindowImpl() = default;

public:
    virtual void implementTop() = 0;
    virtual void implementBottom() = 0;
    virtual void implementSetExtent(const Point&) = 0;
    virtual void implementSetOrigin(const Point&) = 0;

    virtual void deviceRect(Coord, Coord, Coord, Coord) = 0;
    virtual void deviceText(const char*, Coord, Coord) = 0;
    virtual void deviceBitmap(const char*, Coord, Coord) = 0;

protected:
    WindowImpl() = default;
};

enum WindowType
{
    X_WINDOW,
    PRESENTATION_MANAGER_WINDOW
};