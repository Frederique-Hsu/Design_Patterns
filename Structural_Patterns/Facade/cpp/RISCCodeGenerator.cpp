/*!
 *  \file       RISCCodeGenerator.cpp
 *  \brief      
 *  
 */


#include "RISCCodeGenerator.hpp"


namespace gof_design_patterns
{
    RISCCodeGenerator::RISCCodeGenerator(ByteCodeStream &stream) : CodeGenerator(stream)
    {
    }

    void RISCCodeGenerator::visit(StatementNode *)
    {
        /*!
         *  \todo
         */
    }

    void RISCCodeGenerator::visit(ExpressionNode *)
    {
        /*!
         *  \todo
         */
    }
}