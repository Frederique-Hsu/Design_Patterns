#ifndef MULTI_INHERITANCE_ADAPTER_HPP
#define MULTI_INHERITANCE_ADAPTER_HPP

    #include "Target.hpp"
    #include "Adaptee.hpp"

    class MIAdapter;

    /**
     *  The MIAdapter makes the Adaptee's interface compatible with the Target's
     *  interface using multiple inheritance.
     */
    class MIAdapter : public Target, public Adaptee
    {
    public:
        MIAdapter() = default;
        std::string Request() const override;
    };

#endif  /* MULTI_INHERITANCE_ADAPTER_HPP */
