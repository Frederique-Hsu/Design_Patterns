/*!
 *  \file       test_factory_method_pattern.c++
 *  \brief
 *
 */


#include "test_factory_method_pattern.h++"

#include "../parameterized_creator.hpp"
#include "../creator_factory.hpp"
#include "../utils/finalize.hpp"

BOOST_AUTO_TEST_SUITE(UTest4FactoryMethodPattern)

    EnergyDrinksProduct::EnergyDrinksProduct(bool has_taurine) : Product(), m_has_taurine{has_taurine}
    {
    }

    bool EnergyDrinksProduct::hasTaurine() const
    {
        return m_has_taurine;
    }

    RedBullProduct::RedBullProduct(bool has_taurine, const char* brand_name) : EnergyDrinksProduct(has_taurine),
                                                                               m_brand_name{brand_name}
    {
    }

    std::string RedBullProduct::getBrandName()
    {
        return m_brand_name;
    }

    BOOST_AUTO_TEST_CASE(CreateProductOverParameterizedCreator)
    {
        ParameterizedCreator<RedBullProduct> creator;

        auto red_bull = creator.createProduct();
        BOOST_CHECK_EQUAL(red_bull->getBrandName(), "RedBull");
        BOOST_CHECK_EQUAL(red_bull->hasTaurine(), true);

        delete red_bull;
    }

    CarbonatedBeveragesProduct::CarbonatedBeveragesProduct(bool is_soda) : m_is_soda{is_soda}
    {
    }

    bool CarbonatedBeveragesProduct::isSoda() const
    {
        return m_is_soda;
    }

    CocaColaProduct::CocaColaProduct(bool is_soda, BeverageColour colour)
        : CarbonatedBeveragesProduct(is_soda), m_colour{colour}
    {
    }

    PerrierProduct::PerrierProduct(bool is_soda, const std::string& place_of_production)
        : CarbonatedBeveragesProduct(is_soda), m_production_place{place_of_production}
    {
    }

    const std::string& PerrierProduct::productionPlace() const
    {
        return m_production_place;
    }

    BOOST_AUTO_TEST_CASE(CreateBeverageProductOverCreatorFactory)
    {
        CreatorFactory* creator_factory = new BeverageFactory(BeverageFactory::BeverageKind::kSparklingWater);
        Product* product = creator_factory->getProduct();

        auto deleter = finalize([&]() {
            if (creator_factory != nullptr)
            {
                delete creator_factory;
            }
        #if false   // the product had already been deleted inside the CreatorFactory destructor.
            if (product != nullptr)
            {
                delete product;
            }
        #endif
        });

        auto place = dynamic_cast<PerrierProduct*>(product)->productionPlace();
        BOOST_CHECK_EQUAL(place, "France");

        BOOST_CHECK_EQUAL(dynamic_cast<CarbonatedBeveragesProduct*>(product)->isSoda(), true);
    }

BOOST_AUTO_TEST_SUITE_END()