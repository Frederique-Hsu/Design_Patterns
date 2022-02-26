/*!
 *  \file       DIP.cpp
 *  \brief      Dependency Inversion Principle
 *  \author     Frederique Shyu
 *  \date       Fri.    18 Feb. 2022
 *  
 */

#include "DIP.hpp"

Reporting::Reporting(const ILogger& logger) : logger{logger}
{
}

void Reporting::prepare_report()
{
    logger.Log("Preparing the report...");
}

std::ostream& operator<<(std::ostream& out, const Engine& obj)
{
    out << "volume: " << obj.volume
        << ", horse_power: " << obj.horse_power;
    return out;
}

ConsoleLogger::ConsoleLogger()
{
}

void ConsoleLogger::Log(const std::string& log)
{
    std::cout << "LOG: " << log.c_str() << std::endl;
}

Car::Car(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger> logger)
    : engine(std::move(engine)), logger(logger)
{
    logger->Log("making a car");
}

std::ostream& operator<<(std::ostream& out, const Car& obj)
{
    return out << "car with engine: " << *(obj.engine);
}

int main(int argc, char* argv[])
{
    return 0;
}