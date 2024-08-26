#ifndef CONCRETE_PRODUCT_HPP
#define CONCRETE_PRODUCT_HPP

    #include "Product.h++"

    class ConcreteProduct_PhoneAntenna;
    class ConcreteProduct_VehicleAntenna;

    class ConcreteProduct_PhoneAntenna : public Product
    {
    public:
        std::string Operation() const override;
    };

    class ConcreteProduct_VehicleAntenna : public Product
    {
    public:
        std::string Operation() const override;
    };

#endif  /* CONCRETE_PRODUCT_HPP */
