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

void dataGraph1()
{
    Graph graph(Graph::Type_Directed);

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdge(1,2,10);
    graph.addEdge(1,3,5);
    graph.addEdge(2,4,1);
    graph.addEdge(2,3,2);
    graph.addEdge(3,2,3);
    graph.addEdge(3,4,9);
    graph.addEdge(3,5,2);
    graph.addEdge(4,5,4);
    graph.addEdge(5,1,2);
    graph.addEdge(5,4,6);


    graph.display();

    graph.digkstra(1);

    graph.printShortestPath(1,2);
    printf("\n");
    graph.printShortestPath(1,3);
    printf("\n");
    graph.printShortestPath(1,4);
    printf("\n");
    graph.printShortestPath(1,5);
    printf("\n");

//    graph.BFS(1);
//    graph.printShortestPath(1,8);

//    graph.DFS(1);
//    graph.printShortestPath(1,5);
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

void dataGraph2()
{
    Graph graph(Graph::Type_Directed);

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);

    graph.addEdge(1,2,1);
    graph.addEdge(1,4,6);
    graph.addEdge(1,5,7);
    graph.addEdge(2,3,1);
    graph.addEdge(2,4,4);
    graph.addEdge(3,4,2);
    graph.addEdge(3,6,1);
    graph.addEdge(4,5,3);
    graph.addEdge(4,6,2);
    graph.addEdge(5,6,2);


    graph.display();

    graph.digkstra(1);

    graph.printShortestPath(1,2);
    printf("\n");
    graph.printShortestPath(1,3);
    printf("\n");
    graph.printShortestPath(1,4);
    printf("\n");
    graph.printShortestPath(1,5);
    printf("\n");
    graph.printShortestPath(1,6);
    printf("\n");

//    graph.BFS(1);
//    graph.printShortestPath(1,8);

//    graph.DFS(1);
//    graph.printShortestPath(1,5);
}


int main()
{
    dataGraph2();
    //heapOps();

	return 0;
}
