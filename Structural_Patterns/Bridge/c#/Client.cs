/*!
 *  \file       Client.cs
 *  \brief      
 *  
 */


using System;

using DesignPatterns.Structural_Patterns.Bridge.Abstraction;

namespace DesignPatterns.Structural_Patterns.Bridge
{
    class Client
    {
        public void execute(Abstraction abstraction)
        {
            Console.Write(abstraction.operation());
        }
    }
}