/*!
 *  \file       creator_factory.hpp
 *  \brief
 *
 */


#pragma once

#include "product.hpp"


class Product;

class CreatorFactory
{
public:
    CreatorFactory();
    virtual ~CreatorFactory();

public:
    Product* getProduct();

protected:
    virtual Product* createProduct();

private:
    Product* m_product;
};


class VehicleFactory : public CreatorFactory
{
public:
    VehicleFactory();
    ~VehicleFactory() = default;
public:
    virtual VehicleProduct* createProduct() override;
};

class VesselFactory : public CreatorFactory
{
public:
    VesselFactory();
    ~VesselFactory() = default;
public:
    virtual VesselProduct* createProduct() override;
};

class BeverageFactory : public CreatorFactory
{
public:
    enum class BeverageKind
    {
        kCarbonatedBeverage,
        kEneryDrink,
        kSparklingWater
    };
    BeverageFactory(BeverageKind kind);
    ~BeverageFactory() = default;
private:
    BeverageKind m_kind;
public:
    virtual Product* createProduct() override;
};