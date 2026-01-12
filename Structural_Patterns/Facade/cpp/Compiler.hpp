/*!
 *  \file       Compiler.hpp
 *  \brief      
 *  
 */


#pragma once

#include <iostream>

namespace gof_design_patterns
{
    class ByteCodeStream;

    class Compiler
    {
    public:
        Compiler();
        virtual ~Compiler();

    public:
        virtual void compile(const std::istream &, ByteCodeStream &);
    };
}