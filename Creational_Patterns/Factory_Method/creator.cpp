/*!
 *  \file       creator.cpp
 *  \brief
 *
 */


#include "creator.hpp"


Product* Creator::createProduct(ProductID product_category)
{
    if (product_category == static_cast<ProductID>(EProductCategory::kVehicle))
    {
        return new VehicleProduct;
    }
    if (static_cast<EProductCategory>(product_category) == EProductCategory::kVessel)
    {
        return new VesselProduct;
    }
    // ...

    return nullptr;
}

Product* IndustryCreator::createProduct(ProductID product_category)
{
    switch (static_cast<EProductCategory>(product_category))
    {
    case EProductCategory::kVehicle:
        return new VehicleProduct;
    case EProductCategory::kVessel:
        return new VesselProduct;
    default:
        return Creator::createProduct(product_category);
    }
}