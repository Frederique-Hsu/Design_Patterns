# File name     : Leaf.py
# Description   : 
#
#


from Component import Component


class Leaf(Component):
    '''
    The Leaf class represents the end objects of a composition.
    A leaf cannot have any children.

    Usually, it is the leaf objects that do the actual work, wherease Composite objects
    only delegate to their sub-components.
    '''
    def operation(self) -> str:
        return "Leaf"