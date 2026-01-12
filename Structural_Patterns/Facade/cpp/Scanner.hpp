/*!
 *  \file       Scanner.hpp
 *  \brief      
 *  
 */


#pragma once

#include <iostream>

namespace gof_design_patterns
{
    class Token;

    class Scanner
    {
    public:
        Scanner(std::istream &);
        virtual ~Scanner();

    public:
        virtual Token& scan();

    private:
        [[maybe_unused]] std::istream& m_input_stream;
    };
}