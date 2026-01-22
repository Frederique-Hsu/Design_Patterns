# File name     : FlyweightFactory.py
# Description   : 
#
#

from typing import Dict

from Flyweight import Flyweight

class FlyweightFactory:
    '''
    The Flyweight Factory creates and manages the Flyweight objects.
    It ensures that flyweights are shared correctly. When the client requests a flyweight,
    the factory either returns an existing instance or creates a new one, if it doesn't exist yet.
    '''
    _flyweights: Dict[str, Flyweight] = {}

    def __init__(self, initial_flyweights: Dict):
        for state in initial_flyweights:
            self._flyweights[self.get_key(state)] = Flyweight(state)

    def get_key(self, state: Dict):
        return "_".join(sorted(state))
    
    def get_flyweight(self, shared_state: Dict):
        key = self.get_key(shared_state)

        if not self._flyweights.get(key):
            print("FlyweightFactory: Cannot find a flyweight, creating new one.")
            self._flyweights[key] = Flyweight(shared_state)
        else:
            print("FlyweightFactory: Reusing existing flyweight.")

        return self._flyweights[key]
    
    def list_flyweights(self):
        count = len(self._flyweights)
        print(f"FlyweightFactory: I have {count} flyweights:")
        print("\n".join(map(str, self._flyweights.keys())), end="")