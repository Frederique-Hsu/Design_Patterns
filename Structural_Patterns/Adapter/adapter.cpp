/*!
 *  \file       adapter.cpp
 *  \brief      
 *  
 */


#include "adapter.hpp"
#include "adaptee.hpp"

#include <iostream>

Adapter::Adapter()
{
    m_dxf_parser = new DxfParser();
    m_path_planner = new PathPlanner();
}

Adapter::~Adapter()
{
    delete m_dxf_parser;
    delete m_path_planner;
}

void Adapter::pathPlanning()
{
    std::cout << "Path planning..." << std::endl;

    m_dxf_parser->parseFile();
    m_path_planner->calculate();
}