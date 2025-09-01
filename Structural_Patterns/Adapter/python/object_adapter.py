# File name     : object_adapter.py
# Description   :
# Author        :
# Date          :
#
#


class Target:
    def request(self) -> str:
        return "Target: The default target's behaviour"


class Adaptee:
    def specificRequest(self):
        return ".eetpadA eht fo ruoivaheb laicepS"


class Adapter(Target):
    def __init__(self, adaptee : Adaptee) -> None:
        self.adaptee = adaptee

    def request(self) -> str:
        return f"Adapter: (TRANSLATED) {self.adaptee.specificRequest()[::-1]}"

def clientExecute(target : Target):
    print(target.request(), end="")



if __name__ == "__main__":
    print("Client: I can work just fine with the Target objects:")

    target = Target()
    clientExecute(target)
    print("\n")

    adaptee = Adaptee()
    print("Client: The Adaptee class has a weird interface. See, I don't understand it:")
    print(f"Adaptee: {adaptee.specificRequest()}", end="\n\n")

    print("Client: But I can work with it via the Adapter:")
    adapter = Adapter(adaptee)
    clientExecute(adapter)
