/*!
 *  \file       manipulator.hpp
 *  \brief      
 *  
 */


#pragma once


class Manipulator
{
public:
    virtual ~Manipulator() = default;
public:
    virtual void downClick();
    virtual void drag();
    virtual void upClick();
};

class LineManipulator : public Manipulator
{
public:
    virtual void downClick() override;
    virtual void upClick() override;
};

class TextManipulator : public Manipulator
{
public:
    virtual void drag() override;
};