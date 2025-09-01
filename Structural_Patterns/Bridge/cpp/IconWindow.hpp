/*!
 *  \file       IconWindow.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Window.hpp"

class IconWindow : public Window
{
public:
    IconWindow(View* contents, const char* bitmap);
    ~IconWindow();

public:
    void drawContents() override;

private:
    std::string m_bitmap_name;
};