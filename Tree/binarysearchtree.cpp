#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree():
    BinaryTree()
{

}

void BinarySearchTree::deleteNode(int key)
{
    m_root = _deleteNode(m_root,key);
}

int BinarySearchTree::findMin()
{
    return _findMin(m_root);
}

int BinarySearchTree::_findMin(Node *root)
{
    if(!root->left)
    {
        return root->data;
    }
    else
    {
        return _findMin(root->left);
    }
}

BinaryTree::Node *BinarySearchTree::_find(BinaryTree::Node *root,
                                          int key)
{
    if(!root)
    {
        return nullptr;
    }

    if( key < root->data )
    {
        return _find(root->left,key);
    }
    else if( key > root->data )
    {
        return _find(root->right,key);
    }
    else
    {
        return root;
    }
}

int BinarySearchTree::findMax()
{
    return _findMax(m_root);
}

int BinarySearchTree::inorderSuccessor(int key)
{
    if( !m_root )
    {
        return -1;
    }

    Node *cur = _find(m_root,key);

    if( cur->right )
    {
        return _findMin(cur->right);
    }
    else
    {
        Node *ancestor = m_root;

        Node *successor = nullptr;

        while(ancestor != cur)
        {
            if( cur->data < ancestor->data )
            {
                successor = ancestor;

                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor->data;
    }
}

int BinarySearchTree::_findMax(Node *root)
{
    if(!root->right)
    {
        return root->data;
    }
    else
    {
        return _findMax(root->right);
    }
}

void BinarySearchTree::_insert(BinaryTree::Node *root, int key)
{
    if( root->data > key)
    {
        if( !root->left )
        {
            root->left = new Node(key);
            return;
        }
        else
        {
            _insert(root->left,key);
        }
    }
    else if( root->data < key )
    {
        if( !root->right )
        {
            root->right = new Node(key);
            return;
        }
        else
        {
            _insert(root->right,key);
        }
    }
}

BinaryTree::Node* BinarySearchTree::_deleteNode(BinaryTree::Node *root, int key)
{
    if(!root)
    {
        return root;
    }

    else if( root->data > key )
    {
        root->left = _deleteNode(root->left,key);
    }

    else if( root->data < key)
    {
        root->right = _deleteNode(root->right,key);
    }

    else if( root->data == key)
    {
        if( !root->left && !root->right )
        {
            delete root;

            root = nullptr;
        }
        else if( !root->left )
        {
            Node *t = root;

            root = root->right;

            delete t;
        }
        else if( !root->right )
        {
            Node *t = root;

            root = root->left;

            delete t;
        }
        else
        {
            root->data = _findMin(root->right);

            root->right = _deleteNode(root->right,root->data);
        }
    }
    return root;
}

void BinarySearchTree::insert(int key)
{
    Node *newNode = new Node(key);

    if( !m_root )
    {
        m_root = newNode;
    }
    else
    {
        _insert(m_root,key);
    }
}

