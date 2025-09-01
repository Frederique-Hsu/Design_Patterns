/*!
 *  \file       ExtendedAbstraction.cs
 *  \brief      
 *  
 */


using System;

using DesignPatterns.Structural_Patterns.Bridge.Abstraction

namespace DesignPatterns.Structural_Patterns.Bridge
{
    class ExtendedAbstraction : Abstraction
    {
        public ExtendedAbstraction(IImplementation implementor) : Base(implementor)
        {
        }

        public override string Operation()
        {
            return "ExtendedAbstraction: Extended operation with: \n" + 
                Base.m_implementor.OperationImpl();
        }
    }
}