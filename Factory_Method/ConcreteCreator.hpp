#ifndef CONCRETE_CREATOR_HPP
#define CONCRETE_CREATOR_HPP

    #include "Creator.hh"

    class Product;
    class ConcreteCreator_PhonePlant;
    class ConcreteCreator_VehiclePlant;

    class ConcreteCreator_PhonePlant : public Creator
    {
    public:
        Product* FactoryMethod() const override;
    };

    class ConcreteCreator_VehiclePlant : public Creator
    {
    public:
        Product* FactoryMethod() const override;
    };

#endif  /* CONCRETE_CREATOR_HPP */
