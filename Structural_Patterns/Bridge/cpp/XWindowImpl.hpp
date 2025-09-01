/*!
 *  \file       XWindowImpl.hpp
 *  \brief      
 *  
 */


#pragma once

#include "WindowImpl.hpp"


class Display
{
};
class Drawable
{
};
class GC
{
};

class XWindowImpl : public WindowImpl
{
public:
    XWindowImpl();
    ~XWindowImpl();

public:
    void deviceRect(Coord, Coord, Coord, Coord) override;

    void implementTop() override;
    void implementBottom() override;
    void implementSetExtent(const Point&) override;
    void implementSetOrigin(const Point&) override;

    void deviceText(const char*, Coord, Coord) override;
    void deviceBitmap(const char*, Coord, Coord) override;

private:
    void drawXRectangle(Display*, Drawable, GC, int, int, int, int);

private:
    Display *m_display;
    Drawable m_win_id;  // Window ID
    GC m_gc;            // Window graphic context
};