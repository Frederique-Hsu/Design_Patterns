/*!
 *  \file       window.cpp
 *  \brief      
 *  
 */


#include "window.hpp"

#include "window_impl.hpp"
#include "view.hpp"
#include "window_factory.hpp"

#include "../common_utils/point.hpp"

Window::Window(View* contents) : m_contents{contents}
{
}

Window::~Window()
{
}

WindowImpl* Window::getWindowImpl()
{
    if (m_implementor == nullptr)
    {
        m_implementor = WindowSystemFactory::instance()->makeWindowImpl();
    }
    return m_implementor;
}

View* Window::getView()
{
    return m_contents;
}

void Window::drawContents()
{
    /*!
     *  \todo
     */
}

void Window::open()
{
    /*!
     *  \todo
     */
}

void Window::close()
{
    /*!
     *  \todo
     */
}

void Window::iconify()
{
    /*!
     *  \todo
     */
}

void Window::deiconify()
{
    /*!
     *  \todo
     */
}

void Window::setOrigin(const Point& /* at */)
{
    /*!
     *  \todo
     */
}

void Window::setExtent(const Point& /* extent */)
{
    /*!
     *  \todo
     */
}

void Window::raise()
{
    /*!
     *  \todo
     */
}

void Window::lower()
{
    /*!
     *  \todo
     */
}

void Window::drawLine(const Point&, const Point&)
{
    /*!
     *  \todo
     */
}

void Window::drawRect(const Point& p1, const Point& p2)
{
    WindowImpl* implementor = getWindowImpl();
    implementor->deviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
}

void Window::drawPolygon(const Point[], int /* n */)
{
    /*!
     *  \todo
     */
}

void Window::drawText(const char*, const Point&)
{
    /*!
     *  \todo
     */
}

void ApplicationWindow::drawContents()
{
    getView()->drawOn(this);
}

void IconWindow::drawContents()
{
    WindowImpl* implementor = getWindowImpl();
    if (implementor != nullptr)
    {
        implementor->deviceBitmap(m_bitmap_name, 0.0, 0.0);
    }
}