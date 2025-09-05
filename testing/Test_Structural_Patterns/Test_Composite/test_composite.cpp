/*!
 *  \file       test_composite.cpp
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include <memory>
#include <iostream>

#include "Structural_Patterns/Composite/cpp/Component.hpp"
#include "Structural_Patterns/Composite/cpp/Leaf.hpp"
#include "Structural_Patterns/Composite/cpp/Client.hpp"
#include "Structural_Patterns/Composite/cpp/Composite.hpp"

#include "testing/Test_Structural_Patterns/finalize.hpp"
#include "testing/Test_Structural_Patterns/finalize.cpp"

TEST_CASE("UTester for Composite Pattern", "[Composite]")
{
    SECTION("Check how Composite Pattern works for simple scenario.")
    {
        Component *simple = new Leaf;
        std::cout << "Client: I have got a simple component: " << std::endl;
        Client::execute(simple);
        delete simple;
    }

#if true
    SECTION("Check how Composite Pattern recursively works for complex scenario")
    {
        std::shared_ptr<Component> simple(new Leaf);

        std::shared_ptr<Component> tree(new Composite);
        std::shared_ptr<Component> branch1(new Composite);

        std::shared_ptr<Component> leaf_1(new Leaf), leaf_2(new Leaf), leaf_3(new Leaf);

        branch1->add(leaf_1.get());
        branch1->add(leaf_2.get());

        std::shared_ptr<Component> branch2(new Composite);
        branch2->add(leaf_3.get());

        tree->add(branch1.get());
        tree->add(branch2.get());

        std::cout << "Client: Now I have got a composite tree: " << std::endl;
        Client::execute(tree.get());

        std::cout << "Client: I don't need to check the Component classes even when managing the tree: " << std::endl;
        Client::execute(tree.get(), simple.get());
        std::cout << std::endl;
    }
#else
    SECTION("Check how Composite Pattern recursively works for complex scenario")
    {
        Component *simple = new Leaf;

        Component *tree = new Composite;
        Component *branch1 = new Composite;

        Component *leaf_1 = new Leaf, 
                  *leaf_2 = new Leaf,
                  *leaf_3 = new Leaf;

        branch1->add(leaf_1);
        branch1->add(leaf_2);

        Component *branch2 = new Composite;
        auto deleter = finalize([&]() {
            delete simple;      simple = nullptr;
            delete tree;        tree = nullptr;
            delete branch1;     branch1 = nullptr;
            delete leaf_1;      leaf_1 = nullptr;
            delete leaf_2;      leaf_2 = nullptr;
            delete leaf_3;      leaf_3 = nullptr;
            delete branch2;     branch2 = nullptr;
        });

        branch2->add(leaf_3);
        tree->add(branch1);
        tree->add(branch2);

        std::cout << "Client: Now I have got a composite tree: " << std::endl;
        Client::execute(tree);
        std::cout << "\n" << std::endl;

        std::cout << "Client: I don't nee to check the Component classes, even when managing the tree: " << std::endl;
        Client::execute(tree, simple);
        std::cout << std::endl;
    }
#endif
}
