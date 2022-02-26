/*!
 *  \file       ISP.hpp
 *  \brief      Interface Segregation Principle
 *  \details    Demo how the ISP works in the program, and how to apply the ISP onto your design?
 *  \author     Frederique Shyu
 *  \date       Thur.   17 Feb. 2022
 *  
 */

#pragma once

/*!
 *  \remark     What is the Interface Segregation Principle?
 *
 *  \note       you can split up interfaces, so that implementors can pick and choose depending \n 
 *              on their needs.
 */

#include <vector>

#define interface struct            /*<! 取别名，使用#define宏定义 */
// typedef struct interface;        /*<! 定义新类型，使用typedef类型定义 */

#define ENABLE_ISP

class Document;

#if !defined(ENABLE_ISP)
    interface IMachine
    {
        virtual void print(std::vector<Document*> docs) = 0;
        virtual void fax(std::vector<Document*> docs) = 0;
        virtual void scan(std::vector<Document*> docs) = 0;
    };

    class MyFavouritePrinter : public IMachine
    {
    public:
        void print(std::vector<Document*> docs) override;
        void fax(std::vector<Document*> docs) override;
        void scan(std::vector<Document*> docs) override;
    };
#else
    interface IPrinter
    {
        virtual void print(std::vector<Document*> docs) = 0;
    };

    interface IScanner
    {
        virtual void scan(std::vector<Document*> docs) = 0;
    };

    interface IFax
    {
        virtual void fax(std::vector<Document*> docs) = 0;
    };

    class Printer : public IPrinter
    {
    public:
        void print(std::vector<Document*> docs) override;
    };

    class Scanner : public IScanner
    {
    public:
        void scan(std::vector<Document*> docs) override;
    };

    interface IMachine : IPrinter, IScanner
    {
    };

    class Machine : public IMachine
    {
    private:
        IPrinter& printer;
        IScanner& scanner;
    public:
        Machine(IPrinter& printer, IScanner& scanner);
    public:
        void print(std::vector<Document*> docs) override;
        void scan(std::vector<Document*> docs) override;
    };
#endif