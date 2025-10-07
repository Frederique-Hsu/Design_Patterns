/*!
 *  \file       Program.cs
 *  \brief      
 *  
 */


using System;
using DesignPatterns.StructuralPatterns.Composite.Leaf;
using DesignPatterns.StructuralPatterns.Composite.Component;
using DesignPatterns.StructuralPatterns.Composite.Client;
using DesignPatterns.StructuralPatterns.Composite.Composite;


namespace DesignPatterns.StructuralPatterns.Composite
{
    class Program
    {
        static void Main(string[] args)
        {
            Leaf leaf = new Leaf();
            Console.WriteLine("Client: I get a simple component: ");

            Client.execute(leaf);

            Composite tree = new Composite();
            Composite branch1 = new Composite();
            branch1.add(new Leaf());
            branch1.add(new Leaf());

            Composite branch2 = new Composite();
            branch2.add(new Leaf());

            tree.add(branch1);
            tree.add(branch2);

            Console.WriteLine("Client: Now I have got a composite tree: ");
            Client.execute(tree);

            Console.WriteLine("Client: I don't need to check the component classes even when managing the tree: \n");
            Client.execute(tree, leaf);
        }
    }
}