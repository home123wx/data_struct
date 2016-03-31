#ifndef _BST_TREE_H_
#define _BST_TREE_H

#include <stdio.h>
#include <stddef.h>

typedef int T;

//template<typename T>
class TreeNode
{
public:
    TreeNode():cnt(1), left(NULL), right(NULL){}

    T data;
    int cnt;
    TreeNode* left;
    TreeNode* right;
};

//template<typename T>
class BSTTree
{
public:
    BSTTree();
    ~BSTTree();

public:
    void Insert(const T& data);
    void Delete(const T& data);
    void Traversal();
    TreeNode* Find(const T& data);

private:
    void InsertPri(TreeNode*& node, const T& data);
    void DeletePri(TreeNode*& node, const T& data);
    void TraversalPri(TreeNode* node);

    TreeNode* FindPri(TreeNode* node, const T& data);
    TreeNode* FindMinValueNode(TreeNode* node);

private:
    TreeNode* root;
};
#endif //_BST_TREE_H
