#ifndef TARGET_HPP
#define TARGET_HPP

    #include <string>

    class Target;

    /**
     *  The Target defines the domain-specific interface used by the client code.
     */
    class Target
    {
    public:
        Target() = default;
        virtual ~Target() = default;
    public:
        virtual std::string Request() const;
    };

#endif  /* TARGET_HPP */
