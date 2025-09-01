/*!
 *  \file       PresentationManagerWindowImpl.hpp
 *  \brief      
 *  
 */


#pragma once

#include "WindowImpl.hpp"
#include "PPOINTL.hpp"

using HPS = int;

class PresentationManagerWindowImpl : public WindowImpl
{
public:
    PresentationManagerWindowImpl();

public:
    void deviceRect(Coord, Coord, Coord, Coord) override;

    void implementTop() override;
    void implementBottom() override;
    void implementSetExtent(const Point&) override;
    void implementSetOrigin(const Point&) override;

    void deviceText(const char*, Coord, Coord) override;
    void deviceBitmap(const char*, Coord, Coord) override;

private:
    bool GpiBeginPath(HPS hps, long i) const;
    bool GpiSetCurrentPosition(HPS hps, PPOINTL *p) const;
    int  GpiPolyLine(HPS hps, long i, PPOINTL *p) const;
    bool GpiEndPath(HPS hps) const;
    void GpiStrokePath(HPS hps, long, long);

private:
    HPS m_hps;
};