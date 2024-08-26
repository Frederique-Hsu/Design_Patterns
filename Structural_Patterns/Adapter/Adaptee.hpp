#ifndef ADPATEE_HPP
#define ADPATEE_HPP

    #include <string>

    class Adaptee;

    /**
     *  The Adaptee contains some useful behaviour, but its interface is incompatible with
     *  the existing client code. The Adaptee needs some adaptation before the client code
     *  can use it.
     */
    class Adaptee
    {
    public:
        std::string SpecificRequest() const;
    };

#endif  /* ADPATEE_HPP */
