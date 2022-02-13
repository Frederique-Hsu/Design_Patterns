/*!
 *  \file       SRP.cpp
 *  \brief      Single Responsibility Principle
 *  \details    Make a comprehensive research on what is SRP in the design patterns topic, \n 
 *              and how the SRP works, how to apply the SRP on your software architecture design?
 *  \author     Frederique Hsu, and the advisor: Dmitri Nesteruk
 *  \date       Fri.    04 Feb. 2022
 *  \copyright  2022    All rights reserved.
 *  
 */


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

struct Journal
{
    std::string title;
    std::vector<std::string> entries;

    explicit Journal(const std::string& title) : title{title}
    {
    }

    void add(const std::string& entry)
    {
        static int count = 1;
        entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
    }

    const std::vector<std::string>& getEntries() const
    {
        return entries;
    }
};

struct PersistenceManager
{
    static void save(const Journal& journal, const std::string& filename)
    {
        std::ofstream ofs(filename);
        for (auto& entry : journal.entries)
        {
            ofs << entry << std::endl;
        }
    }
};

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    Journal journal{"Dear Diary"};
    journal.add("I cried today");
    journal.add("I ate a bug");

    return 0;
}