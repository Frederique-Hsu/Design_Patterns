/*!
 *  \file       ProgramNodeBuilder.cpp
 *  \brief      
 *  
 */


#include "ProgramNodeBuilder.hpp"

#include "StatementNode.hpp"
#include "ExpressionNode.hpp"


namespace gof_design_patterns
{
    ProgramNodeBuilder::ProgramNodeBuilder(ProgramNode::EProgramNodeType type) : m_node{nullptr}
    {
        switch (type)
        {
        case ProgramNode::EProgramNodeType::Statement_Program_Node:
            m_node = new StatementNode();
            break;
        case ProgramNode::EProgramNodeType::Expression_Program_Node:
            m_node = new ExpressionNode();
            break;
        }
    }

    ProgramNodeBuilder::~ProgramNodeBuilder()
    {
        if (m_node)
        {
            delete m_node;
            m_node = nullptr;
        }
    }

    ProgramNode* ProgramNodeBuilder::newVariable(const char* variable_name) const
    {
        (void)variable_name;
        /*!
         *  \todo
         */
        return nullptr;
    }

    ProgramNode* ProgramNodeBuilder::newAssignment(ProgramNode *variable, 
                                                   ProgramNode *expression) const
    {
        (void)variable;
        (void)expression;
        /*!
         *  \todo
         */
        return nullptr;
    }

    ProgramNode* ProgramNodeBuilder::newReturnStatement(ProgramNode *value) const
    {
        (void)value;
        /*!
         *  \todo
         */
        return nullptr;
    }

    ProgramNode* ProgramNodeBuilder::newCondition(ProgramNode *condition,
                                                  ProgramNode *true_part,
                                                  ProgramNode *false_part) const
    {
        (void)condition;
        (void)true_part;
        (void)false_part;
        /*!
         *  \todo   
         */
        return nullptr;
    }

    ProgramNode* ProgramNodeBuilder::getRootNode()
    {
        return m_node;
    }
}