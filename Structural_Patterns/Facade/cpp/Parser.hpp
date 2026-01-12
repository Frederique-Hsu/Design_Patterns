/*!
 *  \file       Parser.hpp
 *  \brief      
 *  
 */


#pragma once


namespace gof_design_patterns
{
    class Scanner;
    class ProgramNodeBuilder;
    
    class Parser
    {
    public:
        Parser();
        virtual ~Parser();

    public:
        virtual void parse(Scanner &, ProgramNodeBuilder &);
    };
}