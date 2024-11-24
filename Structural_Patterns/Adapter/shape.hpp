/*!
 *  \file       shape.hpp
 *  \brief      
 *  
 */


#pragma once

class Manipulator;
class Point;

class Shape
{
public:
    Shape();
    virtual ~Shape();
public:
    virtual void boundingBox(Point& bottom_left, Point& top_right) const;
    virtual Manipulator* createManipulator() const;
};