/*!
 *  \file       product.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>

typedef int     ProductID;

enum class EProductCategory : ProductID
{
    kVehicle,
    kVessel,
    kPlane
};

class Product
{
public:
    virtual ~Product() = default;
};

class VehicleProduct : public Product
{
public:
    VehicleProduct(const char* brand = "");
private:
    std::string m_brand_name;
};

class VesselProduct : public Product
{
public:
};