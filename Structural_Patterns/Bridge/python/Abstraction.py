# File name     : Abstraction.py
# Description   : 
#
#


from Implementation import Implementation

class Abstraction:
    '''
    This Abstraction defines the interface for the "control" part of the 2 class
    hierarchies. It maintains a reference to an object of the Implementation hierarchy
    and delegate all of the real work to this object.
    '''
    def __init__(self, implementation : Implementation) -> None:
        self.implementation = implementation

    def operation(self) -> str:
        return (f"Abstraction: Base operation with: \n"
                f"{self.implementation.operationImpl()}")