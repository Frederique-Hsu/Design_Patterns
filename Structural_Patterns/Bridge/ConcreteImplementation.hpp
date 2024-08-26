#ifndef CONCRETE_IMPLEMENTATION_HPP
#define CONCRETE_IMPLEMENTATION_HPP

    #include "Implementation.hpp"

    class ConcreteImplementation_A;
    class ConcreteImplementation_B;

    /**
     *  Each concrete implementation corresponds to a specific platform,
     *  and implements the Implementation interface using that platform's API.
     */
    class ConcreteImplementation_A : public Implementation
    {
    public:
        std::string OperationImplementation() const override;
    };

    class ConcreteImplementation_B : public Implementation
    {
    public:
        std::string OperationImplementation() const override;
    };

#endif  /* CONCRETE_IMPLEMENTATION_HPP */