/*!
 *  \file       Program.cs
 *  \brief      
 *  
 */


using System;

using DesignPatterns.Structural_Patterns.Bridge.Client;
using DesignPatterns.Structural_Patterns.Bridge.Abstraction;
using DesignPatterns.Structural_Patterns.Bridge.IImplementation;
using DesignPatterns.Structural_Patterns.Bridge.ConcreteImplementation;


namespace DesignPatterns.Structural_Patterns.Bridge
{
    class Program
    {
        static void Main(string[] args)
        {
            Client client = new Client();

            Abstraction abstraction;
            abstraction = new Abstraction(new ConcreteImplementationA());
            client.execute(abstraction);
            Console.WriteLine();

            abstraction = new ExtendedAbstraction(new ConcreteImplementationB());
            client.execute(abstraction);
            Console.WriteLine();
        }
    }
}