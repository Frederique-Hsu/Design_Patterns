/*!
 *  \file       figure.cpp
 *  \brief
 *
 */


#include "figure.hpp"


Manipulator* Figure::createManipulator()
{
    /*!
     *  \remark     empty implementation, defer to implement in the subclass
     */
    return nullptr;
}

LineManipulator* LineFigure::createManipulator()
{
    return new LineManipulator;
}

TextManipulator* TextFigure::createManipulator()
{
    return new TextManipulator;
}