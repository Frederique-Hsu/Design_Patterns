/*!
 *  \file       Flyweight_Pattern.cpp
 *  \brief      
 *  
 */


#include "Flyweight_Pattern.hpp"

#include <iostream>

/*================================================================================================*/

TreeType::TreeType(const std::string &name, const std::string &color, const std::string &texture)
    : m_name{name}, m_color{color}, m_texture{texture}
{
}

void TreeType::draw(int x, int y)
{
    std::cout << "Draw the tree type: " << m_name
              << " (color: " << m_color
              << ", texture: " << m_texture << ")"
              << " at the position (" << x << ", " << y << ")"
              << std::endl;
}

std::string TreeType::getName() const
{
    return m_name;
}

/*================================================================================================*/

std::unordered_map<std::string, std::shared_ptr<TreeType>> TreeFactory::tree_types;

std::shared_ptr<TreeType> TreeFactory::getTreeType(const std::string &name,
                                                   const std::string &color,
                                                   const std::string &texture)
{
    std::string key = name + "_" + color + "_" + texture;
    if (tree_types.find(key) != tree_types.end())
    {
        std::cout << "Reuse the existing tree type: " << name << std::endl;
        return tree_types[key];
    }
    else
    {
        std::cout << "Create new tree type: " << name << std::endl;
        std::shared_ptr<TreeType> tree_type = std::make_shared<TreeType>(name, color, texture);
        tree_types.insert({key, tree_type});
        return tree_type;
    }
}

void TreeFactory::showTreeTypesCount()
{
    std::cout << "Current tree type count is: " << tree_types.size() << std::endl;
}

/*================================================================================================*/

Tree::Tree(int x, int y, std::shared_ptr<TreeType> tree_type) : m_xcoord{x}, m_ycoord{y}, m_tree_type{tree_type}
{
}

void Tree::draw() const
{
    m_tree_type->draw(m_xcoord, m_ycoord);
}

int Tree::getXCoord() const
{
    return m_xcoord;
}

int Tree::getYCoord() const
{
    return m_ycoord;
}

std::string Tree::getTreeTypeName() const
{
    return m_tree_type->getName();
}

/*================================================================================================*/

void Forest::plantTree(int x, int y,
                       const std::string &name,
                       const std::string &color,
                       const std::string &texture)
{
    std::shared_ptr<TreeType> tree_type = TreeFactory::getTreeType(name, color, texture);
    m_trees.emplace_back(Tree(x, y, tree_type));
}

void Forest::draw() const
{
    std::cout << "===== Start to draw the forest =====" << std::endl;
    for (const Tree& tree : m_trees)
    {
        tree.draw();
    }
    std::cout << "===== Finished the drawing for forest =====" << std::endl;
}

size_t Forest::getTreeCount() const
{
    return m_trees.size();
}

/*================================================================================================*/

int main(int argc, char* argv[])
{
    Forest forest;
    
    std::cout << "========== Start to plant tree for forest ==========" << std::endl;
    
    forest.plantTree(10, 20, "松树", "绿色", "松树纹理");
    forest.plantTree(30, 40, "松树", "绿色", "松树纹理");
    forest.plantTree(50, 60, "松树", "绿色", "松树纹理");
    
    forest.plantTree(70, 80,  "橡树", "深绿色", "橡树纹理");
    forest.plantTree(90, 100, "橡树", "深绿色", "橡树纹理");
    
    forest.plantTree(110, 120, "枫树", "红色", "枫树纹理");
    forest.plantTree(130, 140, "枫树", "红色", "枫树纹理");
    forest.plantTree(150, 160, "枫树", "红色", "枫树纹理");
    forest.plantTree(170, 180, "枫树", "红色", "枫树纹理");
    
    forest.plantTree(190, 200, "棕榈树", "浅绿色", "棕榈树纹理");
    forest.plantTree(210, 220, "棕榈树", "浅绿色", "棕榈树纹理");
    forest.plantTree(230, 240, "棕榈树", "浅绿色", "棕榈树纹理");
    
    std::cout << "========== End the forest planting ==========\n" << std::endl;
    
    TreeFactory::showTreeTypesCount();
    std::cout << "The count of trees in the forest: " << forest.getTreeCount() << std::endl;
    
    forest.draw();
    return 0;
}
