/*!
 *  \file       Component.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>


#define UNUSED(arg)     (void)arg

/*!
 *  \class  Compoent
 *  \brief  The base component class declares common operations for both simple and complex 
 *          objects of a composition
 */
class Component
{
protected:
    Component *m_parent;

public:
    virtual ~Component();

public:
    void setParent(Component *parent);
    Component* getParent() const;

    virtual void add(Component *component);
    virtual void remove(Component *component);
    virtual bool isComposite() const;

    /*!
     *  \note   The base Component may implement some default behaviour or leave it to concrete classes
     *          (by declaring the method containing the behaviour as "abstract")
     */
    virtual std::string operation() const = 0;
};