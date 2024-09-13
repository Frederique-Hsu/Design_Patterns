/*!
 *  \file       parameterized_creator.hpp
 *  \brief
 *
 */


#pragma once


class Product;

/*!
 *  \section    Prototype
 */

class VirtualCreator
{
public:
    virtual ~VirtualCreator() = default;

public:
    virtual Product* createProduct() = 0;
};


template<typename ProductType>
class ParameterizedCreator : public VirtualCreator
{
public:
    ParameterizedCreator();
    virtual ~ParameterizedCreator();

public:
    virtual ProductType* createProduct() override;
};


#include "parameterized_creator_impl.hpp"