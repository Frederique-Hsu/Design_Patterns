#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : ExtendedAbstraction.py
#

from Abstraction import Abstraction

class ExtendedAbstraction(Abstraction):
    def operation(self):
        return ("ExtendedAbstraction: Extended operation with:\n" +
                self.impl.operation_implementation())