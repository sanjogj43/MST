#include "Successor.h"

Successor::Successor(GraphNode *successor, int distance)
{
	this->succNode = successor; // this might need a shallow copy
	this->distance = distance;
}