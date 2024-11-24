/*!
 *  \file       text_manipulator.hpp
 *  \brief      
 *  
 */


#pragma once

#include "manipulator.hpp"

class TextShape;

class TextManipulator : public Manipulator
{
public:
    TextManipulator(const TextShape* pshape);
    ~TextManipulator();
private:
    const TextShape* m_text_shape;
};