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
    Graph::Edge edges[11];

    edges[0] = Graph::Edge(0,1,1);
    edges[1] = Graph::Edge(1,2,1);
    edges[2] = Graph::Edge(1,3,1);
    edges[3] = Graph::Edge(2,4,1);
    edges[4] = Graph::Edge(2,5,1);
    edges[5] = Graph::Edge(3,6,1);
    edges[6] = Graph::Edge(3,7,1);
    edges[7] = Graph::Edge(4,8,1);
    edges[8] = Graph::Edge(5,8,1);
    edges[9] = Graph::Edge(6,8,1);
    edges[10] = Graph::Edge(7,8,1);

    int V = 9;

    int E = 11;

    UndirectedGraph graph(V);

    graph.createAdjList(edges,E);

    graph.display();

    graph.BFS(0);

    graph.DFS(0);
}

int main()
{
    dataGraph();

	return 0;
}
