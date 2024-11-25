/*!
 *  \file       window.hpp
 *  \brief      
 *  
 */


#pragma once

class View;
class WindowImpl;
class Point;

class Window
{
public:
    Window(View* contents);
    virtual ~Window();
private:
    WindowImpl* m_implementor;
    View* m_contents;
public:
    virtual void drawContents();    // requests handled by window

    virtual void open();
    virtual void close();
    virtual void iconify();
    virtual void deiconify();

    virtual void setOrigin(const Point& at);    // requests forwarded to implementator
    virtual void setExtent(const Point& extent);
    virtual void raise();
    virtual void lower();

    virtual void drawLine(const Point&, const Point&);
    virtual void drawRect(const Point&, const Point&);
    virtual void drawPolygon(const Point[], int n);
    virtual void drawText(const char*, const Point&);
protected:
    WindowImpl* getWindowImpl();
    View* getView();
};

class ApplicationWindow : public Window
{
public:
    void drawContents() override;
};

class IconWindow : public Window
{
public:
    virtual void drawContents() override;
private:
    const char* m_bitmap_name;
};

class TransientWindow : public Window
{
public:
};

class IconDockWindow : public IconWindow
{
public:
};