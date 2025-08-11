/*!
 *  \file       Shape.cpp
 *  \brief
 *
 */


#include "Shape.hpp"

#include "Manipulator.hpp"


Shape::Shape()
{
}

void Shape::boundingBox(Point& bottom_left, Point& top_right) const
{
    (void)bottom_left;
    (void)top_right;

    // TODO
}

Manipulator* Shape::createManipulator() const
{
    // TODO

    return nullptr;
}
