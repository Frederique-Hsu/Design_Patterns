# File name     : main.py
# Description   : 
#
#


from Subsystem import Subsystem1, Subsystem2
from Facade import Facade
from Client import Client


def main():
    subsystem1 = Subsystem1()
    subsystem2 = Subsystem2()

    facade = Facade(subsystem1, subsystem2)

    Client.execute(facade)


if __name__ == "__main__":
    main()