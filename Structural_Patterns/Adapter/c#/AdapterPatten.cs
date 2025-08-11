/**
 *  @file       AdapterPattern.cs
 *  @brief
 *
 */



using System;


namespace DesignPatterns.Adapter
{
    public interface ITarget
    {
        string GetRequest();
    }

    public class Adaptee
    {
        public string GetSpecificRequest()
        {
            return "Specific request";
        }
    }

    public class Adapter : ITarget
    {
        private readonly Adaptee m_adaptee;

        public Adapter(Adaptee adaptee)
        {
            this.m_adaptee = adaptee;
        }

        public string GetRequest()
        {
            return $"This is '{this.m_adaptee.GetSpecificRequest()}'";
        }
    }

    public class AdapterPattern
    {
        public static void Main(string[] args)
        {
            Adaptee adaptee = new Adaptee();
            ITarget target = new Adapter(adaptee);

            Console.WriteLine("Adaptee interface is incompatible with the client");
            Console.WriteLine("But with adapter, client can call its method.");

            Console.WriteLine(target.GetRequest());
        }
    }
}
