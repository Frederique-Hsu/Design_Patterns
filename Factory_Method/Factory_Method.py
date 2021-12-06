# File name     : Factory_Method.py
# Description   : Demonstrate how to implement Factory_Method pattern in Python.
#

from __future__ import annotations
from abc import ABC, abstractmethod

class Product(ABC):
    @abstractmethod
    def operation(self) -> str:
        pass
    
class Creator(ABC):
    @abstractmethod
    def factory_method(self):
        pass

    def some_operation(self) -> str:
        prodcut = self.factory_method()
        result = f"Creator: The same creator's code has just worked with {prodcut.operation()}"
        return result

class ConcreteCreator_PhonePlant(Creator):
    def factory_method(self) -> Product:
        return ConcreteCreator_PhonePlant()
    

class ConcreteCreator_VehiclePlant(Creator):
    def factory_method(self) ->Product:
        return ConcreteCreator_VehiclePlant()

class ConcreteProduct_PhoneAntenna(Product):
    def operation(self) -> str:
        return "{Result of the ConcreteProduct: PhoneAntenna}"

class ConcreteProduct_VehicleAntenna(Product):
    def operation(self) -> str:
        return "{Result of the ConcreteProduct: VehicleAntenna}"

def ClientCode(creator : Creator) -> None:
    print(f"Client: I am not aware of the creator's class, but it still works.\n"
          f"{creator.some_operation()}", end = "")


if __name__ == "__main__":
    print("App: Launched with the ConcreteCreator_PhonePlant.")
    ClientCode(ConcreteCreator_PhonePlant())
    print("\n")

    print("App: Launched with the ConcreteCreator_VehiclePlant.")
    ClientCode(ConcreteCreator_VehiclePlant())