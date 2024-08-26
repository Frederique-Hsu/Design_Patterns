#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : main.py
#

from Implementation import Implementation
from ConcreteImplementation import ConcreteImplementation_A, ConcreteImplementation_B
from Abstraction import Abstraction
from ExtendedAbstraction import ExtendedAbstraction

def ClientCode(abstract : Abstraction) -> None:
    print(abstract.operation())


if __name__ == "__main__":
    impl = ConcreteImplementation_A()
    abstract = Abstraction(impl)
    ClientCode(abstract)
    
    print("\n")
    
    impl = ConcreteImplementation_B()
    abstract = ExtendedAbstraction(impl)
    ClientCode(abstract)