/*!
 *  \file       Abstraction.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>

class Implementor;


/*!
 *  \class      Abstraction
 *  \details    The Abstraction defines the interface for the "control" part of the 2 class hierarchies.
 *              It maintains a reference to an object of the Implementor hierarchy and delegates all of
 *              the real work to this object.
 */
class Abstraction
{
public:
    Abstraction(Implementor *implementor);
    virtual ~Abstraction();

protected:
    Implementor *m_implementor;

public:
    virtual std::string Operation() const;

    void check(int num) const volatile;
};