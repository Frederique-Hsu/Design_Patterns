# File name     : Implementation.py
# Description   : 
#
#


from abc import ABC, abstractmethod


class Implementation(ABC):
    '''
    The Implementation defines the interface for all implementation classes.
    It doesn't have to match with the Abstraction's interface.
    In fact, the two interfaces can be entirely different.  Typically the Implementation
    interface provides only primitive operations, while the Abstraction defines higher-
    level operations based on those primitives.
    '''
    @abstractmethod
    def operationImpl(self) -> str:
        pass