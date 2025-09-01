/*!
 *  \file       WindowSystemFactory.cpp
 *  \brief      
 *  
 */


#include "WindowSystemFactory.hpp"

#include "XWindowImpl.hpp"
#include "PresentationManagerWindowImpl.hpp"


WindowSystemFactory* WindowSystemFactory::m_instance = nullptr;

WindowSystemFactory* WindowSystemFactory::instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new WindowSystemFactory;
    }
    return m_instance;
}

WindowSystemFactory::WindowSystemFactory()
{
}

WindowImpl* WindowSystemFactory::makeWindowImpl(WindowType type)
{
    switch (type)
    {
    case WindowType::X_WINDOW:
        return new XWindowImpl();
    case WindowType::PRESENTATION_MANAGER_WINDOW:
        return new PresentationManagerWindowImpl();
    }
    return nullptr;
}