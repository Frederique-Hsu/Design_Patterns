/*!
 *  \file       figure.hpp
 *  \brief
 *
 */


#pragma once

#include "manipulator.hpp"

class Figure
{
public:
    virtual ~Figure() = default;
public:
    virtual Manipulator* createManipulator();
};

class LineFigure : public Figure
{
public:
    virtual LineManipulator* createManipulator() override;
};

class TextFigure : public Figure
{
public:
    virtual TextManipulator* createManipulator() override;
};