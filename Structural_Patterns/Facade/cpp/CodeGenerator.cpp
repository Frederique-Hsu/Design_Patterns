/*!
 *	\file		CodeGenerator.cpp
 *	\brief		
 *	
 */
 
 
#include "CodeGenerator.hpp"


namespace gof_design_patterns
{
	CodeGenerator::CodeGenerator(ByteCodeStream &stream) : m_output{stream}
	{
	}
	
	void CodeGenerator::visit(StatementNode *)
	{
		/*!
		 *	\todo
		 */
	}
	
	void CodeGenerator::visit(ExpressionNode *)
	{
		/*!
		 *	\todo
		 */
	}
}