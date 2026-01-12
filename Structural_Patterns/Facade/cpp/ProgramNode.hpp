/*!
 *  \file       ProgramNode.hpp
 *  \brief      
 *  
 */


#pragma once


namespace gof_design_patterns
{
    class CodeGenerator;

    class ProgramNode
    {
    public:
        enum class EProgramNodeType
        {
            Statement_Program_Node,
            Expression_Program_Node
        };
    public:
        virtual ~ProgramNode();
    protected:
        ProgramNode();

    public:
        virtual void getSourcePosition(int &line, int &index);

        virtual void add(ProgramNode *);
        virtual void remove(ProgramNode *);

        virtual void traverse(CodeGenerator &);
    };
}