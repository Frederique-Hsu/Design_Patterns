# File name     : Flyweight.py
# Description   :
#
#

import json

class Flyweight:
    '''
    The Flyweight stores a common portion of the state (also called intrinsic state) that belongs to multiple 
    real business entities. The Flyweight accepts the rest of the state (extrinsic state, unique for each entity)
    via its method parameters.
    '''
    def __init__(self, shared_state: str):
        self._shared_state = shared_state

    def operation(self, unique_state: str):
        s = json.dumps(self._shared_state)
        u = json.dumps(unique_state)
        print(f"Flyweight: Displaying shared ({s}) and unique ({u}) state.", end="")