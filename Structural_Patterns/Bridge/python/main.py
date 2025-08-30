# File name     : main.py
# Description   : 
#
#


from ConcreteImplementation import ConcreteImplementationA, ConcreteImplementationB
from Abstraction import Abstraction
from Client import Client
from ExtendedAbstraction import ExtendedAbstraction

def run():
    '''
    The client should be able to work with any pre-configured abstraction-implementation combination
    '''
    implementor = ConcreteImplementationA()
    abstractor = Abstraction(implementor)
    Client.execute(abstractor)
    print("\n")

    implementor = ConcreteImplementationB()
    abstractor = ExtendedAbstraction(implementor)
    Client.execute(abstractor)
    print("\n")



if __name__ == "__main__":
    run()