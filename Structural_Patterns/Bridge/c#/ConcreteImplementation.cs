/*!
 *  \file       ConcreteImplementation.cs
 *  \brief      
 *  
 */


using System;

using DesignPatterns.Structural_Patterns.Bridge.IImplementation;

namespace DesignPatterns.Structural_Patterns.Bridge
{
    class ConcreteImplementationA : IImplementation
    {
        public string OperationImpl()
        {
            return "ConcreteImplementationA: The result in platform A.\n";
        }
    }

    class ConcreteImplementationB : IImplementation
    {
        public string OperationImpl()
        {
            return "ConcreteImplementationB: The result in platform B.\n";
        }
    }
}