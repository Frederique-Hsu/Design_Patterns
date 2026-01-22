# File name     : Client.py
# Description   : 
#
#


from FlyweightFactory import FlyweightFactory

class Client:
    @staticmethod
    def add_car_into_police_database(factory: FlyweightFactory,
                                     plates: str,
                                     owner: str,
                                     brand: str,
                                     model: str,
                                     color: str):
        print("\n\nClient: Adding a car into database.")
        flyweight = factory.get_flyweight([brand, model, color])
        flyweight.operation([plates, owner])