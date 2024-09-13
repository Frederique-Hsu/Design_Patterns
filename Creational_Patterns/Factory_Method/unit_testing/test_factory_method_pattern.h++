/*!
 *  \file       test_factory_method_pattern.h++
 *  \brief
 *
 */


#pragma once

#include <boost/test/unit_test.hpp>

#include "../product.hpp"

BOOST_AUTO_TEST_SUITE(UTest4FactoryMethodPattern)

    class CarbonatedBeveragesProduct : public Product
    {
    public:
        CarbonatedBeveragesProduct(bool is_soda);
    private:
        bool m_is_soda;
    public:
        bool isSoda() const;
    };

    class EnergyDrinksProduct : public Product
    {
    public:
        EnergyDrinksProduct(bool has_taurine = false);

    private:
        bool m_has_taurine;
        
    public:
        bool hasTaurine() const;
    };

    class RedBullProduct : public EnergyDrinksProduct
    {
    public:
        RedBullProduct(bool has_taurine = true, const char* brand_name = "RedBull");

    private:
        std::string m_brand_name;

    public:
        std::string getBrandName();
    };
    
    class CocaColaProduct : public CarbonatedBeveragesProduct
    {
    public:
        enum class BeverageColour
        {
            kCaramelColour,
            kLemonColour
        };
        
        CocaColaProduct(bool is_soda, BeverageColour colour);
    private:
        BeverageColour m_colour;
    };
    
    class PerrierProduct : public CarbonatedBeveragesProduct
    {
    public:
        PerrierProduct(bool is_soda, const std::string& place_of_production);
    private:
        std::string m_production_place;
    public:
        const std::string& productionPlace() const;
    };

BOOST_AUTO_TEST_SUITE_END()