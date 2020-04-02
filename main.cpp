#include <stdio.h>
#include "Tree/binarysearchtree.h"
#include "Graph/graph.h"
#include "Graph/distanceheap.h"

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
    Graph graph(9);

    graph.addEdge(0,1,1);
    graph.addEdge(1,2,1);
    graph.addEdge(1,3,1);
    graph.addEdge(2,4,1);
    graph.addEdge(2,5,1);
    graph.addEdge(3,6,1);
    graph.addEdge(3,7,1);
    graph.addEdge(4,8,1);
    graph.addEdge(5,8,1);
    graph.addEdge(6,8,1);
    graph.addEdge(7,8,1);

    graph.display();

//    graph.BFS(0);
//    graph.printShortestPath(0,8);

    graph.DFS(0);
    graph.printShortestPath(0,5);

//    graph.DFS(0);
}

void heapOps()
{
    DistanceHeap H;

    H.insert(DistanceHeap::Node(1,5));
    H.insert(DistanceHeap::Node(2,55));
    H.insert(DistanceHeap::Node(3,1));
    H.insert(DistanceHeap::Node(4,567));
    H.insert(DistanceHeap::Node(5,9));

    printf("%d\n",H.extractMin().dist);
    printf("%d\n",H.extractMin().dist);
    printf("%d\n",H.extractMin().dist);
    printf("%d\n",H.extractMin().dist);
    printf("%d\n",H.extractMin().dist);
    printf("%d\n",H.extractMin().dist);
}

int main()
{
    dataGraph();

	return 0;
}
