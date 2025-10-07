# File name     : Composite.py
# Description   : 
#
#


from typing import List
from Component import Component


class Composite(Component):
    '''
    The Composite class represents the complex components that may have children.
    Usually, the Composite objects delegate the actual work to their children and then 
    "sum-up" their result.
    '''
    def __init__(self) -> None:
        self._children : List[Component] = []

    def add(self, component: Component) -> None:
        self._children.append(component)
        component.parent = self

    def remove(self, component: Component) -> None:
        self._children.remove(component)
        component.parent = None

    def is_composite(self) -> bool:
        return True
    
    def operation(self) -> str:
        '''
        The Composite executes its primary logic in a particular way. It traverses recursively through all its children,
        collecting and summing their results. Since the composite's children pass these calls to their children and so forth,
        the whole object tree is traversed as a result.
        '''
        results = []
        for child in self._children:
            results.append(child.operation())
        return f"Branch({'+'.join(results)})"