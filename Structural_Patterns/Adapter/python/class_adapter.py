# File name     : class_adapter.py
# Description   :
# Author        : Frederique Hsu
# Date          : Mon.  11 Aug. 2025
#
#


class Target:
    '''
    The Target defines the domain-specific interface used by the client code.
    '''
    def request(self) -> str:
        return "Target: The default target's behaviour."


class Adaptee:
    '''
    The Adpatee contains some useful behaviours, but its interface is incompatible with the
    existing client code.
    The Adaptee needs some adaptation before the client code can use it.
    '''
    def specificRequest(self) -> str:
        return ".eetpadA eht fo ruoivaheb cificepS"


class Adapter(Target, Adaptee):
    def request(self) -> str:
        return f"Adapter: (TRANSLATED) {self.specificRequest()[::-1]}"


def clientExecute(target : Target) -> None:
    '''
    The client code supports all classes that follow the Target interface.
    '''
    print(target.request(), end="")


if __name__ == "__main__":
    print("Client: I can work just fine with the Target objects")
    target = Target()
    clientExecute(target)
    print("\n")

    adaptee = Adaptee()
    print("Client: The Adaptee class has a weird interface."
          "See, I don't understanda it.")
    print("Adaptee: {adaptee.specificRequest()}", end="\n\n")

    print("Client: But I can work with it via the Adapter:")
    adapter = Adapter()
    clientExecute(adapter)
