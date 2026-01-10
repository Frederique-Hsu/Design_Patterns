# File          : Component.py
# Description   : 
# 
# 


class Component:
    '''
    The base Component interface defines operations that can be altered by decorators.
    '''
    def operation(self) -> str:
        pass


class ConcreteComponent(Component):
    '''
    Concrete Components provide default implementation of the operation.
    There might be several variations of these classes
    '''
    def operation(self) -> str:
        return "ConcreteComponent"
    

if __name__ == "__main__":
    concrete_component = ConcreteComponent()

    concrete_component.operation()