/*!
 *  \file       PresentationManagerWindowImpl.cpp
 *  \brief      
 *  
 */


#include "PresentationManagerWindowImpl.hpp"

#include <cmath>

#include <stdexcept>

#define UNUSED(arg)     (void)arg

constexpr const int GPI_ERROR = 1;

PresentationManagerWindowImpl::PresentationManagerWindowImpl() : m_hps{HPS{}}
{
}

void PresentationManagerWindowImpl::deviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    Coord left = std::min(x0, x1);
    Coord right = std::max(x0, x1);
    Coord bottom = std::min(y0, y1);
    Coord top = std::max(y0, y1);

    PPOINTL points[4];
    points[0].x = left;     points[0].y = top;
    points[1].x = right;    points[1].y = top;
    points[2].x = right;    points[2].y = bottom;
    points[3].x = left;     points[3].y = bottom;

    if ((GpiBeginPath(m_hps, 1L) == false) || 
        (GpiSetCurrentPosition(m_hps, &points[3]) == false) ||
        (GpiPolyLine(m_hps, 4L, points) == GPI_ERROR) ||
        (GpiEndPath(m_hps) == false))
    {
        throw std::runtime_error("Report error.");
    }
    else
    {
        GpiStrokePath(m_hps, 1L, 0L);
    }
}

bool PresentationManagerWindowImpl::GpiBeginPath(HPS hps, long i) const
{
    UNUSED(hps);
    UNUSED(i);

    /*!
     *  \todo       Implement this method here in the future.
     */
    return true;
}
    
bool PresentationManagerWindowImpl::GpiSetCurrentPosition(HPS hps, PPOINTL *p) const
{
    UNUSED(hps);
    UNUSED(p);

    /*!
     *  \todo       Implement this method here in the future.
     */
    return true;
}
    
int  PresentationManagerWindowImpl::GpiPolyLine(HPS hps, long i, PPOINTL *p) const
{
    UNUSED(hps);
    UNUSED(i);
    UNUSED(p);

    /*!
     *  \todo       Implement this method here in the future.
     */
    return 1;
}
    
bool PresentationManagerWindowImpl::GpiEndPath(HPS hps) const
{
    UNUSED(hps);

    /*!
     *  \todo       Implement this method here in the future.
     */
    return true;
}
    
void PresentationManagerWindowImpl::GpiStrokePath(HPS hps, long, long)
{
    UNUSED(hps);

    /*!
     *  \todo       Implement this method here in the future.
     */
    return;
}

void PresentationManagerWindowImpl::implementTop()
{
}

void PresentationManagerWindowImpl::implementBottom()
{
}

void PresentationManagerWindowImpl::implementSetExtent(const Point&)
{
}

void PresentationManagerWindowImpl::implementSetOrigin(const Point&)
{
}

void PresentationManagerWindowImpl::deviceText(const char*, Coord, Coord)
{
}

void PresentationManagerWindowImpl::deviceBitmap(const char*, Coord, Coord)
{
}