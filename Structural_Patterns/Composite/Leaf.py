#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Leaf.py
#

from Component import Component

class Leaf(Component):
    def operation(self) -> str:
        return "Leaf"