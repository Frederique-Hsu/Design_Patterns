/*!
 *  \file       window_factory.hpp
 *  \brief      
 *  
 */


#pragma once

class WindowImpl;

class WindowSystemFactory
{
public:
    static WindowSystemFactory* instance();
    WindowImpl* makeWindowImpl();
protected:
    WindowSystemFactory();
private:
    static WindowSystemFactory* m_instance;
};