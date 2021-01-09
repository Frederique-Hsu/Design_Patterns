/* Project      : Composite
 * Description  : Study how the composite pattern works?
 * ================================================================================================
 * File name    : client.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sat.  09 Jan. 2021
 * Copyright(C) 2021    All rights reserved.
 *
 */

#include <iostream>
#include <memory>

#include "Component.hpp"
#include "Composite.hpp"
#include "Leaf.hpp"

void ClientCode(Component* comp);
void ClientCode2(Component* composite, Component* component);

int main()
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bit.\n" << std::endl;

    /* for the simple component */
    Component* simple = new Leaf;
    std::cout << "Client: I've got a simple component:" << std::endl;
    ClientCode(simple);
    std::cout << "\n" << std::endl;

    /* .... as well as the complex composites */
    std::shared_ptr<Component>  tree(new Composite);
    std::shared_ptr<Component>  left_branch(new Composite);
    std::shared_ptr<Component>  leaf_1(new Leaf), leaf_2(new Leaf), leaf_3(new Leaf);

    left_branch->Add(leaf_1.get());
    left_branch->Add(leaf_2.get());

    std::shared_ptr<Component> right_branch(new Composite);
    right_branch->Add(leaf_3.get());

    tree->Add(left_branch.get());
    tree->Add(right_branch.get());
    std::cout << "Client: I've got a composite tree:" << std::endl;
    ClientCode(tree.get());

    delete simple;

    return 0;
}

void ClientCode(Component* comp)
{
    std::cout << "RESULT: " << comp->Operation() << std::endl;
}

void ClientCode2(Component* composite, Component* component)
{
    if (composite->IsComposite())
    {
        composite->Add(component);
    }
    std::cout << "RESULT: " << composite->Operation() << std::endl;
}
