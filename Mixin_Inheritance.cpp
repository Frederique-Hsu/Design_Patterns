/*!
 *  \file   Mixin_Inheritance.cpp
 *  \brief  Demo how to define a mixin class, with the hierarchical composition of types. 
 *  
 */

#include <iostream>

template<typename T> class Mixin : public T
{
};

#define MIXIN_CLASS(templateArgName, templateClassName) \
    template<typename templateArgName> class templateClassName : public templateArgName   \
    {   \
    }

#if 1
    template<typename T> class Foo : public T
    {
    };

    template<typename T> class Bar : public T
    {
    };
#else
    MIXIN_CLASS(T, Foo);
    MIXIN_CLASS(T, Bar);
#endif

class Tor
{
};

int main(int argc, char* argv[])
{
    Foo<Bar<Tor>> X;
    std::cout << "sizeof(Foo<Bar<Tor>>) = " << sizeof(Foo<Bar<Tor>>) << std::endl;

    return 0;
}