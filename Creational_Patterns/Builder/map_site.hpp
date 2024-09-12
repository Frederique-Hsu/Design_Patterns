/*!
 *  \file       map_site.hpp
 *  \brief      
 *  
 */


#pragma once


class MapSite
{
public:
    virtual ~MapSite() = default;

public:
    virtual void enter() = 0;
};

enum class Direction
{
    kEast,
    kSouth,
    kWest,
    kNorth
};