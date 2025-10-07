/*!
 *  \file       Component.cs
 *  \brief      
 *  
 */


using System;
using System.Collections.Generic;


namespace DesignPatterns.StructuralPatterns.Composite
{
    abstract class Component
    {
        public Component()
        {
        }

        public abstract string operation();

        public virtual void add(Component component)
        {
            throw new NotImplementedException();
        }

        public virtual void remove(Component component)
        {
            throw new NotImplementedException();
        }

        public virtual bool isComposite()
        {
            return true;
        }
    }
}