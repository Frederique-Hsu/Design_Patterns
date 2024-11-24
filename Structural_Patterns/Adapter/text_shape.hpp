/*!
 *  \file       text_shape.hpp
 *  \brief      
 *  
 */


#pragma once

#include "shape.hpp"
#include "text_view.hpp"

#define CLASS_ADAPTER   1
#define OBJECT_ADAPTER  2
#define ADAPTER_TYPE    CLASS_ADAPTER

#if (ADAPTER_TYPE == CLASS_ADAPTER)

    class TextShape : public Shape, private TextView
    {
    public:
        TextShape();
    public:
        virtual void boundingBox(Point& bottom_left, Point& top_right) const override;
        virtual bool isEmpty() const override;
        virtual Manipulator* createManipulator() const override;
    };

#elif (ADAPTER_TYPE == OBJECT_ADAPTER)

    class TextShape : public Shape
    {
    public:
        TextShape(TextView* text);
        ~TextShape();
    private:
        TextView* m_text;
    public:
        virtual void boundingBox(Point& bottom_left, Point& top_right) const override;
        virtual bool isEmpty() const;
        virtual Manipulator* createManipulator() const override;
    };

#endif