#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#define MAXIMUM 1000
#define MINIMUM -1

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include"Successor.h"

using namespace std;
class GraphNode
{
public:
	char nodeName;
	GraphNode *parent;
	int key;

	vector<Successor*> successorList;

	GraphNode(char nodeName);
	
	void insertSuccessor(GraphNode *successorName, int distance);
	
	bool isAlreadySuccessor(GraphNode *nodeCheck);
};
#endif