/*!
 *  \file       wall.hpp
 *  \brief      
 *  
 */


#pragma once

#include "map_site.hpp"

class Wall : public MapSite
{
public:
    Wall();
    virtual ~Wall();
    
public:
    virtual Wall* clone() const;
    virtual void enter() override;
};

class BombedWall : public Wall
{
public:
    BombedWall();
    virtual ~BombedWall();
private:
    bool m_has_bomb;
public:
    bool hasBomb() const;
};
