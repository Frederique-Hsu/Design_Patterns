#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# 
# File name     : Adaptee.py
#

class Adaptee:
    '''
    The Adaptee contains some useful behaviour, but its interface is incompatible with the 
    existing client code. The Adaptee needs some adaptation before the client code can use it.
    '''
    def specific_request(self) -> str:
        return ".eetpadA eht fo ruoivaheb laicepS"

if __name__ == "__main__":
    adaptee = Adaptee()
    adaptee.specific_request()