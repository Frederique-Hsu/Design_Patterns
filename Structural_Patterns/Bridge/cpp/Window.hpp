/*!
 *  \file       Window.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Point.hpp"
#include "WindowImpl.hpp"

class View;

class Window
{
public:
    Window(View* contents);
    virtual ~Window();
    
public:
    virtual void drawContents();

    virtual void open();
    virtual void close();
    virtual void iconify();
    virtual void deiconify();

    virtual void setOrigin(const Point& at);
    virtual void setExtent(const Point& extent);
    virtual void raise();
    virtual void lower();

    virtual void drawLine(const Point&, const Point&);
    virtual void drawRect(const Point&, const Point&);
    virtual void drawPolygon(const Point[], int n);
    virtual void drawText(const char*, const Point&);

    void setWindowType(WindowType type);
    WindowType getWindowType() const;

protected:
    WindowImpl* getWindowImpl();
    View* getView();

private:
    WindowImpl *m_impl;
    View *m_contents;

    WindowType m_type;
};