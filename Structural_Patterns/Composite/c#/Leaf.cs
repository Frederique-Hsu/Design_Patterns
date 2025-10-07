/*!
 *  \file       Leaf.cs
 *  \brief      
 *  
 */


using System;
using DesignPatterns.StructuralPatterns.Composite.Component;

namespace DesignPatterns.StructuralPatterns.Composite
{
    public class Leaf : Component
    {
        public override string operation()
        {
            return "Leaf";
        }

        public override bool isComposite()
        {
            return false;
        }
    }
}