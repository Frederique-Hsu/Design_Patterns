/*!
 *  \file       ISP.cpp
 *  \brief      Interface Segregation Principle
 *  \details    Demo how the ISP works in the program, and how to apply the ISP onto your design?
 *  \author     Frederique Shyu
 *  \date       Thur.   17 Feb. 2022
 *  
 */

#include "ISP.hpp"

Machine::Machine(IPrinter& printer, IScanner& scanner) : printer{printer}, scanner{scanner}
{
}

void Machine::print(std::vector<Document*> docs)
{
    printer.print(docs);
}

void Machine::scan(std::vector<Document*> docs)
{
    scanner.scan(docs);
}

int main(int argc, char* argv[])
{
    return 0;
}