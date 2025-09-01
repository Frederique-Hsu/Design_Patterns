/*!
 *  \file       Abstraction.cs
 *  \brief      
 *  
 */


using System;

using DesignPatterns.Structural_Patterns.Bridge.IImplementation;


namespace DesignPatterns.Structural_Patterns.Bridge
{
    class Abstraction
    {
        protected IImplementation m_implementor;

        public Abstraction(IImplementation implementor)
        {
            this.m_implementor = implementor;
        }

        public virtual string Operation()
        {
            return "Abstraction: Base operation with: \n" + m_implementor.OperationImpl();
        }
    }
}