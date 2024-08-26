#!/usr/bin/env  python3
# -*- encoding: utf-8 -*-
#
# File name     : Client.py
#

from Component import Component
from Leaf import Leaf
from Composite import Composite

def client_code(component: Component):
    print(f"RESULT: {component.operation()}", end = "")

def client_code2(composite: Component, component: Component):
    if composite.is_composite():
        composite.add(component)
    print(f"RESULT: {component.operation()}", end = "")

if __name__ == "__main__":
    simple = Leaf()
    print("Client: I've got a simple component:")
    client_code(simple)
    print("\n")

    tree = Composite()
    left_branch = Composite()
    left_branch.add(Leaf())
    left_branch.add(Leaf())

    right_branch = Composite()
    right_branch.add(Leaf())

    tree.add(left_branch)
    tree.add(right_branch)
    print("Client: Now I've got a composite tree:")
    client_code(tree)
    print("\n")

    print("Client: I don't need to check the components classes even when managing the tree:")
    client_code2(tree, simple)
    print("\n")