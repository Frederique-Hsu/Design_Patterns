/*!
 *  \file       ApplicationWindow.cpp
 *  \brief      
 *  
 */


#include "ApplicationWindow.hpp"
#include "View.hpp"


void ApplicationWindow::drawContents()
{
    getView()->drawOn(this);
}