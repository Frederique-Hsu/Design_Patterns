/*!
 *  \file       Scanner.cpp
 *  \brief      
 *  
 */


#include "Scanner.hpp"

#include "Token.hpp"


namespace gof_design_patterns
{
    Scanner::Scanner(std::istream &stream) : m_input_stream{stream}
    {
    }

    Scanner::~Scanner()
    {
    }

    Token& Scanner::scan()
    {
        static Token dummy_token;
        return dummy_token;
    }
}