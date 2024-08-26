#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
#
# File name     : Implemenation.py
#

from __future__ import annotations
from abc import ABC, abstractmethod

class Implementation(ABC):

    @abstractmethod
    def operation_implementation(self) -> str:
        pass
