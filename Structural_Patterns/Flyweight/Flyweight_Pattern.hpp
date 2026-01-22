/*!
 *  \file       Flyweight_Pattern.hpp
 *  \brief      
 *  
 */


#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

/*!
 *  \class  TreeType    享元类
 *  \brief  内部状态：可共享的部分
 *
 */
class TreeType
{
public:
    TreeType(const std::string &name, const std::string &color, const std::string &texture);
    
private:
    std::string m_name;
    std::string m_color;
    std::string m_texture;
    
public:
    void draw(int x, int y);
    std::string getName() const;
};


/*!
 *  \class  TreeFactory 享元工厂
 *  \brief  管理享元对象的创建和共享
 *
 */
class TreeFactory
{
private:
    static std::unordered_map<std::string, std::shared_ptr<TreeType>> tree_types;
    
public:
    static std::shared_ptr<TreeType> getTreeType(const std::string &name,
                                                 const std::string &color,
                                                 const std::string &texture);
    static void showTreeTypesCount();
};


/*!
 *  \class  Tree    具体对象类
 *  \brief  包含外部状态（位置）
 *
 */
class Tree
{
public:
    Tree(int x, int y, std::shared_ptr<TreeType> tree_type);
    
private:
    int m_xcoord;
    int m_ycoord;
    std::shared_ptr<TreeType> m_tree_type;
    
public:
    void draw() const;
    
    int getXCoord() const;
    int getYCoord() const;
    std::string getTreeTypeName() const;
};


/*!
 *  \class  Forest  森林类（客户端）
 *  \brief  管理所有树木对象
 *
 */
class Forest
{
private:
    std::vector<Tree> m_trees;
    
public:
    void plantTree(int x, int y,
                   const std::string &name,
                   const std::string &color,
                   const std::string &texture);
    
    void draw() const;
    size_t getTreeCount() const;
};
