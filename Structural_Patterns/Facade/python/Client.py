# File name     : Client.py
# Description   : 
# 
#


from Facade import Facade


class Client:
    @staticmethod
    def execute(facade: Facade):
        print(facade.operation(), end="")