/*!
 *  \file       window_factory.cpp
 *  \brief      
 *  
 */


#include "window_factory.hpp"
#include "window_impl.hpp"

WindowSystemFactory* WindowSystemFactory::m_instance = nullptr;

WindowSystemFactory::WindowSystemFactory()
{
}

WindowSystemFactory* WindowSystemFactory::instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new WindowSystemFactory();
    }
    return m_instance;
}

WindowImpl* WindowSystemFactory::makeWindowImpl()
{
    // TODO
#if false
    return new PMWindowImpl;
#else
    return new XWindowImpl;
#endif
}