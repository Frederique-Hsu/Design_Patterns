/*!
 *  \file       window_impl.hpp
 *  \brief      
 *  
 */


#pragma once

#include "../common_utils/coord.hpp"

class Point;

class WindowImpl
{
public:
    virtual ~WindowImpl() = default;
protected:
    WindowImpl();
public:
    #if false
    virtual void implTop();
    virtual void implBottom();
    virtual void implSetExtent(const Point&);
    virtual void implSetOrigin(const Point&);
    #endif

    virtual void deviceRect(Coord, Coord, Coord, Coord) = 0;
    virtual void deviceText(const char*, Coord, Coord) = 0;
    virtual void deviceBitmap(const char*, Coord, Coord) = 0;
};



class XWindowImpl : public WindowImpl
{
public:
    XWindowImpl();
    ~XWindowImpl();
private:
    // lots of X-Window system-specific state, including:
    class Display{} *m_dpy;
    class Drawable{} m_wndid;
    class GC{} m_gc;
public:
    virtual void deviceRect(Coord, Coord, Coord, Coord) override;
    virtual void deviceText(const char*, Coord, Coord) override;
    virtual void deviceBitmap(const char*, Coord, Coord) override;
private:
    void XDrawRectangle(Display*, Drawable, GC, int, int, int, int);
};

class PMWindowImpl : public WindowImpl
{
public:
    using HPS = int;
    struct POINTL
    {
        Coord x;
        Coord y;
    };
public:
    PMWindowImpl();
    ~PMWindowImpl();
private:
    const int GPI_ERROR = 1;
    // lots of Presentation Manager window system-specific state, including
    HPS m_hps;
public:
    virtual void deviceRect(Coord, Coord, Coord, Coord) override;
    virtual void deviceBitmap(const char*, Coord, Coord) override;
    virtual void deviceText(const char*, Coord, Coord) override;
private:
    bool GpiBeginPath(HPS hps, long i) const;
    bool GpiSetCurrentPosition(HPS hps, POINTL* point) const;
    int  GpiPolyLine(HPS hps, long i, POINTL* point) const;
    bool GpiEndPath(HPS hps) const;
    void GpiStrokePath(HPS hps, long, long);
};