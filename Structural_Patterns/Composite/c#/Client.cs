/*!
 *  \file       Client.cs
 *  \brief      
 *  
 */


using System;
using DesignPatterns.StructuralPatterns.Composite.Component


namespace DesignPatterns.StructuralPatterns.Composite
{
    class Client
    {
        public static void execute(Component leaf)
        {
            Console.WriteLine($"RESULT: {leaf.operation()}");
        }

        public static void execute(Component component1, Component component2)
        {
            if (component1.isComposite())
            {
                component1.add(component2);
            }
            Console.WriteLine($"RESULT: {component1.operation()}");
        }
    }
}