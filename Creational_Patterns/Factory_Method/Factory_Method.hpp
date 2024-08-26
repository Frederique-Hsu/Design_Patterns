/*!
 *  \file   Factory_Method.hpp
 *  \brief  Demonstrate how the Factory Method pattern work.
 *  \author Frederique Hsu
 *  \date   Tue.    07 Dec. 2021
 * 
 */

#ifndef FACTORY_METHOD_HPP
#define FACTORY_METHOD_HPP

    #include <string>

    class Product;
    class ConcreteProduct_PhoneAntenna;
    class ConcreteProduct_VehicleAntenna;
    class Creator;
    class ConcreteCreator_PhoneFactory;
    class ConcreteCreator_VehicleFactory;

    class Product
    {
    public:
        virtual ~Product();
        virtual std::string Operation() const = 0;
    };

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

    class Creator
    {
    public:
        virtual ~Creator();
        virtual Product* FactoryMethod() const = 0;
        std::string SomeOperation() const;
    };

    class ConcreteCreator_PhoneFactory : public Creator
    {
    public:
        Product* FactoryMethod() const override;
    };

    class ConcreteCreator_VehicleFactory : public Creator
    {
    public:
        Product* FactoryMethod() const override;
    };

    void ClientCode(const Creator& creator);

#endif  /* FACTORY_METHOD_HPP */