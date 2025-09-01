# File name     : Client.py
# Description   : 
#
#


from Abstraction import Abstraction


class Client:
    @staticmethod
    def execute(abstraction: Abstraction) -> None:
        '''
        Except for the initialization phase, where an Abstraction object gets linked with
        a specific implementation object, the client should only depend on the Abstraction class.
        This way the client can support any abstraction-implementation combination.
        '''
        print(abstraction.operation(), end="")