#ifndef GRAPH_H
#define GRAPH_H

#include"GraphNode.h"
#include"MinPriority.h"
class Graph
{
	public:
		vector<GraphNode*> nodes;
		vector<GraphNode*> queue;
		
		Graph()
		{

		}

		void addNode(GraphNode *gn);
		
		bool isParentExisting(GraphNode *gn);
		
		void MSTPrim();
		
		int weight(GraphNode *gn1,GraphNode *gn2);

};

#endif