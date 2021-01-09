#ifndef PRODUCT_HPP
#define PRODUCT_HPP

    #include <string>

    class Product;

    class Product
    {
    public:
        virtual ~Product();
    public:
        virtual std::string Operation() const = 0;
    };

#endif  /* PRODUCT_HPP */