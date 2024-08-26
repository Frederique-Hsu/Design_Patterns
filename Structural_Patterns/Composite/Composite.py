#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Composite.py
#

from Component import Component
from typing import List

class Composite(Component):
    def __init__(self):
        self._children : List[Component] = []
    
    def add(self, component: Component) -> None:
        self._children.append(component)
        component.parent = self
    
    def remove(self, component: Component) -> None:
        for child in self._children:
            if child == component:
                self._children.remove(child)
                component.parent = None
                break
    
    def is_composite(self):
        if len(self._children) == 0:
            return False
        else:
            return True
    
    def operation(self):
        results = []
        for child in self._children:
            results.append(child.operation())
        return f"Branch({'+'.join(results)})"