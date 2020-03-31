#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"

class BinarySearchTree : public BinaryTree
{

public:

    BinarySearchTree();

    void insert(int key);

    void deleteNode(int key);

    int findMin();

    int findMax();

    int inorderSuccessor(int key);

private:

    int _findMin(Node *root);

    BinaryTree::Node* _find(Node *root, int key);

    int _findMax(Node *root);

    void _insert(Node *root, int key);

    BinaryTree::Node* _deleteNode(Node *root, int key);


};

#endif // BINARYSEARCHTREE_H
