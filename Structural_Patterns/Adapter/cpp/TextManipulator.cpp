/*!
 *  \file       TextManipulator.cpp
 *  \brief
 *
 */


#include "TextManipulator.hpp"


namespace class_adapter
{
    TextManipulator::TextManipulator(const class_adapter::TextShape *s) : m_text_shape{s}
    {
    }
}


namespace object_adapter
{
    TextManipulator::TextManipulator(const object_adapter::TextShape *s) : m_text_shape{s}
    {
    }
}
