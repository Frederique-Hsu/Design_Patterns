# File name     : Facade.py
# Description   : 
# 
# 


from __future__ import annotations

from Subsystem import Subsystem1, Subsystem2

class Facade:
    def __init__(self, subsystem1: Subsystem1, subsystem2: Subsystem2):
        self._subsystem1 = subsystem1
        self._subsystem2 = subsystem2

    def operation(self) -> str:
        results = []
        
        results.append("Facade initializes subsystems:")
        results.append(self._subsystem1.operation1())
        results.append(self._subsystem2.operation1())

        results.append("Facade orders subsystems to perform the action:")
        results.append(self._subsystem1.operationN())
        results.append(self._subsystem2.operationZ())

        return "\n".join(results)