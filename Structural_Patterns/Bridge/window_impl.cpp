/*!
 *  \file       window_impl.cpp
 *  \brief      
 *  
 */


#include "window_impl.hpp"

#include <cmath>
#include <iostream>

WindowImpl::WindowImpl()
{
}

XWindowImpl::XWindowImpl() : WindowImpl()
{
}

XWindowImpl::~XWindowImpl()
{
}

void XWindowImpl::deviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    int x = std::round(std::min(x0, x1));
    int y = std::round(std::min(y0, y1));
    int width = std::round(std::abs(x0 - x1));
    int height = std::round(std::abs(y0 - y1));

    XDrawRectangle(m_dpy, m_wndid, m_gc, x, y, width, height);
}

void XWindowImpl::XDrawRectangle(Display*, Drawable, GC, int, int, int, int)
{
    // TODO
}

void XWindowImpl::deviceBitmap(const char*, Coord, Coord)
{
    // TODO
}

void XWindowImpl::deviceText(const char*, Coord, Coord)
{
    // TODO
}

PMWindowImpl::PMWindowImpl() : m_hps{HPS{}}
{
}

PMWindowImpl::~PMWindowImpl()
{
}

void PMWindowImpl::deviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    Coord left = std::min(x0, x1);
    Coord right = std::max(x0, x1);
    Coord bottom = std::min(y0, y1);
    Coord top = std::max(y0, y1);

    POINTL points[4];
    points[0] = POINTL{left, top};
    points[1] = POINTL{right, top};;
    points[2] = POINTL{right, bottom};
    points[3] = POINTL{left, bottom};

    if ((GpiBeginPath(m_hps, 1L) == false) or 
        (GpiSetCurrentPosition(m_hps, &points[3]) == false) or
        (GpiPolyLine(m_hps, 4L, points) == GPI_ERROR) or 
        (GpiEndPath(m_hps) == false))
    {
        std::cerr << "Error occurs now." << std::endl;
    }
    else
    {
        GpiStrokePath(m_hps, 1L, 0L);
    }
}

void PMWindowImpl::deviceBitmap(const char*, Coord, Coord)
{
    // TODO
}

void PMWindowImpl::deviceText(const char*, Coord, Coord)
{
    // TODO
}

bool PMWindowImpl::GpiBeginPath(HPS /* hps */, long /* i */) const
{
    // TODO
    return bool{};
}

bool PMWindowImpl::GpiSetCurrentPosition(HPS /* hps */, POINTL* /* point */) const
{
    // TODO 
    return true;
}

int PMWindowImpl::GpiPolyLine(HPS /* hps */, long /* i */, POINTL* /* point */) const
{
    // TODO
    return ~GPI_ERROR;
}

bool PMWindowImpl::GpiEndPath(HPS /* hps */) const
{
    // TODO
    return true;
}

void PMWindowImpl::GpiStrokePath(HPS /* hps */, long, long)
{
    // TODO
}