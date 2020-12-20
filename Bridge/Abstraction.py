#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Abstraction.py
#

from Implementation import Implementation

class Abstraction:
    def __init__(self, impl : Implementation):
        self.impl = impl
    
    def operation(self):
        return "Abstraction: Base operation with:\n" + self.impl.operation_implementation()
    
