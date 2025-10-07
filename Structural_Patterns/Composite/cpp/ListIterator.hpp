/*!
 *  \file       ListIterator.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Iterator.hpp"

template<typename ItemType> class List;

template<typename ItemType>
class ListIterator : public Iterator<ItemType>
{
public:
    ListIterator(const List<ItemType> *list);

public:
    void first() override;
    void next() override;
    bool isDone() const override;
    ItemType currentItem() const override;

private:
    const List<ItemType> *m_list;
    long m_current_index;
};


/*================================================================================================*/

#include "List.hpp"

#include <stdexcept>

template<typename ItemType>
ListIterator<ItemType>::ListIterator(const List<ItemType> *list) : m_list{list}, m_current_index{0}
{
}

template<typename ItemType>
void ListIterator<ItemType>::first()
{
    m_current_index = 0;
}

template<typename ItemType>
void ListIterator<ItemType>::next()
{
    m_current_index++;
}

template<typename ItemType>
bool ListIterator<ItemType>::isDone() const
{
    return m_current_index >= m_list->count();
}

template<typename ItemType>
ItemType ListIterator<ItemType>::currentItem() const
{
    if (isDone())
    {
        throw std::out_of_range("Iterator out of range.");
    }
    return m_list->get(m_current_index);
}
