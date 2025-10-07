/*!
 *  \file       CompositeEquipment.cpp
 *  \brief      
 *  
 */


#include "CompositeEquipment.hpp"
#include "Iterator.hpp"


CompositeEquipment::CompositeEquipment(const char* name) : Equipment(name)
{
}

CompositeEquipment::~CompositeEquipment()
{
}

Equipment::Watt CompositeEquipment::power()
{
    Iterator<Equipment *>* iter = createIterator();
    Watt total = 0;

    for (iter->first(); !iter->isDone(); iter->next())
    {
        total += iter->currentItem()->power();
    }
    delete iter;
    return total;
}

Equipment::Currency CompositeEquipment::netPrice()
{
    Iterator<Equipment *>* iter = createIterator();
    Currency total = 0;

    for (iter->first(); !iter->isDone(); iter->next())
    {
        total += iter->currentItem()->netPrice();
    }
    delete iter;
    return total;
}

Equipment::Currency CompositeEquipment::discountPrice()
{
    Iterator<Equipment *>* iter = createIterator();
    Currency total = 0;

    for (iter->first(); !iter->isDone(); iter->next())
    {
        total += iter->currentItem()->discountPrice();
    }
    delete iter;
    return total;
}

void CompositeEquipment::add(Equipment *equipment)
{
    m_equipments.append(equipment);
}

void CompositeEquipment::remove(Equipment *equipment)
{
    m_equipments.remove(equipment);
}

Iterator<Equipment *>* CompositeEquipment::createIterator()
{
    return m_equipments.createIterator();
}