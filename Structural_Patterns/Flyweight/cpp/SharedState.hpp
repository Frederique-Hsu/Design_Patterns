/*!
 *  \file       SharedState.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>
#include <iostream>

namespace dive_into_design_patterns
{
    class SharedState
    {
        friend std::ostream& operator<<(std::ostream &os, const SharedState &ss);
    public:
        SharedState(const std::string &brand, 
                    const std::string &model, 
                    const std::string &color);

    private:
        std::string m_brand;
        std::string m_model;
        std::string m_color;

    public:
        std::string getBrand() const;
        std::string getModel() const;
        std::string getColor() const;
    };
}
