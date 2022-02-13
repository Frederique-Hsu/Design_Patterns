/*!
 *  \file       OCP.cpp
 *  \brief      Open-Closed Principle
 *  \details    Make a comprehensive research on the design patterns principle: Open-Closed Principle \n 
 *              and demo how to apply this principle onto the project.
 *  \author     Frederique Shyu
 *  \date       Mon.    07 Feb. 2022
 *  \copyright  2022    All rights reserved.
 *  
 */


#include <iostream>
#include "OCP.hpp"

ProductFilter::Items ProductFilter::by_color(ProductFilter::Items items, Color color)
{
    Items result;
    for (auto& item : items)
    {
        if (item->color == color)
        {
            result.push_back(item);
        }
    }
    return result;
}

ProductFilter::Items ProductFilter::by_size(ProductFilter::Items items, Size size)
{
    Items result;
    for (auto& item : items)
    {
        if (item->size == size)
        {
            result.push_back(item);
        }
    }
    return result;
}

ProductFilter::Items ProductFilter::by_color_and_size(ProductFilter::Items items, 
                                                      Color color, 
                                                      Size size)
{
    Items result;
    for (auto& item : items)
    {
        if ((item->color == color) && (item->size == size))
        {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<Product*> BetterFilter::filter(std::vector<Product*> items, 
                                           Specification<Product>& spec)
{
    std::vector<Product*> result;
    for (auto& prod : items)
    {
        if (spec.is_satisfied(prod))
            result.push_back(prod);
    }
    return result;
}

ColorSpecification::ColorSpecification(const Color& color) : color{color}
{
}

bool ColorSpecification::is_satisfied(Product* item)
{
    return (item->color == color);
}

SizeSpecification::SizeSpecification(const Size& size) : size{size}
{
}

bool SizeSpecification::is_satisfied(Product* item)
{
    return (item->size == size);
}


int main(int argc, char* argv[])
{
    Product apple{"Apple", Color::Green, Size::Small};
    Product tree{"Tree", Color::Green, Size::Large};
    Product house{"House", Color::Blue, Size::Large};

    std::vector<Product*> all{&apple, &tree, &house};
    BetterFilter bf;
    ColorSpecification green(Color::Green);
    SizeSpecification large(Size::Large);
    AndSpecification<Product> green_and_large(large, green);
    // auto green_and_large = ColorSpecification(Color::Green) && SizeSpecification(Size::Large);
#if 0
    auto green_things = bf.filter(all, green);
    for (auto& elem : green_things)
    {
        std::cout << elem->name << " is green" << std::endl;
    }
#else
    auto big_green_things = bf.filter(all, green_and_large);
    for (auto& elem : big_green_things)
    {
        std::cout << elem->name << " is large and green." << std::endl;
    }
#endif
    return 0;
}