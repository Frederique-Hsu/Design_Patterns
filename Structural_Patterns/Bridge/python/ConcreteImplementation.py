# File name     : ConcreteImplementation.py
# Description   : 
#
#



from Implementation import Implementation


'''
Each Concrete Implementation corresponds to a specific platform and implements the
Implementation interface using that platform's API.
'''


class ConcreteImplementationA(Implementation):
    def operationImpl(self) -> str:
        return "ConcreteImplementationA: Here is the result on the platform A."
    

class ConcreteImplementationB(Implementation):
    def operationImpl(self) -> str:
        return "ConcreteImplementationB: Here is the result on the platform B."