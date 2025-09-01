/*!
 *  \file       View.cpp
 *  \brief      
 *  
 */


#include "View.hpp"

#include "ApplicationWindow.hpp"

void View::drawOn(const ApplicationWindow *window) const
{
    std::cout << "DrawOn(" << window << ")" << std::endl;
}