#include "binarytree.h"
#include "Queue/linkedqueue.h"
#include <bits/stdc++.h>

BinaryTree::BinaryTree():
    m_root(nullptr)
{

}

void BinaryTree::insert(int key)
{
    Node *newNode = new Node(key);

    if( !m_root )
    {
        m_root = newNode;

        return;
    }

    LinkedQueue<Node *> Q;

    Q.enqueue(m_root);

    while(!Q.isEmpty())
    {
        Node *t = Q.dequeue();

        if( t->left )
        {
            Q.enqueue(t->left);
        }
        else
        {
            t->left = newNode;

            break;
        }

        if( t->right )
        {
            Q.enqueue(t->right);
        }
        else
        {
            t->right = newNode;

            break;
        }
    }
}

void BinaryTree::inorder()
{
    _inorder(m_root);
}

void BinaryTree::preorder()
{
    _preorder(m_root);
}

void BinaryTree::postorder()
{
    _postorder(m_root);
}

void BinaryTree::levelorder()
{
    if( !m_root )
    {
        return;
    }

    LinkedQueue<Node *> Q;

    Q.enqueue(m_root);

    while(!Q.isEmpty())
    {
        Node *t = Q.dequeue();

        printf("%d-->", t->data);

        if( t->left )
        {
            Q.enqueue(t->left);
        }

        if( t->right )
        {
            Q.enqueue(t->right);
        }
    }
}

int BinaryTree::nodes()
{
    return _nodes(m_root);
}

int BinaryTree::leafNodes()
{
    return _leafNodes(m_root);
}

int BinaryTree::nonLeafNodes()
{
    return _nonLeafNodes(m_root);
}

int BinaryTree::fullNodes()
{
    return _fullNodes(m_root);
}

int BinaryTree::height()
{
    return _height(m_root);
}

bool BinaryTree::isComplete()
{
    return _isComplete(m_root);
}

bool BinaryTree::isBST()
{
    return _isBST(m_root, INT_MIN, INT_MAX);
}

void BinaryTree::_inorder(Node *t)
{
    if(t)
    {
        _inorder(t->left);

        printf("%d-->", t->data);

        _inorder(t->right);
    }
}

void BinaryTree::_preorder(Node *t)
{
    if(t)
    {
        printf("%d-->", t->data);

        _preorder(t->left);

        _preorder(t->right);
    }
}

void BinaryTree::_postorder(Node *t)
{
    if(t)
    {
        _postorder(t->left);

        _postorder(t->right);

        printf("%d-->", t->data);
    }
}

int BinaryTree::_nodes(BinaryTree::Node *t)
{
    if(!t)
    {
        return 0;
    }

    int l = _nodes(t->left);

    int r = _nodes(t->right);

    return 1+l+r;
}

int BinaryTree::_leafNodes(BinaryTree::Node *t)
{
    if(!t)
    {
        return 0;
    }

    if(!t->left && !t->right)
    {
        return 1;
    }
    else
    {
        return _leafNodes(t->left)+_leafNodes(t->right);
    }
}

int BinaryTree::_nonLeafNodes(BinaryTree::Node *t)
{
    if(!t)
    {
        return 0;
    }

    if(!t->left && !t->right)
    {
        return 0;
    }
    else
    {
        return 1+_nonLeafNodes(t->left)+_nonLeafNodes(t->right);
    }
}

int BinaryTree::_fullNodes(BinaryTree::Node *t)
{
    if(!t)
    {
        return 0;
    }

    if(!t->left && !t->right)
    {
        return 0;
    }

    if(t->left && t->right)
    {
        return 1+_fullNodes(t->left)+_fullNodes(t->right);
    }
    else
    {
        return _fullNodes(t->left)+_fullNodes(t->right);
    }
}

int BinaryTree::_height(BinaryTree::Node *t)
{
    if(!t)
    {
        return 0;
    }

    if(!t->left && !t->right)
    {
        return 0;
    }

    int l = _height(t->left);

    int r = _height(t->right);

    return 1+ ((l>r)?l:r);
}

bool BinaryTree::_isComplete(BinaryTree::Node *t)
{
    if(!t)
    {
        return true;
    }

    if(!t->left && !t->right)
    {
        return true;
    }

    if(t->left && t->right)
    {
        return _isComplete(t->left) && _isComplete(t->right);
    }
    else
    {
        return 0;
    }
}

bool BinaryTree::_isBST(BinaryTree::Node *t, int min, int max)
{
    if(!t) return true;

    if( t->data < max &&
        t->data > min &&
        _isBST(t->left,min,t->data) &&
        _isBST(t->right,t->data, max))
    {
        return true;
    }
    else
    {
        return false;
    }
}

