/*!
 *  \file       wall.cpp
 *  \brief      
 *  
 */


#include "wall.hpp"

#include "user_exception.hpp"

Wall::Wall() : MapSite()
{
}

Wall::~Wall()
{
}

Wall* Wall::clone() const
{
    return new Wall(*this);
}

void Wall::enter()
{
    /*! \todo   implement this method later */
    throw UnimplementedException(std::string(__FUNCTION__));
}

BombedWall::BombedWall() : m_has_bomb(bool{})
{
}

BombedWall::~BombedWall()
{
}

bool BombedWall::hasBomb() const
{
    return m_has_bomb;
}