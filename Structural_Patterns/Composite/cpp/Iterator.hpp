/*!
 *  \file       Iterator.hpp
 *  \brief      
 *  
 */


#pragma once


template<typename ItemType>
class Iterator
{
public:
    virtual ~Iterator() = default;

protected:
    Iterator() = default;

public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual ItemType currentItem() const = 0;
};