/*!
 *  \file       text_view.hpp
 *  \brief      
 *  
 */


#pragma once

#include "../common_utils/coord.hpp"

class TextView
{
public:
    TextView();
    virtual ~TextView();
public:
    void getOrigin(Coord& x, Coord& y) const;
    void getExtend(Coord& width, Coord& height) const;
    virtual bool isEmpty() const;
private:
    Coord m_x;
    Coord m_y;
    Coord m_width;
    Coord m_height;
};