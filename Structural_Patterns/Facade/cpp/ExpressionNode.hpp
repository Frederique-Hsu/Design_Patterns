/*!
 *  \file       ExpressionNode.hpp
 *  \brief      
 *  
 */


#pragma once

#include "ProgramNode.hpp"

#include "List.hpp"

namespace gof_design_patterns
{
    class ExpressionNode : public ProgramNode
    {
    public:
        ExpressionNode();
        virtual ~ExpressionNode();
        
    public:
        void traverse(CodeGenerator &cg) override;
        void add(ProgramNode *) override;
        void remove(ProgramNode *) override;

    protected:
        List<ProgramNode *> *m_children;
    };
}