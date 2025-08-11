/*!
 *  \file       Shape.hpp
 *  \brief
 *
 */


#pragma once


class Point;
class Manipulator;

class Shape
{
public:
    Shape();

public:
    virtual void boundingBox(Point& bottom_left, Point& top_right) const;
    virtual Manipulator* createManipulator() const;
};
