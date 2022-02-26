/*!
 *  \file       DIP.hpp
 *  \brief      Dependency Inversion Principle
 *  \details    Demo how the DIP works, and how to apply the DIP onto your design?
 *  \author     Frederique Shyu
 *  \date       Fri.    18 Feb. 2022
 *  
 */

#ifndef DIP_HPP
#define DIP_HPP

    /*!
     *  \remark What is the Dependency Inversion Principle
     *  \note   High-level modules should not depend on low-level modules. \n 
     *          Both should depend on abstractions. \n 
     *          
     *          Abstractions should not depend on details. Details should \n 
     *          on abstractions.
     */

    #include <string>
    #include <iostream>
    #include <memory>

    #define interface struct

    interface ILogger
    {
        virtual ~ILogger() {}
        virtual void Log(const std::string& log) = 0;
    };

    class Reporting
    {
    private:
        ILogger& logger;
    public:
        Reporting(const ILogger& logger);
        void prepare_report();
    };

    struct Engine
    {
        float volume = 5;
        int horse_power = 400;

        friend std::ostream& operator<<(std::ostream& out, const Engine& obj);
    };

    class ConsoleLogger : public ILogger
    {
    public:
        ConsoleLogger();
    public:
        void Log(const std::string& log) override;
    };

    class Car
    {
    private:
        std::unique_ptr<Engine> engine;
        std::shared_ptr<ILogger> logger;
    public:
        Car(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger);

        friend std::ostream& operator<<(std::ostream& out, const Car& obj);
    };

#endif  /* DIP_HPP */