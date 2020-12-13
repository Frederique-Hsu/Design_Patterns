#!/usr/bin/env python3
# -*- encoding:utf-8 -*-
# 
# File name : main.py
#


from Adaptee import Adaptee
from Target import Target
from Adapter import Adapter

def client_code(target: "Target") -> None:
    '''
    The client code supports all classes that following the Target interface.
    '''
    print(target.request(), end="")

print("Client: I can work just fine with the Target objects:")
target = Target()

client_code(target)
print("\n")

adpatee = Adaptee()
print("Client: The Adaptee class has a weird interface. See, I don't understand it:")
print("Adaptee: {0}".format(adpatee.specific_request()), end = "\n\n")

print("Client: But I can work with it via the Adapter:")
adapter = Adapter()
client_code(adapter)
print("\n\n")