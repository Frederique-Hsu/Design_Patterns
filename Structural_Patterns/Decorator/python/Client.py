# File name     : Client.py
# Description   : 
#
#


from Component import Component

class Client:
    @staticmethod
    def execute(component : Component):
        '''
        The client code works with all objects using the Component interface.
        This way it can stay independent of the concrete class of component it works with.
        '''
        print(f"RESULT: {component.operation()}", end="")