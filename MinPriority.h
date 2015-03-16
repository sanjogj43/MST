#ifndef MINPRIORITY_H
#define MINPRIORITY_H

#include "Graph.h"

class MinPriority
{
public:
	
	 void heapDecreaseKey(vector<GraphNode*> &graphNodes, GraphNode *gn , int key);
	 
	 int getIndex(vector<GraphNode*> graphNodes,GraphNode *gn); 

	 int parent(int index);

	 int rightChild(int index);
	 
	 int leftChild(int index);
	 
	 vector<GraphNode*> rearrangeQueue(vector<GraphNode *> pqueue);

	 void minHeapify(int i,int heapsize,vector<GraphNode *> &pqueue);

	 bool contains(vector<GraphNode*> queue,GraphNode *gn1);

	 GraphNode* heapExtractMin(vector<GraphNode*> &graphNodes);
};

#endif