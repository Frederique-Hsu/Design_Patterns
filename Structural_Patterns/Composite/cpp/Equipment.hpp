/*!
 *  \file       Equipment.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Iterator.hpp"

class Equipment
{
public:
    using Watt = int;
    using Currency = int;

    virtual ~Equipment();

protected:
    Equipment(const char*);

private:
    const char* m_name;

public:
    const char* name();
    
    virtual Watt power();
    virtual Currency netPrice();
    virtual Currency discountPrice();

    virtual void add(Equipment *);
    virtual void remove(Equipment *);
    virtual Iterator<Equipment *>* createIterator();
};