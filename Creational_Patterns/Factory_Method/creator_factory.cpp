/*!
 *  \file       creator_factory.cpp
 *  \brief
 *
 */


#include "creator_factory.hpp"

#include "creator.hpp"
#include "unit_testing/test_factory_method_pattern.h++"


CreatorFactory::CreatorFactory() : m_product{nullptr}
{
}

CreatorFactory::~CreatorFactory()
{
    if (m_product != nullptr)
    {
        delete m_product;
        m_product = nullptr;
    }
}

Product* CreatorFactory::getProduct()
{
    if (m_product == nullptr)
    {
        m_product = createProduct();
    }
    return m_product;
}

Product* CreatorFactory::createProduct()
{
    /*!
     *  \attention  defer this factory method to implement in the subclass.
     */
    return nullptr;
}

VehicleFactory::VehicleFactory() : CreatorFactory()
{
}

VehicleProduct* VehicleFactory::createProduct()
{
    return new VehicleProduct;
}

VesselFactory::VesselFactory() : CreatorFactory()
{
}

VesselProduct* VesselFactory::createProduct()
{
    return new VesselProduct;
}

BeverageFactory::BeverageFactory(BeverageKind kind) : CreatorFactory(), m_kind{kind}
{
}

Product* BeverageFactory::createProduct()
{
    using namespace UTest4FactoryMethodPattern;
    
    switch (m_kind)
    {
    case BeverageKind::kCarbonatedBeverage:
        return new CocaColaProduct(false, CocaColaProduct::BeverageColour::kCaramelColour);
    case BeverageKind::kEneryDrink:
        return new RedBullProduct();
    case BeverageKind::kSparklingWater:
        return new PerrierProduct(true, "France");
    default:
        return nullptr;
    }
}