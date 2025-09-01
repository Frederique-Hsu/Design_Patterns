/*!
 *  \file       Window.cpp
 *  \brief      
 *  
 */


#include "Window.hpp"

#include "WindowImpl.hpp"
#include "View.hpp"
#include "WindowSystemFactory.hpp"

Window::Window(View *contents) : m_contents{contents}, m_type{WindowType{}}
{
}

Window::~Window()
{
    if (m_impl != nullptr)
    {
        delete m_impl;
        m_impl = nullptr;
    }
}

void Window::drawRect(const Point& p1, const Point& p2)
{
    WindowImpl *impl = getWindowImpl();
    if (impl != nullptr)
    {
        impl->deviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
    }
}

WindowImpl* Window::getWindowImpl()
{
    if (m_impl == nullptr)
    {
        m_impl = WindowSystemFactory::instance()->makeWindowImpl(m_type);
    }
    return m_impl;
}

View* Window::getView()
{
    return m_contents;
}

void Window::drawContents()
{
}

void Window::open()
{
}

void Window::close()
{
}

void Window::iconify()
{
}

void Window::deiconify()
{
}

void Window::setOrigin(const Point& at)
{
    (void)at;
}

void Window::setExtent(const Point& extent)
{
    (void)extent;
}

void Window::raise()
{
}

void Window::lower()
{
}

void Window::drawLine(const Point&, const Point&)
{
}

void Window::drawPolygon(const Point[], int /* n */)
{
}

void Window::drawText(const char*, const Point&)
{
}

void Window::setWindowType(WindowType type)
{
    m_type = type;
}

WindowType Window::getWindowType() const
{
    return m_type;
}

