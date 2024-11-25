/*!
 *  \file       view.cpp
 *  \brief      
 *  
 */


#include "view.hpp"

#include "window.hpp"

#include <iostream>

void View::drawOn(const ApplicationWindow* wnd) const
{
    std::cout << "Draw on the application window = " << wnd << std::endl;
}