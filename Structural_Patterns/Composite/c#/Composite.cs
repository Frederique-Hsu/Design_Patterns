/*!
 *  \file       Composite.cs
 *  \brief      
 *  
 */


using System;
using System.Collections.Generic
using DesignPatterns.StructuralPatterns.Composite.Component


namespace DesignPatterns.StructuralPatterns.Composite
{
    public class Composite : Component
    {
        protected List<Component> m_children = new List<Component>();

        public override void add(Component component)
        {
            m_children.add(component);
        }

        public override void remove(Component component)
        {
            m_children.remove(component);
        }

        public override string operation()
        {
            int i = 0;
            string result = "Branch(";

            foreach (Component component in m_children)
            {
                result += component.operation();
                if (i != m_children.Count() - 1)
                {
                    result += "+";
                }
                i++;
            }
            return result + ")";
        }
    }
}