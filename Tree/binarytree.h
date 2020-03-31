#ifndef BINARYTREE_H
#define BINARYTREE_H


class BinaryTree
{
public:

    struct Node
    {
        int data;

        Node *left;

        Node *right;

        Node(int d)
        {
            data = d;

            left = nullptr;

            right = nullptr;
        }
    };

    BinaryTree();

    virtual void insert(int key);

    void inorder();

    void preorder();

    void postorder();

    void levelorder();

    int nodes();

    int leafNodes();

    int nonLeafNodes();

    int fullNodes();

    int height();

    bool isComplete();

    bool isBST();

private:

    void _inorder(Node *t);

    void _preorder(Node *t);

    void _postorder(Node *t);

    int _nodes(Node *t);

    int _leafNodes(Node *t);

    int _nonLeafNodes(Node *t);

    int _fullNodes(Node *t);

    int _height(Node *t);

    bool _isComplete(Node *t);

    bool _isBST(Node *t, int min, int max);

protected:

    Node *m_root;
};

#endif // BINARYTREE_H
