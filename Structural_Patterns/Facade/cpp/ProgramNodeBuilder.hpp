/*!
 *  \file       ProgramNodeBuilder.hpp
 *  \brief      
 *  
 */


#pragma once

#include "ProgramNode.hpp"

namespace gof_design_patterns
{

    class ProgramNodeBuilder
    {
    public:
        ProgramNodeBuilder(ProgramNode::EProgramNodeType type);
        virtual ~ProgramNodeBuilder();

    private:
        ProgramNode *m_node;

    public:
        virtual ProgramNode* newVariable(const char *variable_name) const;
        virtual ProgramNode* newAssignment(ProgramNode *variable, ProgramNode *expression) const;
        virtual ProgramNode* newReturnStatement(ProgramNode *value) const;
        virtual ProgramNode* newCondition(ProgramNode *condition,
                                          ProgramNode *true_part,
                                          ProgramNode *false_part) const;
        ProgramNode* getRootNode();
    };
}