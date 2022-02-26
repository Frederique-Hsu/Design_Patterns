/*!
 *  \file       SRP.hpp
 *  \brief      Single Responsibility Principle
 *  \details    Demo how the SRP works, and how to apply the SRP onto your design?
 *  \author     Frederique Shyu
 *  \date       Fri.    18 Feb. 2022
 *  
 */

#pragma once

#include <string>
#include <vector>

struct Journal
{
    std::string title;
    std::vector<std::string> entries;
    
    explicit Journal(const std::string& title);
    void add(const std::string& entry);
};

struct PersistenceManager
{
    static void save(const Journal& journal, const std::string& file);
};
