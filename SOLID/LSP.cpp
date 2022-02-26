/*!
 *  \file       LSP.cpp
 *  \brief      Liskov Substitution Principle
 *  \details    Demo how the LSP works in the program, and how to apply the LSP.
 *  
 */

#include "LSP.hpp"

#include <iostream>

/*================================================================================================*/
/*!< Implementations: */
Rectangle::Rectangle(const int width, const int height) : width{width}, height{height}
{
}

int Rectangle::get_width() const
{
    return width;
}

void Rectangle::set_width(const int width)
{
    this->width = width;
}

int Rectangle::get_height() const
{
    return height;
}

void Rectangle::set_height(const int height)
{
    this->height = height;
}

int Rectangle::area() const
{
    return width * height;
}

bool Rectangle::is_square() const
{
    return width == height;
}

Square::Square(int size) : Rectangle(size, size)
{
}

void Square::set_width(const int width)
{
    this->width = width;
    height = width;
}

void Square::set_height(const int height)
{
    this->height = height;
    width = height;
}

void process(Rectangle& r)
{
    int w = r.get_width();
    r.set_height(10);

    std::cout << "expected area = " << (w * 10) << ", got " << r.area() << std::endl;
}

int main(int argc, char* argv[])
{
    Square square{5};
    process(square);

    return 0;
}