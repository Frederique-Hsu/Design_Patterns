/*!
 *  \file   Properties.cpp
 *  \brief  
 *  
 */

#include <iostream>

class Person
{
private:
    int m_age;
public:
    int get_age() const
    {
        return m_age;
    }
    void set_age(int value)
    {
        m_age = value;
    }
    __declspec(property(get=get_age, put=set_age)) int age;
};

int main(int argc, char* argv[])
{
    Person per;
    per.age = 20;

    std::cout << "age = " << per.age << std::endl;
    return 0;
}