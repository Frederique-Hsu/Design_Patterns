/*!
 *  \file       List.hpp
 *  \brief      
 *  
 */


#pragma once

template<typename ItemType> class Iterator;

constexpr const long DEFAULT_LIST_CAPACITY = 200;

template<typename ItemType>
class List
{
public:
    List(long size = DEFAULT_LIST_CAPACITY);
    List(List&);
    List& operator=(const List&);
    ~List();

public:
    long count() const;
    ItemType& get(long index) const;
    ItemType& first() const;
    ItemType& last() const;
    bool includes(const ItemType&) const;

    void append(const ItemType&);
    void prepend(const ItemType&);

    void remove(const ItemType&);
    void removeLast();
    void removeFirst();
    void removeAll();

    ItemType& top() const;
    void push(const ItemType&);
    ItemType& pop();

    Iterator<ItemType>* createIterator() const;

private:
    void removeAt(long index);

private:
    ItemType *m_items;
    long m_size;
    long m_count;
};


/*================================================================================================*/

#include "ListIterator.hpp"

#include <stdexcept>

template<typename ItemType>
List<ItemType>::List(long size) : m_size{size}, m_count{0}
{
    m_items = new ItemType[size];
}

template<typename ItemType>
List<ItemType>::~List()
{
    if (m_items != nullptr)
    {
        delete [] m_items;
        m_items = nullptr;
    }
}

template<typename ItemType>
List<ItemType>::List(List& other)
{
    m_size = other.m_size;
    m_count = other.m_count;
    m_items = new ItemType[m_size];

    for (long index = 0; index < m_count; ++index)
    {
        m_items[index] = other.m_items[index];
    }
}

template<typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List<ItemType>& other)
{
    if (this != &other)
    {
        removeAll();

        m_size = other.m_size;
        m_count = other.m_count;
        m_items = new ItemType[m_size];

        for (long index = 0; index < m_count; ++index)
        {
            m_items[index] = other.m_items[index];
        }
    }
    return *this;
}

template<typename ItemType>
long List<ItemType>::count() const
{
    return m_count;
}

template<typename ItemType>
ItemType& List<ItemType>::get(long index) const
{
    if (index <= m_count)
    {
        return m_items[index];
    }
    else
    {
        throw std::out_of_range("Index out of the range in List<ItemType>::get(index)!");
    }
}

template<typename ItemType>
ItemType& List<ItemType>::first() const
{
    return get(0);
}

template<typename ItemType>
ItemType& List<ItemType>::last() const
{
    return get(count() - 1);
}

template<typename ItemType>
bool List<ItemType>::includes(const ItemType& item) const
{
    for (long index = 0; index < count(); ++index)
    {
        if (m_items[index] == item)
        {
            return true;
        }
    }
    return false;
}

template<typename ItemType>
void List<ItemType>::append(const ItemType& item)
{
    if (m_count <= m_size)
    {
        m_items[m_count] = item;
        m_count++;
    }
}

template<typename ItemType>
void List<ItemType>::prepend(const ItemType& item)
{
    if (m_count <= m_size)
    {
        for (long index = m_count - 1; index >= 0; --index)
        {
            m_items[index+1] = m_items[index];
        }
        m_items[0] = item;
        m_count++;
    }
}

template<typename ItemType>
void List<ItemType>::removeLast()
{
    removeAt(count() - 1);
}

template<typename ItemType>
void List<ItemType>::removeFirst()
{
    removeAt(0);
}

template<typename ItemType>
void List<ItemType>::remove(const ItemType& item)
{
    for (long index = 0; index < count(); ++index)
    {
        if (m_items[index] == item)
        {
            removeAt(index);
        }
    }
}

template<typename ItemType>
void List<ItemType>::removeAll()
{
    m_count = 0;
}

template<typename ItemType>
void List<ItemType>::removeAt(long index)
{
    if ((index < 0) or (index >= m_count))
    {
        throw std::out_of_range("Index out of the range.");
    }
    for (long i = index; i < count() - 1; ++i)
    {
        m_items[i] = m_items[i+1];
    }
    m_count--;
}

template<typename ItemType>
ItemType& List<ItemType>::top() const
{
    return last();
}

template<typename ItemType>
void List<ItemType>::push(const ItemType& item)
{
    append(item);
}

template<typename ItemType>
ItemType& List<ItemType>::pop()
{
    ItemType& top = last();
    removeLast();
    return top;
}

template<typename ItemType>
Iterator<ItemType>* List<ItemType>::createIterator() const
{
    return new ListIterator<ItemType>(this);
}
