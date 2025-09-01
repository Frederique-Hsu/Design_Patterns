/*!
 *  \file       XWindowImpl.cpp
 *  \brief      
 *  
 */


#include "XWindowImpl.hpp"

#include "UnimplementedException.hpp"

#include <cmath>

XWindowImpl::XWindowImpl() : m_display{new Display}, m_win_id{Drawable{}}, m_gc{GC{}}
{
}

XWindowImpl::~XWindowImpl()
{
    if (m_display != nullptr)
    {
        delete m_display;
    }
}

void XWindowImpl::deviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    int x = std::round(std::min(x0, x1));
    int y = std::round(std::min(y0, y1));
    int width = std::round(std::abs(x0 - x1));
    int height = std::round(std::abs(y0 - y1));
    drawXRectangle(m_display, m_win_id, m_gc, x, y, width, height);
}

void XWindowImpl::drawXRectangle(Display *, Drawable, GC, int, int, int, int)
{
    /*!
     *  \todo       Implement this method here in the future.
     */
}

void XWindowImpl::implementTop()
{
    NOT_IMPLEMENTED_EXCEPTION();
}

void XWindowImpl::implementBottom()
{
}

void XWindowImpl::implementSetExtent(const Point&)
{
}

void XWindowImpl::implementSetOrigin(const Point&)
{
}

void XWindowImpl::deviceText(const char*, Coord, Coord)
{
}

void XWindowImpl::deviceBitmap(const char*, Coord, Coord)
{
}