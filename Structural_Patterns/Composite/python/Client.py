# File name     : Client.py
# Description   : 
# 
# 


from Component import Component

class Client:
    @staticmethod
    def execute1(component: Component):
        '''
        The client executes with all of the components via the base interface.
        '''
        print(f"RESULT: {component.operation()}", end="")

    @staticmethod
    def execute2(component1: Component, component2: Component):
        '''
        Thanks to the fact that the child-management operations are declared in the base Component class,
        the client can work with any component, simple or complex, without depending on their concrete classes.
        '''
        if (component1.is_composite()):
            component1.add(component2)
        print(f"RESULT: {component1.operation()}", end="")