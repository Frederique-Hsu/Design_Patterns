/*!
 *  \file       ExpressionNode.cpp
 *  \brief      
 *  
 */


#include "ExpressionNode.hpp"

#include "CodeGenerator.hpp"
#include "ListIterator.hpp"

namespace gof_design_patterns
{
	ExpressionNode::ExpressionNode() : ProgramNode(), m_children{new List<ProgramNode*>()}
	{
	}
	
	ExpressionNode::~ExpressionNode()
	{
		if (m_children)
		{
			delete m_children;
			m_children = nullptr;
		}
	}
	
    void ExpressionNode::traverse(CodeGenerator &cg)
    {
        cg.visit(this);

        ListIterator<ProgramNode *> iter(m_children);
        for (iter.first(); !iter.isDone(); iter.next())
        {
            iter.currentItem()->traverse(cg);
        }
    }

    void ExpressionNode::add(ProgramNode *node)
    {
        m_children->append(node);
    }

    void ExpressionNode::remove(ProgramNode *node)
    {
        m_children->remove(node);
    }
}