/*!
 *  \file       adapter.hpp
 *  \brief      
 *  
 */


#pragma once

#include "target.hpp"


class DxfParser;
class PathPlanner;
/*!
 *  \brief  Define the class for adapter
 */
class Adapter : public Controller
{
public:
    Adapter();
    ~Adapter();
    Adapter(const Adapter&) = delete;
    Adapter& operator=(const Adapter&) = delete;
private:
    DxfParser*      m_dxf_parser;
    PathPlanner*   m_path_planner;
public:
    void pathPlanning();
};