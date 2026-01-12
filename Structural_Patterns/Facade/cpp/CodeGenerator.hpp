/*!
 *  \file       CodeGenerator.hpp
 *	\brief		
 *	
 */
 
 
#pragma once


namespace gof_design_patterns
{
	class StatementNode;
	class ExpressionNode;
	class ByteCodeStream;
	
	class CodeGenerator
	{
	public:
		virtual void visit(StatementNode *);
		virtual void visit(ExpressionNode *);
		
	protected:
		CodeGenerator(ByteCodeStream &);
		
	protected:
		ByteCodeStream &m_output;
	};
}