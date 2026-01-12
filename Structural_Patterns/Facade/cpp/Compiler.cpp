/*!
 *  \file       Compiler.cpp
 *  \brief      
 *  
 */


#include "Compiler.hpp"

#include "Scanner.hpp"
#include "ProgramNodeBuilder.hpp"
#include "Parser.hpp"
#include "RISCCodeGenerator.hpp"
#include "ProgramNode.hpp"


namespace gof_design_patterns
{
    Compiler::Compiler()
    {
    }

    Compiler::~Compiler()
    {
    }

    void Compiler::compile(const std::istream &input, ByteCodeStream &output)
    {
        Scanner scanner(const_cast<std::istream &>(input));
        ProgramNodeBuilder builder(ProgramNode::EProgramNodeType::Expression_Program_Node);
        Parser parser;

        parser.parse(scanner, builder);

        RISCCodeGenerator generator(output);
        ProgramNode *parse_tree = builder.getRootNode();
        parse_tree->traverse(generator);
    }
}