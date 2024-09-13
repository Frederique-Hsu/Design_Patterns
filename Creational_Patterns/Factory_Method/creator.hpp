/*!
 *  \file       creator.hpp
 *  \brief
 *
 */


#pragma once


#include "product.hpp"

class Creator
{
public:
    virtual Product* createProduct(ProductID);
};


class IndustryCreator : public Creator
{
public:
    virtual Product* createProduct(ProductID) override;
};
