/*!
 *  \file       manipulator.cpp
 *  \brief
 *
 */


#include "manipulator.hpp"

#include <iostream>


void Manipulator::downClick()
{
    /*! \remark     empty implementation */
}

void Manipulator::upClick()
{
    /*! \remark     empty implementation */
}

void Manipulator::drag()
{
    /*! \remark     empty implementation */
}

void LineManipulator::downClick()
{
    std::cout << "Down click for the line." << std::endl;
}

void LineManipulator::upClick()
{
    std::cout << "Up click for the line." << std::endl;
}

void TextManipulator::drag()
{
    std::cout << "Drag for text." << std::endl;
}