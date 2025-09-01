/*!
 *  \file       TextShape.txt
 *  \brief
 *
 */


#include "TextShape.hpp"

#include "Point.hpp"
#include "TextManipulator.hpp"


namespace class_adapter
{
    TextShape::TextShape()
    {
    }
    
    void TextShape::boundingBox(Point& bottom_left, Point& top_right) const
    {
        Coord bottom, left, width, height;

        getOrigin(bottom, left);
        getOrigin(width, height);

        bottom_left = Point(bottom, left);
        top_right = Point(bottom + height, left + width);
    }

    bool TextShape::isEmpty() const
    {
        return TextView::isEmpty();
    }

    Manipulator* TextShape::createManipulator() const
    {
        return new TextManipulator(this);
    }
}

namespace object_adapter
{
    TextShape::TextShape(TextView *text_view) : m_text_view{text_view}
    {
    }

    void TextShape::boundingBox(Point &bottom_left, Point &top_right) const
    {
        Coord bottom, left, width, height;

        m_text_view->getOrigin(bottom, left);
        m_text_view->getExtend(width, height);

        bottom_left = Point(bottom, left);
        top_right = Point(bottom + height, left + width);
    }

    bool TextShape::isEmpty() const
    {
        return m_text_view->isEmpty();
    }

    Manipulator* TextShape::createManipulator() const
    {
        return new TextManipulator(this);
    }
}
