/*!
 *  \file       RISCCodeGenerator.hpp
 *  \brief      
 *  
 */


#pragma once


#include "CodeGenerator.hpp"

namespace gof_design_patterns
{
    class RISCCodeGenerator : public CodeGenerator
    {
    public:
        RISCCodeGenerator(ByteCodeStream &);

    public:
        void visit(StatementNode *) override;
        void visit(ExpressionNode *) override;
    };
}