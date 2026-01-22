# File name     : main.py
# Description   : 
#
#


from FlyweightFactory import FlyweightFactory
from Client import Client

def main():
    factory = FlyweightFactory([["Chevrolet", "Camaro2018", "pink"],
                                ["Mercedes Benz", "C300", "black"],
                                ["Mercedes Benz", "C500", "red"],
                                ["BMW", "M5", "red"],
                                ["BMW", "X6", "white"]])
    factory.list_flyweights()

    Client.add_car_into_police_database(factory, "CL234IR", "James Doe", "BMW", "M5", "red")
    Client.add_car_into_police_database(factory, "CL234IR", "James Doe", "BMW", "X1", "red")

    print("\n")
    factory.list_flyweights()



if __name__ == "__main__":
    main()