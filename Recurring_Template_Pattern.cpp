/*!
 *  \file   Recurring_Template_Pattern.cpp
 *  \brief  
 *
 */

#include <iostream>

template<typename Derived> class SomeBase
{
public:
    void foo()
    {
        /*!< 
         * Use CRTP, you can actually cast this pointer from parent 
         * class to the child class type.
         */
        for (auto& item : *static_cast<Derived*>(this))
        {
        }
    }
};

struct Foo : SomeBase<Foo>
{
};


int main(int argc, char* argv[])
{
    std::cout << "Current C++ Standard No. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;
    
    return 0;
}
