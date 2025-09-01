/*!
 *  \file       IconWindow.cpp
 *  \brief      
 *  
 */


#include "IconWindow.hpp"

#include "WindowImpl.hpp"

IconWindow::IconWindow(View* contents, const char* bitmap) : Window(contents), m_bitmap_name{bitmap}
{
}

IconWindow::~IconWindow()
{
}

void IconWindow::drawContents()
{
    WindowImpl *impl = getWindowImpl();
    if (impl != nullptr)
    {
        impl->deviceBitmap(m_bitmap_name.c_str(), 0.0, 0.0);
    }
}