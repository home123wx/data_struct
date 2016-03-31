#include "bst_tree.h"

#include <string>
using std::string;

BSTTree::BSTTree():root(NULL)
{
}

BSTTree::~BSTTree()
{
}

void show(const string& op, const T& data)
{
    printf("%s, %d\n", op.c_str(), data);
}

void BSTTree::Insert(const T& data)
{
    show("insert", data);
    InsertPri(root, data);
}

void BSTTree::Delete(const T& data)
{
    show("delete", data);
    DeletePri(root, data);
}

TreeNode* BSTTree::Find(const T& data)
{
    show("find", data);
    return FindPri(root, data);
}

void BSTTree::Traversal()
{
    TraversalPri(root);
}

void BSTTree::InsertPri(TreeNode* &node, const T& data)
{
    if (node == NULL) {
        node = new TreeNode;
        node->data = data;
        return;
    }

    if (node->data > data) {
        InsertPri(node->left, data);
    } else if (node->data < data) {
        InsertPri(node->right, data);
    } else {
        ++node->cnt;
    }
}

void BSTTree::DeletePri(TreeNode*& node, const T& data)
{
    if (node == NULL) {
        return;
    }

    if (data > node->data) {
        DeletePri(node->right, data);
    } else if (data < node->data) {
        DeletePri(node->left, data);
    } else {
        //1. 删除节点包含两个儿子
        if (node->left != NULL && node->right != NULL) {
            //找到右子树中值最小的节点,覆盖当前节点
            TreeNode* minNode = FindMinValueNode(node->right);
            node->data = minNode->data;
            node->cnt = minNode->cnt;
            delete minNode;
        }
        //2. 删除节点只包含一个儿子或没有儿子
        else {
            TreeNode* temp = node;
            if (node->left == NULL) {
                node = node->right;
            } else if (node->right == NULL) {
                node = node->left;
            }
            delete temp;
        }
    }
}

void BSTTree::TraversalPri(TreeNode* node)
{
    if (node == NULL) {
        return;
    }
    TraversalPri(node->left);
    printf("data : %d, cnt = %d\n", node->data, node->cnt);
    TraversalPri(node->right);
}

TreeNode* BSTTree::FindPri(TreeNode* node, const T& data)
{
    if (node == NULL) {
        return NULL;
    }

    if (node->data > data) {
        return FindPri(node->left, data);
    }

    if (node->data < data) {
        return FindPri(node->right, data);
    }
    return node;
}

TreeNode* BSTTree::FindMinValueNode(TreeNode* node)
{
    TreeNode* t = node;
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}
