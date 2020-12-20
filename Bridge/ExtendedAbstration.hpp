#ifndef EXTENDED_ABSTRATION_HPP
#define EXTENDED_ABSTRATION_HPP

    #include "Abstration.hpp"

    class ExtendedAbstraction;

    class ExtendedAbstraction : public Abstraction
    {
    public:
        ExtendedAbstraction(Implementation* impl);
        std::string Operation() const override;
    };

#endif  /* EXTENDED_ABSTRATION_HPP */
