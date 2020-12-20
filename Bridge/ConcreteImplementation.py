#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : ConcreteImplementation.py
#

from Implementation import Implementation

class ConcreteImplementation_A(Implementation):
    def operation_implementation(self):
        return "ConcreteImplementation_A : Here is the result on the platform A.\n"
    
class ConcreteImplementation_B(Implementation):
    def operation_implementation(self):
        return "ConcreteImplementation_B : Here is the result on the platform B.\n"