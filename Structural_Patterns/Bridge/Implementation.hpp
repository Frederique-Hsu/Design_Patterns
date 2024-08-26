#ifndef IMPLEMENTATION_HPP
#define IMPLEMENTATION_HPP

    #include <string>

    /**
     *  The Implementation define the interface for all implementation classes.
     *  It doesn't have to match the Abstraction's interface. In fact, the two
     *  interfaces can be entirely different. 
     *  Typically the Implementation interface provides only primitive operations,
     *  while the Abstraction defines higher-level operations based on those primitives.
     */

    class Implementation;

    class Implementation
    {
    public:
        virtual ~Implementation();
        virtual std::string OperationImplementation() const = 0;
    };

#endif  /* IMPLEMENTATION_HPP */
