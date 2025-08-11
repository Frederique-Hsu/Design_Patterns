/*!
 *  \file       TextShape.hpp
 *  \brief
 *
 */


#pragma once


#include "Shape.hpp"
#include "TextView.hpp"

namespace class_adapter
{
    class TextShape : public Shape, private TextView
    {
    public:
        TextShape();

    public:
        void boundingBox(Point& bottom_left, Point& top_right) const override;
        bool isEmpty() const override;
        Manipulator* createManipulator() const override;
    };
}


namespace object_adapter
{
    class TextShape : public Shape
    {
    public:
        TextShape(TextView *);

    public:
        void boundingBox(Point &bottom_left, Point &top_right) const override;
        bool isEmpty() const;
        Manipulator* createManipulator() const override;

    private:
        TextView *m_text_view;
    };
}
