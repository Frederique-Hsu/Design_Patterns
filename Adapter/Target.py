#!/usr/bin/env python3
# -*- encoding:utf-8 -*-
#
# File name     : target.py
#


class Target:
    '''
    The Target defines the domain-specific interface used by the client code.
    '''
    def request(self) -> str:
        return "Target: The default target's behaviour.\n"

if __name__ == "__main__":
    target = Target()
    target.request()