# File name     : Main.py
# Description   : 
#
#


from Component import Component, ConcreteComponent
from Client import Client
from Decorator import ConcreteDecoratorA, ConcreteDecoratorB

def main():
    '''
    This way the client code can support both simple components...
    '''
    simple = ConcreteComponent()
    print("Client: I have got a simple component:")
    Client.execute(simple)
    print("\n")

    
    '''
    ... as well as decorated ones.

    Note how decorators can wrap not only simple component, but the other decorators as well.
    '''
    decorator1 = ConcreteDecoratorA(simple)
    decorator2 = ConcreteDecoratorB(decorator1)
    print("Client: Now I have got a decorated component:")
    Client.execute(decorator2)


if __name__ == "__main__":
    main()