/*!
 *  \file       Client.cpp
 *  \brief      
 *  
 */


#include "Client.hpp"

#include "Handler.hpp"

#include <vector>
#include <iostream>

void Client::execute(Handler& handler)
{
    using Food = std::string;
    std::vector<Food> foods{"Nut", "Banana", "Cup of Coffee"};

    for (const Food& food : foods)
    {
        std::cout << "Client: Who wants a " << food << "?" << std::endl;
        const std::string result = handler.handle(food);

        if (!result.empty())
        {
            std::cout << "\t" << result;
        }
        else
        {
            std::cout << "\t" << food << " was left untouched." << std::endl;
        }
    }
}