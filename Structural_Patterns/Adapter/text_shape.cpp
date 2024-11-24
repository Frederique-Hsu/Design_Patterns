/*!
 *  \file       text_shape.cpp
 *  \brief      
 *  
 */


#include "text_shape.hpp"

#include "../common_utils/point.hpp"
#include "text_manipulator.hpp"

#if (ADAPTER_TYPE == CLASS_ADAPTER)

    TextShape::TextShape() : Shape(), TextView()
    {
    }

    void TextShape::boundingBox(Point& bottom_left, Point& top_right) const
    {
        Coord bottom, left, width, height;

        getOrigin(bottom, left);
        getExtend(width, height);

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

#elif (ADAPTER_TYPE == OBJECT_ADAPTER)

    TextShape::TextShape(TextView* text) : Shape(), m_text{text}
    {
    }

    TextShape::~TextShape()
    {
        if (m_text != nullptr)
        {
            delete m_text;
        }
    }

    void TextShape::boundingBox(Point& bottom_left, Point& top_right) const
    {
        Coord bottom, left, width, height;

        m_text->getOrigin(bottom, left);
        m_text->getExtend(width, height);

        bottom_left = Point(bottom, left);
        top_right = Point(bottom + height, left + width);
    }

    bool TextShape::isEmpty() const
    {
        return m_text->isEmpty();
    }

    Manipulator* TextShape::createManipulator() const
    {
        return new TextManipulator(this);
    }

#endif