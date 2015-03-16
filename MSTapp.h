#ifndef MSTAPP_H
#define MSTAPP_H

#include"Graph.h"
class MSTapp
{
	public:
		void processApp();
		void addEdge(Graph *gr,GraphNode *gn1, GraphNode *gn2,int distance);
		GraphNode* findVertex(Graph* gr, char name);
};

#endif