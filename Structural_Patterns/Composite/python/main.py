# File name     : main.py
# Description   : 
#
#


from Leaf import Leaf
from Client import Client
from Composite import Composite

def main():
    simple = Leaf()
    print("Client: I have got a simple component: ")
    Client.execute1(simple)
    print("\n")

    tree = Composite()

    branch1 = Composite()
    branch1.add(Leaf())
    branch1.add(Leaf())

    branch2 = Composite()
    branch2.add(Leaf())

    tree.add(branch1)
    tree.add(branch2)

    print("Client: Now I have got a composite tree: ")
    Client.execute1(tree)
    print("\n")

    print("Client: I don't need to check the components classes even when managing the tree: ")
    Client.execute2(tree, simple)



if __name__ == "__main__":
    main()