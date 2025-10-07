/*!
 *  \file       CompositeEquipment.hpp
 *  \brief      
 *  
 */


#pragma once

#include "Equipment.hpp"
#include "List.hpp"

class CompositeEquipment : public Equipment
{
public:
    virtual ~CompositeEquipment();

protected:
    CompositeEquipment(const char*);

public:
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;

    void add(Equipment *) override;
    void remove(Equipment *) override;
    Iterator<Equipment *>* createIterator() override;

private:
    List<Equipment *> m_equipments;
};