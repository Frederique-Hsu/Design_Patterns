#ifndef ABSTRATION_HPP
#define ABSTRATION_HPP

    #include <string>

    class Abstraction;
    class Implementation;

    class Abstraction
    {
    protected:
        Implementation* m_impl;
    public:
        Abstraction(Implementation* impl);
        virtual ~Abstraction();
        virtual std::string Operation() const;
    };

#endif  /* ABSTRATION_HPP */