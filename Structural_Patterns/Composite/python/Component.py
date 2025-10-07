# File name     : Component.py
# Description   : 
#
#


from __future__ import annotations
from abc import ABC, abstractmethod


class Component(ABC):
    '''
    The base Component class declares common operations for both simple and complex objects of a composition
    '''
    @property
    def parent(self) -> Component:
        return self._parent
    
    @parent.setter
    def parent(self, parent: Component):
        self._parent = parent

    def add(self, component: Component) -> None:
        pass

    def remove(self, component: Component) -> None:
        pass

    def is_composite(self) -> bool:
        return False
    
    @abstractmethod
    def operation(self) -> str:
        pass