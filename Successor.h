#ifndef SUCCESSOR_H
#define SUCCESSOR_H

class GraphNode;

class Successor
{
	public:

	GraphNode *succNode;
	int distance;
	Successor(GraphNode *successor, int distance);
	//{
	//	this->succNode = successor; // this might need a shallow copy
	//	this->distance = distance;
	//}
};

#endif