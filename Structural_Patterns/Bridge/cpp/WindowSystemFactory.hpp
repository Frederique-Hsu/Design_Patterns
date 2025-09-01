/*!
 *  \file       WindowSystemFactory.hpp
 *  \brief      
 *  
 */


#pragma once

#include "WindowImpl.hpp"

class WindowSystemFactory
{
public:
    static WindowSystemFactory* instance();

    WindowImpl* makeWindowImpl(WindowType type);

protected:
    WindowSystemFactory();

private:
    static WindowSystemFactory* m_instance;
};