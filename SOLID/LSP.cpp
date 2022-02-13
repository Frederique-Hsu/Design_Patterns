/*!
 *  \file       LSP.cpp
 *  \brief      Liskov Substitution Principle
 *  \details    Demo how the LSP works in the program, and how to apply the LSP.
 *  
 */

#include "LSP.hpp"

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

int main(int argc, char* argv[])
{
    return 0;
}