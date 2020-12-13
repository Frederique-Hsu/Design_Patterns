#ifndef ADAPTER_HPP
#define ADAPTER_HPP

    #include <string>

    #include "Target.hpp"

    class Adapter;
    class Adaptee;

    /**
     *  The Adapter makes the Adaptee's interface compatible with the Target's
     */
    class Adapter : public Target
    {
    private:
        Adaptee* m_adaptee;
    public:
        explicit Adapter(Adaptee* adaptee);
        Adapter(const Adapter&) = delete;
        Adapter(Adapter&&) = delete;
        Adapter& operator=(const Adapter&) = delete;
        Adapter& operator=(Adapter&&) = delete;
        virtual ~Adapter();
    public:
        std::string Request() const override;
    };

#endif  /* ADAPTER_HPP */
