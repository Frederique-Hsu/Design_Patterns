#ifndef CREATOR_HH
#define CREATOR_HH

    #include <string>
    
    class Creator;
    class Product;

    class Creator
    {
    public:
        virtual ~Creator();
    public:
        virtual Product* FactoryMethod() const = 0;
        std::string SomeOperation() const;
    };

#endif  /* CREATOR_HH */