#include <stdio.h>
#include "Tree/binarysearchtree.h"
#include "Graph/directedgraph.h"
#include "Graph/undirectedgraph.h"

using namespace std;

void dataBST()
{
    BinarySearchTree tree;

    tree.insert(8);
    tree.insert(9);
    tree.insert(1);
    tree.insert(7);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(10);
    tree.insert(11);
    tree.insert(3);
    tree.insert(2);
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    tree.insert(15);

    tree.preorder();
    printf("\n");
    tree.inorder();
    printf("\n");
    tree.postorder();
    printf("\n");
    tree.levelorder();
    printf("\n");

    printf("Total Nodes: %d\n",tree.nodes());
    printf("Total Leaf Nodes: %d\n",tree.leafNodes());
    printf("Total Non Leaf Nodes: %d\n",tree.nonLeafNodes());
    printf("Is Complete: %d\n",tree.isComplete());
    printf("Height: %d\n",tree.height());
    printf("Total Full Nodes: %d\n",tree.fullNodes());
    printf("Is BST: %d\n",tree.isBST());
    printf("Min: %d\n",tree.findMin());
    printf("Max: %d\n",tree.findMax());
    printf("In order Successor: %d\n",tree.inorderSuccessor(10));

    tree.deleteNode(8);

    tree.preorder();
    printf("\n");
    tree.inorder();
    printf("\n");
    tree.postorder();
    printf("\n");
    tree.levelorder();
    printf("\n");

    printf("Total Nodes: %d\n",tree.nodes());
    printf("Total Leaf Nodes: %d\n",tree.leafNodes());
    printf("Total Non Leaf Nodes: %d\n",tree.nonLeafNodes());
    printf("Is Complete: %d\n",tree.isComplete());
    printf("Height: %d\n",tree.height());
    printf("Total Full Nodes: %d\n",tree.fullNodes());
    printf("Is BST: %d\n",tree.isBST());
    printf("Min: %d\n",tree.findMin());
    printf("Max: %d\n",tree.findMax());
}

void dataGraph()
{
    Graph::Edge edges[7];

    edges[0] = Graph::Edge(0,1,6);
    edges[1] = Graph::Edge(1,2,7);
    edges[2] = Graph::Edge(2,0,5);
    edges[3] = Graph::Edge(2,1,4);
    edges[4] = Graph::Edge(3,2,10);
    edges[5] = Graph::Edge(4,5,1);
    edges[6] = Graph::Edge(5,4,3);

    int V = 6;

    int E = 7;

    DirectedGraph graph(V);

    graph.createAdjList(edges,E);

    graph.display();
}

int main()
{
    dataGraph();

	return 0;
}
