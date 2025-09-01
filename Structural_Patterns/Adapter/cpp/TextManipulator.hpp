/*!
 *  \file       TextManipulator.hpp
 *  \brief
 *
 */


#pragma once


#include "Manipulator.hpp"

namespace class_adapter
{
    class TextShape;

    class TextManipulator : public Manipulator
    {
    public:
        TextManipulator(const class_adapter::TextShape *s);

    private:
        [[maybe_unused]] const class_adapter::TextShape *m_text_shape;
    };
}


namespace object_adapter
{
    class TextShape;

    class TextManipulator : public Manipulator
    {
    public:
        TextManipulator(const object_adapter::TextShape *s);

    private:
        [[maybe_unused]] const object_adapter::TextShape *m_text_shape;
    };
}
