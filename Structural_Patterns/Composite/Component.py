#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Component.py
# Description   : Define the class Component.
#


from __future__ import annotations
from abc import ABC, abstractmethod

class Component(ABC):
    @property
    def parent(self):
        return self._parent
    
    @parent.setter
    def parent(self, parent: Component):
        self._parent = parent
    
    def add(self, component: Component) -> None:
        pass

    def remove(self, component: Component) -> None:
        pass

    def is_composite(self) ->bool:
        return False
    
    def operation(self) -> str:
        pass