/*!
 *  \file       SharedState.cpp
 *  \brief      
 *  
 */


#include "SharedState.hpp"


namespace dive_into_design_patterns
{
    SharedState::SharedState(const std::string &brand, const std::string &model, const std::string &color)
        : m_brand{brand}, m_model{model}, m_color{color}
    {
    }

    std::ostream& operator<<(std::ostream &os, const SharedState &ss)
    {
        os << "[" << ss.m_brand << ", " << ss.m_model << ", " << ss.m_color << "]";
        return os;
    }

    std::string SharedState::getBrand() const
    {
        return m_brand;
    }

    std::string SharedState::getModel() const
    {
        return m_model;
    }

    std::string SharedState::getColor() const
    {
        return m_color;
    }
}
