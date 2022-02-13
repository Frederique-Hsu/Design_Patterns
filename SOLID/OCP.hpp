/*!
 *  \file   OCP.hpp
 *  \brief  
 * 
 */

#pragma once

#include <string>
#include <vector>

#define interface struct

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

/*================================================================================================*/
/*!< Prototypes: */
struct Product;
struct ProductFilter;
template<typename T> interface Specification;
template<typename T> interface Filter;
class BetterFilter;
class ColorSpecification;
class SizeSpecification;
template<typename T> class AndSpecification;

/*================================================================================================*/
/*!< Definitions: */
struct Product
{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef std::vector<Product*> Items;

    Items by_color(Items items, Color color);
    Items by_size(Items items, Size size);
    Items by_color_and_size(Items items, Color color, Size size);
};

template<typename T> interface Specification
{
    virtual bool is_satisfied(T* item) = 0;
    AndSpecification<T> operator &&(Specification<T>&& other);
};

template<typename T> interface Filter
{
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

class BetterFilter : public Filter<Product>
{
public:
    std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override;
};

class ColorSpecification : public Specification<Product>
{
private:
    Color color;
public:
    explicit ColorSpecification(const Color& color);
public:
    bool is_satisfied(Product* item) override;
};

class SizeSpecification : public Specification<Product>
{
private:
    Size size;
public:
    explicit SizeSpecification(const Size& size);
public:
    bool is_satisfied(Product* item) override;
};

template<typename T> class AndSpecification : public Specification<T>
{
private:
    Specification<T>& first;
    Specification<T>& second;
public:
    AndSpecification(Specification<T>& first, Specification<T>& second);
public:
    bool is_satisfied(T* item) override;
};

/*================================================================================================*/
/*!< Implementations: */
template<typename T> AndSpecification<T>::AndSpecification(Specification<T>& first,
                                                           Specification<T>& second)
    : first{first}, second{second}
{
}

template<typename T> bool AndSpecification<T>::is_satisfied(T* item)
{
    return (first.is_satisfied(item) && second.is_satisfied(item));
}

template<typename T> AndSpecification<T> Specification<T>::operator &&(Specification<T>&& other)
{
    return AndSpecification<T>(*this, other);
}