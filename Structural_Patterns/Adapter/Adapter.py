#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Adapter.py
#

from Adaptee import Adaptee
from Target import Target

class Adapter(Target, Adaptee):
    '''
    The Adapter makes the Adaptee's interface compatible with the Target's interface via multiple inheritance.
    '''
    def request(self) -> str:
        return f"Adapter: (TRANSLATED) {self.specific_request()[::-1]}"

if __name__ == "__main__":
    adapter = Adapter()
    adapter.request()