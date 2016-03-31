#include "bst_tree.h"

#include <iostream>
using namespace std;

int main()
{
    //printf("--------------\n");
    BSTTree tree;

    tree.Insert(10);
    tree.Insert(2);
    tree.Insert(21);
    tree.Insert(23);
    tree.Insert(25);

    tree.Traversal();

    tree.Delete(21);
    tree.Traversal();

    TreeNode* t = tree.Find(10);
    tree.Insert(10);
    cout << "cnt = "<< t->cnt << endl;
    tree.Traversal();

    //printf("--------------\n");
}
